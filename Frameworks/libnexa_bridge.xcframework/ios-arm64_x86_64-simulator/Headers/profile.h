#pragma once

#include "ml.h"

namespace nexa {

// Ref:
// - Profiling Metrics https://oc1rr3jgj3d.sg.larksuite.com/wiki/JMTiwlW76i3q6Lk88J0lLb5Og0c
// - Profiling for ASR and TTS https://linear.app/nexaai/issue/ENG-5508/profiling-for-asr-and-tts
inline void calculate_profile_data(ml_ProfileData& pd) {
    pd.prefill_speed =
        pd.prompt_time > 0 ? static_cast<double>(pd.prompt_tokens) / (static_cast<double>(pd.prompt_time) / 1e6) : 0.0;

    pd.decoding_speed = pd.decode_time > 0
                            ? static_cast<double>(pd.generated_tokens) / (static_cast<double>(pd.decode_time) / 1e6)
                            : 0.0;

    pd.real_time_factor =
        pd.audio_duration > 0 ? static_cast<double>(pd.decode_time) / static_cast<double>(pd.audio_duration) : 0.0;
}

}  // namespace nexa
