// =============================================================================
// FUN_00665bf0
// -----------------------------------------------------------------------------
// Stable ID: aa_00665bf0
// Address:   0x00665bf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00665bf0 @ 0x00665bf0
// Stable ID: aa_00665bf0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00651a40, FUN_00665bf0.
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

void __thiscall FUN_00665bf0(int param_1,int param_2)



{

  FUN_00651a40(param_2);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x10) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x20);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x14) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x24);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x18) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x28);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x1c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x20) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x50);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x24) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x54);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x28) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x58);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x2c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x50) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x40);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x54) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x44);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x58) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x48);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x5c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x60) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x70);

  *(uint32_t /* width from decompiler */ *)(param_2 + 100) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x74);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x68) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x78);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x6c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x7c);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x30) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x30);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x34) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x34);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x38) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x38);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x3c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x40) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x60);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x44) = *(uint32_t /* width from decompiler */ *)(param_1 + 100);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x48) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x68);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x4c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x70) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x80);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x74) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x84);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x78) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x88);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x7c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x8c);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x80) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x90);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x84) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x94);

  return;

}
