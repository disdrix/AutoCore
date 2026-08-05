# Annotated low-level: FUN_0083edd0

| Field | Value |
|---|---|
| Stable ID | `aa_0083edd0` |
| VA | `0x0083edd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0083edd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0083edd0(void)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *unaff_ESI;
  
  pcVar2 = unaff_ESI;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iVar3 = (int)pcVar2 - (int)(unaff_ESI + 1);
  if ((0 < iVar3) && (unaff_ESI[iVar3 + -1] == '\n')) {
    unaff_ESI[iVar3 + -1] = '\0';
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
