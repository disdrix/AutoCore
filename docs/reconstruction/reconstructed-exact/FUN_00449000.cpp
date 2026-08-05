// =============================================================================
// FUN_00449000
// -----------------------------------------------------------------------------
// Stable ID: aa_00449000
// Address:   0x00449000  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00449000 @ 0x00449000
// Stable ID: aa_00449000
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_00410490, FUN_00449000, FUN_004490a0.
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

void __thiscall FUN_00449000(int param_1,uint param_2)



{

  uint uVar1;

  int iVar2;

  

  iVar2 = *(int *)(param_1 + 4);

  if (iVar2 == 0) {

    uVar1 = 0;

  }

  else {

    uVar1 = *(int *)(param_1 + 8) - iVar2 >> 2;

  }

  if (uVar1 < param_2) {

    if (iVar2 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = *(int *)(param_1 + 8) - iVar2 >> 2;

    }

    FUN_004490a0(*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_2 - iVar2,&stack0x00000008);

    return;

  }

  if ((iVar2 != 0) && (param_2 < (uint)(*(int *)(param_1 + 8) - iVar2 >> 2))) {

    FUN_00410490(&param_2,iVar2 + param_2 * 4,*(int *)(param_1 + 8));

  }

  return;

}
