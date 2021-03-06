#ifndef __APM_PPMDecoder_H__
#define __APM_PPMDecoder_H__

#define NUM_CHANNELS 8
#define MIN_PULSEWIDTH 900
#define MAX_PULSEWIDTH 2100

#include "APM_RC.h"
#include "../Arduino_Mega_ISR_Registry/Arduino_Mega_ISR_Registry.h"

class APM_PPMDecoder : public APM_RC_Class
{
private:
public:
    APM_PPMDecoder();
    void                    Init( Arduino_Mega_ISR_Registry * isr_reg );
    uint16_t                InputCh(unsigned char ch);
    unsigned char           GetState();
    bool                    setHIL(int16_t v[NUM_CHANNELS]);
    void                    clearOverride(void);


private:

    static void                     _timer5_capt_cb(void);
    static volatile uint16_t        _PWM_RAW[NUM_CHANNELS];
    static volatile uint8_t         _radio_status;
    int16_t                         _HIL_override[NUM_CHANNELS];
};


#endif
