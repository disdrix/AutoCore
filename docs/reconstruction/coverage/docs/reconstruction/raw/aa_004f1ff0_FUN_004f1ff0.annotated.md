# Annotated low-level: FUN_004f1ff0

| Field | Value |
|---|---|
| Stable ID | `aa_004f1ff0` |
| VA | `0x004f1ff0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004f1ff0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_004f1ff0(int param_1,undefined4 param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  undefined1 *puVar7;
  undefined4 uVar8;
  int local_130;
  undefined1 auStack_12c [4];
  undefined1 auStack_128 [4];
  undefined1 auStack_124 [4];
  undefined1 auStack_120 [4];
  undefined1 auStack_11c [4];
  undefined4 local_118;
  undefined1 auStack_114 [3];
  char cStack_111;
  char local_110 [8];
  char local_108 [4];
  char acStack_104 [4];
  char acStack_100 [244];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
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
    *(undefined4 *)(pcVar4 + 1) = s__tint_dds_009cd060._0_4_;
    pcVar2 = local_110;
    *(undefined4 *)(pcVar4 + 5) = s__tint_dds_009cd060._4_4_;
    uVar8 = 0xffffffff;
    *(undefined2 *)(pcVar4 + 9) = s__tint_dds_009cd060._8_2_;
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
    *(undefined4 *)(pcVar4 + 1) = DAT_00a67574;
    pcVar2 = local_110;
    *(undefined4 *)(pcVar4 + 5) = DAT_00a67578;
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
     (iVar3 = FUN_00404d70(*(undefined4 *)(*(int *)(param_1 + 0x3c) + 0x6f4)), local_130 = iVar3,
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
    *(undefined4 *)(pcVar5 + 1) = DAT_009cd010;
    pcVar4 = local_110;
    *(undefined4 *)(pcVar5 + 5) = DAT_009cd014;
    uVar8 = 0xffffffff;
    *(undefined2 *)(pcVar5 + 9) = DAT_009cd018;
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
    *(undefined4 *)(pcVar4 + 1) = DAT_009cd004;
    pcVar2 = local_110;
    *(undefined4 *)(pcVar4 + 5) = DAT_009cd008;
    uVar8 = 0xffffffff;
    *(undefined2 *)(pcVar4 + 9) = DAT_009cd00c;
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
    *(undefined4 *)(pcVar6 + 1) = s__trdleft_geo_009cd050._0_4_;
    *(undefined4 *)(pcVar6 + 5) = s__trdleft_geo_009cd050._4_4_;
    pcVar4 = local_110;
    *(undefined4 *)(pcVar6 + 9) = s__trdleft_geo_009cd050._8_4_;
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
    *(undefined4 *)(pcVar6 + 1) = s__trdleft_ai_anm_009cd040._0_4_;
    *(undefined4 *)(pcVar6 + 5) = s__trdleft_ai_anm_009cd040._4_4_;
    pcVar4 = local_110;
    *(undefined4 *)(pcVar6 + 9) = s__trdleft_ai_anm_009cd040._8_4_;
    uVar8 = 0xffffffff;
    *(undefined4 *)(pcVar6 + 0xd) = s__trdleft_ai_anm_009cd040._12_4_;
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
    *(undefined4 *)(pcVar6 + 1) = s__trdright_geo_009cd030._0_4_;
    *(undefined4 *)(pcVar6 + 5) = s__trdright_geo_009cd030._4_4_;
    pcVar4 = local_110;
    *(undefined4 *)(pcVar6 + 9) = s__trdright_geo_009cd030._8_4_;
    uVar8 = 0xffffffff;
    *(undefined2 *)(pcVar6 + 0xd) = s__trdright_geo_009cd030._12_2_;
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
    *(undefined4 *)(pcVar4 + 1) = s__trdright_ai_anm_009cd01c._0_4_;
    *(undefined4 *)(pcVar4 + 5) = s__trdright_ai_anm_009cd01c._4_4_;
    *(undefined4 *)(pcVar4 + 9) = s__trdright_ai_anm_009cd01c._8_4_;
    pcVar2 = local_110;
    *(undefined4 *)(pcVar4 + 0xd) = s__trdright_ai_anm_009cd01c._12_4_;
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
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
