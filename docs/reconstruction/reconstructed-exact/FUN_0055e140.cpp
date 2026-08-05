// =============================================================================
// FUN_0055e140
// -----------------------------------------------------------------------------
// Stable ID: aa_0055e140
// Address:   0x0055e140  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0055e140 @ 0x0055e140
// Stable ID: aa_0055e140
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0055e140.
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

void __thiscall FUN_0055e140(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  int iVar1;

  float fVar2;

  

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xe0) = *param_2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4) = param_2[1];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xe8) = param_2[2];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xec) = param_2[3];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x164) = param_2[0x11];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x168) = param_2[0x12];

  *(float *)(param_1 + 0x16c) = (float)param_2[0x11] * DAT_00a0f298;

  fVar2 = g_flOne;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x17c) = param_2[0x13];

  iVar1 = param_2[0x13];

  *(float *)(param_1 + 0x180) = fVar2 / (float)iVar1;

  *(float *)(param_1 + 0x1ac) = fVar2 / (float)iVar1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1a8) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x178);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = param_2[0x22];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = param_2[0x23];

  return;

}
