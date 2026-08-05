// =============================================================================
// FUN_006f8160
// -----------------------------------------------------------------------------
// Stable ID: aa_006f8160
// Address:   0x006f8160  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f8160 @ 0x006f8160
// Stable ID: aa_006f8160
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_006f8160.
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

void __thiscall FUN_006f8160(int param_1,float *param_2,ushort *param_3,int param_4)



{

  ushort uVar1;

  float fVar2;

  float *pfVar3;

  

  if (*(ushort *)(param_4 + 0x38) < 3) {

    uVar1 = *param_3;

    param_2[3] = 0.0;

    param_2[2] = 0.0;

    param_2[1] = 0.0;

    *param_2 = 0.0;

    param_2[uVar1] = -*(float *)(param_4 + 0x30);

    return;

  }

  if (*(ushort *)(param_4 + 0x38) < 6) {

    fVar2 = -*(float *)(param_4 + 0x30);

    pfVar3 = (float *)((*param_3 + 4) * 0x10 + param_1);

    *param_2 = fVar2 * *pfVar3;

    param_2[1] = fVar2 * pfVar3[1];

    param_2[2] = fVar2 * pfVar3[2];

    param_2[3] = fVar2 * pfVar3[3];

    return;

  }

  *param_2 = *(float *)(param_4 + 0x20);

  param_2[1] = *(float *)(param_4 + 0x24);

  param_2[2] = *(float *)(param_4 + 0x28);

  param_2[3] = *(float *)(param_4 + 0x2c);

  return;

}
