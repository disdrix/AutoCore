# Dual A/B report — W38-J OWN `aa_00769660` + `aa_0076a200`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W38-J  
**Scope:** VAs `0x00769660`, `0x0076a200` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + `get_function_by_address` + xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave38_partition_map.md` (W38-J).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00769660` stoChunkReader_TextReadBool | **accept** — EDI reader + stack 1-byte out + `ret 4`; token/pushback family; `ConvertToInteger(out,1,0)`; Expected-bool log; 624 B sealed |
| `aa_0076a200` stoChunkReader_TextReadString | **accept** — ECX out string + EBX reader + plain `ret`; ReadQuotedTag wrapper; Expected-string log; 181 B sealed |

---

## VA `0x00769660` — sealed facts

1. **Body:** `0x00769660`–`0x007698d0` (**624 B** / `0x270`). SEH `LAB_009aff9c`. Success mid-body `C2 04 00`; fail tail `OR EAX,-1` + `C2 04 00` @ `0x007698ce`.
2. **ABI:** **EDI** = `stoChunkReader*`; stack **`(uint8_t* out)`**; returns **0** / **−1**; **`ret 4`**.
3. **Semantics:** Text-mode **bool** reader (family twin of `stoChunkReader_TextReadU32` @ `0x007689e0`):
   - Sticky gate `+0x402c < 0` → type-error path.
   - Pushback: if `+0x4060 != 0`, token = `+0x404c` then clear; else scan window (`+0x18/+0x1c/+0x20/+0x2c`) with ensure `FUN_00435df0`, `isspace`, optional `'`/`"` (quotes kept).
   - Token `"}"` → log `stoChunk.cpp:0x2a0` past-end, sticky −1, re-stash pushback.
   - Else `FUN_00767600` / `stoChunk_ConvertToInteger` with **byteLen=1**, **signedMode=0** (token in EAX); `hr >= 0` → return **0**.
   - Fail → format `"Expected bool but got \"%s\" in chunk \"%s\""` (`0x00a9d414`), log line **0x3dd**, return **−1**.
4. **Mode peer:** binary `FUN_00437000` via dispatcher `FUN_00439a50` on `reader+0x4044`.
5. **Classification:** worker (text typed reader leaf).
6. **Callers (8):** `FUN_00439a50` (dispatcher), `FUN_0072c860`, `FUN_00739c80`, `FUN_0074ce60`, `FUN_0075a980` (×2), `FUN_00765740`, `FUN_00963fb0`, `FUN_00964690`.
7. **Callees:** `FUN_00435df0`, `FUN_00767600`, `FUN_00436250`, `FUN_0076cec0`, `vog_LogMessage`, `isspace`, `std::string` ops.
8. **Name:** `stoChunkReader_TextReadBool` (Ghidra `FUN_00769660`; **Inferred** from Expected-bool string + integer-text family). **Reject** scaffold-only `Named_stoChunk_00769660` as primary.
9. **Decompile ≡ bytes** for CF; decompiler prototype void/undefined — **bytes win** for ABI/return.

### Gaps

- Product/PDB symbol spelling.  
- Whether non-{0,1} decimal bytes are accepted (owned by ConvertToInteger).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00769660_stoChunkReader_TextReadBool.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00769660_stoChunkReader_TextReadBool.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00769660_FUN_00769660.md` |
| Annotated | `docs/reconstruction/raw/aa_00769660_FUN_00769660.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/stoChunkReader_TextReadBool.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00769660.cpp` |
| Function | `docs/reconstruction/functions/aa_00769660_FUN_00769660.md` |
| Function named | `docs/reconstruction/functions/aa_00769660_stoChunkReader_TextReadBool.md` |

---

## VA `0x0076a200` — sealed facts

1. **Body:** `0x0076a200`–`0x0076a2b5` (**181 B** / `0xB5`); pad `CC` then OpenChunk `FUN_0076a2c0` @ `0x0076a2c0`. SEH `LAB_009b0b25`.
2. **ABI (leaf):** **ECX** = `std::string* out`; **EBX** = `stoChunkReader*`; plain **`ret`** (`C3`); returns **0** / **−1**. No stack args cleaned by this leaf.
3. **Semantics:** Thin **text string** reader:
   - `mov edi,ecx; push ebx; call FUN_00769b70` (`stoChunkReader_ReadQuotedTag`, W25-S).
   - ReadQuotedTag ≥ 0 → return **0** (out holds stripped double-quoted content).
   - Else SSO c_str on out + chunk name (`FUN_00436250`) → format `"Expected string but got \"%s\" in chunk \"%s\""` (`0x00a9d22c`) → log `stoChunk.cpp:0x44a` → return **−1**.
4. **Mode peer:** binary `FUN_00436f10` via dispatcher `FUN_00439a20` (dispatcher: stack reader + `ret 4`; leaf remains ECX/EBX/`C3`).
5. **Classification:** worker (wrapper over sealed tag reader).
6. **Callers:** 25+ functions / 53 CODE xrefs — `FUN_00439a20`, `effEffect_Unserialize`, `phyBoneSharedData_unserialize`, `FUN_00458a30`/`004590a0`/`00459750` family, many gfx/anim/string field readers.
7. **Callees:** `FUN_00769b70`, `FUN_00436250`, `FUN_0076cec0`, `vog_LogMessage`, `std::string` dtor.
8. **Name:** `stoChunkReader_TextReadString` (Ghidra `FUN_0076a200`; **Inferred**). **Reject** scaffold `Named_stoChunk_0076a200` as primary.
9. **Decompile pitfall:** `unaff_EBX` / incomplete `__fastcall` — **bytes + call sites seal** EBX reader.

### Gaps

- Product/PDB symbol spelling.  
- Binary peer `FUN_00436f10` product English (not owned).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0076a200_stoChunkReader_TextReadString.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0076a200_stoChunkReader_TextReadString.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0076a200_FUN_0076a200.md` |
| Annotated | `docs/reconstruction/raw/aa_0076a200_FUN_0076a200.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/stoChunkReader_TextReadString.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0076a200.cpp` |
| Function | `docs/reconstruction/functions/aa_0076a200_FUN_0076a200.md` |
| Function named | `docs/reconstruction/functions/aa_0076a200_stoChunkReader_TextReadString.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00769660` | Port as **text bool read**: same tokenizer as TextReadU32; parse via existing ConvertToInteger with **1-byte** width; return status 0/−1 (not C# `bool` as HRESULT). Do **not** invent `true`/`false` keyword parsing. Preserve pushback / past-end `}` sticky behavior. |
| `0076a200` | Port as **text quoted string read**: delegate to ReadQuotedTag (strict `"` strip); on failure log Expected-string. Map retail **ECX out / EBX reader** when matching dual-mode dispatcher call sites. |
| Shared | Both are **text-mode stoChunk typed readers** under `stoChunk.cpp`; co-owned only by W38-J partition pair. Different ABIs (EDI+stack+ret4 vs ECX+EBX+C3). |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x00767600` | `stoChunk_ConvertToInteger` (W25-R) — bool parse engine |
| `0x007689e0` | `stoChunkReader_TextReadU32` — family twin (byteLen 4) |
| `0x00769b70` | `stoChunkReader_ReadQuotedTag` (W25-S) — string success path |
| `0x00439a50` | Bool mode dispatcher (binary `00437000` / text this) |
| `0x00439a20` | String mode dispatcher (binary `00436f10` / text this) |
| `0x00435df0` | Window ensure |
| `0x00436250` | Current chunk name helper |
| `0x0076cec0` | Format helper |

Closes W38-J OWN pair: text **bool** reader (ConvertToInteger×1) + text **quoted string** reader (ReadQuotedTag wrapper).

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers + assembly context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only (W38-J live seal).  
- No invented product names; `_Inferred` structural names only.  
- Rejected long Named_stoChunk scaffold aliases as primary.  
- Clean avoids bare `undefined4` (`uint8_t` / `std::string` / explicit reader offsets).
