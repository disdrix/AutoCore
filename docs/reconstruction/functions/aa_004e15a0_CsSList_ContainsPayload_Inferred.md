# Function record: CsSList_ContainsPayload_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e15a0` |
| **Canonical name** | `CsSList_ContainsPayload_Inferred` |
| **Ghidra name** | `FUN_004e15a0` |
| **Address** | `0x004e15a0` |
| **Body range** | sealed **89** B to pad (exclusive end `0x004e15f9`); Ghidra meta `004e15a0`–`004e15f8` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client containers / deferred-queue membership |
| **Completion status** | **partial** — dual A/B **accept**; CF + ABI + layout sealed; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_004e15a0_CsSList_ContainsPayload_Inferred.md`, `reviews/B_aa_004e15a0_CsSList_ContainsPayload_Inferred.md` |
| **Last reviewed** | `2026-07-29` (W20-P) |

## Alias

- `FUN_004e15a0` (Ghidra / scaffold)
- `Named_CalleeOf_Named_CalleeOf_CVOGReaction_RemoveObject_004e15a0` (auto parent-seed — incomplete)
- Residual product class spelling for `CsSList_*`

## Purpose

Thread-safe **payload membership** on a CS-protected singly-linked list:

1. Enter CS `list+0x28` then `list+0x10` (**always both**).
2. Walk head `*(list+4)`; compare `*(node+4)==payload`; next `*(node+8)`.
3. Leave inner then outer; return **1** hit / **0** miss.

Twin of `CsSList_AppendPayload_Inferred` (`aa_004024d0`) — same list/node field offsets. Used by deferred enqueue and queue-delete paths as “already present?”.

## Signature

```c
// ECX = list*; stack void* payload; ret 4; AL 0/1
uint32_t __thiscall CsSList_ContainsPayload_Inferred(void *list, void *payload);
```

## Layout

| Off | Field |
|----:|-------|
| list+0x04 | head* |
| list+0x10 | CRITICAL_SECTION (always) |
| list+0x28 | CRITICAL_SECTION (always — no count gate) |
| node+0x04 | payload* |
| node+0x08 | next* |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004e15a0_FUN_004e15a0.md` (+ W20-P append)
- Annotated: `docs/reconstruction/raw/aa_004e15a0_FUN_004e15a0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CsSList_ContainsPayload_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_004e15a0.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-005995a0-004e15a0-w20p-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `EnterCriticalSection`, `LeaveCriticalSection` (IAT) |
| **Callers** | `Object_EnqueueDeferredOnce` (`0x004d0e90` @ `004d0ea8`, queue `host+0xe5fc`); `Object_QueueDelete` (`0x004d4790` @ `004d4840`, queue `host+0xe648`) |

## Confidence

| Claim | Level |
|---|---|
| thiscall list + stack payload + ret 4 | **High** |
| Dual CS enter/leave order | **High** |
| head+4 / payload+4 / next+8 | **High** |
| Always both CS (no count gate) | **High** |
| Twin layout with Append | **High** |
| Product/PDB symbol | Open |
| Runtime / bit-exact | Open |

## Related

- `aa_004024d0` CsSList_AppendPayload_Inferred
- `aa_004d0e90` Object_EnqueueDeferredOnce
- `aa_004d4790` Object_QueueDelete
