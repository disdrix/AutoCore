# Annotated low-level: FUN_0041bbd0

| Field | Value |
|---|---|
| Stable ID | `aa_0041bbd0` |
| VA | `0x0041bbd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0041bbd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0041bbd0(int *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int unaff_EBX;
  undefined4 *unaff_ESI;
  int *unaff_EDI;
  undefined1 local_8 [8];
  
  piVar1 = *(int **)(unaff_EBX + 4);
  if (*(int *)(unaff_EBX + 8) == 0) {
    FUN_0040f100(unaff_ESI,1,piVar1,unaff_EDI);
    return;
  }
  if (param_1 == (int *)*piVar1) {
    if (*unaff_EDI < param_1[3]) {
      FUN_0040f100(unaff_ESI,1,param_1,unaff_EDI);
      return;
    }
  }
  else if (param_1 == piVar1) {
    if (*(int *)(piVar1[2] + 0xc) < *unaff_EDI) {
      FUN_0040f100(unaff_ESI,0,piVar1[2],unaff_EDI);
      return;
    }
  }
  else {
    if (*unaff_EDI < param_1[3]) {
      FUN_005a2850();
      if (param_1[3] < *unaff_EDI) {
        if (*(char *)(param_1[2] + 0x15) != '\0') {
          FUN_0040f100(unaff_ESI,0,param_1,unaff_EDI);
          return;
        }
        FUN_0040f100(unaff_ESI,1,param_1,unaff_EDI);
        return;
      }
    }
    if (param_1[3] < *unaff_EDI) {
      FUN_00673070();
      if ((param_1 == *(int **)(unaff_EBX + 4)) || (*unaff_EDI < param_1[3])) {
        if (*(char *)(param_1[2] + 0x15) != '\0') {
          FUN_0040f100(unaff_ESI,0,param_1,unaff_EDI);
          return;
        }
        FUN_0040f100(unaff_ESI,1,param_1,unaff_EDI);
        return;
      }
    }
  }
  puVar2 = (undefined4 *)FUN_0040ed60(local_8,unaff_EDI);
  *unaff_ESI = *puVar2;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
