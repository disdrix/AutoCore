// =============================================================================
// Named_AllocateNewObjectFromCbidFailed_0090fee0
// -----------------------------------------------------------------------------
// Stable ID: aa_0090fee0
// Address:   0x0090fee0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_AllocateNewObjectFromCbidFailed_0090fee0 @ 0x0090fee0
// Stable ID: aa_0090fee0
// Embedded strings (evidence for future rename):
//   - "allocatenewobjectfromcbid failed %d Get a programmer"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: CVOGReaction_GiveItemByCbid, FUN_00755f10, FUN_0076c4d0, FUN_007a4480, FUN_0090fe50, Named_AllocateNewObjectFromCbidFailed_0090fee0.
//  - Strings: "allocatenewobjectfromcbid failed %d Get a programmer".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "allocatenewobjectfromcbid failed %d Get a programmer"
 * Domain alias of FUN_0090fee0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Named_AllocateNewObjectFromCbidFailed_0090fee0(int *param_1)



{

  int iVar1;

  int in_EAX;

  int *piVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  

  FUN_0090fe50();

  piVar2 = (int *)CVOGReaction_GiveItemByCbid(in_EAX);

  param_1[0x28a] = (int)piVar2;

  if (piVar2 == (int *)0x0) {

    FUN_007a4480(1,"allocatenewobjectfromcbid failed %d Get a programmer");

    return;

  }

  (**(code **)(*piVar2 + 8))();

  puVar3 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x28a] + 0x1cc))();

  (**(code **)*puVar3)(1,0,0,0,0,0,0,g_flOne,0);

  DAT_00d09a68 = 0;

  iVar1 = puVar3[2];

  if (iVar1 != 0) {

    DAT_00d09a68 = iVar1;

    iVar4 = (**(code **)(*param_1 + 0x1a8))();

    if (iVar1 != 0) {

      *(uint8_t *)(iVar4 + 0x48) = 1;

      *(uint32_t /* width from decompiler */ *)(iVar4 + 0x44) = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x40);

      FUN_0076c4d0();

      (**(code **)(**(int **)(iVar4 + 8) + 4))(iVar1);

      FUN_00755f10(iVar1);

    }

  }

  return;

}
