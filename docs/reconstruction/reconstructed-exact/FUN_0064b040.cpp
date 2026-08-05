// =============================================================================
// FUN_0064b040
// -----------------------------------------------------------------------------
// Stable ID: aa_0064b040
// Address:   0x0064b040  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0064b040 @ 0x0064b040
// Stable ID: aa_0064b040
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006368f0, FUN_0064b040.
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

void __thiscall FUN_0064b040(int param_1,int param_2)



{

  FUN_006368f0(param_2);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x28) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x35c);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x2c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x33c);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x30) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x340);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x34) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x344);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x38) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x348);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x3c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x34c);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x44) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x350);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x48) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x354);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x4c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x358);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x40) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x304);

  return;

}
