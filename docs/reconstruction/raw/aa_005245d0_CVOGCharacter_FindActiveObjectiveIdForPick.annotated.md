# Annotated low-level: CVOGCharacter_FindActiveObjectiveIdForPick

| Field | Value |
|---|---|
| Stable ID | `aa_005245d0` |
| VA | `0x005245d0` |
| System | interaction-activation |
| Date | 2026-07-29 |

## Machine-level notes

- `__thiscall` on **character** (`param_1` / ECX); stack arg `param_2` = **world object**.
- Null world object → **0** (no hash walk).
- Active objectives hash root: `*(character + 0x548)` (`charActiveObjectivesHash`).
- Traversal lock byte: `hash + 0x1d` (assert strings HashError / VOG_DEBUG_STOP — **not** the function name).
- Node chain: first `*(hash + 0x14)`; next `*(node + 0x14)`; objective instance payload `*(node + 8)`.
- Match: `FUN_0059da10` with **this = objective instance** (ECX set to payload before call; Ghidra shows two stack formals = character + worldObject). Helper walks evaluators `[obj+0x158, obj+0x15c)` and calls **vtable+0x44**.
- On first true match: return `*(objective + 0x10)` = **objective id** (`objectiveDefId`).
- Exhaust / null payload: unlock and return **0**.
- Sibling `0x00524520` identical except `FUN_0059d9c0` / **vtable+0x40**.

## Pseudocode (annotated)

```c
// __thiscall Character* this, Object* worldObject → uint32 objectiveId or 0
undefined4 __thiscall FUN_005245d0(int character /*this*/, int worldObject)
{
  char match;
  undefined4 result;
  int node;
  int objInst;

  if (worldObject == 0) {
    return 0;
  }
  int hash = *(int *)(character + 0x548);   // active objectives hash
  node = 0;
  result = 0;
  // enter traversal lock
  if (*(char *)(hash + 0x1d) != '\0') {
    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");
    FUN_007a4480(0,"VOG_DEBUG_STOP");
  }
  *(undefined1 *)(hash + 0x1d) = 1;
  do {
    hash = *(int *)(character + 0x548);
    if (*(char *)(hash + 0x1d) == '\0') {
      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");
      FUN_007a4480(0,"VOG_DEBUG_STOP");
    }
    if (node == 0) {
      node = *(int *)(hash + 0x14);         // first node
    }
    else {
      node = *(int *)(node + 0x14);         // next
    }
    if (node == 0) {
      objInst = 0;
    }
    else {
      objInst = *(int *)(node + 8);         // payload = objective instance
    }
    if (objInst == 0) goto unlock;
    // ECX=objInst; stack (character, worldObject) → any eval vtbl+0x44 true?
    match = FUN_0059da10(character, worldObject);
  } while (match == '\0');
  result = *(undefined4 *)(objInst + 0x10); // objective id
unlock:
  *(undefined1 *)(*(int *)(character + 0x548) + 0x1d) = 0;
  return result;
}
```

## Callers (product roles)

| Site | Use of return |
|---|---|
| `Client_InteractClickPickTarget` `0x009247b0` | non-zero OR sibling non-zero → IfInteractable |
| `FUN_00925820` @ `0x00925cd4` | non-zero → select/highlight only (`FUN_0093e120`) |
| `FUN_00490070` pick filter | non-zero keeps type-1/3 candidate |

## Open

- Per-site character ECX provenance.
- Which requirement types implement non-trivial `vtable+0x44`.
- Runtime multi-objective first-wins order.
