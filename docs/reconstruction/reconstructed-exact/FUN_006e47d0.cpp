// =============================================================================
// FUN_006e47d0
// -----------------------------------------------------------------------------
// Stable ID: aa_006e47d0
// Address:   0x006e47d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006e47d0 @ 0x006e47d0
// Stable ID: aa_006e47d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0063a3f0, FUN_006e47d0, FUN_006fb170, FUN_006fb2b0.
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

uint32_t /* width from decompiler */ * __thiscall

FUN_006e47d0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ param_4)



{

  uint32_t /* width from decompiler */ uVar1;

  int *piVar2;

  int iVar3;

  uint8_t local_50 [76];

  

  param_1[2] = param_4;

  *param_1 = &PTR_LAB_00a0e6d4;

  uVar1 = *param_2;

  piVar2 = (int *)*param_3;

  FUN_0063a3f0(param_2[2] + 0x20,param_3[2] + 0x20);

  iVar3 = (**(code **)(*piVar2 + 0x14))();

  if (iVar3 == 5) {

    FUN_006fb2b0(uVar1,piVar2,local_50);

  }

  else {

    FUN_006fb170(uVar1,piVar2,local_50);

  }

  param_1[6] = 0;

  param_1[0xb] = 0xbf800000;

  return param_1;

}
