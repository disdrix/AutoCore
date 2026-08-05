// =============================================================================
// FUN_00711790
// -----------------------------------------------------------------------------
// Stable ID: aa_00711790
// Address:   0x00711790  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00711790 @ 0x00711790
// Stable ID: aa_00711790
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00711790, FUN_00713880, FUN_00713930, FUN_00714350, FUN_00714560, FUN_007147a0, FUN_00714960.
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

void FUN_00711790(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

                 uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ *param_6,int *param_7)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  uint8_t local_414 [1044];

  

  uVar1 = FUN_00714960(param_1);

  iVar2 = FUN_00713930(param_2,param_3,0x91,uVar1,local_414);

  *param_7 = iVar2;

  FUN_00713880(param_3,iVar2 + 0x91,uVar1,local_414);

  FUN_00714560(local_414,uVar1,0x40000000,local_414);

  FUN_007147a0(local_414,uVar1);

  FUN_00714350(local_414,uVar1,9,param_4,param_5);

  *param_6 = uVar1;

  return;

}
