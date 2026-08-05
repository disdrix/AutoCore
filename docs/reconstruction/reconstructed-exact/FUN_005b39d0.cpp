// =============================================================================
// FUN_005b39d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005b39d0
// Address:   0x005b39d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b39d0 @ 0x005b39d0
// Stable ID: aa_005b39d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005b39d0, FUN_0076e240, FUN_0076eb00.
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

int __thiscall FUN_005b39d0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  FUN_0076eb00(param_1,param_2);

  *(float *)(param_1 + 0x24) = *(float *)(param_1 + 0x24) * DAT_00aaa668;

  FUN_0076e240(&local_c,param_1 + 0x20,param_1);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = local_c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = local_8;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = local_4;

  return param_1;

}
