# Annotated low-level: FUN_0055dfc0

| Field | Value |
|---|---|
| Stable ID | `aa_0055dfc0` |
| VA | `0x0055dfc0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0055dfc0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_0055dfc0(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0xe0);
  param_2[1] = *(undefined4 *)(param_1 + 0xe4);
  param_2[2] = *(undefined4 *)(param_1 + 0xe8);
  param_2[3] = *(undefined4 *)(param_1 + 0xec);
  *(undefined1 *)(param_2 + 4) = *(undefined1 *)(param_1 + 0x23c);
  param_2[8] = *(undefined4 *)(param_1 + 0x210);
  param_2[9] = *(undefined4 *)(param_1 + 0x214);
  param_2[10] = *(undefined4 *)(param_1 + 0x218);
  param_2[0xb] = *(undefined4 *)(param_1 + 0x21c);
  param_2[0xc] = *(undefined4 *)(param_1 + 0x220);
  param_2[0xd] = *(undefined4 *)(param_1 + 0x224);
  param_2[0xe] = *(undefined4 *)(param_1 + 0x228);
  param_2[0xf] = *(undefined4 *)(param_1 + 0x22c);
  param_2[5] = *(undefined4 *)(param_1 + 0x234);
  param_2[0x10] = *(undefined4 *)(param_1 + 0x230);
  param_2[0x11] = *(undefined4 *)(param_1 + 0x164);
  param_2[0x12] = *(undefined4 *)(param_1 + 0x168);
  param_2[0x13] = *(undefined4 *)(param_1 + 0x17c);
  param_2[0x18] = *(undefined4 *)(*(int *)(param_1 + 0xcc) + 8);
  param_2[0x1a] = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0xcc) + 0xc) + 4);
  param_2[0x1b] = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0xcc) + 0xc) + 8);
  param_2[0x1c] = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0xcc) + 0xc) + 0xc);
  *(undefined1 *)(param_2 + 0x19) = **(undefined1 **)(*(int *)(param_1 + 0xcc) + 0xc);
  *(undefined1 *)(param_2 + 0x1e) = *(undefined1 *)(*(int *)(*(int *)(param_1 + 0xcc) + 0xc) + 0x14)
  ;
  param_2[0x1f] = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0xcc) + 0xc) + 0x18);
  param_2[0x20] = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0xcc) + 0xc) + 0x1c);
  *(undefined1 *)(param_2 + 0x14) = *(undefined1 *)(param_1 + 0x23e);
  *(undefined1 *)((int)param_2 + 0x51) = *(undefined1 *)(param_1 + 0x23f);
  param_2[0x15] = *(undefined4 *)(param_1 + 0x244);
  param_2[0x16] = *(float *)(param_1 + 0x248) / *(float *)(param_1 + 0x244);
  param_2[0x17] = *(undefined4 *)(param_1 + 0x24c);
  *(undefined1 *)(param_2 + 0x21) = *(undefined1 *)(param_1 + 0x23d);
  param_2[0x22] = *(undefined4 *)(param_1 + 0x30);
  param_2[0x23] = *(undefined4 *)(param_1 + 0x34);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
