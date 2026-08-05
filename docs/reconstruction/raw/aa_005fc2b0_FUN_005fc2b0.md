# Raw capture: FUN_005fc2b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fc2b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005fc2b0` |
| **Canonical name** | `FUN_005fc2b0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_005fc2b0(void)

{
  int iVar1;
  undefined1 auStack_b8 [148];
  void *pvStack_24;
  void *pvStack_1c;
  undefined1 *puStack_18;
  undefined4 uStack_14;
  
  uStack_14 = 0xffffffff;
  puStack_18 = &LAB_009a7bde;
  pvStack_1c = ExceptionList;
  ExceptionList = &pvStack_1c;
  FUN_00649e70();
  iVar1 = (**(code **)(*DAT_00b05060 + 0x10))(0xc0,0x2e);
  *(undefined2 *)(iVar1 + 4) = 0xc0;
  pvStack_1c = (void *)0x0;
  FUN_0064a1b0(auStack_b8);
  ExceptionList = pvStack_24;
  return;
}
```
