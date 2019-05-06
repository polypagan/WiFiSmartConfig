# WiFiSmartConfig
Based on example provided, makes some corrections.

The problem:
To connect to WiFi, need to get credentials (SSID, PassPhrase) from somewhere.
The method commonly used is to simply bake these in as const char *.
The drawbacks to this are 1) security and
2) moving to another network requires re-compilation.

A solution:
This code demonstrates what heppens when ESP8266 or ESP32 fails to connect (times out).
SmartConfig code is entered, awaits configuration using mobile app (which is told SSID & PassPhrase).
Credentials are stored for future use. If they fail (new net?), above is repeated.
