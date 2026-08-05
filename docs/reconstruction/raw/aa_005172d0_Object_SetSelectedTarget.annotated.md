# Annotated low-level: Object_SetSelectedTarget

| Field | Value |
|---|---|
| Stable ID | `aa_005172d0` |
| VA | `0x005172d0` |
| System | object / combat-target / HB |
| Date | 2026-07-29 |

## Machine-level notes

- Source: live Ghidra decompile + full-body `read_memory` (300 bytes) for this dual A/B pass.
- Prefer assembly when decompiler conflicts (two confirmed defects: list `this` at `+0xB0`, dual partner args to `FUN_00604db0`).
- RTTI on purge predicate names the removed class **`CVOGHBPlayerTargetingLink`**.
- Related sibling duals: `CVOGHBList_Enqueue` (`0x005078f0`), list helper `0x004e2600`.

## Offsets

| Offset | Meaning (inferred) |
|---|---|
| `this+0x14` | NetObject* for ghost dirty |
| `this+0xA0` | Selected target object* |
| `this+0xA4` | World/map* |
| `this+0xB0` | CNDDoubleList of HB* (skill validate also uses target+0xB0) |
| `world+0xE4EC` | CVOGHBList* |

## Pseudocode (annotated, asm-corrected)

```c
// Object_SetSelectedTarget  @ 0x005172d0
// void __thiscall (entity* this, object* newTarget)  // ret 4
void __thiscall Object_SetSelectedTarget(void *entity, void *newTarget)
{
  CVOGHBBase *selfLink = NULL;   // PlayerTargetingLink on entity
  CVOGHBBase *targetHb;          // base targeting HB on newTarget
  void *mem;

  // SEH frame omitted

  if (newTarget == *(void **)((char *)entity + 0xA0))
    return; // unchanged

  void *world = *(void **)((char *)entity + 0xA4);
  if (world == NULL)
    return; // no write
  if (*(void **)((char *)world + 0xE4EC) == NULL)
    return; // no write

  void *net = *(void **)((char *)entity + 0x14);
  if (net != NULL)
    NetObject_SetMaskBits(net, /*mask*/ 4, /*arg*/ 0);

  // Early publish of new target when old was non-null (purge may observe +0xA0).
  if (*(void **)((char *)entity + 0xA0) != NULL)
    *(void **)((char *)entity + 0xA0) = newTarget;

  // Remove+destroy all CVOGHBPlayerTargetingLink nodes on entity's HB action list.
  CNDDoubleList_InvokePredicateAndRemove_Inferred(
      *(void **)((char *)entity + 0xB0),  // THIS — decomp omitted
      FUN_005121d0,                       // RTTI cast + vtbl+0x18(1,0) destroy
      0, 0);

  *(void **)((char *)entity + 0xA0) = newTarget; // always after purge

  if (newTarget == NULL || newTarget == entity)
    return; // clear or self: store done, no dual HB

  mem = operator_new(0x28);
  if (mem != NULL)
    selfLink = (CVOGHBBase *)FUN_00512090(mem, entity);
    // FUN_00512090: base FUN_00604d40(attach=entity) then vtbl = PlayerTargetingLink

  mem = operator_new(0x28);
  if (mem == NULL)
    targetHb = NULL;
  else
    targetHb = FUN_00604d40(mem, newTarget);
    // period 1000 ms, flags 2, Start()

  // Cross-link partners at HB+0x24 (decomp dropped 2nd args)
  FUN_00604db0(selfLink, targetHb);
  FUN_00604db0(targetHb, selfLink);

  CVOGHBList_Enqueue(*(void **)((char *)world + 0xE4EC), selfLink);
  CVOGHBList_Enqueue(*(void **)((char *)world + 0xE4EC), targetHb);
}
```

## Predicate `FUN_005121d0` (not owned)

```c
// return 1 = remove node; 0 = keep
if (dynamic_cast<CVOGHBPlayerTargetingLink*>(hb)) {
  hb->vtbl[0x18/4](1, 0); // destroy/release
  return 1;
}
return 0;
```

## Open questions

- Product names for `+0xA0` / method.
- Ghost field corresponding to mask bit value 4.
- Tick semantics of enqueued targeting pair.
- Early-write motive (reentrancy vs accidental double-store).
