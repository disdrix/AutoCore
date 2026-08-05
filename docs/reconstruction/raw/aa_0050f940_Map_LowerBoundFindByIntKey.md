# Raw capture: Map_LowerBoundFindByIntKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_0050f940` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0050f940` |
| **Canonical name** | `Map_LowerBoundFindByIntKey` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Map_LowerBoundFindByIntKey — ordered map lower_bound (INFERRED)
   
   Variant used by quest XP/credit lookups (node flag at +0x15 vs +0x1d
   in StdMap_LowerBoundByIntKey_INFERRED — slightly different node layout).
   INFERRED: both are MSVC std::map lower_bound for int keys.
   Session dependency for Mission_ComputeObjectiveXp. */

void __thiscall Map_LowerBoundFindByIntKey(void *this,void *pMap,void *pOutIt,int *pKey)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)((int)this + 4);
  if (*(char *)((int)puVar3[1] + 0x15) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      if ((int)puVar1[3] < *(int *)pOutIt) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x15) == '\0');
  }
  if ((puVar3 != *(undefined4 **)((int)this + 4)) && ((int)puVar3[3] <= *(int *)pOutIt)) {
    *(undefined4 **)pMap = puVar3;
    return;
  }
  *(undefined4 **)pMap = *(undefined4 **)((int)this + 4);
  return;
}
```
