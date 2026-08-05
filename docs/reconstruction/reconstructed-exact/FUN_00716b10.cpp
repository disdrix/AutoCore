// =============================================================================
// FUN_00716b10
// -----------------------------------------------------------------------------
// Stable ID: aa_00716b10
// Address:   0x00716b10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00716b10 @ 0x00716b10
// Stable ID: aa_00716b10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×3, do×2, while×2, return×1.
//  - Notable callees: FUN_00716b10.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



int FUN_00716b10(int param_1,float param_2,float param_3,float *param_4)



{

  float fVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  float *pfVar4;

  int iVar5;

  

  iVar2 = 0;

  if (DAT_00a10e7c < param_2 * DAT_00a0f708) {

    puVar3 = &DAT_00a10e7c;

    do {

      pfVar4 = (float *)(puVar3 + 1);

      puVar3 = puVar3 + 1;

      iVar2 = iVar2 + 1;

    } while (*pfVar4 < param_2 * DAT_00a0f708);

  }

  fVar1 = *(float *)(param_1 + iVar2 * 4);

  pfVar4 = (float *)(param_1 + iVar2 * 4);

  iVar5 = iVar2;

  do {

    if (fVar1 < *pfVar4) {

      fVar1 = *pfVar4;

      iVar5 = iVar2;

    }

    iVar2 = iVar2 + 1;

    pfVar4 = pfVar4 + 1;

  } while ((iVar2 < 0x4a) &&

          (*(float *)(((int)&DAT_00a10e7c - param_1) + (int)pfVar4) <= param_2 * _DAT_00a132fc));

  if (fVar1 < param_3) {

    fVar1 = (fVar1 + param_3) * DAT_00a0f298;

  }

  *param_4 = fVar1;

  return iVar5;

}
