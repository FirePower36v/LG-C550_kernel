#
# Makefile fragment for Linux 2.6
# Broadcom DHD Driver
#
# Copyright (C) 2008, Broadcom Corporation
# All Rights Reserved.
# 
# THIS SOFTWARE IS OFFERED "AS IS", AND BROADCOM GRANTS NO WARRANTIES OF ANY
# KIND, EXPRESS OR IMPLIED, BY STATUTE, COMMUNICATION OR OTHERWISE. BROADCOM
# SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS
# FOR A SPECIFIC PURPOSE OR NONINFRINGEMENT CONCERNING THIS SOFTWARE.
#
# $Id: makefile.26,v 1.1.144.1 2008/05/07 22:53:44 Exp $

obj-$(CONFIG_BCM4329) += wireless.o

obj-$(CONFIG_BRCM_USE_STATIC_BUF) += brcm_static_buf.o

wireless-objs = \
	src/dhd/sys/dhd_linux.o \
	src/dhd/sys/dhd_linux_sched.o \
	src/shared/linux_osl.o \
	src/shared/bcmutils.o \
	src/dhd/sys/dhd_common.o \
	src/dhd/sys/dhd_custom_gpio.o \
	src/shared/siutils.o \
	src/shared/sbutils.o \
	src/shared/aiutils.o \
	src/shared/hndpmu.o \
	src/wl/sys/wl_iw.o \
	src/shared/bcmwifi.o \
	src/dhd/sys/dhd_cdc.o \
	src/dhd/sys/dhd_sdio.o \
	src/bcmsdio/sys/bcmsdh_sdmmc.o \
	src/bcmsdio/sys/bcmsdh.o \
	src/bcmsdio/sys/bcmsdh_linux.o \
	src/bcmsdio/sys/bcmsdh_sdmmc_linux.o \

SRCROOT = drivers/net/wireless/bcm4329/src
EXTRA_CFLAGS = \
	-DLINUX \
	-DBCMDRIVER \
	-DBCMDONGLEHOST \
	-DDHDTHREAD \
	-DBCMWPA2 \
	-DUNRELEASEDCHIP \
	-DBDC \
	-DTOE \
	-DDHD_BCMEVENTS \
	-DSHOW_EVENTS \
	-DBCMSDIO \
	-DDHD_GPL -DDHD_SCHED\
	-DBCMLXSDMMC \
	-DBCMPLATFORM_BUS \
	-DSDIO_ISR_THREAD \
	-Wall -Wstrict-prototypes \
	-Os \
	-I$(SRCROOT) \
	-I$(SRCROOT)/include \
	-I$(SRCROOT)/shared \
	-I$(SRCROOT)/dhd/sys \
	-I$(SRCROOT)/dongle \
	-I$(SRCROOT)/wl/sys \
	\
	-DIOCTL_RESP_TIMEOUT=2000 \
	-DSDIO_VENDOR_ID_BROADCOM=0x2d0 \
	-DSDIO_DEVICE_ID_BROADCOM_4325=0x4c6 \
	-DSDIO_DEVICE_ID_BROADCOM_4329=0x4329 \
	-DANDROID_SPECIFIC \
	-DDONGLEOVERLAYS \
	-DMMC_SDIO_ABORT \
#-DAP -DAPSTA_PINGTEST \

#	\
	-fshort-wchar \
	-D__KERNEL__ \
	-Iinclude \
	-Iinclude/asm/mach-default \
	-DBCMEMBEDIMAGE="<dongle/rte/wl/builds/4325b0/sdio-g-cdc-reclaim-idsup-wme/rtecdc.h>" \

ifeq ($(CONFIG_BCM4329_DEBUG),y)
EXTRA_CFLAGS += -DDHD_DEBUG -DSDTEST -DSRCBASE="\"$(SRCROOT)\""
endif

ifeq ($(CONFIG_BRCM_USE_STATIC_BUF),y)
EXTRA_CFLAGS += -DDHD_USE_STATIC_BUF
endif

ifeq ($(CONFIG_BRCM_USE_SOFTAP),y)
EXTRA_CFLAGS += -DSOFTAP
endif

EXTRA_CFLAGS += -Dlinux
EXTRA_CFLAGS += -DDHD_SDALIGN=32 -DMAX_HDR_READ=32 -DDHD_FIRSTREAD=32

#ifeq ($(CONFIG_MMC_MSM),y)
#CONFIG_MMC_MSM7X00A = y
#EXTRA_CFLAGS += -DCONFIG_MMC_MSM7X00A=1
#endif
#
#ifeq ($(CONFIG_MMC_MSM7X00A),y)
#EXTRA_CFLAGS += -Dlinux
#EXTRA_CFLAGS += -DDHD_SDALIGN=64 -DMAX_HDR_READ=64 -DDHD_FIRSTREAD=64
#endif
