// =============================================================================
// FUN_00443d10
// -----------------------------------------------------------------------------
// Stable ID: aa_00443d10
// Address:   0x00443d10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00443d10 @ 0x00443d10
// Stable ID: aa_00443d10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×2, if×1, for×1.
//  - Notable callees: FUN_004437a0, FUN_00443d10, FUN_004443f0.
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

int * FUN_00443d10(int param_1,int *param_2,int param_3,int param_4)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  if (param_3 == param_4) {

    *param_2 = param_3;

    return param_2;

  }

  iVar2 = FUN_004443f0(*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_3);

  iVar1 = *(int *)(param_1 + 8);

  for (iVar3 = iVar2; iVar3 != iVar1; iVar3 = iVar3 + 0x14) {

    FUN_004437a0();

  }

  *(int *)(param_1 + 8) = iVar2;

  *param_2 = param_3;

  return param_2;

}
