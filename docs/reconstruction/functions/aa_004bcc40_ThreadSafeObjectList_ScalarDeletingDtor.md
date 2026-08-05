# Function record: ThreadSafeObjectList_ScalarDeletingDtor

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

## Naming evidence

| Source | Value |
|---|---|
| Vtbl slot 0 | `PTR_FUN_009cb368+0` → this VA |
| Complete dtor sibling | `ThreadSafeObjectList_Dtor` @ `0x004bcbf0` (W25-C accept) |
| Pattern | MSVC scalar deleting dtor (`flags&1` → `operator_delete`, `ret 4`) |
| PopFront twin | `ThreadSafeObjectList_PopFront` @ `0x0040b020` |

**Decision:** promote **`ThreadSafeObjectList_ScalarDeletingDtor`** (class + role sealed by family duals; product mangled open).

## Purpose / signature / artifacts

See twin record `aa_004bcc40_FUN_004bcc40.md`.
