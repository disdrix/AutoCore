# Review A (reconstruction fidelity): `aa_009463b0` Phy_Start_ReinitPhysics

| Field | Value |
|---|---|
| **Stable ID** | `aa_009463b0` |
| **VA** | `0x009463b0` |
| **Canonical name** | `Phy_Start_ReinitPhysics` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_009463b0_Phy_Start_ReinitPhysics.md` |
| **System** | `physics` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Map-transition **reinitPhysics** kickoff (plate `start reinitPhysics`). Clears flag **+0xb7**, calls teardown helpers `FUN_009432f0` / `FUN_009302b0`, empties three intrusive lists at **+0xd1c**, **+0xf18**, **+0xf24** via `FUN_004069b0` / `00406bc0` / `00406c00`. Logs `Evicting ALL managed resources prior to map transition`, vtbl evict on `DAT_00d1f044`. Optional process working-set trim when **+0x9e0** set. Large (~207-line) world reset — not per-object phys.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_009463b0_*.md` |
| Annotated | `docs/reconstruction/raw/aa_009463b0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Phy_Start_ReinitPhysics.cpp` |
| Function record | `docs/reconstruction/functions/aa_009463b0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| World reinit / map transition teardown | High | Strings + body |
| Clears three lists +0xd1c/+0xf18/+0xf24 | High | Body |
| Managed resource evict + optional RAM swap | High | Body |
| Per-object rigid body step | Low | Not this function |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| flag → teardown helpers → clear lists → evict → optional trim | Yes |

---

## 5. Gaps / open

1. Name list types at +0xd1c/+0xf18/+0xf24.
2. Document full reinit completion path after this start.

**Verdict:** **accept-with-gaps**
