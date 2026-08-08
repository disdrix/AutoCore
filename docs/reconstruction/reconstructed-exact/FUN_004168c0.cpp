// =============================================================================
// FUN_004168c0 — clean twin alias
// Canonical: Class_00a733ec_Factory_NullFreeCallback_Inferred
// See: Class_00a733ec_Factory_NullFreeCallback_Inferred.cpp
// WQ9K-I dual seal 2026-08-05
// =============================================================================

#include <cstdint>

using FreeCallback = void(__cdecl *)(void *context);

struct Class_00a733ec {
  void *vtbl;
  void *context;
  uint32_t field_08;
  uint32_t field_0c;
  FreeCallback free_callback;
};

extern "C" void *operator_new(uint32_t size);
extern "C" void *const PTR_FUN_00a733ec;
extern "C" Class_00a733ec *Class_00a733ec_Factory_NullFreeCallback_Inferred(
    void *context);

extern "C" Class_00a733ec *FUN_004168c0(void *context)
{
  return Class_00a733ec_Factory_NullFreeCallback_Inferred(context);
}
