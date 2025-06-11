#include "led.h"
#include "keyboard.h"


int iTimeDelay;
int iStepCounter;

enum LedState {RIGHT_DIRECTION, LEFT_DIRECTION, STOP, WIPER, WAIT};				




void Delay(int milisec){
	int iterator;
	for(iterator=1; iterator<milisec*2000; iterator++){}
}


int main()
{

	enum LedState eLedState = STOP;	
	int iMigCounter = 0;
	int iLedNumber = 0;
	
  LedInit();
  KeyboardInit();
  while(1)
  {

			switch(eLedState)
			{
				case STOP:
					if(eKeyboardRead() == BUTTON_0)
					{
						eLedState = LEFT_DIRECTION;
					}
					else if(eKeyboardRead() == BUTTON_2)
					{
						eLedState = RIGHT_DIRECTION;
					}
					else if(eKeyboardRead() == BUTTON_3){
						eLedState = WIPER;
					}
				break;
				case RIGHT_DIRECTION:
					if(eKeyboardRead() == RELASED)
					{
						LedStepRight();
					}
					else if(eKeyboardRead() == BUTTON_1){
						eLedState = STOP;
					}
				break;
				case LEFT_DIRECTION:
					if(eKeyboardRead() == RELASED){
						LedStepLeft();
					}
					if(eKeyboardRead() == BUTTON_1){
						eLedState = STOP;
					}
				break;
				case WIPER:
					if(iMigCounter==7){
						iMigCounter = 0;
						eLedState = WAIT;
					}
					else{
						iMigCounter++;
						if(iLedNumber==0){
							LedOn(0);
							iLedNumber=1;
						}
						else if(iLedNumber==1){
							LedOn(1);
							iLedNumber=0;
						}
					}
				break;
				case WAIT:
						if(eKeyboardRead() == BUTTON_2){
							eLedState = RIGHT_DIRECTION;
						}
						else{}
				break;
			}
			Delay(100);
  }
}
