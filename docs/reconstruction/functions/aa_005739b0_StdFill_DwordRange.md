# Function record: StdFill_DwordRange

| Field | Value |
|---|---|
| **Stable ID** | `aa_005739b0` |
| **Canonical name** | `StdFill_DwordRange` |
| **Ghidra name** | `FUN_005739b0` |
| **Address** | `0x005739b0` |
| **Body range** | `0x005739b0`–`0x005739cd` (30 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `containers` / POD fill |
| **Completion status** | **partial** — dual A/B **accept**; CF + bytes sealed; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_005739b0_StdFill_DwordRange.md`, `reviews/B_aa_005739b0_StdFill_DwordRange.md` (2026-07-29 W19-B) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_005739b0`
- `Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_AddCharacter_005739b0` (legacy xref scaffold)

## Purpose

Leaf **`std::fill`-class** helper: assign `*value` across half-open dword range `[first, last)`. Element stride **4**. Used by vector insert/assign paths after grow or in-place shift.

## Signature

```c
void __cdecl StdFill_DwordRange(uint32_t *first, uint32_t *last,
                                uint32_t const *value);
// stack: [esp+4]=first, [esp+8]=last, [esp+0xC]=value; bare RET
```

## Algorithm

1. Load `first`, `last`, `value` from stack.
2. If `first == last`, return.
3. Loop: `*first = *value`; `first += 1` (advance 4 bytes); until `first == last`.
4. `*value` re-read each iteration.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005739b0_FUN_005739b0.md`
- Annotated: `docs/reconstruction/raw/aa_005739b0_FUN_005739b0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdFill_DwordRange.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_005739b0.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_005739b0_FUN_005739b0.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-004540b0-005739b0-w19b-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | none (leaf) |
| **Callers (29+)** | `FUN_004073a0` (StdVector_InsertN_Dword family), `FUN_004507a0` (insert fill), `FUN_004490a0`, `FUN_00493830`, `FUN_0049c8a0`, `FUN_004a6f70`, `FUN_004a76e0`, `FUN_004ba850`, `FUN_004c2bb0`, `FUN_004e39d0`, `FUN_005064e0`, `FUN_00539810`, `FUN_005438c0`, `FUN_00548210`, `FUN_00574470`, `FUN_0057fd40`, `FUN_00596770`, `FUN_005a3920`, `FUN_005b7860`, `FUN_005b7bd0`, `FUN_005c9cc0`, `FUN_005f52b0`, `FUN_00602920`, `FUN_00604500`, `FUN_006762a0`, `FUN_0067f930`, `FUN_006890c0`, `FUN_0068bae0`, `FUN_00697f60` |

## Confidence

| Claim | Level |
|---|---|
| Control flow + bytes | **High** |
| `__cdecl` three stack pointers | **High** |
| Element width 4 | **High** (`add eax,4`) |
| Half-open `[first,last)` | **High** |
| Leaf / no ctor side effects | **High** |
| Product English `std::fill` symbol | **Inferred** |
| Runtime / differential | Open |

## Related

- Parent insert: `StdVector_InsertN_Dword_Inferred` (`aa_004073a0`)
- Sibling fill-N helpers for larger POD (e.g. combat floater 0x38) are separate units
