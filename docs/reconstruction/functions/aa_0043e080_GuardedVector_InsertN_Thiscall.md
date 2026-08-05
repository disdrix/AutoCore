# Function record: GuardedVector_InsertN_Thiscall

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043e080` |
| **Canonical name** | `GuardedVector_InsertN_Thiscall` (**Inferred**) |
| **Ghidra name** | `FUN_0043e080` |
| **Address** | `0x0043e080`–`0x0043e37d` |
| **Module** | `autoassault.exe` |
| **System** | STL / guarded ring-deque container |
| **Status** | Dual A/B sealed W32-F 2026-07-29 — **accept-with-gaps** |

## Purpose

Insert `N` copies of `*fill` at absolute `insert_at` in the GuardedVector ring header under **thiscall** ABI. Front-biased arms use `GuardedVector_PushFront_Thiscall`; back-biased arms use `GuardedVector_PushBack_Thiscall`. Sole known caller is resize-grow (`FUN_0043d940`), which only exercises end-insert (`suffix < N`).

## Signature

```c
// Retail: ECX=container; stack (seed, insert_at, N, fill*); RET 0x10
void GuardedVector_InsertN_Thiscall(GuardedVectorHeader* container /*ECX*/,
                                    GuardedVectorHeader* seed,
                                    int32_t insert_at,
                                    uint32_t n,
                                    const uint32_t* fill);
```

## Relationship

- Twin of W29-A `GuardedVector_InsertN` (`0x0043cb00`, ECX=N / EAX push).
- Nested push pair sealed W31-I (`0043d670` / `0043e3d0`).
- Nested range helpers `0043e910` / `0043ebb0` / `0043ec50` residual.

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043e080_FUN_0043e080.md` |
| Annotated | `docs/reconstruction/raw/aa_0043e080_FUN_0043e080.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_InsertN_Thiscall.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043e080.cpp` |
| FUN record | `docs/reconstruction/functions/aa_0043e080_FUN_0043e080.md` |
| Review A/B | `docs/reconstruction/reviews/A_aa_0043e080_GuardedVector_InsertN_Thiscall.md`, `B_…` |
