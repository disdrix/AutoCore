// =============================================================================
// FUN_005e03a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005e03a0
// Address:   0x005e03a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005e03a0 @ 0x005e03a0
// Stable ID: aa_005e03a0
// Embedded strings (evidence for future rename):
//   - "Error"
//   - "C:\\vog\\1_code\\havok230\\include\\hkbase\\error\\hkError.cpp"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005e03a0, FUN_00631dc0, FUN_00631ff0, FUN_00632030.
//  - Strings: "Error"; "C:\\vog\\1_code\\havok230\\include\\hkbase\\error\\hkError.cpp".
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

void FUN_005e03a0(uint32_t /* width from decompiler */ param_1)



{

  uint8_t local_200 [512];

  

  FUN_00631ff0(local_200,0x200,1);

  FUN_00631dc0(param_1);

  (**(code **)(*DAT_00bc56d0 + 8))

            ("Error",0x2636fe25,local_200,

             "C:\\vog\\1_code\\havok230\\include\\hkbase\\error\\hkError.cpp",0x1b);

  FUN_00632030();

  return;

}
