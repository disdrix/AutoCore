# Function record: Map_LowerBoundFindByIntKey_Isnil65

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cbd50` |
| **Canonical name** | `Map_LowerBoundFindByIntKey_Isnil65` |
| **Ghidra name** | `FUN_004cbd50` |
| **Address** | `0x004cbd50`–`0x004cbdb1` (**98 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | ordered map / AI profile lookup |
| **Completion status** | **Sealed dual A/B accept** (W26-O 2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Alias

- Ghidra: `FUN_004cbd50`
- Prior scaffold: `Named_CalleeOf_CVOGHBAIDriver_DoLogic_004cbd50`

## Purpose

Leaf MSVC ordered-tree **exact find** for a **signed dword** key. Lower_bound-shaped walk from `head→parent` with **isnil @ +0x65**, key @ **+0x0C**, left/right links; post-gate enforces equality and writes node or end into `*pOutIt`.

## Signature (sealed)

```c
void __thiscall Map_LowerBoundFindByIntKey_Isnil65(
    MapHeader_Isnil65 *this,   /* ECX; end at this+4 */
    MapNode_Isnil65 **pOutIt,  /* Stack[0x4] */
    int32_t *pKey);            /* Stack[0x8] */
/* cleanup: ret 8 */
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004cbd50_FUN_004cbd50.md`
- Annotated: `docs/reconstruction/raw/aa_004cbd50_FUN_004cbd50.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Map_LowerBoundFindByIntKey_Isnil65.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004cbd50.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_004cbd50_Map_LowerBoundFindByIntKey_Isnil65.md`
- Dual B: `docs/reconstruction/reviews/B_aa_004cbd50_Map_LowerBoundFindByIntKey_Isnil65.md`

## Callers / callees

| Direction | Targets |
|---|---|
| **Callees** | *(none — leaf)* |
| **Callers** | `FUN_004c9120`, `FUN_004c9430`, `CVOGHBAIDriver_DoLogic`, `FUN_005d7ca0`, `FUN_005d7f70` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ bytes | **High** |
| thiscall + ret 8 | **High** |
| isnil +0x65 / key +0x0C / L/R links | **High** |
| Exact-find (not pure lower_bound API) | **High** |
| Product STL name | **Open** |
| Full value_type schema | **Open** |
