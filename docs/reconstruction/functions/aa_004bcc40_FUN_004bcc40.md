# Function record: FUN_004bcc40

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bcc40` |
| **Canonical name** | `ThreadSafeObjectList_ScalarDeletingDtor` |
| **Ghidra name** | `FUN_004bcc40` |
| **Address** | `0x004bcc40`–`0x004bcc5d` (**30 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client::util / lock-protected object list |
| **Completion status** | **Sealed** — dual A/B W26-I 2026-07-29; **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Dual verdict** | **accept** |

## Alias

- Structural: `ThreadSafeObjectList_ScalarDeletingDtor`
- Class markers: list vtbl `PTR_FUN_009cb368` slot0; complete body `ThreadSafeObjectList_Dtor` (`FUN_004bcbf0`)

## Purpose

MSVC scalar deleting destructor: run list complete dtor, then optional `operator_delete` when `(flags & 1)`.

## Signature (sealed)

```c
void *__thiscall ThreadSafeObjectList_ScalarDeletingDtor(void *thisList /*ECX*/, uint8_t flags);
// RET 4; EAX = this
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004bcc40_FUN_004bcc40.md` (+ W26-I append)
- Annotated: `docs/reconstruction/raw/aa_004bcc40_FUN_004bcc40.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/ThreadSafeObjectList_ScalarDeletingDtor.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_004bcc40.cpp`
- Named record: `docs/reconstruction/functions/aa_004bcc40_ThreadSafeObjectList_ScalarDeletingDtor.md`
- Dual A: `docs/reconstruction/reviews/A_aa_004bcc40_ThreadSafeObjectList_ScalarDeletingDtor.md`
- Dual B: `docs/reconstruction/reviews/B_aa_004bcc40_ThreadSafeObjectList_ScalarDeletingDtor.md`
- Report: `docs/agents/task-dual-ab-005bc120-004bcc40-w26i-report.md`

## Callers / callees

**Callees:** `ThreadSafeObjectList_Dtor` (`0x004bcbf0`), `operator_delete`

**Callers:** none direct — virtual via `PTR_FUN_009cb368[0]`

## Confidence

| Claim | Level |
|---|---|
| Scalar dtor CF / bytes / ABI | **High** |
| Sibling body = ThreadSafeObjectList_Dtor | **High** (W25-C) |
| Vtbl slot 0 | **High** |
| Product mangled name | Open |
| Runtime / differential | Open |
