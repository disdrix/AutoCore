# Review A (reconstruction fidelity): `aa_005b10a0` Net_GhostObject_getUpdatePriority

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b10a0` |
| **VA** | `0x005b10a0` |
| **Canonical name** | `Net_GhostObject_getUpdatePriority` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005b10a0_Net_GhostObject_getUpdatePriority.md` |
| **System** | `networking` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

TNL-style **getUpdatePriority** for GhostObject (plate `GhostObject::getUpdatePriority`). Returns `float10` priority. If either side lacks object at **+0x50**, returns `param_5 * DAT_00aaa7b8`. Else if same object / parent / child relation → **1.0**. Else distance-based: XZ distance between vtbl **+0x1a0** positions, scaled by ghost scale `*(this+0x58)`, viewer range fields at **viewer+0x29 → +0xe7d0 / +0xe4f8+0x18**, constants `DAT_00aaab3c`, `DAT_00a0f298`, plus `param_5 * msToSeconds`. TFID equality via `FUN_0040aff0` + `TFID_EqualsObjectId`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005b10a0_*.md` |
| Annotated | `docs/reconstruction/raw/aa_005b10a0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Net_GhostObject_getUpdatePriority.cpp` |
| Function record | `docs/reconstruction/functions/aa_005b10a0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Null +0x50 → param_5 * DAT_00aaa7b8 | High | Body |
| Self/parent/child → priority 1.0 | High | Early out |
| Distance-scaled priority with this+0x58 weight | High | Body formula |
| TFID equal path forces 1.0 | High | TFID_EqualsObjectId |
| Exact DAT float values sealed | Medium | Need read_memory |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| null check → relation → TFID → distance formula → return | Yes |

---

## 5. Gaps / open

1. read_memory DAT_00aaa7b8 / 00aaab3c / 00a0f298.
2. Confirm viewer +0x29 range field meanings.

**Verdict:** **accept-with-gaps**
