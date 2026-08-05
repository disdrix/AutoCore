// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004f1ff0
// -----------------------------------------------------------------------------
// Stable ID: aa_004f1ff0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x004f1ff0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper. Evidence string: "CollectAllGraphicsPreloads". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "CollectAllGraphicsPreloads"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~246 non-empty decompiler lines.
//  - Control keywords: do×16, while×16, if×14, goto×2, return×1.
//  - Notable callees: FUN_007b6730×8, FUN_007b6a20×8, FUN_00989e00×8, FUN_0043d670×7, FUN_00404d70, FUN_004a04f0, FUN_004eb010, FUN_004eb3b0.
//  - Strings: "CollectAllGraphicsPreloads".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004f1ff0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  char *pcVar2;

  int iVar3;

  char *pcVar4;

  char *pcVar5;

  char *pcVar6;

  uint8_t *puVar7;

  uint32_t /* width from decompiler */ uVar8;

  int local_130;

  uint8_t auStack_12c [4];

  uint8_t auStack_128 [4];

  uint8_t auStack_124 [4];

  uint8_t auStack_120 [4];

  uint8_t auStack_11c [4];

  uint32_t /* width from decompiler */ local_118;

  uint8_t auStack_114 [3];

  char cStack_111;

  char local_110 [8];

  char local_108 [4];

  char acStack_104 [4];

  char acStack_100 [244];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a2ba9;

  pvStack_c = ExceptionList;

  local_118 = DAT_00d1f040;

  ExceptionList = &pvStack_c;

  FUN_0076cf00("CollectAllGraphicsPreloads");

  local_4 = 0;

  if ((*(byte *)(*(int *)(param_1 + 0x3c) + 0x3f2) & 0x10) != 0) {

    pcVar2 = (char *)(param_1 + 0x188);

    iVar3 = -(int)pcVar2;

    do {

      cVar1 = *pcVar2;

      pcVar2[(int)(local_110 + iVar3)] = cVar1;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    pcVar2 = &cStack_111;

    do {

      pcVar4 = pcVar2;

      pcVar2 = pcVar4 + 1;

    } while (pcVar4[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar4 + 1) = s__tint_dds_009cd060._0_4_;

    pcVar2 = local_110;

    *(uint32_t /* width from decompiler */ *)(pcVar4 + 5) = s__tint_dds_009cd060._4_4_;

    uVar8 = 0xffffffff;

    *(uint16_t *)(pcVar4 + 9) = s__tint_dds_009cd060._8_2_;

    FUN_007b6a20(pcVar2,0xffffffff);

    cVar1 = FUN_007b6730(pcVar2,uVar8);

    if (cVar1 != '\0') {

      FUN_00989e00(&local_130,local_110);

      FUN_0043d670(&local_130);

    }

  }

  if ((*(int *)(param_1 + 0x38) == 0xe) ||

     ((*(int *)(param_1 + 0x38) == 0x12 && (*(int *)(*(int *)(param_1 + 0x3c) + 0x4e8) == 1)))) {

    pcVar2 = (char *)(param_1 + 0x188);

    iVar3 = -(int)pcVar2;

    do {

      cVar1 = *pcVar2;

      pcVar2[(int)(local_110 + iVar3)] = cVar1;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    pcVar2 = &cStack_111;

    do {

      pcVar4 = pcVar2;

      pcVar2 = pcVar4 + 1;

    } while (pcVar4[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar4 + 1) = DAT_00a67574;

    pcVar2 = local_110;

    *(uint32_t /* width from decompiler */ *)(pcVar4 + 5) = DAT_00a67578;

    uVar8 = 0xffffffff;

    pcVar4[9] = DAT_00a6757c;

    FUN_007b6a20(pcVar2,0xffffffff);

    cVar1 = FUN_007b6730(pcVar2,uVar8);

    if (cVar1 != '\0') {

      FUN_00989e00(&local_130,local_110);

      FUN_0043d670(&local_130);

    }

  }

  if ((*(int *)(param_1 + 0x38) != 0xe) ||

     (iVar3 = FUN_00404d70(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x3c) + 0x6f4)), local_130 = iVar3,

     iVar3 == 0)) goto LAB_004f24e1;

  FUN_004f1e20(1,1);

  cVar1 = *(char *)(*(int *)(iVar3 + 0x3c) + 0x4ce);

  if (cVar1 == '\x02') {

    pcVar2 = (char *)(param_1 + 0x188);

    iVar3 = -(int)pcVar2;

    pcVar4 = pcVar2;

    do {

      cVar1 = *pcVar4;

      pcVar4[(int)(local_110 + iVar3)] = cVar1;

      pcVar4 = pcVar4 + 1;

    } while (cVar1 != '\0');

    pcVar4 = &cStack_111;

    do {

      pcVar5 = pcVar4;

      pcVar4 = pcVar5 + 1;

    } while (pcVar5[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar5 + 1) = DAT_009cd010;

    pcVar4 = local_110;

    *(uint32_t /* width from decompiler */ *)(pcVar5 + 5) = DAT_009cd014;

    uVar8 = 0xffffffff;

    *(uint16_t *)(pcVar5 + 9) = DAT_009cd018;

    FUN_007b6a20(pcVar4,0xffffffff);

    cVar1 = FUN_007b6730(pcVar4,uVar8);

    if (cVar1 != '\0') {

      FUN_00989e00(auStack_128,local_110);

      FUN_0043d670(auStack_128);

    }

    do {

      cVar1 = *pcVar2;

      pcVar2[(int)(local_110 + iVar3)] = cVar1;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    pcVar2 = &cStack_111;

    do {

      pcVar4 = pcVar2;

      pcVar2 = pcVar4 + 1;

    } while (pcVar4[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar4 + 1) = DAT_009cd004;

    pcVar2 = local_110;

    *(uint32_t /* width from decompiler */ *)(pcVar4 + 5) = DAT_009cd008;

    uVar8 = 0xffffffff;

    *(uint16_t *)(pcVar4 + 9) = DAT_009cd00c;

    FUN_007b6a20(pcVar2,0xffffffff);

    cVar1 = FUN_007b6730(pcVar2,uVar8);

    if (cVar1 != '\0') {

      FUN_00989e00(auStack_120,local_110);

      puVar7 = auStack_120;

LAB_004f24c5:

      FUN_0043d670(puVar7);

    }

  }

  else if (cVar1 == '\x04') {

    pcVar2 = (char *)(param_1 + 0x188);

    pcVar5 = local_110 + -(int)pcVar2;

    pcVar4 = pcVar2;

    do {

      cVar1 = *pcVar4;

      pcVar4[(int)pcVar5] = cVar1;

      pcVar4 = pcVar4 + 1;

    } while (cVar1 != '\0');

    pcVar4 = &cStack_111;

    do {

      pcVar6 = pcVar4;

      pcVar4 = pcVar6 + 1;

    } while (pcVar6[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 1) = s__trdleft_geo_009cd050._0_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 5) = s__trdleft_geo_009cd050._4_4_;

    pcVar4 = local_110;

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 9) = s__trdleft_geo_009cd050._8_4_;

    uVar8 = 0xffffffff;

    pcVar6[0xd] = s__trdleft_geo_009cd050[0xc];

    FUN_007b6a20(pcVar4,0xffffffff);

    cVar1 = FUN_007b6730(pcVar4,uVar8);

    pcVar4 = pcVar2;

    if (cVar1 != '\0') {

      FUN_00989e00(auStack_11c,local_110);

      FUN_0043d670(auStack_11c);

    }

    do {

      cVar1 = *pcVar4;

      pcVar4[(int)pcVar5] = cVar1;

      pcVar4 = pcVar4 + 1;

    } while (cVar1 != '\0');

    pcVar4 = &cStack_111;

    do {

      pcVar6 = pcVar4;

      pcVar4 = pcVar6 + 1;

    } while (pcVar6[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 1) = s__trdleft_ai_anm_009cd040._0_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 5) = s__trdleft_ai_anm_009cd040._4_4_;

    pcVar4 = local_110;

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 9) = s__trdleft_ai_anm_009cd040._8_4_;

    uVar8 = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 0xd) = s__trdleft_ai_anm_009cd040._12_4_;

    FUN_007b6a20(pcVar4,0xffffffff);

    cVar1 = FUN_007b6730(pcVar4,uVar8);

    pcVar4 = pcVar2;

    if (cVar1 != '\0') {

      FUN_00989e00(auStack_124,local_110);

      FUN_0043d670(auStack_124);

    }

    do {

      cVar1 = *pcVar4;

      pcVar4[(int)pcVar5] = cVar1;

      pcVar4 = pcVar4 + 1;

    } while (cVar1 != '\0');

    pcVar4 = &cStack_111;

    do {

      pcVar6 = pcVar4;

      pcVar4 = pcVar6 + 1;

    } while (pcVar6[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 1) = s__trdright_geo_009cd030._0_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 5) = s__trdright_geo_009cd030._4_4_;

    pcVar4 = local_110;

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 9) = s__trdright_geo_009cd030._8_4_;

    uVar8 = 0xffffffff;

    *(uint16_t *)(pcVar6 + 0xd) = s__trdright_geo_009cd030._12_2_;

    FUN_007b6a20(pcVar4,0xffffffff);

    cVar1 = FUN_007b6730(pcVar4,uVar8);

    if (cVar1 != '\0') {

      FUN_00989e00(auStack_114,local_110);

      FUN_0043d670(auStack_114);

    }

    do {

      cVar1 = *pcVar2;

      pcVar2[(int)pcVar5] = cVar1;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    pcVar2 = &cStack_111;

    do {

      pcVar4 = pcVar2;

      pcVar2 = pcVar4 + 1;

    } while (pcVar4[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar4 + 1) = s__trdright_ai_anm_009cd01c._0_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar4 + 5) = s__trdright_ai_anm_009cd01c._4_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar4 + 9) = s__trdright_ai_anm_009cd01c._8_4_;

    pcVar2 = local_110;

    *(uint32_t /* width from decompiler */ *)(pcVar4 + 0xd) = s__trdright_ai_anm_009cd01c._12_4_;

    uVar8 = 0xffffffff;

    pcVar4[0x11] = s__trdright_ai_anm_009cd01c[0x10];

    FUN_007b6a20(pcVar2,0xffffffff);

    cVar1 = FUN_007b6730(pcVar2,uVar8);

    if (cVar1 != '\0') {

      FUN_00989e00(auStack_12c,local_110);

      puVar7 = auStack_12c;

      goto LAB_004f24c5;

    }

  }

  FUN_004eb010();

LAB_004f24e1:

  FUN_004eb3b0();

  if (*(int *)(param_1 + 0x88) != 0) {

    FUN_004a04f0(param_2,1,0,0);

  }

  local_4 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = pvStack_c;

  return;

}
