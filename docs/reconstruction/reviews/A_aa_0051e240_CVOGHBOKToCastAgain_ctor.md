# Review A (reconstruction fidelity): `aa_0051e240` CVOGHBOKToCastAgain_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051e240` |
| **VA** | `0x0051e240` |
| **Canonical name** | `CVOGHBOKToCastAgain_ctor` |
| **Review date** | `2026-07-29` (dual residual seal; prior 2026-07-23) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0051e240_CVOGHBOKToCastAgain_ctor.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |
| **Scratch** | `reviews/a_0051e240.md` |

---

## 1. Purpose

Construct type-**8** "OK to cast again" heartbeat (`0x28` bytes from `Skill_StartCastAgainHeartbeat`).

```
durationMs = ROUND(ceil(skillCD@+0x10 × equipMod)) + chargeDelay
// equipMod: g_flOne if owner.vtbl+0x210()==0; else ST0 from Vehicle_GetSkillCooldownModifier
if owner.vtbl+0x1dc() pool with +0x6b4 >= 1: durationMs = min(durationMs, 500)
if skill+0x5e8 != -1: category map insert {key, now, duration} on **owner** map (+0x6c)
AttachOwner(**owner**); HB+0x24 = skill; HB+0x1c = 8
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0051e240_CVOGHBOKToCastAgain_ctor.md` |
| Annotated | `raw/aa_0051e240_CVOGHBOKToCastAgain_ctor.annotated.md` |
| Clean | `reconstructed-exact/CVOGHBOKToCastAgain_ctor.cpp` |
| Function record | `functions/aa_0051e240_CVOGHBOKToCastAgain_ctor.md` |
| Ghidra re-decompile | `0x0051e240` (2026-07-29) |
| Bytes | `read_memory` body `0x0051e240`–epilogue; `g_flOne` @ `0x00a0f2a0` |
| Caller dual | `aa_00519200` StartCastAgainHeartbeat (`RET 0xC` + 3 pushes) |
| Category siblings | `aa_00518df0` InsertCategoryCooldown; `aa_0051d2f0` Map_Insert; `aa_00518d70` GetMap |
| Residual scratch | `reviews/a_0051e240.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall` + **`RET 0xC`** (3 stack dwords) | **High** | epilogue `C2 0C 00` |
| Signature `(hb, owner, skill, chargeMs)` | **High** | regs EDI/EBX + caller pushes |
| Prior 2-stack plate | **Falsified** | under-counted |
| `CVOGHBBase_ctor` + vtbl `0x009ce1c4` + `SetPeriodAndCounter(1,1)` | **High** | body |
| Duration: ROUND(ceil(skill+0x10 × mod)) + charge → HB+0x8 | **High** | fild/ceil/fistp/add |
| Equip path via **owner**.vtbl+0x210 (not skill) | **High** | EDI vcalls |
| Null +0x210 → mod = **`g_flOne` (1.0)** not garbage | **High** | `read_memory` `0000803f` |
| Decomp `unaff_EBX` no-plant path | **Falsified** | |
| Clamp: owner.vtbl+0x1dc pool, `+0x6b4>=1`, cap **500** | **High** | `cmp 0x1F4` |
| Category insert if `skill+0x5e8 != -1` | **High** | |
| Insert pack `{key, DAT_00b041cc, HB+0x8}` | **High** | stack layout sealed |
| GetCategoryCooldownMap(**owner**) map @ +0x6c | **High** | `mov ecx,edi` |
| Decomp GetMap(skill) / Attach(skill) | **Falsified** | owner |
| `AttachOwnerObject(hb, owner)`; skill @ HB+0x24; type 8 @ +0x1c | **High** | |
| Category insert ABI open / CONCAT residual | **Closed** (this pass) | ≡ InsertCategoryCooldown |
| Product names for vtbl+0x210 / +0x1dc / +0x6b4 | **Open** | CF sealed |
| Full plant multiply math | **Sibling** | `Vehicle_GetSkillCooldownModifier` |

---

## 4. Control flow: clean ≡ raw ≡ asm

| Stage | Match |
|---|---|
| Base ctor + vtbl + period 1 | **Yes** |
| Owner vehicle gate + mod (1.0 or ST0) | **Yes** (clean updated 2026-07-29) |
| Duration + clamp 500 | **Yes** |
| Category map on owner + insert pack | **Yes** (plate fixed) |
| Attach owner; skill+0x24; type 8 | **Yes** |
| `RET 0xC` | **Yes** |

---

## 5. Asm-sealed signature

```c
void* __thiscall CVOGHBOKToCastAgain_ctor(
    void* thisHb,
    void* pOwnerEntity,
    void* pSkillRuntime,
    int   nChargeDelayMs);
// RET 0xC
```

---

## 6. Gaps / open

1. Product English / PDB for `owner.vtbl+0x210` (vehicle resolve) and `+0x1dc` (pool object).
2. Product meaning of pool `+0x6b4` (counter / specialMode collision still open as name only).
3. Exact stack args of second `+0x210` call (`skill+0x5ec` pointer role).
4. Full body dual of `Vehicle_GetSkillCooldownModifier` (plant `+0xCC` already topic-sealed elsewhere).
5. Runtime / bit-exact / image diff (matrix policy).

**Verdict:** **accept-with-gaps** — ABI, owner/skill split, duration formula, 500 clamp, no-vehicle **1.0**, category insert pack, type-8 identity **sealed High**; only English/runtime remain.
