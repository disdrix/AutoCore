# Function record: GuardedVector_PopFront

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d980` |
| **Canonical name** | `GuardedVector_PopFront` (**Inferred**) |
| **Ghidra name** | `FUN_0040d980` |
| **Address** | `0x0040d980`–`0x0040d9b1` (**50 B** / `0x32`) |
| **Module** | `autoassault.exe` |
| **System** | STL / guarded ring-deque container |
| **Status** | Dual A/B sealed W30-B 2026-07-29 — **accept** |

## Purpose

Leaf header update that drops the front ring slot without reading or destroying the element. Complements PushFront/PushBack (W29-B) and EraseRange family.

## Signature

```c
// Retail: EAX=container; plain RET; void
void GuardedVector_PopFront(GuardedVectorHeader* container /*EAX*/);
```

## Layout (family)

| Off | Role |
|-----|------|
| `+0x08` | capacity (pages) — ring slots = capacity×4 |
| `+0x0c` | begin |
| `+0x10` | size |

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0040d980_FUN_0040d980.md` |
| Annotated | `docs/reconstruction/raw/aa_0040d980_FUN_0040d980.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_PopFront.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0040d980.cpp` |
| FUN record | `docs/reconstruction/functions/aa_0040d980_FUN_0040d980.md` |
| Review A/B | `docs/reconstruction/reviews/A_aa_0040d980_GuardedVector_PopFront.md`, `B_…` |
| Scratch | `docs/reconstruction/tmp/a_0040d980.md` |

## Related

- W29-B: `GuardedVector_PushFront` / `GuardedVector_PushBack`
- W28-D: `GuardedVector_Resize` / `GuardedVector_RingFillRange`
