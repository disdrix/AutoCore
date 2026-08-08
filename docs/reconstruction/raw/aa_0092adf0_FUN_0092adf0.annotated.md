# Annotated low-level: TargetFilter_FindNearestWorldObjByCbidList_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_0092adf0` |
| VA | `0x0092adf0` |
| System | skills-abilities / inventory-transfer (adjacent) |
| Date | 2026-08-04 (WQ8R-I dual seal) |
| Ghidra | `FUN_0092adf0` |

## Machine-level notes

- **EDI** = target-filter context; `*EDI` = **client***.
- Stack formals: origin `float3*`, best-object out `void**`, best squared-distance `float*` (in/out min).
- **`ret 0x0C`**; returns **1**.
- List walk: TraversalLock `FUN_004294f0` + IterateNext `FUN_004022a0` (same family as other inventory/world list walkers).
- **Inventory consumer:** `InventoryGrid_FindItemByCoid` on **`*(character+0xCBC)`** (locker / type-3 grid plate). Continues only when COID **absent**.
- Self-exclude: this-adjusted `*(character+0x250)` vs `object+0xAC`.
- CBID match: whitelist at `ctx+0x2C[0 .. count-1]`, count `ctx+0x28`, vs `*(clonebase+0x34)`.
- Nearest: after vtbl `+0x144`, squared Euclidean on `object+0x80/+0x84/+0x88` vs origin; update if `< *bestDistSq`.

## Pseudocode (annotated)

```c
// EDI = TargetFilterCtx*  (*ctx = Client*)
// ret 0x0C; returns 1
uint32_t TargetFilter_FindNearestWorldObjByCbidList_Inferred(
    float *origin,      // xyz
    void **bestOut,     // nearest matching Object*
    float *bestDistSq)  // in/out current minimum
{
  Object *obj;
  int iterRc;
  void *lockState[/*local_14*/];
  Object *iterOut = NULL;

  lockState[0] = 0;
  TraversalLock(/* from client list mgr */);
  iterRc = IterateNext(lockState, &iterOut);
  obj = iterOut;

  while (iterRc == 0) {
    if (obj != NULL) {
      Character *ch = *(Character **)(*ctx /*EDI*/ + 0xE98);
      void *selfAdj = NULL;
      void *host = *(void **)((char *)ch + 0x250);
      if (host != NULL) {
        // C++ multiple-inheritance this-adjust
        selfAdj = (char *)host + *(int *)(*(int *)((char *)host + 4) + 4) + 4;
      }
      // Skip local player; require object COID not in locker grid
      InventoryGrid *locker = *(InventoryGrid **)((char *)ch + 0xCBC);
      if (obj->field_AC != selfAdj
          && InventoryGrid_FindItemByCoid(locker, obj->coidLo, obj->coidHi) == NULL
          && ctx->cbidCount /*+0x28*/ > 0) {
        int *cbidList = &ctx->cbidArray0; // +0x2C
        for (int i = 0; i < ctx->cbidCount; ++i) {
          if (cbidList[i] == *(int *)(obj->clonebase /*+0xA8*/ + 0x34)) {
            obj->vtbl[+0x144](); // refresh pos / ensure world data
            float dx = obj->posX - origin[0];
            float dy = obj->posY - origin[1];
            float dz = obj->posZ - origin[2];
            float d2 = dx*dx + dy*dy + dz*dz;
            if (d2 < *bestDistSq) {
              *bestDistSq = d2;
              *bestOut = obj;
            }
          }
        }
      }
    }
    iterRc = IterateNext(lockState, &iterOut);
    obj = iterOut;
  }

  // Unlock world-object list CS on client
  void *csHost = *(void **)(*(void **)(*ctx + 0xD34) + 0x20);
  if (*(char *)((char *)csHost + 0x28) != 0) {
    *(char *)((char *)csHost + 0x28) = 0;
    LeaveCriticalSection((char *)csHost + 4);
  }
  return 1;
}
```

## Field plate (object)

| Offset | Index | Role |
|---|---|---|
| `+0xA8` | `[0x2a]` | clonebase* |
| `+0xAC` | `[0x2b]` | identity / owner compare (self exclude) |
| `+0x160/+0x164` | `[0x58]/[0x59]` | COID lo/hi |
| `+0x80/+0x84/+0x88` | `[0x20..0x22]` | position floats (after vtbl+0x144) |

## Open / residual

- Product English for filter-ctx class (skill vs reaction vs interact).
- Why **locker** grid (`+0xCBC`) rather than cargo (`host+0x2B0`) for absence gate.
- Exact semantic of vtbl `+0x144`.
- Runtime / bit-exact.
