# Dual A/B — `aa_005172d0` Object_SetSelectedTarget

**Date:** 2026-07-29  
**Owned VA:** `0x005172d0` only  
**Tools:** Ghidra `decompile_function` / `read_memory` / high pcode / callers / callees / rename + plate (no Launcher; no WORK_QUEUE/RESUME/ACTIVE_WORK/CHANGE_LOG)  
**Verdict:** **accept-with-gaps**

---

## Sealed facts

### Role

| Fact | Evidence |
|---|---|
| Set **selected target** pointer at **`entity+0xA0`** | Asm compare/store; AI/net/input callers |
| No-op if new == current | Entry `cmp`/`je` |
| **Silent no-op** (no store) if `entity+0xA4==0` or `world+0xE4EC==0` | Dual early exits |
| Dirties **`NetObject_SetMaskBits(entity+0x14, 4, 0)`** when net non-null | `push 0; push 4` |
| Purges **`CVOGHBPlayerTargetingLink`** from **`entity+0xB0`** | `mov ecx,[esi+0xB0]`; predicate RTTI |
| Dual HB on non-null non-self: self `0x00512090`, target `0x00604d40`, size **0x28** | Alloc + ctors |
| Partner cross-link **`FUN_00604db0`** both ways (`+0x24`) | Asm push/ecx order |
| Enqueue self link then target HB on **`world+0xE4EC`** | Two `CVOGHBList_Enqueue` |
| ABI **`__thiscall`**, **`ret 4`**, body **`005172d0`–`005173f9`** | Hex tail `C2 04 00` |

### Signature

```c
void __thiscall Object_SetSelectedTarget(void *pEntity, void *pNewTarget);
// Name INFERRED — product string not recovered
```

### Algorithm (authoritative)

```
if newTarget == entity[+0xA0]: return
if entity[+0xA4]==0 or world[+0xE4EC]==0: return   // no write
optional NetObject_SetMaskBits(entity[+0x14], 4, 0)
if entity[+0xA0] != 0: entity[+0xA0] = newTarget    // early
CNDDoubleList_InvokePredicateAndRemove(entity[+0xB0], IsPlayerTargetingLink)
entity[+0xA0] = newTarget
if newTarget != 0 and newTarget != entity:
    selfLink  = new(0x28)? PlayerTargetingLink_ctor(entity) : null
    targetHb  = new(0x28)? TargetingHb_ctor(newTarget) : null
    LinkPartner(selfLink, targetHb); LinkPartner(targetHb, selfLink)
    Enqueue(world.hbList, selfLink); Enqueue(world.hbList, targetHb)
```

### Decomp defects closed

1. List **`this` = entity+0xB0** (not missing).
2. **`FUN_00604db0` binary** mutual partner, not unary.

### Call surface

| Metric | Value |
|---|---|
| Xrefs | **30** |
| Named callers | AI find-target, drive input tick, ghost/vehicle unpack, reactions/clears, etc. |

### Port implication

Do **not** write selected target when world/HB list is absent. Clear path (`newTarget==0`) still purges targeting links when gates pass. Dual HB is mutual; enqueue is pending (see `CVOGHBList_Enqueue` dual).

---

## Gaps

1. Product method/field names.
2. Net mask bit **4** ghost field mapping.
3. Targeting HB tick behavior after enqueue.
4. Early-write reentrancy motive.
5. Runtime / bit-exact verification.
6. Null `operator_new` partial-pair enqueue behavior (Enqueue null → E_INVALIDARG per sibling).

---

## Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_005172d0_Object_SetSelectedTarget.md` | accept-with-gaps |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_005172d0_Object_SetSelectedTarget.md` | accept-with-gaps |

---

## Files touched / authoritative

| Role | Absolute path |
|---|---|
| Dual A | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\A_aa_005172d0_Object_SetSelectedTarget.md` |
| Dual B | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\B_aa_005172d0_Object_SetSelectedTarget.md` |
| Function record | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_005172d0_Object_SetSelectedTarget.md` |
| Raw | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_005172d0_Object_SetSelectedTarget.md` |
| Annotated | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_005172d0_Object_SetSelectedTarget.annotated.md` |
| Clean | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\Object_SetSelectedTarget.cpp` |
| This report | `C:\Users\josh\Documents\GitHub\AutoCore\docs\agents\task-dual-ab-005172d0-object-setselectedtarget-report.md` |

Legacy scaffold (superseded for dual):  
`docs/reconstruction/functions/aa_005172d0_FUN_005172d0.md`,  
`docs/reconstruction/raw/aa_005172d0_FUN_005172d0*.md`,  
`docs/reconstruction/reconstructed-exact/FUN_005172d0.cpp` — prefer **Object_SetSelectedTarget** paths.

Ghidra: renamed `FUN_005172d0` → `Object_SetSelectedTarget`; plate + prototype set.

---

## AutoCore port sketch

```csharp
/// <summary>Retail aa_005172d0: set selected target +0xA0 with targeting-link HB pair.</summary>
public void SetSelectedTarget(ClonedObject? newTarget)
{
    if (ReferenceEquals(newTarget, SelectedTarget)) return;
    if (World == null || World.HbList == null) return;

    NetObject?.SetMaskBits(4, 0);
    if (SelectedTarget != null)
        SelectedTarget = newTarget;

    HbActionList.RemoveWhereIsPlayerTargetingLink();
    SelectedTarget = newTarget;

    if (newTarget == null || ReferenceEquals(newTarget, this))
        return;

    var selfLink = CvoGhbPlayerTargetingLink.Create(this);
    var targetHb = CvoGhbTargeting.Create(newTarget);
    selfLink.LinkPartner(targetHb);
    targetHb.LinkPartner(selfLink);
    World.HbList.Enqueue(selfLink);
    World.HbList.Enqueue(targetHb);
}
```
