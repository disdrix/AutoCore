// =============================================================================
// gfxIndexBufferImpl_Unserialize
// -----------------------------------------------------------------------------
// Purpose:  Read INDX ("XDNI") v1-v2 into gfxIndexBufferImpl.
//           v1: u32 count + u16 data. v2: id + indexSize + count + count2 + data.
//
// Address:  0x00989030  (autoassault.exe, image base 0x400000)
// Stable:   aa_00989030
// System:   graphics / gfx (asset I/O)
// =============================================================================

uint32_t /* width from decompiler */ gfxIndexBufferImpl_Unserialize(int param_1,int param_2,int *param_3)



{

  int *piVar1;

  int *piVar2;

  char cVar3;

  int iVar4;

  int iVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  char local_18;

  int local_14;

  int local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar4 = param_2;

  iVar5 = param_1;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b235a;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  stoChunkReader_EnterChunkScope(param_2);

  local_4 = 0;

  if (local_14 != 0x494e4458) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxIndexBufferImpl.cpp",0x136,3,

                   "Invalid TAG unserializing gfxIndexBufferImpl");

    local_4 = 0xffffffff;

    if (local_18 != '\0') {

      FUN_00769e40();

    }

    ExceptionList = local_c;

    return 0xffffffff;

  }

  if (local_10 != 1) {

    if (local_10 == 2) {

      cVar3 = FUN_00734690();

      if (cVar3 != '\0') {

        uVar6 = *(uint32_t /* width from decompiler */ *)(iVar5 + 0xc);

        uVar7 = *(uint32_t /* width from decompiler */ *)(iVar5 + 8);

        iVar4 = FUN_0044c370(uVar7,uVar6);

        if (iVar4 != 0) {

          local_4 = 0xffffffff;

          if (local_18 != '\0') {

            FUN_00769e40();

          }

          ExceptionList = local_c;

          return 0xfffffffe;

        }

        FUN_0044c340(uVar7,uVar6);

        iVar4 = param_2;

        goto LAB_0098917d;

      }

    }

    else {

      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxIndexBufferImpl.cpp",0x164,3

                     ,"Invalid chunk version unserializing gfxIndexBufferImpl");

    }

    local_4 = 0xffffffff;

    if (local_18 != '\0') {

      FUN_00769e40();

    }

    ExceptionList = local_c;

    return 0xffffffff;

  }

LAB_0098917d:

  if (*(int *)(iVar4 + 0x4044) == 0) {

    FUN_00437050(&param_1);

  }

  else {

    FUN_00768760(&param_1);

  }

  uVar6 = 0x20;

  if ((*(int *)(*param_3 + 0x14) != 0) && (*(char *)(*(int *)(*param_3 + 0x14) + 0x10) != '\0')) {

    uVar6 = 0x18;

  }

  uVar7 = 0xffffffff;

  FUN_00988f20(param_1,uVar6,0,0);

  piVar1 = *(int **)(iVar5 + 0x10);

  if (piVar1 != (int *)0x0) {

    param_3 = *(int **)(iVar5 + 0x1c);

    piVar2 = (int *)*piVar1;

    if (piVar2 != (int *)0x0) {

      iVar5 = (**(code **)(*piVar2 + 0x2c))

                        (piVar2,piVar1[4] * *(int *)(iVar5 + 0x18),piVar1[4] * (int)param_3,&param_3

                         ,0x800);

      if ((iVar5 < 0) || (piVar1[3] = piVar1[3] + 1, param_3 == (int *)0x0)) {

        uVar7 = 0xffffffff;

      }

      else {

        uVar7 = FUN_0044ed70();

      }

    }

  }

  FUN_0044b8b0();

  local_4 = 0xffffffff;

  if (local_18 != '\0') {

    FUN_00769e40();

  }

  ExceptionList = local_c;

  return uVar7;

}
