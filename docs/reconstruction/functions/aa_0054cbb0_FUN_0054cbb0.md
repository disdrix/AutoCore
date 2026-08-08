# Function record: FUN_0054cbb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054cbb0` |
| **Canonical name** | `CVOGHBSkill_PossessCreature_DefaultFactory_Inferred` |
| **Ghidra name** | `FUN_0054cbb0` |
| **Address** | `0x0054cbb0`–`0x0054cc02` (83 B / `0x53`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Completion status** | **Dual A/B sealed (R12-023)** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (Terminal false) |

## Purpose

Default factory for `CVOGHBSkill_PossessCreature`: `operator_new(0x6f0)` → `CVOGHBSkillBase_DefaultCtor` → install vtbl `0x009d1ba4` → return object* or null.

## Signature (image-sealed)

```c
void *FUN_0054cbb0(void);
// cdecl; bare RET; EAX = object* or null
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0054cbb0_FUN_0054cbb0.md`
- Annotated: `docs/reconstruction/raw/aa_0054cbb0_FUN_0054cbb0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/CVOGHBSkill_PossessCreature_DefaultFactory_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0054cbb0.cpp`
- Named record: `docs/reconstruction/functions/aa_0054cbb0_CVOGHBSkill_PossessCreature_DefaultFactory_Inferred.md`
- Review A: `docs/reconstruction/reviews/A_aa_0054cbb0_CVOGHBSkill_PossessCreature_DefaultFactory_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_0054cbb0_CVOGHBSkill_PossessCreature_DefaultFactory_Inferred.md`
- Report: `docs/agents/task-dual-ab-0054cbb0-r12-report.md`

## Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Code CALL | none | 0 callers |
| DATA | `0x009d1bec` | factory ptr |
| Callee | `operator_new` | `0x6f0` |
| Callee | `FUN_00578830` / `CVOGHBSkillBase_DefaultCtor` | thiscall |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ bytes | **High** |
| ABI / size / vtbl | **High** |
| Named role | **Inferred** |
| Runtime | Open |
