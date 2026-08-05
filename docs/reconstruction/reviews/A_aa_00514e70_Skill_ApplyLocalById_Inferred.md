# Review A (reconstruction fidelity): `aa_00514e70` Skill_ApplyLocalById_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00514e70` |
| **VA** | `0x00514e70` |
| **Canonical name (Ghidra)** | `FUN_00514e70` |
| **Proposed name** | `Skill_ApplyLocalById_Inferred` (**High** role; product name open) |
| **Prior scaffold alias** | `Named_CalleeOf_Named_VOG_DEBUG_STOP_00514e70` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile) |
| **Counterpart** | `reviews/B_aa_00514e70_Skill_ApplyLocalById_Inferred.md` |
| **System** | `skills-abilities` / local skill re-apply |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Host thiscall:** look up a skill instance by **skill id**, and if that skill’s active bit is set, **clear sibling casts** then either **queue a skill HB** or **immediately apply effects** on the host.

Used as the shared “re-fire / re-apply this skill’s local effects” leaf under refresh, rank-up, and skill-bag mutation paths — **not** wire cast validate, **not** S2C status apply entry (`Skill_ApplyStatusEffectLocal`).

### Control flow (summary)

1. `skill = host->vtbl[+0x234](skillId)` — resolve skill object by id.
2. Gate: `skill != 0` **and** `(skill+0x615) & 1` (active / apply-enabled bit).
3. `Skill_SiblingCastClear(skillId, hostTFID@host+0x160..+0x16c, flag=0)` via `FUN_00514e20` — stop matching cast HBs on host list `+0xB0` (sibling dual sealed).
4. Pack stack identity from `host[0x58..0x5b]` (= `host+0x160` TFID) and fill companion TFID slots from `g_abTfidInvalid_9CDF88` (16-byte invalid).
5. Branch:
   * **HB path** when `(short)(skill+0x14) > 0` **and** `host[0x29] != 0` **and** `*(host[0x29]+0xe4ec) != 0` (world/sim has HB list):
     * `operator_new(0x674)` + `FUN_006061e0(skillTypeShort, host, skill, world, &identity, &invalidTfid, 0, 0)`
     * `CVOGHBList_Enqueue(world+0xe4ec, action)` + `CVOGHBBase_Start(action)` → return.
   * **Else** if `host[0x29] != 0`:
     * `Skill_ApplyEffectsOnTarget_Inferred(skill, host, world, &identity, &invalidTfid, 0)` (`FUN_005538a0` — live symbol).

**Not** multi-target gather. **Not** sibling-clear alone. **Not** rank mutate (callers do that first).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x00514e70` |
| Callers | `get_function_callers` → `00516a00`, `00523e60`, `0052dc20`, `005304a0` |
| Callees | `get_function_callees` → SiblingCastClear, HB ctor `006061e0`, Enqueue/Start, ApplyEffects |
| Sibling dual | `A\|B_aa_00514e20_Skill_SiblingCastClear` |
| Refresh dual | `A\|B_aa_00516a00_Object_RefreshActiveSkillEffects_Inferred` |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_00514e70` |
| Function record | `docs/reconstruction/functions/aa_00514e70_FUN_00514e70.md` |

**This pass:** live decompile; callers/callees; dual cross-check. **Not performed:** Launcher, runtime, bit-exact, ledgers.

---

## 3. Signature

```c
// thiscall — ECX = host object (character / creature / vehicle host)
void __thiscall Skill_ApplyLocalById_Inferred(
    void *host,          // this — vtbl+0x234 lookup; TFID @ +0x160; world @ [0x29]
    uint32_t skillId);   // stack — id passed to vtbl lookup / sibling clear / apply
```

---

## 4. Callers / callees

| Callee | Role |
|---|---|
| `host->vtbl[+0x234](skillId)` | Resolve skill* by id |
| `Skill_SiblingCastClear` `0x00514e20` | Clear matching cast HBs (flag 0) |
| `FUN_006061e0` | Skill HB ctor (~0x674) from type short `@skill+0x14` |
| `CVOGHBList_Enqueue` `0x005078f0` | Queue on world list `+0xe4ec` |
| `CVOGHBBase_Start` `0x005081c0` | Start HB |
| `Skill_ApplyEffectsOnTarget_Inferred` `0x005538a0` | Immediate apply when HB path unavailable |

| Caller | Role |
|---|---|
| `Object_RefreshActiveSkillEffects_Inferred` `0x00516a00` | Walk active skills; re-apply each id |
| `FUN_00523e60` | Hash walk + `FUN_005536c0`; re-apply gated skills |
| `FUN_0052dc20` | After rank-up / skill-tree purchase; optional re-apply (`param_3==0`) |
| `FUN_005304a0` | After bag insert/set-rank; re-apply skill id |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| vtbl `+0x234` lookup by skillId | Yes |
| Gate `skill+0x615 & 1` | Yes |
| SiblingCastClear flag 0 + host TFID | Yes |
| Invalid TFID pack from `g_abTfidInvalid_9CDF88` | Yes |
| HB path: `skill+0x14>0` + world HB list | Yes |
| Else immediate ApplyEffects | Yes |
| SEH / `operator_new(0x674)` envelope | Yes |

Live decompile renames `FUN_005538a0` → `Skill_ApplyEffectsOnTarget_Inferred` (same VA); scaffold clean still shows `FUN_005538a0` — CF identical.

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role = local re-apply by skill id on host | **High** | callees + caller refresh/rank paths |
| Active gate `skill+0x615&1` | **High** | body; matches refresh dual |
| Sibling clear before re-apply | **High** | sealed sibling dual |
| HB vs immediate branch on `skill+0x14` short + world list | **High** CF | product field names open |
| Identity TFID = `host+0x160` (`[0x58]`) | **High** | sibling dual + body |
| `skill+0x14` product meaning (type/duration id) | **Probable** | ctor arg only |
| Product C++ name | **Tentative** | `_Inferred` |
| HB ctor product class for `006061e0` / size `0x674` | **Probable** skill-HB family | dual residual |

---

## 7. Gaps / open

1. Product name for `vtbl+0x234` lookup and `skill+0x14` field.
2. Full dual of `FUN_006061e0` (HB product class).
3. Whether immediate path target TFID-invalid means “self only” (Probable from pack).
4. Runtime / bit-exact not run.

**Verdict:** **accept-with-gaps** — CF High; product names open.
