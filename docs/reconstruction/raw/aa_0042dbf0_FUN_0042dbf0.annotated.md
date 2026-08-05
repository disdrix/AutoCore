# Annotated low-level: FUN_0042dbf0

| Field | Value |
|---|---|
| Stable ID | `aa_0042dbf0` |
| VA | `0x0042dbf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0042dbf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0042dbf0(undefined4 param_1)

{
  char cVar1;
  int in_EAX;
  int iVar2;
  
  cVar1 = FUN_00974620(in_EAX + 0x14c,in_EAX + 0x138,in_EAX + 0x140,*(undefined4 *)(in_EAX + 0x148))
  ;
  if (cVar1 != '\0') {
    iVar2 = FUN_007833a0();
    FUN_00783aa0("Client puzzle solved in %d ms.",iVar2 - *(int *)(in_EAX + 0x1a4));
    *(undefined4 *)(in_EAX + 0x1b8) = 4;
    FUN_0042dc60(param_1);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
