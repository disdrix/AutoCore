# Annotated low-level: FUN_0069dca0

| Field | Value |
|---|---|
| Stable ID | `aa_0069dca0` |
| VA | `0x0069dca0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0069dca0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_0069dca0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_9c [39];
  
  *param_1 = 0;
  param_1[0xe] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  local_9c[0x13] = 0;
  local_9c[0x14] = 0;
  local_9c[0x15] = 0;
  local_9c[0x16] = 0;
  local_9c[0x17] = 0;
  local_9c[0x18] = 0;
  local_9c[0x19] = 0;
  local_9c[6] = 0;
  local_9c[7] = 0;
  local_9c[8] = 0;
  local_9c[9] = 0;
  local_9c[10] = 0;
  local_9c[0xb] = 0;
  local_9c[0xc] = 0;
  local_9c[0x20] = 0;
  local_9c[0x21] = 0;
  local_9c[0x22] = 0;
  local_9c[0x23] = 0;
  local_9c[0x24] = 0;
  local_9c[0x25] = 0;
  local_9c[0x26] = 0;
  local_9c[0xd] = 0x3f4ccccd;
  local_9c[0xe] = 0x3f4ccccd;
  local_9c[0xf] = 0x3f4ccccd;
  local_9c[0x10] = 0x3e4ccccd;
  local_9c[0x11] = 0x3e4ccccd;
  local_9c[0x12] = 0x3e4ccccd;
  puVar2 = local_9c + 0xd;
  puVar3 = param_1;
  for (iVar1 = 0xd; puVar3 = puVar3 + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
  }
  local_9c[0] = 0x3f800000;
  local_9c[1] = 0x3f800000;
  local_9c[2] = 0x3f800000;
  local_9c[3] = 0x3f000000;
  local_9c[4] = 0x3f000000;
  local_9c[5] = 0x3f000000;
  puVar3 = local_9c;
  puVar2 = param_1 + 0xf;
  for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar2 = puVar2 + 1;
  }
  local_9c[0x1a] = 0x3f800000;
  local_9c[0x1b] = 0x3f800000;
  local_9c[0x1c] = 0x3f800000;
  local_9c[0x1d] = 0x3f000000;
  local_9c[0x1e] = 0x3f000000;
  local_9c[0x1f] = 0x3f000000;
  puVar3 = local_9c + 0x1a;
  puVar2 = param_1 + 0x1f;
  for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar2 = puVar2 + 1;
  }
  param_1[0x1c] = 0x3f000000;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
