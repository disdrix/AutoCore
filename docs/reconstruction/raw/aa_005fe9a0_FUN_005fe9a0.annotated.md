# Annotated low-level: FUN_005fe9a0

| Field | Value |
|---|---|
| Stable ID | `aa_005fe9a0` |
| VA | `0x005fe9a0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005fe9a0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_005fe9a0(int param_1,float param_2)

{
  short *psVar1;
  short sVar2;
  int iVar3;
  
  if ((param_2 <= DAT_009c8354) || (DAT_009d2f7c <= param_2)) {
    psVar1 = (short *)(param_1 + 0xb6);
    iVar3 = 6;
    do {
      sVar2 = (short)(int)((float)(int)*psVar1 * param_2);
      *psVar1 = sVar2;
      if (sVar2 < 0) {
        *psVar1 = 0;
      }
      psVar1 = psVar1 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
