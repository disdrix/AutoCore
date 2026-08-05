# Function record: FUN_005aed20 (scaffold twin)

| Field | Value |
|---|---|
| **Stable ID** | `aa_005aed20` |
| **Canonical name** | `StdMap_InsertOrFindByIntKey_Val12` (see named record) |
| **Ghidra name** | `FUN_005aed20` |
| **Address** | `0x005aed20` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | std map insert-or-find Val12 int key |
| **Completion status** | **Sealed** — dual A/B **accept-with-gaps** (W30-M 2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Named record: `aa_005aed20_StdMap_InsertOrFindByIntKey_Val12.md`
- Legacy: `Named_CalleeOf_Mission_MissionStopLimit_005aed20` (**narrow**)

## Purpose

Val12 unique insert-or-find by signed int key; insert via `0x005ae4e0`.

## Signature (sealed)

```c
void __thiscall FUN_005aed20(void *map, void *outPair, void *value);
// RET 8
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005aed20_FUN_005aed20.md`
- Annotated: `docs/reconstruction/raw/aa_005aed20_FUN_005aed20.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/StdMap_InsertOrFindByIntKey_Val12_005aed20.cpp`
- Clean scaffold: `docs/reconstruction/reconstructed-exact/FUN_005aed20.cpp`
- Reviews: `A_/B_aa_005aed20_StdMap_InsertOrFindByIntKey_Val12.md`
- Report: `docs/agents/task-dual-ab-005aed20-005accf0-w30m-report.md`

## Callers / callees

- Callees: `FUN_005ae4e0`, `FUN_005ae050`
- Callers: `FUN_005acf10` @ `005ad0ae`; site `005ada8b` (~`005ad2f0`)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **High** |
| ABI ret 8 | **High** |
| Parameter semantic names | **High** (map/out/value) |
| Product demangle | Tentative |
