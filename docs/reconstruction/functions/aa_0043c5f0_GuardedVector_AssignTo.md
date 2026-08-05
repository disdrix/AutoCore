# Function record: GuardedVector_AssignTo

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043c5f0` |
| **Canonical name** | `GuardedVector_AssignTo` |
| **Name confidence** | **Inferred** — lock+assign role; no product string |
| **Ghidra** | `FUN_0043c5f0` |
| **Address** | `0x0043c5f0`–`0x0043c650` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | STL / guarded container |
| **Completion status** | **Dual A/B sealed** (W25-R 2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Verdict** | **accept-with-gaps** |

## Alias

- Ghidra: `FUN_0043c5f0`
- Prior: `Named_CalleeOf_Named_assPreloader_0043c5f0`

## Purpose

Optionally enter a critical section on a guarded container, assign/copy that container into a destination via `FUN_0043c730`, then leave the CS. Used to snapshot factory lists (e.g. `NDResourceCache` `cache+0x28`) under lock.

## Signature (retail)

```c
// ECX = source, stack dest*, RET 4
void GuardedVector_AssignTo(GuardedVector* source /*ECX*/, void* dest /*stack*/);
```

## Key offsets

| Off | Field |
|---|---|
| `+0x14` | `CRITICAL_SECTION` |
| `+0x2c` | lock-enable `char` |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043c5f0_FUN_0043c5f0.md` |
| Annotated | `docs/reconstruction/raw/aa_0043c5f0_FUN_0043c5f0.annotated.md` |
| Clean (named) | `docs/reconstruction/reconstructed-exact/GuardedVector_AssignTo.cpp` |
| Clean (Ghidra alias) | `docs/reconstruction/reconstructed-exact/FUN_0043c5f0.cpp` |
| Function (Ghidra) | `docs/reconstruction/functions/aa_0043c5f0_FUN_0043c5f0.md` |
| Review A | `docs/reconstruction/reviews/A_aa_0043c5f0_GuardedVector_AssignTo.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0043c5f0_GuardedVector_AssignTo.md` |

## Callers / callees

| Kind | Target |
|---|---|
| Callees | `EnterCriticalSection`, `LeaveCriticalSection`, `FUN_0043c730` |
| Callers | `NDResourceCache_LookupOrCreate` `0x0075dba0`; `FUN_0075d9c0`; `FUN_007b6770`; `FUN_00948530`; `FUN_00971280`; `FUN_00971ea0`; `FUN_00972140` |

## Confidence

| Claim | Level |
|---|---|
| ECX source, stack dest, RET 4 | **High** |
| CS +0x14 / gate +0x2c | **High** |
| Nested assign semantics | **Tentative** (callee not owned) |
| Product type name | **Inferred** |
| Runtime | **Open** |
