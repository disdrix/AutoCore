# Function record: CVOGHBAI_UpdateAimOffset_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005cedf0` |
| **Canonical name** | `CVOGHBAI_UpdateAimOffset_Inferred` |
| **Ghidra name** | `FUN_005cedf0` |
| **Address** | `0x005cedf0`–`0x005cf558` (**1897 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | HB AI aim-offset state |
| **Completion status** | **Sealed dual A/B accept** (W26-O 2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Alias

- Ghidra: `FUN_005cedf0`
- Prior scaffold: `Named_CalleeOf_CVOGHBAIDriver_DoLogic_005cedf0`

## Purpose

Tick AI **aim-offset** state: arm on still+active-pose-drift, wait 1.5s, build randomized local XZ offset transformed to world via object pose, store at `this+0x40`. Clear on owner/phys loss, 6s TTL, or owner near stored offset.

## Signature (sealed)

```c
void __fastcall CVOGHBAI_UpdateAimOffset_Inferred(void *this /* ECX */);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005cedf0_FUN_005cedf0.md`
- Annotated: `docs/reconstruction/raw/aa_005cedf0_FUN_005cedf0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBAI_UpdateAimOffset_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_005cedf0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_005cedf0_CVOGHBAI_UpdateAimOffset_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_005cedf0_CVOGHBAI_UpdateAimOffset_Inferred.md`

## Callers / callees

| Direction | Targets |
|---|---|
| **Callees** | `FUN_004c3ac0`, `FUN_005d6870`, `FUN_005d1d20`, `FUN_004e8bf0`, `CVOGReaction_RandomUnitScalar` (+ vtbls) |
| **Callers** | `CVOGHBAIDriver_DoLogic`, `FUN_005d7f70`, `CVOGHBAICreatureBase_OnHeartBeat`, `FUN_005d7ca0` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **High** |
| ECX this / void | **High** |
| Constants (read_memory) | **High** |
| Aim-offset role (inferred) | **High** (global name + fields) |
| Product class English | **Open** |
| Runtime RNG / bit-exact | **Open** |
