// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_005b94e0
// -----------------------------------------------------------------------------
// Stable ID: aa_005b94e0
// Callee of Named_VOG_DEBUG_STOP (+1 other named callers)
// Address:   0x005b94e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_VOG_DEBUG_STOP (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~110 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: CONCAT22, FUN_005b94e0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP (+1 other named callers)
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * __fastcall Named_CalleeOf_Named_VOG_DEBUG_STOP_005b94e0(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  *param_1 = 0;

  param_1[1] = 0;

  param_1[2] = 0;

  param_1[3] = 0;

  param_1[4] = 0;

  param_1[5] = 0;

  param_1[6] = 0;

  param_1[7] = 0;

  param_1[8] = 0;

  param_1[9] = 0;

  param_1[10] = 0;

  *(uint8_t *)((int)param_1 + 0x2e) = 0;

  *(uint8_t *)((int)param_1 + 0x2d) = 0;

  *(uint8_t *)(param_1 + 0xb) = 0;

  *(uint8_t *)((int)param_1 + 0x2f) = 0;

  *(uint8_t *)((int)param_1 + 0x32) = 0;

  *(uint8_t *)((int)param_1 + 0x31) = 0;

  *(uint8_t *)(param_1 + 0xc) = 0;

  *(uint8_t *)((int)param_1 + 0x33) = 0;

  param_1[0xd] = 0;

  param_1[0xe] = 0;

  param_1[0xf] = 0;

  param_1[0x10] = 0;

  param_1[0x11] = 0;

  param_1[0x12] = 0;

  param_1[0x13] = 0;

  param_1[0x14] = 0;

  param_1[0x1d] = 0;

  param_1[0x22] = 0;

  param_1[0x23] = 0;

  puVar1 = param_1 + 2;

  *(uint8_t *)((int)param_1 + 0xbe) = 0xff;

  *(uint8_t *)((int)param_1 + 0xbd) = 0xff;

  *(uint8_t *)(param_1 + 0x2f) = 0xff;

  *(uint8_t *)((int)param_1 + 0xbf) = 0xff;

  param_1[0x31] = 0;

  param_1[0x32] = 0;

  param_1[0x33] = 0;

  param_1[0x34] = 0;

  param_1[0x35] = 0;

  param_1[0x36] = 0;

  param_1[0x37] = 0;

  param_1[0x38] = 0;

  param_1[0x39] = 0;

  param_1[0x3a] = 0;

  param_1[0x3b] = 0;

  param_1[0x3c] = 0;

  param_1[0x3d] = 0;

  param_1[0x3e] = 0;

  param_1[0x3f] = 0;

  param_1[0x40] = 0;

  param_1[0x41] = 0;

  param_1[0x42] = 0;

  param_1[0x43] = 0;

  param_1[0x44] = 0;

  param_1[0x45] = 0;

  param_1[0x46] = 0;

  param_1[0x47] = 0;

  param_1[0x48] = 0;

  param_1[0x49] = 0;

  param_1[0x4a] = 0;

  param_1[0x4b] = 0;

  param_1[0x4c] = 0;

  param_1[0x4d] = 0;

  param_1[0x4e] = 0;

  param_1[0x4f] = 0;

  param_1[0x50] = 0;

  param_1[0x51] = 0;

  param_1[0x52] = 0;

  param_1[0x53] = 0;

  param_1[0x54] = 0;

  param_1[0x55] = 0;

  param_1[0x56] = 0;

  param_1[0x57] = 0;

  param_1[0x5a] = 0;

  param_1[3] = puVar1;

  *puVar1 = puVar1;

  param_1[0x58] = 0;

  param_1[0x59] = 0;

  param_1[0x5b] = 0;

  param_1[0x5c] = 0;

  param_1[0x5e] = CONCAT22((short)((uint)param_1[0x5e] >> 0x10),0x800);

  param_1[0x5d] = 0;

  puVar1 = param_1 + 0x24;

  puVar3 = puVar1;

  for (iVar2 = 0xd; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

  }

  *puVar1 = puVar1;

  param_1[0x25] = puVar1;

  param_1[0x15] = 0;

  param_1[0x16] = 0;

  param_1[0x17] = 0;

  param_1[0x18] = 0;

  param_1[0x19] = 0;

  param_1[0x1a] = 0;

  param_1[0x1b] = 0;

  param_1[0x1c] = 0;

  param_1[0x1e] = 0;

  param_1[0x1f] = 0;

  param_1[0x20] = 0;

  param_1[0x21] = 0;

  return param_1;

}
