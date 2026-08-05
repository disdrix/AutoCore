# Dual A/B report — W33-G OWN `aa_0046a2c0` + `aa_00430390`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W33-G  
**Scope:** VAs `0x0046a2c0`, `0x00430390` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` / `batch_decompile` + `analyze_function_complete` + `read_memory` + xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave33_partition_map.md` (W33-G).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0046a2c0` StdUninitCopy_BasicString | **accept-with-gaps** — uninit-copy ABI/CF/0x1c/SEH/catch sealed; product demangle open |
| `aa_00430390` StdUninitFillN_BasicString | **accept-with-gaps** — fill-n wrapper ABI/RET 0x0C/`*0x1c` sealed; nested `FUN_00431700` product open |

---

## VA `0x0046a2c0` — sealed facts

1. **Body:** `0x0046a2c0`–`0x0046a34c` exclusive (**140 B** / `0x8C`; pad `CC` then next).
2. **ABI:** **cdecl** stack **first\***, **last\***, **dest\***; bare **`RET`** (`C3`); returns **dest-end in EAX**. Not ECX-thiscall. Wrappers may push extra unused allocator args.
3. **Semantics:** MSVC-style **`_Uninit_copy`** for `basic_string` elem **0x1C**:
   - SEH `LAB_009bcce1`; per-element state 0/1.
   - Loop: if dest≠null, IAT copy-ctor `CALL [0x009C62EC]` → `0x006EAD80`; advance first/dest by **0x1C**.
   - Success: `first==last` **JZ** → epilogue @ `0x0046A339` (skips catch).
   - Catch residual @ `0x0046A318`: destroy partial dest via IAT dtor `[0x009C62F4]`→`0x006EAD30`; **`_CxxThrowException(0,0)`** @ `0x006A3D60`.
4. **Classification:** worker (STL helper).
5. **Callers:** `FUN_004306b0` @ `0x004307e6`, `0x0043080f` (insert-n grow relocate); `FUN_00431430` @ `0x00431445`; `FUN_00469d10` @ `0x00469d76` (range assign).
6. **Callees:** string copy-ctor IAT; catch: dtor IAT + `_CxxThrowException`.
7. **Name:** `StdUninitCopy_BasicString` (Ghidra `FUN_0046a2c0`; **Inferred** structural). **Reject** scaffold `Named_CalleeOf_Named_*`.
8. **Decompile ≡ happy-path**; catch sealed by **bytes** only.  
   Full hex: raw W33-G append (140 B).

### Gaps

- Product/MSVC demangle for exact `_Uninit_copy` specialization.  
- Allocator trailing-arg product English on wrappers.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0046a2c0_StdUninitCopy_BasicString.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0046a2c0_StdUninitCopy_BasicString.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0046a2c0_FUN_0046a2c0.md` |
| Annotated | `docs/reconstruction/raw/aa_0046a2c0_FUN_0046a2c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdUninitCopy_BasicString.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0046a2c0.cpp` |
| Function | `docs/reconstruction/functions/aa_0046a2c0_FUN_0046a2c0.md` |
| Function named | `docs/reconstruction/functions/aa_0046a2c0_StdUninitCopy_BasicString.md` |
| Scratch | `docs/reconstruction/tmp/a_0046a2c0.md` |

---

## VA `0x00430390` — sealed facts

1. **Body:** `0x00430390`–`0x004303c0` exclusive (**48 B** / `0x30`).
2. **ABI:** **ECX=`alloc`/host**; stack **dest\***, **count**, **value\***; **`RET 0x0C`** (`C2 0C 00`); returns **dest + count×0x1C** in EAX.
3. **Semantics:** Thin **`_Uninit_fill_n`** wrapper for `basic_string` stride **0x1C**:
   - `FUN_00431700(dest, count, value, alloc, value)` — nested SEH fill loop (copy-ctor from value, ×count).
   - `ADD ESP, 0x14`; lea math `count*28` → end pointer.
4. **Classification:** worker (STL helper wrapper).
5. **Callers:** **only** `FUN_004306b0` (`StdVector_InsertN_BasicString`) @ `0x004307f9`, `0x00430910`.
6. **Callees:** `FUN_00431700`.
7. **Name:** `StdUninitFillN_BasicString` (Ghidra `FUN_00430390`; **Inferred** structural). **Reject** scaffold `Named_CalleeOf_Named_*`.
8. **Decompile ≡ bytes** for wrapper CF; call target `0x00431700` sealed.  
   Full hex: raw W33-G append (48 B).

### Gaps

- Nested `FUN_00431700` product plate / demangle (not owned).  
- Allocator ECX formal English.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00430390_StdUninitFillN_BasicString.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00430390_StdUninitFillN_BasicString.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00430390_FUN_00430390.md` |
| Annotated | `docs/reconstruction/raw/aa_00430390_FUN_00430390.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdUninitFillN_BasicString.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00430390.cpp` |
| Function | `docs/reconstruction/functions/aa_00430390_FUN_00430390.md` |
| Function named | `docs/reconstruction/functions/aa_00430390_StdUninitFillN_BasicString.md` |
| Scratch | `docs/reconstruction/tmp/a_00430390.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0046a2c0` | Port as **`uninit_copy` for `vector<string>`** (elem **0x1c**): cdecl `(first,last,dest)→dest_end`. Exception-safe: destroy partial dest on throw. Used by insert-n grow relocate and range assign. Do **not** treat as POD memcpy. |
| `00430390` | Port as **`uninit_fill_n` wrapper**: thiscall alloc + `(dest,count,value)` → `dest+count`; **`RET 0x0C`**. Loop may live in nested helper. Sole retail caller is insert-n fill after grow/shift. |
| Pair with | W32-B `StdVector_InsertN_BasicString` (`0x004306b0`); wrappers `FUN_00431430` / insert-one `FUN_00430310`; nested fill body `FUN_00431700`; range assign `FUN_00469d10` (unowned). |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; structural names only.  
- Rejected scaffold `Named_CalleeOf_Named_*` aliases.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).  
- Closes W32-B residual nested helper plates for relocate (`0046a2c0`) and fill-n (`00430390`) at structural level.
