# Review A (reconstruction fidelity): `aa_005d0840` CVOGHBAICreatureBase_DecideHeading

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d0840` |
| **VA** | `0x005d0840` |
| **Canonical name** | `CVOGHBAICreatureBase_DecideHeading` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005d0840_CVOGHBAICreatureBase_DecideHeading.md` |
| **System** | `npc-ai` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Turn/aim creature (or vehicle) toward desired heading from target/path direction. Rate-limits via time since last decision; validates owner vtbl+0x214 / state +0x6bc; acos heading from rotation matrix +0x30..; apply rotation limit × dt; set heading vtbl+0x54. Shared by pursue/patrol.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005d0840_CVOGHBAICreatureBase_DecideHeading.md` |
| Annotated | `docs/reconstruction/raw/aa_005d0840_CVOGHBAICreatureBase_DecideHeading.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBAICreatureBase_DecideHeading.cpp` |
| Function record | `docs/reconstruction/functions/aa_005d0840_CVOGHBAICreatureBase_DecideHeading.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Args: fDeltaTime + pDirection xyz` | **High** | Signature |
| `Time-since-last gate FUN_004c56a0` | **High** | Early skip |
| `Validate creature vtbl+0x214 / +0xbc +0x6bc` | **High** | State checks |
| `Direction vs stored +0x50..0x5c snapshot` | **High** | Zero-diff reuse |
| `Acos heading from matrix +0x30..` | **High** | FPU path |
| `Forward component <0 angle adjust` | **High** | Body |
| `Rotation limit scaled by dt` | **High** | Turn rate |
| `Apply vtbl+0x54 set heading` | **High** | Write |
| `World ref DAT_00bc5570 family` | **Probable** | Globals |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Timer + validate | **Yes** |
| Direction/matrix/acos | **Yes** |
| Clamp + vtbl set | **Yes** |

---

## 5. Gaps / open

1. Exact turn-rate constants / degrees vs radians.
2. FUN_004c56a0 threshold source.
3. When called vs DoVehiclePursue direct apply.
4. Runtime heading slew capture.

**Verdict:** **accept-with-gaps**
