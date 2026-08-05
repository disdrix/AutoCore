// =============================================================================
// FUN_0056b280
// -----------------------------------------------------------------------------
// Stable ID: aa_0056b280
// Address:   0x0056b280  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0056b280 @ 0x0056b280
// Stable ID: aa_0056b280
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_0056b280.
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

int __fastcall FUN_0056b280(int param_1)



{

  int iVar1;

  float fVar2;

  

  iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x214))();

  if (iVar1 == 0) {

    iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1);

    if (iVar1 == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = *(int *)(iVar1 + 0x3c);

    }

    fVar2 = *(float *)(iVar1 + 0x53c);

  }

  else {

    iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1);

    if (iVar1 == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = *(int *)(iVar1 + 0x3c);

    }

    fVar2 = *(float *)(iVar1 + 0x53c);

    iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x214))();

    iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x27c))();

    fVar2 = (float)iVar1 * fVar2;

  }

  if (fVar2 < 0.0) {

    return (int)(fVar2 - g_flMissionXpRoundBias);

  }

  return (int)(fVar2 + g_flMissionXpRoundBias);

}
