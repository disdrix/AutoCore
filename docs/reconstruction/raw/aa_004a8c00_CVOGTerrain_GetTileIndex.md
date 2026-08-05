# Raw capture: CVOGTerrain_GetTileIndex

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a8c00` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004a8c00` |
| **Canonical name** | `CVOGTerrain_GetTileIndex` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* CVOGTerrain::GetTileIndex(x, y). Per-cell terrain tile layer = map TGA G channel & 7 (buffer at
   +0x3dc, stored column-major dim*x+y). Selects the atlas row (0-7) in tile2_*.dds. G's high 5 bits
   are not used here. */

uint __thiscall CVOGTerrain_GetTileIndex(int param_1,int param_2,int param_3)

{
  uint in_EAX;
  int iVar1;
  
  if ((((-1 < param_2) && (param_2 < *(int *)(param_1 + 0x10))) && (-1 < param_3)) &&
     (in_EAX = *(uint *)(param_1 + 0x14), param_3 < (int)in_EAX)) {
    iVar1 = in_EAX * param_2 + *(int *)(param_1 + 0x3dc);
    return CONCAT31((int3)((uint)iVar1 >> 8),*(undefined1 *)(iVar1 + param_3)) & 0xffffff07;
  }
  return in_EAX & 0xffffff00;
}
```
