# Dual A/B report — W36-M OWN `aa_00459750` + `aa_0046a260`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W36-M  
**Scope:** VAs `0x00459750`, `0x0046a260` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave36_partition_map.md` (W36-M).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00459750` AnmTrackMaster_Unserialize_Inferred | **accept-with-gaps** — thiscall/RET4/tags/resize site/returns sealed; nested duals + full object map open |
| `aa_0046a260` StdUninitFillN_Elem28_CountEcx_Inferred | **accept** — 34 B leaf fill-n; ECX count / EAX dest / EBX template; stride 0x1c; null gate sealed |

---

## VA `0x00459750` — sealed facts

1. **Body:** `0x00459750`–`0x00459a5a` inclusive (**779 B** / `0x30B`; pad `CC` then next).
2. **ABI:** **ECX=`this`**, stack **`ctx*`**, **`RET 4`**. Returns **0** / **0xFFFFFFFE** / **0xFFFFFFFF**.
3. **Semantics:** Animation **track-master chunk unserialize** (`anmTrackMaster_inl.h`):
   - `stoChunkReader_EnterChunkScope`; accept host tags **PBAM** (`0x5042414D`) or **TRAK** (`0x5452414B`); else log path → fail.
   - Dual I/O via **`ctx+0x4044`** (legacy `FUN_004*` vs modern `FUN_007*`).
   - Type fourCC at **`this+0x10`**: **EFCT** (`0x45464354`) if match `0x4B455556`, else **SKEL** (`0x534B454C`).
   - String hashes via `FUN_00989e00` → **`this+0x14` / `+0x18`**.
   - Resize **Pod28** vector at **`this+0x1C`** via sealed **`StdVector_Resize_Pod28`** (`FUN_0045c4b0` @ `0x004599bf`).
   - Optional element path **`FUN_0045dd60`** when count &gt; 0.
4. **Classification:** worker.
5. **Callers:** no direct CALL; **DATA** xref **`0x00aa3d54`** (fn-ptr / vtable).
6. **Callees:** `stoChunkReader_EnterChunkScope`, `FUN_0045c4b0`, `FUN_0045dd60`, dual I/O set, `FUN_0044c370`/`FUN_0044c340`, `FUN_00989e00`, `vog_LogMessage`, `basic_string` ctor/dtor, `FUN_00769e40`, …
7. **Name:** `AnmTrackMaster_Unserialize_Inferred` (Ghidra `FUN_00459750`; **Inferred** structural). **Reject** inventing product demangle.
8. **Decompile vs bytes:** CF matches; **bytes win** on tag immediates, resize site (`ADD EBX,0x1C` + `SUB ESP,0x1C` + call), dual `RET 4` epilogs. Full hex: raw W36-M append.

### Gaps

- Product/PDB demangle English.  
- Full track-object field map beyond sealed offsets.  
- Nested duals (`FUN_0045dd60`, I/O readers, hash) + DATA table owner unowned.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00459750_AnmTrackMaster_Unserialize_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00459750_AnmTrackMaster_Unserialize_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00459750_FUN_00459750.md` |
| Annotated | `docs/reconstruction/raw/aa_00459750_FUN_00459750.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AnmTrackMaster_Unserialize_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00459750.cpp` |
| Function | `docs/reconstruction/functions/aa_00459750_FUN_00459750.md` |
| Function named | `docs/reconstruction/functions/aa_00459750_AnmTrackMaster_Unserialize_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_00459750.md` |

---

## VA `0x0046a260` — sealed facts

1. **Body:** `0x0046a260`–`0x0046a281` inclusive (**34 B** / `0x22`; pad `CC` then next @ `0x0046a290`).
2. **ABI:** **ECX=`count`**, **EAX=`dest*`**, **EBX=`template*`**; bare **`RET`**. Decompiler omits dest/tmpl formals — **bytes + callers win**.
3. **Semantics:** MSVC-style uninit fill-n for POD T size **0x1c**:
   - Early-out if count==0 (`TEST ECX` / `JBE` unsigned).
   - Loop: if dest non-null, **`REP MOVSD`** 7 dwords from template; always `dest += 0x1c`; count--.
   - Template pointer not advanced (EBX held; ESI reloaded each iter).
4. **Classification:** leaf worker — 0 callees.
5. **Callers (2 funcs / 3 sites):** `FUN_00469c80` @ `0x00469cdb`; `FUN_00469f50` (`StdVector_InsertN_Elem28_ValueEdx_Inferred`, W34-Q) @ `0x0046a093`, `0x0046a19e`.
6. **Callees:** none.
7. **Name:** `StdUninitFillN_Elem28_CountEcx_Inferred` (Ghidra `FUN_0046a260`; **Inferred** structural). **Reject** scaffold `Named_CalleeOf_*assPackManag*`.
8. **Decompile vs bytes:** CF matches fill-n; **bytes win** on three-register formals + `REP MOVSD`. Full hex: raw W36-M append.

### Gaps

- Product/MSVC demangle English.  
- Concrete POD T identity.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0046a260_StdUninitFillN_Elem28_CountEcx_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0046a260_StdUninitFillN_Elem28_CountEcx_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0046a260_FUN_0046a260.md` |
| Annotated | `docs/reconstruction/raw/aa_0046a260_FUN_0046a260.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdUninitFillN_Elem28_CountEcx_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0046a260.cpp` |
| Function | `docs/reconstruction/functions/aa_0046a260_FUN_0046a260.md` |
| Function named | `docs/reconstruction/functions/aa_0046a260_StdUninitFillN_Elem28_CountEcx_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_0046a260.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00459750` | Port as **track-master chunk unserialize**: **thiscall** + stack **ctx**, **`RET 4`**. Accept **PBAM\|TRAK**; dual I/O flag **ctx+0x4044**; type **EFCT\|SKEL** @ **+0x10**; hashes @ **+0x14/+0x18**; resize **Pod28** vector @ **+0x1C** via sealed resize. Server may collapse dual I/O to one reader. Do **not** treat as bare STL resize or invent no-cleanup cdecl. |
| `0046a260` | Port as **elem-28 uninit fill-n**: **ECX=count**, **EAX=dest***, **EBX=template***, bare RET. Null-safe store + always advance 0x1c (`REP MOVSD` ×7). Do **not** invent stack formals or conflate with `FUN_0045f150` (different ABI) or `Pod28_FillAssign_Forward` (`0045efe0`, range form). |
| Shared | Closes W36-M OWN pair: **domain unserialize parent** of sealed Pod28 resize + **ValueEdx insert-n fill-n leaf**. Not algorithmically related to each other beyond wave co-ownership of residuals under the elem-28 / track-master chain. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x0045c4b0` | `StdVector_Resize_Pod28` (W35-M) — sole resize callee of `00459750` |
| `0x0045dd60` | element load after resize (unowned) |
| `0x00469f50` | `StdVector_InsertN_Elem28_ValueEdx_Inferred` (W34-Q) — parent of `0046a260` |
| `0x00469c80` | single-append parent of `0046a260` |
| `0x0045f150` | sibling fill-n CountEax ABI (W35-L) |
| `0x0046a240` | prior symbol `StdCopyBackward_Elem28` (W35-L); pad then `0046a260` |
| `0x0045efe0` | assign-fill range cousin (W35-M) |
| `0x00aa3d54` | DATA fn-ptr slot → `00459750` |

Closes W36-M OWN pair: track-master unserialize residual + elem-28 CountEcx fill-n leaf under ValueEdx insert-n.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names; `_Inferred` structural names only.  
- Rejected long Named_CalleeOf / demangle-guess aliases.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit `Elem28` / `Pod28`).
