# Function record: FUN_0043cec0 / GuardedVector_GrowAssignRange

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043cec0` |
| **Canonical name** | `FUN_0043cec0` |
| **Inferred name** | `GuardedVector_GrowAssignRange` (**Inferred**) |
| **Address** | `0x0043cec0`–`0x0043ceef` (**48 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | STL / guarded ring-vector container |
| **Completion status** | **Dual A/B sealed** (W27-C 2026-07-29) — **accept** (trampoline body full) |
| **Bit-for-bit / runtime / diff** | Open for nested `FUN_0043cf40`; body itself sealed |

## Alias

- Human: `GuardedVector_GrowAssignRange` (structural; product/PDB open).
- Prior scaffold: `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPreloader_0043cec0`.

## Purpose

Thin stdcall trampoline on the **grow** path of `GuardedVector_CopyAssign`: forwards seven range arguments to `FUN_0043cf40`, appending `param_1` as the eighth argument (dest self-ref).

## Signature (decompiler + bytes)

```c
// stdcall; RET 0x1c
void FUN_0043cec0(uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4,
                  uint32_t p5, uint32_t p6, uint32_t p7);
// body: FUN_0043cf40(p1,p2,p3,p4,p5,p6,p7,p1);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0043cec0_FUN_0043cec0.md` (+ 2026-07-29 W27-C append)
- Annotated: `docs/reconstruction/raw/aa_0043cec0_FUN_0043cec0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_0043cec0.cpp`
- Clean named: `docs/reconstruction/reconstructed-exact/GuardedVector_GrowAssignRange.cpp`
- Named record: `docs/reconstruction/functions/aa_0043cec0_GuardedVector_GrowAssignRange.md`
- Review A: `docs/reconstruction/reviews/A_aa_0043cec0_GuardedVector_GrowAssignRange.md`
- Review B: `docs/reconstruction/reviews/B_aa_0043cec0_GuardedVector_GrowAssignRange.md`

## Callers / callees

| Direction | Address / name |
|---|---|
| Caller | `0x0043c730` `FUN_0043c730` / `GuardedVector_CopyAssign` (grow only) |
| Callee | `0x0043cf40` `FUN_0043cf40` (grow/insert worker) |

## Confidence

| Claim | Level |
|---|---|
| Body = single forward + RET 0x1c | **High** |
| 8th arg = param_1 duplicate | **High** |
| Sole caller grow path | **High** |
| Nested grow arithmetic | **Out of scope** (unowned `0043cf40`) |
| Product English | **Inferred** |
