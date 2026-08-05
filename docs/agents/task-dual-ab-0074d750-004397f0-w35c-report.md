# Dual A/B report — W35-C OWN `aa_0074d750` + `aa_004397f0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W35-C  
**Scope:** VAs `0x0074d750`, `0x004397f0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** wave35 (W35-C).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0074d750` Class_00aa05cc_Ctor_Inferred | **accept-with-gaps** — ECX thiscall + bare RET + dual NestedHash bags + host 0x5C sealed; product class English open |
| `aa_004397f0` CircularSentinel_Alloc0x10_Inferred | **accept-with-gaps** — size 0x10 + circular links + EAX return + 26 B sealed; product payload English open |

---

## VA `0x0074d750` — sealed facts

1. **Body:** `0x0074d750`–`0x0074d7ad` (**94 B** / `0x5E`; pad `CC` then next).
2. **ABI:** **ECX=this** (`MOV ESI,ECX`); no stack formals; bare **`C3`**; returns **this in EAX**. SEH `LAB_009acbbf` + `ADD ESP,0x10`.
3. **Semantics (ctor):**
   - `*this = PTR_FUN_00aa05cc` (vtbl).
   - `this+0x04 = 0`; `MOVSS` zeros `this+0x08` (4 B).
   - `NestedHashBag_Ctor_Inferred` (`FUN_0044a0d0`, W34-D) at **`this+0x0c`** (stack-self* RET 4).
   - SEH state → 0; `NestedHash_Ctor_Sentinel0x14_Inferred` (`FUN_0043bdf0`, W34-E) at **`this+0x34`**.
4. **Host size:** **0x5C** — head 0x0C + bag 0x28 + bag 0x28; all heap callers use `operator_new(0x5c)`.
5. **Classification:** worker (ctor).
6. **Callers (10 xrefs):** `FUN_004930b0`, `FUN_004cac30` (×2), `FUN_00504d40`, `FUN_005320d0`, `FUN_005866d0`, `FUN_005942d0`, `FUN_00910460`, + `0x0056e9e1`, `0x005865f9`. Post-ctor geo/anm bind (`FUN_0074d420`, vtbl methods); often paired with `AnimSlot_Ctor` (`0x0074ed90`) and tree host `new(0x14)`.
7. **Name:** `Class_00aa05cc_Ctor_Inferred` (Ghidra `FUN_0074d750`; **Inferred** structural from vtbl). **Reject** scaffold `Named_CalleeOf_Named_VOG_DEBUG_STOP_0074d750`.
8. **Decompile ≡ bytes** for stores/call order; **bytes win** on bare RET (thiscall, no stack clean).  
   Full hex: `6aff68bfcb9a0064a1000000005064892500000000510f57c0568bf18d460c5089742408c706cc05aa00c7460400000000f30f114608e845c9cfff8d463450c744241400000000e854e6ceff8b4c24088bc65e64890d0000000083c410c3`

### Gaps

- Product/PDB demangle for class / vtbl methods.  
- Head `+0x04/+0x08` meaning beyond zero.  
- Unowned `FUN_0074d420` and full vtbl contracts.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0074d750_Class_00aa05cc_Ctor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0074d750_Class_00aa05cc_Ctor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0074d750_FUN_0074d750.md` |
| Annotated | `docs/reconstruction/raw/aa_0074d750_FUN_0074d750.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Class_00aa05cc_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0074d750.cpp` |
| Function | `docs/reconstruction/functions/aa_0074d750_FUN_0074d750.md` |
| Function named | `docs/reconstruction/functions/aa_0074d750_Class_00aa05cc_Ctor_Inferred.md` |

---

## VA `0x004397f0` — sealed facts

1. **Body:** `0x004397f0`–`0x00439809` (**26 B** / `0x1A`; pad `CC` then next).
2. **ABI:** no formals; bare **`C3`**; returns **node* in EAX** (decompiler `void` wrong).
3. **Semantics:**
   - `operator_new(0x10)`.
   - If non-null: `*node = node` (next).
   - `*(node+4) = node` (prev) — MSVC `lea/test` gate on `node+4`.
4. **Classification:** wrapper / factory.
5. **Callers (4):** `FUN_00457ac0` @ `0x00457adb` (`NestedHash_Ctor_Sentinel0x10`, W34-E); `FUN_004a0b90` @ `0x004a0df2`; `FUN_007c6c50` @ `0x007c6ca2`; `FUN_007c7200` @ `0x007c7252`.
6. **Callees:** `operator_new`.
7. **Name:** `CircularSentinel_Alloc0x10_Inferred` (Ghidra `FUN_004397f0`; **Inferred**). **Reject** scaffold `Named_CalleeOf_*_VOG_DEBUG_STOP_004397f0`.
8. **Family:** same 26 B CF as `CircularSentinel_Alloc0x28_Inferred` (`0x00423d60`, W33-B) and `StdList_AllocSentinel_0xC_Inferred` (`0x004933f0`) with size **0x10**; non-SEH.
9. **Decompile ≡ bytes** for stores and bare RET; **bytes/callers win** on return type.  
   Full hex: `6a10e89b00050083c40485c0740289008d480485c974028901c3`

### Gaps

- Product English for remaining **0x08** payload bytes of the node.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004397f0_CircularSentinel_Alloc0x10_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004397f0_CircularSentinel_Alloc0x10_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004397f0_FUN_004397f0.md` |
| Annotated | `docs/reconstruction/raw/aa_004397f0_FUN_004397f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CircularSentinel_Alloc0x10_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004397f0.cpp` |
| Function | `docs/reconstruction/functions/aa_004397f0_FUN_004397f0.md` |
| Function named | `docs/reconstruction/functions/aa_004397f0_CircularSentinel_Alloc0x10_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0074d750` | Port as **ECX thiscall ctor** (bare RET, return this). Always **`new(0x5c)`**. Install vtbl `PTR_FUN_00aa05cc`, zero `+4/+8`, then placement NestedHashBag @ **+0x0c** and NestedHash 0x14 @ **+0x34** via sealed W34-D/E (stack-self* RET 4). Do **not** invent stack-self* RET 4 on the host itself. Do **not** invent product English — structural Class_00aa05cc only. Closes W34-D sole-caller residual + W34-E nested-embed residual. |
| `004397f0` | Port as **free factory**: `operator_new(0x10)` + circular next/prev self-links; return node* in EAX. Family twin of Alloc0x28 / Alloc0xC (same 26 B CF). Pair with `NestedHash_Ctor_Sentinel0x10` (W34-E). Do **not** conflate sizes 0x10 / 0x14 / 0x28. |

Shared: NestedHash continuum — this dual seals the **0x10 sentinel factory** residual and the **composed dual-bag host** that owns NestedHashBag (0x28) + NestedHash (0x14). Unrelated systems co-owned only by partition assignment except through the NestedHash family graph.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only (`Class_00aa05cc_*` from vtbl; `CircularSentinel_Alloc0x10` from family + size).  
- Rejected scaffold VOG_DEBUG_STOP names.  
- Avoided bare `undefined4` in clean (used `uint32_t` / explicit structs).
