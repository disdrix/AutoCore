# Function record: Skill_HB_ClearPtrVectorAt6b0_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00578ac0` |
| **Canonical name** | `Skill_HB_ClearPtrVectorAt6b0_Inferred` |
| **Ghidra name** | `FUN_00578ac0` |
| **Address** | `0x00578ac0`–`0x00578b28` inclusive (**0x69 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` |
| **Parent dual** | `aa_00578ce0` Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred |
| **Completion status** | **Dual sealed MEGA-014** — verdict **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (Terminal false) |

## Purpose

OnEnd helper: destroy the skill HB pointer vector at `+0x6b0` (owned `NDSpecialFX*` elements). Called once from shared OnEnd after target resolve, before owner notify / cast-binding clear.

## Signature

```c
// __thiscall; ECX = skill HB this; no stack args; plain RET
void Skill_HB_ClearPtrVectorAt6b0_Inferred(void *hb);
```

## Semantics (sealed)

1. Iterate `[begin, end)` at `hb+0x6b0` / `+0x6b4` (stride 4).
2. For each non-null `p`: `NDSpecialFX_TeardownCore_Inferred(p)` then `operator_delete(p)`.
3. If `begin` non-null: `operator_delete(begin)`.
4. Zero `+0x6b0`, `+0x6b4`, `+0x6b8` **unconditionally**.

## Artifacts

| Kind | Path |
|---|---|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00578ac0_FUN_00578ac0.md` |
| Annotated | `docs/reconstruction/raw/aa_00578ac0_FUN_00578ac0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Skill_HB_ClearPtrVectorAt6b0_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00578ac0.cpp` |
| FUN record | `docs/reconstruction/functions/aa_00578ac0_FUN_00578ac0.md` |
| Dual A | `docs/reconstruction/reviews/A_aa_00578ac0_Skill_HB_ClearPtrVectorAt6b0_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_00578ac0_Skill_HB_ClearPtrVectorAt6b0_Inferred.md` |
| Report | `docs/agents/task-dual-ab-00578ac0-mega-014-report.md` |

## Callers / callees

- **Caller:** sole — `Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred` @ `0x00578d18`.
- **Callees:** `NDSpecialFX_TeardownCore_Inferred` (`0x004b99c0`); `operator_delete` (`0x00489822`).

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / offsets | **Confirmed** (bytes) |
| Sole OnEnd caller | **Confirmed** (1 xref) |
| Element class = NDSpecialFX teardown | **High** (dualed callee) |
| Product vector field name | **Inferred** (`_Inferred`) |
| Runtime Confirmed | **Open** |

## Gaps

- Product / PDB symbol for HB field and method.
- Vector fill / push site (FireTail-adjacent residual).
- Runtime / bit-exact / differential.
