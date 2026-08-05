# Review A (reconstruction fidelity): `aa_004f7e10` Vehicle_EnsureRegenerationHeartbeat

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f7e10` |
| **VA** | `0x004f7e10` |
| **Canonical name** | `Vehicle_EnsureRegenerationHeartbeat` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004f7e10_Vehicle_EnsureRegenerationHeartbeat.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Create/enqueue combat-pool heartbeat action once per vehicle (slot **vehicle+0x27C**). Guards on map/owner context (**+0xa8** family) and existing action. Creates combat pool timed action used for HP/shield/heat/power regen ticks. Idempotent ensure pattern — does not double-create if slot filled.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004f7e10_Vehicle_EnsureRegenerationHeartbeat.md` (or `aa_004f7e10_FUN_004f7e10.md`) |
| Annotated | `docs/reconstruction/raw/aa_004f7e10_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Vehicle_EnsureRegenerationHeartbeat.cpp` |
| Function record | `docs/reconstruction/functions/aa_004f7e10_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Once-per-vehicle slot +0x27C` | High | Plate |
| `Combat pool HB not weapon track` | High | Name + plate |
| `Idempotent ensure` | High | Gate existing |
| `Owner/map context gates` | High | Body +0xa8 path |
| `Exact HB period here vs ActivateEnterWorld` | Medium | May defer to ctor |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| If no HB and context ok → create/enqueue | Yes |
| No invent weapon track 30ms | Yes |

---

## 5. Gaps / open

1. Confirm period ownership (this vs ActivateEnterWorld).
2. Name FUN attach helpers.

**Verdict:** **accept-with-gaps**
