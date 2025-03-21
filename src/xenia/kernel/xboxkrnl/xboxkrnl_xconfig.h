/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2025 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#ifndef XENIA_KERNEL_XBOXKRNL_XBOXKRNL_XCONFIG_H_
#define XENIA_KERNEL_XBOXKRNL_XBOXKRNL_XCONFIG_H_

#include "xenia/kernel/util/shim_utils.h"
#include "xenia/xbox.h"

namespace xe {
namespace kernel {
namespace xboxkrnl {

X_STATUS xeExGetXConfigSetting(uint16_t category, uint16_t setting,
  void* buffer, uint16_t buffer_size,
  uint16_t* required_size = nullptr);

// XCONFIG_SECURED_AV_REGION
enum X_AV_REGION : uint32_t {
  NTSCM = 0x00400100,
  NTSCJ = 0x00400200,
  PAL = 0x00400400,
  PAL_50 = 0x00800300,
};

// XCONFIG_USER_VIDEO_FLAGS
enum X_VIDEO_ASPECT_RATIO : uint32_t {
  RatioNormal = 0x00400100,
  Widescreen = 0x00400200,
};

// XCONFIG_USER_AUDIO_FLAGS
enum X_AUDIO_FLAGS : uint32_t {
  // Audio Mode Analog
  DolbyProLogic = 0x00000001,
  AnalogMono = 0x00000002,
  // Audio Mode Digital
  DigitalStereo = 0x00000000,
  DolbyDigital = 0x00010000,
  DolbyDigitalWithWMAPRO = 0x00030000,
  // Special Flags
  StereoBypass = 0x00000003,
  LowLatency = 0x80000000,
};

// XCONFIG_USER_RETAIL_FLAGS
enum X_RETAIL_FLAGS : uint32_t {
  // Clock
  DSTOff = 0x00000002,
  NetworkInitialized = 0x00000004,
  TwentyFourHourClock = 0x00000008,

  // Startup
  DashboardInitialized = 0x00000040,
  BootToDashboard = 0x00000080,
  BootToIPTV = 0x00000800,
  BootToDisc = 0x00002000,
  BackgroundDownloads  = 0X00010000,
  MCXDownloaderStartup = 0x00020000,
  // IPTV
  IPTVEnabled = 0x00001000,
  IPTVDVREnabled = 0x00080000,
  // Kinect
  KinectInitialized = 0x20000000,
  KinectDisabled = 0x80000000,
};

// XCONFIG_USER_PC_FLAGS
enum X_PC_FLAGS : uint8_t {
  XBLAllowed = 0x01,
  XBLMembershipCreationAllowed = 0x02,
  PCEnabled = 0x80,
};

enum X_PC_HINTS : uint8_t {
  FavoriteFictionalCharactar = 0,
  FavoritePersonFromHistory = 1,
  FavoriteChildhoodBookOrStory = 2,
  FavoriteMovie = 3,
  FavoriteFood = 4
};

// XCONFIG_USER_VIDEO_OUTPUT_BLACK_LEVELS
enum X_BLACK_LEVEL : uint32_t {
  High = 0x00000100,
  Intermediate = 0x00000200,
  LevelNormal = 0x00000300,
};

// XCONFIG_CONSOLE_SCREENSAVER
enum X_SCREENSAVER : uint32_t {
  ScreensaverOn = 0x000A,
  ScreensaverOff = 0X1000,
};

// XCONFIG_CONSOLE_AUTO_SHUTDOWN
enum X_AUTO_SHUTDOWN : uint32_t {
  AutoShutdownOff = 0x0000,
  AutoShutdownOneHr = 0x003C,
  AutoShutdownSixHr = 0x0168,
};

// XCONFIG_CONSOLE_CAMERA_SETTINGS
enum X_CAMERA_FLAGS : uint32_t {
  // Room
  RoomAuto = 0x00000000,
  DarkWall = 0x00000001,
  LightWall = 0x00000002,
  // Lighting
  LightingAuto = 0x00000000,
  Incandescent = 0x00000004,
  Flourescent = 0x00000008,
  Daylight = 0x0000000C,
  // Flourescent Anti-Flicker
  AntiFlickerAuto = 0x00000000,
  AntiFlickerOn = 0x00000001,
  AntiFlickerOff = 0x00000002,
  // Default
  AutoAll = 0x00000001,
};

// XCONFIG_CONSOLE_KEYBOARD_LAYOUT
enum X_KEYBOARD_LAYOUT : uint16_t {
  KeyboardDefault = 0x0000,
  EnglishQWERTY = 0x0001,
};

// XCONFIG_CONSOLE_KEYBOARD_LAYOUT

}  // namespace xboxkrnl
}  // namespace kernel
}  // namespace xe

#endif  // XENIA_KERNEL_XBOXKRNL_XBOXKRNL_XCONFIG_H_
