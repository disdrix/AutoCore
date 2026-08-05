// READABILITY (auto CF):
//  - Body size: ~263 non-empty decompiler lines.
//  - Control keywords: if×31, return×7, for×6, goto×5, do×1, while×1.
//  - Notable callees: Reset×10, FUN_0076c130×5, vog_LogMessage×5, FUN_0040ead0×2, FUN_0043b800×2, FUN_006a5dac×2, FUN_006b7a5a×2, FUN_0075e710×2.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDevice.cpp"; "Beginning shutdown for Device Reset()"; "Failed to Reset() device on IB Factory"; "Failed to Reset() device on VB Factory".
//  - Return sites: 7.

// =============================================================================
// Named_gfxDevice_0075eff0
// -----------------------------------------------------------------------------
// Stable ID: aa_0075eff0
// Address:   0x0075eff0  (autoassault.exe, image base 0x400000)
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

uint32_t /* width from decompiler */ Named_gfxDevice_0075eff0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,byte param_3)



{

  uint32_t /* width from decompiler */ *in_EAX;

  int iVar1;

  int iVar2;

  int iVar3;

  int unaff_ESI;

  int *piVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int iVar7;

  uint32_t /* width from decompiler */ uVar8;

  int *piVar9;

  char *pcVar10;

  uint32_t /* width from decompiler */ local_38 [7];

  uint32_t /* width from decompiler */ local_1c;

  uint local_18;

  uint8_t auStack_8 [8];

  

  iVar3 = DAT_00d1f614;

  if (DAT_00d1f614 != 0) {

    *(int *)(DAT_00d1f614 + 0x364) = *(int *)(DAT_00d1f614 + 0x364) + (-1 - param_1[0xb1]);

    iVar1 = FUN_0040ead0(param_1[0xb0]);

    *(int *)(iVar3 + 0x3ac) =

         *(int *)(iVar3 + 0x3ac) -

         ((uint)(iVar1 * param_1[0xaf] * param_1[0xae] * (param_1[0xb1] + 1)) >> 3);

  }

  if ((param_1[0xb7] != 0) && (iVar3 != 0)) {

    *(int *)(iVar3 + 0x368) = *(int *)(iVar3 + 0x368) + -1;

    iVar1 = FUN_0043b800();

    *(int *)(iVar3 + 0x3b0) =

         *(int *)(iVar3 + 0x3b0) - ((uint)(iVar1 * param_1[0xaf] * param_1[0xae]) >> 3);

  }

  FUN_0075e710();

  local_38[1] = in_EAX[1];

  puVar5 = param_1 + 0xae;

  puVar6 = local_38;

  for (iVar3 = 0xe; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar6 = *puVar5;

    puVar5 = puVar5 + 1;

    puVar6 = puVar6 + 1;

  }

  local_38[0] = *in_EAX;

  local_1c = param_2;

  local_18 = (uint)param_3;

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDevice.cpp",0x1fe,1,

                 "Beginning shutdown for Device Reset()");

  FUN_00985f40();

  FUN_00985580();

  FUN_009864e0();

  FUN_009686e0();

  FUN_0073d8d0();

  iVar3 = param_1[0x1d5];

  piVar9 = *(int **)(iVar3 + 8);

  piVar4 = (int *)*piVar9;

  if (piVar4 != piVar9) {

    do {

      if (*(int *)(piVar4[2] + 0x30) == 0) {

        FUN_0096c8e0();

      }

      piVar4 = (int *)*piVar4;

    } while (piVar4 != (int *)*(int *)(iVar3 + 8));

  }

  iVar3 = param_1[0x1e7];

  piVar9 = *(int **)(iVar3 + 0x3d4);

  if (piVar9 != (int *)0x0) {

    (**(code **)(*piVar9 + 8))(piVar9);

  }

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x3d4) = 0;

  FUN_0073e980();

  FUN_0074f0c0();

  piVar9 = (int *)param_1[2];

  if (piVar9 != (int *)0x0) {

    (**(code **)(*piVar9 + 8))(piVar9);

  }

  param_1[2] = 0;

  piVar9 = (int *)param_1[3];

  if (piVar9 != (int *)0x0) {

    (**(code **)(*piVar9 + 8))(piVar9);

  }

  param_1[3] = 0;

  iVar3 = (**(code **)(*(int *)*param_1 + 0x40))((int *)*param_1,local_38);

  if (-1 < iVar3) {

    (**(code **)(*(int *)*param_1 + 0x14))((int *)*param_1);

    iVar3 = FUN_00985610();

    if (iVar3 < 0) {

      pcVar10 = "Failed to Reset() device on IB Factory";

      uVar8 = 0x236;

    }

    else {

      iVar3 = FUN_00986570();

      if (iVar3 < 0) {

        pcVar10 = "Failed to Reset() device on VB Factory";

        uVar8 = 0x239;

      }

      else {

        iVar3 = FUN_0096e8e0(param_1[0x1d5]);

        if (iVar3 < 0) {

          pcVar10 = "Failed to Reset() device on Texture Factory";

          uVar8 = 0x23c;

        }

        else {

          iVar3 = FUN_00968720();

          if (iVar3 < 0) {

            pcVar10 = "Failed to Reset() device on gfxBufferedViews";

            uVar8 = 0x23f;

          }

          else {

            iVar3 = FUN_0073d870();

            if (iVar3 < 0) {

              pcVar10 = "Failed to Reset() device on Effect Factory";

              uVar8 = 0x242;

            }

            else {

              iVar3 = FUN_00966760();

              if (iVar3 < 0) {

                pcVar10 = "Failed to Reset() device on Stats Monitor";

                uVar8 = 0x245;

              }

              else {

                iVar3 = FUN_0074f090();

                if (-1 < iVar3) {

                  FUN_00968680();

                  FUN_0073be50();

                  puVar5 = (uint32_t /* width from decompiler */ *)&stack0xffffffbc;

                  puVar6 = param_1 + 0xae;

                  for (iVar3 = 0xe; iVar3 != 0; iVar3 = iVar3 + -1) {

                    *puVar6 = *puVar5;

                    puVar5 = puVar5 + 1;

                    puVar6 = puVar6 + 1;

                  }

                  FUN_0075e710();

                  piVar9 = (int *)*param_1;

                  iVar3 = (**(code **)(*piVar9 + 0x1c))(piVar9,param_1 + 5);

                  if (iVar3 < 0) {

                    uVar8 = FUN_006b7a5a(iVar3,"Failed GetDeviceCaps for hardware.");

                    uVar8 = FUN_006a5dac(iVar3,uVar8);

                    uVar8 = FUN_0076cec0(auStack_8,"%s - %s\r\n%s",uVar8);

                    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDevice.cpp",

                                   0x256,3,uVar8);

                  }

                  if (param_1[0x1df] == 0) {

                    puVar5 = param_1 + 5;

                    puVar6 = param_1 + 0x51;

                    for (iVar3 = 0x4c; iVar3 != 0; iVar3 = iVar3 + -1) {

                      *puVar6 = *puVar5;

                      puVar5 = puVar5 + 1;

                      puVar6 = puVar6 + 1;

                    }

                  }

                  else {

                    (**(code **)(*(int *)*param_1 + 0x134))((int *)*param_1,1);

                    iVar3 = (**(code **)(*(int *)*param_1 + 0x1c))((int *)*param_1,param_1 + 0x51);

                    if (iVar3 < 0) {

                      uVar8 = FUN_006b7a5a(iVar3,"Failed GetDeviceCaps for software.");

                      uVar8 = FUN_006a5dac(iVar3,uVar8);

                      uVar8 = FUN_0076cec0(auStack_8,"%s - %s\r\n%s",uVar8);

                      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDevice.cpp",

                                     0x25d,3,uVar8);

                    }

                    if (param_1[0x1df] == 1) {

                      (**(code **)(*(int *)*param_1 + 0x134))((int *)*param_1,0);

                    }

                  }

                  iVar7 = 0;

                  iVar1 = 0;

                  (**(code **)(*(int *)*param_1 + 0x48))((int *)*param_1,0,0,0,param_1 + 2);

                  (**(code **)(*(int *)*param_1 + 0xa0))((int *)*param_1,param_1 + 3);

                  param_1[4] = param_1[0xb8];

                  FUN_00966630();

                  *DAT_00d1f048 = param_1[2];

                  DAT_00d1f048[1] = param_1[3];

                  DAT_00d1f048[2] = param_1[4];

                  iVar3 = DAT_00d1f610;

                  *(uint32_t /* width from decompiler */ *)(DAT_00d1f610 + 0xc) = 0;

                  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x10) = 0xffffffff;

                  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x14) = 0xffffffff;

                  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDevice.cpp",

                                 0x270,1,"Device Reset() complete");

                  iVar3 = DAT_00d1f614;

                  if (DAT_00d1f614 != 0) {

                    *(int *)(DAT_00d1f614 + 0x364) =

                         (int)piVar9 + *(int *)(DAT_00d1f614 + 0x364) + 1;

                    iVar2 = FUN_0040ead0(param_1[0xb0]);

                    *(int *)(iVar3 + 0x3ac) =

                         *(int *)(iVar3 + 0x3ac) +

                         ((uint)(iVar2 * ((int)piVar9 + 1) * iVar7 * iVar1) >> 3);

                  }

                  if ((unaff_ESI != 0) && (iVar3 != 0)) {

                    *(int *)(iVar3 + 0x368) = *(int *)(iVar3 + 0x368) + 1;

                    iVar2 = FUN_0043b800();

                    *(int *)(iVar3 + 0x3b0) =

                         *(int *)(iVar3 + 0x3b0) + ((uint)(iVar2 * iVar7 * iVar1) >> 3);

                  }

                  param_1[0x1e9] = 0;

                  return 0;

                }

                pcVar10 = "Failed to Reset() device on Global Effect";

                uVar8 = 0x248;

              }

            }

          }

        }

      }

    }

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDevice.cpp",uVar8,3,pcVar10);

    return 0xffffffff;

  }

  if (iVar3 < -0x7789f7d8) {

    if (iVar3 == -0x7789f7d9) {

      pcVar10 = 

      "ERROR: Internal driver error. Applications should generally shut down when receiving this error. For more information, see Driver Internal Errors."

      ;

      goto LAB_0075f1db;

    }

    if (iVar3 == -0x7ff8fff2) {

      pcVar10 = "ERROR: Direct3D could not allocate sufficient memory to complete the call.";

      goto LAB_0075f1db;

    }

    if (iVar3 == -0x7789fe84) {

      pcVar10 = "ERROR: Direct3D does not have enough display memory to perform the operation. \n";

      goto LAB_0075f1db;

    }

  }

  else {

    if (iVar3 == -0x7789f798) {

      pcVar10 = 

      "ERROR: The device has been lost but cannot be reset at this time. Therefore, rendering is not possible. \n"

      ;

      goto LAB_0075f1db;

    }

    if (iVar3 == -0x7789f794) {

      pcVar10 = 

      "ERROR: The method call pd3dDevice->Reset() is invalid. For example, a method\'s parameter may have an invalid value. \n"

      ;

      goto LAB_0075f1db;

    }

  }

  pcVar10 = "ERROR: <UNKNOWN> from IDirect3DDevice9::Reset()\n";

LAB_0075f1db:

  FUN_0076c130(pcVar10);

  iVar3 = (**(code **)(*(int *)*param_1 + 0xc))((int *)*param_1);

  if (-1 < iVar3) {

    return 0xffffffff;

  }

  if (iVar3 == -0x7789f7d9) {

    FUN_0076c130(

                "Internal driver error. Applications should generally shut down when receiving this error. For more information, see Driver Internal Errors.\n"

                );

    return 0xffffffff;

  }

  if (iVar3 == -0x7789f798) {

    FUN_0076c130(

                "The device has been lost but cannot be reset at this time. Therefore, rendering is not possible\n"

                );

    return 0xffffffff;

  }

  if (iVar3 != -0x7789f797) {

    FUN_0076c130("<UNKNOWN> from IDirect3DDevice9::TestCooperativeLevel()\n");

    return 0xffffffff;

  }

  FUN_0076c130("The device has been lost but can be reset at this time.\n");

  return 0xffffffff;

}
