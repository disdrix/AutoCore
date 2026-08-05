// READABILITY (auto CF):
//  - Body size: ~247 non-empty decompiler lines.
//  - Control keywords: if×44, goto×7, return×6, for×4.
//  - Notable callees: vog_LogMessage×8, FUN_006a5dac×5, FUN_006b7a5a×5, FUN_0076cec0×5, FUN_0096c730×3, FUN_0043b800, FUN_0096c8e0, FUN_0096cad0.
//  - Strings: ",

                       0x2ad,2,

                       "; ",

                     0x2b3,2,

                     "; ",

                   0x2c6,1,

                   "; ";

        uVar3 = 0x2e3;

      }

      vog_LogMessage(".
//  - Return sites: 6.

// =============================================================================
// Named_effTextureImpl_0096cad0
// -----------------------------------------------------------------------------
// Stable ID: aa_0096cad0
// Address:   0x0096cad0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "effTextureImpl"
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

Named_effTextureImpl_0096cad0(uint param_1,int param_2,uint param_3,uint param_4,uint32_t /* width from decompiler */ param_5,

            uint32_t /* width from decompiler */ *param_6)



{

  int *piVar1;

  uint in_EAX;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  uint uVar5;

  uint uVar6;

  uint32_t /* width from decompiler */ uVar7;

  char *pcVar8;

  uint local_4;

  

  local_4 = param_1;

  FUN_0096c8e0();

  if ((in_EAX & 0x4000) == 0) {

    if (param_3 == 0) {

      param_3 = 1;

LAB_0096cb0a:

      if ((in_EAX & 0x10) == 0) {

        vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effTextureImpl.cpp",

                       0x2ad,2,

                       "Texture Width must be power of 2, setting width to the next Pow2 value");

      }

    }

    else if ((param_3 & param_3 - 1) != 0) {

      iVar2 = 0x1f;

      if (param_3 != 0) {

        for (; param_3 >> iVar2 == 0; iVar2 = iVar2 + -1) {

        }

      }

      param_3 = 2 << ((byte)iVar2 & 0x1f);

      goto LAB_0096cb0a;

    }

    if (param_4 == 0) {

      param_4 = 1;

    }

    else {

      if ((param_4 & param_4 - 1) == 0) goto LAB_0096cb71;

      iVar2 = 0x1f;

      if (param_4 != 0) {

        for (; param_4 >> iVar2 == 0; iVar2 = iVar2 + -1) {

        }

      }

      param_4 = 2 << ((byte)iVar2 & 0x1f);

    }

    if ((in_EAX & 0x10) == 0) {

      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effTextureImpl.cpp",

                     0x2b3,2,

                     "Texture Height must be power of 2, setting Height to the next Pow2 value");

    }

  }

LAB_0096cb71:

  piVar1 = (int *)*DAT_00d1f044;

  uVar5 = in_EAX & 0xffffcfff;

  uVar6 = (in_EAX & 0x80) * 4 | uVar5 >> 4 & 1;

  if ((param_6 == (uint32_t /* width from decompiler */ *)0x0) && ((in_EAX & 0x80) == 0)) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effTextureImpl.cpp",

                   0x2c6,1,

                   "POOL_DEFAULT Texture created, evicting managed resources prior to allocation!");

    (**(code **)(*piVar1 + 0x14))(piVar1);

  }

  local_4 = in_EAX & 0xf;

  if (local_4 == 1) {

    iVar2 = (**(code **)(*piVar1 + 0x5c))

                      (piVar1,param_3,param_4,~(uVar5 >> 8) & 1,uVar6,param_2,param_6,param_1 + 0x10

                       ,0);

    if (iVar2 < 0) {

      if (iVar2 == -0x7ff8fff2) {

        pcVar8 = "Direct3D could not allocate sufficient memory to complete the call.";

        uVar3 = 0x2e2;

      }

      else if (iVar2 == -0x7789fe84) {

        pcVar8 = "Direct3D does not have enough display memory to perform the operation.";

        uVar3 = 0x2e1;

      }

      else if (iVar2 == -0x7789f794) {

        pcVar8 = 

        "The method call is invalid. For example, a method\'s parameter may have an invalid value.";

        uVar3 = 0x2e0;

      }

      else {

        pcVar8 = "Direct3D unknown error calling IDirect3DDevice9::CreateTexture Method.";

        uVar3 = 0x2e3;

      }

      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effTextureImpl.cpp",

                     uVar3,1,pcVar8);

      uVar3 = FUN_006b7a5a(iVar2,"Failed CreateTexture. <see error report>");

      uVar3 = FUN_006a5dac(iVar2,uVar3);

      uVar3 = FUN_0076cec0(&local_4,"%s - %s\r\n%s",uVar3);

      uVar7 = 0x2e5;

      goto LAB_0096cee8;

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = 1;

  }

  else if (local_4 == 2) {

    if (param_4 != param_3) {

      param_3 = param_4;

      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effTextureImpl.cpp",

                     0x2f1,2,"Cube textures must be square, using size.cy only");

    }

    iVar2 = (**(code **)(*piVar1 + 100))

                      (piVar1,param_3,~(uVar5 >> 8) & 1,uVar6,param_2,param_6,param_1 + 0x10,0);

    if (iVar2 < 0) {

      uVar3 = FUN_006b7a5a(iVar2,"Failed CreateCubeTexture.");

      uVar3 = FUN_006a5dac(iVar2,uVar3);

      uVar3 = FUN_0076cec0(&local_4,"%s - %s\r\n%s",uVar3);

      uVar7 = 0x2fc;

      goto LAB_0096cee8;

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = 6;

  }

  else if (local_4 == 4) {

    iVar2 = (**(code **)(*piVar1 + 0x60))

                      (piVar1,param_3,param_4,param_5,~(uVar5 >> 8) & 1,uVar6,param_2,param_6,

                       param_1 + 0x10,0);

    if (iVar2 < 0) {

      uVar3 = FUN_006b7a5a(iVar2,"Failed CreateVolumeTexture.");

      uVar3 = FUN_006a5dac(iVar2,uVar3);

      uVar3 = FUN_0076cec0(&local_4,"%s - %s\r\n%s",uVar3);

      uVar7 = 0x310;

      goto LAB_0096cee8;

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = param_5;

  }

  if ((in_EAX & 0x10) == 0) goto LAB_0096cf03;

  if (local_4 == 2) {

    pcVar8 = "Rendering to Cube Textures not supported at this time.";

    uVar3 = 800;

LAB_0096cdf1:

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effTextureImpl.cpp",

                   uVar3,3,pcVar8);

  }

  else if (local_4 == 4) {

    pcVar8 = "Rendering to Volume Textures not supported at this time.";

    uVar3 = 0x323;

    goto LAB_0096cdf1;

  }

  iVar2 = (**(code **)(**(int **)(param_1 + 0x10) + 0x48))

                    (*(int **)(param_1 + 0x10),0,param_1 + 0x14);

  if (iVar2 < 0) {

    uVar3 = FUN_006b7a5a(iVar2,"Failed to create a render target surface for a rendable texture.");

    uVar3 = FUN_006a5dac(iVar2,uVar3);

    uVar3 = FUN_0076cec0(&param_2,"%s - %s\r\n%s",uVar3);

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effTextureImpl.cpp",

                   0x32a,3,uVar3);

  }

  if ((in_EAX & 0x20) != 0) {

    if (*(char *)((int)DAT_00d1f044 + 0x775) == '\0') {

      uVar5 = in_EAX & 0xffffcfbf;

    }

    else {

      uVar5 = uVar5 | 0x40;

    }

    if ((param_2 == 0x16) || (param_2 == 0x15)) {

      iVar2 = (-(uint)((uVar5 & 0x40) != 0) & 0xfffffffe) + 0x4d;

    }

    else {

      iVar2 = (-(uint)((uVar5 & 0x40) != 0) & 0xfffffff9) + 0x50;

    }

    iVar4 = (**(code **)(*piVar1 + 0x74))(piVar1,param_3,param_4,iVar2,0,0,1,param_1 + 0x18,0);

    if (iVar4 < 0) {

      uVar3 = FUN_006b7a5a(iVar4,"Failed to create a DepthStencil surface for a renderable texture."

                          );

      uVar3 = FUN_006a5dac(iVar4,uVar3);

      uVar3 = FUN_0076cec0(&local_4,"%s - %s\r\n%s",uVar3);

      uVar7 = 0x34b;

LAB_0096cee8:

      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effTextureImpl.cpp",

                     uVar7,3,uVar3);

      return 0xffffffff;

    }

    *(int *)(param_1 + 0x28) = iVar2;

  }

LAB_0096cf03:

  *(uint *)(param_1 + 0x1c) = param_3;

  *(uint *)(param_1 + 0x20) = param_4;

  *(uint32_t /* width from decompiler */ **)(param_1 + 0x30) = param_6;

  *(int *)(param_1 + 0x24) = param_2;

  *(uint *)(param_1 + 0x2c) = uVar5;

  uVar3 = (**(code **)(**(int **)(param_1 + 0x10) + 0x34))(*(int **)(param_1 + 0x10));

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = uVar3;

  *(uint32_t /* width from decompiler */ **)(param_1 + 0xc) = param_6;

  if ((param_6 != (uint32_t /* width from decompiler */ *)0x0) && (iVar2 = (**(code **)*param_6)(param_1), iVar2 != 0)) {

    return 0xffffffff;

  }

  if (*(int *)(param_1 + 0x14) == 0) {

    uVar5 = uVar5 & 0xf;

    if (uVar5 == 1) {

      if (DAT_00d1f614 != 0) {

        *(int *)(DAT_00d1f614 + 0x350) = *(int *)(DAT_00d1f614 + 0x350) + 1;

      }

      iVar2 = FUN_0096c730();

      if (DAT_00d1f614 != 0) {

        *(int *)(DAT_00d1f614 + 0x398) = *(int *)(DAT_00d1f614 + 0x398) + iVar2;

      }

    }

    else {

      if (uVar5 == 2) {

        if (DAT_00d1f614 != 0) {

          *(int *)(DAT_00d1f614 + 0x358) = *(int *)(DAT_00d1f614 + 0x358) + 1;

        }

      }

      else {

        if (uVar5 != 4) {

          return 0;

        }

        if (DAT_00d1f614 != 0) {

          *(int *)(DAT_00d1f614 + 0x360) = *(int *)(DAT_00d1f614 + 0x360) + 1;

        }

      }

      iVar2 = FUN_0096c730();

      if (DAT_00d1f614 != 0) {

        *(int *)(DAT_00d1f614 + 0x3a0) = *(int *)(DAT_00d1f614 + 0x3a0) + iVar2;

        return 0;

      }

    }

  }

  else {

    if (DAT_00d1f614 != 0) {

      *(int *)(DAT_00d1f614 + 0x364) = *(int *)(DAT_00d1f614 + 0x364) + 1;

    }

    iVar4 = FUN_0096c730();

    iVar2 = DAT_00d1f614;

    if (DAT_00d1f614 != 0) {

      *(int *)(DAT_00d1f614 + 0x3ac) = *(int *)(DAT_00d1f614 + 0x3ac) + iVar4;

    }

    if (*(int *)(param_1 + 0x18) != 0) {

      if (iVar2 != 0) {

        *(int *)(iVar2 + 0x368) = *(int *)(iVar2 + 0x368) + 1;

      }

      if (*(int *)(param_1 + 0x18) == 0) {

        iVar4 = 0;

      }

      else {

        uVar5 = FUN_0043b800();

        iVar4 = (uVar5 >> 3) * *(int *)(param_1 + 0x20) * *(int *)(param_1 + 0x1c);

      }

      if (iVar2 != 0) {

        *(int *)(iVar2 + 0x3b0) = *(int *)(iVar2 + 0x3b0) + iVar4;

        return 0;

      }

    }

  }

  return 0;

}
