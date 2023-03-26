# Modbus Ethercard Library for Arduino  
Over TCP/IP implementation for Ethercard (ENC28J60 controller)

[![GitHub release (latest by date including pre-releases)](https://img.shields.io/github/v/release/epsilonrt/modbus-ethercard?include_prereleases)](https://github.com/epsilonrt/modbus-ethercard/releases) 
[![PlatformIO Registry](https://badges.registry.platformio.org/packages/epsilonrt/library/modbus-ethercard.svg)](https://registry.platformio.org/libraries/epsilonrt/modbus-ethercard) 
[![Arduino Registry](https://www.ardu-badge.com/badge/Modbus-EtherCard.svg)](http://www.arduinolibraries.info/libraries/modbus-ether-card)

[![Framework](https://img.shields.io/badge/Framework-Arduino-blue)](https://www.arduino.cc/)
[![Uno](https://github.com/epsilonrt/modbus-ethercard/actions/workflows/build_uno.yml/badge.svg)](https://github.com/epsilonrt/modbus-ethercard/actions/workflows/build_uno.yml) 
[![Leonardo](https://github.com/epsilonrt/modbus-ethercard/actions/workflows/build_leonardo.yml/badge.svg)](https://github.com/epsilonrt/modbus-ethercard/actions/workflows/build_leonardo.yml) 

---

This library allows your Arduino to communicate via Modbus protocol. The Modbus is a master-slave protocol
used in industrial automation and can be used in other areas, such as home automation.

The Modbus generally uses serial RS-232 or RS-485 as physical layer (then called Modbus Serial) and
TCP/IP via Ethernet or WiFi (Modbus TCP).

In the current version the library allows the Arduino operate **as a slave**, supporting Modbus over TCP.

## How to

There are four classes corresponding to five headers that may be used:

* [Modbus-Arduino](http://github.com/epsilonrt/modbus-arduino ) - Base Library
* [Modbus-Serial](https://github.com/epsilonrt/modbus-serial) - Modbus Serial RTU Library    
* [Modbus-Ethernet](https://github.com/epsilonrt/modbus-ethernet) - Modbus TCP Library (standard Ethernet Shield)   
* [Modbus-EtherCard](https://github.com/epsilonrt/modbus-ethercard) - Modbus TCP Library (for ENC28J60 chip)  
* [Modbus-Esp8266AT](https://github.com/epsilonrt/modbus-esp8266at) - Modbus IP Library (for ESP8266 chip with AT firmware)   

By opting for Modbus Serial or Modbus TCP you must include in your sketch the corresponding header and the base library header, eg:

    #include <Modbus.h>
    #include <ModbusSerial.h>

## Modbus-Ethercard

The Arduino standard Ethernet shield is based on chip WIZnet W5100, therefore the IDE comes
with this library installed. If you have a shield based on ENC28J60 from Microchip you must install
another Ethernet library. Among several available we chose EtherCard.

Download the EtherCard in https://github.com/jcw/ethercard and install it in your IDE.
Use the following includes in your sketches:

    #include <EtherCard.h>
    #include <ModbusEthercard.h>
    #include <Modbus.h>

Done! The use of Modbus functions is identical to the ModbusEthernet library described above.

**Notes:**

1. When using Modbus TCP the transport protocol is TCP (port 502) and, by default, 
the connection is terminated to each transmitted message, that is, is not a 
keep-alive type connection. If you need a TCP keep-alive connection you have to 
remove comments of this line in ModbusEthernet.h header (or ModbusEthercard.h ModbusEsp8266AT.h headers):

		#define TCP_KEEP_ALIVE

2. EtherCard is configured to use the pins 10, 11, 12 and 13.

3. The voltage for shields based on ENC28J60 is generally 3.3V.

4. Another alternative is to use the ENC28J60 UIPEthernet library, available from
https://github.com/ntruchsess/arduino_uip. This library was made so that
mimics the same standard Ethernet library functions, whose work is done by
Wiznet W5100 chip. As the ENC28J60 not have all the features of the other chip, the library
UIPEthernet uses a lot of memory, as it has to do in software what in the shield Wiznet
is made in hardware. If for some reason you need to use this library, just change
the file ModbusEthernet.h and your sketches, changing the lines:

		#include <Ethernet.h>

by

		#include <UIPEthernet.h>

Then, you can use the ModbusEthernet library (not the ModbusEthercard).
In fact it allows any library or skecth, made for
Wiznet shield be used in shield ENC28J60. The big problem with this approach
(and why we chose EtherCard) is that UIPEthernet library + ModbusEthernet uses about 60%
arduino program memory, whereas with Ethercard + ModbusEthercard
this value drops to 30%!


License
=======
The code in this repo is licensed under the BSD New License. See LICENSE for more info.

