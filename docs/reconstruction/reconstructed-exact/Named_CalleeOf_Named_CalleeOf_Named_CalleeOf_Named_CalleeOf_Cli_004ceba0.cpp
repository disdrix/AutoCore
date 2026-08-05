// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_004ceba0
// -----------------------------------------------------------------------------
// Stable ID: aa_004ceba0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvSkillSt
// Address:   0x004ceba0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvSkillSt: skill/cast helper. Evidence string: "Victim inanimate (AutoHit)". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Victim inanimate (AutoHit)"
//   - "Non-Creature cast (AutoHit)"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~99 non-empty decompiler lines.
//  - Control keywords: if×16, return×7, for×2.
//  - Notable callees: FUN_004c4070, FUN_004c41c0, FUN_004ceba0, cast, inanimate.
//  - Strings: "Victim inanimate (AutoHit)"; "Non-Creature cast (AutoHit)".
//  - Return sites: 7.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvSkillSt
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

float10 Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_004ceba0(void)



{

  int iVar1;

  int iVar2;

  int iVar3;

  char *pcVar4;

  float fVar5;

  float fVar6;

  float unaff_retaddr;

  float fVar7;

  int *in_stack_00000010;

  int *in_stack_00000014;

  char *in_stack_00000018;

  

  if (in_stack_00000010 == (int *)0x0) {

    if (in_stack_00000018 != (char *)0x0) {

      *(uint32_t /* width from decompiler */ *)in_stack_00000018 = s_No_Attacker_009cc380._0_4_;

      *(uint32_t /* width from decompiler */ *)(in_stack_00000018 + 4) = s_No_Attacker_009cc380._4_4_;

      *(uint32_t /* width from decompiler */ *)(in_stack_00000018 + 8) = s_No_Attacker_009cc380._8_4_;

    }

    return (float10)g_flOne;

  }

  if (in_stack_00000014 == (int *)0x0) {

    if (in_stack_00000018 != (char *)0x0) {

      *(uint32_t /* width from decompiler */ *)in_stack_00000018 = s_No_Victim_009cc374._0_4_;

      *(uint32_t /* width from decompiler */ *)(in_stack_00000018 + 4) = s_No_Victim_009cc374._4_4_;

      *(uint16_t *)(in_stack_00000018 + 8) = s_No_Victim_009cc374._8_2_;

    }

    return (float10)g_flZero;

  }

  iVar1 = (**(code **)(*in_stack_00000014 + 0x214))();

  if (iVar1 == 0) {

    if (in_stack_00000018 != (char *)0x0) {

      pcVar4 = "Victim inanimate (AutoHit)";

      for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {

        *(uint32_t /* width from decompiler */ *)in_stack_00000018 = *(uint32_t /* width from decompiler */ *)pcVar4;

        pcVar4 = pcVar4 + 4;

        in_stack_00000018 = in_stack_00000018 + 4;

      }

      *(uint16_t *)in_stack_00000018 = *(uint16_t *)pcVar4;

      in_stack_00000018[2] = pcVar4[2];

    }

    return (float10)g_flOne;

  }

  iVar1 = (**(code **)(*in_stack_00000010 + 0x214))();

  if (iVar1 != 0) {

    iVar1 = (**(code **)(*in_stack_00000010 + 0x27c))();

    iVar2 = (**(code **)(*in_stack_00000014 + 0x27c))();

    iVar3 = (**(code **)(*in_stack_00000010 + 0x210))(0);

    if ((iVar3 == 0) || (iVar3 = (**(code **)(*in_stack_00000014 + 0x210))(0), iVar3 == 0)) {

      if (9 < iVar1 - iVar2) {

        return (float10)DAT_009cbf7c;

      }

      if (iVar1 - iVar2 < -9) {

        return (float10)g_flKillSpreeBonusPerStack;

      }

    }

    (**(code **)(*in_stack_00000010 + 0x214))();

    FUN_004c4070();

    (**(code **)(*in_stack_00000014 + 0x214))();

    FUN_004c41c0();

    iVar1 = (**(code **)(*in_stack_00000010 + 0x214))();

    fVar5 = *(float *)(iVar1 + 0x260) + unaff_retaddr;

    iVar1 = (**(code **)(*in_stack_00000014 + 0x1d4))();

    if ((iVar1 != 0) &&

       (iVar1 = (**(code **)(*in_stack_00000014 + 0x1d4))(), *(int *)(iVar1 + 0x254) != 0)) {

      (**(code **)(*in_stack_00000014 + 0x1d4))();

    }

    iVar1 = (**(code **)(*in_stack_00000014 + 0x214))();

    if (iVar1 != 0) {

      (**(code **)(*in_stack_00000014 + 0x214))();

    }

    iVar1 = (**(code **)(*in_stack_00000014 + 0x210))(0);

    if (iVar1 != 0) {

      (**(code **)(*in_stack_00000014 + 0x210))(0);

    }

    iVar1 = (**(code **)(*in_stack_00000010 + 0x210))(0);

    if (iVar1 != 0) {

      (**(code **)(*in_stack_00000010 + 0x210))(0);

    }

    (**(code **)(*in_stack_00000010 + 0x214))();

    iVar1 = (**(code **)(*in_stack_00000010 + 0x210))(0);

    if (((((iVar1 == 0) || (iVar1 = (**(code **)(*in_stack_00000014 + 0x210))(0), iVar1 == 0)) ||

         (fVar7 = DAT_00af1b6c, DAT_00af1b6c <= fVar5)) &&

        (fVar6 = DAT_009cbf7c, fVar7 = fVar5, DAT_009cbf7c < fVar5)) ||

       (fVar6 = g_flKillSpreeBonusPerStack, fVar7 < g_flKillSpreeBonusPerStack)) {

      fVar7 = fVar6;

    }

    return (float10)fVar7;

  }

  if (in_stack_00000018 != (char *)0x0) {

    pcVar4 = "Non-Creature cast (AutoHit)";

    for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {

      *(uint32_t /* width from decompiler */ *)in_stack_00000018 = *(uint32_t /* width from decompiler */ *)pcVar4;

      pcVar4 = pcVar4 + 4;

      in_stack_00000018 = in_stack_00000018 + 4;

    }

  }

  return (float10)g_flOne;

}
