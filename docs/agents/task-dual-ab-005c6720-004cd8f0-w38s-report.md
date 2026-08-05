# Dual A/B report — W38-S OWN `aa_005c6720` + `aa_004cd8f0`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W38-S  
**Scope:** VAs `0x005c6720`, `0x004cd8f0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs + `get_function_by_address`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave38_partition_map.md` (W38-S).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005c6720` TrackPayload_MatchObject_TfidOrPtrIdentity_Inferred | **accept-with-gaps** — dual-mode TFID/pointer match, `ret 4`, leaf, 2 callers sealed; product payload English open |
| `aa_004cd8f0` Host_ReplaceOwnedGridObj_E4FC_CtorPopulate_Inferred | **accept-with-gaps** — replace/`new`/ctor/populate/`ret 0x10` sealed; zero static xrefs + product host English open |

---

## VA `0x005c6720` — sealed facts

1. **Body:** `0x005c6720`–`0x005c6788` exclusive (**104 B** / `0x68`; pad `CC`). Ghidra meta end `005c6787` inclusive last byte — **matches**.
2. **ABI:** **`__thiscall`**; ECX = **payload** (track-list entry); stack **`(object*)`**; returns **bool** in AL/EAX; **`RET 4`** on all three exits.
3. **Semantics (leaf):**
   - If **both** payload TFID and object TFID are fully invalid — `(lo & hi) == 0xFFFFFFFF` — return **`*(payload+0x10) == object`** (pointer identity via `setz`).
   - Else compare TFID triple: payload `{+0x18 i32, +0x1c i32, +0x20 i8}` vs object TFID at **`object + *(*(object+4)+4) + 0x164`** (fields `+0/+4/+8`).
   - Same **9-byte** equality field set as sealed `TFID_EqualsObjectId` (`0x00404aa0`); **different** ABI and has pointer fallback.
4. **Payload layout:** object*@`+0x10`; TFID@`+0x18/+0x1c/+0x20`; flag@`+0x51` written by sibling finder (not this unit).
5. **Classification:** leaf match predicate.
6. **Callers (2):** `FUN_004bfd10` @ `0x004bfd3a` (TrackMgr untrack, W37-T); `FUN_004bfdb0` @ `0x004bfdda` (set `payload+0x51`).
7. **Callees:** none.
8. **Name:** `TrackPayload_MatchObject_TfidOrPtrIdentity_Inferred` (Ghidra `FUN_005c6720`; **Inferred**). **Reject** scaffold `Named_CalleeOf_…RecvInvento…`.
9. **Decompile ≡ CF**; bytes seal ABI/`ret 4`/AND-invalid test. Closes W37-T residual “full dual of `FUN_005c6720`”.  
   Full hex: raw W38-S append (104 B).

### Gaps

- Product English for payload / track entry class.  
- Product type of object MI adjustment `*(object+4)`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005c6720_TrackPayload_MatchObject_TfidOrPtrIdentity_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005c6720_TrackPayload_MatchObject_TfidOrPtrIdentity_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005c6720_FUN_005c6720.md` |
| Annotated | `docs/reconstruction/raw/aa_005c6720_FUN_005c6720.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/TrackPayload_MatchObject_TfidOrPtrIdentity_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005c6720.cpp` |
| Function | `docs/reconstruction/functions/aa_005c6720_FUN_005c6720.md` |
| Function named | `docs/reconstruction/functions/aa_005c6720_TrackPayload_MatchObject_TfidOrPtrIdentity_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_005c6720.md` |

---

## VA `0x004cd8f0` — sealed facts

1. **Body:** `0x004cd8f0`–`0x004cd991` exclusive (**161 B** / `0xA1`; pad `CC`). Ghidra meta end `004cd990` inclusive last byte — **matches**.
2. **ABI:** **`__thiscall`**; ECX = **host**; stack **`(dim_a, dim_b, dim_c, ctx)`** — four dwords; void; **`RET 0x10`**. SEH handler `LAB_009a1eb7`.
3. **Semantics:**
   - If `host+0xe4fc` non-null: **scalar-deleting dtor** `vtbl[0](1)`; null the slot.
   - `operator_new(0x30)`; if non-null **`FUN_005b3f60`** (W30-O default ctor: vtbl + empty list@`+0x10` + zero F4@`+0x20`); else null.
   - Store at **`host+0xe4fc`**.
   - **`FUN_005b3fa0`** (W37-L scaled grid populate) with **ECX = new object** (bytes: `mov ecx,eax` — decompiler drops this=), args `(dim_a, dim_b, dim_c, scale, ctx)` where **scale = `*(*(host+0xe4f8)+0x18)`** (nested host, not stack).
4. **Host fields:** owned 0x30 @`+0xe4fc`; nested ptr @`+0xe4f8` (scale at nested`+0x18`).
5. **Classification:** worker (host replace-owned-grid-obj).
6. **Callers:** **none** static CODE/DATA xrefs (Ghidra orphan). Structural live path for 0x30 list host vs dead convenience `005b4260` (W30-O / W37-L).
7. **Callees:** `operator_new`, `FUN_005b3f60`, `FUN_005b3fa0`, owned scalar dtor.
8. **Sibling (do not merge):** `FUN_004cd9a0` — also writes `+0xe4fc` but gate `+0x8c > 0x22` and populate `FUN_005b42f0`.
9. **Name:** `Host_ReplaceOwnedGridObj_E4FC_CtorPopulate_Inferred` (Ghidra `FUN_004cd8f0`; **Inferred**). No product plate.
10. **Decompile ≡ CF** for destroy/new/store; **bytes win** on populate this= and `ret 0x10`.  
    Full hex: raw W38-S append (161 B).

### Gaps

- Product English for host / nested `+0xe4f8`.  
- Zero static xrefs — who (if anyone) calls this.  
- OOM path: populate with ECX=0 after null store.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004cd8f0_Host_ReplaceOwnedGridObj_E4FC_CtorPopulate_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004cd8f0_Host_ReplaceOwnedGridObj_E4FC_CtorPopulate_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004cd8f0_FUN_004cd8f0.md` |
| Annotated | `docs/reconstruction/raw/aa_004cd8f0_FUN_004cd8f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Host_ReplaceOwnedGridObj_E4FC_CtorPopulate_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004cd8f0.cpp` |
| Function | `docs/reconstruction/functions/aa_004cd8f0_FUN_004cd8f0.md` |
| Function named | `docs/reconstruction/functions/aa_004cd8f0_Host_ReplaceOwnedGridObj_E4FC_CtorPopulate_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_004cd8f0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005c6720` | Port as **track payload match**: thiscall on payload, object on stack, `ret 4`. Invalid×invalid → pointer @`payload+0x10`; else TFID triple vs object@`+adj+0x164`. Invalid = **`(lo & hi) == -1`** (both all-ones). Do **not** substitute bare `TFID_EqualsObjectId` without adapting ABI/fallback. Used by 9-bucket untrack / flag-set (W37-T). |
| `004cd8f0` | Port as **host replace owned 0x30**: dtor old @`+0xe4fc`, `new(0x30)` + W30-O default ctor, store, W37-L populate with stack dims + scale from nested `*(+0xe4f8)+0x18` + stack ctx. **`ret 0x10`**. Restore populate **this=new**. Treat static orphan status as open. |
| Shared / contrast | **Unrelated domains** (track match leaf vs host grid-obj replace). Co-owned only by W38-S partition pair — do not cross-wire. |

Shared / related context:

| Symbol | Role |
|--------|------|
| `FUN_004bfd10` | TrackMgr_9CircList_UntrackObject (W37-T) — primary consumer of match |
| `FUN_004bfdb0` | sibling 9-bucket find + set `payload+0x51` |
| `TFID_EqualsObjectId` `0x00404aa0` | pure TFID 9-byte compare peer |
| `FUN_005b3f60` | Obj default ctor 0x30 (W30-O) |
| `FUN_005b3fa0` | Obj_PopulateListAt10_ScaledGridFill (W37-L) |
| `FUN_005b4260` | dead convenience ctor+populate |
| `FUN_004cd9a0` | sibling host path to `+0xe4fc` |

Closes W38-S OWN pair: track-payload dual-mode match (W37-T residual) + host replace/populate of owned grid object at `+0xe4fc` (live structural host for W30-O/W37-L).

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** (W38-S sections).  
- No invented product plates; structural `_Inferred` names from layout + prior duals.  
- Rejected scaffold RecvInventory chain name for `005c6720`.  
- Avoided bare `undefined4` in clean (`uint32_t` / voids / explicit casts).
