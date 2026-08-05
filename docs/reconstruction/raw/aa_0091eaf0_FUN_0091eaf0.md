# Raw capture: FUN_0091eaf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0091eaf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0091eaf0` |
| **Canonical name** | `FUN_0091eaf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0091eaf0(void)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_007fef20(0x1b,1,0);
  FUN_007fef20(0x1c,1,0);
  if (DAT_00d1a8e4 == '\0') {
    FUN_007fef20(0x1e,1,0);
    uVar2 = 0x21;
  }
  else {
    uVar2 = 0x1d;
  }
  FUN_007fef20(uVar2,1,0);
  FUN_007fef20(0x1f,1,0);
  FUN_007fef20(0x16,1,0);
  FUN_007fef20(0x22,1,0);
  FUN_007fef20(0x23,1,0);
  FUN_007fef20(0x2f,1,0);
  FUN_007fe1d0(1);
  FUN_007fef20(0x30,1,0);
  if (DAT_00d1b6d8 != 0) {
    iVar1 = FUN_004c3f10(1);
    if (iVar1 != 0) {
      FUN_007fef20(0x32,1,0);
    }
  }
  return;
}
```
