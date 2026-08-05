// =============================================================================
// FUN_00700ce0
// -----------------------------------------------------------------------------
// Stable ID: aa_00700ce0
// Address:   0x00700ce0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00700ce0 @ 0x00700ce0
// Stable ID: aa_00700ce0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00700810×2, FUN_00700940×2, FUN_00700ce0.
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

void __fastcall FUN_00700ce0(int param_1)



{

  float *pfVar1;

  float *pfVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float local_90;

  float local_8c;

  float local_88;

  float local_84;

  float local_80;

  float local_7c;

  float local_78;

  float local_60;

  float local_5c;

  float local_58;

  float local_50;

  float local_4c;

  float local_48;

  float local_30;

  float local_2c;

  float local_28;

  float local_18;

  

  pfVar1 = *(float **)(param_1 + 0x50);

  FUN_00700940(pfVar1,&local_50);

  pfVar2 = *(float **)(param_1 + 0x50);

  fVar3 = (local_50 - local_30) - *pfVar2;

  fVar4 = (local_4c - local_2c) - pfVar2[1];

  fVar5 = (local_48 - local_28) - pfVar2[2];

  local_90 = -*pfVar1;

  local_8c = -pfVar1[1];

  local_88 = -pfVar1[2];

  local_84 = -pfVar1[3];

  FUN_00700940(&local_90,&local_80);

  pfVar1 = *(float **)(param_1 + 0x50);

  local_18 = local_78 - local_58;

  fVar6 = (local_80 - local_60) - *pfVar1;

  fVar7 = (local_7c - local_5c) - pfVar1[1];

  fVar4 = fVar3 * fVar3 + fVar4 * fVar4 + fVar5 * fVar5;

  fVar3 = fVar6 * fVar6 + fVar7 * fVar7 + (local_18 - pfVar1[2]) * (local_18 - pfVar1[2]);

  if (fVar3 < fVar4 != (fVar3 == fVar4)) {

    FUN_00700810(&local_50);

    return;

  }

  FUN_00700810(&local_80);

  return;

}
