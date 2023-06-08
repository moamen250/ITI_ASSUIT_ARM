#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"

#include "MRCC_interface.h"
#include "MGPIO_interface.h"


void App_voidDelay()  ;

int main(void)
{
	/*System Clock is 16MHz from HSI*/
	MRCC_voidInitSystemClk();

	/*Enable GPIO Peripheral clock*/
	MRCC_voidEnablePeripheralClock(AHB1,_PERIPHERAL_EN_GPIOA ) ;

	/*Set Pin Mode --> Output*/
	MGPIO_voidSetPinMode(_GPIOA_PORT,_PIN_0, _MODE_OUTPUT) ;
	/*Out put Push Pull*/
	MGPIO_voidSetPinOutPutType(_GPIOA_PORT,_PIN_0,_OUTPUT_TYPE_PUSH_PULL);
	/*Pin Speed*/
	MGPIO_voidSetPinOutSpeed(_GPIOA_PORT, _PIN_0, _OUTPUT_SPEED_LOW);
	/*Set Pin Initial value -> High*/
	MGPIO_voidWriteData(_GPIOA_PORT, _PIN_0,_HIGH) ;
	while(1)
	{
		MGPIO_voidWriteData(_GPIOA_PORT, _PIN_0,_HIGH) ;
		App_voidDelay() ;
		MGPIO_voidWriteData(_GPIOA_PORT, _PIN_0,_LOW) ;
		App_voidDelay() ;
	}
}

void App_voidDelay()
{
	volatile u32 i= 0 ;
	for (i = 0 ; i < 2000000 ; i++)
	{
		asm("NOP") ; //No Operation
	}
}
















