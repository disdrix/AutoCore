# Annotated low-level: FUN_004fcd80

| Field | Value |
|---|---|
| Stable ID | `aa_004fcd80` |
| VA | `0x004fcd80` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004fcd80`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_004fcd80(int param_1)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  char *pcVar7;
  char *pcVar8;
  undefined4 local_160;
  undefined4 local_15c;
  undefined4 local_158;
  undefined4 local_154;
  undefined1 local_150 [16];
  undefined1 local_140 [16];
  char local_130 [31];
  char acStack_111 [261];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a2d3d;
  local_c = ExceptionList;
  local_154 = 0;
  if (*(int *)(param_1 + 0x48) == 0) {
    return;
  }
  acStack_111[1] = 0;
  ExceptionList = &local_c;
  FUN_004fc4c0(acStack_111 + 1);
  bVar1 = *(byte *)(param_1 + 0x288);
  if (bVar1 != 0) {
    if (bVar1 < 10) {
      pcVar8 = "_0%i";
    }
    else {
      pcVar8 = "_%i";
    }
    sprintf(local_130,pcVar8,(uint)bVar1);
    pcVar8 = local_130;
    do {
      cVar2 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar2 != '\0');
    uVar3 = (int)pcVar8 - (int)local_130;
    pcVar8 = acStack_111;
    do {
      pcVar7 = pcVar8 + 1;
      pcVar8 = pcVar8 + 1;
    } while (*pcVar7 != '\0');
    pcVar7 = local_130;
    for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar8 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar8 = pcVar8 + 1;
    }
  }
  pcVar8 = acStack_111;
  do {
    pcVar7 = pcVar8;
    pcVar8 = pcVar7 + 1;
  } while (pcVar7[1] != '\0');
  *(undefined4 *)(pcVar7 + 1) = s__tint_dds_009cd060._0_4_;
  *(undefined4 *)(pcVar7 + 5) = s__tint_dds_009cd060._4_4_;
  *(undefined2 *)(pcVar7 + 9) = s__tint_dds_009cd060._8_2_;
  FUN_0096ef70();
  pcVar8 = acStack_111 + 1;
  local_4 = 0;
  FUN_007b6a20(pcVar8);
  cVar2 = FUN_007b6770(pcVar8);
  if (cVar2 == '\0') {
LAB_004fcea9:
    FUN_00989e00(&local_154,"black.dds");
    iVar4 = FUN_0096f3e0(&local_154,0);
    if (iVar4 < 0) goto LAB_004fcfc4;
  }
  else {
    FUN_00989e00(&local_154,acStack_111 + 1);
    iVar4 = FUN_0096f3e0(&local_154,0);
    if (iVar4 < 0) goto LAB_004fcea9;
  }
  local_15c = 0xffffffff;
  local_15c = FUN_00519d20(*(undefined4 *)(param_1 + 0x1a8));
  FUN_009733d0(&local_15c);
  local_158 = 0xffffffff;
  local_158 = FUN_00519d20(*(undefined4 *)(param_1 + 0x1ac));
  FUN_009733d0(&local_158);
  FUN_005858b0(*(undefined4 *)(param_1 + 0x48),local_150,local_140,local_160,&DAT_00afdf30,0);
  if (*(int *)(param_1 + 0x3a0) != 0) {
    FUN_005858b0(*(int *)(param_1 + 0x3a0),local_150,local_140,local_160,&DAT_00afdf30,0);
  }
  piVar6 = (int *)(param_1 + 0x340);
  iVar4 = 3;
  do {
    if (*piVar6 != 0) {
      FUN_005858b0(*piVar6,local_150,local_140,local_160,&DAT_00afdf30,0);
    }
    piVar6 = piVar6 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
LAB_004fcfc4:
  local_4 = 0xffffffff;
  FUN_0096efd0();
  ExceptionList = local_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
