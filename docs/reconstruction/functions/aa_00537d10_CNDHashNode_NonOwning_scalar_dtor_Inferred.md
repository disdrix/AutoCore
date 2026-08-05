# Function record: CNDHashNode_NonOwning_scalar_dtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00537d10` |
| **Canonical name** | `CNDHashNode_NonOwning_scalar_dtor_Inferred` (Ghidra `FUN_00537d10`) |
| **Address** | `0x00537d10` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / CNDHash |
| **Completion status** | **Dual-sealed accept-with-gaps** (2026-07-29); function created in Ghidra this dual |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

MSVC scalar-deleting destructor — **vtbl[0]** of `PTR_FUN_009cf02c`. Sets vptr; if `flags&1` deletes **this only**. Does **not** free value at `+0x08` (non-owning; def pointers). Twin of value-owning `FUN_00537550`.

## Signature (sealed)

```c
void * __thiscall CNDHashNode_NonOwning_scalar_dtor_Inferred(
    void *node /* ECX */,
    unsigned char flags /* stack — bit0 = delete this */);
// ret 4; returns node*
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00537d10_CNDHashNode_NonOwning_scalar_dtor_Inferred.md`
- Annotated: `docs/reconstruction/raw/aa_00537d10_CNDHashNode_NonOwning_scalar_dtor_Inferred.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CNDHashNode_NonOwning_scalar_dtor_Inferred.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00537d10_CNDHashNode_NonOwning_scalar_dtor_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00537d10_CNDHashNode_NonOwning_scalar_dtor_Inferred.md`

## Callers / callees

| Role | Notes |
|---|---|
| Dispatch | vtbl `0x009cf02c` slot 0 |
| Insert sites stamping vtbl | `FUN_0053c460` and siblings |
| Callee | `operator_delete` (this only when bit0) |
| Twin | `FUN_00537550` value-owning |

## Confidence

| Claim | Level |
|---|---|
| Scalar dtor CF; no value free | High |
| Vtbl identity | High |
| Product mangled name | None / open |
