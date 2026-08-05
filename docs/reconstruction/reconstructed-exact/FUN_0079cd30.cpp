// =============================================================================
// FUN_0079cd30
// -----------------------------------------------------------------------------
// Stable ID: aa_0079cd30
// Address:   0x0079cd30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0079cd30 @ 0x0079cd30
// Stable ID: aa_0079cd30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×1, while×1, return×1.
//  - Notable callees: FUN_00793a10×3, FUN_0079cd30.
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

uint32_t /* width from decompiler */ __thiscall FUN_0079cd30(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  char *pcVar1;

  char local_80;

  char local_7f [127];

  

  FUN_00793a10(&local_80,param_2,&DAT_00a97b80,0x80);

  FUN_00793a10(&local_80,&local_80,param_3,0x80);

  FUN_00793a10(&local_80,&local_80,&DAT_00a97b84,0x80);

  if (param_1[0x1a3] != 0) {

    (**(code **)(*param_1 + 8))(PTR_s__00afa264,param_1[0x1a3] * 4);

  }

  pcVar1 = &local_80;

  while (local_80 != '\0') {

    pcVar1 = pcVar1 + 1;

    local_80 = *pcVar1;

  }

  (**(code **)(*param_1 + 8))(&local_80,(int)pcVar1 - (int)&local_80);

  return 1;

}
