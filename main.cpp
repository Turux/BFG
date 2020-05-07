#include "bqlink.h"

//DigitalOut myled(LED1);
//BQ78350 dev;
//Serial pc(USBTX, USBRX);



int main() 
{
   //string device = dev.DeviceName();
   //string manufacturer = dev.ManufacturerName();
   //string chem = dev.DeviceChemistry();
   //pc.printf("TEST 0 \r\n");
   BQLink Mbed(USBTX,USBRX,2000);
   //pc.printf("TEST 1 \r\n");
   
   //pc.printf("Device name: %s by %s \r\n", device.c_str(), manufacturer.c_str());
   
   while(1)
    {
        //unsigned int volt = dev.Voltage();
        //unsigned int soc  = dev.RelativeStateOfCharge();
        //unsigned int soh  = dev.StateOfHealth();
        
        //pc.printf("Device name: %s by %s \r\n", device.c_str(), manufacturer.c_str());
        //pc.printf("Using chemistry: %s \r\n", chem.c_str());
        
        //pc.printf("TEST 2 \r\n");
        
        //pc.printf("Voltage = %i mV \r\n", James.Voltage);
        //pc.printf("Current = %i mA \r\n", James.Current);
        //pc.printf("Capacity = %i mAh out of %i mAh \r\n", James.RemainingCapacity, James.DesignCapacity);
        //pc.printf("SoC = %i %  \r\n", James.RelativeStateOfCharge);
        //pc.printf("SoH = %i % \r\n", James.StateOfHealth);
        //wait_ms(2000);     
    }
}
