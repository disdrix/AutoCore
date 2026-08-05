# Review A (reconstruction fidelity): `aa_005d3d10` CVOGHBAI_CreateByAICode

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d3d10` |
| **VA** | `0x005d3d10` |
| **Canonical name** | `CVOGHBAI_CreateByAICode` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005d3d10_CVOGHBAI_CreateByAICode.md` |
| **System** | `npc-ai` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Factory: allocate and construct HBAI subclass for creature **AICode** (int switch; decomp float bit-patterns 1.4e-45=1 …). Alloc via `DAT_00b05060` vtbl+0x10(size, 0x29); size stamps at +4. Cases: 1 Character/Mine (0x110, profile redirect to Creature), 2 CreatureBase (0x100), 3 Bot (0x100), 4 Mine (0x110), 5 Driver (0x110), 6 WalkingTurreted (0xD0), default Base_Default (0xD0). Post-ctor (except 6): vtbl+0x2c/+0x3c/+0x1c from profile floats.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005d3d10_CVOGHBAI_CreateByAICode.md` |
| Annotated | `docs/reconstruction/raw/aa_005d3d10_CVOGHBAI_CreateByAICode.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBAI_CreateByAICode.cpp` |
| Function record | `docs/reconstruction/functions/aa_005d3d10_CVOGHBAI_CreateByAICode.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `AICode switch as int via float bit-pattern cases` | **High** | 1..6 + default |
| `Alloc DAT_00b05060 vtbl+0x10(size,0x29)` | **High** | All cases |
| `Size stamp uint16 @ alloc+4` | **High** | 0x100/0x110/0xD0 |
| `1 Character → CharacterOrMine unless profile redirect` | **High** | ABS sum gate → Creature |
| `2 CreatureBase_ctor 0x100` | **High** | Default foot AI |
| `3 Bot_ctor 0x100` | **High** | Summons |
| `4 Mine → CharacterOrMine 0x110` | **High** | Shares mid-ctor |
| `5 Driver_ctor 0x110` | **High** | DR vehicle |
| `6 WalkingCreatureTurreted 0xD0` | **High** | No post-ctor profile trio |
| `default Base_Default 0xD0` | **High** | Fallback |
| `Post-ctor vtbl init from param_3 profile` | **High** | +0x2c/+0x3c/+0x1c except case 6 |
| `param_1 float / unaff_EDI residuals` | **Probable** | Decomp framing |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Switch + alloc sizes | **Yes** |
| Ctor dispatch per case | **Yes** |
| Post-ctor profile init (non-6) | **Yes** |
| No invented AICode values | **Yes** |

---

## 5. Gaps / open

1. Exact profile float indices (param_3[5]/[10]/*) meaning for Character redirect.
2. g_flMultiKillCountBlend use in Character→Creature gate (name may be misapplied BSS).
3. Which callers pass AICode from tCreatureAI.
4. Runtime factory capture per AICode.

**Verdict:** **accept-with-gaps**
