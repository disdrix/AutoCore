# Dual A/B report — W38-K OWN `aa_0096b930` + `aa_004a8100`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W38-K  
**Scope:** VAs `0x0096b930`, `0x004a8100` only. Dual A/B + artifacts (trio + function + A/B).  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `batch_decompile` / `decompile_function` + `analyze_function_complete` + `get_function_by_address` + callers/xrefs/callees + `read_memory` + `list_strings`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave38_partition_map.md` (W38-K).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0096b930` phySkeleton_unserialize | **accept-with-gaps** — PSKE tag/v1/RET8/bone-loop+index stamp sealed; `FUN_0096b150` + flag English open |
| `aa_004a8100` StdVector_PushBack_BasicStringW | **accept-with-gaps** — thiscall RET4 / stride 0x1c / spare fill-one vs insert-one grow sealed; product demangle open |

---

## VA `0x0096b930` — sealed facts

1. **Body:** `0x0096b930`–`0x0096ba79` exclusive (**329 B** / `0x149`; pad `CC`).
2. **ABI:** stack **`phySkeleton* self`**, **`stoChunkReader* reader`**; returns **`uint32_t`** in EAX; **`RET 0x08`** (`C2 08 00` both tails).
3. **Semantics:** **phySkeleton** chunk unserialize for tag **`0x50534b45` (`PSKE`)** version **1 only**:
   - SEH `LAB_009b3077` + `stoChunkReader_EnterChunkScope(reader)`.
   - Invalid tag → log `phySkeleton.cpp` line **`0x3a`**; invalid version → format + line **`0x53`**; return **`0xffffffff`**.
   - Success: read bone count via binary `FUN_00437050` / text `FUN_007689e0` selected by **`reader+0x4044`**.
   - `FUN_0096b150(self, count)`; loop bone ptr vector **`self+0x0C..+0x10`**: `phyBone_unserialize` then **`*(bone+0x144)=index`**.
   - **`*(self+0x1C)+=1`**; **`*(self+4)|=3`**; leave scope if flag; return count-read status.
4. **Classification:** worker (asset I/O).
5. **Callers (1 parent, 2 sites):** `FUN_00765740` (gfxBody unserialize) @ `0x00765ac5`, `0x00765ea5` — skeleton @ **`body+0x98`**.
6. **Callees:** EnterChunkScope; `FUN_00437050`; `FUN_007689e0`; `FUN_0096b150`; `phyBone_unserialize` (`0x0096e280`); `FUN_0076cec0`; `vog_LogMessage`; `FUN_00769e40`.
7. **Name:** `phySkeleton_unserialize` (Ghidra `FUN_0096b930`; product path + log strings). Alias scaffold `Named_phySkeleton_0096b930`.
8. **Decompile ≡ bytes** for CF/tag/version/RET. Full hex: raw W38-K append (329 B).

### Gaps

- Product English for `FUN_0096b150` and flag/counter fields.  
- Bone vector ownership / allocator.  
- SEH partial-construction teardown plate.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0096b930_phySkeleton_unserialize.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0096b930_phySkeleton_unserialize.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0096b930_FUN_0096b930.md` |
| Annotated | `docs/reconstruction/raw/aa_0096b930_FUN_0096b930.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/phySkeleton_unserialize.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0096b930.cpp` |
| Function | `docs/reconstruction/functions/aa_0096b930_FUN_0096b930.md` |
| Function named | `docs/reconstruction/functions/aa_0096b930_phySkeleton_unserialize.md` |

---

## VA `0x004a8100` — sealed facts

1. **Body:** `0x004a8100`–`0x004a8187` exclusive (**135 B** / `0x87`; pad `CC`).
2. **ABI:** **`__thiscall`**; ECX=`vector*`; stack **`value*`**; void; **`RET 0x04`** (`C2 04 00` both paths).
3. **Semantics:** MSVC-style **`vector<basic_string<wchar_t>>::push_back`** (elem **0x1c**):
   - size/cap via magic **`0x92492493`** → `/0x1c`.
   - **Spare capacity** (`begin!=0 && size < cap`): `StdUninitFillN_BasicStringW(end, 1, value)` (`FUN_004a74f0`, W36-R); retail often pushes 5 dwords + `ADD ESP,0x14`; **`end += 0x1c`**.
   - **Empty or full:** `StdVector_InsertOne_RebindIt_BasicStringW` (`FUN_004a7ff0`, W37-W) at `where=end`; discard outIt.
4. **Classification:** worker (thin STL wrapper).
5. **Callers (1):** `FUN_004a1d80` @ `0x004a1e57` — splits `wchar_t*` tokens into local `basic_string<wchar_t>` then push_back onto `this` vector.
6. **Callees:** `FUN_004a74f0` / `StdUninitFillN_BasicStringW` (W36-R); `FUN_004a7ff0` / `StdVector_InsertOne_RebindIt_BasicStringW` (W37-W).
7. **Name:** `StdVector_PushBack_BasicStringW` (Ghidra `FUN_004a8100`; **Inferred** structural). **Reject** scaffold `Named_CalleeOf_*attachmentResponse*`. Twins: RcElem28 `0x00460f90`; POD Elem28 `0x00469c80` (different ABI/callees).
8. **Decompile ≡ bytes** for CF/stride/RET. Full hex: raw W38-K append (135 B).

### Gaps

- Product/MSVC demangle English.  
- Runtime / bit-exact under realloc.  
- Strict `const T&` vs by-value formal (one stack slot at known call site).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004a8100_StdVector_PushBack_BasicStringW.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004a8100_StdVector_PushBack_BasicStringW.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004a8100_FUN_004a8100.md` |
| Annotated | `docs/reconstruction/raw/aa_004a8100_FUN_004a8100.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_PushBack_BasicStringW.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004a8100.cpp` |
| Function | `docs/reconstruction/functions/aa_004a8100_FUN_004a8100.md` |
| Function named | `docs/reconstruction/functions/aa_004a8100_StdVector_PushBack_BasicStringW.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0096b930` | Port as **phySkeleton PSKE v1 unserialize**: stack `(self, reader)` **RET 8**; hard-fail non-PSKE / non-v1 with `0xffffffff`; binary/text count via `reader+0x4044`; after bone loop **must** stamp `bone+0x144=index`; bump `+0x1C` and `flags\|=3`. Do **not** fold `phyBone_unserialize` or `FUN_0096b150` into this VA. Nested from gfxBody @ `body+0x98`. |
| `004a8100` | Port as **`vector<wstring>::push_back`**: thiscall + **RET 4**; stride **0x1c**; spare-cap → fill-n count=1 + end+=0x1c; else insert-one-rebind at end. Do **not** unify with RcElem28 `00460f90` or POD `00469c80`. Closes parent left open under W37-W insert-one. |
| Pair with | W37-W `StdVector_InsertOne_RebindIt_BasicStringW` (`0x004a7ff0`); W36-R `StdUninitFillN_BasicStringW` (`0x004a74f0`); W34-R insert-n; phyBone dual `0x0096e280`; gfxBody parent `0x00765740` (unowned). |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x004a74f0` | fill-n fast path (W36-R) |
| `0x004a7ff0` | insert-one slow path (W37-W) |
| `0x004a7ad0` | insert-n under insert-one (W34-R) |
| `0x004a1d80` | sole push_back caller (wstring token split) |
| `0x0096e280` | phyBone_unserialize (dual sealed) |
| `0x0096b150` | skeleton count apply / bone prep (residual) |
| `0x00765740` | gfxBody unserialize parent |
| `0x00437050` / `0x007689e0` | binary / text int32 readers |
| `0x00769e40` | leave chunk scope |

Closes W38-K OWN pair: phySkeleton unserialize left open under phyBone dual as sole parent, and the wstring push_back parent left open under W37-W insert-one.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0096b930-004a8100-w38k-report.md` |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; phySkeleton name from retail strings; push_back uses `_Inferred` structural name.  
- Rejected long Named_CalleeOf scaffold aliases as primary.  
- Avoided bare `undefined4` in clean (`uint32_t` / `BasicStringW_0x1c` / explicit offsets).  
- Terminal coverage: **false** (no Launcher / runtime / bit-exact Confirmed).
