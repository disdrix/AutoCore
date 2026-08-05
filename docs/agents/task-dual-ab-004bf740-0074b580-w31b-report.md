# Dual A/B report — W31-B OWN `aa_004bf740` + `aa_0074b580`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W31-B  
**Scope:** VAs `0x004bf740`, `0x0074b580` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave31_partition_map.md` (W31-B).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004bf740` OwningSList_ClearDestroy_ScalarDtor_Inferred | **accept-with-gaps** — loop/ABI/offsets/scalar-dtor sealed; product T residual |
| `aa_0074b580` EmptyDtorStub | **accept** — 1-byte `c3` nop leaf sealed; multi-role shared stub |

---

## VA `0x004bf740` — sealed facts

1. **Body:** `0x004bf740`–`0x004bf76e` inclusive of `C3` (**47 B** / `0x2F`; exclusive end `0x004bf76f`; pad `CC` then `FUN_004bf770`).
2. **ABI:** **ECX=`this`** (list host); bare **`RET`** (`C3`); void. Ghidra `__fastcall` ≡ thiscall ECX.
3. **Semantics:** **Owning singly-linked list clear**:
   - Head pointer at host **`+0x04`**; count at host **`+0x0c`**.
   - While head ≠ 0: set head = `node→next` (`node+0x04`); call **`vtbl[0](1)`** (MSVC scalar-deleting dtor); **count--**.
   - Empty-head fast-out; does **not** free the list host.
4. **Classification:** leaf (indirect virtual only; no static callees).
5. **Callers:** sole CALL xref — `ListTrackedObj_CompleteDtor` (`FUN_004be2a0`) @ `0x004be321` as `FUN_004bf740(this+0x10)` under flag@`+0x5D0` (W30-P).
6. **Callees:** none static; per-node `vtbl[0]`.
7. **Name:** `OwningSList_ClearDestroy_ScalarDtor_Inferred` (Ghidra `FUN_004bf740`; **Inferred** structural). **Reject** scaffold `Named_CalleeOf_*_VOG_DEBUG_ST_004bf740`.
8. **Decompile ≡ bytes** for full loop + epilogue.  
   Full hex: raw W31-B append (47 B).

### Gaps

- Product/MSVC demangle for node type T and list host class English.  
- Count vs chain-length consistency assert (none in body).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004bf740_OwningSList_ClearDestroy_ScalarDtor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004bf740_OwningSList_ClearDestroy_ScalarDtor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004bf740_FUN_004bf740.md` |
| Annotated | `docs/reconstruction/raw/aa_004bf740_FUN_004bf740.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/OwningSList_ClearDestroy_ScalarDtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004bf740.cpp` |
| Function | `docs/reconstruction/functions/aa_004bf740_FUN_004bf740.md` |
| Function named | `docs/reconstruction/functions/aa_004bf740_OwningSList_ClearDestroy_ScalarDtor_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_004bf740.md` |

---

## VA `0x0074b580` — sealed facts

1. **Body:** `0x0074b580` = **`c3` (`ret`)** only. Exclusive end `0x0074b581`. Following `cc` is pad, not body.
2. **CF:** empty `return;` — decompile ≡ 2026-07-23 raw ≡ live re-verify.
3. **ABI:** bare `ret` (not `ret n`). Body ignores ECX and any stack args callers may push.
4. **Callees:** none. Classification: **stub**.
5. **Roles (xref evidence, not body logic):**
   - Empty **member dtor** stubs in `ListTrackedObj_CompleteDtor` ×3 (`0x004be3ce` / `0x004be3de` / `0x004be3ee` — offsets `+0x474` / `+0x444` / `+0x414`).
   - MSVC **EH Unwind** / trivial dtor targets (`Unwind@009a…`).
   - Other owner call sites (`FUN_004921e0`, `FUN_00496410`, `FUN_00496600`, `FUN_00496920`).
6. **Name:** `EmptyDtorStub` (descriptive). **Reject** scaffold `Named_CalleeOf_Mission_Uses_CVOGReaction_FailMissionNotify_0074b580`.
7. **Not this VA:** mass `EmptyRet` @ `0x0056f570`; `ObjectMotion_SlotEmptyDtor` @ `0x004b0bd0`; `CVOGHBBase_EmptyVFunc` @ `0x005081f0`.

### Gaps

1. Original PDB/compiler symbol.  
2. Exhaustive product English per thiscall offset site.  
3. Runtime / bit-exact / differential — open (vacuous).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0074b580_EmptyDtorStub.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0074b580_EmptyDtorStub.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0074b580_FUN_0074b580.md` |
| Annotated | `docs/reconstruction/raw/aa_0074b580_FUN_0074b580.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/EmptyDtorStub.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0074b580.cpp` |
| Function | `docs/reconstruction/functions/aa_0074b580_FUN_0074b580.md` |
| Function named | `docs/reconstruction/functions/aa_0074b580_EmptyDtorStub.md` |
| Scratch | `docs/reconstruction/tmp/a_0074b580.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004bf740` | Port as **owning SList clear**: while head@`+4`, advance to next@`node+4`, call **scalar-deleting dtor (flags=1)**, decrement count@`+0xc`. Do **not** free the list host. Used from ListTrackedObj complete dtor at `this+0x10` under flag@`+0x5D0`. |
| `0074b580` | Port as **shared empty nop** — do not invent logging, free, or notify. Member dtor call sites may collapse to no-ops or a single shared empty function. Keep distinct from mass `EmptyRet` unless all xrefs are re-audited. |
| Pair with | `ListTrackedObj_CompleteDtor` (`0x004be2a0`, W30-P); nested residual `FUN_00763f60` (W31-C peer, not owned here). |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; structural `_Inferred` / descriptive names only.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).  
- Rejected VOG_DEBUG and Mission_Uses_CVOGReaction scaffold aliases.

---

## Report path

`docs/agents/task-dual-ab-004bf740-0074b580-w31b-report.md`  
Absolute: `C:\Users\josh\Documents\GitHub\AutoCore\docs\agents\task-dual-ab-004bf740-0074b580-w31b-report.md`
