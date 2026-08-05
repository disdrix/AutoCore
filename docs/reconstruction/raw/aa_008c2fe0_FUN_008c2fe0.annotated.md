# Annotated low-level: FUN_008c2fe0

| Field | Value |
|---|---|
| Stable ID | `aa_008c2fe0` |
| VA | `0x008c2fe0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008c2fe0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 FUN_008c2fe0(void)

{
  char cVar1;
  int unaff_EDI;
  undefined4 local_8;
  undefined1 local_4;
  undefined1 local_3;
  undefined1 local_2;
  
  if (((DAT_00d1a8f6 == '\0') && (*(int *)(unaff_EDI + 0x580) != 0)) &&
     (*(int *)(*(int *)(unaff_EDI + 0x580) + 0x56c) != 0)) {
    cVar1 = FUN_00572ef0(*(undefined1 *)(unaff_EDI + 0x521));
    if (cVar1 != '\0') {
      *(undefined *)(*(int *)(unaff_EDI + 0x580) + 0x564) =
           (&DAT_00d17768)[*(int *)(unaff_EDI + 0x50c) * 4];
      FUN_00860700();
      local_2 = *(undefined1 *)(unaff_EDI + 0x521);
      local_4 = *(undefined1 *)(unaff_EDI + 0x50c);
      local_8 = 0x204a;
      local_3 = 0;
      Client_SendSectorPacket(&DAT_00d1a840,8,&local_8);
      return 1;
    }
  }
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
