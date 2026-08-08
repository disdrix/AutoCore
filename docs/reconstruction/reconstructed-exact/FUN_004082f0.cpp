// =============================================================================
// FUN_004082f0  (scaffold twin — prefer named clean)
// -----------------------------------------------------------------------------
// Stable ID: aa_004082f0
// Named:     StdVector_InsertN_Elem12_Inferred
// Address:   0x004082f0
// Dual:      WQ9H-B 2026-08-04 accept-with-gaps
// =============================================================================
// See StdVector_InsertN_Elem12_Inferred.cpp for meaningful reconstruction.
// This twin keeps the Ghidra symbol as an alias entry point for tooling.

#include <cstdint>

struct Pod12 { uint32_t d0, d1, d2; };
struct VecPod12 { void* u0; Pod12* begin; Pod12* end; Pod12* capEnd; };

extern "C" void StdVector_InsertN_Elem12_Inferred(
    VecPod12* self, Pod12* where, uint32_t count, const Pod12* value);

extern "C" void FUN_004082f0(
    VecPod12* self /*ECX*/,
    Pod12* where,
    uint32_t count,
    const Pod12* value)
{
  StdVector_InsertN_Elem12_Inferred(self, where, count, value);
}
