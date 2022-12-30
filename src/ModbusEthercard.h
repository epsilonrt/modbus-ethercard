/*
    ModbusEthercard.h - Header for Modbus TCP using Ethercard ENC28J60 Library
    Copyright (C) 2015 André Sarmento Barbosa
*/
#include <Arduino.h>
#include <Modbus.h>
#include <EtherCard.h>

#pragma once

#define MODBUSIP_PORT     502 ///< TCP/IP port of MODBUS service
#define MODBUSIP_MAXFRAME 200 ///< Maximum length of frame
#define ENC28J60_CS       10 ///< Default chip select pin
//#define TCP_KEEP_ALIVE

/**
   @class ModbusEthercard
   @brief Modbus over TCP/IP network Class for ENC28J60 controller
*/
class ModbusEthercard : public Modbus {
  private:
    byte _MBAP[7];

  public:
    /**
       @brief Default constructor
    */
    ModbusEthercard();
    /**
       @brief Connect a ModbusEthercard object to a network
       @param mac the MAC (Media access control) address for the device
       (array of 6 bytes). this is the Ethernet hardware address of your shield.
       Newer Arduino Ethernet Shields include a sticker with the device's
       MAC address. For older shields, choose your own.
    */
    void config (uint8_t * mac);
    /**
       @brief Connect a ModbusEthercard object to a network
       @param mac the MAC (Media access control) address for the device
       (array of 6 bytes). this is the Ethernet hardware address of your shield.
       Newer Arduino Ethernet Shields include a sticker with the device's
       MAC address. For older shields, choose your own.
       @param ip the IP address of the device (array of 4 bytes)
    */
    void config (uint8_t * mac, uint8_t * ip);
    /**
       @brief Connect a ModbusEthercard object to a network
       @param mac the MAC (Media access control) address for the device
       (array of 6 bytes). this is the Ethernet hardware address of your shield.
       Newer Arduino Ethernet Shields include a sticker with the device's
       MAC address. For older shields, choose your own.
       @param ip the IP address of the device (array of 4 bytes)
       @param dns the IP address of the DNS server (array of 4 bytes).
       optional: defaults to the device IP address with the last octet set to 1
    */
    void config (uint8_t * mac, uint8_t * ip, uint8_t * dns);
    /**
       @brief Connect a ModbusEthercard object to a network
       @param mac the MAC (Media access control) address for the device
       (array of 6 bytes). this is the Ethernet hardware address of your shield.
       Newer Arduino Ethernet Shields include a sticker with the device's
       MAC address. For older shields, choose your own.
       @param ip the IP address of the device (array of 4 bytes)
       @param dns the IP address of the DNS server (array of 4 bytes).
       optional: defaults to the device IP address with the last octet set to 1
       @param gateway the IP address of the network gateway (array of 4 bytes).
       optional: defaults to the device IP address with the last octet set to 1
    */
    void config (uint8_t * mac, uint8_t * ip, uint8_t * dns, uint8_t * gateway);
    /**
       @brief Connect a ModbusEthercard object to a network
       @param mac the MAC (Media access control) address for the device
       (array of 6 bytes). this is the Ethernet hardware address of your shield.
       Newer Arduino Ethernet Shields include a sticker with the device's
       MAC address. For older shields, choose your own.
       @param ip the IP address of the device (array of 4 bytes)
       @param dns the IP address of the DNS server (array of 4 bytes).
       optional: defaults to the device IP address with the last octet set to 1
       @param gateway the IP address of the network gateway (array of 4 bytes).
       optional: defaults to the device IP address with the last octet set to 1
       @param subnet the subnet mask of the network (array of 4 bytes). optional: defaults to 255.255.255.0
    */
    void config (uint8_t * mac, uint8_t * ip, uint8_t * dns, uint8_t * gateway, uint8_t * subnet);
    /**
       @brief Task that performs all operations on MODBUS

       Call once inside loop(), all magic here !
    */
    void task();
};
