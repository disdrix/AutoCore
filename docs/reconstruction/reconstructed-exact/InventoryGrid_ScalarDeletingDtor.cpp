// =============================================================================
// InventoryGrid_ScalarDeletingDtor
// -----------------------------------------------------------------------------
// Stable ID: aa_00573910
// Address:   0x00573910–0x0057392d exclusive (29 B / 0x1D, autoassault.exe base 0x400000)
// System:    inventory-transfer / InventoryGrid MSVC scalar-deleting destructor
// Generated: 2026-08-04 WQ8R-E dual A/B (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler CF + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_00573910
// =============================================================================
//
// PURPOSE:
//   MSVC scalar-deleting destructor for InventoryGrid vtbl family
//   PTR_FUN_009d3390 (vtbl[0]). Always runs complete dtor FUN_005725a0.
//   If (flags & 1), operator_delete the host heap block. Returns this in EAX.
//   Epilogue ret 4.
//
// ABI:
//   __thiscall; ECX=this; stack flags (cleaned as 4 bytes); ret 4; returns this*.
//   Entry: 56 8B F1 …
//   Exit:  8B C6 5E C2 04 00
//
// TWINS / RELATED:
//   FUN_005725a0                 — complete dtor (installs PTR_FUN_009d3390)
//   InventoryGrid_ctor_Inferred  — 0x00572650; same vtbl
//   Vehicle_CreateCargoInventoryFromPageCount — destroy site vtbl[0](1) on +0x2b0
// =============================================================================

#include <cstdint>

extern "C" void __thiscall FUN_005725a0(void* self);  // complete dtor (not owned)
extern "C" void operator_delete(void* p);

// Machine: void* __thiscall FUN_00573910(void* this, uint8_t flags)
extern "C" void* __thiscall InventoryGrid_ScalarDeletingDtor(void* self, uint8_t flags)
{
  // ESI = self (bytes: 56 8B F1)
  FUN_005725a0(self);

  if ((flags & 1u) != 0u) {
    operator_delete(self);
  }

  return self;
}
