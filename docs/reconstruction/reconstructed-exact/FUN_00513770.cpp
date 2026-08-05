// =============================================================================
// FUN_00513770 (legacy path) — see Item_IsWantedByStore_Inferred.cpp
// -----------------------------------------------------------------------------
// Stable ID: aa_00513770
// Address:   0x00513770  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-07-29 dual A/B (scaffold superseded)
// Canonical clean: reconstructed-exact/Item_IsWantedByStore_Inferred.cpp
// Dual A/B: reviews/A_aa_00513770_Item_IsWantedByStore_Inferred.md
//           reviews/B_aa_00513770_Item_IsWantedByStore_Inferred.md
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Store/vendor want-gate. Prefer Item_IsWantedByStore_Inferred name.
// ABI: bool __thiscall (Item* ECX); plain RET; AL result.
// Layout: item+0xA8 clonebase; clonebase+0x3C def; def+0x3B4 == 1.

int __thiscall FUN_004f1e20(void* clonebase, char param_2, char param_3);

unsigned char /* bool AL */ __thiscall FUN_00513770(void* item)
{
  void* clonebase;
  void* def;

  clonebase = *(void**)((char*)item + 0xA8);

  if (*(void**)((char*)clonebase + 0x3C) == 0) {
    FUN_004f1e20(clonebase, 0, 1);
  }

  def = *(void**)((char*)(*(void**)((char*)item + 0xA8)) + 0x3C);
  if (def == 0) {
    return 1;
  }

  return (*(int*)((char*)def + 0x3B4) == 1) ? 1 : 0;
}
