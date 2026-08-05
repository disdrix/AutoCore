# Function record: Skill_HB_SpawnEntities_ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00614dc0` |
| **Canonical name** | `Skill_HB_SpawnEntities_ctor_Inferred` |
| **Prior / Ghidra name** | `FUN_00614dc0` |
| **Address** | `0x00614dc0`–`0x00614e36` (**119 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skill / CVOGHB multi-entity spawn action ctor |
| **Completion status** | **accept** — dual A/B sealed 2026-07-29 (W25-N OWN) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- `FUN_00614dc0`
- Prior auto: `Named_CalleeOf_Skill_Skill_d_had_invalid_creature_d_00614dc0` (xref-path noise; not product role)

## Purpose

Construct the **CVOGHBSkillBase subclass** used as the per-spawn skill HB for multi-entity spawn:

1. `CVOGHBSkillBase_ctor` (base skill HB)
2. Install vtbl `PTR_FUN_009d0ec4`
3. Cache skill vfunc `+0x27c` result as `uint16` at `this+0x6c4`

Sole caller: execute path `new(0x6d0)` → ctor → Enqueue/Start.

## Signature (sealed)

```c
// __thiscall this (ECX); stack 6 formals; ret 0x18; return this*
void* Skill_HB_SpawnEntities_ctor_Inferred(
    void* self /*ECX*/,
    void* skill_or_source,
    void* a3, void* a4, void* target, void* a6, void* a7);
```

## Key fields

| Path | Value |
|---|---|
| `*this` | `PTR_FUN_009d0ec4` |
| `this+0x6c4` | `uint16` from skill `vfunc+0x27c` |
| Alloc size | `0x6d0` (caller) |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00614dc0_FUN_00614dc0.md` |
| Annotated | `docs/reconstruction/raw/aa_00614dc0_FUN_00614dc0.annotated.md` |
| Clean (named) | `docs/reconstruction/reconstructed-exact/Skill_HB_SpawnEntities_ctor_Inferred.cpp` |
| Clean (FUN_*) | `docs/reconstruction/reconstructed-exact/FUN_00614dc0.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_00614dc0_Skill_HB_SpawnEntities_ctor_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00614dc0_Skill_HB_SpawnEntities_ctor_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00614dc0_FUN_00614dc0.md` |

## Callers / callees

| Direction | Symbol | VA / notes |
|---|---|---|
| Callee | `CVOGHBSkillBase_ctor` | `0x005788d0` |
| Caller | `Skill_HB_SpawnEntities_Execute_Inferred` | `0x00615b97` (sole) |
| vtbl peer | Precheck | `0x006170b0` (+0x1c) |
| vtbl peer | Execute | `0x00615020` (+0x2c) |

## Confidence

| Claim | Level |
|---|---|
| CF: base → vtbl → cache ushort | **High** |
| ECX=this, ret 0x18, return this | **High** |
| rel32 base ctor | **High** |
| Product English subclass name | **Inferred** |
| Runtime / bit-exact | **Open** |
