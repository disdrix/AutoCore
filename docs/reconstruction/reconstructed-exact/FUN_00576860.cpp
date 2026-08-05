// =============================================================================
// FUN_00576860 — clean twin of WaterPhase_RegisterToken_Inferred
// Stable ID: aa_00576860 | W32-S
// =============================================================================

#include <cstdint>

extern "C" void *__cdecl operator_new(uint32_t size);
extern "C" void *__thiscall FUN_00576c40(void *token);
extern "C" int32_t __thiscall FUN_00746400(void *host, void *token);
extern "C" void *DAT_00d1f620;

extern "C" int32_t FUN_00576860(void)
{
  void *token = operator_new(4);
  if (token != nullptr) {
    void *obj = FUN_00576c40(token);
    if (obj != nullptr) {
      return FUN_00746400(DAT_00d1f620, obj);
    }
  }
  return -1;
}
