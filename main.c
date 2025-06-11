#include "led.h"
#include "keyboard.h"


int iTimeDelay;
int iStepCounter;

//enum LedState {RIGHT_DIRECTION, LEFT_DIRECTION};												//ZADANIE 3
//enum LedState {RIGHT_DIRECTION, STOP};																		//Zadanie 4 i 5
enum LedState {RIGHT_DIRECTION, LEFT_DIRECTION, STOP};										//Zadanie 6




void Delay(int iMiliseconds)
{

  int iLoopIteration;
  iTimeDelay = (iMiliseconds * 5456);

  for(iLoopIteration = 0 ; iLoopIteration < iTimeDelay ; iLoopIteration++)
  {

  }
}


int main()
{
	
	//enum LedState eLedState = LEFT_DIRECTION;								//ZADANIE 3
	//enum LedState eLedState = STOP;													//ZADANIE 4
	//enum LedState eLedState = RIGHT_DIRECTION;							//ZADANIE 5
	enum LedState eLedState = STOP;													//ZADANIE 6
		
	
  LedInit();
  KeyboardInit();
  while(1)
  {
		
//*************************************					ZADANIE 3					*************************************
//			switch(eLedState)
//			{
//				case LEFT_DIRECTION:
//					if(iStepCounter % 3 != 0)
//					{
//						LedStepLeft();
//						iStepCounter++;
//					}
//					else if(iStepCounter % 3 == 0)
//					{
//						eLedState = RIGHT_DIRECTION;
//					}
//					break;
//				case RIGHT_DIRECTION:
//					if(iStepCounter % 3 != 0)
//					{
//						LedStepRight();
//						iStepCounter++;
//					}
//					else if(iStepCounter % 3 == 0)
//					{
//						eLedState = LEFT_DIRECTION;
//					}
//					break;
//			}
//			Delay(250);
			
//*************************************					ZADANIE 4					*************************************
//			switch(eLedState)
//			{
//				case STOP:
//					if(eKeyboardRead() == BUTTON_0)
//					{
//						eLedState = RIGHT_DIRECTION;
//					}
//					break;
//				case RIGHT_DIRECTION:
//					if(iStepCounter % 3 != 0)
//					{
//						LedStepRight();
//						iStepCounter++;
//					}	
//					else if(iStepCounter % 3 == 0)
//					{
//						eLedState = STOP;
//					}
//					break;
//				
//			}
//			Delay(250);
			
			
			
			
//*************************************					ZADANIE 5					*************************************
//			switch(eLedState)
//			{
//				case STOP:
//					if(eKeyboardRead() == BUTTON_1)
//					{
//						eLedState = RIGHT_DIRECTION;
//					}
//					break;
//				case RIGHT_DIRECTION:
//					if(eKeyboardRead() == RELASED)
//					{
//						LedStepRight();
//					}
//					if(eKeyboardRead() == BUTTON_0)
//					{
//						eLedState = STOP;
//					}
//					break;
//				
//			}
//			Delay(250);
			
			
//*************************************					ZADANIE 6					*************************************
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
					break;
				case RIGHT_DIRECTION:
					if(eKeyboardRead() == RELASED)
					{
						LedStepRight();
					}
					else if(eKeyboardRead() == BUTTON_1)
					{
						eLedState = STOP;
					}
					break;
					case LEFT_DIRECTION:
					if(eKeyboardRead() == RELASED)
					{
						LedStepLeft();
					}
					if(eKeyboardRead() == BUTTON_1)
					{
						eLedState = STOP;
					}
					break;
				
			}
			Delay(100);
  }
}
