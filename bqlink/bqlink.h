//*******************************************************************************
//
//  bqlink.h
//
//  This library provides a set of functions to communicate, controll and interact
//
//  Requirments:
//              -mbed.h
//              -rtos.h
//
//  Author: Lorenzo Stilo
//  Date: Jul 2016
//
//*******************************************************************************
#ifndef __BQLINK_H__
#define __BQLINK_H__

/* Inheritance includes */
#include "battery.h"

//#include "rtos.h"

class BQLink
{
    public:
        /* Default constructor */
        BQLink();
        
        /* Constructor with parameters */
        BQLink(PinName tx, PinName rx, unsigned int rate);
        
        void            UpdateRate(unsigned int rate);
        
    private:        
        void            SendData();
        void            SendNormal();
        void            SendVerbose();
        
        static void     SendDataStarter(void const *p);
    
    protected:
        Battery         BatteryInstance;
        Serial          Link;
        unsigned int    Rate;
        
        Thread          SendDataTh;
        
        Semaphore       SerialSemaphore;
};

#endif