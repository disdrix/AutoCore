# Function record: FUN_005b2ba0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b2ba0` |
| **Canonical name** | `FUN_005b2ba0` |
| **Named alias** | `GuardedVector_Dtor_Inferred` |
| **Address** | `0x005b2ba0`–`0x005b2c05` (**102 B** / `0x66`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | STL / guarded ring-deque container |
| **Completion status** | **Dual A/B sealed W37-D 2026-08-04** — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Classification** | worker |

## Alias

- Scaffold: `Named_CalleeOf_Named_stoPackOSFile_005b2ba0` — **reject** as product role (not exclusive owner).
- Prior clean consumers: `GuardedVector_Dtor_Inferred` (AssPreloader family).

## Purpose

Destroy/free GuardedVector **storage**: drain `size` (clear `begin` when emptied), `operator_delete` each page in the map, free the page map, zero `capacity` and `pages`. Does not free the header object itself.

## Signature

```c
// Retail: ECX = GuardedVectorHeader*; plain RET; void
void __fastcall FUN_005b2ba0(GuardedVectorHeader* container /*ECX*/);
```

## Layout

| Off | Role |
|-----|------|
| `+0x04` | `pages` (uint32_t** / page map) |
| `+0x08` | `capacity` (page count) |
| `+0x0c` | `begin` |
| `+0x10` | `size` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005b2ba0_FUN_005b2ba0.md`
- Annotated: `docs/reconstruction/raw/aa_005b2ba0_FUN_005b2ba0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/GuardedVector_Dtor_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_005b2ba0.cpp`
- Named record: `docs/reconstruction/functions/aa_005b2ba0_GuardedVector_Dtor_Inferred.md`
- Review A/B: `docs/reconstruction/reviews/A_aa_005b2ba0_GuardedVector_Dtor_Inferred.md`, `B_…`

## Callers / callees

**Callees:** `operator_delete` @ `0x00489822`.

**Callers (28, sample):** AssPreloader locals (`FUN_00971640`, `FUN_00971700`, `FUN_009717a0`, `FUN_00971820`, `FUN_00971900`, `FUN_00971a20`), `FUN_004ed1a0`, `FUN_004f26e0`, `FUN_0052c780`, `FUN_0043d4a0`, `FUN_0043e490`, … + thunk twin body @ `0x0043d640` (not owned).

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompile + bytes | **High** |
| ECX this / plain RET / void | **High** |
| Page free + map free + zero capacity/pages | **High** (bytes seal post-delete stores) |
| Family layout offsets | **High** (GuardedVector dual family) |
| Product/PDB English | **Inferred** |
| Per-element dtor | **None** (body never runs them) |
