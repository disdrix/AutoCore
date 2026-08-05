# Annotated low-level: FUN_0094fac0

| Field | Value |
|---|---|
| Stable ID | `aa_0094fac0` |
| VA | `0x0094fac0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0094fac0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __thiscall FUN_0094fac0(void *param_1,undefined4 param_2,char *param_3)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  uint uVar4;
  uint *puVar5;
  undefined4 local_20 [2];
  uint local_18;
  uint local_14;
  undefined1 local_10;
  undefined4 local_8;
  undefined4 local_4;
  
  pcVar3 = strtok((char *)0x0,param_3);
  if (pcVar3 != (char *)0x0) {
    uVar4 = atoi(pcVar3);
    iVar1 = *(int *)(*(int *)((int)param_1 + 0xe98) + 0x1bc);
    if ((iVar1 == 0) ||
       ((uint)(*(int *)(*(int *)((int)param_1 + 0xe98) + 0x1c0) - iVar1 >> 4) <= uVar4)) {
      puVar5 = &DAT_00a15858;
    }
    else {
      puVar5 = (uint *)(uVar4 * 0x10 + iVar1);
    }
    uVar4 = *puVar5;
    uVar2 = puVar5[1];
    if ((((uVar4 & uVar2) != 0xffffffff) || ((char)puVar5[2] != '\0')) &&
       (pcVar3 = strtok((char *)0x0,param_3), pcVar3 != (char *)0x0)) {
      local_20[0] = 0x20a4;
      local_10 = 0;
      local_8 = 0;
      local_4 = 0;
      local_18 = uVar4;
      local_14 = uVar2;
      Client_SendSectorPacket(param_1,0x20,local_20);
    }
  }
  return 1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
