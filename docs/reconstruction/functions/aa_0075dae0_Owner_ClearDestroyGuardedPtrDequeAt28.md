
# Function record: Owner_ClearDestroyGuardedPtrDequeAt28

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075dae0` |
| **Canonical name** | `Owner_ClearDestroyGuardedPtrDequeAt28` (**Inferred**) |
| **Ghidra name** | `FUN_0075dae0` |
| **Address** | `0x0075dae0`–`0x0075db93` (**180 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | owner object + GuardedVector of owned pointers |
| **Completion status** | **Sealed dual A/B** (2026-07-29 W30-C) — CF/ABI High from bytes; decompile residual; xrefs open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Verdict** | **accept-with-gaps** |

## Purpose

Clear the GuardedVector of **owned object pointers** embedded at **`owner+0x28`**:

1. Steal contents into a stack-local header via sealed `GuardedVector_ClearAndSwap` (field emptied under optional CS).
2. For each absolute ring index in `[begin, begin+size)`, load the dword element; if non-null, invoke **scalar deleting destructor** (`vtable[0](p, 1)`).
3. Free stolen page blocks + map via `FUN_0040d9c0` (ESI=local).

Closes the parent ownership story left open by W29-A `GuardedVector_ClearAndSwap` (sole documented consumer).

## Signature (sealed)

```c
// ECX = owner; SEH; ADD ESP,0x20; RET
void Owner_ClearDestroyGuardedPtrDequeAt28(void* owner /*ECX*/);
```

## Layout

| Off (owner) | Role |
|---|---|
| `+0x28` | GuardedVector header base (pages/cap/begin/size; may carry CS at header+0x14 / flag+0x2c) |

| Off (header) | Role |
|---|---|
| `+0x04` | `pages` map |
| `+0x08` | `capacity` (page count) |
| `+0x0c` | `begin` |
| `+0x10` | `size` |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0075dae0_FUN_0075dae0.md` |
| Annotated | `docs/reconstruction/raw/aa_0075dae0_FUN_0075dae0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Owner_ClearDestroyGuardedPtrDequeAt28.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0075dae0.cpp` |
| Function (Ghidra) | `docs/reconstruction/functions/aa_0075dae0_FUN_0075dae0.md` |
| Function named | `docs/reconstruction/functions/aa_0075dae0_Owner_ClearDestroyGuardedPtrDequeAt28.md` |
| Review A | `docs/reconstruction/reviews/A_aa_0075dae0_Owner_ClearDestroyGuardedPtrDequeAt28.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0075dae0_Owner_ClearDestroyGuardedPtrDequeAt28.md` |
| Scratch | `docs/reconstruction/tmp/a_0075dae0.md` |

## Callers / callees

| Dir | Targets |
|---|---|
| Callees | `FUN_0043c660` / `GuardedVector_ClearAndSwap`, `FUN_0040d9c0`, indirect `vtable[0](...,1)` |
| Callers | **none** recovered in Ghidra (0 xrefs) |

## Confidence

| Claim | Level |
|---|---|
| ECX owner + field at +0x28 | **High** (bytes) |
| ClearAndSwap steal ESI/EDI | **High** |
| Ring walk + scalar deleting dtor | **High** |
| FUN_0040d9c0 frees map | **High** (body + call) |
| Decompiler loop text | **Low** (overridden by bytes) |
| Owner product type / xrefs | **Open** |
| Runtime | **Open** |

