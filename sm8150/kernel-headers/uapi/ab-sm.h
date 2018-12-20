/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ***   To edit the content of this header, modify the corresponding
 ***   source file (e.g. under external/kernel-headers/original/) then
 ***   run bionic/libc/kernel/tools/update_all.py
 ***
 ***   Any manual change here will be lost the next time this script will
 ***   be run. You've been warned!
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef __UAPI_AB_SM_H__
#define __UAPI_AB_SM_H__
#include <linux/ioctl.h>
#define AB_SM_IOCTL_MAGIC 'a'
#define AB_SM_ASYNC_NOTIFY _IOR(AB_SM_IOCTL_MAGIC, 0, int *)
#define AB_SM_SET_STATE _IOW(AB_SM_IOCTL_MAGIC, 1, int)
#define AB_SM_GET_STATE _IOR(AB_SM_IOCTL_MAGIC, 2, int *)
#define AB_SM_ENTER_EL2 _IO(AB_SM_IOCTL_MAGIC, 3)
#define AB_SM_EXIT_EL2 _IO(AB_SM_IOCTL_MAGIC, 4)
#define AB_CHIP_ID_UNKNOWN - 1
#define AB_CHIP_ID_A0 0
#define AB_CHIP_ID_B0 1
#endif

