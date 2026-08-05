# Annotated low-level: FUN_005f2df0

| Field | Value |
|---|---|
| Stable ID | `aa_005f2df0` |
| VA | `0x005f2df0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005f2df0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
longlong FUN_005f2df0(void)

{
  int *in_EAX;
  int iVar1;
  int iVar2;
  longlong lVar3;
  char acStack_110 [8];
  
  acStack_110[4] = -1;
  acStack_110[5] = '-';
  acStack_110[6] = '_';
  acStack_110[7] = '\0';
  FUN_005f2d70();
  acStack_110[4] = -1;
  acStack_110[5] = '\0';
  acStack_110[6] = '\0';
  acStack_110[7] = '\0';
  iVar2 = 0;
  builtin_strncpy(acStack_110,"\r._",4);
  (**(code **)(*in_EAX + 0x14))();
  acStack_110[0] = -1;
  acStack_110[1] = '\0';
  acStack_110[2] = '\0';
  acStack_110[3] = '\0';
  iVar1 = (**(code **)(*in_EAX + 8))(&stack0xfffffefc);
  if (((iVar1 != 0) &&
      (((('/' < acStack_110[4] && (acStack_110[4] < ':')) || (acStack_110[4] == '+')) ||
       (acStack_110[4] == '-')))) && (iVar2 = 1, 1 < iVar1)) {
    do {
      if ((acStack_110[iVar2 + 4] < '0') || ('9' < acStack_110[iVar2 + 4])) break;
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  (**(code **)(*in_EAX + 0x18))();
  (**(code **)(*in_EAX + 0xc))(iVar2);
  lVar3 = -1;
  acStack_110[iVar2] = '\0';
  if (0 < iVar2) {
    lVar3 = _atoi64(acStack_110);
  }
  return lVar3;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
