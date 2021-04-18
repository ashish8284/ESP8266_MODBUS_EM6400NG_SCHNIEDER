# ESP8266_MODBUS_EM6400NG_SCHNIEDER

#Thanks to creater of Modbus library : https://github.com/emelianov/modbus-esp8266

#This piece of code read Modbus addresss 2700 of Schnieder make energy meter Model EM6400NG
ESP reads MODBUS address from 0. hence we have to read 2699 address which actually reads 2700.
ESP reads 16 bit integer. as per Energy meter manual Energy reading is 32 bit floating point.
To convert two 16 bit integer in to floating point Seprate function is used in code.

This is sample only for tutorial purpose.

<iframe width="560" height="315" src="https://www.youtube.com/embed/5n0Q8K1_xnU" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
