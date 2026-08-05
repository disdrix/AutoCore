
# Function record: GuardedVector_PopBack

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043df70` |
| **Canonical name** | `GuardedVector_PopBack` (**Inferred**) |
| **Ghidra name** | `FUN_0043df70` |
| **Address** | `0x0043df70`–`0x0043df86` (**23 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | STL / guarded ring-deque container |
| **Completion status** | **Sealed dual A/B** (2026-07-29 W30-C) — CF/ABI High; product English open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Verdict** | **accept** |

## Purpose

Ring-deque **pop_back bookkeeping**: if `size != 0`, decrement `size`; when `size` hits 0, reset `begin` to 0. No element destructor and no page free — pure header update. SEH cleanup twin of construct-side push_back during InsertN / related insert workers.

## Signature (sealed)

```c
// ECX = container; plain RET; no stack args
void GuardedVector_PopBack(GuardedVectorHeader* container /*ECX*/);
```

## Layout (this@ECX)

| Off | Role |
|---|---|
| `+0x0c` | `begin` (zeroed when size hits 0) |
| `+0x10` | `size` (decremented) |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043df70_FUN_0043df70.md` |
| Annotated | `docs/reconstruction/raw/aa_0043df70_FUN_0043df70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_PopBack.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043df70.cpp` |
| Function (Ghidra) | `docs/reconstruction/functions/aa_0043df70_FUN_0043df70.md` |
| Function named | `docs/reconstruction/functions/aa_0043df70_GuardedVector_PopBack.md` |
| Review A | `docs/reconstruction/reviews/A_aa_0043df70_GuardedVector_PopBack.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0043df70_GuardedVector_PopBack.md` |
| Scratch | `docs/reconstruction/tmp/a_0043df70.md` |

## Callers / callees

| Dir | Targets |
|---|---|
| Callees | none (leaf) |
| Callers (5) | SEH catch: `Catch@0043cd81`, `Catch@0043d278`, `Catch@0043e305`, `Catch@0044e470`, `Catch@00544508` |

## Confidence

| Claim | Level |
|---|---|
| ECX container + plain RET | **High** |
| size-- / empty begin=0 | **High** (bytes) |
| No dtor / no free | **High** |
| Family layout +0c/+10 | **High** |
| Product/PDB English | **Inferred** |
| Runtime | **Open** |

