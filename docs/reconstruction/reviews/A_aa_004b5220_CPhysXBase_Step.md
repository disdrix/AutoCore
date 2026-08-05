# Review A (reconstruction fidelity): `aa_004b5220` CPhysXBase_Step

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b5220` |
| **VA** | `0x004b5220` |
| **Canonical name** | `CPhysXBase_Step` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004b5220_CPhysXBase_Step.md` |
| **System** | `physics` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

CPhysXBase **`Step`** (plate). If base ptr `*this` non-null and flag **this[2]==0**: if scene `this[1]` present, query vtbl **+0x16c**; step with vtbl **+0xe0**(dt=`0x3d088889`≈1/30, mode 2 or 1); then **+0xdc** and **+0x19c**. Sets **this[2]=1**. One-shot / gated step marker — not free-running tick alone.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004b5220_*.md` |
| Annotated | `docs/reconstruction/raw/aa_004b5220_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CPhysXBase_Step.cpp` |
| Function record | `docs/reconstruction/functions/aa_004b5220_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Gated by *this and this[2]==0 | High | Body |
| dt constant 0x3d088889 (~1/30) | High | Body |
| Mode 1 vs 2 from vtbl+0x16c | High | Body |
| Sets this[2]=1 after | High | Body |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| if ready: query → step e0 → dc → 19c → flag=1 | Yes |

---

## 5. Gaps / open

1. Confirm 0x3d088889 == 1/30f exactly.
2. Name scene vtbl slots.

**Verdict:** **accept-with-gaps**
