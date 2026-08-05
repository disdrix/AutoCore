// =============================================================================
// FUN_005625c0
// -----------------------------------------------------------------------------
// Stable ID: aa_005625c0
// Address:   0x005625c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005625c0 @ 0x005625c0
// Stable ID: aa_005625c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×5, return×5.
//  - Notable callees: FUN_00632630×5, FUN_0055f210, FUN_0055fe50, FUN_0055ff20, FUN_00560ec0, FUN_00562530, FUN_005625c0.
//  - Return sites: 5.

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

void FUN_005625c0(uint32_t /* width from decompiler */ param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  char *pcVar2;

  

  uVar1 = param_1;

  pcVar2 = (char *)FUN_00632630(&param_1,param_1);

  if (*pcVar2 != '\0') {

    FUN_00560ec0(uVar1);

    return;

  }

  pcVar2 = (char *)FUN_00632630(&param_1,uVar1);

  if (*pcVar2 != '\0') {

    FUN_0055ff20(uVar1);

    return;

  }

  pcVar2 = (char *)FUN_00632630(&param_1,uVar1);

  if (*pcVar2 != '\0') {

    FUN_0055f210(uVar1);

    return;

  }

  pcVar2 = (char *)FUN_00632630(&param_1,uVar1);

  if (*pcVar2 != '\0') {

    FUN_0055fe50(uVar1);

    return;

  }

  pcVar2 = (char *)FUN_00632630(&param_1,uVar1);

  if (*pcVar2 != '\0') {

    FUN_00562530(uVar1,1);

  }

  return;

}
