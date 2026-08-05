// =============================================================================
// FUN_00762e90
// -----------------------------------------------------------------------------
// Stable ID: aa_00762e90
// Address:   0x00762e90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00762e90 @ 0x00762e90
// Stable ID: aa_00762e90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_00762e90.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ __thiscall FUN_00762e90(int param_1,int *param_2,int param_3)



{

  int iVar1;

  int iVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  

  if ((2 < DAT_00afa2dc) || (*(char *)(param_1 + 0x139) != '\0')) {

    iVar1 = *(int *)(param_3 + 0x30);

    if ((param_2[0x16] != 0) &&

       ((param_2[0x17] != 0 && (*(int *)(param_2[0x17] + 0x1c) != param_2[0x18])))) {

      (**(code **)(*param_2 + 0x80))();

    }

    iVar2 = param_2[0x19];

    iVar1 = *(int *)(iVar1 + 8);

    fVar3 = *(float *)(iVar2 + 0x90) - *(float *)(iVar1 + 0x90);

    fVar4 = *(float *)(iVar2 + 0x94) - *(float *)(iVar1 + 0x94);

    fVar5 = *(float *)(iVar2 + 0x98) - *(float *)(iVar1 + 0x98);

    if ((*(byte *)(param_2 + 0x2f) & 1) != 0) {

      (**(code **)(*param_2 + 0x5c))();

    }

    if (fVar5 * fVar5 + fVar4 * fVar4 + fVar3 * fVar3 <

        ((float)param_2[0xd] + _DAT_00afa2e4) * ((float)param_2[0xd] + _DAT_00afa2e4)) {

      *(byte *)(param_2 + 0x2f) = *(byte *)(param_2 + 0x2f) | 0x80;

      (**(code **)(*param_2 + 0x3c))(param_3);

      return 0;

    }

  }

  *(byte *)(param_2 + 0x2f) = *(byte *)(param_2 + 0x2f) & 0x7f;

  (**(code **)(*param_2 + 0x3c))(param_3);

  return 0;

}
