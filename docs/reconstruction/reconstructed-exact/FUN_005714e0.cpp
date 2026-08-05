// =============================================================================
// FUN_005714e0 — SUPERSEDED scaffold
// -----------------------------------------------------------------------------
// Prefer: reconstructed-exact/InventoryGrid_FindFreeForItem.cpp
// Stable: aa_005714e0  VA 0x005714e0
// Dual residual sealed 2026-07-29 (relation to FindFreeSlot 0x005713a0).
// This file kept so old links resolve; body below is 2026-07-23 scaffold.
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005714e0 @ 0x005714e0
// Stable ID: aa_005714e0
// Canonical: InventoryGrid_FindFreeForItem

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×6, return×4.
//  - Notable callees: FUN_0040abf0, FUN_00513e70, FUN_005710c0, FUN_005713a0, FUN_005714e0.
//  - Return sites: 4.

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

uint32_t /* width from decompiler */

FUN_005714e0(int *param_1,uint8_t *param_2,uint8_t *param_3,char param_4,uint32_t /* width from decompiler */ param_5)



{

  char cVar1;

  uint8_t uVar2;

  uint32_t /* width from decompiler */ uVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ uVar5;

  

  if (param_1 == (int *)0x0) {

    return 0;

  }

  if (*(int *)(param_1[0x2a] + 0x38) == 4) {

    *param_2 = 0;

    *param_3 = 0;

    return 1;

  }

  if (param_4 != '\0') {

    cVar1 = FUN_00513e70();

    if (cVar1 != '\0') {

      uVar5 = *(uint32_t /* width from decompiler */ *)(param_1[0x2a] + 0x34);

      uVar3 = (**(code **)(*param_1 + 0x25c))();

      piVar4 = (int *)FUN_005710c0(uVar5,0,uVar3);

      if (piVar4 != (int *)0x0) {

        uVar5 = (**(code **)(*param_1 + 0x25c))();

        cVar1 = FUN_0040abf0(uVar5);

        if (cVar1 != '\0') {

          uVar2 = (**(code **)(*piVar4 + 0x250))();

          *param_2 = uVar2;

          uVar2 = (**(code **)(*piVar4 + 0x254))();

          *param_3 = uVar2;

          return 1;

        }

      }

    }

  }

  uVar5 = FUN_005713a0(*(uint8_t *)(*(int *)(param_1[0x2a] + 0x3c) + 0x406),

                       *(uint8_t *)(*(int *)(param_1[0x2a] + 0x3c) + 0x407),param_2,param_3,

                       param_5);

  return uVar5;

}
