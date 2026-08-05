# Annotated low-level: FUN_0069fac0

| Field | Value |
|---|---|
| Stable ID | `aa_0069fac0` |
| VA | `0x0069fac0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0069fac0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
char * FUN_0069fac0(void)

{
  char *pcVar1;
  char cVar2;
  char *in_EAX;
  int iVar3;
  char *unaff_EBX;
  
  iVar3 = isspace((int)*in_EAX);
  while (iVar3 != 0) {
    pcVar1 = in_EAX + 1;
    in_EAX = in_EAX + 1;
    iVar3 = isspace((int)*pcVar1);
  }
  sscanf(in_EAX,"%s");
  pcVar1 = unaff_EBX + 1;
  do {
    cVar2 = *unaff_EBX;
    unaff_EBX = unaff_EBX + 1;
  } while (cVar2 != '\0');
  return in_EAX + ((int)unaff_EBX - (int)pcVar1);
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
