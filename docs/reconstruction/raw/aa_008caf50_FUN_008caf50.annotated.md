# Annotated low-level: FUN_008caf50

| Field | Value |
|---|---|
| Stable ID | `aa_008caf50` |
| VA | `0x008caf50` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008caf50`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_008caf50(void)

{
  int in_EAX;
  undefined1 *puVar1;
  int iVar2;
  
  *(undefined4 *)(in_EAX + 0x558) = 0;
  puVar1 = (undefined1 *)(in_EAX + 0x574);
  iVar2 = 0x10;
  do {
    *(undefined4 *)(puVar1 + -0x10) = 0xffffffff;
    *puVar1 = 0;
    *(undefined2 *)(puVar1 + -8) = 0;
    puVar1 = puVar1 + 0x3c;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
