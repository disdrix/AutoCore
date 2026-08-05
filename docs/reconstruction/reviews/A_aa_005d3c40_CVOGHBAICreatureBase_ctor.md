# Review A (reconstruction fidelity): `aa_005d3c40` CVOGHBAICreatureBase_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d3c40` |
| **VA** | `0x005d3c40` |
| **Canonical name** | `CVOGHBAICreatureBase_ctor` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005d3c40_CVOGHBAICreatureBase_ctor.md` |
| **System** | `npc-ai` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Construct foot-creature HBAI (AICode **2**): chain `CVOGHBAIBase_ctor`, install CreatureBase vtbl `PTR_LAB_009dab50`, zero extended slots param_1[0x30..0x3f]. Factory size **0x100**. Main tick is OnHeartBeat for non-drivers.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005d3c40_CVOGHBAICreatureBase_ctor.md` |
| Annotated | `docs/reconstruction/raw/aa_005d3c40_CVOGHBAICreatureBase_ctor.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBAICreatureBase_ctor.cpp` |
| Function record | `docs/reconstruction/functions/aa_005d3c40_CVOGHBAICreatureBase_ctor.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Chains CVOGHBAIBase_ctor` | **High** | First call |
| `Vtbl PTR_LAB_009dab50` | **High** | CreatureBase |
| `Zeros [0x30..0x3f]` | **High** | Extended state |
| `Factory size 0x100` | **High** | CreateByAICode case 2 |
| `Returns this` | **High** | Body |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Base chain + vtbl + zero | **Yes** |
| No extra logic | **Yes** |

---

## 5. Gaps / open

1. Meaning of each [0x30..] slot (timers/flags).
2. Whether Driver shares these slots via CharacterOrMine mid.

**Verdict:** **accept-with-gaps**
