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
#ifndef _LINUX_FACEAUTH_H
#define _LINUX_FACEAUTH_H
#include <linux/types.h>
#include <linux/ioctl.h>
#define FACEAUTH_OP_ERASE 0
#define FACEAUTH_OP_ENROLL 1
#define FACEAUTH_OP_VALIDATE 2
#define FACEAUTH_RESULT_SUCCESS 0
#define FACEAUTH_RESULT_FAILURE 1
#define FACEAUTH_ERROR_NO_ERROR 0
struct faceauth_start_data {
  __u32 operation;
  __u8 * image_dot_left;
  __u32 image_dot_left_size;
  __u8 * image_dot_right;
  __u32 image_dot_right_size;
  __u8 * image_flood;
  __u32 image_flood_size;
  __u8 has_calib;
  void * calib_intrinsics;
  __u32 calib_intrinsics_size;
  void * calib_transform;
  __u32 calib_transform_size;
} __attribute__((packed));
struct faceauth_continue_data {
  __u8 completed;
  __u8 result;
  __s32 faceauth_error_code;
  __u32 faceauth_fw_version;
} __attribute__((packed));
struct faceauth_debug_data {
  __u8 * print_buffer;
  __u32 print_buffer_size;
} __attribute__((packed));
#define FACEAUTH_DEV_IOC_INIT _IO('f', 1)
#define FACEAUTH_DEV_IOC_START _IOW('f', 2, struct faceauth_start_data)
#define FACEAUTH_DEV_IOC_CONTINUE _IOR('f', 3, struct faceauth_continue_data)
#define FACEAUTH_DEV_IOC_CLEANUP _IO('f', 4)
#define FACEAUTH_DEV_IOC_DEBUG _IOR('f', 5, struct faceauth_debug_data)
#endif

