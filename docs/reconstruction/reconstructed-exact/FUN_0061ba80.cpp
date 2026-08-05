// =============================================================================
// FUN_0061ba80
// -----------------------------------------------------------------------------
// Stable ID: aa_0061ba80
// Address:   0x0061ba80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0061ba80 @ 0x0061ba80
// Stable ID: aa_0061ba80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×5, goto×4, return×1.
//  - Notable callees: FUN_00512150, FUN_0053e510, FUN_00578270, FUN_0061b6f0, FUN_0061ba80.
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

uint32_t /* width from decompiler */ __thiscall FUN_0061ba80(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  float fVar1;

  int *piVar2;

  int *piVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  float10 fVar6;

  

  if ((param_1[6] == 0) || (*(char *)(*(int *)(param_1[6] + 0xa4) + 0x7e) == '\0'))

  goto LAB_0061bb2c;

  piVar3 = (int *)FUN_00578270();

  if (piVar3 == (int *)0x0) {

LAB_0061bb0c:

    iVar4 = param_1[0x188];

  }

  else {

    iVar4 = (**(code **)(*piVar3 + 0x1c8))();

    if (iVar4 == 0) goto LAB_0061bb0c;

    iVar4 = (**(code **)(*(int *)param_1[6] + 0x1c8))();

    if (iVar4 == 0) goto LAB_0061bb0c;

    fVar1 = (float)param_1[0x15];

    piVar2 = (int *)param_1[6];

    uVar5 = (**(code **)(*piVar3 + 0x19c))();

    (**(code **)(*piVar2 + 0x19c))(uVar5);

    fVar6 = (float10)FUN_0053e510(uVar5);

    if (fVar6 <= (float10)fVar1) goto LAB_0061bb2c;

    iVar4 = param_1[0x188];

  }

  FUN_00512150(6,0,iVar4,1);

  (**(code **)(*param_1 + 0x18))(1,1);

LAB_0061bb2c:

  FUN_0061b6f0(param_2);

  return param_2;

}
