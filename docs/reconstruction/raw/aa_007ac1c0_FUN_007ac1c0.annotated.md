# Annotated low-level: FUN_007ac1c0

| Field | Value |
|---|---|
| Stable ID | `aa_007ac1c0` |
| VA | `0x007ac1c0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007ac1c0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_007ac1c0(int *param_1,char param_2,int param_3)

{
  char cVar1;
  undefined1 *puVar2;
  int iVar3;
  float fVar4;
  
  param_1[0x50] = param_3;
  if (param_2 == '\0') {
    cVar1 = (**(code **)(*param_1 + 0xd0))();
    if (cVar1 != '\0') {
      cVar1 = (**(code **)(*param_1 + 0xf0))(1);
      if (cVar1 != '\0') {
        if (param_1[0x88] == 1) {
          FUN_007abfb0();
        }
        else if (param_1[0x88] != -1) {
          FUN_007abfe0();
        }
      }
      (**(code **)(*param_1 + 0xf0))(2);
      cVar1 = (**(code **)(*param_1 + 0xf0))(4);
      if (cVar1 != '\0') {
        if (param_1[0x88] == 1) {
          FUN_007abf80();
        }
        else if (param_1[0x88] != -1) {
          FUN_007a83a0();
        }
      }
      (**(code **)(*param_1 + 0xf0))(8);
      puVar2 = (undefined1 *)param_1[0xae];
      iVar3 = param_1[0x50];
      param_1[0x88] = -1;
      QueryPerformanceCounter((LARGE_INTEGER *)(puVar2 + 0x10));
      QueryPerformanceCounter((LARGE_INTEGER *)(puVar2 + 0x18));
      *(int *)(puVar2 + 8) = iVar3;
      *(int *)(puVar2 + 0xc) = iVar3;
      fVar4 = DAT_00afa134 + g_flOne;
      *puVar2 = 1;
      param_1[0x51] = (int)fVar4;
      if (param_1[0x3d] == 0) {
        (**(code **)(*param_1 + 0x100))();
      }
    }
  }
  else {
    cVar1 = (**(code **)(*param_1 + 0xf0))(1);
    if (cVar1 != '\0') {
      if (param_1[0x88] == -1) {
        *(char *)((int)param_1 + 0x22b) = (char)param_1[0x3e];
        *(char *)((int)param_1 + 0x22f) = (char)param_1[0x3f];
        *(char *)((int)param_1 + 0x233) = (char)param_1[0x40];
      }
      else if (param_1[0x88] != 1) {
        FUN_007abfe0();
      }
      puVar2 = (undefined1 *)((int)param_1 + 0x22b);
      iVar3 = 3;
      do {
        *puVar2 = 0;
        puVar2 = puVar2 + 4;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    (**(code **)(*param_1 + 0xf0))(2);
    cVar1 = (**(code **)(*param_1 + 0xf0))(4);
    if (cVar1 != '\0') {
      if (param_1[0x88] == -1) {
        param_1[0x8a] = param_1[0x41];
        param_1[0x8b] = param_1[0x42];
        param_1[0x8c] = param_1[0x43];
      }
      else if (param_1[0x88] != 1) {
        param_1[0x41] = param_1[0x8a];
        param_1[0x42] = param_1[0x8b];
        param_1[0x43] = param_1[0x8c];
      }
    }
    (**(code **)(*param_1 + 0xf0))(8);
    cVar1 = (**(code **)(*param_1 + 0xd0))();
    if (cVar1 == '\0') {
      (**(code **)(*param_1 + 0xcc))(1);
    }
    (**(code **)(*param_1 + 0x34c))();
    puVar2 = (undefined1 *)param_1[0xae];
    iVar3 = param_1[0x50];
    param_1[0x88] = 1;
    QueryPerformanceCounter((LARGE_INTEGER *)(puVar2 + 0x10));
    QueryPerformanceCounter((LARGE_INTEGER *)(puVar2 + 0x18));
    *(int *)(puVar2 + 8) = iVar3;
    *(int *)(puVar2 + 0xc) = iVar3;
    fVar4 = DAT_00afa134 + g_flOne;
    *puVar2 = 1;
    param_1[0x51] = (int)fVar4;
    (**(code **)(*param_1 + 0x1f0))();
    if (param_1[0x3d] == 0) {
      (**(code **)(*param_1 + 0x100))();
      return;
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
