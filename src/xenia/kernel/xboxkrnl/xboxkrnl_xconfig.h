/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2022 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#ifndef XENIA_KERNEL_XBOXKRNL_XCONFIG
#define XENIA_KERNEL_XBOXKRNL_XCONFIG

#include "xenia/xbox.h"

namespace xe {
namespace kernel {
namespace xboxkrnl {
  
// clang-format off

// XConfig Categories
#define XCONFIG_STATIC_CATEGORY               0x0
#define XCONFIG_STATISTIC_CATEGORY            0x1
#define XCONFIG_SECURED_CATEGORY              0x2
#define XCONFIG_USER_CATEGORY                 0x3
#define XCONFIG_XNET_MACHINE_ACCOUNT_CATEGORY 0x4
#define XCONFIG_XNET_PARAMETERS_CATEGORY      0x5
#define XCONFIG_MEDIA_CENTER_CATEGORY         0x6
#define XCONFIG_CONSOLE_CATEGORY              0x7
#define XCONFIG_DVD_CATEGORY                  0x8
#define XCONFIG_IPTV_CATEGORY                 0x9
#define XCONFIG_SYSTEM_CATEGORY               0xA

#define XCONFIG_LAST_CATEGORY                 XCONFIG_SYSTEM_CATEGORY
#define XCONFIG_LAST_SETTING                  0xB

// Static Settings


// User Settings
#define XCONFIG_USER_TIME_ZONE_BIAS           0x01
#define XCONFIG_USER_TIME_ZONE_STD_NAME       0x02
#define XCONFIG_USER_TIME_ZONE_DLT_NAME       0x03
#define XCONFIG_USER_TIME_ZONE_STD_DATE       0x04
#define XCONFIG_USER_TIME_ZONE_DLT_DATE       0x05
#define XCONFIG_USER_TIME_ZONE_STD_BIAS       0x06
#define XCONFIG_USER_TIME_ZONE_DLT_BIAS       0x07
#define XCONFIG_USER_LANGUAGE                 0x09
#define XCONFIG_USER_VIDEO_FLAGS              0x0A
#define XCONFIG_USER_RETAIL_FLAGS             0x0B
#define XCONFIG_USER_COUNTRY                  0x0E

// clang-format on

struct XConfigFanOverride {
  char speed;
  char enable;
};

struct XConfigFanOverrides {
  XConfigFanOverride cpu;
  XConfigFanOverride gpu;
};

struct XConfigTemperatureConstant {
  short gain;
  short offset;
};

struct XConfigTemperatureConstants {
  XConfigTemperatureConstant cpu;
  XConfigTemperatureConstant gpu;
  XConfigTemperatureConstant edram;
};

union XConfigTemperature {
  short temp_cal_data[16];
  XConfigTemperatureConstants constant;
};

struct XConfigThermalValues {
  char cpu;
  char gpu;
  char edram;
};

struct XConfigThermal {
  XConfigThermalValues set_point;
  XConfigThermalValues overload;
};

struct XConfigViperAsFlags {
  char memory_voltage_not_setting;
  char gpu_voltage_not_setting;
};

struct XConfigViperFlags {
  char as_uchar;
  XConfigViperAsFlags as_flags;
};

struct XConfigViper {
  XConfigViperFlags flags;
  char gpu_target;
  char memory_target;
  char checksum;
};

union XConfigBackupThermalCalData {
  XConfigTemperature temperature;
  char ana_fuse_value;
  XConfigThermal thermal;
};

struct XConfigSMCBlock {
  char sturcture_version;
  char config_source;
  char clock_select;
  XConfigFanOverrides fan_override;
  char pad1[1];

  char radio_enable;
  char use_temp_cal_defaults;
  char screen_tool_started;
  char screen_tool_finished;
  char screen_tool_execution_count;

  char pad2[3];
  XConfigTemperature temperature;
  char ana_fuse_value;
  XConfigThermal thermal;
  char pad3[1];
  XConfigViper viper_vflags;

  char pad4[190];

  XConfigBackupThermalCalData backup_thermal_cal_data;
  char pad5[3];
  char do_not_use[2];
};

struct XConfigPowerMode {
  char vidDelta;
  char reserved;
};

struct XConfigPowerVcsControl {
  uint8_t configured;
  uint8_t reserved;
  uint8_t full;
  uint8_t quiet;
  uint8_t fuse;
};

struct XConfigTimezoneDate {
  char month;
  char day;
  char day_of_week;
  char hour;
};

struct unnamed_ULargeInt {
  uint32_t high;
  uint32_t low;
};

struct union_ULargeInt {
  uint32_t high;
  uint32_t low;
  unnamed_ULargeInt u;
  uint32_t quad_part;
};

struct XConfigPlayTimerData {
  union_ULargeInt reset_date;
  uint32_t player_timer_frequency;
  uint32_t total_play_time;
  uint32_t remaining_playtime;
};

}  // namespace xboxkrnl
}  // namespace kernel
}  // namespace xe

#endif  // XENIA_KERNEL_XBOXKRNL_XCONFIG