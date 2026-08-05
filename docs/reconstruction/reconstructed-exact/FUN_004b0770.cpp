// =============================================================================
// FUN_004b0770
// -----------------------------------------------------------------------------
// Stable ID: aa_004b0770
// Address:   0x004b0770  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004b0770 @ 0x004b0770
// Stable ID: aa_004b0770
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_004af0b0, FUN_004b0770.
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

void FUN_004b0770(uint32_t /* width from decompiler */ *param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  for (param_2 = param_2 - (int)param_1; 1 < param_2 >> 3; param_2 = param_2 + -8) {

    uVar1 = *(uint32_t /* width from decompiler */ *)((int)param_1 + param_2 + -4);

    uVar2 = *(uint32_t /* width from decompiler */ *)((int)param_1 + param_2 + -8);

    *(uint32_t /* width from decompiler */ *)((int)param_1 + param_2 + -8) = *param_1;

    *(uint32_t /* width from decompiler */ *)((int)param_1 + param_2 + -4) = param_1[1];

    FUN_004af0b0(param_1,0,param_2 + -8 >> 3,uVar2,uVar1,param_3);

  }

  return;

}
