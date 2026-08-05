# Review A (reconstruction fidelity): `aa_00503f30` Vehicle_ActivateEnterWorld

| Field | Value |
|---|---|
| **Stable ID** | `aa_00503f30` |
| **VA** | `0x00503f30` |
| **Canonical name** | `Vehicle_ActivateEnterWorld` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00503f30_Vehicle_ActivateEnterWorld.md` |
| **System** | `input-drive-control` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Owner enter-world / physics activate orchestration. When owner context present: (1) `TimedAction_CreateTokenFlagAction` period **300000 ms** (not combat pools); (2) `Vehicle_CreateWeaponTrackAction` period **30 ms**; (3) combat-pool action period **3000 ms** (race 0/1/2) or **5000 ms**. Zeros heat (**+0x150/+0x154**) and fills current shield from max (**+0x144 ← +0x148**) on player path. Clears owner flag bit at +0x17d (`& ~1`). High-value vehicle spawn enter-world side effects.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00503f30_Vehicle_ActivateEnterWorld.md` (or `aa_00503f30_FUN_00503f30.md`) |
| Annotated | `docs/reconstruction/raw/aa_00503f30_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Vehicle_ActivateEnterWorld.cpp` |
| Function record | `docs/reconstruction/functions/aa_00503f30_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Creates token / weapon-track / combat-pool HBs` | High | Plate + callees |
| `Weapon track period 30 ms` | High | CreateWeaponTrackAction |
| `Combat pool 3s/5s by race` | High | Plate |
| `Heat zero + shield fill on enter` | High | +0x150/+0x154, +0x144←+0x148 |
| `Owner flag +0x17d &= ~1` | High | Body |
| `Full non-owner / NPC branch map` | Medium | Partial CF |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Owner present → timed actions + pool reset | Yes |
| No invented cast pipeline | Yes |

---

## 5. Gaps / open

1. Seal race→period table completely.
2. TokenFlagAction purpose beyond period.
3. NPC/unowned path completeness.

**Verdict:** **accept-with-gaps**
