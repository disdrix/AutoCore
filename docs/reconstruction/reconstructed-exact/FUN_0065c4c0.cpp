// =============================================================================
// FUN_0065c4c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0065c4c0
// Address:   0x0065c4c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0065c4c0 @ 0x0065c4c0
// Stable ID: aa_0065c4c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00651f60, FUN_0065c4c0.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_0065c4c0(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  

  if (param_1 != 0) {

    FUN_00651f60();

    uVar1 = DAT_009e6a88;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x58) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x54) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x50) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x68) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 100) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x60) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x7c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x78) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x74) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x70) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x80) = uVar1;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x84) = _DAT_009e6a30;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x88) = 0;

  }

  return;

}
