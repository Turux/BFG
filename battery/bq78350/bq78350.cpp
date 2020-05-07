//*******************************************************************************
//
//  bq78350.cpp
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

#include "bq78350.h"

BQ78350::BQ78350()
: Interface(p9,p10)
{
    SMB_Address=0x16;
}

BQ78350::BQ78350(char Address)
: Interface(p9,p10)
{
    SMB_Address=Address;
}

void BQ78350::WriteAddress(char Address)
{
    SMB_Address = Address;
}

unsigned int BQ78350::ReadUnsignedInt(char cmd_byte, char num_bytes)
{
    char cmd[1];
    char data[num_bytes];
    cmd[0] = cmd_byte;
    Interface.write(SMB_Address, cmd, 1);
    
    Interface.read(SMB_Address, data, num_bytes);
    
    unsigned int tmp;
    
    switch (num_bytes)
    {
        case 01: tmp = (data[0]); break;
        case 02: tmp = (data[1]<<8)|data[0]; break;
        case 04: tmp = (data[3]<<24)|(data[2]<<16)|(data[1]<<8)|data[0]; break;
        default: tmp = (data[0]); break;
    }
    
    return tmp;
}

int BQ78350::ReadInt(char cmd_byte, char num_bytes)
{
    char cmd[1];
    char data[num_bytes];
    
    cmd[0] = cmd_byte;
    
    Interface.write(SMB_Address, cmd, 1);
    Interface.read(SMB_Address, data, num_bytes);

    int tmp;
    
    switch (num_bytes)
    {
        case 01: tmp = (data[0]); break;
        case 02: tmp = (data[1]<<8)|data[0]; break;
        case 04: tmp = (data[3]<<24)|(data[2]<<16)|(data[1]<<8)|data[0]; break;
        default: tmp = (data[0]); break;
    }
    
    return tmp;
}

string BQ78350::ReadString(char cmd_byte, char num_bytes)
{
    char cmd[1];
    char data[num_bytes];
    
    cmd[0] = cmd_byte;
    
    Interface.write(SMB_Address, cmd, 1);
    Interface.read(SMB_Address, data, num_bytes);
    
    int lenght = data[0];
    
    for (int i=0; i<lenght; i++)
        data[i] = data [i+1];
    
    string tmp(data);
    
    return tmp;
}

unsigned int BQ78350::ReadHex(char cmd_byte, char num_bytes)
{
    char cmd[1];
    char data[num_bytes];
    cmd[0] = cmd_byte;
    Interface.write(SMB_Address, cmd, 1);
    
    Interface.read(SMB_Address, data, num_bytes);
    
    unsigned int tmp;
    
    switch (num_bytes)
    {
        case 01: tmp = (data[0]); break;
        case 02: tmp = ((data[1]<<8)|data[0]); break;
        case 03: tmp = ((data[2]<<16)|(data[1]<<8)|data[0]); break;
        case 04: tmp = ((data[3]<<24)|(data[2]<<16)|(data[1]<<8)|data[0]); break;
        default: tmp = (data[0]); break;
    }
    
    return tmp;
}

BatteryM_Type BQ78350::BatteryMode()
{
    BatteryM_Type temp;
    temp.unicum = ReadUnsignedInt(0x03, 2);
    return temp;
}

unsigned int BQ78350::AtRateTimeToFull()
{
    return ReadUnsignedInt(0x05, 2);
}

unsigned int BQ78350::AtRateTimeToEmpty()
{
    return ReadUnsignedInt(0x06, 2);
}

unsigned int BQ78350::AtRateOK()
{
    return ReadUnsignedInt(0x07, 2);
}

unsigned int BQ78350::Temperature()
{
    return ReadUnsignedInt(0x08, 2);
}

unsigned int BQ78350::Voltage()
{
    return ReadUnsignedInt(0x09, 2);     
}

int BQ78350::Current()
{
    return ReadInt(0x0A, 2);
}

int BQ78350::AverageCurrent()
{
    return ReadInt(0x0B, 2);
}

unsigned int BQ78350::MaxError()
{
    return ReadUnsignedInt(0x0C, 1);
}

unsigned int BQ78350::RelativeStateOfCharge()
{
    return ReadUnsignedInt(0x0D, 1);
}

unsigned int BQ78350::AbsoluteStateOfCharge()
{
    return ReadUnsignedInt(0x0E, 1);
}

unsigned int BQ78350::RemainingCapacity()
{
    return ReadUnsignedInt(0x0F, 2);
}

unsigned int BQ78350::FullChargeCapacity()
{
    return ReadUnsignedInt(0x10, 2);
}

unsigned int BQ78350::RunTimeToEmpty()
{
    return ReadUnsignedInt(0x11, 2);
}

unsigned int BQ78350::AverageTimeToEmpty()
{
    return ReadUnsignedInt(0x12, 2);
}

unsigned int BQ78350::AverageTimeToFull()
{
    return ReadUnsignedInt(0x13, 2);
}

unsigned int BQ78350::ChargingCurrent()
{
    return ReadUnsignedInt(0x14, 2);
}

unsigned int BQ78350::ChargingVoltage()
{
    return ReadUnsignedInt(0x15, 2);
}

BatteryS_Type BQ78350::BatteryStatus()
{
    BatteryS_Type temp;
    temp.unicum = ReadUnsignedInt(0x16, 2);
    return temp;
}

unsigned int BQ78350::CycleCount()
{
    return ReadUnsignedInt(0x17, 2);
}

unsigned int BQ78350::DesignCapacity()
{
    return ReadUnsignedInt(0x18, 2);
}

unsigned int BQ78350::DesignVoltage()
{
    return ReadUnsignedInt(0x19, 2);
}

string       BQ78350::ManufacturerName()
{
    return ReadString(0x20,11);
}

string       BQ78350::DeviceName()
{
    return ReadString(0x21,7);
}

string       BQ78350::DeviceChemistry()
{
    return ReadString(0x22,5);
}

//string       BQ78350::ManufacturerData()
//{
//    return ReadString(0x23,15);
//}

HostFET_Type BQ78350::HostFETControl()
{
    HostFET_Type temp;
    temp.unicum = ReadUnsignedInt(0x2B, 2);
    return temp;
}

unsigned int BQ78350::CellVoltage5()
{
    return ReadUnsignedInt(0x3B, 2);
}

unsigned int BQ78350::CellVoltage4()
{
    return ReadUnsignedInt(0x3C, 2);
}

unsigned int BQ78350::CellVoltage3()
{
    return ReadUnsignedInt(0x3D, 2);
}

unsigned int BQ78350::CellVoltage2()
{
    return ReadUnsignedInt(0x3E, 2);
}

unsigned int BQ78350::CellVoltage1()
{
    return ReadUnsignedInt(0x3F, 2);
}

unsigned int BQ78350::ExtAveCellVoltage()
{
    return ReadUnsignedInt(0x4D, 2);
}

unsigned int BQ78350::PendingEDV()
{
    return ReadUnsignedInt(0x4E, 2);
}

unsigned int BQ78350::StateOfHealth()
{
    return ReadUnsignedInt(0x4F, 1);
}

Operation_Type BQ78350::OperationStatus()
{
    Operation_Type temp;
    temp.unicum = (ReadUnsignedInt(0x54, 4)>>8);
    return temp;
}

Charging_Type BQ78350::ChargingStatus()
{
    Charging_Type temp;
    temp.unicum = ReadHex(0x55,3);
    return temp;
}

Gauging_Type BQ78350::GaugingStatus()
{
    Gauging_Type temp;
    temp.unicum = ReadUnsignedInt(0x56, 3);
    return temp;
}

Manufacturing_Type BQ78350::ManufacturingStatus()
{
    Manufacturing_Type temp;
    temp.unicum = ReadUnsignedInt(0x57, 2);
    return temp;
}