// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×9, return×2.
//  - Notable callees: DrawIndexedPrimitive, FUN_006a5dac, FUN_006b7a5a, FUN_0075e9f0, FUN_0076cec0, vog_LogMessage.
//  - Strings: "DrawIndexedPrimitive() failed"; "%s - %s\r\n%s"; "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDevice.cpp".
//  - Return sites: 2.

// =============================================================================
// Named_gfxDevice_0075e9f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0075e9f0
// Address:   0x0075e9f0  (autoassault.exe, image base 0x400000)
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

uint32_t /* width from decompiler */ __thiscall

Named_gfxDevice_0075e9f0(uint32_t /* width from decompiler */ *param_1,int param_2,int param_3,int param_4,uint32_t /* width from decompiler */ param_5,int param_6)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  

  if (DAT_00afe010 != 0) {

    (**(code **)(**(int **)(DAT_00afe010 + 0xc) + 0x104))(*(int **)(DAT_00afe010 + 0xc));

  }

  if (DAT_00afe034 != 0) {

    (**(code **)(**(int **)(DAT_00afe034 + 0xc) + 0x104))(*(int **)(DAT_00afe034 + 0xc));

  }

  iVar4 = param_6;

  if (param_6 == 0) {

    iVar4 = DAT_00d1a55c;

  }

  iVar2 = (**(code **)(*(int *)*param_1 + 0x148))

                    ((int *)*param_1,param_2,DAT_00d1a558,param_5,iVar4,DAT_00d1a568 + param_3,

                     param_4);

  iVar4 = DAT_00d1f614;

  if (-1 < iVar2) {

    if (DAT_00d1f614 != 0) {

      piVar1 = (int *)(DAT_00d1f614 + 0x10c + *(int *)(DAT_00d1f614 + 0xc4) * 0x4c);

      *piVar1 = *piVar1 + 1;

      piVar1 = (int *)(iVar4 + 0x100 + *(int *)(iVar4 + 0xc4) * 0x4c);

      *piVar1 = *piVar1 + param_4;

    }

    if (param_6 == 0) {

      param_6 = DAT_00d1a55c;

    }

    if (iVar4 != 0) {

      piVar1 = (int *)(iVar4 + 0x104 + *(int *)(iVar4 + 0xc4) * 0x4c);

      *piVar1 = *piVar1 + param_6;

    }

    iVar2 = param_4 * 3;

    if (param_2 != 4) {

      iVar2 = param_4 * 2;

    }

    if (iVar4 != 0) {

      piVar1 = (int *)(iVar4 + 0x108 + *(int *)(iVar4 + 0xc4) * 0x4c);

      *piVar1 = *piVar1 + iVar2;

    }

    return 0;

  }

  uVar3 = FUN_006b7a5a(iVar2,"DrawIndexedPrimitive() failed");

  uVar3 = FUN_006a5dac(iVar2,uVar3);

  uVar3 = FUN_0076cec0(&stack0xfffffff0,"%s - %s\r\n%s",uVar3);

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDevice.cpp",700,3,uVar3);

  return 0xffffffff;

}
