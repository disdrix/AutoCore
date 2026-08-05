# Annotated low-level: FUN_0096bcf0

| Field | Value |
|---|---|
| Stable ID | `aa_0096bcf0` |
| VA | `0x0096bcf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0096bcf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0096bcf0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_ESI;
  
  uVar2 = param_1;
  iVar1 = NDResource_AcquireInnerObject();
  if (iVar1 == unaff_ESI) {
    *(undefined4 *)(unaff_ESI + 0x4c) = uVar2;
    FUN_00745ea0();
    return;
  }
  uVar2 = FUN_0076cec0(&param_1,"Setting asset handle for <%x> to an unrelated asset <%x>.");
  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effTextureImpl.cpp",0x507,
                 5,uVar2);
  FUN_00745ea0();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
