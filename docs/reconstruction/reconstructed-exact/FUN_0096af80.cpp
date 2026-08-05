// =============================================================================
// FUN_0096af80
// -----------------------------------------------------------------------------
// Stable ID: aa_0096af80
// Address:   0x0096af80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0096af80 @ 0x0096af80
// Stable ID: aa_0096af80
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\physics\\phySkeleton.cpp"
//   - "Cannot get scale for invalid bone index"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, for×1.
//  - Notable callees: FUN_0096af80, vog_LogMessage.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\physics\\phySkeleton.cpp"; "Cannot get scale for invalid bone index".
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

uint32_t /* width from decompiler */ __fastcall FUN_0096af80(uint32_t /* width from decompiler */ *param_1,int *param_2)



{

  int iVar1;

  int unaff_EDI;

  

  if (unaff_EDI == -1) {

    iVar1 = *param_2;

    *param_1 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x9c);

    param_1[1] = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xa0);

    param_1[2] = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xa4);

    return 0;

  }

  if (param_2[3] == 0) {

    iVar1 = 0;

  }

  else {

    iVar1 = param_2[4] - param_2[3] >> 2;

  }

  if (unaff_EDI < iVar1) {

    iVar1 = *(int *)(param_2[3] + unaff_EDI * 4);

    *param_1 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xcc);

    param_1[1] = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xd0);

    param_1[2] = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xd4);

    return 0;

  }

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\physics\\phySkeleton.cpp",0x282,3,

                 "Cannot get scale for invalid bone index");

  return 0xffffffff;

}
