# Annotated low-level: FUN_0076aba0

| Field | Value |
|---|---|
| Stable ID | `aa_0076aba0` |
| VA | `0x0076aba0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0076aba0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_0076aba0(char *param_1,undefined1 *param_2,char *param_3,char *param_4)

{
  char cVar1;
  bool bVar2;
  char *in_EAX;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  undefined2 *puVar7;
  
  *param_2 = 0;
  pcVar3 = in_EAX;
  if (in_EAX != (char *)0x0) {
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    uVar4 = (int)pcVar3 - (int)in_EAX;
    pcVar3 = param_2 + -1;
    do {
      pcVar6 = pcVar3 + 1;
      pcVar3 = pcVar3 + 1;
    } while (*pcVar6 != '\0');
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar3 = *(undefined4 *)in_EAX;
      in_EAX = in_EAX + 4;
      pcVar3 = pcVar3 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar3 = *in_EAX;
      in_EAX = in_EAX + 1;
      pcVar3 = pcVar3 + 1;
    }
  }
  bVar2 = false;
  pcVar3 = param_1;
  if (param_1 != (char *)0x0) {
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    uVar4 = (int)pcVar3 - (int)param_1;
    pcVar3 = param_2 + -1;
    do {
      pcVar6 = pcVar3 + 1;
      pcVar3 = pcVar3 + 1;
    } while (*pcVar6 != '\0');
    pcVar6 = param_1;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar3 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar3 = pcVar3 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar3 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar3 = pcVar3 + 1;
    }
    if (*param_1 != '\0') {
      do {
        pcVar3 = param_1;
        param_1 = pcVar3 + 1;
      } while (*pcVar3 != '\0');
      pcVar3 = strchr("/\\",(int)pcVar3[-1]);
      if (pcVar3 == (char *)0x0) {
        bVar2 = true;
      }
    }
  }
  if ((param_3 != (char *)0x0) || (param_4 != (char *)0x0)) {
    if (bVar2) {
      puVar7 = (undefined2 *)(param_2 + -1);
      do {
        pcVar3 = (char *)((int)puVar7 + 1);
        puVar7 = (undefined2 *)((int)puVar7 + 1);
      } while (*pcVar3 != '\0');
      *puVar7 = DAT_00a2eb5c;
    }
    pcVar3 = param_3;
    if (param_3 != (char *)0x0) {
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      uVar4 = (int)pcVar3 - (int)param_3;
      pcVar3 = param_2 + -1;
      do {
        pcVar6 = pcVar3 + 1;
        pcVar3 = pcVar3 + 1;
      } while (*pcVar6 != '\0');
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar3 = *(undefined4 *)param_3;
        param_3 = param_3 + 4;
        pcVar3 = pcVar3 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar3 = *param_3;
        param_3 = param_3 + 1;
        pcVar3 = pcVar3 + 1;
      }
    }
    if (param_4 != (char *)0x0) {
      pcVar3 = param_4;
      if (*param_4 != '.') {
        puVar7 = (undefined2 *)(param_2 + -1);
        do {
          pcVar6 = (char *)((int)puVar7 + 1);
          puVar7 = (undefined2 *)((int)puVar7 + 1);
        } while (*pcVar6 != '\0');
        *puVar7 = DAT_00a2e610;
      }
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      uVar4 = (int)pcVar3 - (int)param_4;
      pcVar3 = param_2 + -1;
      do {
        pcVar6 = pcVar3 + 1;
        pcVar3 = pcVar3 + 1;
      } while (*pcVar6 != '\0');
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar3 = *(undefined4 *)param_4;
        param_4 = param_4 + 4;
        pcVar3 = pcVar3 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar3 = *param_4;
        param_4 = param_4 + 1;
        pcVar3 = pcVar3 + 1;
      }
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
