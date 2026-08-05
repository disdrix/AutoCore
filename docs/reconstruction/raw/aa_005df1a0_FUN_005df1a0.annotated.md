# Annotated low-level: FUN_005df1a0

| Field | Value |
|---|---|
| Stable ID | `aa_005df1a0` |
| VA | `0x005df1a0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005df1a0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int FUN_005df1a0(LPCSTR param_1,int param_2)

{
  uint uVar1;
  LPCSTR lpOutputString;
  LPCSTR pCVar2;
  int iVar3;
  
  if (param_2 == 0) {
    return 0;
  }
  if (param_1[param_2 + -1] == '\0') {
    OutputDebugStringA(param_1);
    printf("%s",param_1);
    return param_2;
  }
  uVar1 = param_2 + 1;
  lpOutputString = (LPCSTR)(**(code **)(*DAT_00b05060 + 0x10))(uVar1,0x12);
  if (0 < param_2) {
    pCVar2 = lpOutputString;
    iVar3 = param_2;
    do {
      *pCVar2 = pCVar2[(int)param_1 - (int)lpOutputString];
      pCVar2 = pCVar2 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  lpOutputString[param_2] = '\0';
  OutputDebugStringA(lpOutputString);
  printf("%s",lpOutputString);
  if (-1 < (int)uVar1) {
    (**(code **)(*DAT_00b05060 + 0x14))(lpOutputString,uVar1 & 0x7fffffff,0x12);
  }
  return param_2;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
