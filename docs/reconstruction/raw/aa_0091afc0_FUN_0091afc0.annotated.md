# Annotated low-level: FUN_0091afc0

| Field | Value |
|---|---|
| Stable ID | `aa_0091afc0` |
| VA | `0x0091afc0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0091afc0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0091afc0(void)

{
  int iVar1;
  int *unaff_ESI;
  
  if (unaff_ESI[0x31e] != 0) {
    (**(code **)(*unaff_ESI + 0xb0))(unaff_ESI[0x31e]);
    (**(code **)(*(int *)unaff_ESI[0x31e] + 0x440))();
    if ((undefined4 *)unaff_ESI[0x31e] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)unaff_ESI[0x31e])(1);
    }
    unaff_ESI[0x31e] = 0;
    FUN_00720d40();
    FUN_00720460();
    (**(code **)(*unaff_ESI + 0x3ec))();
    unaff_ESI[0x1a] = unaff_ESI[0x1a] + -1;
    iVar1 = unaff_ESI[0x1a];
    unaff_ESI[0x1d] = (int)(float)-iVar1;
    if (unaff_ESI[0x1c] < iVar1) {
      unaff_ESI[0x1c] = iVar1;
    }
    (**(code **)(*unaff_ESI + 0x3f4))(0xffffffff);
    *(undefined1 *)((int)unaff_ESI + 0xa36) = 0;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
