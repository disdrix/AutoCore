// =============================================================================
// FUN_00702330
// -----------------------------------------------------------------------------
// Stable ID: aa_00702330
// Address:   0x00702330  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00702330 @ 0x00702330
// Stable ID: aa_00702330
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_007020e0, FUN_007021e0, FUN_00702330.
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

uint32_t /* width from decompiler */ __thiscall

FUN_00702330(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ *param_3,int param_4,

            uint32_t /* width from decompiler */ param_5)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  *param_3 = 0;

  *param_2 = 0;

  param_1[1] = 0x7f7fffff;

  *param_1 = 0x3727c5ac;

  cVar1 = FUN_007020e0(param_5,param_1,param_1 + 1);

  *(char *)(param_4 + 0x44) = cVar1;

  if (cVar1 == '\x01') {

    uVar2 = FUN_007021e0(param_2,param_3,param_4,param_5);

    return uVar2;

  }

  return 2;

}
