#pragma once

#include "ml.h"

namespace nexa {
class Plugin;
}  // namespace nexa

#if defined(_WIN32)
#define PLUGIN_API __declspec(dllexport)
#else
#define PLUGIN_API __attribute__((visibility("default")))
#endif

#ifdef __cplusplus
extern "C" {
#endif

PLUGIN_API ml_PluginId plugin_id();
PLUGIN_API nexa::Plugin* create_plugin();

#ifdef __cplusplus
}
#endif
