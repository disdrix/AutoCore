# Dual A/B report — W32-B OWN `aa_004306b0` + `aa_0040d7c0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W32-B  
**Scope:** VAs `0x004306b0`, `0x0040d7c0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave32_partition_map.md` (W32-B).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004306b0` StdVector_InsertN_BasicString | **accept-with-gaps** — insert-n ABI/CF/0x1c/max/1.5× sealed; product demangle + nested helpers open |
| `aa_0040d7c0` StdTree_Tidy_FreeHead_Val12 | **accept-with-gaps** — tidy order/ABI/head free+null sealed by bytes; product class + nested erase open |

---

## VA `0x004306b0` — sealed facts

1. **Body:** `0x004306b0`–`0x004309bf` exclusive (**783 B** / `0x30F`; pad `CC`).
2. **ABI:** **ECX=`vector*`**; stack **where\***, **count**, **value\***; **`RET 0x0C`** (`C2 0C 00`); void. SEH `LAB_009bccf9`.
3. **Semantics:** MSVC-style **`vector<basic_string<char>>::insert(where, count, value)`** (elem **0x1c**):
   - Copy value to local string under EH.
   - Early-out if `count==0`.
   - Capacity/size via triad begin@`+4` / end@`+8` / capEnd@`+0xC` and `/0x1c` magic `0x92492493`.
   - If `size+count > 0x9249249` → `FUN_004540b0` (too long).
   - Grow: 1.5× (`cap+(cap>>1)`), floor `size+count`; `operator_new`; relocate prefix/suffix (`FUN_0046a2c0`); fill-n (`FUN_00430390`); destroy+delete old (`FUN_00431aa0`).
   - In-place: hole vs mid-shift via `FUN_00431430` / `FUN_00431450` / `FUN_00431480`.
   - Destroy local; return.
4. **Classification:** worker.
5. **Callers:** `FUN_00430310` @ `0x00430363` (insert-one rebind, count=`1`). Indirect: `StringVec_PushFront_EnsureTrailingDirSep` (W31-E).
6. **Callees:** string copy/dtor IAT; `FUN_004540b0`; `FUN_00469c50`; `operator_new`/`delete`; `FUN_0046a2c0`; `FUN_00430390`; `FUN_00431aa0`; `FUN_00431430`/`450`/`480`.
7. **Name:** `StdVector_InsertN_BasicString` (Ghidra `FUN_004306b0`; **Inferred** structural). Reject scaffold `Named_CalleeOf_Named_*`.
8. **Decompile ≡ bytes** for CF; epilogue `C2 0C 00` sealed.  
   Full hex: raw W32-B append (783 B).

### Gaps

- Product/MSVC demangle for exact insert overload.  
- Nested helpers `FUN_00430310` / relocate / fill / destroy not dual-owned.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004306b0_StdVector_InsertN_BasicString.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004306b0_StdVector_InsertN_BasicString.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004306b0_FUN_004306b0.md` |
| Annotated | `docs/reconstruction/raw/aa_004306b0_FUN_004306b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_InsertN_BasicString.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004306b0.cpp` |
| Function | `docs/reconstruction/functions/aa_004306b0_FUN_004306b0.md` |
| Function named | `docs/reconstruction/functions/aa_004306b0_StdVector_InsertN_BasicString.md` |
| Scratch | `docs/reconstruction/tmp/a_004306b0.md` |

---

## VA `0x0040d7c0` — sealed facts

1. **Body:** `0x0040d7c0`–`0x0040d81c` exclusive (**92 B** / `0x5C`; pad `CC`). Ghidra listed end `0040d800` — **truncated**.
2. **ABI:** **ECX=`tree*`** (host+4 from complete dtor); bare **`RET`** (`C3`); void. SEH `LAB_009bda78`.
3. **Semantics:** MSVC-style **`_Tree` tidy / free head** on Val12 tree subobject (head@`+4`, size@`+8`):
   - **`FUN_0040d700(this, &out, *head, head)`** — full-range erase; when range is entire tree, free root via `StdTree_FreeSubtree_Val12` (`head->parent@+4`) and reset sentinel/size.
   - **`operator_delete(head)`** — free header node (cdecl; `ADD ESP,4`).
   - Null **head** and **size**.
4. **Classification:** worker.
5. **Callers:** `FUN_0040d820` @ `0x0040d85b` (`LEA ECX,[ESI+4]`); Unwind `@009be2b6`.
6. **Callees:** `FUN_0040d700`, `operator_delete`.
7. **Name:** `StdTree_Tidy_FreeHead_Val12` (Ghidra `FUN_0040d7c0`; **Inferred**). Closes nested residual named in W31-A complete-dtor dual.
8. **Decompile ≢ bytes** on epilogue (false noreturn); **bytes win**.  
   Full hex: raw W32-B append (92 B).

### Gaps

- Product/MSVC demangle for map T / host class.  
- Nested `FUN_0040d700` product English (not owned).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0040d7c0_StdTree_Tidy_FreeHead_Val12.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0040d7c0_StdTree_Tidy_FreeHead_Val12.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0040d7c0_FUN_0040d7c0.md` |
| Annotated | `docs/reconstruction/raw/aa_0040d7c0_FUN_0040d7c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Tidy_FreeHead_Val12.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0040d7c0.cpp` |
| Function | `docs/reconstruction/functions/aa_0040d7c0_FUN_0040d7c0.md` |
| Function named | `docs/reconstruction/functions/aa_0040d7c0_StdTree_Tidy_FreeHead_Val12.md` |
| Scratch | `docs/reconstruction/tmp/a_0040d7c0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004306b0` | Port as **`vector<string>::insert(where, count, value)`** stride **0x1c**. Honor max `0x9249249`, 1.5× grow, string-aware relocate/fill/destroy. **`RET 0x0C`**. Wrapper `FUN_00430310` is insert-one + iterator rebind. |
| `0040d7c0` | Port as **tree tidy only**: full-range erase, `delete` head, null head+size. Call from host complete dtor on **`this+4` after** value-aware clear (`StdTree_Clear_PtrVal_Vtbl0C`). Ignore Ghidra truncated body. |
| Pair with | `StringVec_PushFront_EnsureTrailingDirSep` (`0x00969830`, W31-E); `StdTreeHost_PtrVal_CompleteDtor` (`0x0040d820`, W31-A); `StdTree_Clear_PtrVal_Vtbl0C` (`0x0040d5b0`, W30-P); `StdTree_FreeSubtree_Val12` (`0x0040d630`, W31-A); nested erase `FUN_0040d700` (unowned). |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; structural `_Inferred` names only.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).  
- Closes W31-A residual nested `FUN_0040d7c0` and W31-E residual nested `FUN_004306b0` (structural plate).
