# Function record: Combat_ComputeBaseCritChance_FromHost

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c4dd0` |
| **Canonical name** | `Combat_ComputeBaseCritChance_FromHost` |
| **Ghidra name** | `FUN_004c4dd0` |
| **Prior aliases** | `Named_CalleeOf_Skill_Combat_Fighting_and_driving_ability_Affect_004c4dd0` (wrong parent string — Perception/crit, not Combat skill UI) |
| **Address** | `0x004c4dd0`–`0x004c4e1d` (77 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | combat-crit |
| **Completion status** | **Dual-sealed 2026-07-29 W23-K** — formula/ABI/constants/UI label **High**; host product type open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Compute **base critical-hit chance** fraction for the skill-host / bind path:

`chance = (FUN_004c41c0(host) + vcall(host_mi,+0x27c)) * 0.001f * 0.125f + 0.02f`

UI (`FUN_008f97c0`) presents this as **"Base Critical Hit Chance"**. Parent `Combat_ComputeCritChance_Inferred` calls this when attacker bind (`vtbl+0x214`) is non-null.

## Signature

```c
// __fastcall; ECX=host; ST0 return; no stack formals
float Combat_ComputeBaseCritChance_FromHost(void* host);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004c4dd0_FUN_004c4dd0.md` (+ W23-K append)
- Annotated: `docs/reconstruction/raw/aa_004c4dd0_FUN_004c4dd0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Combat_ComputeBaseCritChance_FromHost.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004c4dd0.cpp`
- Reviews: `reviews/A_aa_004c4dd0_Combat_ComputeBaseCritChance_FromHost.md`, `reviews/B_aa_004c4dd0_Combat_ComputeBaseCritChance_FromHost.md`
- Scaffold record: `docs/reconstruction/functions/aa_004c4dd0_FUN_004c4dd0.md`

## Callers / callees

| Direction | VA / name | Notes |
|---|---|---|
| Caller | `Combat_ComputeCritChance_Inferred` `0x004cef70` | bind path |
| Caller | `FUN_008f97c0` | character sheet UI |
| Callee | `FUN_004c41c0` | perception-capped score |
| Callee | vcall `+0x27c` | level-like int |

## Constants

| VA | Value | Role |
|---|---|---|
| `0x00a0f72c` | 0.001f | ms→s / per-point scale |
| `0x00a110c0` | 0.125f | bind-path scale |
| `0x00aaa7b8` | 0.02f | base floor add |

## Confidence

| Claim | Level |
|---|---|
| Formula + FPU order | **High** |
| ABI ECX + ST0 | **High** |
| UI label Base Critical Hit Chance | **High** |
| Role = bind-path base crit | **High** |
| Host product type English | **Probable** / open |
| `+0x27c` / `FUN_004c41c0` full semantics | **Open** (callee residual) |
