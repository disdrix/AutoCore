# Annotated low-level: FUN_005dbca0

| Field | Value |
|---|---|
| Stable ID | `aa_005dbca0` |
| VA | `0x005dbca0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005dbca0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __thiscall FUN_005dbca0(int param_1,uint param_2)

{
  float local_10;
  float local_c;
  float local_8;
  undefined4 local_4;
  
  local_8 = DAT_00aaa7a8;
  *(uint *)(param_1 + 400) = param_2;
  local_10 = (float)(param_2 >> 0x10 & 0xff) * local_8;
  local_c = (float)(param_2 >> 8 & 0xff) * local_8;
  local_8 = (float)(param_2 & 0xff) * local_8;
  local_4 = DAT_00a0f298;
  if (*(int *)(param_1 + 0x48) != 0) {
    FUN_009700f0("MatDiffuse",&local_10);
    FUN_009700f0("MatEmissive",&local_10);
    FUN_009700f0("MatAmbient",&local_10);
    FUN_0096f660();
  }
  return 1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
