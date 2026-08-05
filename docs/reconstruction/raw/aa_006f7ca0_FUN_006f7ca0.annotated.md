# Annotated low-level: FUN_006f7ca0

| Field | Value |
|---|---|
| Stable ID | `aa_006f7ca0` |
| VA | `0x006f7ca0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006f7ca0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_006f7ca0(int param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int in_EAX;
  uint uVar4;
  uint *unaff_EBX;
  int iVar5;
  
  uVar4 = in_EAX >> 4;
  bVar3 = ~(byte)(uVar4 >> 3) & 1;
  bVar1 = ~(byte)(uVar4 >> 2) & 1;
  bVar2 = ~(byte)(uVar4 >> 1) & 1;
  if (param_1 != 0) {
    iVar5 = 1 << (bVar1 + bVar2 * '\x02') * '\x02';
    if ((*unaff_EBX & iVar5 * 2) == 0) {
      *unaff_EBX = *unaff_EBX + iVar5;
    }
  }
  if (param_1 != 1) {
    iVar5 = 1 << ((bVar3 + 4 + bVar2 * '\x02') * '\x02' & 0x1f);
    if ((*unaff_EBX & iVar5 * 2) == 0) {
      *unaff_EBX = *unaff_EBX + iVar5;
    }
  }
  if (param_1 != 2) {
    iVar5 = 1 << ((bVar3 + 8 + bVar1 * '\x02') * '\x02' & 0x1f);
    if ((*unaff_EBX & iVar5 * 2) == 0) {
      *unaff_EBX = *unaff_EBX + iVar5;
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
