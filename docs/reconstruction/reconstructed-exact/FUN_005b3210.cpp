// =============================================================================
// FUN_005b3210  (scaffold alias → CVOGHBRespawnCharacter_ctor)
// -----------------------------------------------------------------------------
// Stable ID: aa_005b3210
// Address:   0x005b3210  (autoassault.exe, image base 0x400000)
// Body:      0x005b3210–0x005b325d (77 bytes)
// System:    heartbeat / client death-respawn
// Generated: 2026-07-23 scaffold; refined 2026-07-29 W23-S dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// Canonical clean: CVOGHBRespawnCharacter_ctor.cpp
// =============================================================================

// PURPOSE: CVOGHBRespawnCharacter HB ctor — period at +0x08, AttachOwner with
//          optional MI this-adjust. Death UI uses (localChar, 300000).
// READABILITY: control flow preserved from Ghidra decompile; names cleaned.

#include <cstdint>

extern void CVOGHBBase_ctor(void* self);
extern void CVOGHBBase_SetPeriodAndCounter(void* hb, int nPeriodSentinel, bool bAlsoSetCounter);
extern void CVOGHBBase_AttachOwnerObject(void* hb, void* owner);
extern void* PTR_FUN_009d957c;

std::uint32_t* __thiscall FUN_005b3210(
    std::uint32_t* param_1,
    int param_2,
    std::uint32_t param_3)
{
  CVOGHBBase_ctor(param_1);
  *param_1 = reinterpret_cast<std::uint32_t>(&PTR_FUN_009d957c);
  CVOGHBBase_SetPeriodAndCounter(param_1, 1, true);
  param_1[2] = param_3;
  if (param_2 == 0) {
    CVOGHBBase_AttachOwnerObject(param_1, nullptr);
    return param_1;
  }
  CVOGHBBase_AttachOwnerObject(
      param_1,
      reinterpret_cast<void*>(
          *reinterpret_cast<int*>(*reinterpret_cast<int*>(param_2 + 4) + 4) + 4 + param_2));
  return param_1;
}
