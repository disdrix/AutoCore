// =============================================================================
// FUN_00540550
// -----------------------------------------------------------------------------
// Stable ID: aa_00540550
// Address:   0x00540550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00540550 @ 0x00540550
// Stable ID: aa_00540550
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: CVOGReaction_RandomUnitScalar, FUN_00540550.
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

uint32_t /* width from decompiler */ __thiscall FUN_00540550(int param_1,int param_2,int param_3)



{

  ushort uVar1;

  int iVar2;

  int iVar3;

  

  iVar3 = (param_2 * 7 + param_3) * 0x10;

  iVar2 = *(int *)(iVar3 + 0x14 + param_1);

  iVar3 = iVar3 + param_1;

  if ((iVar2 == 0) || (*(int *)(iVar3 + 0x18) - iVar2 >> 2 == 0)) {

    return 0;

  }

  iVar2 = CVOGReaction_RandomUnitScalar();

  if (0xfffff < *(int *)(iVar2 + 0xc)) {

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc) = 0;

  }

  uVar1 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

  *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

  if (*(int *)(iVar3 + 0x14) == 0) {

    return *(uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 0x14) + ((uint)uVar1 % 0) * 4);

  }

  return *(uint32_t /* width from decompiler */ *)

          (*(int *)(iVar3 + 0x14) +

          (int)((longlong)(ulonglong)uVar1 %

               (longlong)(*(int *)(iVar3 + 0x18) - *(int *)(iVar3 + 0x14) >> 2)) * 4);

}
