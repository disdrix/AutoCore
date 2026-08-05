# Annotated low-level: Client_RefreshMissionDialogChrome

| Field | Value |
|---|---|
| Stable ID | `aa_009306a0` |
| VA | `0x009306a0` |
| System | missions-progression |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_009306a0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Client_RefreshMissionDialogChrome
   
   If dialog chrome at game+0x10b0 is open, call FUN_008a05a0 to refresh it. */

void Client_RefreshMissionDialogChrome(void)

{
  char cVar1;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x10b0) != 0) {
    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x10b0) + 0x3d8))();
    if (cVar1 != '\0') {
      FUN_008a05a0();
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
