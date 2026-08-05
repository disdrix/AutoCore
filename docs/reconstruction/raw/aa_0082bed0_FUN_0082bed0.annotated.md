# Annotated low-level: FUN_0082bed0

| Field | Value |
|---|---|
| Stable ID | `aa_0082bed0` |
| VA | `0x0082bed0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0082bed0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_0082bed0(int *param_1)

{
  int *piVar1;
  int iVar2;
  float unaff_ESI;
  float fVar3;
  undefined1 **ppuStack_44;
  undefined1 *puStack_40;
  undefined4 uStack_3c;
  undefined1 *puStack_38;
  int *piStack_34;
  undefined1 *puStack_30;
  int iStack_2c;
  undefined1 auStack_18 [8];
  undefined1 local_10 [4];
  float fStack_c;
  int *piStack_4;
  
  iStack_2c = 1;
  puStack_30 = local_10;
  piStack_34 = (int *)0x82bee8;
  piVar1 = (int *)(**(code **)(*param_1 + 0x140))();
  if (0 < *piVar1) {
    piStack_34 = (int *)0x1;
    puStack_38 = auStack_18;
    uStack_3c = 0x82bf06;
    iVar2 = (**(code **)(*param_1 + 0x140))();
    if (0 < *(int *)(iVar2 + 4)) {
      piStack_34 = (int *)0x1;
      puStack_38 = &stack0xffffffd8;
      uStack_3c = 0x82bf21;
      piVar1 = (int *)(**(code **)(*param_1 + 0x140))();
      fStack_c = (float)*piStack_4 / (float)*piVar1;
      uStack_3c = 1;
      puStack_40 = auStack_18;
      puStack_30 = (undefined1 *)(float)piStack_4[1];
      ppuStack_44 = (undefined1 **)0x82bf4f;
      (**(code **)(*param_1 + 0x140))();
      if (param_1[0x184] != 0) {
        piStack_34 = (int *)0x1;
        puStack_38 = local_10;
        uStack_3c = 0x82bf86;
        (**(code **)(*(int *)param_1[0x184] + 0x140))();
        uStack_3c = 1;
        puStack_40 = auStack_18;
        ppuStack_44 = (undefined1 **)0x82bfad;
        iVar2 = (**(code **)(*(int *)param_1[0x184] + 0x140))();
        iStack_2c = (int)((float)*(int *)(iVar2 + 4) * (float)puStack_38);
        ppuStack_44 = &puStack_30;
        (**(code **)(*(int *)param_1[0x184] + 300))();
        piVar1 = (int *)(**(code **)(*(int *)param_1[0x184] + 0x120))(&stack0xffffffdc,1,0);
        puStack_38 = (undefined1 *)(int)((float)*piVar1 * unaff_ESI);
        fVar3 = 0.0;
        iVar2 = (**(code **)(*(int *)param_1[0x184] + 0x120))(&puStack_30,1,0);
        puStack_40 = (undefined1 *)(int)((float)*(int *)(iVar2 + 4) * fVar3);
        (**(code **)(*(int *)param_1[0x184] + 0x118))(&ppuStack_44);
      }
      if (param_1[0x185] != 0) {
        piStack_34 = (int *)0x1;
        puStack_38 = local_10;
        uStack_3c = 0x82c057;
        (**(code **)(*(int *)param_1[0x185] + 0x140))();
        uStack_3c = 1;
        puStack_40 = auStack_18;
        ppuStack_44 = (undefined1 **)0x82c07e;
        iVar2 = (**(code **)(*(int *)param_1[0x185] + 0x140))();
        iStack_2c = (int)((float)*(int *)(iVar2 + 4) * (float)puStack_38);
        ppuStack_44 = &puStack_30;
        (**(code **)(*(int *)param_1[0x185] + 300))();
      }
    }
  }
  piStack_34 = piStack_4;
  puStack_38 = (undefined1 *)0x82c0ac;
  FUN_007b08d0();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
