# Raw capture: InventoryGrid_SetOwnerFlag_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00570600` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00570600` |
| **Canonical name** | `InventoryGrid_SetOwnerFlag_Inferred` |
| **System** | inventory-transfer |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* InventoryGrid_SetOwnerFlag_Inferred — write int flag at grid+0x4.
   
   Parameters: this grid; nFlag (cargo path always passes 1 after ctor).
   Returns: void.
   
   Trivial setter. Name INFERRED from cargo create call site only. */

void __thiscall InventoryGrid_SetOwnerFlag_Inferred(void *this,int nFlag)

{
  *(int *)((int)this + 4) = nFlag;
  return;
}
```
