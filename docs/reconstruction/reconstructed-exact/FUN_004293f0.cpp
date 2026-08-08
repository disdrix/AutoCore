// =============================================================================
// FUN_004293f0  (scaffold twin of CNDUIWndBuffered_ScalarDeletingDtor)
// -----------------------------------------------------------------------------
// Stable ID: aa_004293f0
// Address:   0x004293f0–0x0042940d exclusive (29 B / 0x1D, autoassault.exe base 0x400000)
// System:    skills-abilities / CNDUIWndBuffered / MSVC scalar-deleting destructor
// Generated: 2026-08-05 R10-009 dual A/B refresh (from raw + live re-verify)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Named clean: CNDUIWndBuffered_ScalarDeletingDtor.cpp
// =============================================================================

// PURPOSE:
//   MSVC scalar-deleting destructor (vtbl[0] of PTR_FUN_00a99f74):
//   call complete dtor FUN_0078ca80; if (flags & 1) operator_delete(this); return this.
//
// ABI: __thiscall; ECX=this; stack flags; RET 4; returns this* in EAX.
// Body hex (29 B): 568bf1e888363600f644240801740956e81d04060083c4048bc65ec20400

#include <cstdint>

extern "C" void __thiscall FUN_0078ca80(void* self);  // CNDUIWndBuffered_CompleteDtor
extern "C" void operator_delete(void* p);

// Ghidra: void * __thiscall FUN_004293f0(void *param_1, byte param_2)
extern "C" void* __thiscall FUN_004293f0(void* param_1, uint8_t param_2)
{
  FUN_0078ca80(param_1);

  if ((param_2 & 1u) != 0u) {
    /* Ghidra may mark operator_delete as noreturn; epilogue is still reached. */
    operator_delete(param_1);
  }

  return param_1;
}
