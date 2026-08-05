# Annotated low-level: FUN_0096bdc0

| Field | Value |
|---|---|
| Stable ID | `aa_0096bdc0` |
| VA | `0x0096bdc0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0096bdc0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 FUN_0096bdc0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EDI;
  
  if (((byte)*(undefined4 *)(unaff_EDI + 0x2c) & 0xf) != 1) {
    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effTextureImpl.cpp",
                   0x434,3);
    return 0xffffffff;
  }
  iVar1 = D3DXComputeNormalMap
                    (*(undefined4 *)(unaff_EDI + 0x10),*(undefined4 *)(param_1 + 0x10),0,param_3,
                     param_4,param_2);
  if (iVar1 < 0) {
    uVar2 = FUN_006b7a5a(iVar1,"Cannot compute normal map from texture");
    uVar2 = FUN_006a5dac(iVar1,uVar2);
    uVar2 = FUN_0076cec0(&stack0xfffffffc,"%s - %s\r\n%s",uVar2);
    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effTextureImpl.cpp",
                   0x43c,3,uVar2);
    return 0xffffffff;
  }
  *(byte *)(unaff_EDI + 0x2d) = *(byte *)(unaff_EDI + 0x2d) | 2;
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
