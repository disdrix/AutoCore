# Review A (reconstruction fidelity): `aa_0063c940` CVOGHBAIBase_Default_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0063c940` |
| **VA** | `0x0063c940` |
| **Canonical name** | `CVOGHBAIBase_Default_ctor` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0063c940_CVOGHBAIBase_Default_ctor.md` |
| **System** | `npc-ai` |
| **Verdict** | **accept** |

---

## 1. Purpose

Factory **fallback** HBAI when AICode is unrecognized (CreateByAICode default). Chains `CVOGHBAIWalkingCreatureTurreted_ctor`, installs default vtbl `PTR_FUN_009e3d40`, zeros `param_1[4]`, calls `FUN_0063a700(0)`, seeds `param_1[0x1f]=g_flOne`. Factory size family **0xD0** (same as AICode 6).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0063c940_CVOGHBAIBase_Default_ctor.md` |
| Annotated | `docs/reconstruction/raw/aa_0063c940_CVOGHBAIBase_Default_ctor.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBAIBase_Default_ctor.cpp` |
| Function record | `docs/reconstruction/functions/aa_0063c940_CVOGHBAIBase_Default_ctor.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Chains WalkingCreatureTurreted_ctor` | **High** | First call |
| `Vtbl PTR_FUN_009e3d40 (default)` | **High** | Store *this |
| `param_1[4]=0` | **High** | Body |
| `FUN_0063a700(0) post-init helper` | **High** | Shared with Turreted |
| `param_1[0x1f]=g_flOne` | **High** | Scalar seed |
| `Factory size 0xD0 default branch` | **High** | CreateByAICode |
| `Not used for known AICode 1..6` | **High** | Only switch default |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Parent + vtbl + seed | **Yes** |
| No invented fields beyond raw | **Yes** |

---

## 5. Gaps / open

1. Meaning of FUN_0063a700(0) and slot [0x1f].
2. Whether default vtbl shares any DoLogic vs OnHeartBeat slots with Turreted.
3. Retail frequency of unknown AICode hitting this path.

**Verdict:** **accept**
