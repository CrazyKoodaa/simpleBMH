#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#ifndef SIMULATOR
#include <cmsis_os2.h>
#include "main.h"
extern "C"
{
    extern osMessageQueueId_t myQueue1LeftHandle;
    extern osMessageQueueId_t myQueue1MiddleHandle;
    extern osStatus_t r_state;
#include "utils.h"
}
#endif

Model::Model() : modelListener(0),  trainerTemperatur(18), preassure01(0)
{

}

void Model::tick()
{
#ifndef SIMULATOR

    static uint16_t newTemp = 0;
    static uint16_t newPress = 0;
    //get new temperature from message queue (if any)
    myDebug((uint8_t*)"Queue Items Count ->    Get b4    -> ", osMessageQueueGetCount(myQueue1LeftHandle), info);
    r_state = osMessageQueueGet(myQueue1LeftHandle, &newTemp, NULL, 500);
    myDebug((uint8_t*)"Queue Items Count ->    Get b8    -> ", osMessageQueueGetCount(myQueue1LeftHandle), info);
    if (r_state == osOK)
    {
        //inform the view if temperature changed
        if (newTemp != trainerTemperatur)
        {
        	trainerTemperatur = newTemp;
            modelListener->trainerTemperaturChanged();
        }
    }

    r_state = osMessageQueueGet(myQueue1MiddleHandle, &newPress, NULL, 500);
    if (r_state == osOK)
    {
        //inform the view if preassure changed
        if (newPress != preassure01)
        {
        	preassure01 = newPress;
            modelListener->preassure01Changed();
        }
    }

#endif
}
