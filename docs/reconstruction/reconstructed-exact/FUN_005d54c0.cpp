// =============================================================================
// FUN_005d54c0
// -----------------------------------------------------------------------------
// Stable ID: aa_005d54c0
// Address:   0x005d54c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d54c0 @ 0x005d54c0
// Stable ID: aa_005d54c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_005d54c0.
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

void __thiscall FUN_005d54c0(int param_1,int param_2)



{

  if (param_2 != 0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x160);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x164);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x168);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x16c);

    return;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = DAT_009dacc8;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = DAT_009daccc;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = DAT_009dacd0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = DAT_009dacd4;

  return;

}
