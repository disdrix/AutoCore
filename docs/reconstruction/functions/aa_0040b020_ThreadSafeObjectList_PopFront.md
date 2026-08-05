# Function record: `ThreadSafeObjectList_PopFront`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040b020` |
| **Canonical name** | `ThreadSafeObjectList_PopFront` (structural, **Inferred**) |
| **Ghidra name** | `FUN_0040b020` |
| **Address** | `0x0040b020` |
| **Body** | `0040b020`–`0040b136` (SEH + `ret`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `client::util` / lock-protected object list |
| **Completion status** | **Dual A/B sealed 2026-07-29 (W24-S)** — accept |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Alias

- Ghidra: `FUN_0040b020`
- Prior scaffold alias: `Named_CalleeOf_Client_NotifyActiveMissionChanged_0040b020`
- Class markers: list vtbl `PTR_FUN_009cb368`; node vtbl `PTR_FUN_009cb340`

## Purpose

Pop head of a dual-critical-section singly-linked object list; return the payload pointer; free the node via `(*vtbl)(1)`; `InterlockedDecrement` count. Empty → `NULL` without entering CS.

## Signature

```c
void *__fastcall ThreadSafeObjectList_PopFront(ThreadSafeObjectList *list);
// epilogue: ret
```

## Layouts

### List

| Off | Field |
|----:|-------|
| `+0x00` | vtbl |
| `+0x04` | head |
| `+0x08` | tail |
| `+0x0C` | `LONG` count |
| `+0x10` | `CRITICAL_SECTION` inner |
| `+0x28` | `CRITICAL_SECTION` outer |

### Node (`0xC`)

| Off | Field |
|----:|-------|
| `+0x00` | vtbl |
| `+0x04` | payload* |
| `+0x08` | next* |

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0040b020_FUN_0040b020.md` (+ 2026-07-29 live append) |
| Annotated | `docs/reconstruction/raw/aa_0040b020_FUN_0040b020.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ThreadSafeObjectList_PopFront.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0040b020.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_0040b020_ThreadSafeObjectList_PopFront.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0040b020_ThreadSafeObjectList_PopFront.md` |
| Scaffold record | `docs/reconstruction/functions/aa_0040b020_FUN_0040b020.md` |

## Callers / callees

**Callees:** `EnterCriticalSection`, `LeaveCriticalSection`, `InterlockedDecrement`

**Twins:** push `FUN_004024d0`; dtor drain `FUN_004bcbf0`

**Callers (direct):** `FUN_004d64d0`, `FUN_00944770`, `FUN_004bcbf0`, `FUN_004bbc70`, `FUN_00919dc0`, `FUN_004e0ad0`, `FUN_0058c850` (Skill multi-target iterate)

## Confidence

| Claim | Level |
|---|---|
| Pop-front CF + dual CS policy | **Confirmed** |
| Node 0xC / payload@+4 / next@+8 | **Confirmed** (via push twin) |
| Empty → 0, no lock | **Confirmed** |
| Product English name | **Open** (Inferred only) |
| Nested-CS threshold English | **Open** (bytes sealed `count < 2`) |
