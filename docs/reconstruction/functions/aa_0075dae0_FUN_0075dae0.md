
# Function record: FUN_0075dae0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075dae0` |
| **Canonical name** | `Owner_ClearDestroyGuardedPtrDequeAt28` (**Inferred**) / Ghidra `FUN_0075dae0` |
| **Address** | `0x0075dae0`–`0x0075db93` (**180 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | owner + GuardedVector of owned pointers |
| **Completion status** | **Sealed dual A/B** (2026-07-29 W30-C) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Verdict** | **accept-with-gaps** |

## Purpose

Steal + destroy + free owned-pointer GuardedVector at `this+0x28`. See named record. **Authoritative CF is bytes**, not the 2026-07-23 decompile scaffold.

## Signature (sealed)

```c
void Owner_ClearDestroyGuardedPtrDequeAt28(void* owner /*ECX*/);
// Ghidra display (misleading): void FUN_0075dae0(void)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0075dae0_FUN_0075dae0.md`
- Annotated: `docs/reconstruction/raw/aa_0075dae0_FUN_0075dae0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Owner_ClearDestroyGuardedPtrDequeAt28.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0075dae0.cpp`
- Named record: `docs/reconstruction/functions/aa_0075dae0_Owner_ClearDestroyGuardedPtrDequeAt28.md`
- Review A/B: `docs/reconstruction/reviews/A_aa_0075dae0_Owner_ClearDestroyGuardedPtrDequeAt28.md`, `B_…`

## Callers / callees

- Callees: `FUN_0043c660`, `FUN_0040d9c0`, vtable dtor
- Callers: none in Ghidra

## Confidence

| Claim | Level |
|---|---|
| Bytes CF | **High** |
| Decompiler scaffold | **Low** (dead loop) |
| Product name | **Inferred** |

