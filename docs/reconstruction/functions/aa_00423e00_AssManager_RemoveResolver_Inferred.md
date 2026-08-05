# Function record: AssManager_RemoveResolver_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00423e00` |
| **Canonical name** | `AssManager_RemoveResolver_Inferred` |
| **Ghidra name** | `FUN_00423e00` |
| **Address** | `0x00423e00`–`0x00423e43` (68 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `assets` / `assManager` |
| **Completion status** | **partial** — dual A/B **accept** (W29-C) |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `reviews/A_aa_00423e00_AssManager_RemoveResolver_Inferred.md`, `reviews/B_aa_00423e00_AssManager_RemoveResolver_Inferred.md` |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_00423e00`
- `Named_assManager_00423e00`

## Purpose

Remove one resolver key from assManager's GuardedVector at **`this+0x58`**: find (`FUN_0043e5b0`) → log miss or erase (`FUN_0043c550`). Soft-fail on not found.

## Signature

```c
void AssManager_RemoveResolver_Inferred(void *assManager /*ECX*/, int key /*EAX*/);
```

## Artifacts

- Raw / annotated / clean under `aa_00423e00` / named clean
- Scaffold record: `functions/aa_00423e00_FUN_00423e00.md`
- Report: `docs/agents/task-dual-ab-00436860-00423e00-w29c-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_0043e5b0`, `vog_LogMessage`, `FUN_0043c550` |
| **Callers** | `FUN_007b65d0` only |

## Confidence

| Claim | Level |
|---|---|
| CF + strings + register ABI | **High** |
| Product name | **Inferred** |
| Runtime | Open |
