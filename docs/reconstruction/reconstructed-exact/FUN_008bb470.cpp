// =============================================================================
// FUN_008bb470
// -----------------------------------------------------------------------------
// Stable ID: aa_008bb470
// Address:   0x008bb470  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008bb470 @ 0x008bb470
// Stable ID: aa_008bb470
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: CVOGReaction_RandomUnitScalar, FUN_0050e770, FUN_008bb470.
//  - Return sites: 1.

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

void FUN_008bb470(void)



{

  ushort uVar1;

  int iVar2;

  uint uVar3;

  int unaff_ESI;

  uint32_t /* width from decompiler */ local_4;

  

  if ((*(int *)(unaff_ESI + 0x588) != 0) && (*(int *)(unaff_ESI + 0x554) != 0)) {

    do {

      iVar2 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar2 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc) = 0;

      }

      uVar1 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

      *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

      uVar3 = (uint)uVar1 % *(uint *)(unaff_ESI + 0x554);

    } while (*(uint *)(unaff_ESI + 0x50c) == uVar3);

    *(uint *)(unaff_ESI + 0x50c) = uVar3;

    FUN_0050e770(uVar3,&local_4);

    (**(code **)(**(int **)(unaff_ESI + 0x588) + 0x1d8))(local_4,1,1);

    (**(code **)(**(int **)(unaff_ESI + 0x588) + 0xcc))(1);

    (**(code **)(**(int **)(unaff_ESI + 0x588) + 0x34c))();

  }

  return;

}
