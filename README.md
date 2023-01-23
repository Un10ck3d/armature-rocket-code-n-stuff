# rocket-stuff (very much WIP)

source code for NokiaOS (rocket operating system)
also a rocket interface for looking at data

dosnt work yet at all none of it 

# The code
Coded in c++ because arduino framework. Using platform IO.

The  board connects to wifi and runs over the air updates if debug pins are connnected.

It reads data from sensors (Altimeter, accelerometer, temperature and camera) and saves it on the sd-card

The sd-card must be formatted in  FAT32 format. And it will not work with anything bigger than 32GB

You can configure it in the "config.h" c++ file.

# The flight computer
The code runs on a 2 core esp32-cam module.
I have choosen the esp32-cam because it has 2 cores, a camera and a sd-card reader wich is very useful to save data and images.

On the esp32 i have soldered a BMP388 barometer to get altitude
There is also a GY-521 mpu accelerometer for speed, and stability data.

I am working on adding a XL1278-SMT 433hz radio module for in-flight communication

![The flight computer](https://github.com/Un10ck3d/armature-rocket-code-n-stuff/blob/main/compuer.jpg?raw=true)
![The flight computer upside down](https://github.com/Un10ck3d/armature-rocket-code-n-stuff/blob/main/computer-upsidedown.jpg?raw=true)
