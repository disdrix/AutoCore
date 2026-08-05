# Dual A/B report — W34-H OWN `aa_004642d0` + `aa_00431700`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W34-H  
**Scope:** VAs `0x004642d0`, `0x00431700` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + xrefs + nested callee decompile. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave34_partition_map.md` (W34-H).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004642d0` HeadBag_Ctor_Sentinel0x14_Inferred | **accept-with-gaps** — placement ABI/layout/0x14 sentinel/9-fill/twin CF sealed; 0 static callers + product owner open |
| `aa_00431700` BasicString_UninitializedFillN | **accept-with-gaps** — cdecl/0x1c fill/IAT copy-dtor/EH rethrow/callers sealed; product demangle + unused 4th/5th formals open |

---

## VA `0x004642d0` — sealed facts

1. **Body:** `0x004642d0`–`0x00464332` exclusive (**98 B** / `0x62`; pad `CC`).
2. **ABI:** stack **`self*`** placement ctor; **`RET 4`** (`C2 04 00`); returns **`self` in EAX**. Not ECX-thiscall.
3. **Semantics:**
   - `head = FUN_0043c460()` (`operator_new(0x14)` circular next/prev) → store @ **`+0x08`**; **`+0x0c = 0`**.
   - **`FUN_004646e0(this+0x10, 9, &head)`** — pointer vector reserve/fill **9** slots (W33-B).
   - **`+0x20 = 1`**, **`+0x24 = 1`**.
4. **Classification:** worker.
5. **Callers:** **none static** (0 code/data xrefs; no imm32 image match for entry).
6. **Callees:** `FUN_0043c460`, `FUN_004646e0`.
7. **Name:** `HeadBag_Ctor_Sentinel0x14_Inferred` (Ghidra `FUN_004642d0`; **Inferred**). Twin CF of AssResolver bags but **0x14** sentinel — do **not** invent Ass product plate.
8. **Twin:** same CF/length as `FUN_00423cf0` / `FUN_00469db0` with sentinel factory `FUN_0043c460` (0x14) vs `FUN_00423d60` (0x28).  
   Full hex: raw W34-H append (98 B).

### Gaps

- Product owner English (unreferenced bag).  
- Flag / unwritten prefix meaning.  
- Nested `FUN_0043c460` product plate (not owned).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004642d0_HeadBag_Ctor_Sentinel0x14_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004642d0_HeadBag_Ctor_Sentinel0x14_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004642d0_FUN_004642d0.md` |
| Annotated | `docs/reconstruction/raw/aa_004642d0_FUN_004642d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/HeadBag_Ctor_Sentinel0x14_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004642d0.cpp` |
| Function | `docs/reconstruction/functions/aa_004642d0_FUN_004642d0.md` |
| Function named | `docs/reconstruction/functions/aa_004642d0_HeadBag_Ctor_Sentinel0x14_Inferred.md` |

---

## VA `0x00431700` — sealed facts

1. **Body:** `0x00431700`–`0x0043178c` exclusive (**140 B** / `0x8C`; pad `CC`).
2. **ABI:** **cdecl** (bare **`C3`**). Callers push **5** dwords + `ADD ESP,0x14`; body uses **dest*, count, value*** only.
3. **Semantics:** MSVC-style **uninitialized fill-n** / construct-n for `basic_string`:
   - Loop `count` times: if dest≠null, IAT **copy-ctor**; advance dest by **`0x1c`**.
   - SEH: on throw, IAT **dtor** constructed prefix then **`_CxxThrowException(0,0)`**.
4. **Classification:** worker.
5. **Callers (2):** `FUN_004301f0` / `StringVec_PushBack` @ `0x00430249`; `FUN_00430390` / `StdUninitFillN_BasicString` @ `0x004303a7`.
6. **Callees:** IAT copy-ctor `[0x009c62ec]`→`0x006ead80`; IAT dtor `[0x009c62f4]`→`0x006eace6`; `_CxxThrowException` @ `0x006a3d60`.
7. **Name:** `BasicString_UninitializedFillN` (Ghidra `FUN_00431700`; **Inferred**). **Reject** scaffold `Named_CalleeOf_*VOG_DEBUG*`.
8. **Decompile ≡ happy-path CF**; **bytes win** on EH residual + bare RET.  
   Full hex: raw W34-H append (140 B).

### Gaps

- Product demangle (`_Uninit_fill_n` English).  
- Exact role of unused 4th/5th call-site formals.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00431700_BasicString_UninitializedFillN.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00431700_BasicString_UninitializedFillN.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00431700_FUN_00431700.md` |
| Annotated | `docs/reconstruction/raw/aa_00431700_FUN_00431700.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/BasicString_UninitializedFillN.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00431700.cpp` |
| Function | `docs/reconstruction/functions/aa_00431700_FUN_00431700.md` |
| Function named | `docs/reconstruction/functions/aa_00431700_BasicString_UninitializedFillN.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004642d0` | Port as **stack placement ctor** (RET 4): 0x14 circular sentinel @+0x08, ptr-vec **n=9** @+0x10 filled with sentinel*, flags 1/1 @+0x20/+0x24. **Do not** alias to AssResolver bags (those use **0x28** sentinel). Currently **no static callers**. |
| `00431700` | Port as **cdecl** uninit fill-n: construct `count` strings from `value` at `dest`, stride **0x1c**. Honor SEH partial-destroy. Call sites may pass 2 unused trailing args; preserve cdecl cleanup. **Do not** free the vector buffer. |
| Pair with | W33-B `PtrVecShell_InitFill_Inferred`; W32-D/E AssResolver bag twins (0x28); W33-D `StringVec_PushBack`; W33-G `StdUninitFillN_BasicString`; unowned `FUN_0043c460` / IAT string ops. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + xrefs + nested callee decompile. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; structural **Inferred** names only.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).  
- Rejected scaffold `Named_CalleeOf_*` product aliases.  
- Closes W33-B residual caller label `FUN_004642d0` and W33-D/G nested construct-n `FUN_00431700`.
