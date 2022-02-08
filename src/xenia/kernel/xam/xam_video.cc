/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2022 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#include "xenia/kernel/xam/xam_video.h"
#include "xenia/base/logging.h"
#include "xenia/kernel/kernel_state.h"
#include "xenia/kernel/util/shim_utils.h"
#include "xenia/kernel/xam/xam_private.h"
#include "xenia/kernel/xboxkrnl/xboxkrnl_video.h"
#include "xenia/xbox.h"

// TODO(halotroop2288): Xenia currently only supports 720p or fake upscaling.
// If this changes, replace this with query of display supported modes
DEFINE_bool(support_widescreen, true,
            "Enable widescreen video mode option in the dashboard", "XAM");
DEFINE_bool(support_480p, false,
            "Enable 480p resolution option in the dashboard", "XAM");
DEFINE_bool(support_720p, true,
            "Enable 720p resolution option in the dashboard", "XAM");
DEFINE_bool(support_1080i, false,
            "Enable 1080i resolution option in the dashboard", "XAM");

namespace xe {
namespace kernel {
namespace xam {

void XGetVideoMode_entry(pointer_t<X_VIDEO_MODE> video_mode) {
  // TODO(benvanik): actually check to see if these are the same.
  xboxkrnl::VdQueryVideoMode(video_mode);
}
DECLARE_XAM_EXPORT1(XGetVideoMode, kVideo, kSketchy);

dword_result_t XGetVideoCapabilities_entry() {
  uint32_t flags = 0;
  if (cvars::support_widescreen) {
    flags |= X_VIDEO_FLAGS_WIDESCREEN;
  }
  if (cvars::support_480p) {
    flags |= X_VIDEO_FLAGS_480p;
  }
  if (cvars::support_720p) {
    flags |= X_VIDEO_FLAGS_720p;
  }
  if (cvars::support_1080i) {
    flags |= X_VIDEO_FLAGS_1080i;
  }

  return flags;
}
DECLARE_XAM_EXPORT1(XGetVideoCapabilities, kVideo, kSketchy);

}  // namespace xam
}  // namespace kernel
}  // namespace xe

DECLARE_XAM_EMPTY_REGISTER_EXPORTS(Video);
