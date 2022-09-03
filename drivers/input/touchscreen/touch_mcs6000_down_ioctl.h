/*
 * drivers/input/touchscreen/mcs6000_ts_ioctl.h
 *
 * Header file of Touch Driver
 * 
 * Copyright (C) 2008 LGE Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef _MCS6000_TS_DOWN_IOCTL_H_
#define _MCS6000_TS_DOWN_IOCTL_H_

#include <asm/ioctl.h>

struct mcs6000_ts_down_ioctl_i2c_type {
	int addr;
	int data;
};

#define MCS6000_TS_DOWN_IOCTL_MAGIC 'D'

#define MCS6000_TS_DOWN_IOCTL_VDD_HIGH  	_IO( MCS6000_TS_DOWN_IOCTL_MAGIC, 0)
#define MCS6000_TS_DOWN_IOCTL_VDD_LOW 		_IO( MCS6000_TS_DOWN_IOCTL_MAGIC, 1)

#define MCS6000_TS_DOWN_IOCTL_INTR_HIGH 	_IO( MCS6000_TS_DOWN_IOCTL_MAGIC, 2)
#define MCS6000_TS_DOWN_IOCTL_INTR_LOW 		_IO( MCS6000_TS_DOWN_IOCTL_MAGIC, 3)
#define MCS6000_TS_DOWN_IOCTL_INTR_OUT 		_IO( MCS6000_TS_DOWN_IOCTL_MAGIC, 4)
#define MCS6000_TS_DOWN_IOCTL_INTR_IN 		_IO( MCS6000_TS_DOWN_IOCTL_MAGIC, 5)

#define MCS6000_TS_DOWN_IOCTL_SCL_HIGH		_IO( MCS6000_TS_DOWN_IOCTL_MAGIC, 6)
#define MCS6000_TS_DOWN_IOCTL_SCL_LOW		_IO( MCS6000_TS_DOWN_IOCTL_MAGIC, 7)
#define MCS6000_TS_DOWN_IOCTL_SDA_HIGH		_IO( MCS6000_TS_DOWN_IOCTL_MAGIC, 8)
#define MCS6000_TS_DOWN_IOCTL_SDA_LOW		_IO( MCS6000_TS_DOWN_IOCTL_MAGIC, 9)
#define MCS6000_TS_DOWN_IOCTL_SCL_OUT		_IO( MCS6000_TS_DOWN_IOCTL_MAGIC, 10)
#define MCS6000_TS_DOWN_IOCTL_SDA_OUT		_IO( MCS6000_TS_DOWN_IOCTL_MAGIC, 11)

#define MCS6000_TS_DOWN_IOCTL_I2C_ENABLE 	_IO( MCS6000_TS_DOWN_IOCTL_MAGIC, 12)
#define MCS6000_TS_DOWN_IOCTL_I2C_DISABLE   _IO( MCS6000_TS_DOWN_IOCTL_MAGIC, 13)

#define MCS6000_TS_DOWN_IOCTL_I2C_READ   	_IOWR( MCS6000_TS_DOWN_IOCTL_MAGIC, 14, struct mcs6000_ts_down_ioctl_i2c_type)
#define MCS6000_TS_DOWN_IOCTL_I2C_WRITE   	_IOWR( MCS6000_TS_DOWN_IOCTL_MAGIC, 15, struct mcs6000_ts_down_ioctl_i2c_type)

/* 16 */

#define MCS6000_TS_DOWN_IOCTL_SELECT_TS_TYPE 	_IO( MCS6000_TS_DOWN_IOCTL_MAGIC, 17)

// LGE_CHANGE_S dangwoo.choi - added for MCS7000
#define MCS6000_TS_DOWN_IOCTL_SDA_INPUT 		_IO( MCS6000_TS_DOWN_IOCTL_MAGIC, 18)
#define MCS6000_TS_DOWN_IOCTL_SDA_DATA 			_IO( MCS6000_TS_DOWN_IOCTL_MAGIC, 19)
// LGE_CHANGE_E dangwoo.choi - added for MCS7000

#define MCS6000_TS_DOWN_IOCTL_MAXNR 20

#endif
