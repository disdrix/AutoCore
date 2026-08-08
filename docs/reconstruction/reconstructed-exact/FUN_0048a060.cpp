// =============================================================================
// FUN_0048a060  (scaffold twin — prefer SoftCastHitList_SortIfCountGt1_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0048a060
// Address:   0x0048a060  (autoassault.exe, image base 0x400000)
// System:    interaction-activation
// Generated: 2026-08-05 MEGA-116 — machine ABI correction of 2026-07-23 scaffold
// Exactness: Behavior-preserving. Named clean is authoritative for ports.
// =============================================================================
//
// PURPOSE: Soft-cast hit-list sort gate (count>1) → FUN_00489f20.
// Canonical: SoftCastHitList_SortIfCountGt1_Inferred
//
// ABI CORRECTION vs scaffold:
//   Scaffold used decompiler void __fastcall(uint param_1).
//   Sealed: thiscall ECX=this SoftCastHitList*; bare RET; no stack args.
// =============================================================================

#include <cstdint>

extern "C" void __cdecl FUN_00489f20(void *array_base, int lo, int hi,
                                     uint32_t sort_cookie);

// Ghidra symbol retained for xref continuity; prefer the named clean.
void __thiscall FUN_0048a060(void *self_hit_list)
{
  uint32_t sort_cookie =
      static_cast<uint32_t>(reinterpret_cast<uintptr_t>(self_hit_list)) &
      0xFFFFFF00u;

  int count = *reinterpret_cast<int *>(
      reinterpret_cast<uint8_t *>(self_hit_list) + 0x14);

  if (count > 1) {
    void *array_base = *reinterpret_cast<void **>(
        reinterpret_cast<uint8_t *>(self_hit_list) + 0x10);
    FUN_00489f20(array_base, 0, count - 1, sort_cookie);
  }
}
