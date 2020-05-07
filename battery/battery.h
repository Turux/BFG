//*******************************************************************************
//
//  battery.h
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
//  Date: Jul 2016
//
//*******************************************************************************
#ifndef __BATTERY_H__
#define __BATTERY_H__

#include "bq78350.h"

#include "rtos.h"

class Battery
{
    public:
        /* Default Constructor */
        Battery();
        
        bool                GetStatus();
        
        /* Members */
        BatteryM_Type       BatteryMode;
        unsigned int        AtRateTimeToFull;
        unsigned int        AtRateTimeToEmpty;
        bool                AtRateOK;
        unsigned int        Temperature;
        unsigned int        Voltage;
        int                 Current;
        int                 AverageCurrent;
        unsigned int        MaxError;
        unsigned int        RelativeStateOfCharge;
        unsigned int        AbsoluteStateOfCharge;
        unsigned int        RemainingCapacity;
        unsigned int        FullChargeCapacity;
        unsigned int        RunTimeToEmpty;
        unsigned int        AverageTimeToEmpty;
        unsigned int        AverageTimeToFull;
        unsigned int        ChargingCurrent;
        unsigned int        ChargingVoltage;
        BatteryS_Type       BatteryStatus;
        unsigned int        CycleCount;
        unsigned int        DesignCapacity;
        unsigned int        DesignVoltage;
        string              ManufacturerName;
        string              DeviceName;
        string              DeviceChemistry;
        string              ManufacturerData;
        unsigned int        CellVoltage4;
        unsigned int        CellVoltage3;
        unsigned int        CellVoltage2;
        unsigned int        CellVoltage1;
        unsigned int        ExtAveCellVoltage;
        unsigned int        PendingEDV;
        unsigned int        StateOfHealth;
        Operation_Type      OperationStatus;
        Charging_Type       ChargingStatus;
        Gauging_Type        GaugingStatus;
        Manufacturing_Type  ManufacturingStatus;
        
        
    private:
        void                Normal();
        void                Verbose();
        void                UpdateStatus();
        /* Update the values */
        void                Update();
        
        static void         updateStarter(void const *p);
        static void         statusStarter(void const *p);
    
    protected:
        BQ78350             Device;
        bool                Normal_Status;
        
        Semaphore           SystemSemaphore;
        
        Thread              updateStatusTh;
        Thread              updateTh;
};

#endif
