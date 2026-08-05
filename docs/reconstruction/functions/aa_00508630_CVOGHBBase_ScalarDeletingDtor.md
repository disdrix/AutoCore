# Function record: CVOGHBBase_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00508630` |
| **Canonical name** | `CVOGHBBase_ScalarDeletingDtor` |
| **Ghidra name** | `FUN_00508630` |
| **Address** | `0x00508630` |
| **Body range** | `0x00508630`–`0x00508667` (55 B / `0x37`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `heartbeat` / timed-action |
| **Completion status** | **partial** — dual A/B **accept** |
| **Dual A/B** | `reviews/A_aa_00508630_CVOGHBBase_ScalarDeletingDtor.md`, `reviews/B_aa_00508630_CVOGHBBase_ScalarDeletingDtor.md` |
| **Last reviewed** | `2026-07-29` (W23-Q) |

## Naming evidence

| Source | Value |
|---|---|
| Vtbl slot 0 | `PTR_FUN_009cdab0+0` → this VA |
| Ctor dual | same vtbl install; sealed layout |
| Complete dtor sibling | `CVOGHBBase_dtor` @ `0x00508390` (no free) |
| Pattern | MSVC scalar deleting dtor (`flags&1` → `operator_delete`) |

**Decision:** promote **`CVOGHBBase_ScalarDeletingDtor`** (class + role sealed by family duals; product mangled open).

## Purpose / signature / artifacts

See twin record `aa_00508630_FUN_00508630.md`.
