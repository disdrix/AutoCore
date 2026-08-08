// =============================================================================
// FUN_008e5990  (machine twin of UI_CraftHost_BindResolvedObject_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_008e5990
// Address:   0x008e5990  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Dual:      MEGA-032 2026-08-05
// Canonical: UI_CraftHost_BindResolvedObject_Inferred
// Exactness: Behavior-preserving rewrite of sealed CF + ABI.
// Bit-for-bit / runtime / differential: OPEN (no Launcher).
// =============================================================================

// Twin: keep Ghidra symbol available for tooling that keys on FUN_*.
// Full annotated port lives in UI_CraftHost_BindResolvedObject_Inferred.cpp.

#include <cstdint>

extern void __thiscall UI_CraftHost_BindResolvedObject_Inferred(void* host, int* object);

// thiscall ECX=host; stack object*; RET 4
void __thiscall FUN_008e5990(void* host, int* object) {
  UI_CraftHost_BindResolvedObject_Inferred(host, object);
}
