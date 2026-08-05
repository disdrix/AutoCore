# Annotated low-level: Skill_ApplyEffectsOnTarget_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_005538a0` |
| VA | `0x005538a0` |
| System | skills-abilities |
| Date | 2026-07-29 |
| Prior | `FUN_005538a0` |
| Name confidence | **Probable** (`_Inferred`) |

## Role

Skill **thiscall** that resolves a primary TFID target and applies combat/skill effects immediately: start/fail/hit combat events, optional accuracy roll + miss floater, skill-handler invoke. Called when delay&lt;1 from `Skill_ApplyStatusEffectLocal`, when active-skill HB fires (`FUN_00606180`), and on Recv path with null source + status `'c'`.

## Signature (decompiler + callers)

```c
// __thiscall  ECX = skill runtime (CVOGHBBase-like; offsets +0x5fc id, +0x5f0 handler, +0x624 flags)
unsigned int Skill_ApplyEffectsOnTarget_Inferred(
    void *skill,          // this
    void *caster,         // may be null (Recv null-source 'c' path)
    void *world,          // must be non-null; world+0xe4e8 gate
    void *targetTfid,     // TFID* (primary / list head) → ResolveObjectTarget
    void *posOrArg,       // forwarded to handler vtbl+0x2c
    unsigned int randomSeed); // FUN_0058ab60 RNG slice when accuracy bit set
// returns 1 = applied/ok, 0 = fail/miss/no-world
```

## Control flow (readable)

```
if world==0 || world+0xe4e8==0 → return 0
target = ResolveObjectTarget(targetTfid)
if caster:
  caster.vtbl+0x238(4, skillId, rank, skill+0x14, target, 0,0,0)   // start
  if caster.vtbl+0x214(): FUN_004c2f20(skillId)                     // optional side
handlerFail=false; missFloater=false
if skill+0x5f0 && target:
  if !(skill+0x624 & 1):
    handlerFail = (handler.vtbl+0x2c(caster,skill,world,tfid,pos,seed) == 0)
  else:
    slice = FUN_0058ab60(seed)
    if FUN_00553240(caster, target, *slice, 0) == 0:  // miss
      EnqueueCombatFloater(from→to TFID); missFloater=true
    else:
      handlerFail = (handler.vtbl+0x2c(...) == 0)
    delete[] slice
if caster && (no power || power+0x6b4 < 1) && caster.vtbl+0x214():
  powerObj.vtbl+0xb0(skill+8)   // power/stamina drain path (INFERRED)
if handlerFail || missFloater:
  caster.vtbl+0x238(0xc, skillId, rank, ..., target, ROUND(skill+0x28), 0,0)
  return 0
if target:
  if caster: caster.vtbl+0x238(0xe, ...)   // success on caster
  if target.type==0xe && target.vtbl+0x238(6, ...) nonzero: return 1
  target.vtbl+0x238(5, ...)               // hit on target
return 1
```

## Callers (Ghidra)

| Address | Symbol | Role of call |
|--------:|--------|--------------|
| `0x0051aa00` | `Skill_ApplyStatusEffectLocal` | delay&lt;1 immediate apply |
| `0x00811170` | `Client_RecvSkillStatusEffect` | null source + status `'c'`: ResolveSkillTargets then this |
| `0x00606180` | `FUN_00606180` | active-skill HB fire (after LocalCastValidate==0) |
| `0x00514e70` | `FUN_00514e70` | self/flag skill path with caster TFID as target |
| `0x00620480` | `FUN_00620480` | related apply (see decompile) |

## Callees

`CVOGReaction_ResolveObjectTarget`, `Client_EnqueueCombatFloater_INFERRED`, `FUN_00553240` (accuracy), `FUN_0058ab60` (RNG slice), `FUN_004c2f20`, `operator_delete[]`.

## Open

- Product original name (none recovered)
- Exact English for combat event codes 4/5/6/0xc/0xe
- Whether `targetTfid` is always single TFID vs multi-list head (handler may walk list)
- Power path `vtbl+0x210/+0x214/+0xb0` product names
- `FUN_00553240` / `FUN_0058ab60` residual names

## Pseudocode (annotated copy of raw)

```c
undefined4 __thiscall
Skill_ApplyEffectsOnTarget_Inferred(int param_1,int *param_2,int param_3,undefined4 *param_4,undefined4 param_5,
            undefined4 param_6)

{
  bool bVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  undefined2 *puVar5;
  int *piVar6;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  bool bVar7;
  undefined4 uVar8;
  int aiStack_38 [4];
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  undefined1 uStack_e;
  undefined4 uStack_8;
  
  if ((param_3 == 0) || (*(int *)(param_3 + 0xe4e8) == 0)) {
    return 0;
  }
  piVar3 = (int *)CVOGReaction_ResolveObjectTarget
                            (CONCAT31((int3)((uint)param_4[1] >> 8),*(undefined1 *)(param_4 + 2)),
                             *param_4,param_4[1]);
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 0x238))
              (4,*(undefined4 *)(param_1 + 0x5fc),
               (int)(short)(*(short *)(param_1 + 0x5f6) + *(short *)(param_1 + 0x174)),
               (int)*(short *)(param_1 + 0x14),piVar3,0,0,0);
    iVar4 = (**(code **)(*param_2 + 0x214))();
    if (iVar4 != 0) {
      uVar8 = *(undefined4 *)(param_1 + 0x5fc);
      (**(code **)(*param_2 + 0x214))(uVar8);
      FUN_004c2f20(uVar8);
    }
  }
  bVar1 = false;
  bVar7 = false;
  if ((*(int *)(param_1 + 0x5f0) != 0) && (piVar3 != (int *)0x0)) {
    if ((*(byte *)(param_1 + 0x624) & 1) == 0) {
      iVar4 = (**(code **)(**(int **)(param_1 + 0x5f0) + 0x2c))
                        (param_2,param_1,param_3,param_4,param_5,param_6);
      bVar7 = iVar4 == 0;
      if (bVar7) goto LAB_00553ad2;
    }
    else {
      puVar5 = (undefined2 *)FUN_0058ab60(param_6);
      cVar2 = FUN_00553240(param_2,piVar3,CONCAT22(extraout_var_00,*puVar5),0);
      if (cVar2 == '\0') {
        piVar6 = aiStack_38;
        for (iVar4 = 0xe; iVar4 != 0; iVar4 = iVar4 + -1) {
          *piVar6 = 0;
          piVar6 = piVar6 + 1;
        }
        piVar6 = param_2 + 0x58;
        if (param_2 == (int *)0x0) {
          piVar6 = &DAT_009d1ca8;
        }
        aiStack_38[0] = *piVar6;
        aiStack_38[1] = piVar6[1];
        aiStack_38[2] = piVar6[2];
        aiStack_38[3] = piVar6[3];
        iStack_28 = piVar3[0x58];
        iStack_24 = piVar3[0x59];
        iStack_20 = piVar3[0x5a];
        iStack_1c = piVar3[0x5b];
        uStack_e = 1;
        uStack_8 = 0;
        Client_EnqueueCombatFloater_INFERRED(aiStack_38);
        bVar1 = true;
        operator_delete__(puVar5);
      }
      else {
        iVar4 = (**(code **)(**(int **)(param_1 + 0x5f0) + 0x2c))
                          (param_2,param_1,param_3,param_4,param_5,param_6);
        bVar7 = iVar4 == 0;
        operator_delete__(puVar5);
      }
    }
  }
  if ((param_2 != (int *)0x0) &&
     (((iVar4 = (**(code **)(*param_2 + 0x210))(0), iVar4 == 0 ||
       (iVar4 = (**(code **)(*param_2 + 0x210))(0), *(int *)(iVar4 + 0x6b4) < 1)) &&
      (iVar4 = (**(code **)(*param_2 + 0x214))(), iVar4 != 0)))) {
    piVar6 = (int *)(**(code **)(*param_2 + 0x214))();
    (**(code **)(*piVar6 + 0xb0))(CONCAT22(extraout_var,*(undefined2 *)(param_1 + 8)));
  }
LAB_00553ad2:
  if ((bVar7) || (bVar1)) {
    if (param_2 != (int *)0x0) {
      (**(code **)(*param_2 + 0x238))
                (0xc,*(undefined4 *)(param_1 + 0x5fc),
                 (int)(short)(*(short *)(param_1 + 0x5f6) + *(short *)(param_1 + 0x174)),
                 (int)*(short *)(param_1 + 0x14),piVar3,(int)ROUND(*(float *)(param_1 + 0x28)),0,0);
    }
    return 0;
  }
  if (piVar3 != (int *)0x0) {
    if (param_2 != (int *)0x0) {
      (**(code **)(*param_2 + 0x238))
                (0xe,*(undefined4 *)(param_1 + 0x5fc),
                 (int)(short)(*(short *)(param_1 + 0x5f6) + *(short *)(param_1 + 0x174)),
                 (int)*(short *)(param_1 + 0x14),piVar3,(int)ROUND(*(float *)(param_1 + 0x28)),0,0);
    }
    if ((*(int *)(piVar3[0x2a] + 0x38) == 0xe) &&
       (cVar2 = (**(code **)(*piVar3 + 0x238))
                          (6,*(undefined4 *)(param_1 + 0x5fc),
                           (int)(short)(*(short *)(param_1 + 0x5f6) + *(short *)(param_1 + 0x174)),
                           (int)*(short *)(param_1 + 0x14),param_2,
                           (int)ROUND(*(float *)(param_1 + 0x28)),0,0), cVar2 != '\0')) {
      return 1;
    }
    (**(code **)(*piVar3 + 0x238))
              (5,*(undefined4 *)(param_1 + 0x5fc),
               (int)(short)(*(short *)(param_1 + 0x5f6) + *(short *)(param_1 + 0x174)),
               (int)*(short *)(param_1 + 0x14),param_2,(int)ROUND(*(float *)(param_1 + 0x28)),0,0);
  }
  return 1;
}
```
