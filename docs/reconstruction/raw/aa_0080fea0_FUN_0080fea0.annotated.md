# Annotated low-level: FUN_0080fea0

| Field | Value |
|---|---|
| Stable ID | `aa_0080fea0` |
| VA | `0x0080fea0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0080fea0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0080fea0(int param_1)

{
  int in_EAX;
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  FUN_007a69d0();
  if (*(char *)(param_1 + 4) == '\0') {
    uVar4 = 0;
    uVar3 = 1;
    uVar2 = 0xffffffff;
    uVar1 = FUN_007a6de0("The server is not accepting logins at this time. Please try again in a few moments..."
                         ,0xffffffff);
    FUN_007fdfb0(in_EAX,uVar1,uVar2,uVar3,uVar4);
  }
  else {
    FUN_00937560(in_EAX);
    if (*(int *)(in_EAX + 0xf38) != 0) {
      FUN_00920050();
      return;
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
