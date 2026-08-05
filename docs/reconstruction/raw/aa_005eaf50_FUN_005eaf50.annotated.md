# Annotated low-level: FUN_005eaf50

| Field | Value |
|---|---|
| Stable ID | `aa_005eaf50` |
| VA | `0x005eaf50` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005eaf50`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_005eaf50(int param_1,undefined1 *param_2,int param_3,float param_4)

{
  char *pcVar1;
  undefined1 local_21 [29];
  
  pcVar1 = (char *)FUN_00645230(local_21,param_3,param_4);
  if ((*pcVar1 != '\0') &&
     ((ABS(*(float *)(param_1 + 0x38) - *(float *)(param_3 + 0x38)) <= param_4 &&
      ABS(*(float *)(param_1 + 0x34) - *(float *)(param_3 + 0x34)) <= param_4) &&
      ABS(*(float *)(param_1 + 0x30) - *(float *)(param_3 + 0x30)) <= param_4)) {
    *param_2 = 1;
    return;
  }
  *param_2 = 0;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
