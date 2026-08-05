// =============================================================================
// CVOGHBBase_dtor
// -----------------------------------------------------------------------------
// Purpose:  Complete object destructor body for CVOGHBBase:
//           restore base vtbl PTR_FUN_009cdab0, optionally detach from
//           owner list manager (FUN_005085b0). Does NOT free memory.
//
// Address:  0x00508390  (autoassault.exe, image base 0x400000)
// Body:     0x00508390–0x005083af (32 bytes)
// Stable:   aa_00508390
// System:   heartbeat / timed-action
// Ghidra:   FUN_00508390
//
// ABI:      __thiscall / __fastcall shape — this in ECX; bare RET
// Exactness: CF mirrors raw + read_memory bytes; names cleaned.
//            Decompiler under-models FUN_005085b0 this (shows HB only);
//            machine: ECX=listMgr, stack=HB* — corrected below.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 W21-A seal).
// =============================================================================

#include <cstdint>

// Base vtbl installed by CVOGHBBase_ctor / restored here.
extern "C" void *PTR_FUN_009cdab0[];

// Dual-sealed list remove-by-key: ECX = list manager, stack = HB*.
extern "C" uint32_t __thiscall FUN_005085b0(void *listMgr /* ECX */, void *hb /* stack */);

/* CVOGHBBase_dtor — complete dtor body (non-scalar).

   Parameters:
     thisHb: CVOGHBBase* in ECX

   Algorithm:
     1) Load owner = this+0x18
     2) *this = &PTR_FUN_009cdab0  (always)
     3) if owner && *(owner+0xB0): FUN_005085b0(listMgr, this)
     4) return

   Returns: void */

void __fastcall CVOGHBBase_dtor(void *thisHb /* ECX */)
{
  void *pOwner;
  void *pListMgr;

  pOwner = *reinterpret_cast<void **>(reinterpret_cast<char *>(thisHb) + 0x18);
  *reinterpret_cast<void **>(thisHb) = PTR_FUN_009cdab0;

  if (pOwner != nullptr) {
    pListMgr = *reinterpret_cast<void **>(reinterpret_cast<char *>(pOwner) + 0xB0);
    if (pListMgr != nullptr) {
      // machine: push thisHb; call with ECX = pListMgr
      FUN_005085b0(pListMgr, thisHb);
    }
  }
  return;
}

// Ghidra alias
extern "C" void __fastcall FUN_00508390(void *param_1)
{
  CVOGHBBase_dtor(param_1);
}
