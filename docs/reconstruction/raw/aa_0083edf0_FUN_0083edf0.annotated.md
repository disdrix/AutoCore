# Annotated low-level: FUN_0083edf0

| Field | Value |
|---|---|
| Stable ID | `aa_0083edf0` |
| VA | `0x0083edf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0083edf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0083edf0(void)

{
  int in_EAX;
  int iVar1;
  int *unaff_EBX;
  int *piVar2;
  int *piVar3;
  
  unaff_EBX[0x145] = in_EAX;
  if (in_EAX == 0) {
    *(undefined1 *)(unaff_EBX + 0x13f) = 0;
  }
  else {
    piVar2 = (int *)(in_EAX + 0x24);
    piVar3 = unaff_EBX + 0x146;
    for (iVar1 = 0x18c; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar3 = *piVar2;
      piVar2 = piVar2 + 1;
      piVar3 = piVar3 + 1;
    }
    *(undefined1 *)(unaff_EBX + 0x13f) = 1;
  }
  (**(code **)(*unaff_EBX + 0x444))();
                    /* WARNING: Could not recover jumptable at 0x0083ee2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*unaff_EBX + 0x34c))();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
