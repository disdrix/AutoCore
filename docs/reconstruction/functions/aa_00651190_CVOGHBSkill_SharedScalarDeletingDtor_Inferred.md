# Function record: CVOGHBSkill_SharedScalarDeletingDtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00651190` |
| **Canonical / inferred name** | `CVOGHBSkill_SharedScalarDeletingDtor_Inferred` |
| **Ghidra name** | `FUN_00651190` |
| **Address** | `0x00651190`–`0x006511ae` exclusive (**30 B** / `0x1E`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` |
| **ABI** | `__thiscall` — ECX=this; stack `uint8_t flags`; **`ret 4`**; EAX=this |
| **Completion status** | **Dual A/B sealed (R12-001)** — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (Terminal false) |

## Purpose

Shared MSVC **scalar deleting destructor** for the `CVOGHBSkill_*` subclass family:

1. Always invoke `FUN_00578a60` (CVOGHBSkillBase complete dtor) via JMP thunk `0x00548f90`.
2. If `(flags & 1)` → `operator_delete(this)`.
3. Return `this`.

Installed as **vtbl slot 0** on many skill subclass tables (Master, XPAdder, SpawnEntities family, …). Not the base-class scalar at `0x00578de0`.

## Naming

| Gate | Result |
|---|---|
| Role sealed (scalar dtor) | **Yes** |
| Single-class RTTI on this VA | **No** (multi-vtbl share) → **`_Inferred`** |
| Product demangle | **Absent** |
| Collision with `CVOGHBSkillBase_ScalarDeletingDtor` | Avoided (that name is `0x00578de0`) |

## Signature

```c
void *__thiscall CVOGHBSkill_SharedScalarDeletingDtor_Inferred(void *thisHb, uint8_t flags);
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00651190_FUN_00651190.md` |
| Annotated | `docs/reconstruction/raw/aa_00651190_FUN_00651190.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBSkill_SharedScalarDeletingDtor_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00651190.cpp` |
| Ghidra record | `docs/reconstruction/functions/aa_00651190_FUN_00651190.md` |
| Dual A | `docs/reconstruction/reviews/A_aa_00651190_CVOGHBSkill_SharedScalarDeletingDtor_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_00651190_CVOGHBSkill_SharedScalarDeletingDtor_Inferred.md` |
| Report | `docs/agents/task-dual-ab-00651190-r12-report.md` |

## Related (not OWN)

| VA | Role |
|---|---|
| `0x00578a60` | Complete dtor body (SkillBase) |
| `0x00548f90` | JMP thunk → complete body |
| `0x00578de0` | Base-class scalar deleting dtor |
| `0x00508630` | `CVOGHBBase_ScalarDeletingDtor` |
| `0x00614c80` | Master Execute (owner-null → this VA with flags=1) |
