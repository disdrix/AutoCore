# Dual A/B report — W38-G OWN `aa_00438040` + `aa_004382c0`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W38-G  
**Scope:** VAs `0x00438040`, `0x004382c0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave38_partition_map.md` (W38-G).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00438040` StdVector_Resize_Elem8_ViaInsertN_00438d80 | **accept-with-gaps** — fastcall ECX=count/EDX=vec, stride-8 resize, grow `00438d80` / shrink `00438d00`, `ret 8`, 171 B sealed; product element type open |
| `aa_004382c0` Struct_TwoBasicString_DefaultCtor_Inferred | **accept-with-gaps** — dual `basic_string` default ctor at +0/+0x1c (0x38 span), stack this + `ret 4`, 70 B sealed; product field English open |

---

## VA `0x00438040` — sealed facts

1. **Body:** `0x00438040`–`0x004380EA` inclusive (**171 B** / `0xAB`); pad `CC`.
2. **ABI:** **`__fastcall`**; **ECX = newCount**, **EDX = vector\*** (`begin@+4`, `end@+8`); stack **8-byte fill by value**; void; **`ret 8`** (`c2 08 00`). SEH `LAB_009be178`.
3. **Semantics:** MSVC-style **vector of 8-byte elements** resize:
   - `size = (begin==0) ? 0 : (end-begin)>>3`
   - **Grow** (`size < newCount`): `FUN_00438d80(vec, end, newCount-size, &fill)`
   - **Shrink** (`begin!=0 && newCount < size`): `FUN_00438d00(vec, &tmp, begin+newCount*8, end)` — **element dtors** in erase
   - **Equal size:** no-op
   - **Fill cleanup:** if stack dword1 (rep) ≠ 0: `refcount--` at `+4`; if zero `call [vtbl+8]`
4. **Twin distinction:** Not dword thiscall resize (`00410420` / `004367f0`). Different register ABI, stride, and non-POD shrink.
5. **Classification:** worker leaf (vector resize utility).
6. **Callers (3 sites / 2 funcs):** `FUN_00437ce0` @ `00437cf7` (proxy fill `{0xa9da78,0}`); `FUN_00765740` @ `00765b15` / `00765ef5` (`EDX=host+0x128`).
7. **Callees:** `FUN_00438d80` (grow insert-N), `FUN_00438d00` (shrink erase-range).
8. **Name:** `StdVector_Resize_Elem8_ViaInsertN_00438d80` (Ghidra `FUN_00438040`; **Inferred**). **Reject** scaffold `Named_CalleeOf_Named_gfxBody_00438040`.
9. **Decompile ≡ CF**; machine seals fastcall registers, stride 8, `ret 8`, fill-rep epilogue. Full hex in raw W38-G append.

### Gaps

- Product element type (shared_ptr-shaped 8 B vs custom `{ptr,rep}`).  
- Unowned grow/shrink engine internals.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00438040_StdVector_Resize_Elem8_ViaInsertN_00438d80.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00438040_StdVector_Resize_Elem8_ViaInsertN_00438d80.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00438040_FUN_00438040.md` |
| Annotated | `docs/reconstruction/raw/aa_00438040_FUN_00438040.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_Resize_Elem8_ViaInsertN_00438d80.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00438040.cpp` |
| Function | `docs/reconstruction/functions/aa_00438040_FUN_00438040.md` |
| Function named | `docs/reconstruction/functions/aa_00438040_StdVector_Resize_Elem8_ViaInsertN_00438d80.md` |

---

## VA `0x004382c0` — sealed facts

1. **Body:** `0x004382c0`–`0x00438305` inclusive (**70 B** / `0x46`); pad `CC`.
2. **ABI:** stack **this\***; returns **this** in EAX; **`ret 4`**. **Not** ECX-thiscall (`mov esi,[esp+0x14]` after SEH). SEH `LAB_009bbfb9`.
3. **Semantics:** Default-construct **two** MSVC `basic_string` (each **0x1c**):
   - `basic_string_default_ctor(this+0)` via IAT `[0x009c6288]` → `0x006eb25c`
   - SEH state ← 0
   - `basic_string_default_ctor(this+0x1c)` same IAT
   - return `this`
4. **Object span:** **0x38** dual-string record; matches callers `sub esp,0x38` and vector resize stride `/0x38` (`FUN_00437e40`, not OWN).
5. **Classification:** worker leaf (composite default ctor).
6. **Callers (6 sites / 4 funcs):** `FUN_00437ad0`, `FUN_00765740`, `FUN_009895c0`, `FUN_0095e3e0` (×3).
7. **Callees:** MSVC `basic_string` default ctor (IAT, ×2).
8. **Name:** `Struct_TwoBasicString_DefaultCtor_Inferred` (Ghidra `FUN_004382c0`; **Inferred**). **Reject** scaffold `Named_CalleeOf_Named_gfxBody_004382c0`.
9. **Decompile ≡ bytes** for dual +0x1c ctors / return this. Full hex in raw W38-G append.

### Gaps

- Product struct / field English.  
- Whether type has fields beyond the 0x38 dual-string span.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004382c0_Struct_TwoBasicString_DefaultCtor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004382c0_Struct_TwoBasicString_DefaultCtor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004382c0_FUN_004382c0.md` |
| Annotated | `docs/reconstruction/raw/aa_004382c0_FUN_004382c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Struct_TwoBasicString_DefaultCtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004382c0.cpp` |
| Function | `docs/reconstruction/functions/aa_004382c0_FUN_004382c0.md` |
| Function named | `docs/reconstruction/functions/aa_004382c0_Struct_TwoBasicString_DefaultCtor_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00438040` | Port as **`vector<Elem8>::resize(n, fill)`** with **fastcall** (count, vec\*) and **8-byte fill by value**. `begin@+4`/`end@+8`. Grow = insert-N via `00438d80`; shrink = erase `[n,end)` via `00438d00` **with element dtors**. Do **not** merge with dword thiscall resizes (`00410420`/`004367f0`). Destroy fill.rep on exit if non-null. |
| `004382c0` | Port as **default ctor of `{string,string}`** (offsets 0 / 0x1c, total 0x38). Stack this, return this, `ret 4`. Use as default fill for 0x38-elem dual-string vectors. |
| Shared | Co-owned only by W38-G partition pair. Both appear on `FUN_00765740` paths but are **independent utilities** (elem8 vector resize vs dual-string default ctor). Avoid bare `undefined4` in clean (`uint32_t` / structs). |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x00438d80` | Grow insert-N for 8-byte elements |
| `0x00438d00` | Shrink erase-range with element dtors |
| `0x00437ce0` | Thin wrapper into resize |
| `0x00437e40` | Vector resize stride **0x38** (often after dual-string default) |
| `0x00437ad0` | Local 0x38 + dual-string ctor + 0x38 resize |
| `0x00765740` | Host consumer (vec @ +0x128; dual-string temps) |
| `0x009c6288` | IAT slot for `basic_string` default ctor |

Closes W38-G OWN pair: 8-byte-element vector resize (via insert-N `00438d80`) + dual-`basic_string` default constructor leaf.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers + assembly context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** (W38-G sections).  
- No invented product plates; `_Inferred` structural names only.  
- Rejected scaffold Named_CalleeOf / gfxBody product roles.  
- Clean avoids bare `undefined4` (`uint32_t` / explicit structs).
