//*******************************************************************************
//
//  battery.cpp
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
#include "battery.h"

Battery::Battery():
    SystemSemaphore(1),
    updateStatusTh(&Battery::statusStarter, this, osPriorityNormal,1024),
    updateTh(&Battery::updateStarter, this, osPriorityNormal,1024)
{
    Normal_Status = true;
}

void Battery::UpdateStatus()
{
    while(1)
    {
        SystemSemaphore.wait();

        StateOfHealth = Device.StateOfHealth();
        RelativeStateOfCharge = Device.RelativeStateOfCharge();
        MaxError = Device.MaxError();
        BatteryStatus = Device.BatteryStatus();
        OperationStatus = Device.OperationStatus();
        
        if (    
                (StateOfHealth < 45)            or
                (MaxError > 40)                 or
                (RelativeStateOfCharge < 15)    or
                (BatteryStatus.bits.OTA)        or
                (BatteryStatus.bits.OCA)        or
                (BatteryStatus.bits.RCA)        or
                (BatteryStatus.bits.RTA)        or
                (OperationStatus.bits.PCHG)     
            )
            Normal_Status = false;
        else
            Normal_Status = true;
        
        SystemSemaphore.release();
        Thread::wait(1000);
    }
}

void Battery::Normal()
{
    Normal_Status = true;
}

void Battery::Verbose()
{
    Normal_Status = false;
}

void Battery::Update()
{
    while(1)
    {    
        SystemSemaphore.wait();
        
        if (Normal_Status)
        {
            RelativeStateOfCharge = Device.RelativeStateOfCharge();
            StateOfHealth = Device.StateOfHealth();
            RunTimeToEmpty = Device.RunTimeToEmpty();
            AverageTimeToEmpty = Device.AverageTimeToEmpty();
            AverageTimeToFull = Device.AverageTimeToFull();
            Voltage = Device.Voltage();
            Current = Device.Current();
            ExtAveCellVoltage = Device.ExtAveCellVoltage();
        }
        else
        {
            BatteryMode = Device.BatteryMode();
            AtRateTimeToFull = Device.AtRateTimeToFull();
            AtRateTimeToEmpty = Device.AtRateTimeToEmpty();
            AtRateOK = Device.AtRateOK();
            Temperature = Device.Temperature();
            Voltage = Device.Voltage();
            Current = Device.Current();
            AverageCurrent = Device.AverageCurrent();
            MaxError = Device.MaxError();
            RelativeStateOfCharge = Device.RelativeStateOfCharge();
            AbsoluteStateOfCharge = Device.AbsoluteStateOfCharge();
            RemainingCapacity = Device.RemainingCapacity();
            FullChargeCapacity = Device.FullChargeCapacity();
            RunTimeToEmpty = Device.RunTimeToEmpty();
            AverageTimeToEmpty = Device.AverageTimeToEmpty();
            AverageTimeToFull = Device.AverageTimeToFull();
            ChargingCurrent = Device.ChargingCurrent();
            ChargingVoltage = Device.ChargingVoltage();
            BatteryStatus = Device.BatteryStatus();
            CycleCount = Device.CycleCount();
            DesignCapacity = Device.DesignCapacity();
            DesignVoltage = Device.DesignVoltage();
            //ManufacturerName = Device.ManufacturerName();
            //DeviceName = Device.DeviceName();
            //DeviceChemistry = Device.DeviceChemistry();
            //ManufacturerData = Device.ManufacturerData();
            CellVoltage4 = Device.CellVoltage4();
            CellVoltage3 = Device.CellVoltage3();
            CellVoltage2 = Device.CellVoltage2();
            CellVoltage1 = Device.CellVoltage1();
            ExtAveCellVoltage = Device.ExtAveCellVoltage();
            PendingEDV = Device.PendingEDV();
            StateOfHealth = Device.StateOfHealth();
            OperationStatus = Device.OperationStatus();
            ChargingStatus = Device.ChargingStatus();
            GaugingStatus = Device.GaugingStatus();
            ManufacturingStatus = Device.ManufacturingStatus();
        }
        SystemSemaphore.release();
        Thread::wait(5000);
    }
    
}

bool Battery::GetStatus()
{
    return Normal_Status;
}

void Battery::statusStarter(void const *p)
{
    Battery *instance = (Battery*)p;
    instance->UpdateStatus();
}

void Battery::updateStarter(void const *p)
{
    Battery *instance = (Battery*)p;
    instance->Update();
}
