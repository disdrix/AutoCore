// =============================================================================
// FUN_005815a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005815a0
// Address:   0x005815a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005815a0 @ 0x005815a0
// Stable ID: aa_005815a0
// Embedded strings (evidence for future rename):
//   - "VOG_DEBUG_STOP"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_005815a0, FUN_007a4480.
//  - Strings: "VOG_DEBUG_STOP".
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

void __thiscall FUN_005815a0(int param_1,char param_2)



{

  if (param_2 != *(char *)(param_1 + 0xd)) {

    if (*(char *)(param_1 + 0xe) == '\x01') {

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    *(char *)(param_1 + 0xd) = param_2;

  }

  return;

}
