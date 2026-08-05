# Function record: GuardedVector_Dtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b2ba0` |
| **Canonical name** | `GuardedVector_Dtor_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_005b2ba0` |
| **Address** | `0x005b2ba0`–`0x005b2c05` (**102 B** / `0x66`) |
| **Module** | `autoassault.exe` |
| **System** | STL / guarded ring-deque container |
| **Status** | Dual A/B sealed W37-D 2026-08-04 — **accept-with-gaps** |

## Purpose

Storage destructor for a GuardedVector ring-deque header: empty the ring header fields that matter for element count, free every non-null page block, free the page map, and zero `capacity`/`pages`. Used heavily for stack-local rings (AssPreloader) and member teardown paths. **Not** a scalar `operator delete this` of the header.

## Signature

```c
// Retail: ECX=container; 0 stack formals; plain RET; void
void GuardedVector_Dtor_Inferred(GuardedVectorHeader* container /*ECX*/);
```

## Algorithm

1. While `size != 0`: `size--`; if `size == 0` then `begin = 0`.
2. For `i = capacity … 1`: if `pages[i-1] != null` → `operator_delete(page)`.
3. If `pages != null` → `operator_delete(pages)`.
4. `capacity = 0`; `pages = 0` (always, both null and non-null map paths).

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005b2ba0_FUN_005b2ba0.md` |
| Annotated | `docs/reconstruction/raw/aa_005b2ba0_FUN_005b2ba0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_Dtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005b2ba0.cpp` |
| FUN record | `docs/reconstruction/functions/aa_005b2ba0_FUN_005b2ba0.md` |
| Review A/B | `docs/reconstruction/reviews/A_aa_005b2ba0_GuardedVector_Dtor_Inferred.md`, `B_…` |

## Related

- Family: Push/Pop/Resize/Erase/ClearAndSwap duals (W28–W30).
- Thunk/copy body: `thunk_FUN_005b2ba0` @ `0x0043d640` (not owned this wave).
- Consumers: AssPreloader ring locals, multi-clear dtor chains.
