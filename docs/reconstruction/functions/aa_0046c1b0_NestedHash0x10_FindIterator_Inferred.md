# Function record: NestedHash0x10_FindIterator_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0046c1b0` |
| **Canonical name** | `NestedHash0x10_FindIterator_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_0046c1b0` |
| **Address** | `0x0046c1b0`–`0x0046c223` (**116 B** / `0x74`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | NestedHash bag (sentinel node 0x10) — find-iterator |
| **Completion status** | Dual A/B sealed W36-B 2026-07-29 — **accept** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Leaf **find-by-u32-key** on NestedHash0x10: identity-hash into bucket table, walk ordered chain, write node or end-sentinel to `*out_it`.

## Signature

```c
// ESI=map, ECX=key*, EAX=out_it*; bare RET
void NestedHash0x10_FindIterator_Inferred(
    void* map /*ESI*/,
    uint32_t* key /*ECX*/,
    void** out_it /*EAX*/);
```

## Evidence

- Live Ghidra decompile 2026-07-29 ≡ raw 2026-07-23 CF
- Full body hex via `read_memory` (116 B); three bare `C3` epilogues
- 0 callees (leaf); ~13 callers including sto factory + GfxMesh + operator[] shell
- Sibling insert `NestedHash0x10_Insert_Inferred` (`0x0046bf90`)
- Dual A/B **accept**

## Rejected aliases

- `Named_CalleeOf_Named_gfxDeviceIB_0046c1b0` (scaffold chain)
- Conflation with `HashMap_FindIterator_Inferred` (`0x0044e8c0` — string hash + different ABI)

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0046c1b0_FUN_0046c1b0.md` |
| Annotated | `docs/reconstruction/raw/aa_0046c1b0_FUN_0046c1b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NestedHash0x10_FindIterator_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0046c1b0.cpp` |
| FUN record | `docs/reconstruction/functions/aa_0046c1b0_FUN_0046c1b0.md` |
| Review A | `docs/reconstruction/reviews/A_aa_0046c1b0_NestedHash0x10_FindIterator_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0046c1b0_NestedHash0x10_FindIterator_Inferred.md` |
