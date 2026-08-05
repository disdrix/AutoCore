# Raw capture: StdMap_LowerBoundByIntKey_INFERRED

| Field | Value |
|---|---|
| **Stable ID** | `aa_004054f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004054f0` |
| **Canonical name** | `StdMap_LowerBoundByIntKey_INFERRED` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* StdMap_LowerBoundByIntKey_INFERRED
   
   INFERRED MSVC std::map lower_bound for int keys.
   this = map object; writes *ppOutNode to matching node or end sentinel.
   Used by Experience_GetCumulativeThreshold and LevelUp table lookups.
   Dependency of session XP RE only — not fully verified against STL symbols. */

void __thiscall StdMap_LowerBoundByIntKey_INFERRED(void *this,void **ppOutNode,int *pKey)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)((int)this + 4);
  if (*(char *)((int)puVar3[1] + 0x1d) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      if ((int)puVar1[3] < *pKey) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x1d) == '\0');
  }
  if ((puVar3 != *(undefined4 **)((int)this + 4)) && ((int)puVar3[3] <= *pKey)) {
    *ppOutNode = puVar3;
    return;
  }
  *ppOutNode = *(undefined4 **)((int)this + 4);
  return;
}
```
