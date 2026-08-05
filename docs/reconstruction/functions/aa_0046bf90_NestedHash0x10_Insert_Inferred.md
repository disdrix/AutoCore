# Function record: NestedHash0x10_Insert_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0046bf90` |
| **Canonical name** | `NestedHash0x10_Insert_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_0046bf90` |
| **Address** | `0x0046bf90`–`0x0046c1ae` (**543 B** / `0x21F`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | NestedHash bag (sentinel node 0x10) — insert |
| **Completion status** | Dual A/B sealed W36-B 2026-07-29 — **accept** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Worker **insert-or-find** on NestedHash0x10: optional rehash under load, ordered bucket walk, return existing `{node,0}` or buynode-link `{node,1}`. Node size **0x10** (key+value dwords).

## Signature

```c
// EDI=map; stack out_pair*, kv*; RET 8
void NestedHash0x10_Insert_Inferred(
    void* map /*EDI*/,
    InsertResult* out /*stack — node* + bool*/,
    uint32_t* kv /*stack — key, value*/);
```

## Evidence

- Live Ghidra decompile 2026-07-29 ≡ raw 2026-07-23 CF
- Full body hex via `read_memory` (543 B); dual `C2 08 00` epilogues
- Callees: `FUN_0044a380`, `FUN_0046c2a0` (`new(0x10)`), `FUN_0046c230`
- 4 callers (sto factory ×2, operator[] shell, GfxMesh)
- Sibling find `NestedHash0x10_FindIterator_Inferred` (`0x0046c1b0`)
- Dual A/B **accept**

## Rejected aliases

- `Named_CalleeOf_Named_gfxDeviceIB_0046bf90`

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0046bf90_FUN_0046bf90.md` |
| Annotated | `docs/reconstruction/raw/aa_0046bf90_FUN_0046bf90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NestedHash0x10_Insert_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0046bf90.cpp` |
| FUN record | `docs/reconstruction/functions/aa_0046bf90_FUN_0046bf90.md` |
| Review A | `docs/reconstruction/reviews/A_aa_0046bf90_NestedHash0x10_Insert_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0046bf90_NestedHash0x10_Insert_Inferred.md` |
