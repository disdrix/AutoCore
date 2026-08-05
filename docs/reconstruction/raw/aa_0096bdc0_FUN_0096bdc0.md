# Raw capture: FUN_0096bdc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096bdc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0096bdc0` |
| **Canonical name** | `FUN_0096bdc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

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
