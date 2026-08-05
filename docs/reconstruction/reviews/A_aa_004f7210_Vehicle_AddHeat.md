# Review A (reconstruction fidelity): `aa_004f7210` Vehicle_AddHeat

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f7210` |
| **VA** | `0x004f7210` |
| **Canonical name** | `Vehicle_AddHeat` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004f7210_Vehicle_AddHeat.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Apply signed heat delta to vehicle combat pools: floor cool accumulator if negative; optional character heat-sink divert when over MaxHeat (owner vfunc **+0x210**, sink scale at char **+0xc6c**); `CurrentHeat += delta`; clamp to **[0, 2×MaxHeat]**; if ghosted and changed, `NetObject_SetMaskBits` **HeatMask 0x20000000**. Positive heats, negative cools (regen). Decomp delta may show as `unaff_retaddr` — fragile.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004f7210_Vehicle_AddHeat.md` (or `aa_004f7210_FUN_004f7210.md`) |
| Annotated | `docs/reconstruction/raw/aa_004f7210_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Vehicle_AddHeat.cpp` |
| Function record | `docs/reconstruction/functions/aa_004f7210_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Signed delta + clamp [0, 2*MaxHeat]` | High | Plate |
| `HeatMask 0x20000000 dirty` | High | Plate |
| `Cool accumulator floor` | High | Body |
| `Optional heat-sink divert via owner` | High | Body +0xc6c |
| `Delta arg decomp fragility` | Medium | unaff_retaddr |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Floor cool → optional sink → add → clamp → dirty | Yes |
| No invent shield write | Yes |

---

## 5. Gaps / open

1. Confirm 2×MaxHeat ceiling vs UI display.
2. Seal heat-sink short field at +300.

**Verdict:** **accept-with-gaps**
