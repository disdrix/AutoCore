// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, goto×1.
//  - Notable callees: FUN_007a69d0, FUN_007a6de0, FUN_007fdfb0, FUN_0080a410, Refinery.
//  - Strings: "Failed adding item to Refinery.".
//  - Return sites: 3.

// =============================================================================
// Client_OnRefineryAddItemFailure
// -----------------------------------------------------------------------------
// Purpose:  Refinery add-item failure messages when object missing from inventory.
//
// Address:  0x0080a410  (autoassault.exe, image base 0x400000)
// Stable:   aa_0080a410
// System:   inventory-transfer
//
// String evidence: "Failed adding item to Refinery (object doesn't exist in inventory)."
//
// Exactness: Behavior-preserving rewrite of decompiler control flow (scaffold).
// Bit-for-bit vs retail EXE: DEFERRED.
// Source:    Prefer over FUN_0080a410.cpp; FUN_* left intact as raw scaffold twin.
// =============================================================================

/*
 * Behavioral notes:
 * - Renamed from FUN_0080a410 using string evidence: "Failed adding item to Refinery (object doesn't exist in inventory)."
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 */

void Client_OnRefineryAddItemFailure(void)

{

  int iVar1;

  int iVar2;

  char cVar3;

  uint32_t /* width from decompiler */ uVar4;

  int unaff_ESI;

  int unaff_EDI;

  char *pcVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  

  FUN_007a69d0();

  if (*(char *)(unaff_EDI + 0x1c) != '\0') {

    iVar1 = *(int *)(unaff_ESI + 0xe98);

    iVar2 = *(int *)(*(int *)(iVar1 + 4) + 4);

    if ((*(int *)(unaff_EDI + 8) == *(int *)(iVar2 + 0x164 + iVar1)) &&

       (*(int *)(unaff_EDI + 0xc) == *(int *)(iVar2 + 0x168 + iVar1))) {

      if (*(int *)(iVar1 + 0xcd0) == 0) {

        pcVar5 = "Failed adding item to Refinery (object doesn\'t exist in inventory).";

      }

      else {

        if (*(int **)(unaff_ESI + 0x1054) == (int *)0x0) {

          return;

        }

        cVar3 = (**(code **)(**(int **)(unaff_ESI + 0x1054) + 0x3d8))();

        if (cVar3 == '\0') {

          return;

        }

        pcVar5 = 

        "Failed adding item to Refinery: Object found in inventory but couldnt be added to.";

      }

      goto LAB_0080a48c;

    }

  }

  pcVar5 = "Failed adding item to Refinery.";

LAB_0080a48c:

  uVar8 = 0;

  uVar7 = 1;

  uVar6 = 0xffffffff;

  uVar4 = FUN_007a6de0(pcVar5,0xffffffff);

  FUN_007fdfb0(unaff_ESI,uVar4,uVar6,uVar7,uVar8);

  return;

}
