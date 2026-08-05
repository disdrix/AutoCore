// =============================================================================
// CVOGHBRespawnCharacter_ctor  (was FUN_005b3210)
// -----------------------------------------------------------------------------
// Stable ID: aa_005b3210
// Address:   0x005b3210  (autoassault.exe, image base 0x400000)
// Body:      0x005b3210–0x005b325d (77 bytes)
// System:    heartbeat / client death-respawn
// Generated: 2026-07-29 W23-S dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
//
// RTTI Confirmed: COL@0x00aaffac → type_info@0x00af3e88
//                 ".?AVCVOGHBRespawnCharacter@@"
// Vtable: PTR_FUN_009d957c
// Dual: reviews/A|B_aa_005b3210_CVOGHBRespawnCharacter_ctor.md
//
// Sole caller (sealed): Client_LocalDeathUiSequence_Inferred @ 0x00802170
//   operator_new(0x24); ctor(localChar, 300000); Enqueue + Start
// =============================================================================

#include <cstdint>

extern void CVOGHBBase_ctor(void* self);
extern void CVOGHBBase_SetPeriodAndCounter(void* hb, int nPeriodSentinel, bool bAlsoSetCounter);
extern void CVOGHBBase_AttachOwnerObject(void* hb, void* owner);
extern void* PTR_FUN_009d957c;

// pObject  — multi-inheritance object pointer (may be null); death path passes
//            client local character at client+0xe98.
// periodMs — written to HB pulse period at +0x08 (death path: 300000).
std::uint32_t* __thiscall CVOGHBRespawnCharacter_ctor(
    std::uint32_t* self,
    int pObject,
    std::uint32_t periodMs)
{
  CVOGHBBase_ctor(self);
  *self = reinterpret_cast<std::uint32_t>(&PTR_FUN_009d957c);
  CVOGHBBase_SetPeriodAndCounter(self, 1, true);
  self[2] = periodMs; // +0x08 pulse period

  if (pObject == 0) {
    CVOGHBBase_AttachOwnerObject(self, nullptr);
    return self;
  }

  // this-adjust: pObject + 4 + *(*(pObject + 4) + 4)
  int mid = *reinterpret_cast<int*>(pObject + 4);
  int adj = *reinterpret_cast<int*>(mid + 4);
  void* owner = reinterpret_cast<void*>(pObject + 4 + adj);
  CVOGHBBase_AttachOwnerObject(self, owner);
  return self;
}

// Scaffold alias
std::uint32_t* __thiscall FUN_005b3210(
    std::uint32_t* param_1,
    int param_2,
    std::uint32_t param_3)
{
  return CVOGHBRespawnCharacter_ctor(param_1, param_2, param_3);
}
