# Review A (reconstruction fidelity): `aa_00786c10` NetObject_SetMaskBits

| Field | Value |
|---|---|
| **Stable ID** | `aa_00786c10` |
| **VA** | `0x00786c10` |
| **Canonical name** | `NetObject_SetMaskBits` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00786c10_NetObject_SetMaskBits.md` |
| **System** | `networking` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Dirties **64-bit ghost mask** on NetObject and links into global dirty list. `__thiscall(this, dwMaskLo, dwMaskHi)`. If both **+0x18/+0x1c** were zero and `g_pNetObjectDirtyListHead` non-null, splices this into list via **+0x10** next / head **+0xc** prev, then sets head = this. Always ORs masks into **+0x18** (lo) and **+0x1c** (hi). Combat-pool masks: POWER `0x08000000`, SHIELD `0x04000000`, HEAT `0x20000000` (low word). Call-site arg order residual (mask,0) vs (0,mask).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00786c10_*.md` |
| Annotated | `docs/reconstruction/raw/aa_00786c10_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NetObject_SetMaskBits.cpp` |
| Function record | `docs/reconstruction/functions/aa_00786c10_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| OR into +0x18 lo / +0x1c hi | High | Body |
| Dirty-list splice when masks were clear | High | Body |
| Combat masks POWER/SHIELD/HEAT documented | High | Plate + GHOST_VEHICLE_MASK |
| Arg order always (lo,hi) | Medium | Call-site variance note |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| if clean → link list; OR lo/hi; return | Yes |

---

## 5. Gaps / open

1. Audit all call sites for (mask,0) vs (0,mask).
2. Confirm dirty list walk on pack tick.

**Verdict:** **accept-with-gaps**
