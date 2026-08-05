# Dual A/B report — W33-P OWN `aa_00985390` + `aa_0076b190`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W33-P  
**Scope:** VAs `0x00985390`, `0x0076b190` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave33_partition_map.md` (W33-P).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00985390` AssPack_ReleaseBlock_CoalesceFreeRanges_Inferred | **accept-with-gaps** — ECX/EAX/AL + map-erase + free-range coalesce/insert sealed; product English + nested map/vector plates open |
| `aa_0076b190` Fs_Path_EnsureExtension_Inferred | **accept-with-gaps** — stack path/out + ESI default ext + ensure-not-replace + `"glm"` sites sealed; nested split/make plates open |

---

## VA `0x00985390` — sealed facts

1. **Body:** `0x00985390`–`0x0098545e` exclusive (**206 B** / `0xCE`; pad `CC CC` then next @ `0x00985460`).
2. **ABI:** **ECX=`host*`**, **EAX=`block*`**; bare **`C3`**; returns **AL** (`1` = map emptied after erase; `0` = free ranges updated). Not single-formal thiscall.
3. **Semantics:**
   - Map lower_bound + erase on **`host+0x04`** (`FUN_00445750`, `FUN_004477a0`).
   - If **`host+0x0c == 0`** → return **1**.
   - Else **`offset=block+0x18`**, **`size=block+0x1c`**; free-range vector **`[host+0x14, host+0x18)`** (stride **8**).
   - Lower-bound (`FUN_00460a60`); **coalesce next** if adjacent; else **coalesce prev**; else **insert** (`FUN_00445c80`); return **0**.
4. **Classification:** worker.
5. **Callers (1):** `FUN_00985a30` @ `0x00985a85` (`mov eax,ebx; mov ecx,edi; call`; `test al,al`).
6. **Callees:** `FUN_00445750`, `FUN_004477a0`, `FUN_00460a60`, `FUN_00445c80`.
7. **Name:** `AssPack_ReleaseBlock_CoalesceFreeRanges_Inferred` (Ghidra `FUN_00985390`; **Inferred**). **Reject** scaffold `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxIndexBuff_00985390`.
8. **Neighborhood:** immediately after CompactPackFile `FUN_00985010` (ends `0x0098538d` + pad).  
   Full hex: raw W33-P append (206 B).

### Gaps

- Product/PDB English for host + block types.  
- Nested map/vector helper plates (not owned).  
- Full caller `FUN_00985a30` product plate.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00985390_AssPack_ReleaseBlock_CoalesceFreeRanges_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00985390_AssPack_ReleaseBlock_CoalesceFreeRanges_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00985390_FUN_00985390.md` |
| Annotated | `docs/reconstruction/raw/aa_00985390_FUN_00985390.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssPack_ReleaseBlock_CoalesceFreeRanges_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00985390.cpp` |
| Function | `docs/reconstruction/functions/aa_00985390_FUN_00985390.md` |
| Function named | `docs/reconstruction/functions/aa_00985390_AssPack_ReleaseBlock_CoalesceFreeRanges_Inferred.md` |

---

## VA `0x0076b190` — sealed facts

1. **Body:** `0x0076b190`–`0x0076b208` exclusive (**120 B** / `0x78`; pad `CC` then next).
2. **ABI:** stack **`const char* path`**, **`char* out`**; **ESI=`const char* defaultExt`** (no leading `.`); cdecl (caller cleans); bare **`C3`**; void.
3. **Semantics:**
   - Split via **`FUN_0076af70`** into drive + dir/fname/ext (3×256 stack locals).
   - If **ext empty**, strcpy from **ESI** into ext.
   - Recompose via **`FUN_0076aba0`** into **out**.
   - **Does not** replace a non-empty extension (ensure, not force).
4. **Classification:** worker (fs path helper).
5. **Callers (2):** `FUN_00985010` (CompactPackFile) @ `0x0098503d`; `FUN_0071a9d0` @ `0x0071a9ee`. Both load ESI=`"glm"` @ `0x00aa61bc`.
6. **Callees:** `FUN_0076af70`, `FUN_0076aba0`.
7. **Name:** `Fs_Path_EnsureExtension_Inferred` (Ghidra `FUN_0076b190`; **Inferred**). Reject scaffold call-graph alias as product name.
8. **Decompile ≡ bytes** for ensure branch; ESI formal sealed by call sites.  
   Full hex: raw W33-P append (120 B).

### Gaps

- Nested split/make product CRT twin plates.  
- Truncation / max-length inside nested helpers.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0076b190_Fs_Path_EnsureExtension_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0076b190_Fs_Path_EnsureExtension_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0076b190_FUN_0076b190.md` |
| Annotated | `docs/reconstruction/raw/aa_0076b190_FUN_0076b190.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Fs_Path_EnsureExtension_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0076b190.cpp` |
| Function | `docs/reconstruction/functions/aa_0076b190_FUN_0076b190.md` |
| Function named | `docs/reconstruction/functions/aa_0076b190_Fs_Path_EnsureExtension_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00985390` | Port as **pack free-map release**: ECX host, EAX block; erase map @+0x04; if count@+0x0c==0 return 1; else coalesce/insert free pair (offset@block+0x18, size@+0x1c) into vec [+0x14,+0x18). AL-only. **Not** gfx index buffer. |
| `0076b190` | Port as **ensure-extension** path rewrite: stack path+out; default ext in ESI (Compact uses `"glm"`). Do **not** clobber existing extensions. Void cdecl. |
| Pair with | W32-E `AssPackManager_CompactPackFile_Inferred` (calls path helper); W31-H open-pack; free-map owner around `FUN_00985a30`; nested split/make / map-vector residuals. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; structural `_Inferred` names only.  
- Rejected gfxIndexBuff scaffold alias for `00985390`.  
- Avoided bare `undefined4` in clean (`uint8_t` / `uint32_t` / explicit structs).
