# Raw capture: FUN_005c0ee0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c0ee0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005c0ee0` |
| **Canonical name** | `FUN_005c0ee0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_005c0ee0(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  *(int *)(*(int *)(param_1 + 200) + *(int *)(param_1 + 0xcc) * 4) = param_3;
  *(int *)(param_1 + 0xcc) = *(int *)(param_1 + 0xcc) + 1;
  *(int *)(param_3 + 200) = param_1;
  iVar1 = CVOGTerrainChunk_BuildVertexBuffer
                    (param_2,*(undefined4 *)(param_2 + 0x18),*(undefined4 *)(param_1 + 0xd0));
  *(int *)(param_1 + 0xd4) = *(int *)(param_1 + 0xd4) + iVar1;
  *(int *)(param_1 + 0xd0) = *(int *)(param_1 + 0xd0) + iVar1 * 0x28;
  return *(undefined4 *)(param_1 + 0xd4);
}
```
