# Dual A/B report — W36-S OWN `aa_004a7aa0` + `aa_004a7a70`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W36-S  
**Scope:** VAs `0x004a7aa0`, `0x004a7a70` only. Dual A/B + artifacts (trio + function + A/B).  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `batch_decompile` / `decompile_function` + `get_function_by_address` + xrefs/callees + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave36_partition_map.md` (W36-S).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004a7aa0` StdVector_DestroyRange_BasicStringW | **accept-with-gaps** — destroy-range ABI/CF/0x1c/IAT wchar dtor sealed; product demangle open |
| `aa_004a7a70` StdUninitFillN_BasicStringW | **accept-with-gaps** — fill-n wrapper ABI/RET 0x0C/`*0x1c` sealed; nested `FUN_004a74f0` product open |

---

## VA `0x004a7aa0` — sealed facts

1. **Body:** `0x004a7aa0`–`0x004a7ac4` exclusive (**36 B** / `0x24`; pad `CC`).
2. **ABI:** stack **`first*`**, **`last*`**; **`RET 0x08`** (`C2 08 00`); void.
3. **Semantics:** MSVC-style **destroy-range** over `basic_string<wchar_t>` storage:
   - Loop `[first, last)` with stride **`0x1c`**.
   - Each elem: IAT **`~basic_string<wchar_t>`** via `[0x009c62ac]` → `0x006eb03a`.
   - Does **not** free the buffer (parent insert grow calls `operator_delete` after).
4. **Classification:** worker.
5. **Callers:** `FUN_004a7ad0` / `StdVector_InsertN_BasicStringW` @ `0x004a7c82`; Catch@`0x004a7cbd`; Catch@`0x004a7d90`.
6. **Callees:** IAT `~basic_string<wchar_t>`.
7. **Name:** `StdVector_DestroyRange_BasicStringW` (Ghidra `FUN_004a7aa0`; **Inferred** structural). Reject scaffold `Named_CalleeOf_*`. Twin of char `StdVector_DestroyRange_BasicString` (`0x00431aa0`, W33-H).
8. **Decompile ≡ bytes** for CF/stride/RET.  
   Full hex: raw W36-S append (36 B).

### Gaps

- Product/MSVC demangle (`_Destroy_range` English).  
- IAT dtor full symbol plate.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004a7aa0_StdVector_DestroyRange_BasicStringW.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004a7aa0_StdVector_DestroyRange_BasicStringW.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004a7aa0_FUN_004a7aa0.md` |
| Annotated | `docs/reconstruction/raw/aa_004a7aa0_FUN_004a7aa0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_DestroyRange_BasicStringW.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004a7aa0.cpp` |
| Function | `docs/reconstruction/functions/aa_004a7aa0_FUN_004a7aa0.md` |
| Function named | `docs/reconstruction/functions/aa_004a7aa0_StdVector_DestroyRange_BasicStringW.md` |

---

## VA `0x004a7a70` — sealed facts

1. **Body:** `0x004a7a70`–`0x004a7aa0` exclusive (**48 B** / `0x30`); next is destroy-range sibling.
2. **ABI:** **ECX=`alloc`/host**; stack **dest\***, **count**, **value\***; **`RET 0x0C`** (`C2 0C 00`); returns **dest + count×0x1C** in EAX.
3. **Semantics:** Thin **`_Uninit_fill_n`** wrapper for `basic_string<wchar_t>` stride **0x1C**:
   - `FUN_004a74f0(dest, count, value, alloc, value)` — nested SEH fill loop (copy-ctor from value, ×count).
   - `ADD ESP, 0x14`; lea math `count*28` → end pointer.
4. **Classification:** worker (STL helper wrapper).
5. **Callers:** **only** `FUN_004a7ad0` (`StdVector_InsertN_BasicStringW`) @ `0x004a7d4a` (in-place **hole** arm). Grow path calls `FUN_004a74f0` directly.
6. **Callees:** `FUN_004a74f0`.
7. **Name:** `StdUninitFillN_BasicStringW` (Ghidra `FUN_004a7a70`; **Inferred** structural). **Reject** scaffold `Named_CalleeOf_*`. Twin of char `StdUninitFillN_BasicString` (`0x00430390`, W33-G).
8. **Decompile ≡ bytes** for wrapper CF; call target `0x004a74f0` sealed.  
   Full hex: raw W36-S append (48 B).

### Gaps

- Nested `FUN_004a74f0` product plate / demangle (not owned; W36-R).  
- Allocator ECX formal English.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004a7a70_StdUninitFillN_BasicStringW.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004a7a70_StdUninitFillN_BasicStringW.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004a7a70_FUN_004a7a70.md` |
| Annotated | `docs/reconstruction/raw/aa_004a7a70_FUN_004a7a70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdUninitFillN_BasicStringW.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004a7a70.cpp` |
| Function | `docs/reconstruction/functions/aa_004a7a70_FUN_004a7a70.md` |
| Function named | `docs/reconstruction/functions/aa_004a7a70_StdUninitFillN_BasicStringW.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004a7aa0` | Port as **destroy `[first,last)` of `basic_string<wchar_t>`** stride **0x1c**. **Do not** free the buffer here. **`RET 0x08`**. Call after grow relocate, before `operator_delete(old)`. Use **wchar** dtor IAT — not char twin `00431aa0`. |
| `004a7a70` | Port as **`uninit_fill_n` wrapper**: thiscall alloc + `(dest,count,value)` → `dest+count`; **`RET 0x0C`**. Loop lives in nested `FUN_004a74f0`. Sole retail caller is insert-n **hole** fill; grow may call loop helper directly. |
| Pair with | W34-R `StdVector_InsertN_BasicStringW` (`0x004a7ad0`); W36-R `FUN_004a6b50` / `FUN_004a74f0` (relocate + fill core); char twins W33-H `00431aa0` + W33-G `00430390`. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x004a7ad0` | sole parent — `StdVector_InsertN_BasicStringW` (W34-R) |
| `0x004a74f0` | nested uninit fill loop body (W36-R) |
| `0x004a6b50` | nested uninit copy / relocate (W36-R) |
| `0x00431aa0` | char destroy-range twin (W33-H) |
| `0x00430390` | char uninit-fill-n wrapper twin (W33-G) |

Closes W36-S OWN pair: the two nested helpers left open under W34-R insert-n (destroy-range + hole fill-n wrapper).

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004a7aa0-004a7a70-w36s-report.md` |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; `_Inferred` structural names only (`StdVector_DestroyRange_BasicStringW` / `StdUninitFillN_BasicStringW` from char twins + parent BasicStringW family).  
- Rejected long Named_CalleeOf scaffold aliases.  
- Avoided bare `undefined4` in clean (`uint32_t` / `BasicStringW_0x1c`).
