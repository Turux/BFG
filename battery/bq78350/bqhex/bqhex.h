#ifndef __BQHEX_H__
#define __BQHEX_H__

#include "stdint.h"


typedef union
{
    struct
    {
        bool ICC  : 1;
        bool PBS  : 1;
        unsigned char RSVD_0 : 5;
        bool CF  : 1;
        bool CC  : 1;
        bool PB  : 1;
        unsigned char RSVD_1 : 3;
        bool AM  : 1;
        bool CHGM  : 1;
        bool CHPM  : 1;
    }bits;
    uint16_t unicum;
  
}BatteryM_Type;

typedef union
{
    struct
    {
        unsigned char EC : 4;
        bool FD : 1;
        bool FC : 1;
        bool DSG : 1;
        bool INIT : 1;
        bool RTA : 1;
        bool RCA : 1;
        bool RSVD_0 : 1;
        bool TDA : 1;
        bool OTA : 1;
        bool RSVD_1  : 1;
        bool TCA : 1;
        bool OCA : 1;
    }bits;
    uint16_t unicum;
  
}BatteryS_Type;

typedef union
{
    struct
    {
        unsigned char REV : 4;
        unsigned char VER : 4;
        unsigned char VSCALE : 4;
        unsigned char IPSCALE : 4;
    }bits;
    uint16_t unicum;
  
}Specification_Type;

typedef union
{
    struct
    {
        bool CHG : 1;
        bool DSG : 1;
        bool PCHG : 1;
        unsigned int RSVD : 13;
    }bits;
    uint16_t unicum;
  
}HostFET_Type;

typedef union
{
    struct
    {
        bool RSVD : 1;
        bool LED1 : 1;
        bool LED2 : 1;
        bool LED3 : 1;
        bool LED4 : 1;
        bool LED5 : 1;
        bool GPIOA : 1;
        bool GPIOB : 1;
    }bits;
    uint8_t unicum;
  
}GPIO_Type;

typedef union
{
    struct
    {
        bool PRES : 1;              //Bit 0
        bool CHG : 1;               //Bit 1
        bool DSG : 1;               //Bit 2
        bool PCHG : 1;              //Bit 3
        bool RSVD_0 : 1;            //Bit 4
        bool SAFE : 1;              //Bit 5
        unsigned char RSVD_1 : 2;   //Bit 6-7
        unsigned char SEC : 2;      //Bit 8-9
        bool SDV : 1;               //Bit 10
        bool SS : 1;                //Bit 11
        bool PF : 1;                //Bit 12
        bool XDSG : 1;              //Bit 13
        bool XCHG : 1;              //Bit 14
        bool SLEEP : 1;             //Bit 15
        bool SDM : 1;               //Bit 16
        bool LED : 1;               //Bit 17
        bool AUTH : 1;              //Bit 18
        bool RSVD_2 : 1;            //Bit 19
        bool CAL : 1;               //Bit 20
        unsigned char RSVD_3 : 2;   //Bit 21-22
        bool SLEEPM : 1;            //Bit 23
        bool INIT : 1;              //Bit 24
        unsigned char RSVD_4 : 3;   //Bit 25-27
        bool CB : 1;                //Bit 28
        unsigned char RSVD_5 : 2;   //Bit 29-30
        bool KEY_IN : 1;            //Bit 31
    }bits;
    uint32_t unicum;
  
}Operation_Type;

typedef union
{
    struct
    {
        bool PCHG : 1;              //Bit 0
        bool FCHG : 1;              //Bit 1
        unsigned char RSVD_0 : 2;   //Bit 2-3
        bool IN : 1;                //Bit 4
        bool SU : 1;                //Bit 5
        bool RSVD_1 : 1;            //Bit 6
        bool VCT : 1;               //Bit 7
        bool UT : 1;                //Bit 8
        bool LT : 1;                //Bit 9
        bool ST : 1;                //Bit 10
        bool HT : 1;                //Bit 11
        bool OT : 1;                //Bit 12    
        unsigned char RSVD_2 : 3;   //Bit 13-15
    }bits;
    uint16_t unicum;
  
}Charging_Type;

typedef union
{
    struct
    {
        bool FD : 1;                //Bit 0
        bool FC : 1;                //Bit 1
        bool TD : 1;                //Bit 2
        bool TC : 1;                //Bit 3
        bool BAL_OK : 1;            //Bit 4
        bool EDV0 : 1;              //Bit 5
        bool DSG : 1;               //Bit 6
        bool CF : 1;                //Bit 7
        bool REST : 1;              //Bit 8
        bool OCVFR : 1;             //Bit 9
        bool FCCX : 1;              //Bit 10
        unsigned char RSVD : 2;     //Bit 11-12
        bool EDV1 : 1;              //Bit 13
        bool EDV2 : 1;              //Bit 14    
        bool VDQ : 1;               //Bit 15
    }bits;
    uint16_t unicum;
  
}Gauging_Type;

typedef union
{
    struct
    {
        bool PCHG_TEST : 1;         //Bit 0
        bool CHG_TEST : 1;          //Bit 1
        bool DSG_TEST : 1;          //Bit 2
        bool RSVD_0 : 1;            //Bit 3
        bool FET_EN : 1;            //Bit 4
        bool LF_EN : 1;             //Bit 5
        bool PF_EN : 1;             //Bit 6
        bool BBR_EN : 1;            //Bit 7
        bool SAFE_EN : 1;           //Bit 8
        bool LED_EN : 1;            //Bit 9
        unsigned char RSVD_1 : 2;   //Bit 10-11
        bool AFE_DD_TEST : 1;       //Bit 12
        bool CB_TEST : 1;           //Bit 13
        bool LT_TEST : 1;           //Bit 14    
        bool CAL_EN : 1;            //Bit 15
    }bits;
    uint16_t unicum;
  
}Manufacturing_Type;

#endif