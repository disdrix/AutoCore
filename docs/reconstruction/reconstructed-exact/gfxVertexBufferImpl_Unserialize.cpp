// =============================================================================
// gfxVertexBufferImpl_Unserialize
// -----------------------------------------------------------------------------
// Purpose:  Read VERT ("TREV") v1-v3. v3 path: id/stride/count + DECL + data.
//           Common strides: 32 pos+n+uv; 56 +tangents; 24 pos+n (shadow).
//
// Address:  0x0099aa20  (autoassault.exe, image base 0x400000)
// Stable:   aa_0099aa20
// System:   graphics / gfx (asset I/O)
// =============================================================================

int gfxVertexBufferImpl_Unserialize(int param_1,int param_2,int param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ uVar2;

  int *piVar3;

  int *piVar4;

  char cVar5;

  int iVar6;

  int iVar7;

  uint32_t /* width from decompiler */ uVar8;

  int iVar9;

  int extraout_EDX;

  int local_58;

  int local_54;

  uint8_t local_50 [4];

  int local_4c;

  int local_48;

  uint32_t /* width from decompiler */ local_44;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_3c;

  char local_30;

  int local_2c;

  int local_28;

  uint8_t local_24 [4];

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar6 = param_2;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b2396;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  stoChunkReader_EnterChunkScope(param_2);

  local_4 = 0;

  if (local_2c != 0x56455254) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxVertexBufferImpl.cpp",0x32b,3,

                   "Invalid TAG unserializing gfxVertexBufferImpl");

    local_4 = 0xffffffff;

    if (local_30 != '\0') {

      FUN_00769e40();

    }

    ExceptionList = local_c;

    return -1;

  }

  cVar5 = FUN_00767120();

  iVar9 = param_1;

  if (cVar5 != '\0') {

    local_4 = 0xffffffff;

    if (local_30 != '\0') {

      FUN_00769e40();

    }

    ExceptionList = local_c;

    return 0;

  }

  if (local_28 == 1) {

    local_4c = 0;

    local_48 = 0;

    local_44 = 0;

    local_40 = 0;

    local_3c = 0;

    local_4._0_1_ = 1;

    iVar6 = FUN_00747d30(local_50);

    if (-1 < iVar6) {

      uVar8 = FUN_0044bb60();

      iVar9 = FUN_00439a00();

      iVar6 = param_1;

      if (-1 < iVar9) {

        iVar7 = FUN_0099a8e0(param_3,local_50,uVar8,0);

        if (iVar7 < 0) goto LAB_0099ad41;

        piVar3 = *(int **)(iVar6 + 0x10);

        if (piVar3 == (int *)0x0) {

          param_3 = 0;

        }

        else {

          piVar4 = (int *)*piVar3;

          param_3 = *(int *)(iVar6 + 0x18);

          if (piVar4 == (int *)0x0) {

            param_3 = 0;

          }

          else {

            iVar9 = (**(code **)(*piVar4 + 0x2c))

                              (piVar4,piVar3[2] * *(int *)(iVar6 + 0x14),piVar3[2] * param_3,

                               &local_58,0x800);

            if (iVar9 < 0) {

              param_3 = 0;

            }

            else {

              piVar3[4] = piVar3[4] + 1;

              param_3 = local_58;

            }

          }

        }

        if ((param_3 != 0) && (local_54 = local_48 + -8, iVar9 = local_4c, local_4c != local_54)) {

          do {

            iVar7 = *(int *)(iVar6 + 0x18);

            switch(*(uint8_t *)(iVar9 + 6)) {

            case 0:

            case 1:

            case 3:

            case 4:

            case 5:

            case 6:

              FUN_007467b0();

              iVar7 = extraout_EDX;

              iVar6 = param_1;

              if (-1 < extraout_EDX + -1) {

                do {

                  stoChunkReader_readF32Array(param_2);

                  iVar7 = iVar7 + -1;

                  iVar6 = param_1;

                } while (iVar7 != 0);

              }

              break;

            case 2:

            case 10:

              if (-1 < iVar7 + -1) {

                do {

                  FUN_00436900();

                  iVar7 = iVar7 + -1;

                  iVar6 = param_1;

                } while (iVar7 != 0);

              }

            }

            iVar9 = iVar9 + 8;

          } while (iVar9 != local_54);

        }

        FUN_00414aa0();

        if (-1 < *(int *)(param_2 + 0x402c)) goto LAB_0099aea4;

      }

    }

  }

  else {

    if (local_28 != 2) {

      if (local_28 != 3) {

        vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxVertexBufferImpl.cpp",

                       0x3cc,3,"Invalid chunk version unserializing gfxVertexBufferImpl");

        goto LAB_0099acf0;

      }

      puVar1 = (uint32_t /* width from decompiler */ *)(param_1 + 8);

      cVar5 = FUN_00734690();

      if (cVar5 == '\0') goto LAB_0099acf0;

      uVar8 = *(uint32_t /* width from decompiler */ *)(iVar9 + 0xc);

      uVar2 = *puVar1;

      iVar6 = FUN_0044c370(uVar2,uVar8);

      if (iVar6 != 0) {

        local_4 = 0xffffffff;

        if (local_30 != '\0') {

          FUN_00769e40();

        }

        ExceptionList = local_c;

        return -2;

      }

      FUN_0044c340(uVar2,uVar8);

      iVar6 = param_2;

    }

    local_20 = 0;

    local_1c = 0;

    local_18 = 0;

    local_14 = 0;

    local_10 = 0;

    local_4._0_1_ = 2;

    iVar7 = FUN_00747d30(local_24);

    if (-1 < iVar7) {

      uVar8 = FUN_0044bb60();

      iVar7 = FUN_00439a00();

      if (-1 < iVar7) {

        iVar7 = FUN_0099a8e0(param_1,local_24,uVar8,0);

        if (iVar7 < 0) {

LAB_0099ad41:

          FUN_00414b60();

          local_4 = 0xffffffff;

          if (local_30 != '\0') {

            FUN_00769e40();

          }

          ExceptionList = local_c;

          return iVar7;

        }

        local_4c = 0;

        local_48 = 0;

        local_44 = 0;

        local_4._0_1_ = 3;

        FUN_00746d40(local_24);

        piVar3 = *(int **)(iVar9 + 0x10);

        if (piVar3 != (int *)0x0) {

          param_1 = *(int *)(iVar9 + 0x18);

          piVar4 = (int *)*piVar3;

          if (((piVar4 != (int *)0x0) &&

              (iVar7 = (**(code **)(*piVar4 + 0x2c))

                                 (piVar4,piVar3[2] * *(int *)(iVar9 + 0x14),piVar3[2] * param_1,

                                  &param_1,0x800), -1 < iVar7)) &&

             (piVar3[4] = piVar3[4] + 1, param_1 != 0)) {

            FUN_00769990(local_4c,*(uint32_t /* width from decompiler */ *)(iVar9 + 0x18));

          }

        }

        FUN_00414aa0();

        if (-1 < *(int *)(iVar6 + 0x402c)) {

          FUN_00405ef0();

LAB_0099aea4:

          FUN_00414b60();

          local_4 = 0xffffffff;

          if (local_30 != '\0') {

            FUN_00769e40();

          }

          ExceptionList = local_c;

          return 0;

        }

        FUN_00405ef0();

      }

    }

  }

  FUN_00414b60();

LAB_0099acf0:

  local_4 = 0xffffffff;

  if (local_30 != '\0') {

    FUN_00769e40();

  }

  ExceptionList = local_c;

  return -1;

}
