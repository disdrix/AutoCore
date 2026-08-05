# Review B (skeptical / adversarial): `aa_00539e30` CNDHash_Recreate_009cfa88

| Field | Value |
|---|---|
| **Stable ID** | `aa_00539e30` |
| **VA** | `0x00539e30` |
| **Canonical name** | `FUN_00539e30` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial dual |
| **Counterpart** | `reviews/A_aa_00539e30_CNDHash_Recreate_009cfa88.md` |
| **System** | container / CNDHash / missions-progression |
| **Verdict** | **accept-with-gaps** |

---

## 1. What this is *not*

| Attack | Result |
|---|---|
| “Same as `00539d70`/`00539dd0`” | **Falsified** — callees `00539110`/`00537bf0` unique |
| “Active mission hash (`+0x540`) recreate” | **Falsified** — caller passes `*(+0x55c)` |
| “Completed hash (`+0x538`)” | **Falsified** — different slot |
| “RemoveAll equivalent” | **Falsified** — frees bucket table |
| “Non-owning” | **Falsified** — `00538200` deletes values |
| “Lock stops recreate” | **Falsified** — continue after log |

---

## 2. Cross-check vs dual A

| A claim | B stance |
|---|---|
| Pending slot `+0x55c` | **Agree** (system map + caller + ctor) |
| RET 4 / owning teardown / AllocBuckets_00537bf0 | **Agree** |
| Default bits 2 from ctor | **Agree** for initial construct; recreate can pass other bits |
| Product English open | **Agree** |

---

## 3. Surviving contract

```
// thiscall RET 4 — char+0x55c pending objectives hash family (vtbl 009cfa88)
void CNDHash_Recreate_009cfa88(CNDHash* this, uint8_t log2Bits);
// lock → log+continue; teardown 00539110; AllocBuckets 00537bf0
```

### Traps

1. Do not swap with `00539dd0` (`+0x530`) in `FUN_0052b4e0` port.
2. Do not assume 4-bucket size after recreate if caller passes different bits.
3. Do not merge with RemoveAll `0053b*` family.

---

## 4. Residual

1. Product Recreate name.
2. Full semantics of `FUN_0052b4e0` wipe ordering.
3. Runtime.

**Verdict:** **accept-with-gaps**. Accept A.
