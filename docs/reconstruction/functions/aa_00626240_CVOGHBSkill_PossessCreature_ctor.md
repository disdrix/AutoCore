# Function record: CVOGHBSkill_PossessCreature_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00626240` |
| **Canonical name** | `CVOGHBSkill_PossessCreature_ctor` |
| **Ghidra name** | `FUN_00626240` |
| **Address** | `0x00626240`–`0x006262e4` (165 B / `0xA5`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Class** | `CVOGHBSkill_PossessCreature` (RTTI Confirmed `.?AVCVOGHBSkill_PossessCreature@@`) |
| **Vtbl** | `PTR_FUN_009d1ba4` |
| **Object size** | `0x6f0` |
| **Parent** | `CVOGHBSkillBase_ctor` (`0x005788d0`) |
| **Completion status** | **Dual A/B sealed (R11-021)** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (Terminal false) |

## Purpose

Construct the PossessCreature skill heartbeat subclass: skill-base ctor, install vtbl, clear subclass flags, dyn-cast target to `CVOGCreature*` at `+0x6c0`, optional non-fatal `VOG_DEBUG_STOP` on cast fail, return `this`.

## Signature (image-sealed)

```c
void *__thiscall CVOGHBSkill_PossessCreature_ctor(
    void *self,
    void *pSourceObj,
    void *pSkillBlob,
    uint32_t arg4,
    void *pTarget,
    void *pTfid,
    uint32_t arg7);
// ret 0x18; EAX = self
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00626240_FUN_00626240.md`
- Annotated: `docs/reconstruction/raw/aa_00626240_FUN_00626240.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBSkill_PossessCreature_ctor.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00626240.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00626240_CVOGHBSkill_PossessCreature_ctor.md`
- Review B: `docs/reconstruction/reviews/B_aa_00626240_CVOGHBSkill_PossessCreature_ctor.md`
- Report: `docs/agents/task-dual-ab-00626240-r11-report.md`

## Callers / callees

| Direction | Address / name | Notes |
|---|---|---|
| Caller (code) | `0x006263ab` | sole full-ctor site; factory `operator_new(0x6f0)` then this |
| DATA | `FUN_0054a640` @ type id `0x1a` | registry stub installs same vtbl |
| DATA | `FUN_0054cbb0` | default factory: new(0x6f0)+base+vtbl |
| Callee | `CVOGHBSkillBase_ctor` `0x005788d0` | parent |
| Callee | `__RTDynamicCast` | ClonedObjectBase→Creature |
| Callee | `FUN_007a4480` | debug stop helper |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ bytes | **High** |
| ABI thiscall / ret 0x18 / 6 args | **High** |
| RTTI class name | **Confirmed** |
| Parameter product English (source/skill/target) | **High** via parent dual |
| Non-OWN vtbl method English | Open |
| Runtime | Open |
