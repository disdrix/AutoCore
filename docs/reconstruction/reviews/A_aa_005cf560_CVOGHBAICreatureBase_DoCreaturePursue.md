# Review A (reconstruction fidelity): `aa_005cf560` CVOGHBAICreatureBase_DoCreaturePursue

| Field | Value |
|---|---|
| **Stable ID** | `aa_005cf560` |
| **VA** | `0x005cf560` |
| **Canonical name** | `CVOGHBAICreatureBase_DoCreaturePursue` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005cf560_CVOGHBAICreatureBase_DoCreaturePursue.md` |
| **System** | `combat` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Creature AI **pursue** heartbeat logic (`CVOGHBAICreatureBase::DoCreaturePursue`). `__fastcall(this)`. Uses owner creature `param_1[0x19]`, range/target via vtbl **+0x19c** / **+0x1a4**, distance helper `FUN_0053e510`, chase helpers `FUN_005d1c00` / `FUN_005d1bb0` / `FUN_00567ce0`. Gates on float field path `+0x3c/+0x4c0` vs `g_flZero` and flag bit **0x40** at multi-inherit `+0xb8`. Combat-adjacent AI steer toward target — not loot or net pack.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005cf560_*.md` |
| Annotated | `docs/reconstruction/raw/aa_005cf560_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBAICreatureBase_DoCreaturePursue.cpp` |
| Function record | `docs/reconstruction/functions/aa_005cf560_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Plate name DoCreaturePursue sealed | High | String + clean |
| Owner at this[0x19]; range vtbl +0x19c | High | Body |
| FUN_0053e510 distance compare vs +0x124 | High | Body |
| Full nav math sealed | Medium | Large float stack residual |
| Bit 0x40 +0xb8 gate meaning | Medium | Inferred combat-ready |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| log → range/target resolve → distance branch → chase helpers | Yes |

---

## 5. Gaps / open

1. Seal pursue vs attack range thresholds.
2. Name FUN_0053e510 / FUN_005d1c00.

**Verdict:** **accept-with-gaps**
