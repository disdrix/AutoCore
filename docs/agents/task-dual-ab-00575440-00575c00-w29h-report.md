# Dual A/B report — W29-H OWN `aa_00575440` + `aa_00575c00`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W29-H  
**Scope:** VAs `0x00575440`, `0x00575c00` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave29_partition_map.md` (W29-H).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00575440` Object_009d33c4_Ctor | **accept-with-gaps** — derived ctor CF/ABI/base chain/list LEA@+0x1DC + field init sealed |
| `aa_00575c00` Object_009d33c4_ScalarDeletingDtor | **accept-with-gaps** — vtbl[0] scalar deleting CF/ABI/RET 4 + optional free sealed |

---

## VA `0x00575440` — sealed facts

1. **Body:** `0x00575440`–`0x00575528` exclusive (**232** B / `0xE8`). Final bare **`RET`** (`C3`); pad `CC` after.
2. **ABI:** **`__thiscall`**; ECX = `this`; no stack formals; returns `this` in EAX; bare **`RET`**. (Ghidra may show `__fastcall`.)
3. **Semantics:** MSVC **complete-object constructor** for vtbl `PTR_FUN_009d33c4`:
   - SEH frame `LAB_009a5096`; EH state `-1` → `0` after base.
   - `Object_SharedBase_Ctor` (`FUN_00518940`, W22-B).
   - Install derived vtbl.
   - **`lea edi,[this+0x1DC]`**; `FUN_00457c60()` → 0x18 circular sentinel → store at **list+4 (`this+0x1E0`)**; size **list+8 (`this+0x1E4`) = 0**.
   - Init derived region: `+0x190=1`; four 0x10 id-pair slots @ `+0x198/+0x1A8/+0x1B8/+0x1C8` as `{−1,−1,0}`; `+0x1E8=−1`; owned `+0x1EC=0`; flags `+0x1D8/+0x1F0/+0x1F1/+0x1F2=0`; buffer triple `+0x1F8/+0x1FC/+0x200=0`.
4. **Classification:** worker (derived complete ctor body).
5. **Callers (2):** `CVOGReaction_GiveItemByCbid` @ `0x0051a601`; `FUN_0094bed0` @ `0x0094bf04`.
6. **Xrefs:** 2.
7. **Related:** complete dtor twin `FUN_00575350` (W28-M); scalar deleting `FUN_00575c00` (this dual); list destroy peer `StdList_Destroy_FreeHead` (`FUN_00497360`).
8. **Name:** `Object_009d33c4_Ctor` (Ghidra `FUN_00575440`). Supersedes scaffold `Named_CalleeOf_CVOGReaction_GiveItemByCbid_00575440`. **Do not** treat as base-only ctor.
9. **Decompile ≡ raw CF** for order; **list ECX/EDI target** sealed by bytes (Ghidra drops LEA).

### Gaps

- Product English / MSVC demangle for derived type.  
- Semantic labels for id-pair cluster and `+0x190`/`+0x1E8`/`+0x1EC`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00575440_Object_009d33c4_Ctor.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00575440_Object_009d33c4_Ctor.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00575440_FUN_00575440.md` |
| Annotated | `docs/reconstruction/raw/aa_00575440_FUN_00575440.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_009d33c4_Ctor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00575440.cpp` |
| Function | `docs/reconstruction/functions/aa_00575440_FUN_00575440.md` |
| Function named | `docs/reconstruction/functions/aa_00575440_Object_009d33c4_Ctor.md` |

---

## VA `0x00575c00` — sealed facts

1. **Body:** `0x00575c00`–`0x00575c1e` exclusive (**30** B / `0x1E`; pad `CC` after).
2. **ABI:** **`__thiscall`**; ECX = `this`; stack formal `flags`; returns `this`; **`RET 4`**.
3. **Semantics:** MSVC **scalar deleting destructor** for vtbl `PTR_FUN_009d33c4`:
   - Call complete dtor `FUN_00575350` (`Object_009d33c4_CompleteDtor`).
   - If `(flags & 1)`: `operator_delete(this)` (fall-through; Ghidra false-noreturn).
   - Return `this`.
4. **Vtbl:** **[0]=`0x00575c00`** scalar-deleting; **[1]=`0x0056f570`** empty stub (W28-M).
5. **Classification:** worker (scalar deleting dtor wrapper).
6. **Callers:** none direct; **1 data xref** from vtbl @ `0x009d33c4`.
7. **Xrefs:** 1.
8. **Name:** `Object_009d33c4_ScalarDeletingDtor` (Ghidra `FUN_00575c00`). **Do not** merge with complete dtor or base dtor `FUN_00518ec0`.
9. **Decompile ≡ raw CF**; RET 4 + optional free sealed by bytes.

### Gaps

- Product English / MSVC demangle for derived type.  
- Runtime virtual-delete trace.  
- Bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00575c00_Object_009d33c4_ScalarDeletingDtor.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00575c00_Object_009d33c4_ScalarDeletingDtor.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00575c00_FUN_00575c00.md` |
| Annotated | `docs/reconstruction/raw/aa_00575c00_FUN_00575c00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_009d33c4_ScalarDeletingDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00575c00.cpp` |
| Function | `docs/reconstruction/functions/aa_00575c00_FUN_00575c00.md` |
| Function named | `docs/reconstruction/functions/aa_00575c00_Object_009d33c4_ScalarDeletingDtor.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00575440` | Port derived ctor: call `Object_SharedBase_Ctor` first; install `PTR_FUN_009d33c4`; build StdList at **+0x1DC** (head @ **+0x1E0** via 0x18 sentinel alloc, size @ **+0x1E4**=0); init derived fields to match dtor teardown. Keep separate from base-only ctor. |
| `00575c00` | Port scalar deleting: complete dtor then `(flags&1)` free; **`RET 4`**. Keep separate from complete dtor body. Ignore Ghidra noreturn on `operator_delete`. |
| Pair with | `Object_009d33c4_CompleteDtor` (`0x00575350`), `Object_SharedBase_Ctor` (`0x00518940`), base dtor `FUN_00518ec0`, `StdList_Destroy_FreeHead` (`0x00497360`), sentinel alloc `FUN_00457c60`. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; names use vtbl suffix + structural ctor / scalar-deleting roles.
