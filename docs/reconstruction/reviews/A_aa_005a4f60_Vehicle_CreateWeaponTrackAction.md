# Review A (reconstruction fidelity): `aa_005a4f60` Vehicle_CreateWeaponTrackAction

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a4f60` |
| **VA** | `0x005a4f60` |
| **Canonical name** | `Vehicle_CreateWeaponTrackAction` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005a4f60_Vehicle_CreateWeaponTrackAction.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Construct timed action for weapon tracking / secondary systems — **NOT** combat pool. `CVOGHBBase_ctor` then period: countdown special **-1000**, period **+0x08 = 0x1E (30 ms)**, type field **param_1[7]=4**. Attaches owner object; if hardpoint weapon present at **+0x260[1]** may call `FUN_004f8430`. Null owner triggers debug stop. Called from `Vehicle_ActivateEnterWorld`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005a4f60_Vehicle_CreateWeaponTrackAction.md` (or `aa_005a4f60_FUN_005a4f60.md`) |
| Annotated | `docs/reconstruction/raw/aa_005a4f60_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Vehicle_CreateWeaponTrackAction.cpp` |
| Function record | `docs/reconstruction/functions/aa_005a4f60_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Period 30 ms (0x1e)` | High | Plate + body |
| `Countdown special -1000` | High | SetPeriodAndCounter |
| `Not combat pool HB` | High | Plate |
| `Attach owner + optional weapon init` | High | Body |
| `FUN_004f8430 role` | Medium | Unnamed |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| ctor base → set period → attach owner | Yes |
| No invent heat math | Yes |

---

## 5. Gaps / open

1. Name FUN_004f8430.
2. What weapon track tick does each 30 ms.

**Verdict:** **accept-with-gaps**
