// =============================================================================
// FUN_006644e0
// -----------------------------------------------------------------------------
// Stable ID: aa_006644e0
// Address:   0x006644e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006644e0 @ 0x006644e0
// Stable ID: aa_006644e0
// Embedded strings (evidence for future rename):
//   - "Timer values (cpu cycles) are shown in usec (10e-6s)"
//   - "Simulate"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: FUN_00638060×2, FUN_006380a0×2, FUN_00638180×2, FUN_006381a0×2, usec×2, values×2, FUN_005b3300, FUN_0063f620.
//  - Strings: "Timer values (cpu cycles) are shown in usec (10e-6s)"; "Simulate".
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ * __thiscall FUN_006644e0(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  ulonglong uVar4;

  

  *param_1 = 0;

  param_1[1] = 0;

  param_1[2] = 0x80000000;

  param_1[3] = 0;

  param_1[4] = 0;

  param_1[5] = 0x80000000;

  DAT_00d02c6c = DAT_00d02c6c + 1;

  param_1[8] = &DAT_00d02c70;

  DAT_00d02c6c = DAT_00d02c6c + 1;

  param_1[9] = &DAT_00d02c70;

  if ((int)(param_1[5] & 0x7fffffff) < param_2) {

    iVar3 = (param_1[5] & 0x7fffffff) * 2;

    if (iVar3 <= param_2) {

      iVar3 = param_2;

    }

    FUN_005b3300(param_1 + 3,iVar3,1);

  }

  uVar4 = FUN_0063f620();

  param_1[7] = 0;

  param_1[6] = (float)((float10)_DAT_00aaab98 /

                      (-(float10)(longlong)((uVar4 >> 0x20 & 0x80000000) << 0x20) +

                      (float10)(uVar4 & 0x7fffffffffffffff)));

  iVar2 = FUN_00638060("Timer values (cpu cycles) are shown in usec (10e-6s)");

  iVar3 = param_1[8];

  if ((*(int *)(iVar3 + -8) < iVar2) || (0 < *(int *)(iVar3 + -4))) {

    piVar1 = (int *)(iVar3 + -4);

    *piVar1 = *piVar1 + -1;

    if (*piVar1 < 0) {

      FUN_00638180();

    }

    iVar3 = FUN_006381a0(iVar2);

    param_1[8] = iVar3 + 0xc;

  }

  FUN_006380a0(param_1[8],"Timer values (cpu cycles) are shown in usec (10e-6s)",iVar2 + 1);

  *(int *)(param_1[8] + -0xc) = iVar2;

  iVar2 = FUN_00638060("Simulate");

  iVar3 = param_1[9];

  if ((*(int *)(iVar3 + -8) < iVar2) || (0 < *(int *)(iVar3 + -4))) {

    piVar1 = (int *)(iVar3 + -4);

    *piVar1 = *piVar1 + -1;

    if (*piVar1 < 0) {

      FUN_00638180();

    }

    iVar3 = FUN_006381a0(iVar2);

    param_1[9] = iVar3 + 0xc;

  }

  FUN_006380a0(param_1[9],"Simulate",iVar2 + 1);

  *(int *)(param_1[9] + -0xc) = iVar2;

  return param_1;

}
