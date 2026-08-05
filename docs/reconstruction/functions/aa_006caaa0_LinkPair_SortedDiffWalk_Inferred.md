# Function record: LinkPair_SortedDiffWalk_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006caaa0` |
| **Canonical name** | `LinkPair_SortedDiffWalk_Inferred` |
| **Ghidra name** | `FUN_006caaa0` |
| **Address** | `0x006caaa0`–`0x006cac19` (**378 B** / `0x17A`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | world-object / spatial-link merge |
| **Completion status** | **Dual sealed** (W27-N 2026-07-29) — A/B accept |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Ghidra: `FUN_006caaa0`
- Prior scaffold alias: `Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_006caaa0` (auto path name; superseded for dual)

## Purpose

Two-pointer **sorted diff walk** over two ranges of 8-byte link pairs. Matches skip both; right-only fires handler vcall +8; left-only optionally fires handler vcall +4 after a predicate gate. Used on the **complex** branch of world-object bind/unbind when `*(obj+0x40) != 0` (simple branch uses `FUN_006297e0` only).

## Signature (machine)

```c
// thiscall; ECX = handler_table; ret 0x14; void
void LinkPair_SortedDiffWalk_Inferred(
    int handler_table,
    int *left_pairs,
    int *left_count,   // count → end = base + count*2 ints
    int *right_pairs,
    int right_count,
    std::uint32_t *predicate_obj);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_006caaa0_FUN_006caaa0.md` (+ W27-N append)
- Annotated: `docs/reconstruction/raw/aa_006caaa0_FUN_006caaa0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/LinkPair_SortedDiffWalk_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_006caaa0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_006caaa0_LinkPair_SortedDiffWalk_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_006caaa0_LinkPair_SortedDiffWalk_Inferred.md`

## Callers / callees

| Direction | Targets |
|---|---|
| Callers (6) | `FUN_0055fa40`, `FUN_0055fbf0`, `FUN_0055ff20`, `FUN_00560020`, `FUN_006297e0`, `FUN_00634450` |
| Callees | none direct — handler-table vcalls (+4 / +8) + predicate vcall |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ live | **High** |
| ABI thiscall + `ret 0x14` | **High** |
| Pair stride 8 B / keys at +4 | **High** |
| Role in bind/unbind complex path | **High** (caller duals W26-D/E) |
| Product English / handler matrix | **Tentative / Inferred** |
| Predicate semantics | **Medium** |
| Runtime / bit-exact | **Open** |
