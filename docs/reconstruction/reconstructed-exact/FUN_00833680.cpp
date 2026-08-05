// =============================================================================
// FUN_00833680
// -----------------------------------------------------------------------------
// Stable ID: aa_00833680
// Address:   0x00833680  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00833680 @ 0x00833680
// Stable ID: aa_00833680
// Embedded strings (evidence for future rename):
//   - "allocatenewobjectfromcbid failed %d Get a programmer"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: CVOGReaction_GiveItemByCbid, FUN_007a4480, FUN_00833680, Vehicle_SetWheelset.
//  - Strings: "allocatenewobjectfromcbid failed %d Get a programmer".
//  - Return sites: 3.

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

void FUN_00833680(void)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int *unaff_EDI;

  

  iVar2 = unaff_EDI[0x142];

  if (((iVar2 != 0) && (*(int *)(iVar2 + 600) == 0)) &&

     (iVar2 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0xac + iVar2) + 0x3c) +

                      0x6f4), iVar2 != -1)) {

    piVar1 = (int *)CVOGReaction_GiveItemByCbid(iVar2);

    if (piVar1 == (int *)0x0) {

      FUN_007a4480(1,"allocatenewobjectfromcbid failed %d Get a programmer",iVar2);

      return;

    }

    (**(code **)(*piVar1 + 8))(iVar2,DAT_00d1b644,1);

    if (*(int *)(piVar1[0x2a] + 0x38) == 0x10) {

      iVar2 = (*(code *)((uint32_t /* width from decompiler */ *)*piVar1)[0x7c])();

      *(uint8_t *)(iVar2 + 0xcc) = 1;

      Vehicle_SetWheelset(iVar2);

      puVar3 = (uint32_t /* width from decompiler */ *)

               (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x1f0))();

      (**(code **)*puVar3)(0,0,0,0,0,0,0,g_flOne,0);

                    /* WARNING: Could not recover jumptable at 0x008337a2. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(*unaff_EDI + 0x3bc))();

      return;

    }

    (**(code **)*piVar1)(1);

  }

  return;

}
