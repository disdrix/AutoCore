# Function record: Mission_EnsureRegionMissions

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053fff0` |
| **Canonical name** | `Mission_EnsureRegionMissions` |
| **Address** | `0x0053fff0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` |
| **Completion status** | **Sealed (wave3 2026-07-29)** — dual A/B accept; `+0xf18` wrapper layout sealed; secondary index keys residual |
| **Bit-for-bit / runtime / diff** | Static seal only (Ghidra decompile + bytes); runtime open |

## Alias

| Name | Notes |
|---|---|
| `FUN_0053fff0` | Ghidra default |
| `Mission_EnsureRegionMissions` | Role name (method English product open) |
| `Named_CalleeOf_Client_RecvNpcMissionDialog_0053fff0` | Prior scaffold alias |
| Mission table lazy getter | Wave3 partition label |

## Purpose

Lazy-ensure the **`CVOGRegionMissions`** (product path `VOGRegionMissions.cpp`) object at **`owner+0xf18`** and return that **wrapper\***.

- First call: `operator_new(0x10)` + `FUN_0060b870` ctor (builds four hashes and populates from WAD vector or DB).
- Later calls: return cached pointer.
- Callers needing mission-id lookup: `hash = *wrapper` then `CNDHash_*`.

## Signature

```c
// MSVC __fastcall — ECX = owner
void* __fastcall Mission_EnsureRegionMissions(void* owner);
// returns *(owner + 0xf18)  // CVOGRegionMissions* wrapper, may be null if OOM on first init
```

## Wrapper at `owner+0xf18` (0x10)

| Off | Role |
|---|---|
| `+0x0` | Primary mission-id `CNDHash*` (`FUN_0053b0b0(8)`) |
| `+0x4` | Objective-side `CNDHash*` (`FUN_0053b1b0(8)`) |
| `+0x8` | Extended hash 0x38 (`PTR_FUN_009df688`) |
| `+0xC` | Extended hash 0x38 (same shape) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0053fff0_FUN_0053fff0.md`
- Annotated: `docs/reconstruction/raw/aa_0053fff0_FUN_0053fff0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Mission_EnsureRegionMissions.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0053fff0_Mission_EnsureRegionMissions.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0053fff0_Mission_EnsureRegionMissions.md`
- Residual seal: `docs/reconstruction/reviews/a_0053fff0.md`
- Ctor (related): `docs/reconstruction/functions/aa_0060b870_FUN_0060b870.md`

## Callers / callees

**Callees:** `operator_new`, `FUN_0060b870` (`Mission_VOGRegionMissions` ctor).

**High-signal callers:** GiveMission, SearchAutoMissions, HasCompletedMission, CompleteMissionObjectives, CheckMissionPrerequisites, CompleteObjective, ApplyCreateFromPacket, EvalOfferableMissionInteractState, EvalInteractStateFromChildren, RecvNpcMissionDialog, ShowNpcMissionDialogUI, UpdateMissionJournal, EvaluateComputed (+ residual `FUN_*`).

**Typical `this`/ECX:** `DAT_00b041fc`; dialog: `*(clientCtx+0xd30)`.

## Confidence

| Claim | Level |
|---|---|
| Control flow / lazy slot / return wrapper\* | **High** |
| Wrapper 4-hash layout | **High** |
| Primary hash = `*wrapper` | **High** |
| Class `CVOGRegionMissions` | **High** (path string) |
| Method product English | **Open** |
| Secondary index key domains | **Tentative / residual** |
