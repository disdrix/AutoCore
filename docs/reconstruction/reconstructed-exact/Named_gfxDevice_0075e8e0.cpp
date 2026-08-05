// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×6, return×2.
//  - Notable callees: DrawPrimitive, FUN_006a5dac, FUN_006b7a5a, FUN_0075e8e0, FUN_0076cec0, vog_LogMessage.
//  - Strings: "DrawPrimitive() failed"; "%s - %s\r\n%s"; "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDevice.cpp".
//  - Return sites: 2.

// =============================================================================
// Named_gfxDevice_0075e8e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0075e8e0
// Address:   0x0075e8e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxDevice"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_gfxDevice_0075e8e0(uint32_t /* width from decompiler */ *param_1,int param_2,int param_3,int param_4)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  

  if (DAT_00afe010 != 0) {

    (**(code **)(**(int **)(DAT_00afe010 + 0xc) + 0x104))(*(int **)(DAT_00afe010 + 0xc));

  }

  if (DAT_00afe034 != 0) {

    (**(code **)(**(int **)(DAT_00afe034 + 0xc) + 0x104))(*(int **)(DAT_00afe034 + 0xc));

  }

  iVar3 = (**(code **)(*(int *)*param_1 + 0x144))

                    ((int *)*param_1,param_2,DAT_00d1a558 + param_3,param_4);

  iVar2 = DAT_00d1f614;

  if (-1 < iVar3) {

    if (DAT_00d1f614 != 0) {

      piVar1 = (int *)(DAT_00d1f614 + 0x10c + *(int *)(DAT_00d1f614 + 0xc4) * 0x4c);

      *piVar1 = *piVar1 + 1;

      piVar1 = (int *)(iVar2 + 0x100 + *(int *)(iVar2 + 0xc4) * 0x4c);

      *piVar1 = *piVar1 + param_4;

    }

    iVar3 = param_4 * 3;

    if (param_2 != 4) {

      iVar3 = param_4 * 2;

    }

    if (iVar2 != 0) {

      piVar1 = (int *)(iVar2 + 0x104 + *(int *)(iVar2 + 0xc4) * 0x4c);

      *piVar1 = *piVar1 + iVar3;

    }

    return 0;

  }

  uVar4 = FUN_006b7a5a(iVar3,"DrawPrimitive() failed");

  uVar4 = FUN_006a5dac(iVar3,uVar4);

  uVar4 = FUN_0076cec0(&stack0xfffffff4,"%s - %s\r\n%s",uVar4);

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDevice.cpp",0x2d2,3,uVar4);

  return 0xffffffff;

}
