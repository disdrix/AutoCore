# Function record: AssPreloader_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00970cf0` |
| **Canonical name** | `AssPreloader_Ctor_Inferred` |
| **Ghidra name** | `FUN_00970cf0` |
| **Address** | `0x00970cf0`–`0x00970e4c` exclusive (**348 B** / `0x15C`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | assets / AssPreloader construction |
| **Completion status** | **Dual sealed** W37-W — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Placement constructor for the **AssPreloader** object (`operator_new(0x114)` by sole parent ensure):

1. Install vtbl `PTR_FUN_00aa9a94` (scalar-deleting dtor `FUN_00481270`).
2. Create unnamed auto-reset event → `+0x04`.
3. Build map/tree head via `StdTree_AllocNode_0x1c` → `+0x14`.
4. Init four GuardedVector+CS banks (seed ring header at `+0xAC`).
5. Build second tree via `RbTree_AllocEmptyNode` → `+0xE0`.
6. Store host back-pointer at `+0x110`.

## Signature

```c
// stack (self*, host*); RET 0x08; returns self*
AssPreloader* AssPreloader_Ctor_Inferred(AssPreloader* self, void* host);
```

## Related

| VA | Role |
|---|---|
| `0x0075d3c0` | `AssManager_EnsureAssPreloader_Inferred` (W33-O) — sole caller |
| `0x005ae2b0` | `StdTree_AllocNode_0x1c_Inferred` — map head |
| `0x00439770` | `RbTree_AllocEmptyNode_Inferred` — second tree |
| `0x00970e50` | `AssPreloader_RetireStaleNeverLoaded_Inferred` — uses map `+0x10` |
| `0x00481270` | vtbl[0] scalar-deleting dtor thunk |
| Family | enqueue/worker/isReady duals — cache via `+0x110` |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00970cf0_FUN_00970cf0.md` |
| Annotated | `docs/reconstruction/raw/aa_00970cf0_FUN_00970cf0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssPreloader_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00970cf0.cpp` |
| Scaffold record | `docs/reconstruction/functions/aa_00970cf0_FUN_00970cf0.md` |
| A/B | `docs/reconstruction/reviews/A_aa_00970cf0_AssPreloader_Ctor_Inferred.md`, `B_…` |
| Dual report | `docs/agents/task-dual-ab-004a7ff0-00970cf0-w37w-report.md` |

## Confidence

| Claim | Level |
|---|---|
| RET 8 / two stack formals / returns self | **Confirmed** |
| Object size 0x114 / parent wiring | **Confirmed** |
| Event + 4× CS + two tree heads + host@+0x110 | **Confirmed** |
| Seed ring header @+0xAC layout vs GuardedVector dual | **High** (W33-O + W32-N) |
| Product class English | **Open** (`_Inferred`) |
| Runtime / bit-exact | **Open** |
