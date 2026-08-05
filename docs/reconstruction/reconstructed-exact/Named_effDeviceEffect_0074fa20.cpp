// READABILITY (auto CF):
//  - Body size: ~71 non-empty decompiler lines.
//  - Control keywords: if×7, return×4.
//  - Notable callees: CONCAT11, D3DXCreateEffect, FUN_00445bc0, FUN_00691630, FUN_0074fa20, FUN_0076cec0, vog_LogMessage.
//  - Return sites: 4.

// =============================================================================
// Named_effDeviceEffect_0074fa20
// -----------------------------------------------------------------------------
// Stable ID: aa_0074fa20
// Address:   0x0074fa20  (autoassault.exe, image base 0x400000)
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

uint32_t /* width from decompiler */ __thiscall Named_effDeviceEffect_0074fa20(int *param_1,int param_2,int param_3)



{

  void *pvVar1;

  char cVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  int *piStack_28;

  uint local_24;

  undefined **appuStack_20 [2];

  void *local_18;

  int local_14;

  uint32_t /* width from decompiler */ local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009ada05;

  pvStack_c = ExceptionList;

  local_24 = (uint)CONCAT11(1,-(*(char *)(DAT_00d1f044 + 0x1de) != '\x01') & 5);

  local_18 = (void *)0x0;

  local_14 = 0;

  local_10 = 0;

  local_4 = 0;

  ExceptionList = &pvStack_c;

  uVar3 = (**(code **)(*param_1 + 0x1c))();

  FUN_00445bc0(uVar3,0);

  cVar2 = (**(code **)(*param_1 + 0x20))();

  pvVar1 = local_18;

  if ((cVar2 != '\0') && (cVar2 = (**(code **)(*param_1 + 0x24))(), cVar2 != '\0')) {

    iVar4 = *param_1;

    uVar3 = (**(code **)(iVar4 + 0x1c))();

    iVar4 = (**(code **)(iVar4 + 0x14))(pvVar1,uVar3);

    if (-1 < iVar4) {

      appuStack_20[0] = &PTR_LAB_00a9fa84;

      piStack_28 = (int *)0x0;

      if (pvVar1 == (void *)0x0) {

        iVar4 = 0;

      }

      else {

        iVar4 = local_14 - (int)pvVar1;

      }

      iVar4 = D3DXCreateEffect(*DAT_00d1f044,pvVar1,iVar4,*(uint32_t /* width from decompiler */ *)(param_3 + 4),appuStack_20,

                               local_24,*(uint32_t /* width from decompiler */ *)(DAT_00d1f05c + 0x140),param_2 + 0xc,

                               &piStack_28);

      if (iVar4 < 0) {

        uVar3 = (**(code **)(*piStack_28 + 0xc))(piStack_28);

        uVar3 = FUN_0076cec0(&param_3,

                             "effDeviceEffect::CompileEffect falied to compile the effect, errorBuffer=%s"

                             ,uVar3);

        vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effDeviceEffect.cpp"

                       ,0x2ca,2,uVar3);

      }

      if (piStack_28 != (int *)0x0) {

        (**(code **)(*piStack_28 + 8))(piStack_28);

      }

      piStack_28 = (int *)0x0;

      FUN_00691630();

      if (iVar4 < 0) {

        ExceptionList = pvStack_c;

        return 0xffffffff;

      }

      ExceptionList = pvStack_c;

      return 0;

    }

  }

  if (pvVar1 == (void *)0x0) {

    ExceptionList = pvStack_c;

    return 0xffffffff;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(pvVar1);

}
