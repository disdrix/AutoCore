# Dual A/B report — W37-S OWN `aa_00765740` + `aa_0076b080`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W37-S  
**Scope:** VAs `0x00765740`, `0x0076b080` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + `get_function_by_address` + callers/xrefs + callee/caller decompile. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave37_partition_map.md` (W37-S).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00765740` GfxBody_UnserializeGBOD_Inferred | **accept-with-gaps** — GBOD tag + v1/v2/v3 + stdcall RET 8 + plates + factory/copy sealed (2310 B); field English + nested helpers open |
| `aa_0076b080` Fs_UnlinkFile_ESI_ForceChmod_Inferred | **accept** — full 114 B hex, ESI path + force chmod + unlink bool + cdecl sealed; product English residual only |

---

## VA `0x00765740` — sealed facts

1. **Body:** `0x00765740`–`0x00766045` (**2310 B** / `0x906`; pad `CC` then next).
2. **ABI:** **stdcall** two stack formals `(body*, reader*)`; SEH `LAB_009b31c4`; epilogue `ADD ESP,0x5C; RET 8`; returns **uint** OR-status (bad tag/version **`0xFFFFFFFF`**).
3. **Semantics:**
   - `stoChunkReader_EnterChunkScope` → require tag **GBOD** `0x47424F44` (file **DOBG**); else plate `"Invalid TAG unserializeing gfxBody, probably exported wrong"` + `gfxBody.cpp` log → −1.
   - Version **1** dedicated arm; **2/3** shared arm (v3 prepends count/string skips); other versions plate `"Invalid chunk version (%i) unserializeing gfxBody"` → −1.
   - Reader mode `reader[0x1011]` (`+0x4044`) selects local vs alternate read helpers.
   - Status bitwise-OR of nested readers; MapA factory `FUN_00437b00` on vectors `+0xC0/+0xC4` and `+0xD0/+0xD4` (second sets `*obj+0xBC \|= 0x40`); v2/v3 may early-exit factory loops on status `<0`.
   - v2/v3 optional MapB `FUN_00437c90` → `body+0x94` + vcalls.
   - Copy **12 dwords** `body+4 → body+0x34`; leave chunk if scope active.
4. **Classification:** **worker** (gfxBody GBOD unserialize).
5. **Callers (1):** `FUN_0073eb40` @ `0x0073ebce` (SAMB peek alternate else this).
6. **Callees (high-signal):** EnterChunkScope, vog_LogMessage, leave `FUN_00769e40`, read helpers, `FUN_00437b00`, `FUN_00437c90`, `FUN_00767570`, `FUN_0074ce60`, `FUN_004372a0`, grow/section helpers, `basic_string`.
7. **Name:** `GfxBody_UnserializeGBOD_Inferred` (Ghidra `FUN_00765740`; **Inferred**). Reject scaffold-only plates as product method English.
8. **Family:** sole consumer of multi-site MapA factory from W36-A; optional MapB W36-C; product peer of GBOD/GPCE graphics sto.
9. **Decompile ≡ bytes** for tag/version/RET8/copy/status policy. Prologue/tag/epilogue hex sealed in raw W37-S append.

### Gaps

- Product field English for body offsets.  
- Nested unowned helper full contracts.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00765740_GfxBody_UnserializeGBOD_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00765740_GfxBody_UnserializeGBOD_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00765740_FUN_00765740.md` |
| Annotated | `docs/reconstruction/raw/aa_00765740_FUN_00765740.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GfxBody_UnserializeGBOD_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00765740.cpp` |
| Function | `docs/reconstruction/functions/aa_00765740_FUN_00765740.md` |
| Function named | `docs/reconstruction/functions/aa_00765740_GfxBody_UnserializeGBOD_Inferred.md` |

---

## VA `0x0076b080` — sealed facts

1. **Body:** `0x0076b080`–`0x0076b0f1` (**114 B** / `0x72`; pad `CC` then next).
2. **ABI:** **cdecl** stack `char force`; register **ESI = path**; `ADD ESP,0x28; RET`; returns **bool** (`_unlink==0`).
3. **Semantics:**
   - If force: `stat(ESI)`; if regular (`st_mode>>15`) and not writable (`~(mode>>7)&1`): `_chmod(ESI, 0x180)` (`_S_IREAD|_S_IWRITE`).
   - Always `_unlink(ESI)`; return success.
4. **Classification:** **worker** (filesystem single-file delete).
5. **Callers (3):** `FUN_0076ba10` @ `0x0076bb7d` (LEA ESI; PUSH force); `FUN_0076bc00` @ `0x0076bc5f` (PUSH 1); `FUN_007b75b0` @ `0x007b765d` (PUSH 1).
6. **Callees:** `stat`, `_chmod`, `_unlink`.
7. **Name:** `Fs_UnlinkFile_ESI_ForceChmod_Inferred` (Ghidra `FUN_0076b080`; **Inferred**). **Reject** `Named_CalleeOf_Named_assManager_*`.
8. **Family:** file arm of W34-A `Fs_DeleteDirTreeRecursive`; peers ensure-dir / asset precompile prep.
9. **Decompile ≡ bytes** for force/mode/chmod/unlink/bool. Full 114 B hex in raw W37-S append.

### Gaps

- Product English plate (no body string).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0076b080_Fs_UnlinkFile_ESI_ForceChmod_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0076b080_Fs_UnlinkFile_ESI_ForceChmod_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0076b080_FUN_0076b080.md` |
| Annotated | `docs/reconstruction/raw/aa_0076b080_FUN_0076b080.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Fs_UnlinkFile_ESI_ForceChmod_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0076b080.cpp` |
| Function | `docs/reconstruction/functions/aa_0076b080_FUN_0076b080.md` |
| Function named | `docs/reconstruction/functions/aa_0076b080_Fs_UnlinkFile_ESI_ForceChmod_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00765740` | Port as **GBOD root unserialize** for gfxBody: stdcall `(body*, reader*)`, versions 1/2/3, OR status, MapA factory vectors, optional MapB, copy 12 dwords `+4→+0x34`. Do **not** treat as GPCE piece serialize or ECX-thiscall. Pair with W36-A/C factory duals. Keep `_Inferred` until RTTI/method English seals. |
| `0076b080` | Port as **ESI-path force-unlink**: stack force bool; optional chmod 0x180 on non-writable regular files; always unlink. **Not** recursive rmdir; pair with W34-A tree delete. |

Shared: co-owned only by W37-S partition assignment — different subsystems (graphics sto vs filesystem). No shared ABI.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers + related caller decompile. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names; body/caller plates used where sealed.  
- Rejected scaffold `Named_CalleeOf_Named_assManager_*` and bare path-only plate as sole product method for gfxBody.  
- Terminal coverage false; runtime/diff not claimed.  
- Avoided bare `undefined4` as sole clean type surface (`uint32_t` / explicit pointers).
