/*
 * I2C_Private.h
 *
 * Created: 1/8/2023 12:01:47 AM
 *  Author: fathi
 */ 


#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_


#define TWBR_REG     *((volatile  u8*)0x20)
#define TWSR_REG     *((volatile  u8*)0x21)
#define TWCR_REG     *((volatile  u8*)0x56)
#define TWAR_REG     *((volatile  u8*)0x22)
#define TWDR_REG     *((volatile  u8*)0x23)

#endif /* I2C_PRIVATE_H_ */