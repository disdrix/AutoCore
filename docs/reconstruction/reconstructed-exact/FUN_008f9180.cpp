// =============================================================================
// FUN_008f9180
// -----------------------------------------------------------------------------
// Stable ID: aa_008f9180
// Address:   0x008f9180  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008f9180 @ 0x008f9180
// Stable ID: aa_008f9180
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_008f9180.
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

void __fastcall FUN_008f9180(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  

  uVar1 = DAT_00a0f298;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4b8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4bc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4b4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x504) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x508) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x144c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1450) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1454) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1458) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1460) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1464) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1468) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x146c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1470) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1474) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1478) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1480) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1484) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1488) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x148c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1490) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1494) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1498) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x149c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14a0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14a4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14a8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14ac) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14b0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14b4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14b8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14bc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14c0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14c4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14c8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14cc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14d0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14d4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1440) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1444) = uVar1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1448) = 0;

  *(uint8_t *)(param_1 + 0x14dc) = 0;

  return;

}
