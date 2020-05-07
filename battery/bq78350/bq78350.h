//*******************************************************************************
//
//  bq78350.h
//
//  This library provides a set of functions to communicate, control and interact
//  with the Gas-Gauging TI IC BQ78350.
//  This library follows the specification of the SMBus commands available on the
//  Technical Reference document named "sluuan7b"
//
//  Requirments:
//              -mbed.h
//              -string
//
//  Author: Lorenzo Stilo
//  Date: Jun 2016
//
//*******************************************************************************
#ifndef __BQ78350_H__
#define __BQ78350_H__


/* Mbed Includes */
#include "mbed.h"

/* Standard Includes */
#include <string>

/* BQHEX Includes */
#include "bqhex.h"

class BQ78350
{
    public:
        /* Default Constructor */
        BQ78350();
        
        /* Constructor with parameters */
        BQ78350(char Address);
        
        /* SMB Commands */
        //unsigned short      ManufacturerAccess(unsigned short Command);
        //unsigned int        RemainingCapacityAlarm();
        //unsigned int        RemainingTimeAlarm();
        BatteryM_Type        BatteryMode();
        //unsigned short      AtRate();
        unsigned int        AtRateTimeToFull();
        unsigned int        AtRateTimeToEmpty();
        unsigned int        AtRateOK();
        unsigned int        Temperature();
        unsigned int        Voltage();
        int                 Current();
        int                 AverageCurrent();
        unsigned int        MaxError();
        unsigned int        RelativeStateOfCharge();
        unsigned int        AbsoluteStateOfCharge();
        unsigned int        RemainingCapacity();
        //unsigned int        RemainingCapacity(unsigned int capacity);
        unsigned int        FullChargeCapacity();
        unsigned int        RunTimeToEmpty();
        unsigned int        AverageTimeToEmpty();
        unsigned int        AverageTimeToFull();
        unsigned int        ChargingCurrent();
        unsigned int        ChargingVoltage();
        BatteryS_Type       BatteryStatus();
        unsigned int        CycleCount();
        unsigned int        DesignCapacity();
        unsigned int        DesignVoltage();
        //Specification_Type  SpecificationInfo();
        //unsigned int        ManufacturerDate();
        //unsigned int        SerialNumber();
        string              ManufacturerName();
        string              DeviceName();
        string              DeviceChemistry();
        //string              ManufacturerData();
        HostFET_Type        HostFETControl();
        //GPIO_Type           GPIOStatus();
        //GPIO_Type           GPIOControl();
        //unsigned int        VAUXVoltage();
        //void                Authenticate();
        unsigned int        CellVoltage5();
        unsigned int        CellVoltage4();
        unsigned int        CellVoltage3();
        unsigned int        CellVoltage2();
        unsigned int        CellVoltage1();
        unsigned int        ExtAveCellVoltage();
        unsigned int        PendingEDV();
        unsigned int        StateOfHealth();
        //unsigned int        SafetyAlert();
        //unsigned int        SafetyStatus();
        //unsigned int        PFAlert();
        //unsigned int        PFStatus();
        Operation_Type      OperationStatus();
        Charging_Type       ChargingStatus();
        Gauging_Type        GaugingStatus();
        Manufacturing_Type  ManufacturingStatus();
        //unsigned int    AFEStatus();
        //string          AFEConfig();
        //string          AFEVCx();
        //string          AFEData();
        //string          ManufacturerInfo();        
        
    private:
        /* Change SMBus Address, rather then default  */
        void            WriteAddress(char Address);
        
        /* Method used to read every Unsigned Int data coming fromt the BQ */
        unsigned int    ReadUnsignedInt(char cmd_byte, char num_bytes);
        
        /* Method used to read every Int data coming fromt the BQ */
        int             ReadInt(char cmd_byte, char num_bytes);
        
        /* Method used to read every String data coming fromt the BQ */
        string          ReadString(char cmd_byte, char num_bytes);
        
        /* Method used to read every Hex data coming fromt the BQ */
        unsigned int    ReadHex(char cmd_byte, char num_bytes);
    
    protected:
    
        /* SMBus Address */
        char            SMB_Address;
        
        /* Serial Interface used to communicate with the BQ IC */
        I2C             Interface;
    
};

#endif