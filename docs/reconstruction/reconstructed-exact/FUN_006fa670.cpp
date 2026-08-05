// =============================================================================
// FUN_006fa670
// -----------------------------------------------------------------------------
// Stable ID: aa_006fa670
// Address:   0x006fa670  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006fa670 @ 0x006fa670
// Stable ID: aa_006fa670
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_006f7eb0, FUN_006f88a0, FUN_006f9f90, FUN_006fa670.
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

void FUN_006fa670(uint32_t /* width from decompiler */ param_1,uint16_t *param_2,float param_3)



{

  char *pcVar1;

  uint8_t local_51;

  uint8_t local_50 [52];

  float local_1c;

  uint16_t local_18;

  uint16_t local_16;

  

  pcVar1 = (char *)FUN_006f7eb0(&local_51,param_2);

  if (*pcVar1 == '\0') {

    local_18 = *param_2;

    local_16 = param_2[1];

    pcVar1 = (char *)FUN_006f9f90(&local_51,local_50);

    if ((*pcVar1 != '\0') &&

       (param_3 * DAT_00a111a8 < local_1c != (param_3 * DAT_00a111a8 == local_1c))) {

      FUN_006f88a0(param_1,local_50,param_2);

    }

  }

  return;

}
