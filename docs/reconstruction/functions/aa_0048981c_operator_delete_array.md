# Function record: operator_delete_array

| Field | Value |
|---|---|
| **Stable ID** | `aa_0048981c` |
| **Canonical name** | `operator_delete_array` |
| **CRT demangle** | `operator delete[]` |
| **Ghidra name** | `operator_delete[]` |
| **Decomp alias** | `operator_delete__` |
| **FUN record** | `aa_0048981c_FUN_0048981c.md` |
| **Address** | `0x0048981c`–`0x00489821` inclusive (**6 B** / `0x6`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | CRT universal (partition seed inventory-transfer; parent dual `0x005725a0`) |
| **Classification** | **thunk** |
| **Wave** | R10-010 OWN-ONLY dual (2026-08-05) |
| **Verdict** | **accept** |
| **Bit-for-bit / runtime / diff** | Thunk sealed; external CRT + runtime open |

## Purpose

MSVC **`operator delete[]`** import thunk. Tail-jumps through IAT slot `0x009c6698` into the CRT array-delete implementation. No in-image free algorithm.

## Signature (sealed)

```c
// __cdecl; stack arg0 = void* array block; void; caller cleans stack
void __cdecl operator_delete_array(void *block);
// equivalent: void operator delete[](void *block);
```

## Body

```
0048981c  FF 25 98 66 9C 00   JMP dword ptr [0x009c6698]
```

Sibling scalar `operator_delete` @ `0x00489822` → `[0x009c6694]` — **do not merge**.

## Callers / callees

| Role | Target | Status |
|---|---|---|
| Callee | IAT `0x009c6698` → CRT `operator delete[]` | external |
| Caller (seed) | `0x005725a0` InventoryGrid_CompleteDtor cells `@+0x28` | dualed accept |
| Caller (sample) | `0x00570720` AllocateCellArray free-old @ `0x0057072d` | dualed |
| Callers | ≥100 xrefs (vectors, UI, skills, Unwind, …) | universal |

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_0048981c_operator_delete__.md`
- Annotated: `docs/reconstruction/raw/aa_0048981c_operator_delete__.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/operator_delete_array.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/operator_delete__.cpp`
- FUN record: `docs/reconstruction/functions/aa_0048981c_FUN_0048981c.md`
- Dual A: `docs/reconstruction/reviews/A_aa_0048981c_operator_delete_array.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0048981c_operator_delete_array.md`
- Report: `docs/agents/task-dual-ab-0048981c-r10-report.md`

## Related

| VA | Name | Relation |
|---|---|---|
| `0x00489822` | `operator_delete` | scalar sibling IAT thunk |
| `0x00489892` | `operator_new` | alloc family |
| `0x005725a0` | `InventoryGrid_CompleteDtor` | parent dual seed |
| `0x00570720` | `InventoryGrid_AllocateCellArray_Inferred` | cdecl CALL sample |

## Confidence

| Claim | Level |
|---|---|
| Thunk CF / IAT / cdecl / returns | **Confirmed** |
| CRT array-delete identity | **Confirmed** |
| Product-specific ownership | **Rejected** (universal CRT) |
| Runtime Confirmed | Open |
