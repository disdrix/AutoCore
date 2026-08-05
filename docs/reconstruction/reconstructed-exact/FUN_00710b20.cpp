// =============================================================================
// FUN_00710b20
// -----------------------------------------------------------------------------
// Stable ID: aa_00710b20
// Address:   0x00710b20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00710b20 @ 0x00710b20
// Stable ID: aa_00710b20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00710b20, ceil, ftol.
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

uint32_t /* width from decompiler */ FUN_00710b20(uint16_t *param_1)



{

  uint8_t uVar1;

  short sVar2;

  

  if (param_1 == (uint16_t *)0x0) {

    return 0x181a;

  }

  *param_1 = 4;

  *(uint32_t /* width from decompiler */ *)(param_1 + 1) = DAT_00af8a38;

  *(uint32_t /* width from decompiler */ *)(param_1 + 3) = DAT_00af8a3c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 5) = DAT_00af8a40;

  uVar1 = DAT_00af8a44;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x12) = 100;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 3000;

  *(uint8_t *)(param_1 + 7) = uVar1;

  param_1[0x16] = 8000;

  param_1[0x17] = 0x10;

  param_1[0x18] = 0xa0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0xc80;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1e) = 0x40;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0x40;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x22) = 0x40;

  ceil(0.90625);

  sVar2 = ftol();

  param_1[0x24] = sVar2;

  param_1[0x25] = sVar2 * 0xa0 + -0x91;

  param_1[0x19] = 1;

  param_1[0x1a] = 1;

  return 0;

}
