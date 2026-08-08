# Function record: operator_delete__ (alias → operator_delete_array)

| Field | Value |
|---|---|
| **Stable ID** | `aa_0048981c` |
| **This name** | `operator_delete__` (Ghidra decomp encoding) |
| **Canonical** | `operator_delete_array` |
| **Redirect** | See `aa_0048981c_operator_delete_array.md` |
| **Address** | `0x0048981c` |
| **Wave** | R10-010 OWN-ONLY dual (2026-08-05) |
| **Verdict** | **accept** |
| **Completion status** | Dual sealed — use named record |

## Purpose

Alias plate for pre-R10 scaffold name `operator_delete__`. Authoritative identity is CRT **`operator delete[]`** / canonical **`operator_delete_array`**.

## Signature

```c
void __cdecl operator_delete__(void *param_1);  // alias of operator_delete_array
```

## Artifacts

- Named: `docs/reconstruction/functions/aa_0048981c_operator_delete_array.md`
- FUN: `docs/reconstruction/functions/aa_0048981c_FUN_0048981c.md`
- Raw: `docs/reconstruction/raw/aa_0048981c_operator_delete__.md`
- Clean: `docs/reconstruction/reconstructed-exact/operator_delete_array.cpp`
- Report: `docs/agents/task-dual-ab-0048981c-r10-report.md`
