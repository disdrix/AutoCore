# Annotated low-level: FUN_0083cdb0

| Field | Value |
|---|---|
| Stable ID | `aa_0083cdb0` |
| VA | `0x0083cdb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0083cdb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0083cdb0(int *param_1,uint param_2)

{
  int *piVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  void *pvVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  char unaff_BL;
  void *unaff_ESI;
  int *piVar9;
  bool bVar10;
  undefined4 uStack_44;
  char *pcStack_40;
  char *pcStack_3c;
  int *piStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  void *local_c;
  int *piStack_8;
  uint local_4;
  
  local_4 = 0xffffffff;
  piStack_8 = (int *)&LAB_009b4616;
  local_c = ExceptionList;
  piVar9 = (int *)0x0;
  if ((((param_1[0x130] != 0) && (param_1[0x14e] != 0)) && (param_2 != 0)) &&
     (0 < *(int *)(param_2 + 0x40))) {
    uStack_30 = 0x83ce05;
    ExceptionList = &local_c;
    cVar3 = FUN_0083c110();
    if ((cVar3 != '\x01') && (iVar4 = FUN_00415720(), iVar4 != -1)) {
      uStack_30 = 0x83ce2a;
      pvVar5 = operator_new(0x638);
      local_4 = 0;
      if (pvVar5 != (void *)0x0) {
        uStack_30 = 0x83ce3f;
        piVar9 = (int *)FUN_00824410();
      }
      local_4 = 0xffffffff;
      uStack_30 = 0x83ce54;
      (**(code **)(*param_1 + 0xa8))();
      uStack_30 = 0x83ce5e;
      (**(code **)(*piVar9 + 0x43c))();
      uStack_30 = 1;
      uStack_34 = 1;
      piStack_38 = (int *)0x83ce6c;
      (**(code **)(*piVar9 + 0xec))();
      if ((int *)piVar9[0x18a] != (int *)0x0) {
        piStack_38 = (int *)0x1;
        pcStack_3c = (char *)0x1;
        pcStack_40 = (char *)0x83ce82;
        (**(code **)(*(int *)piVar9[0x18a] + 0xec))();
      }
      if ((int *)piVar9[0x18b] != (int *)0x0) {
        piStack_38 = (int *)0x1;
        pcStack_3c = (char *)0x1;
        pcStack_40 = (char *)0x83ce98;
        (**(code **)(*(int *)piVar9[0x18b] + 0xec))();
      }
      if ((int *)piVar9[0x18c] != (int *)0x0) {
        piStack_38 = (int *)0x1;
        pcStack_3c = (char *)0x1;
        pcStack_40 = (char *)0x83ceae;
        (**(code **)(*(int *)piVar9[0x18c] + 0xec))();
      }
      piVar9[0x44] = iVar4;
      piStack_38 = (int *)0x83cec1;
      FUN_0083b830();
      iVar4 = param_1[0x14e];
      if (*(char *)(iVar4 + 0x1d) != '\0') {
        piStack_38 = (int *)0xa64c18;
        pcStack_3c = (char *)0x0;
        pcStack_40 = (char *)0x83ced9;
        FUN_007a4480();
        pcStack_40 = "VOG_DEBUG_STOP";
        uStack_44 = 0;
        FUN_007a4480();
      }
      piStack_38 = (int *)0x83cef1;
      iVar6 = FUN_00415ac0();
      if (iVar6 != 0) {
LAB_0083cfe4:
        param_1[0x151] = param_1[0x151] & ~(1 << ((byte)piVar9[0x44] & 0x1f));
        piStack_38 = (int *)0x83d003;
        (**(code **)(*piVar9 + 0x440))();
        pcStack_3c = (char *)0x83d00e;
        piStack_38 = piVar9;
        (**(code **)(*param_1 + 0xbc))();
        ExceptionList = unaff_ESI;
        return;
      }
      for (iVar6 = *(int *)(*(int *)(*(int *)(iVar4 + 0x10) + (*(uint *)(iVar4 + 8) & param_2) * 4)
                           + 4); iVar6 != 0; iVar6 = *(int *)(iVar6 + 0xc)) {
        if (param_2 == *(uint *)(iVar6 + 0x10)) {
          if ((iVar6 != 0) && (*(int *)(iVar6 + 8) != 0)) {
            piStack_38 = (int *)param_2;
            pcStack_3c = "Duplicate hash insert %u, failing out";
            pcStack_40 = (char *)0x0;
            uStack_44 = 0x83cfe1;
            FUN_007a4480();
            goto LAB_0083cfe4;
          }
          break;
        }
      }
      piStack_38 = (int *)0x83cf28;
      puVar7 = (undefined4 *)FUN_00416ff0();
      puVar7[3] = 0;
      puVar7[5] = 0;
      puVar7[6] = 0;
      *(undefined1 *)(puVar7 + 1) = 0;
      *puVar7 = &PTR_LAB_00a6d5fc;
      puVar7[2] = piVar9;
      puVar7[4] = local_4;
      iVar6 = *(int *)(*(int *)(iVar4 + 0x10) + (*(uint *)(iVar4 + 8) & local_4) * 4);
      puVar7[3] = *(undefined4 *)(iVar6 + 4);
      *(undefined4 **)(iVar6 + 4) = puVar7;
      piStack_38 = (int *)0x83cf62;
      FUN_00429310();
      uVar2 = local_4;
      piVar1 = piStack_8;
      if (*(int *)(iVar4 + 0x18) == 0) {
        *(undefined4 **)(iVar4 + 0x18) = puVar7;
        *(undefined4 **)(iVar4 + 0x14) = puVar7;
        puVar7[6] = 0;
        puVar7[5] = 0;
      }
      else {
        *(undefined4 **)(*(int *)(iVar4 + 0x18) + 0x14) = puVar7;
        puVar7[5] = 0;
        puVar7[6] = *(undefined4 *)(iVar4 + 0x18);
        *(undefined4 **)(iVar4 + 0x18) = puVar7;
      }
      *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;
      piStack_8[0x150] = piStack_8[0x150] + 1;
      piStack_8[0x151] = piStack_8[0x151] | 1 << ((byte)piVar9[0x44] & 0x1f);
      piStack_38 = (int *)0x83cfab;
      FUN_00823790();
      bVar10 = (*(byte *)(uVar2 + 0x638) & 8) == 0;
      if (bVar10) {
        iVar4 = *(int *)piVar9[0x18a];
      }
      else {
        iVar4 = *(int *)piVar9[0x18a];
      }
      piStack_38 = (int *)(uint)bVar10;
      pcStack_3c = (char *)0x83d046;
      pcStack_3c = (char *)(**(code **)(*piVar1 + 0x164))();
      pcStack_40 = (char *)0x0;
      uStack_44 = 0x83d055;
      (**(code **)(iVar4 + 0x154))();
      uStack_44 = 0;
      iVar4 = (**(code **)(*(int *)piVar9[0x18a] + 0x164))();
      *(undefined1 *)(iVar4 + 3) = 0xff;
      iVar4 = *(int *)piVar9[0x18a];
      uVar8 = (**(code **)(iVar4 + 0x164))(0);
      (**(code **)(iVar4 + 0x154))(2,uVar8);
      (**(code **)(*piVar9 + 0x74))(uVar2 + 50000);
      (**(code **)(*piVar9 + 8))(piVar1 + 0x148);
      (**(code **)(*piVar9 + 0x118))(&uStack_44);
      if (unaff_BL == '\0') {
        (**(code **)(*piVar9 + 0xfc))(1,0x3f000000);
      }
      else {
        (**(code **)(*piVar9 + 4))(1);
      }
      if (piVar1[0x12e] != 0) {
        FUN_0092cc60();
      }
    }
  }
  ExceptionList = local_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
