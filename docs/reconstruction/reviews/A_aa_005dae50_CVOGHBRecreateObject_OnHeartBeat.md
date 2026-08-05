# Review A (reconstruction fidelity): `aa_005dae50` CVOGHBRecreateObject_OnHeartBeat

| Field | Value |
|---|---|
| **Stable ID** | `aa_005dae50` |
| **VA** | `0x005dae50` |
| **Canonical name** | `CVOGHBRecreateObject_OnHeartBeat` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005dae50_CVOGHBRecreateObject_OnHeartBeat.md` |
| **System** | `combat` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Heartbeat **recreate/despawn-respawn object** (`CVOGHBRecreateObject::OnHeartBeat`). RTTI-casts owner to `CVOGPhysicsBase`; if missing body **+8**, ends HB (vtbl **+0x18**) and `CVOGHBBase_RescheduleAfterFire`. Else copies pose from phys **+0xcc** quat/pos, wraps physics debug/render pair `FUN_006c6d00`/`006c6d40` tags 10/0xb/0xc, `FUN_00560c90` transform, then either recreate `FUN_005dac00` or random delay via `CVOGReaction_RandomUnitScalar` + table lookup. Combat/world object lifecycle HB — not ghost pack.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005dae50_*.md` |
| Annotated | `docs/reconstruction/raw/aa_005dae50_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBRecreateObject_OnHeartBeat.cpp` |
| Function record | `docs/reconstruction/functions/aa_005dae50_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| RTTI cast to CVOGPhysicsBase; +8 body required | High | Body |
| Reschedule via CVOGHBBase_RescheduleAfterFire | High | Callee |
| FUN_005dac00 recreate path when local_12c==0 | High | Body |
| Random delay from reaction scalar table | High | Body |
| Exact recreate payload | Medium | FUN residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| cast → no body: end+resched; else pose+helpers → recreate or delay | Yes |

---

## 5. Gaps / open

1. Name FUN_005dac00 recreate body.
2. Seal delay formula (uVar1 % 0x14 + 0xc).

**Verdict:** **accept-with-gaps**
