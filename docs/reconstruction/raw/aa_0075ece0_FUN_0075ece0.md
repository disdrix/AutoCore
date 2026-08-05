# Raw capture: FUN_0075ece0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075ece0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0075ece0` |
| **Canonical name** | `FUN_0075ece0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

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
