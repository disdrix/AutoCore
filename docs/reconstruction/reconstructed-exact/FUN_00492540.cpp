// =============================================================================
// FUN_00492540
// -----------------------------------------------------------------------------
// Stable ID: aa_00492540
// Address:   0x00492540  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00492540 @ 0x00492540
// Stable ID: aa_00492540
// Embedded strings (evidence for future rename):
//   - "gFogDensity"
//   - "gFogStart"
//   - "gFogEnd"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~300 non-empty decompiler lines.
//  - Control keywords: if×20, return×1.
//  - Notable callees: FUN_0074f1b0×5, FUN_00495970×4, FUN_004959e0×4, FUN_0076cef0×2, FUN_0076f5f0×2, FUN_0079a110×2, FUN_0079a120×2, FUN_0079a1c0×2.
//  - Strings: "gFogDensity"; "gFogStart"; "gFogEnd".
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

uint32_t /* width from decompiler */ __thiscall FUN_00492540(int param_1,float *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  float *pfVar2;

  uint32_t /* width from decompiler */ uVar3;

  int *piVar4;

  float *pfVar5;

  int iVar6;

  uint32_t /* width from decompiler */ uVar7;

  int iVar8;

  float10 fVar9;

  char *pcStack_5c;

  float *pfStack_58;

  float *pfStack_54;

  float *pfStack_50;

  float *pfStack_4c;

  float local_38;

  float fStack_24;

  float fStack_20;

  float fStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  uint32_t /* width from decompiler */ uStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a09bc;

  pvStack_c = ExceptionList;

  pfStack_4c = (float *)0x9c7904;

  pfStack_50 = (float *)0x492574;

  ExceptionList = &pvStack_c;

  FUN_0076cf00();

  local_4 = 0;

  if ((*(byte *)(*(int *)(param_1 + 0xb8) + 0xe7d4) & 1) != 0) {

    *(uint8_t *)(param_1 + 0x78) = 0;

  }

  *(uint8_t *)(DAT_00d1f048 + 0xf) = *(uint8_t *)(param_1 + 0x78);

  *(uint8_t *)(DAT_00d1f048 + 0x2d) = *(uint8_t *)(param_1 + 0x78);

  if (*(char *)(param_1 + 0x8c) != '\0') {

    DAT_00b03738 = DAT_00b03738 + 1;

    DAT_00b03514 = DAT_00b03514 + 1;

    if (((*(char *)(param_1 + 0xfc) != '\0') && (*(int *)(param_1 + 0xdc) != 0)) &&

       (*(int *)(param_1 + 0xe0) != 0)) {

      *(uint8_t *)(param_1 + 0xfc) = 0;

      pfStack_4c = (float *)0x4925ee;

      FUN_004923b0();

    }

    iVar6 = DAT_00d1f05c;

    iVar8 = *(int *)(param_1 + 0xb8);

    local_38 = g_flOne;

    if ((iVar8 != 0) && (*(int *)(iVar8 + 0xe4f8) != 0)) {

      local_38 = *(float *)(*(int *)(iVar8 + 0xe4f8) + 0x33c);

    }

    if (*(char *)(iVar8 + 0xf5) != '\0') {

      local_38 = local_38 * DAT_00a0f298;

    }

    uVar3 = *(uint32_t /* width from decompiler */ *)(*(int *)(iVar8 + 0xe898) + 0x54);

    pfStack_4c = (float *)0xa9f558;

    pfStack_50 = (float *)0x49265f;

    pfStack_54 = (float *)FUN_0074f1b0();

    pfStack_58 = *(float **)(*(int *)(iVar6 + 4) + 0xc);

    pfStack_4c = (float *)0xffffffff;

    pfStack_50 = (float *)(param_1 + 0x70);

    pcStack_5c = (char *)0x492672;

    (**(code **)((int)*pfStack_58 + 0x50))();

    pcStack_5c = "gFogDensity";

    uVar7 = FUN_0074f1b0();

    piVar4 = *(int **)(*(int *)(iVar6 + 4) + 0xc);

    pcStack_5c = (char *)0xffffffff;

    (**(code **)(*piVar4 + 0x50))(piVar4,uVar7,param_1 + 0x74);

    pfStack_50 = (float *)(*(float *)(param_1 + 0x10c) * (float)pfStack_58);

    pfStack_4c = (float *)(*(float *)(param_1 + 0x110) * (float)pfStack_58);

    uVar7 = FUN_0074f1b0("gFogStart");

    piVar4 = *(int **)(*(int *)(iVar6 + 4) + 0xc);

    (**(code **)(*piVar4 + 0x50))(piVar4,uVar7,&pfStack_50,0xffffffff);

    uVar7 = FUN_0074f1b0("gFogEnd");

    piVar4 = *(int **)(*(int *)(iVar6 + 4) + 0xc);

    (**(code **)(*piVar4 + 0x50))(piVar4,uVar7,&pcStack_5c,0xffffffff);

    pfStack_4c = (float *)0xa9f540;

    pfStack_50 = (float *)0x49270b;

    pcStack_5c = (char *)FUN_0074f1b0();

    pfStack_58 = *(float **)(param_1 + 0x60);

    pfStack_54 = *(float **)(param_1 + 100);

    pfStack_50 = *(float **)(param_1 + 0x68);

    pfStack_4c = *(float **)(param_1 + 0x6c);

    FUN_00969a50();

    if (DAT_00afe010 != 0) {

      pfStack_4c = *(float **)(DAT_00afe010 + 0xc);

      pfStack_50 = (float *)0x492746;

      (**(code **)((int)*pfStack_4c + 0x104))();

    }

    if (DAT_00afe034 != 0) {

      pfStack_4c = *(float **)(DAT_00afe034 + 0xc);

      pfStack_50 = (float *)0x49275b;

      (**(code **)((int)*pfStack_4c + 0x104))();

    }

    if ((*(int *)(param_1 + 0xbc) != 0) && (*(int *)(param_1 + 0xc0) != 0)) {

      pfStack_4c = (float *)0x2;

      pfStack_50 = (float *)0x492782;

      FUN_0079a1c0();

      pfStack_4c = *(float **)(param_1 + 4);

      pfStack_50 = (float *)0x49278b;

      FUN_00442b90();

      if (*(int *)(param_1 + 4) != 0) {

        pfStack_4c = (float *)0x49279a;

        FUN_0074dfa0();

      }

      pfVar5 = *(float **)(*(int *)(param_1 + 4) + 0x3c);

      pfStack_4c = (float *)0x4927b7;

      pfStack_4c = (float *)FUN_0075c9c0();

      pfStack_54 = (float *)0x4927c0;

      pfStack_50 = pfVar5;

      FUN_00497210();

      pfStack_4c = (float *)0x0;

      pfStack_50 = (float *)0x0;

      pfStack_54 = (float *)0x4927d8;

      FUN_004367f0();

      pfVar5 = param_2;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x114) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x118) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x17c) = 0;

      if (*(char *)(param_1 + 0x8e) != '\0') {

        iVar8 = *(int *)(*(int *)(param_1 + 0xc0) + 8);

        if ((*(byte *)(iVar8 + 0xbc) & 1) != 0) {

          pfStack_4c = (float *)0x492816;

          iVar8 = FUN_00972e50();

        }

        puVar1 = (uint32_t /* width from decompiler */ *)(param_1 + 0x128);

        *puVar1 = *(uint32_t /* width from decompiler */ *)(iVar8 + 0x30);

        *(uint32_t /* width from decompiler */ *)(param_1 + 300) = *(uint32_t /* width from decompiler */ *)(iVar8 + 0x34);

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x130) = *(uint32_t /* width from decompiler */ *)(iVar8 + 0x38);

        pfVar2 = (float *)(param_1 + 0x134);

        *pfVar2 = *(float *)(iVar8 + 0x20);

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x138) = *(uint32_t /* width from decompiler */ *)(iVar8 + 0x24);

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x13c) = *(uint32_t /* width from decompiler */ *)(iVar8 + 0x28);

        pfStack_54 = (float *)0x492853;

        pfStack_50 = pfVar2;

        pfStack_4c = pfVar2;

        FUN_0076f5f0();

        pfStack_4c = (float *)0x492861;

        fVar9 = (float10)FUN_0079a110();

        pfStack_4c = (float *)(float)fVar9;

        pfStack_50 = (float *)0x49286a;

        FUN_006894b0();

        uStack_18 = *puVar1;

        uStack_14 = *(uint32_t /* width from decompiler */ *)(param_1 + 300);

        uStack_10 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x130);

        pfStack_58 = (float *)0x492897;

        pfStack_54 = pfVar2;

        pfStack_50 = pfVar2;

        FUN_0076f5f0();

        fStack_24 = *pfVar2 * DAT_00aaa668;

        fStack_20 = *(float *)(param_1 + 0x138) * DAT_00aaa668;

        pfStack_58 = &fStack_24;

        pcStack_5c = (char *)&uStack_18;

        fStack_1c = *(float *)(param_1 + 0x13c) * DAT_00aaa668;

        FUN_006892b0();

        pfStack_4c = (float *)0x3e99999a;

        pfStack_50 = (float *)0x4928f3;

        fVar9 = (float10)FUN_0079a110();

        pfStack_50 = (float *)(float)fVar9;

        pfStack_54 = (float *)0x4928fc;

        FUN_005b4800();

        iVar8 = *(int *)(*(int *)(param_1 + 0xb8) + 0xe898);

        *(float *)(iVar8 + 0x54) = *(float *)(iVar8 + 0x54) * local_38;

        pfStack_50 = *(float **)(param_1 + 0xb8);

        pfStack_4c = (float *)0x1;

        pfStack_54 = (float *)0x49292f;

        FUN_00496920();

        pfStack_4c = (float *)(param_1 + 0x17c);

        pfStack_50 = pfVar5;

        pfStack_54 = (float *)0x492948;

        FUN_00495730();

        if (DAT_00aef950 == '\0') {

          pfStack_4c = pfVar5;

          pfStack_50 = (float *)0x0;

          pfStack_54 = (float *)0x49297c;

          FUN_00495970();

        }

        else {

          pfStack_50 = pfVar5;

          pfStack_54 = (float *)0x0;

          pfStack_58 = (float *)0x492966;

          pfStack_4c = (float *)puVar1;

          FUN_004959e0();

        }

        if (*(char *)(param_1 + 0x85) != '\0') {

          pfStack_50 = *(float **)(param_1 + 0xb8);

          pfStack_4c = pfVar5;

          pfStack_54 = (float *)0x492998;

          FUN_004951d0();

          if (DAT_00aef950 == '\0') {

            pfStack_4c = pfVar5;

            pfStack_50 = (float *)0x0;

            pfStack_54 = (float *)0x4929cc;

            FUN_00495970();

          }

          else {

            pfStack_50 = pfVar5;

            pfStack_54 = (float *)0x0;

            pfStack_58 = (float *)0x4929b6;

            pfStack_4c = (float *)puVar1;

            FUN_004959e0();

          }

        }

        pfStack_4c = (float *)0x3;

        pfStack_50 = (float *)0x4929d9;

        FUN_0079a1c0();

        pfStack_4c = pfVar5;

        pfStack_50 = (float *)0x4929e1;

        FUN_0048f660();

        pfStack_4c = (float *)0x3;

        pfStack_50 = (float *)0x4929ee;

        FUN_0079a120();

        if (DAT_00aef950 == '\0') {

          pfStack_4c = pfVar5;

          pfStack_50 = (float *)0x0;

          pfStack_54 = (float *)0x492a22;

          FUN_00495970();

        }

        else {

          pfStack_50 = pfVar5;

          pfStack_54 = (float *)0x0;

          pfStack_58 = (float *)0x492a0c;

          pfStack_4c = (float *)puVar1;

          FUN_004959e0();

        }

        if ((*(int *)(param_1 + 0xb8) != 0) && (*(int *)(*(int *)(param_1 + 0xb8) + 0xe89c) != 0)) {

          pfStack_4c = (float *)(DAT_00d17958 + 0x2d0);

          pfStack_50 = (float *)0x492a4f;

          FUN_00496110();

        }

      }

      pfStack_4c = (float *)&param_2;

      pfStack_50 = pfVar5;

      param_2 = (float *)0x1e;

      pfStack_54 = (float *)0x492a68;

      FUN_0048fee0();

      pfStack_4c = (float *)&param_2;

      pfStack_50 = pfVar5;

      pfStack_54 = (float *)0x492a75;

      FUN_00491f60();

      if (*(int **)(param_1 + 0x174) != (int *)0x0) {

        pfStack_4c = pfVar5;

        pfStack_50 = (float *)0x492a85;

        (**(code **)(**(int **)(param_1 + 0x174) + 0x3c))();

      }

      if ((((*(char *)(param_1 + 0x86) != '\0') && (*(int *)(param_1 + 0xb8) != 0)) &&

          (iVar8 = *(int *)(*(int *)(param_1 + 0xb8) + 0xe4f8), iVar8 != 0)) &&

         (*(int *)(iVar8 + 0x390) != 0)) {

        pfStack_4c = (float *)0x9c78fc;

        pfStack_50 = (float *)0x492ac5;

        FUN_0040b140();

        local_4._0_1_ = 1;

        iVar8 = (int)ROUND(DAT_00aefa50);

        param_2 = (float *)0x32;

        iVar6 = *(int *)(*(int *)(param_1 + 0xb8) + 0xe898);

        pfStack_4c = (float *)&param_2;

        pfStack_50 = (float *)(*(int *)(iVar6 + 0x70) * iVar8);

        pfStack_54 = (float *)(*(int *)(iVar6 + 0x6c) * iVar8);

        pfStack_58 = (float *)(*(int *)(iVar6 + 0x68) * iVar8);

        pcStack_5c = (char *)(*(int *)(iVar6 + 100) * iVar8);

        FUN_004aae00(pfVar5);

        local_4 = (uint)local_4._1_3_ << 8;

        pfStack_4c = (float *)0x492b2f;

        FUN_0076cef0();

      }

      if (DAT_00aef950 == '\0') {

        pfStack_4c = pfVar5;

        pfStack_50 = (float *)0x0;

        pfStack_54 = (float *)0x492b61;

        FUN_00495970();

      }

      else {

        pfStack_4c = (float *)(param_1 + 0x128);

        pfStack_50 = pfVar5;

        pfStack_54 = (float *)0x0;

        pfStack_58 = (float *)0x492b57;

        FUN_004959e0();

      }

      pfStack_4c = (float *)0x492b72;

      FUN_00496ed0();

      if ((*(char *)(param_1 + 0x87) != '\0') && (*(int **)(param_1 + 0x94) != (int *)0x0)) {

        pfStack_4c = pfVar5;

        pfStack_50 = (float *)0x492b8b;

        (**(code **)(**(int **)(param_1 + 0x94) + 0x3c))();

      }

      pfStack_4c = (float *)0x2;

      pfStack_50 = (float *)0x492b98;

      FUN_0079a120();

      *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0xb8) + 0xe898) + 0x54) = uVar3;

    }

  }

  local_4 = 0xffffffff;

  pfStack_4c = (float *)0x492bbe;

  FUN_0076cef0();

  ExceptionList = pvStack_c;

  return 0;

}
