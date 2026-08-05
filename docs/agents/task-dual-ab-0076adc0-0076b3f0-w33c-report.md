# Dual A/B report — W33-C OWN `aa_0076adc0` + `aa_0076b3f0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W33-C  
**Scope:** VAs `0x0076adc0`, `0x0076b3f0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` (no disasm) + `read_memory` + xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave33_partition_map.md` (W33-C).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0076adc0` Fs_PathIsDirectory_Stat_Inferred | **accept-with-gaps** — cdecl is_dir via CRT `stat` + S_IFDIR sealed; product/CRT demangle open |
| `aa_0076b3f0` Fs_ListDirBasenames_Inferred | **accept-with-gaps** — 2-arg cdecl list + `"/*"` gate + basename push sealed; decompiler 1-arg gap closed by bytes; product/SSO residual |

---

## VA `0x0076adc0` — sealed facts

1. **Body:** `0x0076adc0`–`0x0076ae35` (**118 B** / `0x76`; pad `CC`).
2. **ABI:** **cdecl** 1 formal `const char* path` @ `[esp+4]`; both exits **`ADD ESP,0x128; RET`** (`C3`); returns **0/1** in EAX/AL.
3. **Semantics:**
   - Byte-copy path into 260-byte stack buffer.
   - Strip one trailing `\` (`0x5C`) or `/` (`0x2F`) if present.
   - `stat(buf, &st)` via IAT `[0x009c6504]`.
   - Fail: **`XOR AL,AL`** → **0** (decompiler `uVar4 & 0xffffff00` is a false widening).
   - Success: load dword at **`stat_buf+6`** (`st_mode`), **`(x >> 14) & 1`** = **S_IFDIR** (`0x4000`).
4. **Classification:** worker.
5. **Callers (8):** `FUN_0076b3f0`, `FUN_0076ba10`, `FUN_0076bc00`, `FUN_0076bc80`, `FUN_007a13e0`, `FUN_007b75b0`, `FUN_009839b0`, `FUN_00984340`.
6. **Callees:** `stat` only.
7. **Name:** `Fs_PathIsDirectory_Stat_Inferred` (Ghidra `FUN_0076adc0`; **Inferred**).
8. **Decompile ≡ bytes** for CF; **bytes win** on fail-return zeroing. Full hex in raw W33-C append (118 B).

### Gaps

- Product/MSVC demangle for free helper.  
- Exact CRT import name (`stat` vs `_stat` / `_stat32`).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0076adc0_Fs_PathIsDirectory_Stat_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0076adc0_Fs_PathIsDirectory_Stat_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0076adc0_FUN_0076adc0.md` |
| Annotated | `docs/reconstruction/raw/aa_0076adc0_FUN_0076adc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Fs_PathIsDirectory_Stat_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0076adc0.cpp` |
| Function | `docs/reconstruction/functions/aa_0076adc0_FUN_0076adc0.md` |
| Function named | `docs/reconstruction/functions/aa_0076adc0_Fs_PathIsDirectory_Stat_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_0076adc0.md` |

---

## VA `0x0076b3f0` — sealed facts

1. **Body:** `0x0076b3f0`–`0x0076b54e` (**351 B** / `0x15F`; pad `CC` then next @ `0x0076b550`).
2. **ABI:** **cdecl** **2** formals — `const char* path`, `void* out_string_vec`; SEH **`LAB_009acd96`**; epilogue **`ADD ESP,0x184; RET`**. Void.
3. **Semantics:**
   - `basic_string` pattern from path (MSVC8 SSO; cap threshold `0x10`).
   - If `FUN_0076adc0(path)` → `operator+=("/*")` (`DAT_00a9d210` = `2f 2a 00`).
   - `FindFirstFileA` / `FindNextFileA` / `FindClose` (IAT `0x009c60ec` / `0x009c60e4` / `0x009c60e8`).
   - Skip exact `.` (`DAT_00a2e610`) and `..` (`DAT_00a9d20c`) via `REPE CMPSB` lengths **2** and **3** (incl. NUL).
   - Else: string from `cFileName` → **thiscall** `FUN_004301f0(out_vec, &tmp)` push.
   - **Basenames only** — no parent join; no `dwFileAttributes` dir/file filter; **no recurse**.
4. **Classification:** worker.
5. **Callers (4):** `FUN_0076ba10`, `FUN_009698a0`, `FUN_009839b0`, `FUN_00984340`.
6. **Callees:** `FUN_0076adc0`, `basic_string` ctor/dtor/`+=`, `FindFirstFileA`, `FindNextFileA`, `FindClose`, `FUN_004301f0`.
7. **Name:** `Fs_ListDirBasenames_Inferred` (Ghidra `FUN_0076b3f0`; **Inferred**).
8. **Bytes win:** decompiler shows 1 formal; second arg recovered from callers + ECX setup at push site. Consumer string stride **0x1c** (W32-D). Hex head+tail in raw W33-C append.

### Gaps

- Product English / demangle.  
- Full SSO field map beyond cap `< 0x10`.  
- `FUN_004301f0` product plate (W33-D).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0076b3f0_Fs_ListDirBasenames_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0076b3f0_Fs_ListDirBasenames_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0076b3f0_FUN_0076b3f0.md` |
| Annotated | `docs/reconstruction/raw/aa_0076b3f0_FUN_0076b3f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Fs_ListDirBasenames_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0076b3f0.cpp` |
| Function | `docs/reconstruction/functions/aa_0076b3f0_FUN_0076b3f0.md` |
| Function named | `docs/reconstruction/functions/aa_0076b3f0_Fs_ListDirBasenames_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_0076b3f0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0076adc0` | Port as **cdecl is_directory**: strip one trailing sep, CRT `stat`, return `(st_mode & S_IFDIR) != 0`. Fail → false. Do **not** invent GetFileAttributes. |
| `0076b3f0` | Port as **cdecl (path, out_vec\*)** flat basename enumerator. If is_dir append `"/*"`. Skip `.`/`..`. Push basenames only via vector push. **No** recurse, **no** full-path join, **no** dir/file filter. |
| Pair with | W32-D `Fs_DirRecurseCollectLeafPaths` (`009839b0`); W33-D `FUN_004301f0` / `FUN_00431ae0`; callers `0076ba10`, `00984340`, `009698a0`. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete (disasm off) + read_memory + xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; structural `_Inferred` names only.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit types).  
- Closes W32-D residual high-mention nested callees `FUN_0076adc0` / `FUN_0076b3f0` named in wave33 partition W33-C.
