# Review B (skeptical / adversarial): `aa_0040c700` List_TraversalUnlock

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040c700` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (WQ9D-E OWN-ONLY dual B) |
| **Counterpart** | `reviews/A_aa_0040c700_List_TraversalUnlock.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Always LeaveCS | Unconditional unlock | **Falsified** — gated on `+0x28 != 0` |
| 2 | Is Traversal**Lock** | Name swap | **Falsified** — LeaveCS + clear flag; lock is `0x004294f0` EnterCS + set flag |
| 3 | Is `List_IterateNext` | Iterator conflation | **Falsified** — no cursor/node walk |
| 4 | Skill-only status-effect helper | Scaffold alias bias | **Falsified** — 17 xrefs across list consumers |
| 5 | Same as InventoryGrid unlock | Offset skim | **Falsified** — grid helpers use CS `@+0x30` / flag `@+0x54` |
| 6 | Throws `0x80070005` when unlocked | Clear/Insert policy | **Falsified** — silent no-op when flag clear |
| 7 | Name invents “TraversalUnlock” | Symbol inflation | **Role holds** — exact inverse of string-sealed TraversalLock; no product string on this VA (acceptable) |
| 8 | Clears flag **after** LeaveCS | Ordering race | **Falsified** — clear then LeaveCS (matches lock: Enter then set) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Flag + CS contract | **High** | CS leak / double Leave |
| Pair of TraversalLock | **High** | Deadlock with wrong unlock |
| Domain breadth | **High** | Over-scoping as skill-only |
| Product class name | **Low–Med** | Doc only |

---

## 3. Cross-check against raw ≡ live

```text
if (*(list+0x28) != 0) {
  *(list+0x28) = 0;
  LeaveCriticalSection(list+4);
}
return;
```

Sibling contrast:

* `List_TraversalLock` (`0x004294f0`): if flag set → debug log return; else EnterCS(+4), flag=1.
* `List_IterateNext` (`0x004022a0`): requires flag; TryEnter(+4); walks nodes.
* InventoryGrid local unlock: **different** offsets — not this VA.

---

## 4. Surviving contract for AutoCore

```
List_TraversalUnlock(list):
  if list.traversalFlag (+0x28):
      list.traversalFlag = 0
      LeaveCS(list.cs @ +4)
  // else: no-op
```

**Port tests:** unlock after lock leaves CS free; double unlock is safe; never EnterCS here; never free nodes.

**Verdict:** **accept** — adversarial lock/iterator/skill-only/throw confusions **fail**.
