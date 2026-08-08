// =============================================================================
// FUN_004085e0  (twin of named clean source)
// -----------------------------------------------------------------------------
// Stable ID: aa_004085e0
// Address:   0x004085e0–0x00408635  (autoassault.exe @ 0x400000; 85 B)
// Canonical: CNDHash_ReleaseBucketChainsToFreelist_00a2c2bc_Inferred
// Dual A/B:  2026-08-04 WQ9H-A  accept-with-gaps
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// Prefer the named unit:
//   reconstructed-exact/CNDHash_ReleaseBucketChainsToFreelist_00a2c2bc_Inferred.cpp
// This twin keeps the Ghidra symbol for inventory paths that still key on FUN_*.
// =============================================================================

#include <cstdint>

extern "C" void *PTR_FUN_00a2c2bc;
extern void operator delete(void *p);

// customcc: EBX = CNDHash*
extern "C" void FUN_004085e0(void);

// Named entry used by dualed parents; models EBX formal.
extern "C" void CNDHash_ReleaseBucketChainsToFreelist_00a2c2bc_Inferred(
    void *hashEbx);

// Thin alias — real body lives in the named translation unit when linked as a
// reconstruction reference. Standalone CF mirror:

extern "C" void FUN_004085e0_cf_mirror(void *hashEbx)
{
  CNDHash_ReleaseBucketChainsToFreelist_00a2c2bc_Inferred(hashEbx);
}
