// =============================================================================
// FUN_00448d10
// -----------------------------------------------------------------------------
// Stable ID: aa_00448d10
// Address:   0x00448d10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00448d10 @ 0x00448d10
// Stable ID: aa_00448d10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00448d10.
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

void FUN_00448d10(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ *param_3,code *param_4)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  char cVar3;

  

  cVar3 = (*param_4)(param_2,param_1);

  if (cVar3 != '\0') {

    uVar1 = *param_2;

    uVar2 = param_2[1];

    *param_2 = *param_1;

    param_2[1] = param_1[1];

    *param_1 = uVar1;

    param_1[1] = uVar2;

  }

  cVar3 = (*param_4)(param_3,param_2);

  if (cVar3 != '\0') {

    uVar1 = *param_3;

    uVar2 = param_3[1];

    *param_3 = *param_2;

    param_3[1] = param_2[1];

    *param_2 = uVar1;

    param_2[1] = uVar2;

  }

  cVar3 = (*param_4)(param_2,param_1);

  if (cVar3 != '\0') {

    uVar1 = *param_2;

    uVar2 = param_2[1];

    *param_2 = *param_1;

    param_2[1] = param_1[1];

    *param_1 = uVar1;

    param_1[1] = uVar2;

  }

  return;

}
