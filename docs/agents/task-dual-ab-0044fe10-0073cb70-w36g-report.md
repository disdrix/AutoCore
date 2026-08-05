# Dual A/B report — W36-G OWN `aa_0044fe10` + `aa_0073cb70`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W36-G  
**Scope:** VAs `0x0044fe10`, `0x0073cb70` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + callee/neighbor decompile. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave36_partition_map.md` (W36-G).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0044fe10` AnmTrackEvents_UnserializeOneEvent_Inferred | **accept** — EDI reader + NestedHash bag lookup + factory/unserialize + fail −1 sealed (86 B); product event class residual only |
| `aa_0073cb70` HostEDI_VecCursor44_GetOrCreate_PalDiffMap14c_Inferred | **accept-with-gaps** — EDI cursor-vector get-or-create + 0x14c/0xC4 + PalDiffMap.fx sealed (506 B); product host English + unowned material pipeline open |

---

## VA `0x0044fe10` — sealed facts

1. **Body:** `0x0044fe10`–`0x0044fe65` (**86 B** / `0x56`; pad `CC` then next).
2. **ABI:** stack out-param `void **out_event`; **EDI = stoChunkReader\*** register formal; plain **`RET`** after `ADD ESP,8`.
3. **Semantics:**
   - `MOV ESI,EDI` → `FUN_0076a900()` reads FOURCC/key.
   - `FUN_0044fee0()` NestedHash0x10 static once-get (W35-E) → ESI=bag.
   - `FUN_0046c1b0` lookup by key → node.
   - Second once-get; if node == `*(bag+8)` sentinel → null object.
   - Else thiscall factory `node[+0xC]`; store to `*out_event`.
   - If object: `PUSH EDI`; thiscall `obj[+4]`; return status. Else **`0xffffffff`**.
4. **Classification:** **worker** (per-event unserialize / factory dispatch).
5. **Callers (1):** `FUN_00987750` @ `0x00987987` — product `anmTrackEvents.cpp`, `"anmTrackEvents: Error Reading event!"`.
6. **Callees:** `FUN_0076a900`, `FUN_0044fee0` ×2, `FUN_0046c1b0`; virtual factory / unserialize.
7. **Name:** `AnmTrackEvents_UnserializeOneEvent_Inferred` (Ghidra `FUN_0044fe10`; **Inferred**). Reject bare scaffold-only plate without structural semantics.
8. **Family:** sole consumer of W35-E NestedHash once-get `0044fee0`; NestedHash lookup owned W36-B.
9. **Decompile ≡ bytes** for EDI/key/lookup/sentinel/fail.  
   Full hex: `83ec08568bf7e8e5aa310089442404e8bc0000008bf08d4c24048d442408e87dc30100e8a80000008b4c24083b48085e7405ff510ceb0233c085c08b4c240c8901740c8b10578bc8ff520483c408c383c8ff83c408c3`

### Gaps

- Product C++ class of factory node / event object.  
- Factory key-arg shape (decompiler vs pure thiscall bytes).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0044fe10_AnmTrackEvents_UnserializeOneEvent_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0044fe10_AnmTrackEvents_UnserializeOneEvent_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0044fe10_FUN_0044fe10.md` |
| Annotated | `docs/reconstruction/raw/aa_0044fe10_FUN_0044fe10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AnmTrackEvents_UnserializeOneEvent_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0044fe10.cpp` |
| Function | `docs/reconstruction/functions/aa_0044fe10_FUN_0044fe10.md` |
| Function named | `docs/reconstruction/functions/aa_0044fe10_AnmTrackEvents_UnserializeOneEvent_Inferred.md` |

---

## VA `0x0073cb70` — sealed facts

1. **Body:** `0x0073cb70`–`0x0073cd69` (**506 B** / `0x1FA`; pad `CC` then twin `FUN_0073cd70`).
2. **ABI:** **EDI = host object** (register formal; prologue does not save EDI); no stack args; returns **0x14c host pointer**; SEH `LAB_009b2fcf`; exits `ADD ESP,0x64; RET`.
3. **Semantics:** get-or-create into EDI vector:
   - **Hit:** if `cursor(+0x44) < count(begin+0x4c,end+0x50)` return `vec[cursor++]`.
   - **Miss:** `new(0x14c)+FUN_00764030`, `new(0xC4)+FUN_00748960`, load **`PalDiffMap.fx`**, resolve **`DiffuseMap`**, optional 0x10×0x10 fmt **0x16**, material local + vcall mat**[+0x5c]**, **`FUN_007647c0(host,mat)`**, grow **`FUN_004367f0` on +0x48**, store, `cursor++`, dtor local, return host.
4. **Host table span:** ≥ **0x54** (through `+0x50` end pointer).
5. **Classification:** **worker** (get-or-create factory).
6. **Callers (2):** `FUN_0073d020` @ `0x0073d025`, `FUN_0073d0a0` @ `0x0073d0a5`.
7. **Callees:** `operator_new`, `FUN_00764030`, `FUN_00748960`, FX/tex helpers, `FUN_007647c0`, `FUN_004367f0`, `FUN_00457a00`.
8. **Name:** `HostEDI_VecCursor44_GetOrCreate_PalDiffMap14c_Inferred` (Ghidra `FUN_0073cb70`; **Inferred** structural). Product strings seal material path; host class English open.
9. **Family:** related 0x14c/0xC4 construction to W35-E `HostPtrTable12_Bootstrap_EDI` (bootstrap once vs cursor vector reuse).
10. **Decompile ≡ bytes** for cursor/vector/sizes/strings/RET. Full 506 B hex in raw W36-G append.

### Gaps

- Product host / 0x14c / 0xC4 class English.  
- Unowned material/FX helper full contracts (W36-H/L siblings).  
- Twin `0x0073cd70` not owned.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0073cb70_HostEDI_VecCursor44_GetOrCreate_PalDiffMap14c_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0073cb70_HostEDI_VecCursor44_GetOrCreate_PalDiffMap14c_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0073cb70_FUN_0073cb70.md` |
| Annotated | `docs/reconstruction/raw/aa_0073cb70_FUN_0073cb70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/HostEDI_VecCursor44_GetOrCreate_PalDiffMap14c_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0073cb70.cpp` |
| Function | `docs/reconstruction/functions/aa_0073cb70_FUN_0073cb70.md` |
| Function named | `docs/reconstruction/functions/aa_0073cb70_HostEDI_VecCursor44_GetOrCreate_PalDiffMap14c_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0044fe10` | Port as **per-event unserialize**: stack `out_event**` + **EDI** chunk reader. NestedHash0x10 once-get + lookup by FOURCC/key; sentinel miss → null + return **−1**. Success → factory then obj vtbl[+4] with reader. Do **not** treat as free NestedHash API. Pair with W35-E once-get and W36-B lookup. |
| `0073cb70` | Port as **EDI host cursor-vector get-or-create** of **0x14c** hosts (span ≥ 0x54), not ECX-thiscall, not one-shot bootstrap. Include PalDiffMap.fx / DiffuseMap miss path and `FUN_007647c0` wire. Expect wrappers to re-bind DiffuseMap + vcall **+0x18**. Do not invent Multikill product plate from blend global alone. |

Shared: both are **EDI register-formal workers** with sealed product strings (anmTrackEvents caller vs PalDiffMap.fx body). Co-owned only by W36-G partition assignment; different subsystems.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers + callee decompile. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names; caller/body strings used where sealed.  
- Rejected bare scaffold-only plate for `0044fe10`; kept anmTrackEvents role from sole caller.  
- Avoided bare `undefined4` in clean (used `uint32_t` / explicit pointers).
