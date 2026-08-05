// =============================================================================
// FUN_00571010  — scaffold alias; prefer InventoryGrid_FindItemByCoid.cpp
// -----------------------------------------------------------------------------
// Stable ID: aa_00571010
// Address:   0x00571010  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-07-23 scaffold; dual seal 2026-07-29 → InventoryGrid_FindItemByCoid
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE: First grid item with instance COID == (param_2, param_3) at +0x160/+0x164.
// Sibling CBID finder: InventoryGrid_FindItemByCbid @ 0x005710c0 (do not conflate).
// Authoritative clean: reconstructed-exact/InventoryGrid_FindItemByCoid.cpp
// Duals: reviews/A_aa_00571010_InventoryGrid_FindItemByCoid.md + B_ + a_00571010.md

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, while×1.
//  - Notable callees: FUN_004022a0×2, LeaveCriticalSection×2, FUN_004294f0, FUN_00571010.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int __thiscall FUN_00571010(int param_1,int param_2,int param_3)



{

  int iVar1;

  int local_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0;

  FUN_004294f0();

  iVar1 = FUN_004022a0(&local_4,&local_8);

  while( true ) {

    if (iVar1 != 0) {

      if (*(char *)(param_1 + 0x54) != '\0') {

        *(uint8_t *)(param_1 + 0x54) = 0;

        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));

      }

      return 0;

    }

    if (((local_8 != 0) && (*(int *)(local_8 + 0x160) == param_2)) &&

       (*(int *)(local_8 + 0x164) == param_3)) break;

    iVar1 = FUN_004022a0(&local_4,&local_8);

  }

  if (*(char *)(param_1 + 0x54) != '\0') {

    *(uint8_t *)(param_1 + 0x54) = 0;

    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));

  }

  return local_8;

}
