// =============================================================================
// FUN_004b0f00
// -----------------------------------------------------------------------------
// Stable ID: aa_004b0f00
// Address:   0x004b0f00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004b0f00 @ 0x004b0f00
// Stable ID: aa_004b0f00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, for×1.
//  - Notable callees: FUN_004b0f00, ROUND.
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

uint32_t /* width from decompiler */ __thiscall FUN_004b0f00(int *param_1,int param_2)



{

  int iVar1;

  float *pfVar2;

  float fVar3;

  

  iVar1 = *param_1;

  if ((*(byte *)(iVar1 + 0x98c) & 0x40) != 0) {

    return 1;

  }

  if (*(char *)(iVar1 + 0x7fb) == '\0') {

    fVar3 = (float)param_1[0x5c];

    for (pfVar2 = *(float **)(param_1[1] + 0x2f4); pfVar2 != (float *)(iVar1 + 0x14);

        pfVar2 = (float *)pfVar2[0xbd]) {

      fVar3 = *pfVar2 + fVar3;

    }

    if ((int)ROUND(fVar3 * DAT_00a0f520) <= param_2) {

      return 1;

    }

  }

  return 0;

}
