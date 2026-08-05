# Raw capture: FUN_005d8fc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d8fc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005d8fc0` |
| **Canonical name** | `FUN_005d8fc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_005d8fc0(undefined4 param_1)

{
  int iVar1;
  undefined4 unaff_retaddr;
  undefined4 uVar2;
  
  uVar2 = 0xc;
  iVar1 = (**(code **)(*DAT_00b05060 + 0x10))(0x68,0xc);
  if (iVar1 != 0) {
    uVar2 = FUN_005d89f0(uVar2,unaff_retaddr,param_1);
    return uVar2;
  }
  return 0;
}
```
