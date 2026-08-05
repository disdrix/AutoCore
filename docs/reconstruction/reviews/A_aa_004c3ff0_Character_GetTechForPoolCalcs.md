# Review A (reconstruction fidelity): `aa_004c3ff0` Character_GetTechForPoolCalcs

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c3ff0` |
| **VA** | `0x004c3ff0` |
| **Canonical name** | `Character_GetTechForPoolCalcs` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004c3ff0_Character_GetTechForPoolCalcs.md` |
| **System** | `vehicle-combat-pools` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Clamp **Tech** for vehicle combat-pool formulas (HP/power/etc.). `__fastcall(pCharacter) → int` in **[1,250]**. Reads raw Tech short `+0x13c`, caps at **200** before bonus short `+0x144`; if `capped+bonus < 2` return **1**; if `< 0xFA (250)` return sum; else **250**. AutoCore: `VehicleHitPointCalculator.GetTechForPoolCalcs` / `Vehicle_CalcMaxHitPoints` consumer.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004c3ff0_*.md` |
| Annotated | `docs/reconstruction/raw/aa_004c3ff0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Character_GetTechForPoolCalcs.cpp` |
| Function record | `docs/reconstruction/functions/aa_004c3ff0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Tech@+0x13c, bonus@+0x144 | High | Clean plate |
| Pre-bonus cap 200 | High | Clean `199 < nTechRaw` |
| Floor 1 when sum < 2 | High | Clean |
| Ceil 250 (0xFA) | High | Clean return |
| __fastcall ECX = character | High | Convention |
| Decompiler re-caps thrice (dup paths) | Medium | Ugly but same math |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| cap200 → +bonus → clamp [1,250] | Yes |
| No chassis/armor reads here | Yes |

---

## 5. Gaps / open

1. Confirm bonus field semantics (items/skills).
2. Live-diff edge cases: Tech=0,200,201 + bonus ±.

**Verdict:** **accept-with-gaps**
