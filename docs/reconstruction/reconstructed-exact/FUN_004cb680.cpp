// =============================================================================
// FUN_004cb680 — scaffold alias → SkillCNDHash_ReleaseChainsToFreelist_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004cb680
// Address:   0x004cb680  (autoassault.exe, image base 0x400000)
// WQ9F-A: Prefer clean plate SkillCNDHash_ReleaseChainsToFreelist_Inferred.cpp
// =============================================================================

// Scaffold retained for Ghidra-symbol lookup. Authoritative CF + ABI:
//   docs/reconstruction/reconstructed-exact/SkillCNDHash_ReleaseChainsToFreelist_Inferred.cpp
//
// void __thiscall FUN_004cb680(SkillCNDHash *hash);
// bare ret; sole caller DestroyBucketTable 0x004cba60;
// walk buckets 0..mask; delete payload@+8; freelist push @ hash+0x20.

void FUN_004cb680(void);
