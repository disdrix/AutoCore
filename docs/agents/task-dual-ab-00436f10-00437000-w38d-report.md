# Dual A/B report — W38-D OWN `aa_00436f10` + `aa_00437000`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W38-D  
**Scope:** VAs `0x00436f10`, `0x00437000` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `force_decompile` + `read_memory` + `analyze_function_complete` + `get_function_by_address` + assembly context on call sites. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** wave38 (W38-D).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00436f10` stoChunkStreamWindow_ReadCString | **accept-with-gaps** — ESI/EDI/bare-RET, streamEnd loop, NUL consume, ensure, 0/−1 sealed; product English open |
| `aa_00437000` stoChunkReader_ReadU8 | **accept-with-gaps** — EAX/EDI/bare-RET, 1 B copy, ensure, window@+0x14 sealed; fail *out spill + U8/bool English open |

---

## VA `0x00436f10` — sealed facts

1. **Body:** `0x00436f10`–`0x00436f7b` (**108 B** / `0x6C`; pad `CC` @ `0x00436f7c`).
2. **ABI:** **ESI** = `StoStreamWindow*`, **EDI** = `std::string* out`, bare **`RET`**, return **0 / `0xffffffff`**. Decompiler `unaff_*` incomplete — **bytes + callers win**. **Not** thiscall.
3. **Semantics (binary C-string read):**
   - `string::resize(out, 0)` via IAT `[0x009c6308]`.
   - Require `cursor + base < streamEnd` (`window+0x14`).
   - Loop: if `available < cursor+1` → `FUN_00435df0(window, base+cursor)` thiscall; fail if hr < 0 or `available < 1`.
   - Load byte at `window+0x18+cursor`; **cursor++**.
   - If `NUL` → return **0** (terminator **consumed**, not appended).
   - Else `operator+=` via IAT `[0x009c6294]`; continue while `cursor+base < streamEnd`.
   - Exhaust streamEnd without NUL → **−1**.
4. **Classification:** worker — callees resize, Ensure, operator+=.
5. **Callers (50+ xrefs):** mode wrapper `FUN_00439a20` (`reader+0x4044 == 0` → this; else text `FUN_0076a200`); many binary unserialize paths with `lea esi, [reader+0x14]`.
6. **Name:** `stoChunkStreamWindow_ReadCString` (Ghidra `FUN_00436f10`). **Reject** scaffold `Named_CalleeOf_Named_assId_*`.
7. **Decompile ≡ force ≡ bytes** for CF; **bytes win** on ESI/EDI register ABI.  
   Full hex: `516a008bcfff1508639c008b46040346083b46147d4d8b46048d48013b4e0c7e178b560803d0528bcee8b2eeffff85c07c31837e0c017c2b8b46048a4c301883c00184c9880c24894604741c8b0424508bcfff1594629c008b4e04034e083b4e147cb383c8ff59c333c059c3`

### Gaps

- Product/PDB English (CString vs StringZ).  
- Ensure full contract (`FUN_00435df0` — not owned).  
- streamEnd when length unknown.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00436f10_stoChunkStreamWindow_ReadCString.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00436f10_stoChunkStreamWindow_ReadCString.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00436f10_FUN_00436f10.md` |
| Annotated | `docs/reconstruction/raw/aa_00436f10_FUN_00436f10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/stoChunkStreamWindow_ReadCString.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00436f10.cpp` |
| Function | `docs/reconstruction/functions/aa_00436f10_FUN_00436f10.md` |
| Function named | `docs/reconstruction/functions/aa_00436f10_stoChunkStreamWindow_ReadCString.md` |

---

## VA `0x00437000` — sealed facts

1. **Body:** `0x00437000`–`0x00437048` (**73 B** / `0x49`; pad `CC` @ `0x00437049`; next `stoChunkReader_ReadU32` @ `0x00437050`).
2. **ABI:** **EAX** = `stoChunkReader*`, **EDI** = `uint8_t* out`, bare **`RET`**, return **0 / `0xffffffff`**. Decompiler invents `__fastcall param_1` from ECX spill — **reject**; **bytes + callers win**.
3. **Semantics (binary u8 read):**
   - `mov esi, eax; add esi, 0x14` → window at **reader+0x14** (same remap as ReadU32).
   - If `available < cursor+1` → `FUN_00435df0(window, base+cursor)`; fail if hr < 0 or `available < 1`.
   - `*out = *(u8*)(window+0x18+cursor)`; cursor += 1; return 0.
   - **Fail path writes `*out`** from `[esp+7]` (high byte of entry-ECX push slot) then −1 — **non-product spill**; do not rely on `*out` after fail. Sibling ReadU32 leaves `*out` untouched on fail.
4. **Classification:** worker — sole callee Ensure.
5. **Callers (10 xrefs):** mode wrapper `FUN_00439a50` (binary → this; text → `FUN_00769660` bool-token); direct binary sites with `mov eax, reader` / `lea edi, out`.
6. **Name:** `stoChunkReader_ReadU8` (Ghidra `FUN_00437000`). **Reject** scaffold `Named_CalleeOf_Named_gfxBody_*`. Width sibling of sealed `stoChunkReader_ReadU32`.
7. **Decompile ≡ force** for math; **bytes win** on ESI remap + EDI out + bare RET.  
   Full hex: `51568bf08b461883c6148d48013b4e0c7e238b560803d0528bcee8d1edffff85c07c06837e0c017d0c8a4c240783c8ff880f5e59c38b46048a4c301883c00189460433c0880f5e59c3`

### Gaps

- Product English U8 vs bool (text peer logs "Expected bool").  
- Ensure full contract.  
- Caller dependence on fail-path `*out` (none expected).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00437000_stoChunkReader_ReadU8.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00437000_stoChunkReader_ReadU8.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00437000_FUN_00437000.md` |
| Annotated | `docs/reconstruction/raw/aa_00437000_FUN_00437000.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/stoChunkReader_ReadU8.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00437000.cpp` |
| Function | `docs/reconstruction/functions/aa_00437000_FUN_00437000.md` |
| Function named | `docs/reconstruction/functions/aa_00437000_stoChunkReader_ReadU8.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00436f10` | Port as **register ABI** binary string reader: **ESI=window**, **EDI=std::string***, bare RET, 0/−1. Clear dest first. Gate on **streamEnd** (`+0x14`), not only available. **Consume** NUL without appending. Callers usually pass `reader+0x14`. Do **not** invent thiscall or length-prefixed string. Text peer is unowned `FUN_0076a200`. |
| `00437000` | Port as **register ABI** binary u8 leaf: **EAX=reader**, **EDI=out***, bare RET, 0/−1. Remap window @ **+0x14** like ReadU32. Do **not** invent stack out or RET 4 (that is ReadU32 only). On fail, treat `*out` as **unspecified** (retail spill). Text peer is unowned `FUN_00769660` (bool token). |

Shared: both are **binary-mode** (`reader+0x4044 == 0`) stream leaves over the sealed Ensure window (`FUN_00435df0` / `stoChunkStreamWindow_Ensure`). Completes the thin typed-reader set beside sealed ReadU32 / ReadHeader16 / ReadBytes.

Window field map (both units):

| Reader off | Window off | Role |
|---:|---:|---|
| `+0x18` | `+0x04` | cursor |
| `+0x1c` | `+0x08` | base |
| `+0x20` | `+0x0c` | available |
| `+0x2c` | `+0x18` | buffer |
| (window only) | `+0x14` | streamEnd — used by ReadCString only |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + force_decompile + read_memory + function/xref/call-site helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; structural names from CF + sibling family.  
- Rejected scaffold `Named_CalleeOf_*` as product alias.  
- Avoided bare `undefined4` in clean named plates (`int32_t` / `uint8_t` / explicit structs).

---

## This report

`docs/agents/task-dual-ab-00436f10-00437000-w38d-report.md`
