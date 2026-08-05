// =============================================================================
// FUN_0055dfc0
// -----------------------------------------------------------------------------
// Stable ID: aa_0055dfc0
// Address:   0x0055dfc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0055dfc0 @ 0x0055dfc0
// Stable ID: aa_0055dfc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0055dfc0.
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

void __thiscall FUN_0055dfc0(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  *param_2 = *(uint32_t /* width from decompiler */ *)(param_1 + 0xe0);

  param_2[1] = *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4);

  param_2[2] = *(uint32_t /* width from decompiler */ *)(param_1 + 0xe8);

  param_2[3] = *(uint32_t /* width from decompiler */ *)(param_1 + 0xec);

  *(uint8_t *)(param_2 + 4) = *(uint8_t *)(param_1 + 0x23c);

  param_2[8] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x210);

  param_2[9] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x214);

  param_2[10] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x218);

  param_2[0xb] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x21c);

  param_2[0xc] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x220);

  param_2[0xd] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x224);

  param_2[0xe] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x228);

  param_2[0xf] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x22c);

  param_2[5] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x234);

  param_2[0x10] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x230);

  param_2[0x11] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x164);

  param_2[0x12] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x168);

  param_2[0x13] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x17c);

  param_2[0x18] = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xcc) + 8);

  param_2[0x1a] = *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0xcc) + 0xc) + 4);

  param_2[0x1b] = *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0xcc) + 0xc) + 8);

  param_2[0x1c] = *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0xcc) + 0xc) + 0xc);

  *(uint8_t *)(param_2 + 0x19) = **(uint8_t **)(*(int *)(param_1 + 0xcc) + 0xc);

  *(uint8_t *)(param_2 + 0x1e) = *(uint8_t *)(*(int *)(*(int *)(param_1 + 0xcc) + 0xc) + 0x14)

  ;

  param_2[0x1f] = *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0xcc) + 0xc) + 0x18);

  param_2[0x20] = *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0xcc) + 0xc) + 0x1c);

  *(uint8_t *)(param_2 + 0x14) = *(uint8_t *)(param_1 + 0x23e);

  *(uint8_t *)((int)param_2 + 0x51) = *(uint8_t *)(param_1 + 0x23f);

  param_2[0x15] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x244);

  param_2[0x16] = *(float *)(param_1 + 0x248) / *(float *)(param_1 + 0x244);

  param_2[0x17] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x24c);

  *(uint8_t *)(param_2 + 0x21) = *(uint8_t *)(param_1 + 0x23d);

  param_2[0x22] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x30);

  param_2[0x23] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x34);

  return;

}
