/*
 *  Project     'Stream Cheap' Mini Macro Keyboard - ESP32 BLE Version
 *  @author     David Madison, Michael Linder
 *  @link       partsnotincluded.com/electronics/diy-stream-deck-mini-macro-keyboard
 *  @license    MIT - Copyright (c) 2018 David Madison
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

// ---------------------------------
// Key definitions
#define BUTTON_KEY1 KEY_F13
#define BUTTON_KEY2 KEY_F14
#define BUTTON_KEY3 KEY_F15


#define BUTTON_KEY4 KEY_F16
#define BUTTON_KEY5 KEY_F17
#define BUTTON_KEY6 KEY_F18
#define BUTTON_KEY7 KEY_F19
#define BUTTON_KEY8 KEY_F20

// Pin definitions
#define BUTTON_PIN1 26 // REC
#define BUTTON_PIN2 13 // TIME
#define BUTTON_PIN3 33 // MOVIE
#define BUTTON_PIN4 14 // CODE
#define BUTTON_PIN5 17 // MUTE
#define BUTTON_PIN6 16 // CAM OFF
#define BUTTON_PIN7 15 // LOVE TWITCH
#define BUTTON_PIN8 27 // 


// ---------------------------------

//#include "Keyboard.h"
#include <BleKeyboard.h>
BleKeyboard bleKeyboard;

// Button helper class for handling press/release and debouncing
class button {
  public:
  const char key;
  const uint8_t pin;

  button(uint8_t k, uint8_t p) : key(k), pin(p){}

  void press(boolean state){
    if(state == pressed || (millis() - lastPressed  <= debounceTime)){
      return; // Nothing to see here, folks
    }

    lastPressed = millis();

    state ? bleKeyboard.press(key) : bleKeyboard.release(key);    
    pressed = state;
    Serial.println("**********************************");
    Serial.println("Key on following PIN pressed:");
    Serial.println(pin);
    Serial.println("Sending key:");
    Serial.println(key);
    Serial.println("Pressed state:");
    Serial.println(pressed);
    Serial.println("**********************************");
  }

  void update(){
    press(!digitalRead(pin));
  }

  private:
  const long debounceTime = 30;
  unsigned long lastPressed;
  boolean pressed = 0;
} ;

// Button objects, organized in array
button buttons[] = {
  {BUTTON_KEY1, BUTTON_PIN1},
  {BUTTON_KEY2, BUTTON_PIN2},
  {BUTTON_KEY3, BUTTON_PIN3},
  {BUTTON_KEY4, BUTTON_PIN4},
  {BUTTON_KEY5, BUTTON_PIN5},
  {BUTTON_KEY6, BUTTON_PIN6},
  {BUTTON_KEY7, BUTTON_PIN7},
  {BUTTON_KEY8, BUTTON_PIN8},
};

const uint8_t NumButtons = sizeof(buttons) / sizeof(button);


const uint8_t ledPin = 17;

void setup() {  
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();
  
  for(int i = 0; i < NumButtons; i++){
    pinMode(buttons[i].pin, INPUT_PULLUP);
  }
}

void loop() {
  if(bleKeyboard.isConnected()) {
    for(int i = 0; i < NumButtons; i++){
      //Serial.println("Update for");
      //Serial.println(i);
      buttons[i].update();
    }
  }
  Serial.println("***********Waiting 2 seconds...");
  delay(2000);
}

void failsafe(){
  for(;;){} // Just going to hang out here for awhile :D
}
