// =============================================================================
// FUN_00744360  (Ghidra twin of PreloadDep_CollectTransitiveKeys_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00744360
// Address:   0x00744360–0x0074445c  (autoassault.exe, image base 0x400000)
// Dual:      W32-L 2026-07-29
// Canonical: docs/reconstruction/reconstructed-exact/PreloadDep_CollectTransitiveKeys_Inferred.cpp
// =============================================================================

struct GuardedVectorHeader;

extern "C" void __fastcall PreloadDep_CollectTransitiveKeys_Inferred(
    void* host, const int* key, GuardedVectorHeader* ring);

extern "C" void __fastcall FUN_00744360(
    void* host, const int* key, GuardedVectorHeader* ring)
{
  PreloadDep_CollectTransitiveKeys_Inferred(host, key, ring);
}
