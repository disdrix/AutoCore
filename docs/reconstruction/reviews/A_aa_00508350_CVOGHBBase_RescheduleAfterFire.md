# Review A (reconstruction fidelity): `aa_00508350` CVOGHBBase_RescheduleAfterFire

| Field | Value |
|---|---|
| **Stable ID** | `aa_00508350` |
| **VA** | `0x00508350` |
| **Canonical name** | `CVOGHBBase_RescheduleAfterFire` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00508350_CVOGHBBase_RescheduleAfterFire.md` |
| **System** | `heartbeat` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

After OnHeartBeat: if **nPeriodSentinel==-1000** → out delay Continue (0); else **decrement nPeriodCounter**, if still >0 Continue else out **g_dwTimedActionDefaultPeriodMs (16)**. Combat pool interval is TryFire vs nPeriodMs, **not** this 16ms default.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00508350_CVOGHBBase_RescheduleAfterFire.md` |
| Annotated | `docs/reconstruction/raw/aa_00508350_CVOGHBBase_RescheduleAfterFire.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBBase_RescheduleAfterFire.cpp` |
| Function record | `docs/reconstruction/functions/aa_00508350_CVOGHBBase_RescheduleAfterFire.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Sentinel -1000 → *out=Continue` | **High** | Combat pool |
| `Else nPeriodCounter--` | **High** | Body |
| `Counter>0 → Continue` | **High** | Burst periods |
| `Counter exhausted → 16 default` | **High** | List delay |
| `Does not stamp last fire (StampLastFireTime sibling)` | **High** | Separation |
| `Called from Regen / CreatureBase OnHeartBeat` | **High** | Call graph |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Sentinel path | **Yes** |
| Counter path | **Yes** |
| Out-param write | **Yes** |

---

## 5. Gaps / open

1. Relationship of nPeriodSentinel vs nPeriodMs same field views.
2. Who resets counter after 16 path.
3. Stack out-param residual in decomp.

**Verdict:** **accept-with-gaps**
