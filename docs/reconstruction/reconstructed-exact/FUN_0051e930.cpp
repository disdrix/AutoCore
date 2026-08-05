// =============================================================================
// FUN_0051e930
// -----------------------------------------------------------------------------
// Stable ID: aa_0051e930
// Address:   0x0051e930  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0051e930 @ 0x0051e930
// Stable ID: aa_0051e930
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004e87d0, FUN_004e88e0, FUN_0051e930.
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

void __thiscall FUN_0051e930(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ *param_4)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint8_t local_10 [16];

  

  puVar1 = (uint32_t /* width from decompiler */ *)FUN_004e88e0(local_10,param_1 + 0x80);

  *param_3 = *puVar1;

  param_3[1] = puVar1[1];

  param_3[2] = puVar1[2];

  puVar1 = (uint32_t /* width from decompiler */ *)FUN_004e87d0(local_10,param_1 + 0x90);

  *param_4 = *puVar1;

  param_4[1] = puVar1[1];

  param_4[2] = puVar1[2];

  param_4[3] = puVar1[3];

  return;

}
