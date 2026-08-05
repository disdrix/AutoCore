# Annotated low-level: BitStream_readFlag

| Field | Value |
|---|---|
| Stable ID | `aa_0042ad50` |
| VA | `0x0042ad50` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0042ad50`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
bool __thiscall BitStream_readFlag(int param_1,undefined1 *param_2)

{
  byte bVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x18);
  if (*(uint *)(param_1 + 0x2c) < uVar2) {
    *(undefined1 *)(param_1 + 0x1c) = 1;
    *param_2 = 0;
    return *(char *)(param_1 + 0x1c) == '\0';
  }
  bVar1 = *(byte *)((uVar2 >> 3) + *(int *)(param_1 + 0xc));
  *(uint *)(param_1 + 0x18) = uVar2 + 1;
  *param_2 = (bVar1 & (byte)(1 << ((byte)uVar2 & 7))) != 0;
  return *(char *)(param_1 + 0x1c) == '\0';
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
