# Function record: Skill_HB_FireTail_FxTargetAndPeriodStamp

| Field | Value |
|---|---|
| **Stable ID** | `aa_00578b30` |
| **Canonical name** | `Skill_HB_FireTail_FxTargetAndPeriodStamp` (**INFERRED** structural) |
| **Ghidra name** | `FUN_00578b30` |
| **Address** | `0x00578b30`–`0x00578cda` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / heartbeat |
| **Completion status** | **Dual A/B sealed** (W21-C 2026-07-29) — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

| Name | Notes |
|---|---|
| `FUN_00578b30` | Ghidra / scaffold |
| `Skill_Skill_d_has_invalid_frequency_d` | prior auto alias from string |
| `Skill_HB_FireTail_FxTargetAndPeriodStamp` | structural dual name |

## Purpose

Shared skill heartbeat **fire tail**:

1. Empty hook `FUN_004648a0`.
2. Resolve object target.
3. Owner present → optional `owner+0x26` bump (flag `0x10`), FX resolve event **0x16**, attach via vtbl+`0xf8`, mission-fail notify side path.
4. Target present → optional `FUN_00518ca0` / `FUN_0051f880` gated by flags and target vfuncs.
5. Period finalize: one-shot (`sentinel==-1000 && periodMs==0`) → Stop+Stamp; else clamp `periodMs` floor **300** when `sentinel!=1`; always StampLastFireTime.

## Signature (sealed)

```c
// ECX = this; void; plain RET
void Skill_HB_FireTail_FxTargetAndPeriodStamp(void *skillHb);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00578b30_FUN_00578b30.md`
- Annotated: `docs/reconstruction/raw/aa_00578b30_FUN_00578b30.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Skill_HB_FireTail_FxTargetAndPeriodStamp.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00578b30.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00578b30_Skill_HB_FireTail_FxTargetAndPeriodStamp.md`
- Review B: `docs/reconstruction/reviews/B_aa_00578b30_Skill_HB_FireTail_FxTargetAndPeriodStamp.md`

## Callers / callees

**Callers:** `CVOGHBMissionPatrol_Tick` `0x00650f90`, `FUN_006148a0`, `FUN_00617b40`, `FUN_00618270`, `FUN_0061f930`, `FUN_00620340`, `FUN_00626890`, `FUN_00627850`.

**Callees:** `FUN_004648a0`, `CVOGReaction_ResolveObjectTarget`, `FxCache_EnsureMasterAndResolve` (`0x005408f0`), owner/target vfuncs, `CVOGReaction_FailMissionNotify`, `FUN_004b7e50`, `FUN_00518ca0`, `FUN_0051f880`, `CVOGHBBase_Stop`, `CVOGHBBase_StampLastFireTime`, `FUN_007a4480`.

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ live ≡ bytes | **Confirmed** |
| `+0x08` periodMs floor 300; `+0x0C` sentinel −1000/1 gates | **Confirmed** |
| ECX this, void, stamp exit | **Confirmed** |
| FX event `0x16` + skillKey `+0x620` | **Confirmed** |
| Nested vtbl+0xf8 arg packing details | **Probable** (decomp / bytes) |
| Product/PDB English | **Open** |
| Runtime / differential | **Open** |
