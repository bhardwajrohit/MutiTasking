#include <stdio.h>
#include <string.h>
#include "stm32f3xx_hal.h"
#include "common.h"

static uint32_t counter;

void CmdCount(int mode)
{
if(mode != CMD_INTERACTIVE)
 {
    return;
  }
  fetch_uint32_arg(&counter);
}

ADD_CMD("count",CmdCount,"             Taking the value");

void taskCounter(void)
  {
   if(counter != 0)
   {
    printf("The Counter is :%u\n",(unsigned)counter);
    counter--;
   }
 }
