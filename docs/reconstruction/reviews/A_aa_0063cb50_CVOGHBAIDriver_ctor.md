# Review A (reconstruction fidelity): `aa_0063cb50` CVOGHBAIDriver_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0063cb50` |
| **VA** | `0x0063cb50` |
| **Canonical name** | `CVOGHBAIDriver_ctor` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0063cb50_CVOGHBAIDriver_ctor.md` |
| **System** | `npc-ai` |
| **Verdict** | **accept** |

---

## 1. Purpose

Construct vehicle-driver HBAI (AICode **5**, DR profiles). Chains `CVOGHBAICharacterOrMine_ctor`, installs Driver vtbl `PTR_LAB_009e3dc0`. Factory size **0x110**. Main tick is **DoLogic** (not CreatureBase_OnHeartBeat).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0063cb50_CVOGHBAIDriver_ctor.md` |
| Annotated | `docs/reconstruction/raw/aa_0063cb50_CVOGHBAIDriver_ctor.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBAIDriver_ctor.cpp` |
| Function record | `docs/reconstruction/functions/aa_0063cb50_CVOGHBAIDriver_ctor.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Chains CharacterOrMine_ctor` | **High** | Mid-size parent |
| `Vtbl PTR_LAB_009e3dc0` | **High** | Driver |
| `No extra field zero beyond parent` | **High** | Body is short |
| `Factory size 0x110` | **High** | CreateByAICode case 5 |
| `DoLogic is main tick` | **High** | Architecture docs |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Parent + vtbl | **Yes** |
| No invented init | **Yes** |

---

## 5. Gaps / open

1. CharacterOrMine mid fields Driver relies on.
2. Whether any Driver-only fields zeroed in parent.

**Verdict:** **accept**
