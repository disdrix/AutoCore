// =============================================================================
// FUN_005eaf50
// -----------------------------------------------------------------------------
// Stable ID: aa_005eaf50
// Address:   0x005eaf50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005eaf50 @ 0x005eaf50
// Stable ID: aa_005eaf50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: ABS×3, FUN_005eaf50, FUN_00645230.
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

void __thiscall FUN_005eaf50(int param_1,uint8_t *param_2,int param_3,float param_4)



{

  char *pcVar1;

  uint8_t local_21 [29];

  

  pcVar1 = (char *)FUN_00645230(local_21,param_3,param_4);

  if ((*pcVar1 != '\0') &&

     ((ABS(*(float *)(param_1 + 0x38) - *(float *)(param_3 + 0x38)) <= param_4 &&

      ABS(*(float *)(param_1 + 0x34) - *(float *)(param_3 + 0x34)) <= param_4) &&

      ABS(*(float *)(param_1 + 0x30) - *(float *)(param_3 + 0x30)) <= param_4)) {

    *param_2 = 1;

    return;

  }

  *param_2 = 0;

  return;

}
