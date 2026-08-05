# Review A (reconstruction fidelity): `aa_005d0310` CVOGHBAICreatureBase_OnHeartBeat

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d0310` |
| **VA** | `0x005d0310` |
| **Canonical name** | `CVOGHBAICreatureBase_OnHeartBeat` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005d0310_CVOGHBAICreatureBase_OnHeartBeat.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBAICreatureBase_OnHeartBeat.cpp` |
| Related | `AI_CheckSlotTimerReady`, `CVOGHBBase_RescheduleAfterFire`, `CVOGHBAIDriver_DoLogic` |
| System notes | `docs/NPC.md` § HBAI / OnHeartBeat |

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Scoped string `CVOGHBAICreatureBase::OnHeartBeat()` | **High** | Present in clean/raw |
| Owner at `this+0x18`; null → default status | **High** | Direct early return |
| Idle / engage / combat via `owner+0x26c` | **High** | Matches Driver DoLogic + NPC.md |
| Death/respawn at `owner+0x278` | **High** | Shared with FindTarget |
| Vehicle ref `owner+0x250` | **High** | Used in no-target bail + counters |
| `AI_CheckSlotTimerReady` on combat pulse | **High** | Call preserved |
| `CVOGHBBase_RescheduleAfterFire` on exit paths | **High** | Call preserved |
| Random period reseed via `CVOGReaction_RandomUnitScalar` | **High** CF; **Medium** semantic of `this+0x24/0x28` bases |
| Position snapshot `this+0x50..0x5c` from vtbl+0x1a0 | **High** | Store order preserved |
| Idle flags `owner+0x305..0x307` | **Medium** | Polarity/name inferred from use sites |
| FUN_005cd220 / FUN_005cc* helpers | **Medium** | Names open; roles probable patrol/engage |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Exception frame + scoped string | **Yes** |
| Null-owner early status | **Yes** |
| Timer / no-target / no-vehicle bail + reschedule | **Yes** |
| Branch tree around `owner+0x26c` / `+0x207` / combat latch `+0x6d` | **Yes** (large; plate summarizes) |
| Slot-timer + random fire gate | **Yes** |
| Reschedule / epilogue | **Yes** |

---

## 4. Gaps

1. Several `FUN_005cc*` / `FUN_005cd*` callees still unnamed (patrol vs engage helpers).
2. Exact meaning of `this+0x34` timer vs `DAT_00a0f518` threshold not sealed in types.
3. `pResult` / `pOutNextDelayMs` decompiler aliasing (HB status out-param) needs type registry.
4. Unreachable-block warning at `0x005d07cd` — cleaned plate notes CF from raw; bit-exact open.

**Verdict:** Heartbeat state machine and call order faithful to decompile. **accept-with-gaps.**
