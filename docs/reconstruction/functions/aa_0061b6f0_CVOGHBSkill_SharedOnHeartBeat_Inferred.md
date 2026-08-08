# Function record: CVOGHBSkill_SharedOnHeartBeat_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0061b6f0` |
| **Canonical name** | `CVOGHBSkill_SharedOnHeartBeat_Inferred` |
| **Ghidra symbol** | `FUN_0061b6f0` |
| **Address** | `0x0061b6f0` |
| **Body** | `0x0061b6f0`–`0x0061b955` exclusive (**613** B / `0x265`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / CVOGHB skill heartbeat |
| **Completion status** | **Sealed** — dual A/B accept-with-gaps (WQ9D-C 2026-08-04) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Ghidra: `FUN_0061b6f0`
- Virus dual residual: “Shared pulse `FUN_0061b6f0`” (`aa_0061fdf0`)
- Prior scaffold name only

## Purpose

Default multi-class skill heartbeat **OnHeartBeat** pulse. Installed at **vtbl+0x08** for many `CVOGHBSkill_*` classes (RTTI-sampled: **Chain**, **InverseChain**, **Aggregate**). Also invoked as a **subroutine** by specialized overrides (`CVOGHBSkill_Virus_OnHeartBeat`, range-gated `FUN_0061ba80`).

Runs shared reschedule/status (`FUN_005787a0`), increments pulse counter, then optionally applies a cascade of combat side-effects (heat, HP, shield, floater, multi-arg apply, phys impulse) scaled by HB fields before a post-pulse virtual (`vtbl+0x50`). Writes status to out-arg.

## Signature (sealed)

```c
// __thiscall; ECX = skill HB*; stack = uint32_t *pOutStatus; void; RET 4
void __thiscall CVOGHBSkill_SharedOnHeartBeat_Inferred(
    int32_t *thisHb, uint32_t *pOutStatus);
```

## Key fields (this HB)

| Offset | Role (inferred) |
|---|---|
| +0x0c | state dword (`>1` or `==-1000` gate) |
| +0x18 | owner/object ptr (param_1[6]) |
| +0x20 | char flag (must be 0 to apply effects) |
| +0x44 | char flag → flag8 hard-stop path |
| +0x60 / +0x64 / +0x110 / +0x114 / +0x144 | float effect scales |
| +0x74 | short damage amount |
| +0x648 / +0x649 | effect enable bits |
| +0x668 | TFID_16 source (via `FUN_0061b960`) |
| +0x6c4 | float intensity scale |
| +0x6c8 | pulse counter (++) |

## Constants

| Symbol | VA / value | Role |
|---|---|---|
| `DAT_00af4bd0` | `0x00af4bd0` = **0x10** | status gate (skip effects when equal); near `"Health"` string |
| `g_flZero` | `0x00a0f518` | zero float compare |

## Artifacts

- Raw (+ WQ9D-C re-verify): `docs/reconstruction/raw/aa_0061b6f0_FUN_0061b6f0.md`
- Annotated: `docs/reconstruction/raw/aa_0061b6f0_FUN_0061b6f0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBSkill_SharedOnHeartBeat_Inferred.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_0061b6f0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0061b6f0_CVOGHBSkill_SharedOnHeartBeat_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_0061b6f0_CVOGHBSkill_SharedOnHeartBeat_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_0061b6f0_FUN_0061b6f0.md`

## Callers / callees

| Direction | Targets |
|---|---|
| **Code callers** | `FUN_0061ba80`, `CVOGHBSkill_Virus_OnHeartBeat` (`0061fdf0`) |
| **DATA (vtbl)** | 9 skill vtbl slots at +0x08 (Chain / InverseChain / Aggregate / …) |
| **Callees** | `FUN_005787a0`, `Object_ResolveTargetViaReaction_Inferred` (`00578270`), `00589bc0` heat, `00589c70` HP, `00589d90` shield, `0058cc40`, `0058d8e0`, `0058c3b0` impulse, `FUN_0061b960` TFID, `Object_HasFlag8SelfOrLinked` (`005134e0`) |

## Confidence

| Claim | Level |
|---|---|
| CF + ABI thiscall / ret 4 | **High** |
| Shared OnHeartBeat role (vtbl+0x08 multi-class) | **High** |
| RTTI sample classes install this slot | **Confirmed** |
| Effect cascade order / gates | **High** (decompile ≡ raw) |
| Field English / product skill design | **Inferred** / open |
| Dual of `FUN_005787a0` / effect leaves | residual (not OWN) |
| Runtime / differential | Open |
