# Dual A/B report — W38-C OWN `aa_00970910` + `aa_004363b0`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W38-C  
**Scope:** VAs `0x00970910`, `0x004363b0` only. Dual A/B + artifacts (trio + function + A/B).  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `batch_decompile` / `decompile_function` + `analyze_function_complete` + `get_function_by_address` + callers/xrefs + `read_memory` + `get_assembly_context` + parent context. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave38_partition_map.md` (W38-C).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00970910` AssPreloader_ExtBucketFromPath_Inferred | **accept-with-gaps** — 5-bucket path classifier (`.geo/.dds/.ogg/.xml`/OTHER default); RET 4; once-init table sealed; product English open |
| `aa_004363b0` BitVec_EnsureOneAndLocateRef_Inferred | **accept-with-gaps** — ensure-one + bit-ref locate; EAX host / EDI out / RET 0xC sealed; param3 + product type open |

---

## VA `0x00970910` — sealed facts

1. **Body:** `0x00970910`–`0x00970a24` exclusive (**276 B** / `0x114`); pad `CC`.
2. **ABI:** stack **`(const char** name_holder)`**; returns **`int` bucket**; **`RET 4`** (`C2 04 00`) on both exits. SEH `LAB_009ab8b5`. **Not** thiscall.
3. **Semantics:** Once-init (`DAT_00d1f87c` bit0) builds five MSVC `basic_string` (stride **0x1c**) at `DAT_00d1f7f0`:
   - 0 `.geo` (`0x00a28904`)
   - 1 `.dds` (`0x00a2c53c`)
   - 2 `.ogg` (`0x00a9d9a4`)
   - 3 `.xml` (`0x00a9eaf0`)
   - 4 `OTHER` (`0x00a9eaf8`) — constructed + atexit, **not** `strstr`-scanned  
   Classify: `strstr(hay, ext)` over indices **0..3**; hay = `*name_holder` or empty (`*[0x00afa2bc]` → `0x00a1419b` = `""`); no match → **return 4**.
4. **Classification:** worker (pure classifier leaf).
5. **Callers (4):** `FUN_00970bb0`, `FUN_00970c00`, `FUN_00971480` (`AssPreloader_DrainSuccessResultsAndTally_Inferred`, W37-B), `FUN_00971ea0` — all use EAX as index into preloader **`+0xe8`** (bytes) / **`+0xfc`** (counts).
6. **Callees:** `basic_string` ctor IAT `[0x009c62f8]`, `_atexit(LAB_009c3320)`, `strstr` IAT `[0x009c6688]`.
7. **Name:** `AssPreloader_ExtBucketFromPath_Inferred` (Ghidra `FUN_00970910`; **Inferred**). **Reject** `Named_xml` and long `Named_CalleeOf_Named_assPreloader_*`.
8. **Decompile ≡ bytes** for CF/table/RET. Full hex in raw W38-C append.

### Gaps

- Product/MSVC demangle English.  
- Intentional mid-path `strstr` matches vs suffix-only.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00970910_AssPreloader_ExtBucketFromPath_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00970910_AssPreloader_ExtBucketFromPath_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00970910_FUN_00970910.md` |
| Annotated | `docs/reconstruction/raw/aa_00970910_FUN_00970910.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssPreloader_ExtBucketFromPath_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00970910.cpp` |
| Function | `docs/reconstruction/functions/aa_00970910_FUN_00970910.md` |
| Function named | `docs/reconstruction/functions/aa_00970910_AssPreloader_ExtBucketFromPath_Inferred.md` |

---

## VA `0x004363b0` — sealed facts

1. **Body:** `0x004363b0`–`0x0043640f` exclusive (**95 B** / `0x5F`); next sibling `FUN_00436410` @ `0x00436410`.
2. **ABI:** **EAX** = bitvec host*; **EDI** = out `BitRef{bit, word*}`*; stack **`(bitAdd, dwordPos*, param3)`**; returns **out*** in EAX; **`RET 0x0C`** (`C2 0C 00`). Custom register+stack — **not** plain ECX-thiscall.
3. **Semantics:**
   - Snapshot `old_begin = *(host+8)`.
   - `FUN_004364b0` thiscall with **EAX count = 1** (ensure/insert one bit); stack formals forwarded.
   - Re-read `begin' = *(host+8)`.
   - `bitIndex = ((dwordPos - old_begin) >> 2) * 32 + bitAdd`.
   - `*out = { bitIndex & 31, begin' + (bitIndex >> 5)*4 }`; return `out`.
4. **Classification:** worker (bit-storage ensure+locate leaf).
5. **Callers (1):** `FUN_00765740` @ `0x00765c31` — gfxBody.cpp plate unserialize path builds bit cursor from stream count then calls.
6. **Callees:** `FUN_004364b0` (not OWN).
7. **Name:** `BitVec_EnsureOneAndLocateRef_Inferred` (Ghidra `FUN_004363b0`; **Inferred**). **Reject** scaffold `Named_CalleeOf_Named_gfxBody_*`.
8. **Decompile CF OK**; bytes seal register ABI, count=1, RET 0xC, return out*. Full hex in raw W38-C append.

### Gaps

- Product type name (`vector<bool>`-like vs custom).  
- Meaning of `param3` (forwarded only into ensure).  
- Nested dual of `FUN_004364b0` / fill helpers.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004363b0_BitVec_EnsureOneAndLocateRef_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004363b0_BitVec_EnsureOneAndLocateRef_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004363b0_FUN_004363b0.md` |
| Annotated | `docs/reconstruction/raw/aa_004363b0_FUN_004363b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/BitVec_EnsureOneAndLocateRef_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004363b0.cpp` |
| Function | `docs/reconstruction/functions/aa_004363b0_FUN_004363b0.md` |
| Function named | `docs/reconstruction/functions/aa_004363b0_BitVec_EnsureOneAndLocateRef_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00970910` | Port as pure **path → bucket enum** `{Geo=0,Dds=1,Ogg=2,Xml=3,Other=4}` using CRT `strstr` on four extensions; default Other. Preserve pointer-to-cstr formal and stdcall-ish `ret 4`. Wire AssPreloader tallies as `host[0xe8/4 + b]` / `host[0xfc/4 + b]`. Do **not** search the literal `"OTHER"`. |
| `004363b0` | Port as **ensure-one + bit-ref** on dword-packed bits at `host+8`. Preserve custom **EAX/EDI** ABI or wrap only at `FUN_00765740`. Always compute bit index from **pre-ensure** positions, apply to **post-ensure** begin. Do not model as void thiscall. |
| Shared | Unrelated domains (AssPreloader path buckets vs bit-vector storage). Co-owned only by W38-C partition pair. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x00971480` | AssPreloader drain/tally consumer of bucket classifier (W37-B) |
| `0x00970bb0` / `0x00970c00` / `0x00971ea0` | Sibling tally/untally callers |
| `0x004364b0` | Bitvec ensure/insert engine (count in EAX) |
| `0x00436410` | Sibling multi-arg ensure/locate |
| `0x00765740` | gfxBody unserialize sole caller of bit-ref helper |
| `0x00d1f7f0` | Static extension string table (5× basic_string) |

Closes W38-C OWN pair: AssPreloader extension-bucket classifier + bit-vector ensure-one/locate-ref.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers + assembly context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names; `_Inferred` structural names only.  
- Rejected Named_xml / Named_CalleeOf_gfxBody scaffold aliases.  
- Clean avoids bare `undefined4` (`uint32_t` / explicit structs).
