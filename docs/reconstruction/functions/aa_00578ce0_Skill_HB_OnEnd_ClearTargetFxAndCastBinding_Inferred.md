# Function record: Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00578ce0` |
| **Canonical name** | `Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred` |
| **Address** | `0x00578ce0`–`0x00578de0` exclusive |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` |
| **Completion status** | **Dual sealed 2026-08-04 WQ9D-F** — trio + A/B; accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (no Launcher) |

## Alias

| Name | Role |
|---|---|
| `FUN_00578ce0` | Ghidra / scaffold |
| `Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred` | dual preferred |

## Purpose

Shared skill HB **OnEnd** (`vtbl+0x10`): client end-hook, resolve target, clear `+0x6b0` vector, owner notify `vtbl+0x238(1,…)`, optional `owner+0x26--`, clear cast binding when flag `0x02`, optional `FUN_0051f880(0)`, tail empty base OnEnd. Inverse polarity of `Skill_HB_FireTail_FxTargetAndPeriodStamp`.

## Signature

```c
void __fastcall Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred(void* hb /* ECX */);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00578ce0_FUN_00578ce0.md`
- Annotated: `docs/reconstruction/raw/aa_00578ce0_FUN_00578ce0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00578ce0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00578ce0_Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00578ce0_Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred.md`
- Scratch: `docs/reconstruction/tmp/a_00578ce0.md`

## Callers / callees

**Callers (CODE):** subclass OnEnd wrappers e.g. `FUN_006214f0`, `FUN_006148d0`, `FUN_006278c0`, `FUN_00614e90`, `FUN_006224f0`, `FUN_006186c0`, `FUN_00617bd0`, `FUN_006510b0`, …

**DATA:** many skill HB vtables slot **+0x10**.

**Callees:** `PTR_FUN_00af31e0`, `CVOGReaction_ResolveObjectTarget`, `FUN_00578ac0`, owner `vtbl+0x238`, `Skill_ClearCastBindingAndMaybeRestartCd`, target `vtbl+0x214/+0x210`, `FUN_0051f880`, tail `CVOGHBBase_EmptyVFunc`.

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + bytes | **High / Confirmed** |
| OnEnd role (vtbl+0x10) | **Confirmed** |
| FireTail inverse polarity | **Confirmed** |
| Parameter semantic names | **High** (offsets) / product English open |
| Types | **Probable** |
