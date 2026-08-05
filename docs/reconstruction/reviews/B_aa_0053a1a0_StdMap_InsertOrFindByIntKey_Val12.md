# Review B (adversarial): `aa_0053a1a0` StdMap_InsertOrFindByIntKey_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053a1a0` |
| **VA** | `0x0053a1a0` |
| **Canonical name** | `StdMap_InsertOrFindByIntKey_Val12` (**Inferred**) |
| **Review date** | `2026-07-29` (OWN-ONLY dual B — W28-P) |
| **Reviewer role** | Adversarial / disconfirm |
| **Counterpart** | `reviews/A_aa_0053a1a0_StdMap_InsertOrFindByIntKey_Val12.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks considered

| Attack | Result |
|---|---|
| Always-insert (no uniqueness) | **Reject** — equal-key path sets `inserted=0` and returns existing node without calling insert |
| Multi-key / pointer key | **Reject** — compares `*value` as **int** to `node[3]`; Val12 payload starts at +0x0C |
| Wrong isnil offset | **Reject** — walk and helper use **`+0x19`** |
| Wrong ABI (`ret 0x0c` / `ret 0x10`) | **Reject** — three exits `c2 08 00` |
| Confuse with hint-insert parent | **Reject** — this VA is lower_bound+insert; parent `0053a8e0` may short-circuit then **falls back** here |
| Confuse with W27-R peer parent `00567860` | **Note** — same *role* on another Val12 clone (different insert helper `00567450`); **do not merge VAs** |
| Overclaim product name | **Gap** — Inferred retained |

---

## Residual risks

- Buynode OOM inside `00539210` not exercised here.
- InsertPair layout beyond `{it, u8 inserted@+4}` (padding/bool width) not fully product-typed.
- No runtime confirmation of sole caller fallback frequency.

---

## Decision

No successful disconfirm of CF/ABI/layout. Accept with documented product gaps.

**Verdict:** **accept-with-gaps**
