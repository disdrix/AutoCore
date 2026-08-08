# Function record: CVOGHBSkill_SummonSnoop_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_006202f0` |
| **Canonical name** | `CVOGHBSkill_SummonSnoop_Ctor` |
| **Ghidra name** | `FUN_006202f0` |
| **Address** | `0x006202f0`–`0x00620323` |
| **Body size** | 52 bytes (`0x34`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Name confidence** | **Confirmed** class (RTTI); **High** ctor role |
| **Completion status** | **Dual residual sealed 2026-08-05 R11-016** — accept |
| **Bit-for-bit / runtime / diff** | Open (Terminal **false**) |
| **Dual A/B** | `reviews/A_aa_006202f0_CVOGHBSkill_SummonSnoop_Ctor.md`, `reviews/B_aa_006202f0_CVOGHBSkill_SummonSnoop_Ctor.md` |
| **Last reviewed** | `2026-08-05` (R11-016) |

## Alias

- `FUN_006202f0` (Ghidra)
- Scaffold: `Named_CalleeOf_Skill_Skill_d_had_invalid_template_d_006202f0` (**retired** — string is caller-side; class is RTTI SummonSnoop)

## Purpose

Construct a **`CVOGHBSkill_SummonSnoop`** heartbeat: `CVOGHBSkillBase_ctor` then install subclass vtbl `PTR_FUN_009d156c`. Sole CALL from `Skill_SpawnTemplateAndStartHB` after `operator_new(0x6c0)`.

## Signature

```c
CVOGHBSkill_SummonSnoop* __thiscall CVOGHBSkill_SummonSnoop_Ctor(
    CVOGHBSkill_SummonSnoop *this,  // ECX
    void *pSourceObj,               // → base TFID seed
    void *pSkillBlob,               // → base skill blob copy
    uint32_t arg4,                  // → this+0x688 (caller: WorldCtx*)
    void *pTarget,                  // ValidateTarget + AttachOwner (spawned entity)
    uint32_t *pTfid16,              // → this+0x690
    uint32_t arg7);                 // → this+0x6a8
// ret 0x18; EAX = this; object size 0x6c0
```

## Sealed facts

| Claim | Confidence |
|---|---|
| RTTI `.?AVCVOGHBSkill_SummonSnoop@@` | **Confirmed** |
| Vtbl `PTR_FUN_009d156c` | **Confirmed** |
| Base `CVOGHBSkillBase_ctor` @ `0x005788d0` | **Confirmed** |
| ABI `__thiscall` + `ret 0x18` | **Confirmed** |
| Sole CALL from `Skill_SpawnTemplateAndStartHB` | **Confirmed** |
| Object size `0x6c0` | **Confirmed** |
| No subclass field stores | **Confirmed** |
| Product design English | **Open** |

## Artifacts

| Kind | Path |
|---|---|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_006202f0_FUN_006202f0.md` |
| Annotated | `docs/reconstruction/raw/aa_006202f0_FUN_006202f0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBSkill_SummonSnoop_Ctor.cpp` |
| Clean scaffold | `docs/reconstruction/reconstructed-exact/FUN_006202f0.cpp` |
| Scaffold record | `docs/reconstruction/functions/aa_006202f0_FUN_006202f0.md` |
| Review A | `docs/reconstruction/reviews/A_aa_006202f0_CVOGHBSkill_SummonSnoop_Ctor.md` |
| Review B | `docs/reconstruction/reviews/B_aa_006202f0_CVOGHBSkill_SummonSnoop_Ctor.md` |
| Report | `docs/agents/task-dual-ab-006202f0-r11-report.md` |

## Callers / callees

| Direction | Notes |
|---|---|
| **Callee** | `CVOGHBSkillBase_ctor` (`0x005788d0`) |
| **Caller** | `Skill_SpawnTemplateAndStartHB` (`0x00620480`) @ `0x006208f4` |

## Related (not dualled here)

| VA | Role |
|---|---|
| `0x005788d0` | `CVOGHBSkillBase_ctor` (base; partition parent) |
| `0x00620480` | `Skill_SpawnTemplateAndStartHB` (sole caller; prior dual W19-E) |
| `0x00620340` | SummonSnoop OnHB-like peer (vtbl+0x04) |
| `0x00651190` | scalar deleting dtor (vtbl+0x00) |
| `0x009d156c` | subclass vtbl |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + bytes | **Confirmed** |
| Product class name | **Confirmed** (RTTI) |
| Parameter semantic names | High via base plate + caller map |
| Runtime / bit-exact | Open |
