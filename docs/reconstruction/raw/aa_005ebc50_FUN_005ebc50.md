# Raw capture: FUN_005ebc50

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ebc50` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005ebc50` |
| **Canonical name** | `FUN_005ebc50` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005ebc50(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0xc4) + -1;
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xcc);
  if (-1 < iVar3) {
    do {
      puVar1 = (undefined4 *)(*(int *)(param_1 + 0xc0) + iVar3 * 8);
      (**(code **)(*(int *)*puVar1 + 8))(param_1 + 0xc,puVar1[1],uVar2,param_2);
      iVar3 = iVar3 + -1;
    } while (-1 < iVar3);
  }
  return;
}
```
