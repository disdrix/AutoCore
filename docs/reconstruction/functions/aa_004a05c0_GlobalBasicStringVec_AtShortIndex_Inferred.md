# Function record: GlobalBasicStringVec_AtShortIndex_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a05c0` |
| **Canonical name** | `GlobalBasicStringVec_AtShortIndex_Inferred` |
| **Ghidra name** | `FUN_004a05c0` |
| **Address** | `0x004a05c0` |
| **Body** | `0x004a05c0`–`0x004a0629` inclusive (**106 B** / `0x6A`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | Global `basic_string` vector lookup |
| **Completion status** | **Dual sealed (W38-AF)** — accept |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Preferred: `GlobalBasicStringVec_AtShortIndex_Inferred`
- Reject: `Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable_004a05c0`

## Purpose

1. `count = (DAT_00b0360c == 0) ? 0 : (DAT_00b03610 - DAT_00b0360c) / 0x1c`
2. Index is **signed short** (`MOVSX`); if `count <= (uint)index` → construct empty string into out.
3. Else copy-construct from element at `begin + index * 0x1c`.
4. Return out (`__cdecl`, caller `ADD ESP,8`).

## Signature

```c
std::string* __cdecl GlobalBasicStringVec_AtShortIndex_Inferred(std::string* out, int16_t index);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004a05c0_FUN_004a05c0.md`
- Annotated: `docs/reconstruction/raw/aa_004a05c0_FUN_004a05c0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/GlobalBasicStringVec_AtShortIndex_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004a05c0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004a05c0_GlobalBasicStringVec_AtShortIndex_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_004a05c0_GlobalBasicStringVec_AtShortIndex_Inferred.md`
- Report: `docs/agents/task-dual-ab-00965600-004a05c0-w38af-report.md`

## Callers / callees

| **Callers** | `FUN_004b88e0` (×2), `FUN_00491480` (×2), `FUN_00491a00` (×2) |
| **Callees** | `basic_string` ctor empty; `basic_string` copy-ctor |

## Confidence

| Claim | Level |
|---|---|
| Control flow / stride / short index | **Confirmed** |
| cdecl out-string ABI | **Confirmed** |
| Product table owner | **Open** |
