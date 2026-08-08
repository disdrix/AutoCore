// =============================================================================
// FUN_00408050  (twin of named clean source)
// -----------------------------------------------------------------------------
// Stable ID: aa_00408050
// Address:   0x00408050–0x004082ed  (autoassault.exe @ 0x400000; 669 B)
// Canonical: StdVector_InsertN_Elem0x28_Inferred
// Dual A/B:  2026-08-04 WQ9H-A  accept-with-gaps
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// Prefer the named unit:
//   reconstructed-exact/StdVector_InsertN_Elem0x28_Inferred.cpp
// This twin keeps the Ghidra name for inventory paths that still key on FUN_*.
// =============================================================================

#include <cstdint>

// ECX=vec*, EDX=value*, stack where*, count; ret 8
extern "C" void FUN_00408050(
    /*ECX*/ void *vec,
    /*EDX*/ const void *value,
    /*stack*/ void *where,
    /*stack*/ unsigned count);

extern "C" void StdVector_InsertN_Elem0x28_Inferred(
    void *vec,
    const void *value,
    void *where,
    unsigned count);

// Thin alias for call-graph parents that still name FUN_00408050.
extern "C" void FUN_00408050(
    void *vec,
    const void *value,
    void *where,
    unsigned count)
{
  StdVector_InsertN_Elem0x28_Inferred(vec, value, where, count);
}
