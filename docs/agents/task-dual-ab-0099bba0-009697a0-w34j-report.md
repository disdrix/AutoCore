# Dual A/B report — W34-J OWN `aa_0099bba0` + `aa_009697a0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W34-J  
**Scope:** VAs `0x0099bba0`, `0x009697a0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + xrefs + callee decompiles for role + plate strings. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave34_partition_map.md`

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0099bba0` CNDAssetStringTable_Unserialize | **accept-with-gaps** — product plate + RET-12/AL=1 + string-table stage sealed; nested pyramid schema + host layout open |
| `aa_009697a0` StringVec_PushBackIfAbsent_EnsureTrailingDirSep | **accept-with-gaps** — EDI ABI + normalize + absent-only push_back sealed; Ghidra callers empty + product list English open |

---

## VA `0x0099bba0` — sealed facts

1. **Body:** `0x0099bba0`–`0x0099BED5` exclusive (**821 B** / `0x335`; pad `CC…`).
2. **ABI:** **three stack formals**; **`RET 0x0C`** (`C2 0C 00`); returns **1** in **AL** (`B0 01`). Stream reader held in **EBP**; sized read via **vtbl[+0x14]**.
3. **Semantics:** Product **`CNDAssetStringTable::Unserialize`** (plate @ `0x00a9b728`):
   - Log plate; zero local `vector<basic_string>`.
   - Read string count; log `string table size =%u`; per entry: default-ctor → `FUN_00766fb0` (C-string from stream) → `FUN_00989e00` (intern/lookup) → `StringVec_PushBack` (`FUN_004301f0`) → dtor.
   - Read pyramid count; log `pyramids =%u`; `FUN_00430540` resize (elem stride **0x10**); nested reshape (`FUN_00430600`) + lower_bound (`FUN_0044ff40`) + IAT `_stricmp` name resolve.
   - Destroy local string vector; return success.
4. **Classification:** worker.
5. **Callers:** `FUN_0099c1c0` @ `0x0099c23a` only.
6. **Callees:** `FUN_007a4480`, IAT string ctor/dtor, `FUN_00766fb0`, `FUN_00989e00`, `FUN_004301f0`, `FUN_00430540`, `FUN_00430600`, `FUN_0044ff40`, `_stricmp`, `operator_delete`.
7. **Name:** `CNDAssetStringTable_Unserialize` (Ghidra `FUN_0099bba0`; **product plate**). Pair serialize `0x0099b8e0`.
8. **Decompile ≡ bytes** for plate/ABI/string stage/epilogue; nested pyramid detail **Med** (unreachable-block noise). Ghidra false-noreturn on `operator_delete` ignored (epilogue present).  
   Full hex: raw W34-J append (821 B).

### Gaps

- Nested pyramid / row POD schema not dual-owned.  
- Full host `CNDAssetStringTable` layout open.  
- Nested helper product plates open.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0099bba0_CNDAssetStringTable_Unserialize.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0099bba0_CNDAssetStringTable_Unserialize.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0099bba0_FUN_0099bba0.md` |
| Annotated | `docs/reconstruction/raw/aa_0099bba0_FUN_0099bba0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDAssetStringTable_Unserialize.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0099bba0.cpp` |
| Function | `docs/reconstruction/functions/aa_0099bba0_FUN_0099bba0.md` |
| Function named | `docs/reconstruction/functions/aa_0099bba0_CNDAssetStringTable_Unserialize.md` |
| Scratch | `docs/reconstruction/tmp/a_0099bba0.md` |

---

## VA `0x009697a0` — sealed facts

1. **Body:** `0x009697a0`–`0x0096982D` exclusive (**141 B** / `0x8D`; pad `CC CC CC` then `FUN_00969830`).
2. **ABI:** **EDI=`StringVecShell*`**; stack path `basic_string*`; **`RET 4`** (`C2 04 00`); void. SEH `LAB_009acae3`.
3. **Semantics:**
   - Build local string via **`FUN_009694e0`** (copy + ensure trailing dir sep).
   - Linear scan `[EDI+4]..[EDI+8)` stride **0x1c** with IAT `operator==`.
   - If **absent** (iterator == end): **`FUN_004301f0` / `StringVec_PushBack`(EDI, local)**.
   - If present: skip push.
   - Destroy local string (IAT dtor).
4. **Classification:** worker.
5. **Callers:** Ghidra xrefs **empty** (peer erase `009696c0` also empty).
6. **Callees:** `FUN_009694e0`, IAT `operator==`, `FUN_004301f0`, IAT dtor.
7. **Name:** `StringVec_PushBackIfAbsent_EnsureTrailingDirSep` (Ghidra `FUN_009697a0`; **Inferred** structural). Sibling push_front `00969830` (W31-E); erase `009696c0`.
8. **Decompile ≡ bytes** for normalize → scan → conditional push_back.  
   Full hex: raw W34-J append (141 B).

### Gaps

- No sealed retail callers.  
- Product English for path-list role.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_009697a0_StringVec_PushBackIfAbsent_EnsureTrailingDirSep.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_009697a0_StringVec_PushBackIfAbsent_EnsureTrailingDirSep.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_009697a0_FUN_009697a0.md` |
| Annotated | `docs/reconstruction/raw/aa_009697a0_FUN_009697a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StringVec_PushBackIfAbsent_EnsureTrailingDirSep.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_009697a0.cpp` |
| Function | `docs/reconstruction/functions/aa_009697a0_FUN_009697a0.md` |
| Function named | `docs/reconstruction/functions/aa_009697a0_StringVec_PushBackIfAbsent_EnsureTrailingDirSep.md` |
| Scratch | `docs/reconstruction/tmp/a_009697a0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0099bba0` | Port as **`CNDAssetStringTable::Unserialize`**: stream-read string count + C-strings (intern), then pyramid count + nested rows with name→index resolve; always succeed (`true`/`1`) after cleanup. Pair with serialize `0x0099b8e0`. Do **not** trust Ghidra noreturn on delete. Nested pyramid POD needs follow-up dual of reshape/lower_bound helpers before bit-exact host writes. |
| `009697a0` | Port as **unique path-list push_back**: `EnsureTrailingDirSep(path)` then `if not contains → push_back`. Retail shell in **EDI** (not ESI). Complements push_front `00969830` and erase `009696c0`. Uses sealed `StringVec_PushBack` / trailing-sep helpers. |
| Pair with | Serialize twin `0x0099b8e0`; push_front `0x00969830` (W31-E); normalize `0x009694e0` (W32-A); push_back gate `0x004301f0` (W33-D); caller loader `FUN_0099c1c0`. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + xrefs (+ callee decompile for role; plate string `read_memory`). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Product plate used for Unserialize; structural `_Inferred` name for path-list helper.  
- Avoided bare `undefined4` in clean (`uint8_t` / explicit structs).
