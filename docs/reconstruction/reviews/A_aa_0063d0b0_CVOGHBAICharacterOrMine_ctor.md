# Review A (reconstruction fidelity): `aa_0063d0b0` CVOGHBAICharacterOrMine_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0063d0b0` |
| **VA** | `0x0063d0b0` |
| **Canonical name** | `CVOGHBAICharacterOrMine_ctor` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0063d0b0_CVOGHBAICharacterOrMine_ctor.md` |
| **System** | `npc-ai` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Shared **mid-size** HBAI ctor for Character (AICode **1**) and Mine (AICode **4**); also parent of **Driver** (AICode 5). Chains `CVOGHBAIBase_ctor`, installs mid vtbl `PTR_LAB_009e3e40`, seeds `[0x38..0x3b]=g_flOne`, zeros `[0x30..0x37]` and `[0x3c..0x43]`, sets `param_1[4]=DAT_00aaa668`. Factory size **0x110**.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0063d0b0_CVOGHBAICharacterOrMine_ctor.md` |
| Annotated | `docs/reconstruction/raw/aa_0063d0b0_CVOGHBAICharacterOrMine_ctor.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBAICharacterOrMine_ctor.cpp` |
| Function record | `docs/reconstruction/functions/aa_0063d0b0_CVOGHBAICharacterOrMine_ctor.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Chains CVOGHBAIBase_ctor` | **High** | First call |
| `Vtbl PTR_LAB_009e3e40` | **High** | Character/Mine mid |
| `[0x38..0x3b]=g_flOne (4 floats)` | **High** | Body |
| `Zeros [0x30..0x37] and [0x3c..0x43]` | **High** | Extended mid state |
| `param_1[4]=DAT_00aaa668` | **High** | Constant seed |
| `Factory size 0x110 for AICode 1/4/5` | **High** | CreateByAICode |
| `Driver chains this then swaps Driver vtbl` | **High** | Driver_ctor dual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Base + vtbl + float seed + zero blocks | **Yes** |
| No invented logic | **Yes** |

---

## 5. Gaps / open

1. Semantic names for [0x30..0x43] slots Driver relies on.
2. DAT_00aaa668 identity (global float/int constant).
3. Character profile-redirect to Creature in CreateByAICode is outside this body.

**Verdict:** **accept-with-gaps**
