# Raw capture: FUN_0091edd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0091edd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0091edd0` |
| **Canonical name** | `FUN_0091edd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0091edd0(int param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  pcVar1 = "Contact Interrupted!";
  FUN_007a69d0("Contact Interrupted!",0xffffffff);
  uVar2 = FUN_007a6de0(pcVar1,uVar2);
  if (DAT_00d1b8dc != 0) {
    FUN_008f8200(DAT_00d1b8dc,0x18,&DAT_00a156cc,uVar2,0);
  }
  *(undefined4 *)(param_1 + 0xc24) = 0;
  FUN_007fb640();
  return;
}
```
