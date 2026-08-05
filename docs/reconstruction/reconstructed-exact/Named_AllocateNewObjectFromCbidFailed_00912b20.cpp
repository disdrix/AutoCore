// =============================================================================
// Named_AllocateNewObjectFromCbidFailed_00912b20
// -----------------------------------------------------------------------------
// Stable ID: aa_00912b20
// Address:   0x00912b20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_AllocateNewObjectFromCbidFailed_00912b20 @ 0x00912b20
// Stable ID: aa_00912b20
// Embedded strings (evidence for future rename):
//   - "allocatenewobjectfromcbid failed %d Get a programmer"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: CVOGReaction_GiveItemByCbid, FUN_00540350, FUN_007a4480, Named_AllocateNewObjectFromCbidFailed_00912b20.
//  - Strings: "allocatenewobjectfromcbid failed %d Get a programmer".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "allocatenewobjectfromcbid failed %d Get a programmer"
 * Domain alias of FUN_00912b20 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_AllocateNewObjectFromCbidFailed_00912b20(uint32_t /* width from decompiler */ param_1)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  int *unaff_ESI;

  

  if (*unaff_ESI != 0) {

    return 1;

  }

  iVar1 = FUN_00540350(param_1);

  if (iVar1 != 0) {

    iVar1 = *(int *)(iVar1 + 0x34);

    piVar2 = (int *)CVOGReaction_GiveItemByCbid(iVar1);

    if (piVar2 == (int *)0x0) {

      iVar3 = 0;

    }

    else {

      iVar3 = (**(code **)(*piVar2 + 0x1cc))();

    }

    *unaff_ESI = iVar3;

    if (iVar3 != 0) {

      (**(code **)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3) + 8))

                (iVar1,DAT_00d1b644,1);

      (**(code **)(*(int *)(*(int *)(*(int *)(*unaff_ESI + 4) + 4) + 4 + *unaff_ESI) + 0x218))

                (DAT_00d1b644);

      (*(code *)**(uint32_t /* width from decompiler */ **)*unaff_ESI)(1,0,0,0,0,0,0,g_flOne,0);

      return 1;

    }

    FUN_007a4480(1,"allocatenewobjectfromcbid failed %d Get a programmer",iVar1);

  }

  return 0;

}
