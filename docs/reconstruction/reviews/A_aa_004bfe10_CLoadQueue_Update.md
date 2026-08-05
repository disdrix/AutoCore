# Review A (reconstruction fidelity): `aa_004bfe10` CLoadQueue_Update

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bfe10` |
| **VA** | `0x004bfe10` |
| **Canonical name** | `CLoadQueue_Update` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004bfe10_CLoadQueue_Update.md` |
| **System** | `client-load` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

CLoadQueue **update** (plate `CLoadQueue::update`). `__thiscall(this, dt)`. Walks **9** priority lists starting at **this+0x8**, stride **3 ints** per bucket. For each node, calls `FUN_005c7df0(&dt_remaining, 0)`; on success deletes node payload via vtbl dtor and unlinks; stops when remaining dt ≤ 0. Time-sliced load scheduler for CLoadNode pipeline.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004bfe10_*.md` |
| Annotated | `docs/reconstruction/raw/aa_004bfe10_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CLoadQueue_Update.cpp` |
| Function record | `docs/reconstruction/functions/aa_004bfe10_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| 9 buckets from this+0x8 stride 0xC | High | uVar3 < 9 loop |
| FUN_005c7df0 time-slice worker | High | Body |
| Stops when local_14 dt exhausted | High | g_flZero compare |
| Deletes finished nodes | High | operator_delete path |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| for bucket 0..8: walk list; worker; maybe delete; dt gate | Yes |

---

## 5. Gaps / open

1. Name FUN_005c7df0 (likely CLoadNode step dispatcher).
2. Document bucket priority semantics.

**Verdict:** **accept-with-gaps**
