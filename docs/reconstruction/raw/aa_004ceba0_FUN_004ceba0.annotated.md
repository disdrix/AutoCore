# Annotated low-level: FUN_004ceba0

| Field | Value |
|---|---|
| Stable ID | `aa_004ceba0` |
| VA | `0x004ceba0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004ceba0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

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

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.

---

## Re-verify 2026-07-29 (accuracy score chain)

**Tools:** `decompile_function` live; `get_function_pcode` high; `read_memory`; callers `005531d0` / `0056cf00`; callees `004c4070` / `004c41c0` / `004c4140`.

### Signature (callers)

```
float10 f(float atkBonus, float zero, float skillAcc, void* atk, void* vic, char* diag)
```

High pcode stack refs: `0x10` atk, `0x14` vic, `0x18` diag; first float collapsed to `stack:0` / `unaff_retaddr`. **No** live use of 2nd/3rd floats in body.

### Sealed returns

| Condition | Return |
|---|---|
| atk NULL | 1.0 + "No Attacker" |
| vic NULL | 0.0 + "No Victim" |
| vic vfunc+0x214 == 0 | 1.0 + "Victim inanimate (AutoHit)" |
| atk vfunc+0x214 == 0 | 1.0 + "Non-Creature cast (AutoHit)" |
| level Δ > 9 (if either vfunc+0x210 null) | 0.95 (`DAT_009cbf7c`) |
| level Δ < -9 (same gate) | 0.05 (`g_flKillSpreeBonusPerStack`) |
| else | `*(f32*)(cre+0x260) + atkBonus`, clamp [0.05,0.95], dual-veh floor 0.15 |

### Constants (`read_memory`)

| VA | LE bytes | f32 |
|---|---|---|
| `009cbf7c` | `33 33 73 3f` | 0.95 |
| `009cbf80` | `cd cc 4c 3d` | 0.05 |
| `00af1b6c` | `9a 99 19 3e` | 0.15 |

### Pcode score core

- `004ced06` `FLOAT_ADD` ← load `[cre+0x260]` + stack float
- `004cef2e`/`004cef49`/`004cef58` clamp compares vs `af1b6c` / `9cbf7c` / `9cbf80`
- `CALL 004c4070` / `004c41c0`: high pcode output discarded

### Chain

`Skill_AccuracyHitCheck_Inferred` → `FUN_005531d0` → **this** → score vs `(roll%100)*0.01`.

Still open: product names for vfuncs / `+0x260`; why 4070/41c0 called if dead; runtime.
