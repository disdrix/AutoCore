# Review B (skeptical / independent): `aa_00606180` CVOGHBWakeupSkill_Fire_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00606180` |
| **VA** | `0x00606180` |
| **Canonical name** | `CVOGHBWakeupSkill_Fire_Inferred` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_00606180_CVOGHBWakeupSkill_Fire_Inferred.md` |
| **System** | `skills-abilities` / heartbeat |
| **Verdict** | **accept-with-gaps** — agree with A; keep `_Inferred` |

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_00606180` only | Acceptable scaffold; under-describes sealed class |
| `CVOGHBWakeupSkill_OnHeartBeat` | **Reject** — OnHeartBeat is `vtbl+0x0C` = RescheduleAfterFire on this vtbl |
| `CVOGHBWakeupSkill_OnEnd` | **Ambiguous** — Stop seals OnEnd at `+0x10`; EndOrDestroy dual calls `+0x14` "OnEnd" — two slots. Prefer Fire role over overloaded OnEnd |
| `CVOGHBWakeupSkill_Fire` without `_Inferred` | **Reject** — no method string/PDB |
| `CVOGHBWakeupSkill_Fire_Inferred` | **Accept** — class RTTI + apply role |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| ApplyEffects this is owner not skill | **Fails** — `lea ecx,[esi+0x24]`; ctor embeds skill at +0x24 |
| LocalCastValidate skill arg is skill@+0x24 | **Fails** — both pushes after flag are **0** |
| FUN_00514e00 this is HB | **Fails** — ECX is owner from `mov ecx,[esi+0x18]` before cmp |
| Function is TryFire body | **Fails** — TryFire is shared `0x005082c0` at vtbl+8; this is +0x14 only |
| Name without RTTI | **Fails** — type string + ctor vtbl write Confirmed |

---

## 3. Agreement with Review A

- CF owner gate / optional dec / validate / apply / empty tail: **agree Confirmed/High**
- Class RTTI: **agree Confirmed**
- Keep `_Inferred` on method: **agree**
- Gaps (product method English, runtime): **agree open**

---

## 4. Residual risks

- EndOrDestroy dual naming of `+0x14` as "OnEnd" may confuse future agents — document Fire vs Stop OnEnd explicitly (done in A §1).
- Null skill into LocalCastValidate is intentional for this path; do not invent a hidden skill push without new bytes.

**Verdict:** **accept-with-gaps**
