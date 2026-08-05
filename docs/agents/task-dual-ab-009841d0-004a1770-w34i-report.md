# Dual A/B report — W34-I OWN-ONLY (`aa_009841d0`, `aa_004a1770`)

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W34-I  
**Scope:** VAs `0x009841d0`, `0x004a1770` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` / `batch_decompile` / `analyze_function_complete` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave34_partition_map.md` (W34-I).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_009841d0` Fs_ReadPathListFileToStringVec_Inferred | **accept-with-gaps** — cdecl path-list reader; stoFile mode-1 + line loop + assign sealed; product English residual |
| `aa_004a1770` StringTable_FindOrIntern_u16_Inferred | **accept-with-gaps** — global find-or-intern `u16`; `"Empty"` seed + table shell sealed; product table plate residual |

---

## VA `0x009841d0` — sealed facts

1. **Body:** `0x009841d0`–`0x00984335` exclusive (**357 B** / `0x165`; pad `CC`×11 then `FUN_00984340` @ `0x00984340`). Inclusive RET `0x00984334`.
2. **ABI:** **cdecl** stack **`out_string_vec*`**, **`const char* path`**; plain **`RET`** (`C3`); returns **`out_vec*` in EAX**.
3. **Semantics:**
   - Stack-construct `stoFileOSFile` (vtable `0x00a9d84c`); open path mode **1** / flags **0** via `FUN_007669d0` (success `0`, fail `-1`).
   - **Open fail:** `FUN_00469d10` assign empty collector → out; `FUN_00766750` dtor; `FUN_00431ae0` tidy; return out.
   - **Open ok:** default-ctor line `basic_string`; while `Tell() < Size()`: `FUN_00766ee0` readline → `StringVec_PushBack` (`FUN_004301f0`); assign collector → out; dtor line; close; tidy; return out.
4. **Classification:** worker (path-list file reader for `@` expand).
5. **Callers (1):** `Fs_ExpandPathSpecToStringVec_Inferred` (`FUN_00984340`) @ `0x00984395`.
6. **Callees:** `FUN_007669d0`, `FUN_00766ee0`, `FUN_007667f0` (Tell), `FUN_00766750`, `FUN_004301f0`, `FUN_00469d10`, `FUN_00431ae0`, `basic_string` ctor/dtor.
7. **Name:** `Fs_ReadPathListFileToStringVec_Inferred` (Ghidra `FUN_009841d0`; **Inferred**).
8. **Decompile ≡ bytes** for CF; entry/exit hex in raw W34-I append.

### Gaps

- Product/MSVC demangle English.  
- Nested stoFile open/readline plates (unowned).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_009841d0_Fs_ReadPathListFileToStringVec_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_009841d0_Fs_ReadPathListFileToStringVec_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_009841d0_FUN_009841d0.md` |
| Annotated | `docs/reconstruction/raw/aa_009841d0_FUN_009841d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Fs_ReadPathListFileToStringVec_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_009841d0.cpp` |
| Function | `docs/reconstruction/functions/aa_009841d0_FUN_009841d0.md` |
| Function named | `docs/reconstruction/functions/aa_009841d0_Fs_ReadPathListFileToStringVec_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_009841d0.md` |

---

## VA `0x004a1770` — sealed facts

1. **Body:** `0x004a1770`–`0x004a18a8` exclusive (**312 B** / `0x138`; pad `CC`×8 then `FUN_004a18b0` @ `0x004a18b0`). Inclusive RET `0x004a18a7`.
2. **ABI:** **cdecl** stack **`const char* name`**; plain **`RET`** (`C3`); returns **`unsigned`** (hit: `index & 0xffff`; miss: `size - 1`).
3. **Semantics:**
   - Global `StringVec` shell **`0x00b03608`** (begin `DAT_00b0360c`, end `DAT_00b03610`, stride **0x1c**).
   - Linear `basic_string::compare` scan; match → `u16` index.
   - Miss + empty (`begin==0` or size 0): push **`"Empty"`** (`0x00a41278`) then query via `StringVec_PushBack`; return `size-1`.
   - Miss + non-empty: push query only; return `size-1`.
4. **Classification:** worker (global string intern → compact index).
5. **Callers (1 func / 2 sites):** `FUN_004a18b0` @ `0x004a1bb1`, `0x004a1c4a` (`cloudName` / `skyName` → `uint16_t` fields).
6. **Callees:** `StringVec_PushBack` (`FUN_004301f0`), IAT `basic_string` ctor/compare/dtor.
7. **Name:** `StringTable_FindOrIntern_u16_Inferred` (Ghidra `FUN_004a1770`; **Inferred**). **Reject** scaffold `Named_CalleeOf_Named_VOG_DEBUG_STOP_004a1770`.
8. **Decompile ≡ bytes** for CF; entry/exit + literal hex in raw W34-I append.

### Gaps

- Product English for the global table / owning module.  
- `"Empty"` sentinel product meaning.  
- Table lifetime / other writers (unowned).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004a1770_StringTable_FindOrIntern_u16_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004a1770_StringTable_FindOrIntern_u16_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004a1770_FUN_004a1770.md` |
| Annotated | `docs/reconstruction/raw/aa_004a1770_FUN_004a1770.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StringTable_FindOrIntern_u16_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004a1770.cpp` |
| Function | `docs/reconstruction/functions/aa_004a1770_FUN_004a1770.md` |
| Function named | `docs/reconstruction/functions/aa_004a1770_StringTable_FindOrIntern_u16_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_004a1770.md` |

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-009841d0-004a1770-w34i-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `009841d0` | Port as **cdecl** free path-list reader: out string-vec + path. Preserve **fail→empty out**, line-oriented push (CRLF via nested readline), and assign-into-out. Not a directory walker — pair with `Fs_ExpandPathSpecToStringVec_Inferred` `@` arm. |
| `004a1770` | Port as **process-global find-or-intern** returning **`u16`**. Preserve `"Empty"` seed at first empty miss and stride-`0x1c` string elements. Consumers store compact name indices (e.g. env `cloudName`/`skyName`). |
| Pair with | W33-E `Fs_ExpandPathSpecToStringVec_Inferred` (`0x00984340`); W33-D `StringVec_PushBack` / `StringVec_Tidy`; nested stoFile cluster `FUN_007669d0` / `FUN_00766ee0`; env parse `FUN_004a18b0`. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: `decompile_function` / `batch_decompile` / `analyze_function_complete` + `read_memory` (+ callers/xrefs). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.
