# Dual A/B report — W33-Q OWN `aa_00984d30` + `aa_00984910`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W33-Q  
**Scope:** VAs `0x00984d30`, `0x00984910` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave33_partition_map.md` (W33-Q).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00984d30` AssPackManager_ExtractPackEntryToFile_Inferred | **accept-with-gaps** — ABI/CF/path fallback/write mode6/sole caller sealed; stream product + stack2 spill open |
| `aa_00984910` AssPackManager_AddOrReplaceFileInPack_Inferred | **accept-with-gaps** — ABI/CF/skip-replace-add/dual callers sealed; compress/insert nested + arg4 open |

---

## VA `0x00984d30` — sealed facts

1. **Body:** `0x00984d30`–`0x00984ed4` (**421 B** / `0x1A5`; pad `CC` then `FUN_00984ee0` @ `0x00984ee0`).
2. **ABI:** **ECX=`outPath`** (nullable); stack **host**, **entryName**, **spill**; **`RET 0x0C`**; returns **0** / **`0xFFFFFFFF`**. **Not** ECX-thiscall on host.
3. **Semantics:**
   - Optional CS: gate **`host+0x50`**, section **`host+0x38`**.
   - `FUN_009835f0` lookup (EAX=host, ECX=name) → miss log `assPackManager.cpp:0x20f` `"<%s> couldnt be found!"` level 3 → **−1**.
   - Hit: `FUN_00983d40` stream; `new[](size+1)` size@**entry+0x08**; vtbl+0x14 read.
   - Path: ECX else **entry+0x10** else empty (`PTR_DAT_00afa2bc` → `DAT_00a1419b`).
   - `FUN_007669d0(path, 6, 0)` open-write; `WriteFile`; free; stream dtor; return **0**.
4. **Classification:** worker.
5. **Callers (1):** `FUN_00985010` @ `0x00985169` (compact extract stage).
6. **Callees:** `FUN_009835f0`, `FUN_00983d40`, `operator_new[]`/`delete[]`, `FUN_0076bd90`, `FUN_007669d0`, `WriteFile`, `CloseHandle`, `FUN_00766750`, `FUN_0076cec0`, `vog_LogMessage`, CS APIs.
7. **Name:** `AssPackManager_ExtractPackEntryToFile_Inferred` (Ghidra `FUN_00984d30`; **Inferred**). **Reject** scaffold `Named_assPackManager_00984d30`.
8. **Decompile ≡ bytes** for CF; **bytes win** on ECX=outPath vs compact decompiler formal order.  
   Full hex: raw W33-Q append (421 B).

### Gaps

- Nested stream/`FUN_009835f0` product English (not OWN).  
- stack[2] product role (sole caller always empty).  
- Open-handle identity behind decompiler `HANDLE -1` placeholders.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00984d30_AssPackManager_ExtractPackEntryToFile_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00984d30_AssPackManager_ExtractPackEntryToFile_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00984d30_FUN_00984d30.md` |
| Annotated | `docs/reconstruction/raw/aa_00984d30_FUN_00984d30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssPackManager_ExtractPackEntryToFile_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00984d30.cpp` |
| Function | `docs/reconstruction/functions/aa_00984d30_FUN_00984d30.md` |
| Function named | `docs/reconstruction/functions/aa_00984d30_AssPackManager_ExtractPackEntryToFile_Inferred.md` |

---

## VA `0x00984910` — sealed facts

1. **Body:** `0x00984910`–`0x00984c65` (**854 B** / `0x356`; pad `CC` then `FUN_00984c70` @ `0x00984c70`).
2. **ABI:** **ECX=`srcPath`**; stack **host**, **typeId**, **forceReplace**, **arg4**, **replaceCookie**; **`RET 0x14`**; returns **1** skip / **≥0** add / **−1** fail. **Not** ECX-thiscall on host.
3. **Semantics:**
   - Optional CS: gate **`host+0x50`**, section **`host+0x38`**.
   - Lookup existing; if present and **force==0** and mtime@**+0x0c** / size@**+0x08** / type i16@**+0x14** match → log `:0x128` `"Not replacing %s."` → return **1**.
   - Else if present: **`FUN_009847c0(replaceCookie)`**.
   - Open-read **`FUN_007669d0(path, 1, 0)`**; fail → `:0x163` `"Error: Unable to open file <%s>"` → **−1**.
   - Else read full file; compress path (`FUN_0071aaf0` / `FUN_0071ad70` / `FUN_007199e0`); meta + **`FUN_00469910`** insert; log `:0x166` `"Added file %s"`.
4. **Classification:** worker.
5. **Callers (2):** `FUN_00984c70` @ `0x00984ce5` (dir bulk add, force=1); `FUN_00985010` @ `0x00985198` (compact add into packB).
6. **Callees:** `FUN_00719630`, `FUN_009835f0`, `stat`, `FUN_0076ad40`, `FUN_009847c0`, open/read/compress/insert family, `FUN_00766750`, log APIs, CS APIs.
7. **Name:** `AssPackManager_AddOrReplaceFileInPack_Inferred` (Ghidra `FUN_00984910`; **Inferred**). **Reject** scaffold `Named_assPackManager_00984910`.
8. **Decompile ≡ bytes** for CF; **bytes win** on ECX=path.  
   Full hex: raw W33-Q append (854 B).

### Gaps

- Nested compress/insert product plates (not OWN).  
- Exact MSVC `stat` field for mtime mask vs `entry+0x0c`.  
- arg4 product meaning.  
- `FUN_009847c0` replace contract.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00984910_AssPackManager_AddOrReplaceFileInPack_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00984910_AssPackManager_AddOrReplaceFileInPack_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00984910_FUN_00984910.md` |
| Annotated | `docs/reconstruction/raw/aa_00984910_FUN_00984910.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssPackManager_AddOrReplaceFileInPack_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00984910.cpp` |
| Function | `docs/reconstruction/functions/aa_00984910_FUN_00984910.md` |
| Function named | `docs/reconstruction/functions/aa_00984910_AssPackManager_AddOrReplaceFileInPack_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00984d30` | Port as **extract entry → file**: ECX outPath (nullable), host+name on stack, RET 0x0C. Preserve CS gate, path fallback, write mode **6**. Sole use is compact’s per-entry extract to `_pk_/name`. |
| `00984910` | Port as **add/replace file into pack**: ECX srcPath, five stack formals, RET 0x14. Preserve skip-if-same when `forceReplace==0`, replace-prep, open mode **1**, compress+insert. Used by compact and dir bulk-add. |
| Pair with | W32-E `AssPackManager_CompactPackFile_Inferred`; W31-H `AssPackManager_OpenPackFile_Inferred`; W32-D `Fs_DirRecurseCollectLeafPaths_Inferred`; W33-E `FUN_00984c70` (unowned here). |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; structural `_Inferred` names only.  
- Rejected scaffold `Named_assPackManager_*` as product aliases.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).  
- Compact-caller decompiler formal order treated as **non-authority** where call-site bytes disagree.
