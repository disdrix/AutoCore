// =============================================================================
// FUN_00406de0 — scaffold alias
// Named plate: StdVector_InsertOne_RebindIt_Elem0x28_Via408050_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00406de0
// Address:   0x00406de0  (autoassault.exe, image base 0x400000)
// Body:      0x00406de0–0x00406e48 (104 B / 0x68); ret 0xC
// Dual A/B:  accept-with-gaps (2026-08-04 WQ9G-H)
// See:       StdVector_InsertOne_RebindIt_Elem0x28_Via408050_Inferred.cpp
// =============================================================================

#include <cstdint>

extern "C" void FUN_00408050(
    /*ECX*/ void* vec,
    /*EDX*/ const void* value,
    /*stack*/ void* where,
    /*stack*/ unsigned count);

// Decompiler lost EDI=vec and stack value*; recovered ABI in named plate.
extern "C" void** FUN_00406de0(void** outIt, void* where, const void* value)
{
  // Real entry requires EDI = vector*. Parent FUN_00406220 installs EDI from EAX.
  void* vec = nullptr; // placeholder — register formal
  (void)vec;
  (void)outIt;
  (void)where;
  (void)value;
  // Prefer named plate StdVector_InsertOne_RebindIt_Elem0x28_Via408050_Inferred.
  return outIt;
}
