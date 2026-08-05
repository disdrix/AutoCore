// =============================================================================
// FUN_00713d50
// -----------------------------------------------------------------------------
// Stable ID: aa_00713d50
// Address:   0x00713d50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00713d50 @ 0x00713d50
// Stable ID: aa_00713d50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_00713d50.
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

float10 FUN_00713d50(float param_1)



{

  int iVar1;

  uint uVar2;

  float10 fVar3;

  

  if ((int)param_1 <= (int)DAT_00a10fbc) {

    param_1 = DAT_00a10fbc;

  }

  if (DAT_00a10fb0 < (int)param_1) {

    if (DAT_00a10fac < (int)param_1) {

      uVar2 = (uint)((int)param_1 <= DAT_00a10fa8);

    }

    else {

      uVar2 = 2;

    }

  }

  else if (DAT_00a10fb4 < (int)param_1) {

    uVar2 = 3;

  }

  else {

    uVar2 = ((int)param_1 <= DAT_00a10fb8) + 4;

  }

  fVar3 = (float10)param_1 * (float10)*(float *)(&UNK_00a10fc0 + uVar2 * 4);

  iVar1 = uVar2 * 0x18;

  return ((((fVar3 * (float10)*(float *)(&UNK_00a10fd8 + iVar1) +

            (float10)*(float *)(&UNK_00a10fdc + iVar1)) * fVar3 +

           (float10)*(float *)(&UNK_00a10fe0 + iVar1)) * fVar3 +

          (float10)*(float *)(&UNK_00a10fe4 + iVar1)) * fVar3 +

         (float10)*(float *)(&UNK_00a10fe8 + iVar1)) * fVar3 +

         (float10)*(float *)(&UNK_00a10fec + iVar1);

}
