#include "bqlink.h"

BQLink::BQLink():
    Link(USBTX, USBRX),
    SerialSemaphore(1),
    SendDataTh(&BQLink::SendDataStarter, this, osPriorityNormal,1024)
{
    Rate = 2000;
}

BQLink::BQLink(PinName tx, PinName rx, unsigned int rate):
    Link(tx,rx),
    SerialSemaphore(1),
    SendDataTh(&BQLink::SendDataStarter, this, osPriorityNormal,1024)
{
    Rate = rate;
}

void BQLink::UpdateRate(unsigned int rate)
{
    Rate = rate;
}

void BQLink::SendNormal()
{
    SerialSemaphore.wait();
    Link.printf("Normal Mode \r\n");
    Link.printf("Voltage = %i mV \r\n", BatteryInstance.Voltage);
    Link.printf("Current = %i mA \r\n", BatteryInstance.Current);
    Link.printf("Capacity = %i mAh out of %i mAh \r\n", BatteryInstance.RemainingCapacity, BatteryInstance.DesignCapacity);
    Link.printf("SoC = %i %  \r\n", BatteryInstance.RelativeStateOfCharge);
    Link.printf("SoH = %i % \r\n", BatteryInstance.StateOfHealth);
    SerialSemaphore.release();
}

void BQLink::SendVerbose()
{
    SerialSemaphore.wait();
    Link.printf("Verbose Mode \r\n");
    Link.printf("Voltage = %i mV \r\n", BatteryInstance.Voltage);
    Link.printf("Current = %i mA \r\n", BatteryInstance.Current);
    Link.printf("Capacity = %i mAh out of %i mAh \r\n", BatteryInstance.RemainingCapacity, BatteryInstance.DesignCapacity);
    Link.printf("SoC = %i %  \r\n", BatteryInstance.RelativeStateOfCharge);
    Link.printf("SoH = %i % \r\n", BatteryInstance.StateOfHealth);
    if (BatteryInstance.BatteryStatus.bits.DSG)
    Link.printf("Battery is discharging \r\n");
    else
    Link.printf("Battery is charging \r\n");
    if (BatteryInstance.OperationStatus.bits.PCHG)
    Link.printf("Battery is in Pre-charge mode \r\n");
    Link.printf("OperationStatus %x \r\n", BatteryInstance.OperationStatus.unicum);
    Link.printf("ChargingStatus %x \r\n", BatteryInstance.ChargingStatus.unicum);
    Link.printf("GaugingStatus %x \r\n", BatteryInstance.GaugingStatus.unicum);
    Link.printf("ManufacturingStatus %x \r\n", BatteryInstance.ManufacturingStatus.unicum);
    Link.printf("Cell1  = %i mV \r\n", BatteryInstance.CellVoltage1);
    Link.printf("Cell2  = %i mV \r\n", BatteryInstance.CellVoltage2);
    Link.printf("Cell3  = %i mV \r\n", BatteryInstance.CellVoltage3);
    Link.printf("Cell4  = %i mV \r\n", BatteryInstance.CellVoltage4);
    SerialSemaphore.release();
}

void BQLink::SendData()
{
    while(1)
    {
        if(BatteryInstance.GetStatus())
        SendNormal();
        else
        SendVerbose();
        Thread::wait(Rate);
    }
    
}

void BQLink::SendDataStarter(void const *p)
{
    BQLink *instance = (BQLink*)p;
    instance->SendData();
}