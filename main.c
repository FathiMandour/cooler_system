/*
 * I2C_Slave2.c
 *
 * Created: 1/8/2023 3:14:26 AM
 * Author : fathi
 */ 

#include "header_files/LIB.h"
#include"header_files/MATH.h"
#include"header_files/I2C_Private.h"
#include"header_files/I2C_interface.h"
#include "header_files/LCD_interface.h"
#define  F_CPU 12000000UL
#include<util/delay.h>





int main(void)
{
	u8 recive =0 ;
	// inilize lcd 
	LCD_init() ;
	//  51 --> address for slave 
	I2C_slave_Init(51) ;
	// write string in lcd 
	LCD_write_string("odd=") ;
	while (1)
	{
		
		// check if slave available 
		if (I2C_slave_avialable()==1){
			
			// read data 
			recive=I2C_slave_read() ;
			// send command to write in 0x84 pattern 
			LCD_write_command(0x84) ;
			LCD_write_number(recive) ;
			
			
		}
		
	}
}
