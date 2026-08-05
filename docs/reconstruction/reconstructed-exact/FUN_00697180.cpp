// =============================================================================
// FUN_00697180
// -----------------------------------------------------------------------------
// Stable ID: aa_00697180
// Address:   0x00697180  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00697180 @ 0x00697180
// Stable ID: aa_00697180
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_00697100, FUN_00697180.
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

void __fastcall FUN_00697180(uint32_t /* width from decompiler */ param_1)



{

  float fVar1;

  int iVar2;

  int extraout_ECX;

  float10 fVar3;

  

  fVar3 = (float10)FUN_00697100(param_1);

  if (((float)fVar3 != g_flZero) && (iVar2 = 0, 0 < *(int *)(extraout_ECX + 0x14))) {

    fVar1 = g_flOne / (float)fVar3;

    do {

      iVar2 = iVar2 + 1;

      *(float *)(extraout_ECX + -4 + iVar2 * 4) = fVar1 * *(float *)(extraout_ECX + -4 + iVar2 * 4);

    } while (iVar2 < *(int *)(extraout_ECX + 0x14));

  }

  return;

}
