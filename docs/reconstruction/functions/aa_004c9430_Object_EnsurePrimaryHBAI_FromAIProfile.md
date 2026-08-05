# Function record: Object_EnsurePrimaryHBAI_FromAIProfile

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c9430` |
| **Canonical name** | `Object_EnsurePrimaryHBAI_FromAIProfile` |
| **Ghidra name** | `FUN_004c9430` |
| **Address** | `0x004c9430` |
| **Body range** | `0x004c9430`–`0x004c96a9` (**634 B** inclusive last byte of `RET 8`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | npc-ai / host HB list / AI profile map |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF/ABI/factory table sealed; product type English open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_004c9430_Object_EnsurePrimaryHBAI_FromAIProfile.md`, `reviews/B_aa_004c9430_Object_EnsurePrimaryHBAI_FromAIProfile.md` |
| **Last reviewed** | `2026-07-29` (W27-I) |

## Alias

- `FUN_004c9430` (Ghidra)
- Prior scaffold: `aa_004c9430_FUN_004c9430`

## Purpose

If `this+0x1fc` is empty, look up the host AI-profile map by key (`param_3` or def `+0x4dc`), allocate the HBAI subclass matching profile node word `+0x10` (types 2/3/4/5/default), store pointer, enqueue on `CVOGHBList` at host `+0xe4ec`, and `Start` (or `Stop` when `param_2==0` and host flag `+0x7e`). Optionally create secondary `FUN_005d6b80` HB when def `+0x4e8==1`. Refresh skill effects when clone type `!=0x14`.

## Signature

```c
// Machine: __thiscall + SEH; RET 8
void * __thiscall Object_EnsurePrimaryHBAI_FromAIProfile(
    void *self,
    char deferStopIfHostFlag,
    char profileKeyOrMinus1);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004c9430_FUN_004c9430.md` (+ W27-I append)
- Annotated: `docs/reconstruction/raw/aa_004c9430_FUN_004c9430.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Object_EnsurePrimaryHBAI_FromAIProfile.cpp`
- Scaffold twin: `docs/reconstruction/reconstructed-exact/FUN_004c9430.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-004c9430-005d7ca0-w27i-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Xrefs** | DATA `0x009cfe54`, `0x009cbf34` (no Ghidra code callers listed) |
| **Callees** | `Host_AIProfileMap_GetOrReset` ×2, `Map_LowerBoundFindByIntKey_Isnil65`, `operator_new`, `FUN_005d8330`/`005d7f50`/`005d7de0`/`005d7bb0`/`005d6da0`/`005d6b80`, `CVOGHBList_Enqueue` ×2, `CVOGHBBase_Start` ×2, `CVOGHBBase_Stop`, `Object_RefreshActiveSkillEffects_Inferred` |

## Offsets

| Off | Role |
|---|---|
| `this+0x1fc` | Primary HBAI/HB pointer (already-present gate + store) |
| `this+0x200` | Type bitmask `1<<(word&0x1f)` |
| profile node `+0x10` | uint16 type word (switch) |
| def `+0x4dc` | default profile key when param_3==-1 |
| def `+0x4e8` | secondary HB enable (==1) |
| host `+0xe4ec` | CVOGHBList* |
| host `+0x7e` | defer-stop gate with param_2 |

## Confidence

| Claim | Level |
|---|---|
| thiscall + RET 8 + SEH | **High** |
| Factory switch 2/3/4/5/default sizes | **High** |
| Enqueue + Start/Stop policy | **High** |
| Name (no plate string) | **Probable** (`_FromAIProfile` structural) |
| Product type English | **Open** |
| Runtime / bit-exact | Open |
