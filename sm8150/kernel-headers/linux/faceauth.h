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
#include <linux/time.h>
#define FACEAUTH_OP_ERASE 0
#define FACEAUTH_OP_ENROLL 1
#define FACEAUTH_OP_VALIDATE 2
#define FACEAUTH_OP_ENROLL_COMPLETE 3
#define FACEAUTH_RESULT_SUCCESS 0
#define FACEAUTH_RESULT_FAILURE 1
#define FACEAUTH_ERROR_NO_ERROR 0
#define FACEAUTH_MAX_TASKS 32
#define FACEAUTH_DEBUG_REGISTER_COUNT (24)
struct faceauth_init_data {
  __u64 features;
} __attribute__((packed));
struct faceauth_start_data {
  __u8 profile_id;
  __u8 operation;
  __u8 * image_dot_left;
  __u32 image_dot_left_size;
  __u8 * image_dot_right;
  __u32 image_dot_right_size;
  __u8 * image_flood;
  __u32 image_flood_size;
  void * calibration;
  __u32 calibration_size;
  __u8 result;
  __u32 bin_bitmap;
  __s32 error_code;
  __u32 fw_version;
} __attribute__((packed));
#define GET_DEBUG_DATA_FROM_CACHE (0)
#define GET_DEBUG_DATA_FROM_AB_DRAM (1)
struct faceauth_debug_data {
  union {
    __u8 * debug_buffer;
    __u8 * print_buffer;
  };
  union {
    __u32 debug_buffer_size;
    __u32 print_buffer_size;
  };
  __u32 flags;
} __attribute__((packed));
struct faceauth_workload_control {
  __u32 workload_state;
  __u32 run_count;
  __u32 run_time_ms;
  __u32 run_time_us;
  __u32 status;
} __attribute__((packed));
struct faceauth_debug_register {
  __u64 address;
  __u64 value;
} __attribute__((packed));
struct faceauth_airbrush_state {
  __u32 faceauth_version;
  __s32 error_code;
  __u32 internal_state_size;
  __u32 command;
  __u32 num_tasks;
  __u32 register_list_length;
  __u32 saved_register_count;
  struct faceauth_workload_control control_list[FACEAUTH_MAX_TASKS];
  struct faceauth_debug_register debug_registers[FACEAUTH_DEBUG_REGISTER_COUNT];
} __attribute__((packed));
struct faceauth_debug_image {
  __u32 offset_to_image;
  __u32 image_size;
};
struct faceauth_debug_entry {
  struct timeval timestamp;
  struct faceauth_debug_image left_dot;
  struct faceauth_debug_image right_dot;
  struct faceauth_debug_image flood;
  struct faceauth_airbrush_state ab_state;
} __attribute__((packed));
#define FACEAUTH_DEV_IOC_INIT _IOR('f', 1, struct faceauth_init_data)
#define FACEAUTH_DEV_IOC_START _IOWR('f', 2, struct faceauth_start_data)
#define FACEAUTH_DEV_IOC_CLEANUP _IO('f', 4)
#define FACEAUTH_DEV_IOC_DEBUG _IOR('f', 5, struct faceauth_debug_data)
#define FACEAUTH_DEV_IOC_DEBUG_DATA _IOR('f', 6, struct faceauth_debug_data)
#endif

