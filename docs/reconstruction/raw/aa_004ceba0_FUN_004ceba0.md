# Raw capture: FUN_004ceba0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ceba0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004ceba0` |
| **Canonical name** | `FUN_004ceba0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
float10 FUN_004ceba0(void)



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

      *(undefined4 *)in_stack_00000018 = s_No_Attacker_009cc380._0_4_;

      *(undefined4 *)(in_stack_00000018 + 4) = s_No_Attacker_009cc380._4_4_;

      *(undefined4 *)(in_stack_00000018 + 8) = s_No_Attacker_009cc380._8_4_;

    }

    return (float10)g_flOne;

  }

  if (in_stack_00000014 == (int *)0x0) {

    if (in_stack_00000018 != (char *)0x0) {

      *(undefined4 *)in_stack_00000018 = s_No_Victim_009cc374._0_4_;

      *(undefined4 *)(in_stack_00000018 + 4) = s_No_Victim_009cc374._4_4_;

      *(undefined2 *)(in_stack_00000018 + 8) = s_No_Victim_009cc374._8_2_;

    }

    return (float10)g_flZero;

  }

  iVar1 = (**(code **)(*in_stack_00000014 + 0x214))();

  if (iVar1 == 0) {

    if (in_stack_00000018 != (char *)0x0) {

      pcVar4 = "Victim inanimate (AutoHit)";

      for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {

        *(undefined4 *)in_stack_00000018 = *(undefined4 *)pcVar4;

        pcVar4 = pcVar4 + 4;

        in_stack_00000018 = in_stack_00000018 + 4;

      }

      *(undefined2 *)in_stack_00000018 = *(undefined2 *)pcVar4;

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

      *(undefined4 *)in_stack_00000018 = *(undefined4 *)pcVar4;

      pcVar4 = pcVar4 + 4;

      in_stack_00000018 = in_stack_00000018 + 4;

    }

  }

  return (float10)g_flOne;

}
```

---

## Append — re-verify 2026-07-29

Live Ghidra decompile body matches capture above (no material CF change). Additional sealed evidence (not replacing body):

- Callers: `FUN_005531d0 @ 005531d0`, `FUN_0056cf00 @ 0056cf00` only (`get_function_callers`).
- Call sites xrefs: `0055322c`, `0056cf43`.
- Constants: `DAT_009cbf7c`=`0.95f`, `g_flKillSpreeBonusPerStack`=`0.05f`, `DAT_00af1b6c`=`0.15f` (`read_memory`).
- High pcode: sole `FLOAT_ADD` at `004ced06` = `*(float*)(cre+0x260) + firstFloat`; clamp FLOAT ops at `004cef2e`/`004cef49`/`004cef58`.
- Dual A/B: `reviews/A_aa_004ceba0_Skill_NonCreatureCastAutoHit.md`, `reviews/B_aa_004ceba0_Skill_NonCreatureCastAutoHit.md`.
