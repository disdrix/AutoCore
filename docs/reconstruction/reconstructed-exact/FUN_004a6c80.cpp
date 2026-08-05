// =============================================================================
// FUN_004a6c80
// -----------------------------------------------------------------------------
// Stable ID: aa_004a6c80
// Address:   0x004a6c80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004a6c80 @ 0x004a6c80
// Stable ID: aa_004a6c80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004a6c80.
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

void __fastcall FUN_004a6c80(int param_1)



{

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0;

  *(uint8_t *)(param_1 + 0x31e) = 0xff;

  *(uint8_t *)(param_1 + 0x31d) = 0xff;

  *(uint8_t *)(param_1 + 0x31c) = 0xff;

  *(uint8_t *)(param_1 + 799) = 0xff;

  *(uint8_t *)(param_1 + 0x322) = 0xff;

  *(uint8_t *)(param_1 + 0x321) = 0xff;

  *(uint8_t *)(param_1 + 800) = 0xff;

  *(uint8_t *)(param_1 + 0x323) = 0xff;

  *(uint8_t *)(param_1 + 0x392) = 0xff;

  *(uint8_t *)(param_1 + 0x391) = 0xff;

  *(uint8_t *)(param_1 + 0x390) = 0xff;

  *(uint8_t *)(param_1 + 0x393) = 0xff;

  *(uint8_t *)(param_1 + 0x396) = 0xff;

  *(uint8_t *)(param_1 + 0x395) = 0xff;

  *(uint8_t *)(param_1 + 0x394) = 0xff;

  *(uint8_t *)(param_1 + 0x397) = 0xff;

  return;

}
