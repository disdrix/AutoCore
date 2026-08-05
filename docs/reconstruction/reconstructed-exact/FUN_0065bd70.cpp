// =============================================================================
// FUN_0065bd70
// -----------------------------------------------------------------------------
// Stable ID: aa_0065bd70
// Address:   0x0065bd70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0065bd70 @ 0x0065bd70
// Stable ID: aa_0065bd70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00651f60, FUN_0065bd70.
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

int __fastcall FUN_0065bd70(int param_1)



{

  float fVar1;

  

  FUN_00651f60();

  fVar1 = g_flOne;

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

  *(float *)(param_1 + 0x70) = fVar1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x74) = DAT_009e64c0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x78) = DAT_00aaabe8;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7c) = DAT_009e64bc;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x80) = DAT_009e64b8;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x84) = 0;

  return param_1;

}
