# Review A (reconstruction fidelity): `aa_00519200` Skill_StartCastAgainHeartbeat

| Field | Value |
|---|---|
| **Stable ID** | `aa_00519200` |
| **VA** | `0x00519200` |
| **Canonical name** | `Skill_StartCastAgainHeartbeat` |
| **Review date** | `2026-07-29` (residual strengthen; prior quality refresh same day) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00519200_Skill_StartCastAgainHeartbeat.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |
| **Scratch** | `reviews/a_00519200.md` |

---

## 1. Purpose

Allocate `CVOGHBOKToCastAgain` (HB type-**8**, size **0x28**), construct with owner entity + skill runtime + charge delay, enqueue on world heartbeat list at `*(owner+0xa4)+0xe4ec`, then `CVOGHBBase_Start`. Client optimistic cooldown / cast-again overlay, sim apply path, accuracy-miss path, and restart-after-clear path. Duration formula lives in **ctor**, not here.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00519200_Skill_StartCastAgainHeartbeat.md` |
| Annotated | `raw/aa_00519200_Skill_StartCastAgainHeartbeat.annotated.md` |
| Clean | `reconstructed-exact/Skill_StartCastAgainHeartbeat.cpp` |
| Function record | `functions/aa_00519200_Skill_StartCastAgainHeartbeat.md` |
| Ghidra decompile | `0x00519200` (2026-07-29 residual) |
| Bytes | `read_memory` body `00519200` len 128; ctor tail `0051e340`; call sites Apply / LocalRange |
| Xrefs | `get_function_xrefs` → **6** unconditional CALL sites |
| Asm context | `get_assembly_context` all 6 callers (push/mov/call patterns) |
| Pcode | `get_function_pcode` high — confirms CF; under-counts ctor args vs bytes |
| Ctor dual / raw | `aa_0051e240` CVOGHBOKToCastAgain_ctor |
| Residual scratch | `reviews/a_00519200.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF: `new(0x28)` → ctor → `Enqueue(*( *(this+0xa4)+0xe4ec ))` → `Start` | **High** | decomp ≡ body bytes |
| Body range `00519200`–`00519279` | **High** | function info + epilogue |
| `__thiscall` + **`RET 0x8`** (`C2 08 00`) | **High** | epilogue bytes |
| Signature: `(ownerEntity, skillRuntime, chargeDelayMs)` | **High** | body loads + 6 call sites |
| Ctor arity **3 stack** (`RET 0xC`): `(hb, owner, skill, chargeMs)` | **High** | three pushes + ctor `C2 0C 00` |
| Type field HB **`+0x1c = 8`** written in ctor | **High** | `C7 46 1C 08 00 00 00` |
| World HB list offset **`+0xe4ec`** via **`this+0xa4`** | **High** | `8B 87 A4 00 00 00` / `8B 88 EC E4 00 00` |
| Null alloc still Enqueue/Start with **null** | **High** | `je` skips ctor only; no early return |
| Duration / category-map insert **not** in this unit | **High** | ctor-only |
| Plate names as 3 stack formals | **Falsified** | `RET 0x8` |
| Decomp `ctor(mem, this, (int)arg0)` only | **Falsified / incomplete** | missing skill stack arg |
| This unit prevents type-8 stacking | **Falsified** | always alloc; no dedup |
| Complete callers = **6** xrefs | **High** | includes LocalRangeTargetCheck |
| Charge source taxonomy (4 classes) | **High** | see §6 |
| Optimistic client role before C2S **0x2030** | **High** | RequestCast / QuickBar / Stance |
| Server CD authority | **Falsified** | client/sim HB overlay only |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| SEH → `operator_new(0x28)` | **Yes** |
| Ctor with owner + skill + charge | **Yes** (clean corrected; raw plate under-counts; **bytes authority**) |
| Enqueue world list `+0xe4ec` → Start | **Yes** |
| No network send in body | **Yes** |
| Null path still Enqueue/Start | **Yes** (clean matches) |

---

## 5. Asm-sealed signature

```c
void __thiscall Skill_StartCastAgainHeartbeat(
    void* pOwnerEntity,    // ECX; +0xa4 → world
    void* pSkillRuntime,   // stack0
    int   nChargeDelayMs); // stack1; source caller-dependent
// RET 0x8
```

Callees: `operator_new@00489892`, `CVOGHBOKToCastAgain_ctor@0051e240`, `CVOGHBList_Enqueue@005078f0`, `CVOGHBBase_Start@005081c0`.

---

## 6. Callers (complete, residual-sealed)

| Caller | Call VA | Charge | Gate snapshot |
|---|---|---|---|
| `Client_RequestCastSkill` | `0x00941731` | skill+**0x14** movsx | `+0x61c == 0` |
| `Client_QuickBarActivateSkillSlot` | `0x00921cfd` | skill+**0x14** movsx | `+0x61c == 0` |
| `Client_StanceOrGadgetActivatePath` | `0x0093a525` | skill+**0x14** movsx | `+0x61c == 0` |
| `Skill_ClearCastBindingAndMaybeRestartCd` | `0x0051a77c` | **0** | `+0x61c != 0` |
| `Skill_ApplyStatusEffectLocal` | `0x0051ac53` | packet+**0x10** | `world+0x7e != 0` ∧ `+0x61c == 0` |
| `Skill_LocalRangeTargetCheck` | `0x005531ac` | skill+**0x10** | accuracy miss + flag0; then ret **0x0f** |

---

## 7. Gaps / open

1. Live multi-HB stacking / hotbar vs server `esetCoolDown` timing.
2. LocalRange `[esp+0x14]` flag semantics (caller-owned).
3. Whether `Enqueue`/`Start` tolerate null HB (callee).
4. Runtime / bit-exact / image diff (matrix policy).
5. Original PDB symbol unknown.

**Verdict:** **accept-with-gaps** — ABI, type-8, list, null path, **6-caller set**, and charge taxonomy **sealed High**; only verification/runtime and cross-caller live policy remain.
