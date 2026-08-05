# Annotated low-level: Client_RefreshOpenMissionUiWindows

| Field | Value |
|---|---|
| Stable ID | `aa_0093a940` |
| VA | `0x0093a940` |
| System | missions-progression |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0093a940`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Client_RefreshOpenMissionUiWindows
   
   Bulk refresh/hide of open HUD panels after mission state change (journal, dialogs, convoy UI).
   Called from CompleteObjective path and Client_RecvCompleteDynamicObjective.
   Can re-enter interface XML loads — re-entrancy sensitive with MSXML. */

void Client_RefreshOpenMissionUiWindows(int param_1)

{
  int *piVar1;
  char cVar2;
  
  if (*(int **)(param_1 + 0x1030) != (int *)0x0) {
    cVar2 = (**(code **)(**(int **)(param_1 + 0x1030) + 0x3d8))();
    if (cVar2 != '\0') {
      FUN_00888de0();
    }
  }
  piVar1 = *(int **)(param_1 + 0x1074);
  if (piVar1 != (int *)0x0) {
    cVar2 = (**(code **)(*piVar1 + 0x3d8))();
    if (cVar2 != '\0') {
      (**(code **)(*piVar1 + 0x448))();
    }
  }
  if (*(int **)(param_1 + 0x1094) != (int *)0x0) {
    cVar2 = (**(code **)(**(int **)(param_1 + 0x1094) + 0x3d8))();
    if (cVar2 != '\0') {
      FUN_008c0d10();
    }
  }
  piVar1 = *(int **)(param_1 + 0x1068);
  if (piVar1 != (int *)0x0) {
    cVar2 = (**(code **)(*piVar1 + 0x3d8))();
    if (cVar2 != '\0') {
      FUN_008e55e0();
      FUN_008e41b0();
      FUN_008e2f40(piVar1);
      FUN_008e5e00();
      FUN_008e47d0();
    }
  }
  piVar1 = *(int **)(*(int *)(param_1 + 0x1040) + 0x50c);
  if (piVar1 != (int *)0x0) {
    cVar2 = (**(code **)(*piVar1 + 0x3d8))();
    if ((cVar2 != '\0') && (piVar1[0x160] != 0)) {
      if (piVar1[0x151] != 0) {
        (**(code **)(*(int *)piVar1[0x151] + 0x34c))();
      }
      if (piVar1[0x160] != 0) {
        FUN_00860700();
      }
      (**(code **)(*piVar1 + 0x448))();
      (**(code **)(*piVar1 + 0x450))();
    }
  }
  piVar1 = *(int **)(*(int *)(param_1 + 0x1034) + 0x510);
  if (piVar1 != (int *)0x0) {
    cVar2 = (**(code **)(*piVar1 + 0x3d8))();
    if ((cVar2 != '\0') && (piVar1[0x160] != 0)) {
      if (piVar1[0x151] != 0) {
        (**(code **)(*(int *)piVar1[0x151] + 0x34c))();
      }
      if (piVar1[0x160] != 0) {
        FUN_00860700();
      }
      (**(code **)(*piVar1 + 0x448))();
    }
  }
  piVar1 = *(int **)(*(int *)(param_1 + 0x1040) + 0x510);
  if (piVar1 != (int *)0x0) {
    cVar2 = (**(code **)(*piVar1 + 0x3d8))();
    if (cVar2 != '\0') {
      FUN_008bdb10();
      (**(code **)(*piVar1 + 0x448))();
    }
  }
  if (*(int **)(param_1 + 0x1054) != (int *)0x0) {
    cVar2 = (**(code **)(**(int **)(param_1 + 0x1054) + 0x3d8))();
    if (cVar2 != '\0') {
      FUN_0089c6c0(1);
    }
  }
  if (*(int **)(param_1 + 0x105c) != (int *)0x0) {
    cVar2 = (**(code **)(**(int **)(param_1 + 0x105c) + 0x3d8))();
    if (cVar2 != '\0') {
      FUN_0088f500();
      FUN_0088ef70();
    }
  }
  piVar1 = *(int **)(param_1 + 0x1060);
  if (piVar1 != (int *)0x0) {
    cVar2 = (**(code **)(*piVar1 + 0x3d8))();
    if (cVar2 != '\0') {
      (**(code **)(*piVar1 + 0x448))();
    }
  }
  piVar1 = *(int **)(param_1 + 0x1050);
  if (piVar1 != (int *)0x0) {
    cVar2 = (**(code **)(*piVar1 + 0x3d8))();
    if (cVar2 != '\0') {
      if (piVar1[0x162] != 0) {
        FUN_00860700();
        (**(code **)(*piVar1 + 0x448))();
      }
      if (piVar1[0x163] != 0) {
        FUN_00860700();
        (**(code **)(*piVar1 + 0x448))();
      }
    }
  }
  if (*(int *)(param_1 + 0x1078) != 0) {
    FUN_008801b0(*(int *)(param_1 + 0x1078));
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
