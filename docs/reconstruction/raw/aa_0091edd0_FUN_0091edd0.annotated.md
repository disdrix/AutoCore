# Annotated low-level: FUN_0091edd0

| Field | Value |
|---|---|
| Stable ID | `aa_0091edd0` |
| VA | `0x0091edd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0091edd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0091edd0(int param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  pcVar1 = "Contact Interrupted!";
  FUN_007a69d0("Contact Interrupted!",0xffffffff);
  uVar2 = FUN_007a6de0(pcVar1,uVar2);
  if (DAT_00d1b8dc != 0) {
    FUN_008f8200(DAT_00d1b8dc,0x18,&DAT_00a156cc,uVar2,0);
  }
  *(undefined4 *)(param_1 + 0xc24) = 0;
  FUN_007fb640();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
