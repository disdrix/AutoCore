# Review B (skeptical / adversarial): `aa_0040dc40` List_ClearDestroy

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040dc40` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0040dc40_List_ClearDestroy.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Soft-fail like TraversalLock on re-entry | Family bundle | **Falsified** — **throws** `0x80070005` after LeaveCS |
| 2 | Clears only head pointer, keeps nodes | Shallow clear | **Falsified** — dtor(1) each node |
| 3 | Frees the list object / CS | Full dtor | **Falsified** — nodes only; callers DeleteCS separately |
| 4 | Safe while TraversalLock held | Concurrent walk | **Falsified** — throw path |
| 5 | Next link at `node+8` (32-bit) | Sibling mix | **Falsified for this body** — uses `node+0x10` |
| 6 | Unlocks without Enter when unlocked | Order | **Falsified** — always Enter first |
| 7 | Product name string-proven | Inflation | **Not sealed** — inferred role |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Throw if locked | **High** | Silent free during walk → UAF |
| Scalar dtor per node | **High** | Leak |
| Head/next u64 layout | **High** | Wrong free chain |
| Portable to 32-bit key lists | **Med / open** | Offset mismatch |
| Field names +0x20/+0x24 | **Med** | Doc |

---

## 3. Cross-check raw ≡ force

```text
EnterCS(list+4)
if list.traversalFlag:
    LeaveCS; throw 0x80070005
while head = list.head:
    list.head = head->next (+0x10)
    head->dtor(1)
list.field_24 = list.field_20 = list.head = 0
LeaveCS
```

Contrast TraversalLock: double-lock is **log+return**, not throw.

---

## 4. Surviving contract

```
List_ClearDestroy(list):
  assert not list.traversalFlag else throw E_ACCESSDENIED
  destroy all nodes; zero head/aux fields under CS
// does NOT DeleteCriticalSection or free list shell
```

**Port tests:** refuse clear while locked; use `+0x10` next for this list family; pair with owner dtor for CS.

**Verdict:** **accept-with-gaps** — soft-fail and shallow-clear attacks **fail**.
