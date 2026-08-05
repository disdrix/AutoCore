# Annotated low-level: CVOGCreature_FindTerrainHeight

| Field | Value |
|---|---|
| Stable ID | `aa_004c6100` |
| VA | `0x004c6100` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004c6100`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* CVOGCreature::FindTerrainHeight

   

   AI/movement ground snap. Returns terrainY + creature[+0x120].

   Combat NPCs re-snap here; static IsNPC never call this — server must

   send elevated Y (AutoCore applies physics foot offset for IsNPC). */



float10 __thiscall CVOGCreature_FindTerrainHeight(int *param_1,undefined4 *param_2,float param_3)



{

  int iVar1;

  int *piVar2;

  char cVar3;

  float10 fVar4;

  float fStack_8c;

  undefined4 uStack_80;

  float fStack_7c;

  undefined4 uStack_78;

  undefined4 uStack_74;

  undefined4 uStack_70;

  float fStack_6c;

  undefined4 uStack_68;

  undefined4 uStack_64;

  undefined1 uStack_60;

  int iStack_5c;

  undefined1 auStack_50 [20];

  float fStack_3c;

  int iStack_30;

  void *pvStack_1c;

  undefined1 *puStack_18;

  undefined4 uStack_14;

  

  uStack_14 = 0xffffffff;

  puStack_18 = &LAB_009a1bed;

  pvStack_1c = ExceptionList;

  iVar1 = *(int *)(*(int *)(param_1[1] + 4) + 0xa8 + (int)param_1);

  ExceptionList = &pvStack_1c;

  if ((iVar1 != 0) && (ExceptionList = &pvStack_1c, *(int *)(iVar1 + 0xe8a0) != 0)) {

    ExceptionList = &pvStack_1c;

    piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0xe8a0) + 0x1d8))();

    if (piVar2 == param_1) {

      cVar3 = '\x01';

      goto LAB_004c6157;

    }

  }

  cVar3 = '\0';

LAB_004c6157:

  FUN_0076cf00("CVOGCreature::FindTerrainHeight::findZposition");

  uStack_14 = 0;

  fVar4 = (float10)FUN_004cd220(*param_2,param_2[2]);

  uStack_14 = 0xffffffff;

  fStack_8c = (float)(fVar4 + (float10)param_3);

  FUN_0076cef0();

  if (DAT_00a0f298 < ((float)param_2[1] - fStack_8c) - (float)param_1[0x48]) {

    FUN_0076cf00("CVOGCreature::FindTerrainHeight::castRay");

    uStack_14 = 1;

    if (param_1[0x95] == 0) {

      fVar4 = (float10)CVOGMap_CastTerrainHeight

                                 (*param_2,param_2[2],(float)param_2[1] + param_3,cVar3);

      fStack_8c = (float)(fVar4 + (float10)param_3);

    }

    else {

      (**(code **)(*param_1 + 0x54))();

      uStack_80 = *param_2;

      uStack_70 = *param_2;

      fStack_7c = (float)param_2[1] + (float)param_1[0x48];

      fStack_3c = g_flOne;

      uStack_78 = param_2[2];

      uStack_68 = param_2[2];

      fStack_6c = fStack_7c - DAT_00aaa7ac;

      iStack_5c = (-(uint)(cVar3 != '\0') & 0xd) + 5;

      iStack_30 = 0;

      uStack_74 = 0;

      uStack_60 = 0;

      uStack_64 = 0;

      FUN_00580ed0(&uStack_80,auStack_50);

      if (iStack_30 != 0) {

        fStack_8c = fStack_7c * (g_flOne - fStack_3c) + fStack_6c * fStack_3c + param_3 +

                    DAT_00aaa8f0;

      }

    }

    uStack_14 = 0xffffffff;

    FUN_0076cef0();

  }

  ExceptionList = pvStack_1c;

  return (float10)fStack_8c + (float10)(float)param_1[0x48];

}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.

## Human refine (2026-07-23, priority_011)

- human-refined clean: bLocal, findZposition, castRay paths; foot +0x120
- Clean: docs/reconstruction/reconstructed-exact/CVOGCreature_FindTerrainHeight.cpp
- Dual review: open

