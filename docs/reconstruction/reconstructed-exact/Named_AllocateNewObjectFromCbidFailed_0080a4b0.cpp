// =============================================================================
// Named_AllocateNewObjectFromCbidFailed_0080a4b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0080a4b0
// Address:   0x0080a4b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_AllocateNewObjectFromCbidFailed_0080a4b0 @ 0x0080a4b0
// Stable ID: aa_0080a4b0
// Embedded strings (evidence for future rename):
//   - "allocatenewobjectfromcbid failed %d Get a programmer"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: CVOGReaction_GiveItemByCbid, FUN_004c49d0, FUN_007a4480, Named_AllocateNewObjectFromCbidFailed_0080a4b0.
//  - Strings: "allocatenewobjectfromcbid failed %d Get a programmer".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "allocatenewobjectfromcbid failed %d Get a programmer"
 * Domain alias of FUN_0080a4b0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_AllocateNewObjectFromCbidFailed_0080a4b0(void)



{

  int iVar1;

  int iVar2;

  int in_EAX;

  int *piVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  int unaff_EBX;

  int *piVar6;

  

  piVar3 = (int *)CVOGReaction_GiveItemByCbid(*(int *)(unaff_EBX + 4));

  if (piVar3 == (int *)0x0) {

    FUN_007a4480(1,"allocatenewobjectfromcbid failed %d Get a programmer",

                 *(uint32_t /* width from decompiler */ *)(unaff_EBX + 4));

    return;

  }

  (**(code **)(*piVar3 + 8))(*(uint32_t /* width from decompiler */ *)(unaff_EBX + 4),*(uint32_t /* width from decompiler */ *)(in_EAX + 0xe04),0);

  iVar4 = (**(code **)(*piVar3 + 0x1d4))();

  (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0xc4))();

  iVar4 = (**(code **)(*piVar3 + 0x1d4))();

  (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x218))

            (*(uint32_t /* width from decompiler */ *)(in_EAX + 0xe04));

  iVar4 = (**(code **)(*piVar3 + 0x1d4))();

  (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x104))(0);

  piVar6 = (int *)(in_EAX + 0xe9c);

  iVar4 = 0xc;

  do {

    if (*piVar6 != 0) {

      iVar1 = *piVar6;

      iVar2 = *(int *)(*(int *)(iVar1 + 4) + 4);

      if ((*(int *)(iVar2 + 0x164 + iVar1) == *(int *)(unaff_EBX + 0xd8)) &&

         (*(int *)(iVar2 + 0x168 + iVar1) == *(int *)(unaff_EBX + 0xdc))) {

        uVar5 = (**(code **)(*piVar3 + 0x1d4))();

        FUN_004c49d0(uVar5);

      }

    }

    piVar6 = piVar6 + 1;

    iVar4 = iVar4 + -1;

  } while (iVar4 != 0);

  return;

}
