# Annotated low-level: FUN_004bdf80

| Field | Value |
|---|---|
| Stable ID | `aa_004bdf80` |
| VA | `0x004bdf80` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004bdf80`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004bdf80(int param_1,float param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  *(float *)(param_1 + 0x5c8) = param_2;
  if (*(char *)(param_1 + 0x571) == '\0') {
    param_2 = param_2 - _DAT_00aefa4c;
    local_8 = 0.0;
    local_4 = g_flOne;
    if ((param_2 <= 0.0) || (DAT_00aef954 <= param_2)) {
      cVar1 = '\0';
    }
    else {
      local_8 = g_flOne;
      local_4 = g_flOne - param_2 / DAT_00aef954;
      cVar1 = '\x01';
    }
    local_10 = local_8;
    local_c = local_8;
    if (*(char *)(param_1 + 0x5c5) == cVar1) {
      if (*(char *)(param_1 + 0x5c5) == '\0') {
        return;
      }
      if (ABS(*(float *)(param_1 + 0x5cc) - local_4) <= DAT_00a0f718) {
        return;
      }
      iVar3 = 0;
      while( true ) {
        if (*(int *)(param_1 + 0xf0) == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = *(int *)(param_1 + 0xf4) - *(int *)(param_1 + 0xf0) >> 2;
        }
        if (iVar2 <= iVar3) break;
        FUN_009700f0("MatDiffuse",&local_10);
        FUN_007522a0("Translucent");
        iVar3 = iVar3 + 1;
      }
      iVar3 = 0;
      while( true ) {
        if (*(int *)(param_1 + 0x23c) == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = *(int *)(param_1 + 0x240) - *(int *)(param_1 + 0x23c) >> 2;
        }
        if (iVar2 <= iVar3) break;
        FUN_009700f0("MatDiffuse",&local_10);
        FUN_007522a0("Translucent");
        iVar3 = iVar3 + 1;
      }
    }
    else {
      *(char *)(param_1 + 0x5c5) = cVar1;
      if (cVar1 == '\0') {
        iVar3 = 0;
        while( true ) {
          if (*(int *)(param_1 + 0xf0) == 0) {
            iVar2 = 0;
          }
          else {
            iVar2 = *(int *)(param_1 + 0xf4) - *(int *)(param_1 + 0xf0) >> 2;
          }
          if (iVar2 <= iVar3) break;
          FUN_0096f5d0();
          iVar3 = iVar3 + 1;
        }
        iVar3 = 0;
        while( true ) {
          if (*(int *)(param_1 + 0x23c) == 0) {
            iVar2 = 0;
          }
          else {
            iVar2 = *(int *)(param_1 + 0x240) - *(int *)(param_1 + 0x23c) >> 2;
          }
          if (iVar2 <= iVar3) break;
          FUN_0096f5d0();
          iVar3 = iVar3 + 1;
        }
        return;
      }
      iVar3 = 0;
      while( true ) {
        if (*(int *)(param_1 + 0xf0) == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = *(int *)(param_1 + 0xf4) - *(int *)(param_1 + 0xf0) >> 2;
        }
        if (iVar2 <= iVar3) break;
        FUN_0096fdf0();
        FUN_009700f0("MatDiffuse",&local_10);
        FUN_007522a0("Translucent");
        iVar3 = iVar3 + 1;
      }
      iVar3 = 0;
      while( true ) {
        if (*(int *)(param_1 + 0x23c) == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = *(int *)(param_1 + 0x240) - *(int *)(param_1 + 0x23c) >> 2;
        }
        if (iVar2 <= iVar3) break;
        FUN_0096fdf0();
        FUN_009700f0("MatDiffuse",&local_10);
        FUN_007522a0("Translucent");
        iVar3 = iVar3 + 1;
      }
    }
    *(float *)(param_1 + 0x5cc) = local_4;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
