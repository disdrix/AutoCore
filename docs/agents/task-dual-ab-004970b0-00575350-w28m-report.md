# Dual A/B report — W28-M OWN `aa_004970b0` + `aa_00575350`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W28-M  
**Scope:** VAs `0x004970b0`, `0x00575350` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave28_partition_map.md` (W28-M).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004970b0` Class_009c7a1c_CompleteDtor | **accept-with-gaps** — complete dtor CF/ABI/vector+buffers+list LEA@+0x0C sealed |
| `aa_00575350` Object_009d33c4_CompleteDtor | **accept-with-gaps** — derived dtor CF/ABI/list LEA@+0x1DC + tail-jmp Object base sealed |

---

## VA `0x004970b0` — sealed facts

1. **Body:** `0x004970b0`–`0x004971e0` exclusive (**304** B / `0x130`). Final bare **`RET`** (`C3`); next fn @ `0x004971e0`.
2. **ABI:** **`__thiscall`**; ECX = `this`; no stack formals; **void**; bare **`RET`**.
3. **Semantics:** MSVC **complete-object destructor** for vtbl `PTR_FUN_009c7a1c`:
   - Install vtbl; SEH frame `LAB_009a0d7e`, EH state `6` on vector path.
   - Cookie-vector @ `+0x28`: elem size `0x28`, count @ `ptr-4`, elem dtor `FUN_005b8000`, then `operator_delete[]`.
   - Zero `+0x28`, `+4`, `+8`.
   - Free six begin/end/cap triples: `+0xBC`, `+0xAC`, `+0x9C`, `+0x40`, `+0x30`, `+0x1C`.
   - **`lea ecx,[this+0x0C]; call StdList_Destroy_FreeHead`** (`FUN_00497360`, W27-K). Decompiler drops LEA.
4. **Classification:** worker (complete dtor body).
5. **Callers (1):** `FUN_004975e0` only — **scalar deleting dtor** = **vtbl[0]** of `PTR_FUN_009c7a1c` (`RET 4`, flags&1 free).
6. **Xrefs:** 1.
7. **Related:** ctor twin `FUN_00496f70` (same vtbl); element dtor `FUN_005b8000`.
8. **Name:** `Class_009c7a1c_CompleteDtor` (Ghidra `FUN_004970b0`). Product demangle open; vtbl suffix disambiguates. **Do not** treat as scalar-deleting or as list-only destroy.
9. **Decompile ≡ raw CF** for order; **list ECX target and operator_delete fall-through** sealed by bytes (Ghidra false-noreturn on delete).

### Gaps

- Product English / MSVC demangle.  
- Semantic labels for six buffers and `+4`/`+8`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004970b0_Class_009c7a1c_CompleteDtor.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004970b0_Class_009c7a1c_CompleteDtor.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004970b0_FUN_004970b0.md` |
| Annotated | `docs/reconstruction/raw/aa_004970b0_FUN_004970b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Class_009c7a1c_CompleteDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004970b0.cpp` |
| Function | `docs/reconstruction/functions/aa_004970b0_FUN_004970b0.md` |
| Function named | `docs/reconstruction/functions/aa_004970b0_Class_009c7a1c_CompleteDtor.md` |
| Scratch | `docs/reconstruction/tmp/a_004970b0.md` |

---

## VA `0x00575350` — sealed facts

1. **Body:** `0x00575350`–`0x005753ba` exclusive (**106** B / `0x6A`; pad `CC` after tail-jmp).
2. **ABI:** **`__thiscall`**; ECX = `this`; no stack formals; **no local RET** — ends in **`jmp FUN_00518ec0`**.
3. **Semantics:** MSVC **derived complete-object destructor** for vtbl `PTR_FUN_009d33c4`:
   - Install vtbl.
   - Free owned @ `+0x1EC`; clear bytes `+0x1F0`, `+0x1F1`.
   - Free buffer triple @ `+0x1F8` / `+0x1FC` / `+0x200`.
   - **`lea ecx,[this+0x1DC]; call StdList_Destroy_FreeHead`**.
   - **Tail-call** Object shared-base dtor `FUN_00518ec0` (same `this`).
4. **Inheritance:** ctor twin `FUN_00575440` → `Object_SharedBase_Ctor` (`FUN_00518940`, W22-B) then same vtbl.
5. **Classification:** worker (derived complete dtor).
6. **Callers (1):** `FUN_00575c00` only — **scalar deleting dtor** = **vtbl[0]** (`RET 4`).
7. **Xrefs:** 1.
8. **Vtbl:** `[0]=0x00575c00` scalar-deleting; `[1]=0x0056f570` empty stub.
9. **Name:** `Object_009d33c4_CompleteDtor` (Ghidra `FUN_00575350`). **Do not** merge with base-only `FUN_00518ec0` or with `Class_009c7a1c_CompleteDtor`.
10. **Decompile ≡ raw CF**; list LEA + tail-jmp sealed by bytes.

### Gaps

- Product English / MSVC demangle for derived type.  
- Payload/flag semantics @ `+0x1EC` / `+0x1F0`/`+0x1F1`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00575350_Object_009d33c4_CompleteDtor.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00575350_Object_009d33c4_CompleteDtor.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00575350_FUN_00575350.md` |
| Annotated | `docs/reconstruction/raw/aa_00575350_FUN_00575350.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_009d33c4_CompleteDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00575350.cpp` |
| Function | `docs/reconstruction/functions/aa_00575350_FUN_00575350.md` |
| Function named | `docs/reconstruction/functions/aa_00575350_Object_009d33c4_CompleteDtor.md` |
| Scratch | `docs/reconstruction/tmp/a_00575350.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004970b0` | Port complete dtor: vtbl first; destroy 0x28-stride cookie vector @+0x28; free six buffer triples; **StdList destroy at +0x0C** (not root). Keep scalar-deleting (`004975e0`) separate. Ignore Ghidra noreturn on `operator_delete`. |
| `00575350` | Port derived complete dtor: free +0x1EC / buffer +0x1F8 / list +0x1DC; **must** chain Object shared-base dtor (`00518ec0`). Scalar-deleting (`00575c00`) separate. Do not merge with `Class_009c7a1c`. |
| Pair with | `StdList_Destroy_FreeHead` (`0x00497360`), `Object_SharedBase_Ctor` (`0x00518940`), element dtor `FUN_005b8000`, base dtor body `FUN_00518ec0`. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; names use vtbl suffix + structural complete-dtor role.
