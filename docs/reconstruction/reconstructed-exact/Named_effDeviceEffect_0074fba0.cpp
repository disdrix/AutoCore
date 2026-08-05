// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×7, return×3, for×2, goto×1.
//  - Notable callees: FUN_006a5dac, FUN_006b7a5a, FUN_0074f360, FUN_0074fba0, FUN_0076cec0, vog_LogMessage.
//  - Strings: "Can\'t Set Technique"; "%s - %s\r\n%s".
//  - Return sites: 3.

// =============================================================================
// Named_effDeviceEffect_0074fba0
// -----------------------------------------------------------------------------
// Stable ID: aa_0074fba0
// Address:   0x0074fba0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "effDeviceEffect"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_effDeviceEffect_0074fba0(int param_1,int param_2)



{

  char cVar1;

  int *piVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  

  if (param_2 == 0) {

    return 0xffffffff;

  }

  if (*(int *)(param_1 + 0x20) != param_2) {

    if ((&DAT_00afe010)[*(int *)(param_1 + 0x28) * 3] != 0) {

      FUN_0074f360();

    }

    piVar2 = *(int **)(param_1 + 0xc);

    if (piVar2 == (int *)0x0) {

      iVar3 = -0x7789f794;

    }

    else {

      iVar3 = (**(code **)(*piVar2 + 0xe8))(piVar2,*(uint32_t /* width from decompiler */ *)(param_2 + 4));

      if (-1 < iVar3) {

        *(int *)(param_1 + 0x20) = param_2;

        goto LAB_0074fc3f;

      }

    }

    uVar4 = FUN_006b7a5a(iVar3,"Can\'t Set Technique");

    uVar4 = FUN_006a5dac(iVar3,uVar4);

    uVar4 = FUN_0076cec0(&stack0xfffffffc,"%s - %s\r\n%s",uVar4);

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effDeviceEffect.cpp",

                   0x142,3,uVar4);

    return 0xffffffff;

  }

LAB_0074fc3f:

  cVar1 = *(char *)(DAT_00d1f048 + 0xc);

  if (*(char *)(param_2 + 0x10) != cVar1) {

    *(bool *)(DAT_00d1f048 + 0xc) = cVar1 == '\0';

    if (DAT_00d1f044[0x1df] == 1) {

      (**(code **)(*(int *)*DAT_00d1f044 + 0x134))((int *)*DAT_00d1f044,cVar1 == '\0');

    }

    puVar5 = &DAT_00d0e128;

    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar5 = 0;

      puVar5 = puVar5 + 1;

    }

    puVar5 = &DAT_00d0e0e8;

    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar5 = 0;

      puVar5 = puVar5 + 1;

    }

    DAT_00d1a558 = 0;

    DAT_00d1a55c = 0;

  }

  return 0;

}
