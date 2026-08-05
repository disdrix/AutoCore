# Review A (reconstruction fidelity): `aa_004f7480` Vehicle_IsAnyWeaponFiring

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f7480` |
| **VA** | `0x004f7480` |
| **Canonical name** | `Vehicle_IsAnyWeaponFiring` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004f7480_Vehicle_IsAnyWeaponFiring.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Thin hardpoint fire query: true if turret weapon (**vehicle+0x264**) or any of three hardpoint weapons (**table at +0x260**, indices 0..2) has firing flag **weapon+0xC7** non-zero. Used by combat-pool OnTick to slow cooling while weapons fire. Short-circuit: turret first, then scan hardpoints. Clean rewrites typed pad (**pPad_248** +0x1C/+0x18 → absolute +0x264/+0x260).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004f7480_*.md` |
| Annotated | `docs/reconstruction/raw/aa_004f7480_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Vehicle_IsAnyWeaponFiring.cpp` |
| Function record | `docs/reconstruction/functions/aa_004f7480_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Turret at +0x264, hardpoints at +0x260` | High | Clean + plate |
| `Firing flag weapon+0xC7` | High | Body |
| `Three hardpoint slots` | High | Loop bound 3 |
| `OnTick cool-slow consumer` | High | Combat-pool call graph |
| `Null weapon skipped` | High | pWeapon!=0 gate |
| `Hardpoint table is int* array base` | Medium | Pointer vs inline array residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| turret fire? → true; else scan 3 hardpoints; else false | Yes |
| No invent 4th slot | Yes |

---

## 5. Gaps / open

1. Confirm hardpoint table is *int[3] vs inline int[3] at +0x260.
2. Xref all cool-slow callers beyond OnTick.

**Verdict:** **accept-with-gaps**
