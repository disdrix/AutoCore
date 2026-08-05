# Dual A/B report — W36-R OWN-ONLY (`0x004a6b50`, `0x004a74f0`)

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W36-R  
**Scope:** OWN ONLY VAs `0x004a6b50`, `0x004a74f0`. Dual A/B + artifacts (trio + function + A/B).  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave36_partition_map.md` → **W36-R**.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `decompile_function` / `get_function_by_address` / `get_xrefs_to` / `get_function_callers` / `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_004a6b50` StdUninitCopy_BasicStringW | **accept-with-gaps** — cdecl uninit-copy first/last/dest→dest_end; stride 0x1c wstring; SEH catch sealed; product demangle open |
| `aa_004a74f0` StdUninitFillN_BasicStringW | **accept-with-gaps** — cdecl uninit-fill-n dest/count/value; stride 0x1c wstring; full SEH loop; product demangle open |

---

## `aa_004a6b50` — StdUninitCopy_BasicStringW

### Sealed facts

1. **Body:** `0x004a6b50`–`0x004a6bdc` exclusive (**140 B** / `0x8C`). Final **`C3`** (bare RET); pad `CC`.

2. **ABI:** **cdecl** stack **first\***, **last\***, **dest\***; bare **`RET`**; returns **dest-end in EAX**. Confirmed `8B 75 10` / `8B 7D 08` / `3B 7D 0C` + `C3`. Not thiscall.

3. **Semantics:** MSVC-style **`_Uninit_copy`** for `basic_string<wchar_t>` elem **0x1C**:
   - SEH `LAB_009a1181`; per-element state 0/1
   - Loop: if dest≠null, IAT copy-ctor `CALL [0x009C62B4]` → `0x006EAF96`; advance first/dest by **0x1C**
   - Success: `first==last` **JZ** → epilogue (skips catch)
   - Catch residual: destroy partial dest via IAT dtor `[0x009C62AC]` → `0x006EB03A`; **`_CxxThrowException(0,0)`** @ `0x006A3D60`

4. **Classification:** worker (STL helper).

5. **Callers (1 parent, 4 sites):** `FUN_004a7ad0` (`StdVector_InsertN_BasicStringW`, W34-R) @ `0x004a7c06`, `0x004a7c44`, `0x004a7d18`, `0x004a7daa`.

6. **Related:** char twin `StdUninitCopy_BasicString` (`0x0046a2c0`, W33-G); parent insert-n `0x004a7ad0` (W34-R); sibling fill-n `0x004a74f0`.

7. **Name:** `StdUninitCopy_BasicStringW` (Ghidra `FUN_004a6b50`; **Inferred**). **Reject** scaffold `Named_CalleeOf_Named_*_004a6b50`.

8. **Decompile ≡ happy-path raw CF** (live 2026-07-29 ≡ scaffold 2026-07-23); catch sealed by **bytes**.

### Gaps

1. Product/MSVC demangle plate for exact `_Uninit_copy` specialization.  
2. Runtime / bit-exact / differential — open.  
3. Null-dest path residual (unused by sole known parent).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_004a6b50_StdUninitCopy_BasicStringW.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_004a6b50_StdUninitCopy_BasicStringW.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004a6b50_StdUninitCopy_BasicStringW.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004a6b50_StdUninitCopy_BasicStringW.md` |
| Function record | `docs/reconstruction/functions/aa_004a6b50_StdUninitCopy_BasicStringW.md` |
| Scaffold record | `docs/reconstruction/functions/aa_004a6b50_FUN_004a6b50.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdUninitCopy_BasicStringW.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_004a6b50.cpp` |
| Raw (+ W36-R append) | `docs/reconstruction/raw/aa_004a6b50_FUN_004a6b50.md` |
| Annotated | `docs/reconstruction/raw/aa_004a6b50_FUN_004a6b50.annotated.md` |
| Scratch | `docs/reconstruction/tmp/a_004a6b50.md` |

---

## `aa_004a74f0` — StdUninitFillN_BasicStringW

### Sealed facts

1. **Body:** `0x004a74f0`–`0x004a757c` exclusive (**140 B** / `0x8C`). Final **`C3`** (bare RET); pad `CC`.

2. **ABI:** **cdecl** stack **dest\***, **count**, **value\***; bare **`RET`**; void. Confirmed `8B 75 08` / `8B 7D 0C` / `8B 45 10` + `C3`.

3. **Semantics:** MSVC-style **`_Uninit_fill_n`** for `basic_string<wchar_t>` elem **0x1C**:
   - SEH `LAB_009a11c1`; per-element state 0/1
   - Loop: if dest≠null, IAT copy-ctor from `*value` (same `[0x009C62B4]`); `count--`; dest += **0x1C**
   - Early-out: `count==0` unsigned **`JBE`**
   - Catch residual: destroy partial dest; **`_CxxThrowException(0,0)`** @ `0x006A3D60`
   - **Full SEH loop** — not a thin thiscall rebind like char `StdUninitFillN_BasicString` (`0x00430390`)

4. **Classification:** worker (STL helper).

5. **Callers (3):**
   - `FUN_004a7ad0` @ `0x004a7c1c` — insert-n fill arm (W34-R)
   - `FUN_004a7a70` @ `0x004a7a87` — in-place hole fill helper
   - `FUN_004a8100` @ `0x004a8159` — resize/assign fill path

6. **Related:** char fill family `0x00430390` / `0x00431700` (W33-G); parent insert-n `0x004a7ad0`; sibling uninit-copy `0x004a6b50`.

7. **Name:** `StdUninitFillN_BasicStringW` (Ghidra `FUN_004a74f0`; **Inferred**). **Reject** scaffold `Named_CalleeOf_Named_*_004a74f0`.

8. **Decompile ≡ happy-path raw CF**; catch sealed by **bytes**.

### Gaps

1. Product/MSVC demangle plate for exact `_Uninit_fill_n` specialization.  
2. Nested dual seal of non-owned callers `FUN_004a7a70` / `FUN_004a8100`.  
3. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_004a74f0_StdUninitFillN_BasicStringW.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_004a74f0_StdUninitFillN_BasicStringW.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004a74f0_StdUninitFillN_BasicStringW.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004a74f0_StdUninitFillN_BasicStringW.md` |
| Function record | `docs/reconstruction/functions/aa_004a74f0_StdUninitFillN_BasicStringW.md` |
| Scaffold record | `docs/reconstruction/functions/aa_004a74f0_FUN_004a74f0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdUninitFillN_BasicStringW.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_004a74f0.cpp` |
| Raw (+ W36-R append) | `docs/reconstruction/raw/aa_004a74f0_FUN_004a74f0.md` |
| Annotated | `docs/reconstruction/raw/aa_004a74f0_FUN_004a74f0.annotated.md` |
| Scratch | `docs/reconstruction/tmp/a_004a74f0.md` |

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004a6b50-004a74f0-w36r-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004a6b50` | Port as **`uninit_copy` for `vector<wstring>`** (elem **0x1c**): cdecl `(first,last,dest)→dest_end`; bare **RET**. Exception-safe: destroy partial dest on throw. Used by insert-n grow/hole relocate. Do **not** treat as POD memcpy or char-string twin binary. |
| `004a74f0` | Port as **`uninit_fill_n` for `vector<wstring>`**: cdecl `(dest,count,value*)` void; bare **RET**. Full SEH loop in this body (unlike char thin wrapper `00430390`). Used by insert-n fill, hole helper, resize fill. |
| Pair with | W34-R `StdVector_InsertN_BasicStringW` (`0x004a7ad0`); char twins W33-G `0046a2c0` / `00430390`; size leaf `StdVector_Elem28_Size` (`0x00469c50`). |

### Shared context (not owned)

| VA | Role |
|---|---|
| `0x004a7ad0` | sole primary parent insert-n (W34-R sealed) |
| `0x004a7a70` / `0x004a8100` | additional fill-n callers (unowned dual residual) |
| `0x0046a2c0` | char `StdUninitCopy_BasicString` shape twin (W33-G) |
| `0x00430390` / `0x00431700` | char fill-n wrapper + nested body |
| `0x006A3D60` | `_CxxThrowException` |
| `0x009C62B4` / `0x009C62AC` | wstring copy-ctor / dtor IAT |

Closes W34-R residual nested helpers `FUN_004a6b50` + `FUN_004a74f0` named in insert-n dual.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + function/xref helpers + `read_memory`. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; structural `_Inferred` / family names only (`StdUninitCopy/FillN_BasicStringW`).  
- Rejected scaffold `Named_CalleeOf_Named_*` aliases.  
- Avoided bare `undefined4` in clean (`uint8_t` storage / explicit `BasicStringW_0x1c`).  
