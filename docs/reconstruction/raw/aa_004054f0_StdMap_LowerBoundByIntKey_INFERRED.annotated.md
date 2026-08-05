# Annotated low-level: StdMap_LowerBoundByIntKey_INFERRED

| Field | Value |
|---|---|
| Stable ID | `aa_004054f0` |
| VA | `0x004054f0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004054f0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

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

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
