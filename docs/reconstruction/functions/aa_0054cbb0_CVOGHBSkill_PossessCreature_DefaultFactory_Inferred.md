# Function record: CVOGHBSkill_PossessCreature_DefaultFactory_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054cbb0` |
| **Canonical name** | `CVOGHBSkill_PossessCreature_DefaultFactory_Inferred` |
| **Ghidra name** | `FUN_0054cbb0` |
| **Address** | `0x0054cbb0`–`0x0054cc02` (83 B / `0x53`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Class** | `CVOGHBSkill_PossessCreature` (RTTI Confirmed via parent dual `aa_00626240`) |
| **Vtbl** | `PTR_FUN_009d1ba4` |
| **Object size** | `0x6f0` |
| **Base init** | `CVOGHBSkillBase_DefaultCtor` (`0x00578830`) |
| **Parent dual** | `0x00626240` `CVOGHBSkill_PossessCreature_ctor` (R11-021) |
| **Partition** | `WAVE_2026-08-05_r12_residual_partition_map.md` → **R12-023** |
| **Dual start** | 2646 |
| **Completion status** | **Dual A/B sealed (R12-023)** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (Terminal false) |

## Purpose

Default heap factory for PossessCreature skill heartbeat objects: `operator_new(0x6f0)`, run skill-base default ctor, install subclass vtbl `0x009d1ba4`, return pointer or null. Not the full-arg subclass ctor.

## Signature (image-sealed)

```c
// cdecl; 0 args; bare RET; EAX = object* or null
void *CVOGHBSkill_PossessCreature_DefaultFactory_Inferred(void);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0054cbb0_FUN_0054cbb0.md`
- Annotated: `docs/reconstruction/raw/aa_0054cbb0_FUN_0054cbb0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBSkill_PossessCreature_DefaultFactory_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0054cbb0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0054cbb0_CVOGHBSkill_PossessCreature_DefaultFactory_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_0054cbb0_CVOGHBSkill_PossessCreature_DefaultFactory_Inferred.md`
- Report: `docs/agents/task-dual-ab-0054cbb0-r12-report.md`
- Scaffold record: `docs/reconstruction/functions/aa_0054cbb0_FUN_0054cbb0.md`

## Callers / callees

| Direction | Address / name | Notes |
|---|---|---|
| Code CALL | *(none)* | 0 UNCONDITIONAL_CALL xrefs |
| DATA | `0x009d1bec` | factory function pointer = `0x0054cbb0` |
| Callee | `operator_new` | size `0x6f0` |
| Callee | `CVOGHBSkillBase_DefaultCtor` `0x00578830` | dualed W23-S; thiscall ECX=alloc |

## Related (not OWN this dual)

| Unit | Role |
|---|---|
| `0x00626240` `CVOGHBSkill_PossessCreature_ctor` | full-arg subclass ctor (parent dual R11-021) |
| site `0x006263ab` | full-ctor path: new(0x6f0) then `00626240` |
| `0x0054a640` type id `0x1a` | skill-element registry (same size/vtbl family) |
| vtbl methods on `0x009d1ba4` | non-OWN method duals |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ bytes | **High** |
| ABI cdecl / 0 args / bare RET / return ptr | **High** |
| Size 0x6f0 + vtbl 0x009d1ba4 | **High** |
| Base default ctor callee | **High** (rel call + dualed unit) |
| Class name via parent RTTI | **High** (inherited Confirmed) |
| Role English "DefaultFactory" | **Inferred** |
| Runtime | Open |
