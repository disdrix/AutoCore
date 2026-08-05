// =============================================================================
// FUN_006463b0
// -----------------------------------------------------------------------------
// Stable ID: aa_006463b0
// Address:   0x006463b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006463b0 @ 0x006463b0
// Stable ID: aa_006463b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_006463b0, FUN_006483f0, FUN_00652b30, FUN_00659140.
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

uint32_t /* width from decompiler */ * __thiscall

FUN_006463b0(uint32_t /* width from decompiler */ *param_1,int param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  short *psVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  

  param_1[2] = param_4;

  *param_1 = &PTR_FUN_009e4590;

  param_1[3] = param_3;

  param_1[4] = param_2;

  if (param_2 == 0) {

    iVar2 = (**(code **)(*DAT_00b05060 + 0x10))(0xc,6);

    *(uint16_t *)(iVar2 + 4) = 0xc;

    uVar3 = FUN_006483f0();

    param_1[4] = uVar3;

  }

  else {

    *(short *)(param_2 + 6) = *(short *)(param_2 + 6) + 1;

  }

  if (param_1[3] == 0) {

    iVar2 = (**(code **)(*DAT_00b05060 + 0x10))(0xc,6);

    *(uint16_t *)(iVar2 + 4) = 0xc;

    uVar3 = FUN_00652b30();

    param_1[3] = uVar3;

  }

  else {

    psVar1 = (short *)(param_1[3] + 6);

    *psVar1 = *psVar1 + 1;

  }

  if (param_1[2] == 0) {

    iVar2 = (**(code **)(*DAT_00b05060 + 0x10))(0xc,5);

    *(uint16_t *)(iVar2 + 4) = 0xc;

    uVar3 = FUN_00659140();

    param_1[2] = uVar3;

    return param_1;

  }

  psVar1 = (short *)(param_1[2] + 6);

  *psVar1 = *psVar1 + 1;

  return param_1;

}
