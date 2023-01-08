/*
 * I2C_interface.c
 *
 * Created: 1/8/2023 12:02:30 AM
 *  Author: fathi
 */ 
#include "../header_files/LIB.h"
#include"../header_files/MATH.h"
#include"../header_files/I2C_Private.h"
#include"../header_files/I2C_interface.h"


void I2C_master_init(void){
	
	TWBR_REG=7 ; //  for 400K SCL and 12Mhz freq uc
	
	
}
void I2C_master_start(void){
	
	TWCR_REG= 1<<7|1<<5|1<<2 ; //  transmit START condition
	
	while(GET_BIT(TWCR_REG,7)==0) ;  // wait for end of transmission
	
	
	
}

void I2C_master_addr(u8 ID, u8 R_W){
	
	// for write you should put 0 on LSB
	// load slave address into data register
	TWDR_REG=ID<<1 ; 
	if(R_W==1){
		
		SET_BIT(TWDR_REG,0) ;
	
	} else {
		CLR_BIT(TWDR_REG,0) ;
		
	}
	TWCR_REG= 1<<7|1<<2 ; 	// start transmission of address
	
	while(GET_BIT(TWCR_REG,7)==0) ;  // wait for end of transmission Address
}

void I2C_master_write(u8 data){
	
	TWDR_REG=data ;// load data into data register
	TWCR_REG= 1<<7|1<<2 ; 	// start transmission of data
	while(GET_BIT(TWCR_REG,7)==0) ;  // wait for end of transmission data
	
}

void I2C_master_stop(void){
	
	// transmit STOP condition
		TWCR_REG= 1<<7|1<<4|1<<2 ; //  transmit Stop condition
	
	
	
}

void I2C_slave_Init(u8 My_Add){
	
	TWAR_REG=My_Add<<1 ;
	
}

u8 I2C_slave_avialable(){
	
	TWCR_REG= 1<<7|1<<6|1<<2 ; //  transmit acknowledge
	while(GET_BIT(TWCR_REG,7)==0) ;  // wait for end of transmission acknowledge
	
	if(TWSR_REG==0x60){
		
		return  1 ;  // Own SLA+W has been received;
		             //ACK has been returned
	}
	else {
		
		return 0 ;
	}
	
}


u8 I2C_slave_read(void){
	// start TWI module and acknowledge data after reception
	TWCR_REG= 1<<7|1<<6|1<<2 ;
	// wait for end of transmission
	while(GET_BIT(TWCR_REG,7)==0) ;
	
	// return received data from TWDR
	return TWDR_REG ;
	
	
}