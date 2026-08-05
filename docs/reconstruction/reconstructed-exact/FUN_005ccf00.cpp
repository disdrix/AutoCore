// =============================================================================
// FUN_005ccf00
// -----------------------------------------------------------------------------
// Stable ID: aa_005ccf00
// Address:   0x005ccf00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005ccf00 @ 0x005ccf00
// Stable ID: aa_005ccf00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×6, return×2.
//  - Notable callees: CVOGReaction_RandomUnitScalar×2, FUN_005ccf00.
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

uint __fastcall FUN_005ccf00(int param_1)



{

  ushort uVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  

  iVar2 = *(int *)(param_1 + 100);

  if ((iVar2 != 0) &&

     (iVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x27c))(),

     iVar2 < 6)) {

    iVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 100) + 4) + 4) + 4 +

                                 *(int *)(param_1 + 100)) + 0x27c))();

    if (iVar2 + -3 < 2) {

      iVar2 = 1;

    }

    else {

      iVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 100) + 4) + 4) + 4 +

                                   *(int *)(param_1 + 100)) + 0x27c))();

      iVar2 = iVar2 + -3;

    }

    iVar3 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar3 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc) = 0;

    }

    uVar1 = *(ushort *)(*(int *)(iVar3 + 8) + *(int *)(iVar3 + 0xc) * 2);

    *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + 1;

    iVar3 = (int)((longlong)(ulonglong)uVar1 % (longlong)iVar2) - iVar2 / 2;

    if (iVar3 < 0) {

      iVar3 = iVar3 + 0xc;

    }

    *(byte *)(param_1 + 0x6c) = (byte)iVar3;

    if ((byte)iVar3 < 0xc) {

      return iVar2 / 2;

    }

  }

  iVar2 = CVOGReaction_RandomUnitScalar();

  if (0xfffff < *(int *)(iVar2 + 0xc)) {

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc) = 0;

  }

  uVar1 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

  *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

  uVar4 = (uint)uVar1;

  *(char *)(param_1 + 0x6c) = (char)((ulonglong)uVar4 % 0xc);

  return uVar4 / 0xc;

}
