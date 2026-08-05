# Annotated low-level: BitStream_writeFlag

| Field | Value |
|---|---|
| Stable ID | `aa_0042b770` |
| VA | `0x0042b770` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0042b770`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall BitStream_writeFlag(int param_1,char param_2)

{
  char cVar1;
  byte *pbVar2;
  byte bVar3;
  
  if (*(uint *)(param_1 + 0x30) < *(int *)(param_1 + 0x18) + 1U) {
    cVar1 = FUN_0042b450();
    if (cVar1 == '\0') {
      return;
    }
  }
  bVar3 = '\x01' << ((byte)*(uint *)(param_1 + 0x18) & 7);
  pbVar2 = (byte *)((*(uint *)(param_1 + 0x18) >> 3) + *(int *)(param_1 + 0xc));
  if (param_2 != '\0') {
    *pbVar2 = *pbVar2 | bVar3;
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
    return;
  }
  *pbVar2 = *pbVar2 & ~bVar3;
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
