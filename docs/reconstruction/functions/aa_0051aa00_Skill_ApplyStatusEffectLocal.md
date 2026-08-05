# Function record: Skill_ApplyStatusEffectLocal

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051aa00` |
| **Canonical name** | `Skill_ApplyStatusEffectLocal` |
| **Address** | `0x0051aa00` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Calling convention** | `__fastcall` — ECX=`pCasterObj`, EDX=`nInferred` (unused), stack packet + local flag |
| **Return type** | `int` (0 ok, `0x11` binding-present/cancel-skip, `2` fail) |
| **System** | skills-abilities |
| **Completion status** | **Human-refined + dual residual sealed** (2026-07-29) — runtime open |
| **Bit-for-bit / runtime / diff** | Open |

---

## 1. Summary

Local consumer of a SkillStatusEffect (`0x2031`) workspace. Loads or materializes skill runtime (learned tree vs item/reaction), may cancel an active cast binding (local return `0x11`), starts optimistic cast-again heartbeat on sim (`world+0x7e`), builds compact TFID list from packet targets, then either applies immediately via `Skill_ApplyEffectsOnTarget_Inferred` (`lDelayTime < 1`) or enqueues a delayed `CVOGHBWakeupSkill` heartbeat (size `0x674`).

**Not** the wire cancel path: Recv handles `eSkillResponses==0x11` (`CANCELLED_ACTIVE`) separately and does not call this unit.

---

## 2. Signature

```c
int __fastcall Skill_ApplyStatusEffectLocal(
    void* pCasterObj,   // ECX — source object from packet TFID
    int   nInferred,    // EDX — decompiler pollution / unused
    void* pPacket,      // 0x2031 buffer
    char  bIsLocalCaster);
```

---

## 3. Behavior (exact outline)

1. `packet+0x38 == 0` → lookup skill on caster (`vtbl+0x234`); load+rank if missing; reevaluate if rank sum (`+0x5f6 + +0x174`) ≠ packet level.
2. Else → `CVOGReaction_ResolveSkillTargets` (item/reaction).
3. Skill null → debug stop, return `2`.
4. Sim (`world+0x7e`): maybe rewrite `packet+0x3c` (dice seed) via random helper.
5. Non-item: if active binding present → set status `0x11`, clear binding; early `return 0x11` if binding TFID == first packet target **or** `skill+0x614&1` **or** invalid packet target; on sim start cast-again HB unless `skill+0x61c`, clear counter.
6. Item: `Skill_InsertCategoryCooldown(skill+0x5e8, delay + skill+0x10)`.
7. Copy `(size-0x40)/0x18` TFIDs (16B each from 0x18 stride).
8. Presentation hooks; if delay `<1` `Skill_ApplyEffectsOnTarget_Inferred` else `CVOGHBWakeupSkill_ctor` + enqueue + Start; optional VFX when not local caster.
9. Free list; non-item return status; item frees temp skill.

---

## 4. Related artifacts

| Kind | Path |
|---|---|
| Raw / annotated | `raw/aa_0051aa00_Skill_ApplyStatusEffectLocal.*` |
| Clean | `reconstructed-exact/Skill_ApplyStatusEffectLocal.cpp` |
| Dual residual scratch | `reviews/a_0051aa00.md` |
| Reviews | `A|B_aa_0051aa00_Skill_ApplyStatusEffectLocal.md` (+ legacy reconstruction/skeptical) |
| Callees sealed | `Skill_ApplyEffectsOnTarget_Inferred` `0x005538a0`; `CVOGHBWakeupSkill_ctor` `0x006061e0` |
| Callers | `aa_00811170` RecvSkillStatusEffect; `aa_004d09a0` CastSkillOnTarget |
| Topic | `docs/topic-extractions/skill-cast.md` |

---

## 5. Confidence

| Dimension | Level |
|---|---|
| Control flow | **High** |
| Packet field map (body-used) | **High** |
| Skill offsets (overlay→byte) | **High** (`sizeof(CVOGHBBase)==0x28`) |
| WakeupSkill ctor name | **Confirmed** (RTTI) |
| ApplyEffectsOnTarget name | **High** role / Inferred product |
| Return code semantics | **High** (local vs wire split) |
| Convention formals | **High**; EDX contents **Probable** unused |
| Overall | **Human-refined; dual residual sealed; runtime open** |

---

## 6. Open questions

1. English name for `skill+0x614` bit0 (cancel-on-reapply).
2. Product names for `FUN_00514e00` / `FUN_00514e20` (roles sealed).
3. Runtime / bit-exact / image diff (matrix policy).
