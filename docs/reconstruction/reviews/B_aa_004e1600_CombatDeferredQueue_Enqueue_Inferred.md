# Review B (skeptical / adversarial): `aa_004e1600` CombatDeferredQueue_Enqueue_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e1600` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004e1600_CombatDeferredQueue_Enqueue_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Applies combat damage itself | Only links payload node; no pool/floater | **Falsified** as apply |
| 2 | Always locks both CS | Outer only when `this+0xc < 4` | **Survives** as gated |
| 3 | Null payload crashes | Early return before alloc | **Survives** null-safe |
| 4 | Doubly-linked list | Only `node+8` next; head/tail only | **Falsified** as DLL — **SLL** |
| 5 | Same as `004d78e0` | Distinct VA/role | **Falsified** merge |
| 6 | Drain of queue sealed here | Only enqueue; drain not in body | **Survives** as open gap |

---

## 2. Live ≡ raw

Live matches raw `aa_004e1600`: null check, `operator_new(0xc)`, vtbl init, dual CS, head/tail link, `FUN_004e16b3`.

Epilogue live: leave `+0x10`, optional leave `+0x28`, `InterlockedIncrement(+0xc)`.

---

## 3. Surviving contract

```
// this = queue
// if payload==null → return 0
// node = new 0xC { vtbl, payload, next=0 }
// if count<4: EnterCS(+0x28)
// EnterCS(+0x10)
// append to SLL (head@+4, tail@+8)
// LeaveCS(+0x10); maybe LeaveCS(+0x28); InterlockedIncrement(count@+0xc)
```

**Gaps kept:** product names; queue drain consumer; outer-CS policy rationale.

**Verdict:** **accept-with-gaps**.
