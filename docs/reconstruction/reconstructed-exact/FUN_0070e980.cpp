// =============================================================================
// FUN_0070e980
// -----------------------------------------------------------------------------
// Stable ID: aa_0070e980
// Address:   0x0070e980  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0070e980 @ 0x0070e980
// Stable ID: aa_0070e980
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×2, for×2, return×1.
//  - Notable callees: FUN_0070e5a0, FUN_0070e810, FUN_0070e980.
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

void FUN_0070e980(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

                 uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ param_6,int param_7,int param_8)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  puVar2 = (uint32_t /* width from decompiler */ *)((-param_8 & 3U) + param_8);

  iVar1 = param_7;

  puVar3 = puVar2;

  if (0 < param_7) {

    for (; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar3 = 0;

      puVar3 = puVar3 + 1;

    }

  }

  FUN_0070e5a0(param_1,param_2,param_3,param_5,param_6,param_7,puVar2);

  iVar1 = param_7;

  puVar3 = puVar2;

  if (0 < param_7) {

    for (; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar3 = 0;

      puVar3 = puVar3 + 1;

    }

  }

  FUN_0070e810(param_5,param_4,param_5,param_6,param_7,puVar2);

  return;

}
