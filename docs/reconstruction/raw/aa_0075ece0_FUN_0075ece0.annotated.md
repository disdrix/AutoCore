# Annotated low-level: FUN_0075ece0

| Field | Value |
|---|---|
| Stable ID | `aa_0075ece0` |
| VA | `0x0075ece0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0075ece0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 FUN_0075ece0(void)

{
  int iVar1;
  undefined4 *unaff_EDI;
  
  iVar1 = DAT_00d1f05c;
  if (unaff_EDI[0x1e9] == 1) {
    if (*(int *)(DAT_00d1f05c + 4) != 0) {
      FUN_0074f360();
      iVar1 = *(int *)(iVar1 + 0x144);
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0xc) = 0;
        *(undefined4 *)(iVar1 + 0x10) = 0xffffffff;
        *(undefined4 *)(iVar1 + 0x14) = 0xffffffff;
      }
    }
    iVar1 = (**(code **)(*(int *)*unaff_EDI + 0xa8))((int *)*unaff_EDI);
    if (iVar1 < 0) {
      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDevice.cpp",0x15b,3,
                     "EndScene() Failed");
      return 0xffffffff;
    }
  }
  unaff_EDI[0x1e9] = unaff_EDI[0x1e9] + -1;
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
