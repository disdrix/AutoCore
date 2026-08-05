# Function record: Skill_ValidateTarget_HBSkillListener

| Field | Value |
|---|---|
| **Stable ID** | `aa_005532e0` |
| **Canonical name** | `Skill_ValidateTarget_HBSkillListener` |
| **Address** | `0x005532e0` – `0x00553384` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Convention** | `__stdcall` (`ret 0x0C`) |
| **Completion status** | **SEALED** 2026-07-29 — full dual A/B + three-rep; type tag + RTTI path sealed |
| **Evidence** | RTTI `CVOGHBBase@0x00af8d98` → `CVOGHBSkillBase@0x00af8cec`; string `"Skill found with no base class: %d"`; sole predicate of `Skill_ValidateTargetForSkill` |
| **Dual** | `reviews/A\|B_aa_005532e0_Skill_ValidateTarget_HBSkillListener.md` |

---

## Purpose

`CNDDoubleList_InvokePredicateAndRemove_Inferred` match predicate over a target’s HB list. When node type `+0x1c == 1` and dynamic_cast to `CVOGHBSkillBase` succeeds with `+0x20 == 0`, re-invokes skill handler `skill+0x5F0` vtbl `+0x44(target, skill, hb)`.

| Handler result | Effect |
|---:|---|
| `1` | `ctx.result = 0` (reject ValidateTarget); `*stop = 1`; keep node |
| `2` | `ctx.result = 1`; `*stop = 1`; if `ctx.notifyHB` then `hb->vtbl+0x18(1,0)` and **remove** node |
| other | no ctx change from this node |

---

## Signature (assembly-backed)

```c
uint8_t __stdcall Skill_ValidateTarget_HBSkillListener(
    void* hbPayload,           // CVOGHBBase* list payload
    ValidateTargetCtx* ctx,    // +0 target, +4 skill, +8 result, +9 notify
    char* stopFlag);           // out stop-walk
// AL: 0 = keep node, 1 = remove node
```

---

## Type tag + RTTI (sealed)

| Item | Value | Conf |
|---|---|---|
| Type tag offset | HB `+0x1c` dword | **Confirmed** |
| Type tag value | **`1`** (skill base) | **Confirmed** |
| Tag writer | `CVOGHBSkillBase_ctor` @ `0x005788d0` | **Confirmed** |
| RTTI src | `0x00af8d98` `".?AVCVOGHBBase@@"` | **Confirmed** |
| RTTI dst | `0x00af8cec` `".?AVCVOGHBSkillBase@@"` | **Confirmed** |
| Cast API | `__RTDynamicCast(..., VfDelta=0, isRef=0)` | **Confirmed** |
| Active gate | HB `+0x20 == 0` (`cStopped`, High) | **Confirmed** gate |

---

## Callers

- `Skill_ValidateTargetForSkill` @ `0x00553650` (only) — DATA xref `0x00553684`

---

## Files

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005532e0_Skill_ValidateTarget_HBSkillListener.md` |
| Annotated | `docs/reconstruction/raw/aa_005532e0_Skill_ValidateTarget_HBSkillListener.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_ValidateTarget_HBSkillListener.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_005532e0_Skill_ValidateTarget_HBSkillListener.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005532e0_Skill_ValidateTarget_HBSkillListener.md` |

---

## Gaps (non-blocking)

1. Handler class at `skill+0x5F0` / vtbl+0x44 catalog.
2. HB `vtbl+0x18` product name / full semantics.
3. `+0x20` product English beyond High `cStopped`.
