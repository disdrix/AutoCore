# Function record: FUN_004cef70 / Combat_ComputeCritChance_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cef70` |
| **Canonical name** | `Combat_ComputeCritChance_Inferred` |
| **Ghidra name** | `FUN_004cef70` |
| **Address** | `0x004cef70`–`0x004cf07c` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | combat-crit |
| **Completion status** | **Dual-sealed W22-A** — raw append + annotated + clean + A/B reviews |
| **Bit-for-bit / runtime / diff** | Body hex sealed via `read_memory`; runtime histogram open |

## Alias

Prior scaffold chain name (`Named_CalleeOf_…VOG_DEBUG_ST_…`) is **not** product truth. Structural name from sole combat consumer `Combat_RollCritMultiplier_Inferred`.

## Purpose

Return crit **chance** float (ST0). Fallback without skill bind: `level * 0.00025 + 0.05`. With bind: `FUN_004c4dd0` base, plus attacker `FUN_004c3140` bonus, minus target `FUN_004c3120` resist; floor at `0.05`.

## Signature (sealed)

```c
// cdecl; ST0
float Combat_ComputeCritChance_Inferred(void *attacker, void *target /*nullable*/);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004cef70_FUN_004cef70.md` (+ 2026-07-29 W22-A append)
- Annotated: `docs/reconstruction/raw/aa_004cef70_FUN_004cef70.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Combat_ComputeCritChance_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004cef70.cpp`
- Reviews: `reviews/A_aa_004cef70_Combat_ComputeCritChance_Inferred.md`, `reviews/B_aa_004cef70_Combat_ComputeCritChance_Inferred.md`

## Callers / callees

| Direction | Address / name | Notes |
|---|---|---|
| Caller | `0x004cf0bf` `FUN_004cf080` | Combat roll mult |
| Caller | `0x00839a01` `FUN_00838e20` | UI path |
| Callee | `FUN_004c4dd0` | skill-table base |
| Callee | `FUN_004c3140` | atk bonus +0x1d8/+0x1dc |
| Callee | `FUN_004c3120` | tgt resist +0x1e0/+0x1e4 |

## Confidence

| Claim | Level |
|---|---|
| CF + fallback formula bytes | **High** |
| cdecl / ST0 return | **High** |
| Combat role via 004cf080 | **High** |
| Product English name | **Probable** (inferred OK) |
| `vtbl+0x1d4` English | **Open** |
| `FUN_004c4dd0` internals | **Open** (sibling) |
