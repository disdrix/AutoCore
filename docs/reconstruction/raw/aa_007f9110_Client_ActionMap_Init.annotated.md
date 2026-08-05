# Annotated low-level: Client_ActionMap_Init

| Field | Value |
|---|---|
| Stable ID | `aa_007f9110` |
| VA | `0x007f9110` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007f9110`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* ActionMap ctor/init: zero tables, Client_InitActionDisplayNames, Client_InitDefaultKeybinds. Slot
   stride 0x34. Called from FUN_009495c0. */

void Client_ActionMap_Init(void)

{
  int iVar1;
  undefined4 *unaff_ESI;
  undefined4 *puVar2;
  
  *unaff_ESI = &PTR_LAB_00a84e08;
  puVar2 = (undefined4 *)((int)unaff_ESI + 6);
  for (iVar1 = 0x41; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = (undefined4 *)((int)unaff_ESI + 0x10a);
  for (iVar1 = 0x4e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = (undefined4 *)((int)unaff_ESI + 0x242);
  for (iVar1 = 0x618; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = (undefined4 *)((int)unaff_ESI + 0x1aa2);
  for (iVar1 = 0x104; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  Client_InitActionDisplayNames();
  Client_InitDefaultKeybinds();
  *(undefined1 *)((int)unaff_ESI + 5) = 0;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
