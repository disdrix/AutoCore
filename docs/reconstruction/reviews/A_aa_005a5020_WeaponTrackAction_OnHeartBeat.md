# Review A (reconstruction fidelity): `aa_005a5020` WeaponTrackAction_OnHeartBeat

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a5020` |
| **VA** | `0x005a5020` |
| **Canonical name** | `WeaponTrackAction_OnHeartBeat` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005a5020_WeaponTrackAction_OnHeartBeat.md` |
| **System** | `combat` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Thin **weapon-track action heartbeat**. `__thiscall(this, outTick*)`. If tracker field **+0x24** non-zero, calls `FUN_004f8430` (track update). Always writes `*out = DAT_00b05064` (default reschedule / period). HB list consumer for weapon tracking FX/aim path.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005a5020_*.md` |
| Annotated | `docs/reconstruction/raw/aa_005a5020_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/WeaponTrackAction_OnHeartBeat.cpp` |
| Function record | `docs/reconstruction/functions/aa_005a5020_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| +0x24 gates FUN_004f8430 | High | Body |
| Always stamps DAT_00b05064 into out | High | Annotated raw |
| Not heat/cost apply | High | No CanFire/AddHeat |
| FUN_004f8430 track identity | Medium | Callee residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| if +0x24: FUN_004f8430; *out=DAT; return | Yes |

---

## 5. Gaps / open

1. Name FUN_004f8430 track step.
2. read_memory DAT_00b05064 period.

**Verdict:** **accept-with-gaps**
