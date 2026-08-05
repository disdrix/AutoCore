# Annotated low-level: FUN_0065bec0

| Field | Value |
|---|---|
| Stable ID | `aa_0065bec0` |
| VA | `0x0065bec0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0065bec0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int __fastcall FUN_0065bec0(int param_1)

{
  float fVar1;
  
  FUN_00651f60();
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  fVar1 = g_flOne;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(float *)(param_1 + 0x60) = fVar1;
  *(float *)(param_1 + 0x74) = fVar1;
  *(float *)(param_1 + 0x88) = fVar1;
  *(undefined4 *)(param_1 + 0x90) = DAT_00aaa63c;
  *(undefined4 *)(param_1 + 0x94) = DAT_009e6580;
  *(undefined4 *)(param_1 + 0x98) = 0;
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
