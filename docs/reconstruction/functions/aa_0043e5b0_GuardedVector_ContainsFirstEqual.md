# Function record: GuardedVector_ContainsFirstEqual

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043e5b0` |
| **Canonical name** | `GuardedVector_ContainsFirstEqual` (**Inferred**) |
| **Ghidra name** | `FUN_0043e5b0` |
| **Address** | `0x0043e5b0`–`0x0043e62a` (**123 B** / `0x7B`) |
| **Module** | `autoassault.exe` |
| **System** | STL / guarded ring-deque container |
| **Status** | Dual A/B sealed W30-B 2026-07-29 — **accept-with-gaps** |

## Purpose

CS-gated membership query: linear first-equal scan of ring elements for `*key`. Used by `assManager` resolver remove/release paths before erase.

## Signature

```c
// Retail: EAX=container; stdcall 1 stack arg; RET 4; AL=bool
uint8_t GuardedVector_ContainsFirstEqual(
    GuardedVectorHeader* container /*EAX*/,
    const int* key /*stack*/);
```

## Layout (family)

| Off | Role |
|-----|------|
| `+0x04` | pages |
| `+0x08` | capacity (pages) |
| `+0x0c` | begin |
| `+0x10` | size |
| `+0x14` | CRITICAL_SECTION |
| `+0x2c` | CS enable flag |

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043e5b0_FUN_0043e5b0.md` |
| Annotated | `docs/reconstruction/raw/aa_0043e5b0_FUN_0043e5b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_ContainsFirstEqual.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043e5b0.cpp` |
| FUN record | `docs/reconstruction/functions/aa_0043e5b0_FUN_0043e5b0.md` |
| Review A/B | `docs/reconstruction/reviews/A_aa_0043e5b0_GuardedVector_ContainsFirstEqual.md`, `B_…` |
| Scratch | `docs/reconstruction/tmp/a_0043e5b0.md` |

## Related

- W28-C erase twin: `GuardedVector_EraseFirstEqual` (`0x0043c550`)
- Parent: `AssManager_RemoveResolver_Inferred` (`0x00423e00`)
