# Function record: ThreadSafeObjectList_Dtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bcbf0` |
| **Canonical name** | `ThreadSafeObjectList_Dtor` (structural, **Inferred**) |
| **Ghidra name** | `FUN_004bcbf0` |
| **Address** | `0x004bcbf0`–`0x004bcc31` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client::util / lock-protected object list |
| **Classification** | destructor / drain + CS teardown |
| **Completion status** | **Sealed** — dual A/B W25-C 2026-07-29; **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Dual verdict** | **accept** |

## Alias

- Ghidra: `FUN_004bcbf0`
- Prior scaffold: `Named_CalleeOf_Named_VOG_DEBUG_STOP_004bcbf0`
- Class markers: list vtbl `PTR_FUN_009cb368`; scalar-deleting wrapper `FUN_004bcc40`

## Purpose

Destroy a dual-critical-section object list: install list vtbl, drain via `ThreadSafeObjectList_PopFront` while deleting each owned payload (`vtbl[0](payload, 1)`), zero count, and `DeleteCriticalSection` on both CS regions.

## Signature (sealed)

```c
void __fastcall ThreadSafeObjectList_Dtor(ThreadSafeObjectList *list);
// ECX = list*; ret
```

## Layout

| Off | Field | Confidence |
|---:|---|---|
| `+0x00` | vtbl | **High** |
| `+0x04` | head | **High** (via PopFront twin) |
| `+0x08` | tail | **High** |
| `+0x0C` | count (zeroed here) | **High** |
| `+0x10` | `CRITICAL_SECTION` inner | **High** |
| `+0x28` | `CRITICAL_SECTION` outer | **High** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004bcbf0_FUN_004bcbf0.md` (+ W25-C append)
- Annotated: `docs/reconstruction/raw/aa_004bcbf0_FUN_004bcbf0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/ThreadSafeObjectList_Dtor.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_004bcbf0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_004bcbf0_ThreadSafeObjectList_Dtor.md`
- Dual B: `docs/reconstruction/reviews/B_aa_004bcbf0_ThreadSafeObjectList_Dtor.md`
- Report: `docs/agents/task-dual-ab-004bcbf0-00421240-w25c-report.md`

## Callers / callees

**Callees:** `ThreadSafeObjectList_PopFront` (`0x0040b020`), `DeleteCriticalSection`

**Callers:** `FUN_004bcc40`, `FUN_004d64d0`, `FUN_004bbc70`, `FUN_0058c850` (×2), `Unwind@009a5750`

## Confidence

| Claim | Level |
|---|---|
| Drain + dual DeleteCS CF / bytes | **High** |
| Layout twin with PopFront | **High** |
| Payload delete with flag 1 | **High** |
| Product English name | **Probable** / Inferred |
| Runtime / differential | Open |
