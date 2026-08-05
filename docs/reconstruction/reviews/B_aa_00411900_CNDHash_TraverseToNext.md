# Review B (skeptical / adversarial): `aa_00411900` CNDHash_TraverseToNext

| Field | Value |
|---|---|
| **Stable ID** | `aa_00411900` |
| **VA** | `0x00411900` |
| **Canonical name** | `CNDHash_TraverseToNext` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00411900_CNDHash_TraverseToNext.md` |
| **Live tools** | Independent `force_decompile` + callers + `read_memory` |
| **Verdict** | **accept-with-gaps** — accept A's CF; reject overclaims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Unlocked traverse is fatal / aborts | **Falsified** — dual log only; fall-through continues |
| 2 | Returns the **node** pointer | **Falsified** — returns `*(node+8)` payload |
| 3 | Same list-next offset as inventory insert `0x00413920` | **Falsified** — here **+0x14**; inv-u64 nodes use **+0x20** |
| 4 | Sets / clears traversal lock | **Falsified** — read-only lock check |
| 5 | Free function (not thiscall) | **Falsified** — `mov esi,ecx`; `ret 4` |
| 6 | Only QuickBar consumer | **Falsified** — 20+ callers across icons, inventory UI, debug |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Iterate step under lock | **High** | Infinite loop / skip if next offset wrong |
| Payload at `node+8` (this family) | **High** | Wrong skill/object handle |
| No membership mutation | **High** | Accidental remove ports |
| Node layout portability to 0x28 inv nodes | **None** — do not mix | Crash / corrupt |
| Product English "CNDHash" | **High** (HashError strings) | — |

---

## 3. Caller challenge

| Caller | Must not claim |
|---|---|
| `Client_QuickBarActivateSkillSlot` | That this VA **is** the skill map — it only walks `char+…+0x74` hash |
| Inlined twin in same function | That all advances call this symbol (some re-implement body) |
| `FUN_0089bc30` | Inventory-only exclusivity |

---

## 4. CF challenge of Review A

- Dual force/non-force identity: **agree**
- Head `+0x14`, next `node+0x14`, value `node+8`: **agree**
- Lock log non-fatal: **agree**
- Residual on node-family split: **add** (A already notes)

---

## 5. Surviving contract

```
value = CNDHash_TraverseToNext(hash, &cursor):
  if !hash.lockedForTraversal: log HashError:TraverseToNext…; // continue
  if cursor==0: cursor = hash.listHead (+0x14)
  else:         cursor = cursor->listNext (+0x14)   // 0x1c-node family
  return cursor ? cursor->value (+8) : 0
```

**Verdict:** **accept-with-gaps.** Accept A.
