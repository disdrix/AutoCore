// =============================================================================
// FUN_005a2410  (scaffold alias of TNL_NetClassRepInstance_Ctor)
// -----------------------------------------------------------------------------
// Stable ID: aa_005a2410
// Address:   0x005a2410  (autoassault.exe, image base 0x400000)
// Body:      0x005a2410–0x005a2466 (87 B through ret 0x10)
// System:    tnl / NetClassRep
// Generated: 2026-07-29 W21-K dual seal (refined from 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical clean: TNL_NetClassRepInstance_Ctor.cpp
// Dual A/B: accept (2026-07-29).
// =============================================================================

#include <cstdint>

extern "C" void __fastcall FUN_0042aea0(void* self);
extern "C" char* _strdup(const char* s);
extern void* PTR_FUN_009d7bf4;
extern void* DAT_00d179a4;

uint32_t* __thiscall FUN_005a2410(
    uint32_t* param_1,
    char* param_2,
    uint32_t param_3,
    uint32_t param_4,
    uint32_t param_5)
{
  char* pcVar1;

  FUN_0042aea0(param_1);
  *param_1 = reinterpret_cast<uint32_t>(&PTR_FUN_009d7bf4);
  pcVar1 = _strdup(param_2);
  param_1[8] = reinterpret_cast<uint32_t>(pcVar1);
  param_1[2] = param_5;
  param_1[3] = param_4;
  param_1[1] = param_3;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[0xd] = reinterpret_cast<uint32_t>(DAT_00d179a4);
  DAT_00d179a4 = param_1;
  return param_1;
}
