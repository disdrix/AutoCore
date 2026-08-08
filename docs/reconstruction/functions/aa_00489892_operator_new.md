# Function record: operator_new

| Field | Value |
|---|---|
| **Stable ID** | `aa_00489892` |
| **Canonical name** | `operator_new` |
| **Address** | `0x00489892` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer (parent dual context); unit = **CRT IAT thunk** |
| **Completion status** | **Dual A/B accept** (R10-002, 2026-08-05) |
| **Bit-for-bit / runtime / diff** | Open (deferred / CRT DLL body) |
| **Classification** | thunk (IAT) |
| **Name provenance** | **Confirmed** PE/CRT import — not `_Inferred` |

## Purpose

Scalar C++ `operator new` IAT trampoline used by essentially all client heap allocations of fixed-size objects (tree/list nodes, UI widgets, inventory grids, etc.).

### Body (sealed)

```
00489892  FF 25 64 66 9C 00    JMP dword ptr [0x009c6664]  ; PTR_operator_new
```

6 bytes. No stack frame.

## Signature

```c
void * __cdecl operator_new(unsigned int size_bytes);
```

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00489892_FUN_00489892.md` |
| Annotated | `docs/reconstruction/raw/aa_00489892_FUN_00489892.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/operator_new.cpp` |
| FUN twin | `docs/reconstruction/reconstructed-exact/FUN_00489892.cpp` |
| FUN record | `docs/reconstruction/functions/aa_00489892_FUN_00489892.md` |
| Dual A | `docs/reconstruction/reviews/A_aa_00489892_operator_new.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_00489892_operator_new.md` |
| Report | `docs/agents/task-dual-ab-00489892-r10-report.md` |

## Related (not owned)

| VA | Name | Note |
|----|------|------|
| `0x0048981c` | `operator_delete[]` | sibling IAT |
| `0x00489822` | `operator_delete` | sibling IAT |
| `0x00489834` | `operator_new[]` | sibling IAT |
| `0x00685b20` | `operator_new` | secondary thunk (1 xref) — different VA |
| `0x004f3a30` | `Vehicle_CreateCargoInventoryFromPageCount` | parent dual residual |

## Confidence

| Claim | Level |
|---|---|
| IAT JMP body | **Confirmed** |
| CRT import identity | **Confirmed** |
| Game-logic port priority | **None** — use host `new` |
