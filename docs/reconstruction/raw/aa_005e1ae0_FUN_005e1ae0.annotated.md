# Annotated low-level: FUN_005e1ae0

| Field | Value |
|---|---|
| Stable ID | `aa_005e1ae0` |
| VA | `0x005e1ae0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005e1ae0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_005e1ae0(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = DAT_009dc4d4;
  *param_1 = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  uVar3 = DAT_00a111a8;
  param_1[1] = uVar1;
  uVar1 = DAT_009dc4d0;
  param_1[5] = 0x400;
  *(undefined1 *)(param_1 + 4) = 1;
  param_1[0xb] = 0;
  param_1[8] = uVar1;
  param_1[9] = uVar1;
  param_1[10] = uVar1;
  uVar2 = DAT_00aaaa90;
  param_1[0xf] = 0;
  uVar1 = DAT_00a0f71c;
  param_1[0xc] = uVar2;
  param_1[0xd] = uVar2;
  param_1[0xe] = uVar2;
  uVar2 = DAT_00a0f718;
  param_1[0x11] = uVar1;
  param_1[0x12] = g_flOne;
  param_1[0x15] = DAT_009dc4cc;
  param_1[0x16] = g_flOverheatCoolFrac;
  param_1[0x17] = g_flMsToSeconds_Inferred;
  param_1[0x18] = g_flMultiKillCountBlend;
  param_1[0x1a] = DAT_00a10e78;
  uVar1 = DAT_00a0f70c;
  param_1[0x1b] = DAT_00a0f70c;
  param_1[0x22] = uVar1;
  uVar1 = DAT_00a110d8;
  param_1[0x10] = 0;
  param_1[0x13] = 4;
  *(undefined1 *)(param_1 + 0x14) = 0;
  *(undefined1 *)((int)param_1 + 0x51) = 0;
  *(undefined1 *)(param_1 + 0x19) = 1;
  param_1[0x1c] = uVar2;
  param_1[0x1d] = uVar3;
  *(undefined1 *)(param_1 + 0x1e) = 1;
  param_1[0x1f] = uVar2;
  param_1[0x20] = 0x14;
  *(undefined1 *)(param_1 + 0x21) = 1;
  param_1[0x23] = uVar1;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
