# Raw capture: FUN_0067ffb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0067ffb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0067ffb0` |
| **Canonical name** | `FUN_0067ffb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0067ffb0(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 != 0) &&
     ((uint)(*(int *)(param_1 + 8) - iVar1 >> 2) < (uint)(*(int *)(param_1 + 0xc) - iVar1 >> 2))) {
    puVar2 = *(undefined4 **)(param_1 + 8);
    *puVar2 = *param_2;
    *(undefined4 **)(param_1 + 8) = puVar2 + 1;
    return;
  }
  FUN_0067f930(*(undefined4 *)(param_1 + 8),1,param_2);
  return;
}
```
