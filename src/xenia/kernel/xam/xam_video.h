/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2022 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#ifndef XENIA_KERNEL_XAM_XAM_VIDEO_
#define XENIA_KERNEL_XAM_XAM_VIDEO_

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "xenia/base/mutex.h"
#include "xenia/kernel/kernel_state.h"
#include "xenia/kernel/xam/app_manager.h"

namespace xe {
namespace kernel {
namespace xam {

#define X_VIDEO_FLAGS_WIDESCREEN 0x1
#define X_VIDEO_FLAGS_720p 0x2
#define X_VIDEO_FLAGS_1080i 0x4
#define X_VIDEO_FLAGS_480p 0x8

}  // namespace xam
}  // namespace kernel
}  // namespace xe

#endif  // XENIA_KERNEL_XAM_XAM_VIDEO_H_
