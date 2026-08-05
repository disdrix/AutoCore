# Review A (reconstruction fidelity): `aa_00639830` CVOGHBAIWalkingCreatureTurreted_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00639830` |
| **VA** | `0x00639830` |
| **Canonical name** | `CVOGHBAIWalkingCreatureTurreted_ctor` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00639830_CVOGHBAIWalkingCreatureTurreted_ctor.md` |
| **System** | `npc-ai` |
| **Verdict** | **accept** |

---

## 1. Purpose

Construct **WalkingCreatureTurreted** HBAI (AICode **6**). Chains `CVOGHBAIBase_ctor`, installs vtbl `PTR_LAB_009e3cc0`, zeros `param_1[0x30]` and `param_1[4]`, `FUN_0063a700(0)`, seeds `param_1[0x1f]=g_flOne`. Factory size **0xD0**. CreateByAICode **skips** post-ctor profile vtbl trio for this AICode only. Also mid-base for Default_ctor.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00639830_CVOGHBAIWalkingCreatureTurreted_ctor.md` |
| Annotated | `docs/reconstruction/raw/aa_00639830_CVOGHBAIWalkingCreatureTurreted_ctor.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBAIWalkingCreatureTurreted_ctor.cpp` |
| Function record | `docs/reconstruction/functions/aa_00639830_CVOGHBAIWalkingCreatureTurreted_ctor.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Chains CVOGHBAIBase_ctor` | **High** | First call |
| `Vtbl PTR_LAB_009e3cc0` | **High** | Turreted |
| `param_1[0x30]=0; param_1[4]=0` | **High** | Body |
| `FUN_0063a700(0)` | **High** | Shared helper |
| `param_1[0x1f]=g_flOne` | **High** | Same as Default |
| `Factory size 0xD0` | **High** | CreateByAICode case 6 |
| `No post-ctor profile trio in factory` | **High** | CreateByAICode dual |
| `Parent of Default_ctor` | **High** | Default body |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Base + vtbl + zeros + helper + seed | **Yes** |
| No invented clamps | **Yes** |

---

## 5. Gaps / open

1. Why factory skips profile post-init only for case 6.
2. Retail rarity of AICode 6 in tCreatureAI.
3. FUN_0063a700 meaning.

**Verdict:** **accept**
