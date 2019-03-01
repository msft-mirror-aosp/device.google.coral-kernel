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
#define AB_SM_SET_IPU_FREQUENCY _IOW(AB_SM_IOCTL_MAGIC, 5, int)
#define AB_SM_SET_TPU_FREQUENCY _IOW(AB_SM_IOCTL_MAGIC, 6, int)
#define AB_SM_SET_DDR_FREQUENCY _IOW(AB_SM_IOCTL_MAGIC, 7, int)
#define AB_SM_SET_PCIE_FREQUENCY _IOW(AB_SM_IOCTL_MAGIC, 8, int)
#define AB_SM_SET_AON_FREQUENCY _IOW(AB_SM_IOCTL_MAGIC, 9, int)
#define AB_SM_SET_IPU_STATE _IOW(AB_SM_IOCTL_MAGIC, 10, int)
#define AB_SM_SET_TPU_STATE _IOW(AB_SM_IOCTL_MAGIC, 11, int)
#define AB_SM_SET_DDR_STATE _IOW(AB_SM_IOCTL_MAGIC, 12, int)
#define AB_SM_SET_PCIE_STATE _IOW(AB_SM_IOCTL_MAGIC, 13, int)
#define AB_SM_UPDATE_IPU_STATE_PROPERTIES _IOW(AB_SM_IOCTL_MAGIC, 14, struct new_block_props *)
#define AB_SM_UPDATE_TPU_STATE_PROPERTIES _IOW(AB_SM_IOCTL_MAGIC, 15, struct new_block_props *)
#define AB_SM_UPDATE_DRAM_STATE_PROPERTIES _IOW(AB_SM_IOCTL_MAGIC, 16, struct new_block_props *)
#define AB_SM_UPDATE_MIF_STATE_PROPERTIES _IOW(AB_SM_IOCTL_MAGIC, 17, struct new_block_props *)
#define AB_SM_UPDATE_FSYS_STATE_PROPERTIES _IOW(AB_SM_IOCTL_MAGIC, 18, struct new_block_props *)
#define AB_SM_UPDATE_AON_STATE_PROPERTIES _IOW(AB_SM_IOCTL_MAGIC, 19, struct new_block_props *)
#define AB_SM_GET_EL2_MODE _IOR(AB_SM_IOCTL_MAGIC, 20, int *)
#define AB_CHIP_ID_UNKNOWN - 1
#define AB_CHIP_ID_A0 0
#define AB_CHIP_ID_B0 1
#define UAPI_BLK_(num,pmu,rail,v,clk,freq,pwr,used,tiles,dr) { UAPI_BLOCK_STATE_ ##num, (enum uapi_pmu_state) pmu, uapi_ ##rail, UAPI_VOLTAGE_ ##v, uapi_ ##clk, (__u64) (1000000. * freq), pwr, used, tiles, dr, }
enum uapi_block_state {
  UAPI_BLOCK_STATE_0_0 = 0,
  UAPI_BLOCK_STATE_0_1,
  UAPI_BLOCK_STATE_0_2,
  UAPI_BLOCK_STATE_0_3,
  UAPI_BLOCK_STATE_0_4,
  UAPI_BLOCK_STATE_0_5,
  UAPI_BLOCK_STATE_0_6,
  UAPI_BLOCK_STATE_1_0 = 10,
  UAPI_BLOCK_STATE_1_1,
  UAPI_BLOCK_STATE_1_2,
  UAPI_BLOCK_STATE_2_0 = 20,
  UAPI_BLOCK_STATE_2_1,
  UAPI_BLOCK_STATE_3_0 = 30,
  UAPI_NUM_BLOCK_STATES,
};
enum uapi_pmu_state {
  UAPI_PMU_STATE_ON = 0,
  UAPI_PMU_STATE_SLEEP,
  UAPI_PMU_STATE_DEEP_SLEEP,
  UAPI_PMU_STATE_OFF
};
enum uapi_state {
  uapi_off = 0,
  uapi_on = 1,
};
enum uapi_logic_voltage {
  UAPI_VOLTAGE_0_0,
  UAPI_VOLTAGE_0_60,
  UAPI_VOLTAGE_0_75,
  UAPI_VOLTAGE_0_85,
};
struct uapi_block_properties {
  enum uapi_block_state id;
  enum uapi_pmu_state pmu;
  enum uapi_state voltage_rail_status;
  enum uapi_logic_voltage logic_voltage;
  enum uapi_state clk_status;
  __u64 clk_frequency;
  __u32 num_powered_cores;
  __u32 num_computing_cores;
  __u32 num_powered_tiles;
  __u32 data_rate;
};
struct new_block_props {
  struct uapi_block_properties table[UAPI_NUM_BLOCK_STATES];
};
#endif

