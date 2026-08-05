# Review A (reconstruction fidelity): `aa_0091a550` Input_TryFireSecondaryWeapons

| Field | Value |
|---|---|
| **Stable ID** | `aa_0091a550` |
| **VA** | `0x0091a550` |
| **Canonical name** | `Input_TryFireSecondaryWeapons` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0091a550_Input_TryFireSecondaryWeapons.md` |
| **System** | `combat` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Client **secondary-weapon fire attempt** from input. Gates: local player `DAT_00d1b6d8` non-null; flags byte at multi-inherit `+0xb8` must clear mask **0xd2**; sector net connection live (vtbl **+8** truthy); vehicle at character **+0x250**. Then `FUN_004f52e0` heat/fire check — on fail logs `Failed to fire secondary weapons due to heat.` and returns. On pass calls `FUN_004f5110` (fire). Optional `FUN_0089ff80` if chars `+0x6b8`/`+0x6b9` and UI vtbl **+0x3d8**. Companion to `Weapon_CanFireHeatCheck` / `Weapon_ApplyShotHeatAndPowerCost`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0091a550_*.md` |
| Annotated | `docs/reconstruction/raw/aa_0091a550_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Input_TryFireSecondaryWeapons.cpp` |
| Function record | `docs/reconstruction/functions/aa_0091a550_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Heat gate FUN_004f52e0 before fire FUN_004f5110 | High | Body |
| Requires vehicle @ char+0x250 and net conn | High | Body |
| Flag mask 0xd2 at +0xb8 blocks fire | High | Body |
| Heat fail is log-only (no throw) | High | Body |
| FUN_004f52e0 ≡ CanFireHeatCheck family | Medium | Callee name residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| gates → heat check → fire → optional UI | Yes |
| Does not write heat itself | Yes |

---

## 5. Gaps / open

1. Seal FUN_004f52e0 / FUN_004f5110 as CanFire / fire-secondary.
2. Document +0x6b8/+0x6b9 secondary weapon UI flags.
3. Bit-exact vs retail deferred.

**Verdict:** **accept-with-gaps**
