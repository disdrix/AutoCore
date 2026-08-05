# Annotated low-level: FUN_004aaa20

| Field | Value |
|---|---|
| Stable ID | `aa_004aaa20` |
| VA | `0x004aaa20` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004aaa20`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 FUN_004aaa20(char *param_1)

{
  char cVar1;
  char *pcVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  undefined4 *puVar9;
  undefined1 *puVar10;
  undefined1 local_21c [4];
  char local_218 [2];
  undefined4 uStack_216;
  CHAR local_110 [268];
  
  local_218[0] = '\0';
  local_218[1] = '\0';
  puVar3 = &uStack_216;
  for (iVar4 = 0x40; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined2 *)puVar3 = 0;
  pcVar2 = strrchr(param_1,0x5c);
  if ((pcVar2 == (char *)0x0) && (pcVar2 = strrchr(param_1,0x2f), pcVar2 == (char *)0x0)) {
    pcVar7 = (char *)((int)local_21c + 0x1e);
    strncpy(pcVar7,param_1,0x104);
    *(undefined1 *)((int)local_21c + 0x122) = 0;
    pcVar2 = pcVar7;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar8 = local_21c + 3;
    do {
      pcVar6 = pcVar8 + 1;
      pcVar8 = pcVar8 + 1;
    } while (*pcVar6 != '\0');
    pcVar6 = pcVar7;
    for (uVar5 = (uint)((int)pcVar2 - (int)pcVar7) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar5 = (int)pcVar2 - (int)pcVar7 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar8 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar8 = pcVar8 + 1;
    }
  }
  else {
    iVar4 = -(int)param_1;
    do {
      cVar1 = *param_1;
      param_1[(int)(local_218 + iVar4)] = cVar1;
      param_1 = param_1 + 1;
    } while (cVar1 != '\0');
    pcVar2 = strrchr(local_218,0x5c);
    if (pcVar2 == (char *)0x0) {
      pcVar2 = strrchr(local_218,0x2f);
      pcVar7 = (char *)((int)local_21c + 0x1e);
      do {
        cVar1 = *pcVar2;
        *pcVar7 = cVar1;
        pcVar2 = pcVar2 + 1;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
    }
  }
  _strlwr((char *)((int)local_21c + 0x1e));
  pcVar2 = strstr(local_218,".fam");
  if (pcVar2 == (char *)0x0) {
    puVar3 = (undefined4 *)(local_21c + 3);
    do {
      puVar9 = puVar3;
      puVar3 = (undefined4 *)((int)puVar9 + 1);
    } while (*(char *)((int)puVar9 + 1) != '\0');
    *(undefined4 *)((int)puVar9 + 1) = DAT_00a285c4;
    *(undefined1 *)((int)puVar9 + 5) = DAT_00a285c8;
  }
  GetCurrentDirectoryA(0x104,local_110);
  pcVar2 = local_218;
  FUN_007b6a20(pcVar2);
  puVar3 = (undefined4 *)FUN_007b72b0(pcVar2);
  if (puVar3 != (undefined4 *)0x0) {
    FUN_004a94e0(puVar3);
    (**(code **)*puVar3)(1);
    pcVar2 = strrchr(local_21c,0x2e);
    if (pcVar2 != (char *)0x0) {
      *pcVar2 = '\0';
    }
    puVar3 = (undefined4 *)&stack0xfffffde3;
    do {
      puVar9 = puVar3;
      puVar3 = (undefined4 *)((int)puVar9 + 1);
    } while (*(char *)((int)puVar9 + 1) != '\0');
    *(undefined4 *)((int)puVar9 + 1) = DAT_00a395dc;
    *(undefined1 *)((int)puVar9 + 5) = DAT_00a395e0;
    pcVar2 = strrchr(local_21c,0x5c);
    if ((pcVar2 == (char *)0x0) && (pcVar2 = strrchr(local_21c,0x2f), pcVar2 == (char *)0x0)) {
      pcVar2 = local_21c;
    }
    else {
      pcVar2 = pcVar2 + 1;
    }
    FUN_004aa200(pcVar2);
    puVar10 = local_21c;
    FUN_007b6a20(puVar10);
    FUN_007b70b0(puVar10);
    return 1;
  }
  FUN_007a4480(1,"Could not locate the following map: %s",local_218);
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
