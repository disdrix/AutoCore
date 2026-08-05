// =============================================================================
// FUN_0048dde0
// -----------------------------------------------------------------------------
// Stable ID: aa_0048dde0
// Address:   0x0048dde0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048dde0 @ 0x0048dde0
// Stable ID: aa_0048dde0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~180 non-empty decompiler lines.
//  - Control keywords: if×29, return×17, goto×9, while×3, do×2.
//  - Notable callees: FUN_0048d0a0×5, FUN_0048cea0×3, FUN_0048a940, FUN_0048aa20, FUN_0048acb0, FUN_0048ad10, FUN_0048af60, FUN_0048b1a0.
//  - Return sites: 17.

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

char * __thiscall FUN_0048dde0(int param_1,uint32_t /* width from decompiler */ param_2,int param_3,int *param_4)



{

  char cVar1;

  char *pcVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  char *pcVar5;

  int *piVar6;

  int iVar7;

  uint32_t /* width from decompiler */ *extraout_ECX;

  uint32_t /* width from decompiler */ *puVar8;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a0768;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  pcVar2 = (char *)FUN_0048cea0(param_2,param_4);

  iVar3 = FUN_0048af60();

  if ((pcVar2 == (char *)0x0) || (*pcVar2 == '\0')) {

    if (iVar3 == 0) {

      ExceptionList = local_c;

      return (char *)0x0;

    }

    if (*(char *)(iVar3 + 0x2c) != '\0') {

      ExceptionList = local_c;

      return (char *)0x0;

    }

    *(uint8_t *)(iVar3 + 0x2c) = 1;

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x30) = 4;

    pcVar2 = PTR_s_Error_parsing_Element__00aef918;

    do {

      cVar1 = *pcVar2;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    FUN_0048a940(PTR_s_Error_parsing_Element__00aef918,

                 (int)pcVar2 - (int)(PTR_s_Error_parsing_Element__00aef918 + 1));

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x40) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x3c) = 0xffffffff;

    ExceptionList = local_c;

    return (char *)0x0;

  }

  puVar8 = (uint32_t /* width from decompiler */ *)0x0;

  if (param_3 != 0) {

    FUN_0048cca0(pcVar2,param_4);

    *(uint32_t /* width from decompiler */ *)(param_1 + 4) = *extraout_ECX;

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = extraout_ECX[1];

    puVar8 = extraout_ECX;

  }

  if (*pcVar2 != '<') {

    if (iVar3 == 0) {

      ExceptionList = local_c;

      return (char *)0x0;

    }

    FUN_0048d0a0(4,pcVar2,puVar8,param_4);

    ExceptionList = local_c;

    return (char *)0x0;

  }

  uVar4 = FUN_0048cea0(pcVar2 + 1,param_4);

  pcVar2 = (char *)FUN_0048cf60(uVar4,(int *)(param_1 + 0x20),param_4);

  if ((pcVar2 == (char *)0x0) || (*pcVar2 == '\0')) {

    if (iVar3 == 0) {

      ExceptionList = local_c;

      return (char *)0x0;

    }

    FUN_0048d0a0(5,uVar4,param_3,param_4);

    ExceptionList = local_c;

    return (char *)0x0;

  }

  FUN_0048c020(&DAT_00a89ddc);

  puVar8 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x20);

  local_4 = 0;

  FUN_0048aa20(puVar8 + 2,*puVar8);

  FUN_0048acb0(&DAT_00a3a4a0);

  do {

    if (*pcVar2 == '\0') {

      local_4 = 0xffffffff;

      if (param_4 == &DAT_00b03504) {

        ExceptionList = local_c;

        return pcVar2;

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(param_4);

    }

    pcVar5 = (char *)FUN_0048cea0(pcVar2,param_4);

    if ((pcVar5 == (char *)0x0) || (cVar1 = *pcVar5, cVar1 == '\0')) {

      if (iVar3 == 0) goto LAB_0048e11f;

      uVar4 = 7;

LAB_0048e118:

      FUN_0048d0a0(uVar4,pcVar2,param_3,param_4);

LAB_0048e11f:

      local_4 = 0xffffffff;

      if (param_4 == &DAT_00b03504) {

        ExceptionList = local_c;

        return (char *)0x0;

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(param_4);

    }

    if (cVar1 == '/') {

      pcVar2 = pcVar5 + 1;

      if (pcVar5[1] == '>') {

        local_4 = 0xffffffff;

        if (param_4 == &DAT_00b03504) {

          ExceptionList = local_c;

          return pcVar5 + 2;

        }

                    /* WARNING: Subroutine does not return */

        operator_delete(param_4);

      }

      if (iVar3 == 0) goto LAB_0048e11f;

      uVar4 = 8;

      goto LAB_0048e118;

    }

    if (cVar1 == '>') {

      pcVar2 = (char *)FUN_0048d6e0(pcVar5 + 1,param_3,param_4);

      if ((pcVar2 == (char *)0x0) || (*pcVar2 == '\0')) goto LAB_0048e11f;

      piVar6 = param_4 + 2;

      iVar7 = (int)pcVar2 - (int)piVar6;

      break;

    }

    piVar6 = operator_new(0x24);

    if (piVar6 == (int *)0x0) {

      if (iVar3 == 0) goto LAB_0048e11f;

      uVar4 = 3;

      goto LAB_0048e118;

    }

    piVar6[2] = -1;

    piVar6[1] = -1;

    piVar6[3] = 0;

    *piVar6 = (int)&PTR_FUN_009c6e04;

    piVar6[5] = (int)&DAT_00b03504;

    piVar6[6] = (int)&DAT_00b03504;

    piVar6[4] = 0;

    piVar6[8] = 0;

    piVar6[7] = 0;

    piVar6[4] = iVar3;

    pcVar2 = (char *)(**(code **)(*piVar6 + 8))(pcVar5,param_3,param_4);

    if ((pcVar2 == (char *)0x0) || (*pcVar2 == '\0')) {

      if (iVar3 != 0) {

        FUN_0048d0a0(4,pcVar5,param_3,param_4);

      }

      (**(code **)*piVar6)(1);

      goto LAB_0048e11f;

    }

    iVar7 = FUN_0048b1c0(piVar6 + 5);

    if (iVar7 != 0) {

      FUN_0048ad10(piVar6[6] + 8);

      (**(code **)*piVar6)(1);

      goto LAB_0048e11f;

    }

    FUN_0048b1a0(piVar6);

  } while( true );

  while ((*(char *)(iVar7 + (int)piVar6) == (char)*piVar6 &&

         (pcVar5 = (char *)(iVar7 + 1 + (int)piVar6), piVar6 = (int *)((int)piVar6 + 1),

         *pcVar5 != '\0'))) {

    if ((char)*piVar6 == '\0') goto LAB_0048e049;

  }

  if ((char)*piVar6 != '\0') {

    if (iVar3 != 0) {

      FUN_0048d0a0(9,pcVar2,param_3,param_4);

    }

    local_4 = 0xffffffff;

    if (param_4 == &DAT_00b03504) {

      ExceptionList = local_c;

      return (char *)0x0;

    }

                    /* WARNING: Subroutine does not return */

    operator_delete(param_4);

  }

LAB_0048e049:

  local_4 = 0xffffffff;

  if (param_4 == &DAT_00b03504) {

    ExceptionList = local_c;

    return pcVar2 + *param_4;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(param_4);

}
