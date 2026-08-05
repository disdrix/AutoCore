# Dual A/B report — W37-E OWN `aa_007669d0` + `aa_00431b30`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W37-E  
**Scope:** VAs `0x007669d0`, `0x00431b30` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `analyze_function_complete` + `read_memory` + xrefs/callers. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave37_partition_map.md` (W37-E).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_007669d0` stoFileOSFile_Open | **accept-with-gaps** — CreateFile mode matrix, ABI RET 0x0C, HANDLE@+8, log plate sealed; method demangle + quality singleton open |
| `aa_00431b30` StdVector_BuyN_BasicString | **accept-with-gaps** — blank-buy no-free / stride 0x1c / max / 0\|1 return sealed; product demangle open |

---

## VA `0x007669d0` — sealed facts

1. **Body:** `0x007669d0`–`0x00766d8c` exclusive (**956 B** / `0x3BC`); dual `C2 0C 00`; switch jump table at `0x00766d90`.
2. **ABI:** **ECX=`stoFileOSFile*`**; stack **path** (LPCSTR), **mode**, **dwFlagsAndAttributes**; **`RET 0x0C`**; returns **0** success / **`0xFFFFFFFF`** fail.
3. **Semantics:** arda2 **`stoFileOSFile` open**:
   - Store mode @ `this+4`; HANDLE @ `this+8`.
   - Optional quality remap when `FUN_007a69d0()->+0x2c != 0` for **`.ogg`** / **`.dds`** only (scratch `DAT_00d206c8`; `fopen("rb")` probe then path swap). Quality tags: `1→_FR`, `2→_DE`, `3→_UK`. DDS suffix table includes `_on/_off/_over/_down`.
   - Mode → CreateFile (share always `FILE_SHARE_READ`):
     | mode | access | disposition |
     |---|---|---|
     | 0 | — | fail immediately |
     | 1 | `0x20001` | OPEN_EXISTING (3) |
     | 2 | `0x20006` | OPEN_EXISTING (3) |
     | 3 | `0x20007` | OPEN_EXISTING (3) |
     | 4,5 | `0` | OPEN_EXISTING (3) |
     | 6 | `0x20006` | CREATE_ALWAYS (2) |
   - Fail: `GetLastError` → `FormatMessageA` → `"File open error <%s> - %s"` → `vog_LogMessage(…\stoFileOSFile.cpp, 0xB9, 2, …)`.
4. **Classification:** worker.
5. **Callers (10 funcs / 14 sites):** `FUN_005ea300`, `FUN_009965e0`, `FUN_0099bfe0`, `FUN_009841d0`, `FUN_0071a9d0`, `FUN_00984910`, `FUN_00984d30`, `FUN_009615c0`, `FUN_00999650`, `FUN_00751da0`. Mode **1** = read, mode **6** = write/create (prior duals).
6. **Callees:** `FUN_007a69d0`; `strstr`; `fopen`/`fclose`; `CreateFileA`; `GetLastError`; `FormatMessageA`; `FUN_0076cec0`; `vog_LogMessage`.
7. **Name:** `stoFileOSFile_Open` (Ghidra `FUN_007669d0`; class/file **Confirmed** via log path; method Open **Inferred**). Reject bare scaffold-only naming without plate.
8. **Decompile ≡ bytes** for CF/mode switch/log; dual `RET 0x0C` sealed.  
   Full hex: raw W37-E append (956 B).

### Gaps

- Exact product C++ method demangle.  
- `FUN_007a69d0` quality field product plate; 5th DDS table entry string.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_007669d0_stoFileOSFile_Open.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_007669d0_stoFileOSFile_Open.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_007669d0_FUN_007669d0.md` |
| Annotated | `docs/reconstruction/raw/aa_007669d0_FUN_007669d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/stoFileOSFile_Open.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_007669d0.cpp` |
| Function | `docs/reconstruction/functions/aa_007669d0_FUN_007669d0.md` |
| Function named | `docs/reconstruction/functions/aa_007669d0_stoFileOSFile_Open.md` |
| Scratch | `docs/reconstruction/tmp/a_007669d0.md` |

---

## VA `0x00431b30` — sealed facts

1. **Body:** `0x00431b30`–`0x00431b82` exclusive (**82 B** / `0x52`; pad `CC` then next).
2. **ABI:** **ECX=`vector*`** (StringVec shell); stack **`n`**; **`RET 4`** (`C2 04 00`); returns **AL** `0` if `n==0`, **`1`** after buy.
3. **Semantics:** MSVC-style **blank capacity buy** for `vector<basic_string>` (elem **0x1c**):
   - Zero begin@`+4` / end@`+8` / capEnd@`+0xC` — **no free** of prior buffer.
   - `n==0` → return 0 (empty triad).
   - `n > 0x9249249` → `FUN_004540b0()` noreturn throw `"vector<T> too long"`.
   - Else `operator_new(n*0x1c)`; begin=end=buf (size 0); capEnd=buf+nbytes; return 1.
4. **Classification:** worker.
5. **Callers (1):** `FUN_00469d10` (`StdVector_AssignFrom_BasicString`, W34-S) @ `0x00469d56`.
6. **Callees:** `FUN_004540b0`; `operator_new`.
7. **Name:** `StdVector_BuyN_BasicString` (Ghidra `FUN_00431b30`; **Inferred** structural). Closes W34-S residual nested buy plate.
8. **Decompile ≡ bytes** for CF; **bytes win** on noreturn throw (decomp falsely reuses throw return as `n`).  
   Full hex: raw W37-E append (82 B).

### Gaps

- Product/MSVC demangle for exact `_Buy` helper.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00431b30_StdVector_BuyN_BasicString.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00431b30_StdVector_BuyN_BasicString.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00431b30_FUN_00431b30.md` |
| Annotated | `docs/reconstruction/raw/aa_00431b30_FUN_00431b30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_BuyN_BasicString.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00431b30.cpp` |
| Function | `docs/reconstruction/functions/aa_00431b30_FUN_00431b30.md` |
| Function named | `docs/reconstruction/functions/aa_00431b30_StdVector_BuyN_BasicString.md` |
| Scratch | `docs/reconstruction/tmp/a_00431b30.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `007669d0` | Port as **`stoFileOSFile::Open(path, mode, attrs)`**: thiscall, **`RET 0x0C`**, return 0/-1 (not HANDLE). Honor mode matrix (1=read, 2=write-existing, 3=rw, 6=create+write). Optional quality remap for `.ogg`/`.dds` only. Share `FILE_SHARE_READ`. Fail log plate matches client. |
| `00431b30` | Port as **vector blank-buy**: ECX=dest, stack n, **`RET 4`**, AL 0/1. **Do not free** prior buffer. Leave size 0 after buy. Max `0x9249249` → length_error. Callers (assign-from) must pass empty dest. |
| Pair with | W34-S `StdVector_AssignFrom_BasicString` (`0x00469d10`); W33-G `StdUninitCopy_BasicString` (`0x0046a2c0`); W33-D `StringVec_Tidy` (`0x00431ae0`); W33-E / W34-I FS path readers using open mode 1; pack extract open mode 6; throw `FUN_004540b0`; quality singleton `FUN_007a69d0`. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; `stoFileOSFile` class Confirmed from path string; method Open + `StdVector_BuyN_BasicString` structural `_Inferred` where English not Confirmed.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).  
- Terminal coverage: **false** (no runtime/diff/bit-exact Confirmed).  
- Closes W34-S residual nested buy dual; closes nested open plate for FS/pack callers.
