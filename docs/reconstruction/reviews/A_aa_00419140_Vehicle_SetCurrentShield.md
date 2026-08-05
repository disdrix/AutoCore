# Review A (reconstruction fidelity): `aa_00419140` Vehicle_SetCurrentShield

| Field | Value |
|---|---|
| **Stable ID** | `aa_00419140` |
| **VA** | `0x00419140` |
| **Canonical name** | `Vehicle_SetCurrentShield` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00419140_Vehicle_SetCurrentShield.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept** |

---

## 1. Purpose

Clamp desired current shield to **[0, MaxShield]** and store. Max at **+0x148**, current at **+0x144**. Does **NOT** call `NetObject_SetMaskBits` — caller must dirty **ShieldMask 0x04000000** when value changes. Thin combat-pool setter; pairs shield combat regression tests.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00419140_Vehicle_SetCurrentShield.md` (or `aa_00419140_FUN_00419140.md`) |
| Annotated | `docs/reconstruction/raw/aa_00419140_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Vehicle_SetCurrentShield.cpp` |
| Function record | `docs/reconstruction/functions/aa_00419140_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Current +0x144 / Max +0x148` | High | Plate |
| `Clamp [0, Max]` | High | Body CF |
| `No SetMaskBits in body` | High | NOTE in plate |
| `Caller owns ShieldMask 0x04000000` | High | Plate |
| `Decomp stack arg naming` | Medium | in_stack_00000004 |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Clamp → store current | Yes |
| No invent max recompute | Yes |

---

## 5. Gaps / open

1. Confirm all callers dirty ShieldMask.
2. Zero vs <1 clamp edge (body uses <1 → 0).

**Verdict:** **accept**
