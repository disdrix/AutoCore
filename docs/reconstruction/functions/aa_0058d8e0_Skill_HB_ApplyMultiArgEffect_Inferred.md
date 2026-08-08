# Function record: Skill_HB_ApplyMultiArgEffect_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058d8e0` |
| **Canonical name** | `Skill_HB_ApplyMultiArgEffect_Inferred` |
| **Ghidra name** | `FUN_0058d8e0` |
| **Address** | `0x0058d8e0`–`0x0058d95d` |
| **Body size** | **126 B** / `0x7E` (pad `CC CC` at `0x0058d95e`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Name confidence** | **High** role (HB multi-arg → multi-hit wrapper); product English **Inferred** |
| **Completion status** | **Dual residual sealed 2026-08-05 MEGA-009** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

- Ghidra: `FUN_0058d8e0`
- Partition hint: `Skill_HB_ApplyMultiArgEffect`
- Parent dual language: “multi-arg apply” cascade arm under shared OnHeartBeat

## Purpose

Skill-HB **multi-arg combat effect** leaf used by the shared heartbeat pulse when bit0 of skill field `+0x648` is set. Builds a **single-entry TFID list** from `object+0x160` terminated by global null TFID, then invokes dualed multi-target hit apply. Returns summed damage.

## Signature (sealed)

```c
// __cdecl; bare ret; EAX = damage sum (0 if object null)
int Skill_HB_ApplyMultiArgEffect_Inferred(
    void *combatSource,
    void *objectWithTfidAt160,
    void *damageEffectBlob,
    uint32_t unusedParam4,
    void *rollTable,
    int rollSeedIndex);
```

## Sealed facts

| Claim | Confidence |
|---|---|
| Body **126 B**, bare `ret` both exits | **High** |
| `__cdecl` 6 stack formals; caller `ADD ESP,0x18` | **High** |
| Null-check `param_2`; copy TFID_16 @ `+0x160` | **High** |
| Terminator `DAT_009d4d28..34` = `ff..ff ff..ff 0 0` | **High** |
| Sole callee `Skill_ApplyMultiTargetHits_Inferred` | **High** |
| Parent gate bit0 @ `+0x648` on shared pulse | **High** |
| Return = multi-hit damage sum | **High** |
| Product symbol | **Open** |

## Parent call pack (`0x0061b8f9` in `CVOGHBSkill_SharedOnHeartBeat_Inferred`)

| Formal | Source |
|---|---|
| param_1 | `FUN_00578270(skill)` — reaction-resolved object |
| param_2 | `skill[+0x18]` — owner/object (TFID source) |
| param_3 | `&skill[+0x24]` — damage/effect blob |
| param_4 | `skill[+0x688]` — forwarded; unused in multi-hit |
| param_5 | `skill[+0x6a0]` — roll table |
| param_6 | `skill[+0x6c8]` — pulse counter (roll seed) |

## Artifacts

- Raw (+ MEGA-009 re-verify): `docs/reconstruction/raw/aa_0058d8e0_FUN_0058d8e0.md`
- Annotated: `docs/reconstruction/raw/aa_0058d8e0_FUN_0058d8e0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Skill_HB_ApplyMultiArgEffect_Inferred.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_0058d8e0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0058d8e0_Skill_HB_ApplyMultiArgEffect_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_0058d8e0_Skill_HB_ApplyMultiArgEffect_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_0058d8e0_FUN_0058d8e0.md`

## Prior alias

No `Named_CalleeOf_*` scaffold existed for this VA. Scaffold machine name `FUN_0058d8e0` retained as twin clean/record only.

## Peer / chain

| Unit | Role |
|---|---|
| `CVOGHBSkill_SharedOnHeartBeat_Inferred` (`0x0061b6f0`) | parent pulse (dualed) |
| `Skill_ApplyMultiTargetHits_Inferred` (`0x0058c850`) | sole callee (dualed W20-Q) |
| `Skill_HB_ApplyHeatDelta` / `ApplyHpDelta` / `ApplyShieldPool` / `ApplyShortAndFloater` | sibling cascade arms (other MEGA owners) |
