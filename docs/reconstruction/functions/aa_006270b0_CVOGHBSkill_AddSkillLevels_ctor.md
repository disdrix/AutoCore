# Function record: CVOGHBSkill_AddSkillLevels_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_006270b0` |
| **Canonical name** | `CVOGHBSkill_AddSkillLevels_ctor` |
| **Ghidra name** | `FUN_006270b0` |
| **Address** | `0x006270b0`–`0x00627160` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **RTTI** | `.?AVCVOGHBSkill_AddSkillLevels@@` (COL `0x00aae638` → type_info `0x00af22b4`) |
| **Vtbl** | `PTR_FUN_009d1c54` @ `0x009d1c54` |
| **Parent base** | `CVOGHBSkillBase_ctor` @ `0x005788d0` |
| **Object size** | `0x6d0` (sole caller `operator_new`) |
| **Completion status** | **Dual sealed (R11-022)** — **accept-with-gaps** |
| **Terminal** | false |

## Purpose

Construct a `CVOGHBSkill_AddSkillLevels` heartbeat action:

1. `CVOGHBSkillBase_ctor` — skill blob, TFIDs, ValidateTarget, attach, period.
2. Override vtbl to `0x009d1c54`.
3. Install empty red-black map header at `this+0x6c4` (sentinel + size 0).
4. If `pTarget->vtbl+0x210(0) == 0`, force `AttachOwnerObject(this, null)` so the factory refuses Enqueue/Start.

## Signature

```c
CVOGHBSkill_AddSkillLevels* __thiscall CVOGHBSkill_AddSkillLevels_ctor(
    CVOGHBSkill_AddSkillLevels *this,
    void *pSource, void *pSkillBlob, void *arg4,
    void *pTarget, void *pTfid, void *arg7);
// ret 0x18
```

## Layout (ctor-owned)

| Offset | Field | Init |
|---|---|---|
| `+0x00` | vtbl | `0x009d1c54` |
| `+0x6c4` | map `_Myhead` | empty sentinel from `FUN_00439770` |
| `+0x6c8` | map `_Mysize` | `0` |

Base fields (`+0x18` owner, skill blob @ `+0x24`, etc.) owned by `CVOGHBSkillBase_ctor`.

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_006270b0_FUN_006270b0.md` |
| Annotated | `docs/reconstruction/raw/aa_006270b0_FUN_006270b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBSkill_AddSkillLevels_ctor.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_006270b0.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_006270b0_CVOGHBSkill_AddSkillLevels_ctor.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_006270b0_CVOGHBSkill_AddSkillLevels_ctor.md` |
| Report | `docs/agents/task-dual-ab-006270b0-r11-report.md` |

## Gaps

- Map key/value product type.
- Consumers/populators of `+0x6c4` on this vtbl.
- Object `vtbl+0x210` English.
- Runtime / bit-exact.

## Confidence

| Claim | Level |
|---|---|
| RTTI class | Confirmed |
| Ctor CF / ABI / empty map | High |
| Gate-on-fail detach | High |
| Level-add gameplay semantics | Open (not in this body) |
