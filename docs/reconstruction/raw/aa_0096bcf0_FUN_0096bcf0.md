# Raw capture: FUN_0096bcf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096bcf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0096bcf0` |
| **Canonical name** | `FUN_0096bcf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

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
