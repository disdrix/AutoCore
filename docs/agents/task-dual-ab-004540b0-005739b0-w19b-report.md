# Dual A/B report — W19-B OWN-ONLY (`aa_004540b0`, `aa_005739b0`)

**Date:** 2026-07-29  
**Agent:** W19-B OWN-ONLY  
**Scope:** OWN ONLY VAs `0x004540b0`, `0x005739b0`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / other parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004540b0` StdVector_ThrowTooLong | **accept** — vector `"vector<T> too long"` noreturn throw sealed (bytes + plate + callees) |
| `aa_005739b0` StdFill_DwordRange | **accept** — **30-byte** `__cdecl` dword `[first,last)` fill sealed |

---

## Sealed facts — `0x004540b0`

1. **ABI:** no formals; SEH frame; **noreturn**. Body **`0x004540b0`–`0x004540fa`** (**75 bytes**).

2. **Plate string:** `0x00a15830` = **`"vector<T> too long"`** (`read_memory`).

3. **Algorithm:** `basic_string` ctor (IAT `[0x009c62f8]`) → `FUN_00401a40` (exception from string; vtbl `PTR_FUN_009c7634`) → `_CxxThrowException(&ex, &DAT_00acc388)`.

4. **ThrowInfo:** `DAT_00acc388` pushed as second throw arg (bytes sealed).

5. **Role:** MSVC **`vector::_Xlen()`-class** shared overflow throw. Callers: **100+** grow/insert size-guard sites (e.g. `FUN_004507a0` when `param_3` would exceed max).

6. **Name:** `StdVector_ThrowTooLong` — role-sealed **INFERRED** from plate + CF. Ghidra: `FUN_004540b0`.

7. **Siblings:** other VAs also embed the same plate string as local throw bodies; this VA is the **shared CALLee** for many paths.

---

## Sealed facts — `0x005739b0`

1. **ABI:** `void __cdecl StdFill_DwordRange(uint32_t *first, uint32_t *last, uint32_t const *value)` — stack `[esp+4/8/C]`; bare **`ret`**.

2. **Body:** `0x005739b0`–`0x005739cd` (**30 bytes**).

3. **Algorithm:** half-open range fill; stride **4**; `*first = *value` each step; re-reads `*value` every iteration; empty range is no-op.

4. **Leaf:** no callees, no SEH, no construction — POD assign only.

5. **Parents:** 29+ including `FUN_004073a0` (InsertN dword family), `FUN_004507a0` (insert hole fill after shift/grow).

6. **Name:** `StdFill_DwordRange` — role-sealed **INFERRED**. Ghidra: `FUN_005739b0`.

---

## Gaps

### `004540b0`
1. Product/PDB English (`std::vector<T>::_Xlen` or equivalent).  
2. Exact C++ exception type hierarchy (`FUN_00401a40` / ThrowInfo RTTI) — out of owned scope.  
3. Runtime / bit-exact / differential — open.  
4. Sibling same-string throw bodies at other VAs — not merged here.

### `005739b0`
1. Product/PDB symbol (`std::fill` / `_Fill`).  
2. Runtime / bit-exact / differential — open.  
3. Exhaustive element-type catalog behind dword storage — caller-owned.

---

## Files

### `aa_004540b0`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004540b0_StdVector_ThrowTooLong.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004540b0_StdVector_ThrowTooLong.md` |
| Function record | `docs/reconstruction/functions/aa_004540b0_StdVector_ThrowTooLong.md` |
| Scaffold record | `docs/reconstruction/functions/aa_004540b0_FUN_004540b0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_ThrowTooLong.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_004540b0.cpp` |
| Raw (authoritative body + re-verify append) | `docs/reconstruction/raw/aa_004540b0_FUN_004540b0.md` |
| Annotated | `docs/reconstruction/raw/aa_004540b0_FUN_004540b0.annotated.md` |

### `aa_005739b0`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_005739b0_StdFill_DwordRange.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005739b0_StdFill_DwordRange.md` |
| Function record | `docs/reconstruction/functions/aa_005739b0_StdFill_DwordRange.md` |
| Scaffold record | `docs/reconstruction/functions/aa_005739b0_FUN_005739b0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdFill_DwordRange.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_005739b0.cpp` |
| Raw (authoritative body + re-verify append) | `docs/reconstruction/raw/aa_005739b0_FUN_005739b0.md` |
| Annotated | `docs/reconstruction/raw/aa_005739b0_FUN_005739b0.annotated.md` |

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004540b0-005739b0-w19b-report.md` |

---

## AutoCore impact

- **`004540b0`:** Port size-overflow arms as hard fail / managed exception with message `"vector<T> too long"`. Do not soft-continue past max element count. Map to a single shared helper called from all vector grow/insert guards.
- **`005739b0`:** Port as trivial dword range fill (`for` / `Array.Fill` / `Span` fill). Use only for POD 4-byte elements; do not add constructors. Preserve pointer-to-value ABI when matching client call sites that pass `&template`.
