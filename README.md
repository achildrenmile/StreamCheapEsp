# StreamCheapEsp
Based on the idea of Dave Madison on building a reliable stream deck on low budget, this is the ESP32 version of this idea. ESP32 does not have USB capabilities, so instead of using the keyboard library, the BleKeyboard library was used.
The original stream deck code (for Arduino Pro Micro / Leonardo) as well as the casing information can be found here: https://www.partsnotincluded.com/diy-stream-deck-mini-macro-keyboard/.

# Where can I find the casing to print it with a 3d printer?
Based on this design https://www.thingiverse.com/thing:2822140, the base was changed to fit the ESP32 in the form factor WEMOS Mini. Tested this out with an ESP32 MH-ET Live.
You can find the stl of the base here: https://github.com/achildrenmile/StreamCheapEsp/blob/main/StreamCheap_Base_ESP32.stl.

# Do I really need to buy the relagendable key caps?
No, you can download them on thingiverse: https://www.thingiverse.com/thing:3791028. Thanks to https://www.thingiverse.com/Mc_gee!

# How to flash the software?
Download the ino file and open it with e.g. Arduino IDE. Choose one ESP32 board. Flash it and connect the keyboard. You are done!

# How to assign the hotkeys in e.g. OBS?
Have a look here https://www.partsnotincluded.com/diy-stream-deck-mini-macro-keyboard/.

# What does it cost?
## Hardware:
* ESP32 MH-ET Live ~ 4-6 Euro (including Shipment to Austria) on AliExpress
* 8 x Cherry MX switches ~ 0,5 Euro per piece on AliExpress
* 1 x Right Angle Connector ~ 0,5 Euro per piece on AliExpress
* Dupond Cable bundle ~ 1,5 Euro on AliExpress
* some solder wire
## 3D Case:
I used PETG 0,2mm incl. support where it was needed

* ~ 80 g of Filament * Total printing time with MK3S in total for casing and keycaps 
* Total printing time ~5 hours on Prusa MK3S

![StreamCheap](https://github.com/achildrenmile/StreamCheapEsp/blob/main/StreamCheap.jpeg)

