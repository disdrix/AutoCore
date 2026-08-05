# Review A (reconstruction fidelity): `aa_007a4330` CVOGReaction_RandomUnitScalar

| Field | Value |
|---|---|
| **Stable ID** | `aa_007a4330` |
| **VA** | `0x007a4330` |
| **Canonical name** | `CVOGReaction_RandomUnitScalar` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007a4330_CVOGReaction_RandomUnitScalar.md` |
| **System tag** | `util-rng` |
| **Verdict** | **accept** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/CVOGReaction_RandomUnitScalar.cpp` |
| Raw | `docs/reconstruction/raw/aa_007a4330_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** Meyers-style singleton getter for RNG object at DAT_00d20c1c. Once-init via DAT_00d20c34 bit0: FUN_007a42d0 then atexit(LAB_009c30c0). Returns &DAT_00d20c1c. Despite name, does not return a float unit scalar — returns pointer to RNG state used by map var type 8 and terrain solid-tile UV variants. Name is historical/misleading.

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Guard DAT_00d20c34 & 1 once-init | High | Body |
| FUN_007a42d0 constructs RNG | High | Call |
| _atexit teardown LAB_009c30c0 | High | Call |
| Returns &DAT_00d20c1c | High | Return |
| Not a float in [0,1] return | High | ABI undefined* |
| Consumers: var type 8, terrain UV | High | Cross refs |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| if !init: init+atexit; return &DAT | Yes |

---

## 4. Gaps

1. RNG algorithm inside FUN_007a42d0 / table at +8.
2. Thread safety (none assumed).

**Verdict:** **accept**
