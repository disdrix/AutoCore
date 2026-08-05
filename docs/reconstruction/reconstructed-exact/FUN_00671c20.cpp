// =============================================================================
// FUN_00671c20
// -----------------------------------------------------------------------------
// Stable ID: aa_00671c20
// Address:   0x00671c20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00671c20 @ 0x00671c20
// Stable ID: aa_00671c20
// Embedded strings (evidence for future rename):
//   - "Set Pitch Warp: %f"
//   - "C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\AudioInThread.cpp"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00671c20, FUN_00677c00, FUN_0076cec0, vog_LogMessage.
//  - Strings: "Set Pitch Warp: %f".
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

uint32_t /* width from decompiler */ FUN_00671c20(float *param_1)



{

  float *pfVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  pfVar1 = param_1;

  FUN_00677c00();

  uVar2 = FUN_0076cec0(&param_1,"Set Pitch Warp: %f",(double)*pfVar1);

  vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\AudioInThread.cpp"

                 ,0x2bd,1,uVar2);

  return 0;

}
