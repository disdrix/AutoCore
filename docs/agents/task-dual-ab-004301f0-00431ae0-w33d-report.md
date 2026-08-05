# Dual A/B report — W33-D OWN `aa_004301f0` + `aa_00431ae0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W33-D  
**Scope:** VAs `0x004301f0`, `0x00431ae0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave33_partition_map.md` (W33-D).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004301f0` StringVec_PushBack | **accept-with-gaps** — push_back capacity gate + in-place construct / insert-at-end sealed; nested `FUN_00431700` + product demangle open |
| `aa_00431ae0` StringVec_Tidy | **accept-with-gaps** — destroy+free+null triad sealed by bytes (decompile incomplete); product class open |

---

## VA `0x004301f0` — sealed facts

1. **Body:** `0x004301f0`–`0x00430278` exclusive (**136 B** / `0x88`; pad `CC`).
2. **ABI:** **ECX=`StringVecShell*`**; stack **value\*** (`basic_string*`); **`RET 0x04`** (`C2 04 00`); void.
3. **Semantics:** MSVC-style **`vector<basic_string>::push_back`** (elem **0x1c**):
   - Triad begin@`+4` / end@`+8` / capEnd@`+0xC`; size/cap via `/0x1c` magic `0x92492493`.
   - **Fast path** (`begin != 0` && `size < capacity`): cdecl **`FUN_00431700(end, 1, value)`** construct-n; `end += 0x1c`.
   - **Slow path** (null begin or capacity full): thiscall **`FUN_00430310(this, &out_scratch, end, value)`** = `StringVec_InsertOne` at **end** (W32-A → grow `FUN_004306b0` W32-B). Out-iterator discarded.
4. **Classification:** worker.
5. **Callers:** `FUN_009841d0`, `FUN_004a1770`, `FUN_0099bba0`, `FUN_009839b0`, `FUN_0076b3f0`, `FUN_009697a0`, `FUN_00984340` (path/listing push sites).
6. **Callees:** `FUN_00431700`, `FUN_00430310` (`StringVec_InsertOne`).
7. **Name:** `StringVec_PushBack` (Ghidra `FUN_004301f0`; **Inferred** structural). Reject scaffold `Named_CalleeOf_*VOG_DEBUG*_004301f0`.
8. **Decompile ≡ bytes** for CF/capacity gate; both epilogues `C2 04 00` sealed.  
   Full hex: raw W33-D append (136 B).

### Gaps

- Nested `FUN_00431700` product plate / dual not owned.  
- Product/MSVC demangle for exact push_back overload.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004301f0_StringVec_PushBack.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004301f0_StringVec_PushBack.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004301f0_FUN_004301f0.md` |
| Annotated | `docs/reconstruction/raw/aa_004301f0_FUN_004301f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StringVec_PushBack.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004301f0.cpp` |
| Function | `docs/reconstruction/functions/aa_004301f0_FUN_004301f0.md` |
| Function named | `docs/reconstruction/functions/aa_004301f0_StringVec_PushBack.md` |
| Scratch | `docs/reconstruction/tmp/a_004301f0.md` |

---

## VA `0x00431ae0` — sealed facts

1. **Body:** `0x00431ae0`–`0x00431b27` exclusive (**71 B** / `0x47`; pad `CC`).
2. **ABI:** **ECX=`StringVecShell*`** (thiscall / single-arg fastcall-this); bare **`RET`** (`C3`); void.
3. **Semantics:** MSVC-style **`vector<basic_string>::_Tidy`** / buffer release:
   - If **begin == null**: zero begin/end/capEnd; return.
   - Else: destroy `[begin, end)` stride **0x1c** via IAT `~basic_string`; **`operator_delete(begin)`**; zero triad.
4. **Classification:** worker.
5. **Callers:** `FUN_00444810`, `FUN_009841d0`, `FUN_0076ba10`, `FUN_00754320`, `FUN_009839b0`, `FUN_009c37c0`, Catch@`00469d96`, `FUN_00984c70`, `FUN_00984340`. Thunk `0x00431ad0` → `JMP 0x00431ae0`.
6. **Callees:** IAT `~basic_string`, `operator_delete`.
7. **Name:** `StringVec_Tidy` (Ghidra `FUN_00431ae0`; **Inferred**). Reject scaffold `Named_CalleeOf_*assManager*_00431ae0`. Sibling range-dtor-only: `FUN_00431aa0` (unowned; reallocation path).
8. **Decompile ≢ bytes** on tail (false noreturn; missing post-delete zeros); **bytes win**.  
   Full hex: raw W33-D append (71 B).

### Gaps

- Product/MSVC demangle for host container class.  
- Exact CRT free import plate (behavioral free sealed).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00431ae0_StringVec_Tidy.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00431ae0_StringVec_Tidy.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00431ae0_FUN_00431ae0.md` |
| Annotated | `docs/reconstruction/raw/aa_00431ae0_FUN_00431ae0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StringVec_Tidy.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00431ae0.cpp` |
| Function | `docs/reconstruction/functions/aa_00431ae0_FUN_00431ae0.md` |
| Function named | `docs/reconstruction/functions/aa_00431ae0_StringVec_Tidy.md` |
| Scratch | `docs/reconstruction/tmp/a_00431ae0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004301f0` | Port as **`vector<string>::push_back`**: if `size < capacity` construct at end + bump; else insert-at-end (may grow). Stride **0x1c**. **`RET 0x04` thiscall**. Discard insert-one out-iterator. |
| `00431ae0` | Port as **vector tidy / full buffer release**: destroy live strings, `delete` buffer, **null begin+end+cap**. Not capacity-preserving clear. Not range-dtor-only (`FUN_00431aa0`). Ignore Ghidra noreturn warning. |
| Pair with | `StringVec_InsertOne` (`0x00430310`, W32-A); `StdVector_InsertN_BasicString` (`0x004306b0`, W32-B); `StringVec_PushFront_EnsureTrailingDirSep` (`0x00969830`, W31-E); listing cleanup `FUN_009839b0` (W32-D); unowned construct-n `FUN_00431700`; unowned range-dtor `FUN_00431aa0`. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; structural `_Inferred` names only.  
- Avoided bare `undefined4` in clean (`uint8_t*` / explicit structs).  
- Closes W32-A residual “push_back gate `FUN_004301f0`” and W32-D residual listing destroy ABI of `FUN_00431ae0`.
