// =============================================================================
// FUN_006ce870
// -----------------------------------------------------------------------------
// Stable ID: aa_006ce870
// Address:   0x006ce870  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006ce870 @ 0x006ce870
// Stable ID: aa_006ce870
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×12, return×1.
//  - Notable callees: FUN_006ce870.
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

void __fastcall FUN_006ce870(int param_1)



{

  if (-1 < *(int *)(param_1 + 0xb0)) {

    (**(code **)(*DAT_00b05060 + 0x14))

              (*(uint32_t /* width from decompiler */ *)(param_1 + 0xa8),*(int *)(param_1 + 0xb0) << 2,0x12);

  }

  if (-1 < *(int *)(param_1 + 0xa4)) {

    (**(code **)(*DAT_00b05060 + 0x14))

              (*(uint32_t /* width from decompiler */ *)(param_1 + 0x9c),*(int *)(param_1 + 0xa4) << 2,0x12);

  }

  if (-1 < *(int *)(param_1 + 0x98)) {

    (**(code **)(*DAT_00b05060 + 0x14))

              (*(uint32_t /* width from decompiler */ *)(param_1 + 0x90),*(int *)(param_1 + 0x98) << 2,0x12);

  }

  if (-1 < *(int *)(param_1 + 0x8c)) {

    (**(code **)(*DAT_00b05060 + 0x14))

              (*(uint32_t /* width from decompiler */ *)(param_1 + 0x84),*(int *)(param_1 + 0x8c) << 2,0x12);

  }

  if (-1 < *(int *)(param_1 + 0x80)) {

    (**(code **)(*DAT_00b05060 + 0x14))

              (*(uint32_t /* width from decompiler */ *)(param_1 + 0x78),*(int *)(param_1 + 0x80) << 2,0x12);

  }

  if (-1 < *(int *)(param_1 + 0x74)) {

    (**(code **)(*DAT_00b05060 + 0x14))

              (*(uint32_t /* width from decompiler */ *)(param_1 + 0x6c),*(int *)(param_1 + 0x74) << 2,0x12);

  }

  if (-1 < *(int *)(param_1 + 0x68)) {

    (**(code **)(*DAT_00b05060 + 0x14))

              (*(uint32_t /* width from decompiler */ *)(param_1 + 0x60),*(int *)(param_1 + 0x68) << 2,0x12);

  }

  if (-1 < (int)*(uint *)(param_1 + 0x5c)) {

    (**(code **)(*DAT_00b05060 + 0x14))

              (*(uint32_t /* width from decompiler */ *)(param_1 + 0x54),*(uint *)(param_1 + 0x5c) & 0x7fffffff,0x12);

  }

  if (-1 < *(int *)(param_1 + 0x50)) {

    (**(code **)(*DAT_00b05060 + 0x14))

              (*(uint32_t /* width from decompiler */ *)(param_1 + 0x48),*(int *)(param_1 + 0x50) << 2,0x12);

  }

  if (-1 < *(int *)(param_1 + 0x44)) {

    (**(code **)(*DAT_00b05060 + 0x14))

              (*(uint32_t /* width from decompiler */ *)(param_1 + 0x3c),*(int *)(param_1 + 0x44) << 2,0x12);

  }

  if (-1 < *(int *)(param_1 + 0x38)) {

    (**(code **)(*DAT_00b05060 + 0x14))

              (*(uint32_t /* width from decompiler */ *)(param_1 + 0x30),*(int *)(param_1 + 0x38) << 2,0x12);

  }

  if (-1 < *(int *)(param_1 + 0x2c)) {

    (**(code **)(*DAT_00b05060 + 0x14))

              (*(uint32_t /* width from decompiler */ *)(param_1 + 0x24),*(int *)(param_1 + 0x2c) << 2,0x12);

  }

  return;

}
