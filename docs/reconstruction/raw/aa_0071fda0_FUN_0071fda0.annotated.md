# Annotated low-level: FUN_0071fda0

| Field | Value |
|---|---|
| Stable ID | `aa_0071fda0` |
| VA | `0x0071fda0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0071fda0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined1 * FUN_0071fda0(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  int iVar2;
  int *piVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009ab66a;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x158);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  iVar2 = 0;
  local_4 = 0;
  piVar3 = (int *)(param_1 + 0x80);
  do {
    if (*piVar3 != 0) {
      iVar1 = FUN_0071f760(1);
      if (iVar1 != 0) {
        iVar2 = *(int *)(param_1 + 0x80 + iVar2 * 4);
        LeaveCriticalSection(lpCriticalSection);
        ExceptionList = local_c;
        return (undefined1 *)(iVar2 + 0x48);
      }
    }
    iVar2 = iVar2 + 1;
    piVar3 = piVar3 + 1;
  } while (iVar2 < 2);
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = local_c;
  return &DAT_00a1419b;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
