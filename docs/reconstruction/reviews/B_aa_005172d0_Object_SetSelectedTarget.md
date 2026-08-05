# Review B (skeptical / adversarial): `aa_005172d0` Object_SetSelectedTarget

| Field | Value |
|---|---|
| **Stable ID** | `aa_005172d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005172d0_Object_SetSelectedTarget.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | “Always writes `+0xA0` when arg differs” | Missing world or null `world+0xE4EC` exits **before** any store | **Falsified if over-read** — silent no-op leaves old target |
| 2 | Decompiler shows list remove with no `this` | Asm loads **`[esi+0xB0]` → ECX** before call | **Decomp bug** — list is `entity+0xB0`, not phantom |
| 3 | `FUN_00604db0(pAction)` unary | Asm **`push partner; mov ecx,this; call`** twice, swapped | **Falsified unary** — mutual partner write at `+0x24` |
| 4 | “Set target” is pure pointer store | Also net dirty, list purge, dual HB construct/enqueue | **Under-specified if store-only** |
| 5 | Clears always allocate HB pair | `new==0` or `new==self` skip allocs after store/purge | **Falsified** |
| 6 | `__stdcall` / `__cdecl` | `ret 4` + ECX this | **Falsified** — `__thiscall` one stack arg |
| 7 | Scaffold clean ≡ retail | Scaffold omitted `+0xB0` ECX and cross-link args | **Prior clean incomplete** — refined three-rep required |
| 8 | Early write is redundant dead code | Only when old≠0; purge may observe mid-destroy; still sealed | **Motive open**; behavior real |
| 9 | Self HB and target HB are same class | Self: `00512090` overrides vtbl to `009cdfd4`; target: `00604d40` keeps `009cdfb0` | **Different subclasses** — RTTI destroy only matches PlayerTargetingLink |
| 10 | Name is product-confirmed | No method string; RTTI only on link class | **Inferred name** — keep `_Inferred` awareness |
| 11 | Return value meaningful | Void path; EAX not defined for caller | **void** (analyze_function warned on raw `undefined` sig — fixed intent void) |
| 12 | Enqueue is immediate TryFire | `CVOGHBList_Enqueue` is pending-only (sibling dual) | **Caller residual** — not this unit’s fire |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI thiscall + ret 4 | **High** | Wrong stack cleanup / arg order |
| `+0xA0` selected target | **High** | Combat AI / skills aim wrong entity |
| World/`+0xE4EC` gate before write | **High** | Port always-writes vs retail no-op |
| `+0xB0` list purge + RTTI class | **High** | Leaked targeting HBs / wrong list |
| Dual HB + partner `+0x24` + enqueue order | **High** | Broken mutual targeting pulse |
| Net mask bit 4 meaning | **Tentative** | Ghost desync field wrong |
| Product name | **Tentative** | Naming only |
| Early-write purpose | **Tentative** | Overfit narrative |
| Period/flags on target HB (1000 ms etc.) | **High on callee** | Mis-tune if reimplemented without callee |

---

## 3. Cross-check against raw / pcode / memory

```
raw scaffold decompile:
  if (param_2 != *(param_1+0xa0)) {
    if (world && world->list) {
      NetObject_SetMaskBits(...);
      early write if old;
      CNDDoubleList_Invoke...(FUN_005121d0,0,0);  // this MISSING in raw text
      store +0xa0;
      dual new / FUN_00604db0 unary / enqueue
    }
  }

asm / read_memory:
  ECX this, EDI = arg, ESI = this copy
  +0xB0 → ECX before CNDDoubleList call  // seals missing this
  FUN_00604db0: push partner; this=other; ×2 swapped
  ret 4 at 005173f8

pcode (high):
  INT_ADD ECX, 0xa0 / 0xa4 / 0x14 / 0xb0 confirmed via LOAD sites
  CALL NetObject_SetMaskBits const 4, 0
  CALL CNDDoubleList with predicate 0x005121d0
```

Clean **must not** invent null-entity guards (retail crashes on null this) or write `+0xA0` when world/list gate fails.

---

## 4. Surviving contract for AutoCore

```csharp
// Retail aa_005172d0 — inferred name Object_SetSelectedTarget
// thiscall: entity in ECX, newTarget on stack.
void SetSelectedTarget(ClonedObject entity, ClonedObject? newTarget)
{
    if (ReferenceEquals(newTarget, entity.SelectedTarget)) // +0xA0
        return;
    var world = entity.World; // +0xA4
    if (world == null || world.HbList == null) // +0xE4EC
        return; // leave SelectedTarget unchanged

    if (entity.NetObject != null) // +0x14
        entity.NetObject.SetMaskBits(mask: 4, clear: 0);

    if (entity.SelectedTarget != null)
        entity.SelectedTarget = newTarget; // early

    entity.HbActionList.InvokePredicateAndRemove( // +0xB0
        IsCvoGhbPlayerTargetingLinkAndDestroy);

    entity.SelectedTarget = newTarget;

    if (newTarget != null && !ReferenceEquals(newTarget, entity))
    {
        var selfLink = AllocAndCtorPlayerTargetingLink(entity);   // 0x28, 0x00512090
        var targetHb = AllocAndCtorTargetingHb(newTarget);        // 0x28, 0x00604d40
        LinkPartner(selfLink, targetHb);  // +0x24 both ways (0x00604db0)
        LinkPartner(targetHb, selfLink);
        world.HbList.Enqueue(selfLink);
        world.HbList.Enqueue(targetHb);
    }
}
```

---

## 5. Residual gaps (do not over-seal)

1. Product identifiers for fields and method.
2. Ghost mask bit 4 payload / pack path.
3. Tick body of PlayerTargetingLink after enqueue.
4. Early-write reentrancy story.
5. Live CE / runtime capture.
6. Whether null `operator_new` leaves one-sided partner links (retail still enqueues nulls — Enqueue returns E_INVALIDARG on null per sibling dual).

**Verdict:** **accept-with-gaps**
