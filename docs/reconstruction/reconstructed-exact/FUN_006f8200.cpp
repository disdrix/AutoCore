// =============================================================================
// FUN_006f8200
// -----------------------------------------------------------------------------
// Stable ID: aa_006f8200
// Address:   0x006f8200  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f8200 @ 0x006f8200
// Stable ID: aa_006f8200
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_005d6a40, FUN_006f8200.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_006f8200(int param_1,uint8_t *param_2,float *param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  

  if ((int)param_3[0x15] < 2) {

    *(uint8_t *)((int)param_3 + 0x59) = 0;

    *param_2 = 1;

    return;

  }

  if (*(char *)((int)param_3 + 0x59) == '\0') {

    FUN_005d6a40(param_1 + 0x70,param_3);

    *(uint8_t *)((int)param_3 + 0x59) = 1;

  }

  fVar1 = param_3[4];

  fVar2 = param_3[5];

  fVar3 = param_3[6];

  if ((fVar1 * *(float *)(param_1 + 0x70) +

      fVar2 * *(float *)(param_1 + 0x80) + fVar3 * *(float *)(param_1 + 0x90)) * *param_3 +

      (fVar1 * *(float *)(param_1 + 0x74) +

      fVar2 * *(float *)(param_1 + 0x84) + fVar3 * *(float *)(param_1 + 0x94)) * param_3[1] +

      (fVar1 * *(float *)(param_1 + 0x78) +

      fVar2 * *(float *)(param_1 + 0x88) + fVar3 * *(float *)(param_1 + 0x98)) * param_3[2] <

      _DAT_00a0ef10) {

    *param_2 = 1;

    return;

  }

  *param_2 = 0;

  return;

}
