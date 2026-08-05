// =============================================================================
// FUN_00866220
// -----------------------------------------------------------------------------
// Stable ID: aa_00866220
// Address:   0x00866220  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00866220 @ 0x00866220
// Stable ID: aa_00866220
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×4, goto×2, return×1.
//  - Notable callees: FUN_007944a0×2, FUN_00790020, FUN_00866220.
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

void __thiscall FUN_00866220(int *param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  int *piVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  if (param_2 == 0x26) {

    if (*(char *)((int)param_1 + param_1[0x68a7] * 0x418 + 0x966) == '\0') goto LAB_0086636c;

    (**(code **)(*(int *)param_1[0x68ae] + 0x3ac))(0);

    (**(code **)(*(int *)param_1[0x68ae] + 0x278))((int)param_1 + param_1[0x68a7] * 0x418 + 0x966);

    uVar2 = FUN_007944a0();

    *(uint32_t /* width from decompiler */ *)(param_1[0x68ae] + 0x490) = uVar2;

    (**(code **)(*(int *)param_1[0x68ae] + 0x358))(0x23,0);

    piVar1 = param_1 + 0x68a7;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 < 0) {

      param_1[0x68a7] = param_1[0x68a7] + 100;

    }

  }

  else {

    if ((param_2 != 0x28) || (param_1[0x68a7] == param_1[0x68a6])) goto LAB_0086636c;

    param_1[0x68a7] = (param_1[0x68a7] + 1) % 100;

    (**(code **)(*(int *)param_1[0x68ae] + 0x3ac))(0);

    (**(code **)(*(int *)param_1[0x68ae] + 0x278))((int)param_1 + param_1[0x68a7] * 0x418 + 0x966);

    uVar2 = FUN_007944a0();

    *(uint32_t /* width from decompiler */ *)(param_1[0x68ae] + 0x490) = uVar2;

    (**(code **)(*(int *)param_1[0x68ae] + 0x358))(0x23,0);

  }

  (**(code **)(*param_1 + 0x34c))();

LAB_0086636c:

  FUN_00790020(param_2,param_3);

  return;

}
