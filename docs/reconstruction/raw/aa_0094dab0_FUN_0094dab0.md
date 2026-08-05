# Raw capture: FUN_0094dab0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0094dab0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0094dab0` |
| **Canonical name** | `FUN_0094dab0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0094dab0(void)

{
  int iVar1;
  undefined4 *puVar2;
  int in_EAX;
  
  if ((*(int *)(in_EAX + 0xe98) != 0) &&
     (iVar1 = *(int *)(*(int *)(in_EAX + 0xe98) + 0xcb0), iVar1 != 0)) {
    FUN_004bb970(1,*(undefined4 *)(iVar1 + 0x160),*(undefined4 *)(iVar1 + 0x164));
    FUN_00575200();
    puVar2 = *(undefined4 **)(*(int *)(in_EAX + 0xe98) + 0xcb0);
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)*puVar2)(1);
    }
    FUN_00520330(0);
    if (*(int *)(in_EAX + 0x10a0) != 0) {
      FUN_008ea880();
      FUN_008e8b50(0xffffffff,0xffffffff,1);
    }
  }
  return;
}
```
