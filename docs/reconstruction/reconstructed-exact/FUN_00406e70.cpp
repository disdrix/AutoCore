// =============================================================================
// FUN_00406e70 (scaffold alias)
// -----------------------------------------------------------------------------
// Stable ID: aa_00406e70
// Address:   0x00406e70  (autoassault.exe, image base 0x400000)
// Named:     StdVector_InsertOne_RebindIt_Elem12_EdiVec_Inferred
// Generated: 2026-08-04 WQ9G-I — prefer named clean plate.
// Exactness: Scaffold keeps decompiler surface; full CF in named twin.
// =============================================================================

#include <cstdint>

// Prefer: reconstructed-exact/StdVector_InsertOne_RebindIt_Elem12_EdiVec_Inferred.cpp
// Decompiler loses EDI=vec as unaff_EDI; real ABI is customcc ret 0x0C.

extern "C" int* FUN_00406e70(int* outIt, int where, uint32_t value)
{
  // Registers required at entry: EDI = vector*.
  // See named plate for full body (index save, InsertN count=1, rebind *0xC).
  (void)outIt;
  (void)where;
  (void)value;
  return outIt;
}
