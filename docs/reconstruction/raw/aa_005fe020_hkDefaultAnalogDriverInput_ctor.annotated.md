# Annotated low-level: hkDefaultAnalogDriverInput_ctor

| Field | Value |
|---|---|
| Stable ID | `aa_005fe020` |
| VA | `0x005fe020` |
| System | input-drive-control |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005fe020`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall hkDefaultAnalogDriverInput_ctor(undefined4 *param_1,undefined4 *param_2)

{
  float fVar1;
  float fVar2;
  
  fVar1 = g_flOne;
  *(undefined1 *)(param_1 + 6) = 0;
  *(undefined1 *)((int)param_1 + 0x19) = 0;
  *(undefined1 *)(param_1 + 9) = 0;
  *(undefined1 *)((int)param_1 + 0x25) = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  *(undefined2 *)((int)param_1 + 6) = 1;
  *param_1 = &PTR_FUN_009dd368;
  param_1[10] = *param_2;
  param_1[0xe] = param_2[2];
  param_1[0xb] = param_2[1];
  fVar2 = (float)param_1[0xb] * ((float)param_1[10] - (float)param_1[0xe]);
  *(undefined1 *)(param_1 + 0xf) = *(undefined1 *)(param_2 + 3);
  param_1[0xd] = fVar2;
  param_1[0xc] = (fVar1 - fVar2) /
                 ((fVar1 - (float)param_1[0xe]) - ((float)param_1[10] - (float)param_1[0xe]));
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
