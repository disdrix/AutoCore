# Function record: CNDUIWndBuffered_TeardownBufferedOwned_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0078c3d0` |
| **Canonical name** | `CNDUIWndBuffered_TeardownBufferedOwned_Inferred` |
| **Ghidra name** | `FUN_0078c3d0` |
| **Address** | `0x0078c3d0`–`0x0078c47e` inclusive (**175 B** / `0xAF`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | UI / CNDUIWndBuffered complete-dtor helper |
| **Naming evidence** | Owner class from dualed parent `CNDUIWndBuffered_CompleteDtor` + RTTI `.?AVCNDUIWndBuffered@@`. Role: gate on `+0x2A4`, unregister+scalar-delete owned slots, HostBase-aux release. No method-string demangle → **`_Inferred`**. |
| **Rejected** | `Named_CalleeOf_*` scaffolds; claiming complete dtor; claiming HostBase free |
| **Completion status** | **Dual sealed** WQ9L-D2 2026-08-05 — **accept-with-gaps** |
| **Terminal** | **false** |

## Signature

```c
void __fastcall CNDUIWndBuffered_TeardownBufferedOwned_Inferred(void *self /*ECX*/);
```

## Semantics

1. If `*(self+0x2A4) == 0` → return.
2. `FUN_0074e260(*(HostBase+4), *(*(self+0x2AC)+0x8C))`; scalar-delete `+0x2AC`; null.
3. If `+0x49C` live: same unregister + scalar-delete + null.
4. Scalar-delete `+0x2A4`; null.
5. On `*(HostBase+4)`: refcount-release pointer at `+0x3C` (`--` at `+4`; if 0 call `vtbl[+8]`); null slot.

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0078c3d0_FUN_0078c3d0.md` |
| Annotated | `docs/reconstruction/raw/aa_0078c3d0_FUN_0078c3d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDUIWndBuffered_TeardownBufferedOwned_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0078c3d0.cpp` |
| FUN record | `docs/reconstruction/functions/aa_0078c3d0_FUN_0078c3d0.md` |
| Review A | `docs/reconstruction/reviews/A_aa_0078c3d0_CNDUIWndBuffered_TeardownBufferedOwned_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0078c3d0_CNDUIWndBuffered_TeardownBufferedOwned_Inferred.md` |
| Report | `docs/agents/task-dual-ab-0078c3d0-wq9ld2-report.md` |

## Gaps

- Product / RTTI for owned types at `+0x2A4` / `+0x2AC` / `+0x49C`.
- Dual of `FUN_0074e260`.
- Product English for HostBase-aux `+0x3C` COM-like object.
- Vtable method indices for 4 DATA slots.
- Runtime / bit-exact / differential.
