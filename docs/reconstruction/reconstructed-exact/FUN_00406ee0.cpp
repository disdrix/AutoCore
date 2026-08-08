// =============================================================================
// FUN_00406ee0 (scaffold alias)
// -----------------------------------------------------------------------------
// Stable ID: aa_00406ee0
// Address:   0x00406ee0  (autoassault.exe, image base 0x400000)
// Named:     StdVector_UninitializedFillN_Elem12_Inferred
// Generated: 2026-08-04 WQ9G-I — prefer named clean plate.
// Exactness: Scaffold keeps decompiler surface; full CF in named twin.
// =============================================================================

#include <cstdint>

// Prefer: reconstructed-exact/StdVector_UninitializedFillN_Elem12_Inferred.cpp
// Decompiler loses EDI=dest / ESI=count as unaff_*; real ABI is customcc ret 4.

extern "C" int FUN_00406ee0(void)
{
  // Registers required at entry: EDI = dest*, ESI = count; stack value*.
  // See named plate: call FUN_00409db0 then return dest + count*0xC.
  return 0;
}
