# Function record: UiHost_FindTrackedPairNode_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00871690` |
| **Canonical name** | `UiHost_FindTrackedPairNode_Inferred` |
| **Address** | `0x00871690` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client UI / vehicle-garage host residual |
| **Completion status** | **Dual A/B complete** (2026-07-29 W21-R) — **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

| Name | Notes |
|---|---|
| `FUN_00871690` | Ghidra default / scaffold |
| `Named_CalleeOf_Named_CalleeOf_Named_VOGClient_00871690` | Prior auto parent-seed alias (superseded for role) |
| `UiHost_FindTrackedPairNode_Inferred` | Dual canonical |

## Purpose

Under list lock at host `+0x628`, iterate nodes until `(node+8, node+0xc) == (keyA, keyB)` and return that node pointer, or `NULL` at end. Always leaves the list CS if TraversalLock held (`+0x650`).

## Signature (byte-sealed)

```c
// ECX = host*; stack keyA, keyB; RET 8
int* /*node*/ __thiscall UiHost_FindTrackedPairNode_Inferred(void *host, int keyA, int keyB);
```

## Layout

| Location | Field |
|---|---|
| host `+0x628` | locked list head |
| host `+0x62c` | `CRITICAL_SECTION` |
| host `+0x650` | lock-held byte |
| node `+0x08` / `+0x0c` | keyA / keyB |

## Artifacts

- Raw + re-verify: `docs/reconstruction/raw/aa_00871690_FUN_00871690.md`
- Annotated: `docs/reconstruction/raw/aa_00871690_FUN_00871690.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/UiHost_FindTrackedPairNode_Inferred.cpp`
- Clean scaffold: `docs/reconstruction/reconstructed-exact/FUN_00871690.cpp`
- Legacy alias clean: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Named_VOGClient_00871690.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_00871690_FUN_00871690.md`
- Review A: `docs/reconstruction/reviews/A_aa_00871690_UiHost_FindTrackedPairNode_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00871690_UiHost_FindTrackedPairNode_Inferred.md`

## Callers / callees

**Callers (3):** `FUN_008718a0` (ClearTrackedPairAndRefresh), `FUN_008718d0`, `FUN_008719d0`  
**Callees:** `FUN_004294f0`, `FUN_004113b0`, `LeaveCriticalSection`

## Confidence

| Claim | Level |
|---|---|
| ABI / ret 8 / returns node\|0 | **High** (bytes) |
| Match keys at +8/+0xc | **High** |
| List base +0x628 / CS +0x62c / flag +0x650 | **High** |
| Product English names | **Tentative** (`_Inferred`) |
| keyA/keyB semantic type | **Tentative** |
| Runtime golden | Open |
