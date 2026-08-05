# Review B (adversarial): `aa_005aed20` StdMap_InsertOrFindByIntKey_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_005aed20` |
| **VA** | `0x005aed20` |
| **Canonical name** | `StdMap_InsertOrFindByIntKey_Val12` (**Inferred**) |
| **Review date** | `2026-07-29` (OWN-ONLY dual B — W30-M) |
| **Reviewer role** | Adversarial / disconfirm |
| **Counterpart** | `reviews/A_aa_005aed20_StdMap_InsertOrFindByIntKey_Val12.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks considered

| Attack | Result |
|---|---|
| Always-insert (no uniqueness) | **Reject** — equal-key path sets `inserted=0` and returns existing node without calling insert |
| Multi-key / pointer key | **Reject** — compares `*value` as **int** to `node[3]`; Val12 payload starts at +0x0C |
| Wrong isnil offset | **Reject** — walk and Dec helper use **`+0x19`** |
| Wrong ABI (`ret 0x0c` / `ret 0x10` / bare ret) | **Reject** — three exits `c2 08 00` |
| MissionStopLimit-specific logic | **Reject** — generic `_Tree` insert-or-find; legacy name is xref chain only |
| Merge with peer `aa_0053a1a0` | **Reject** — same *role*, different insert helper (`005ae4e0` vs `00539210`) and callers; **do not merge VAs** |
| Confuse with insert helper itself | **Reject** — this VA owns uniqueness; `005ae4e0` is always-insert + rebalance only |
| Overclaim product name | **Gap** — Inferred retained |

---

## Residual risks

- Buynode OOM inside `005ae4e0` not exercised here.
- InsertPair layout beyond `{it, u8 inserted@+4}` (padding/bool width) not fully product-typed.
- Second call site body (`005ad2f0`) not plate-defined in Ghidra — parse path inferred from vtable +0x48 only.

---

## Decision

No successful disconfirm of CF/ABI/layout. Accept with documented product gaps.

**Verdict:** **accept-with-gaps**
