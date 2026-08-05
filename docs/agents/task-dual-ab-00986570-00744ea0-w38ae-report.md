# Dual A/B report — W38-AE OWN `aa_00986570` + `aa_00744ea0`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W38-AE  
**Scope:** VAs `0x00986570`, `0x00744ea0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + `get_function_by_address` + callers/xrefs + `get_assembly_context` + callee decompile. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave38_partition_map.md` (W38-AE).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00986570` GfxVertexBufferFactory_PostRestoreDevice_Inferred | **accept-with-gaps** — EAX-this / plain RET / HRESULT / map+0x14 / flag&0x28 skip / recreate+callbacks / EH_Abort sealed; VB C++ types + demangle open |
| `aa_00744ea0` NDResDepHost_RemoveResourceId_Inferred | **accept-with-gaps** — thiscall ECX / pId+recurse / RET 8 / bool AL / erase-only maps+vector / cascade gate sealed; product host English open |

**Terminal coverage:** false (no Launcher / runtime / bit-exact Confirmed).

---

## VA `0x00986570` — sealed facts

1. **Body:** `0x00986570`–`0x00986752` exclusive (**482 B** / `0x1E2`; pad `CC`×14 then next).
2. **ABI:** **EAX=`factory*`**, no stack args, plain **`RET`** (`C3`); returns **HRESULT** (0 / negative). Decompiler `in_EAX` correct — **not** ECX-thiscall.
3. **Semantics:** `gfxVertexBufferFactory.cpp` **PostRestoreDevice** (retail string typo `PostResoreDevice`):
   - Map head `*(this+0x14)`; tree isnil `@+0x21`.
   - Skip pools with `(node+0xE & 0x28) != 0`.
   - Slot range `[node[5], node[6])` stride **0x20**.
   - `FUN_00746640(vb, count@+0xC, stride@+8, usage@+4, fvf=0)` recreate.
   - Fail → errReport line `0x194`; choice≠3 return hr; else EH_Abort (`VOGCRASH.txt` / `raise(0x16)` / `ExitProcess(3)`).
   - Surface-callback map at `slot[2]`; vtbl[0] on host `@payload+0x1c`; fail **log-only** line `0x1a4`.
4. **Classification:** worker.
5. **Callers (1):** `FUN_0075eff0` (`gfxDevice.cpp` device Reset) @ `0x0075f2a1` — fail plate `"Failed to Reset() device on VB Factory"`.
6. **Callees:** `FUN_00746640`, `FUN_0076d1b0`, `FUN_0076cec0`, `vog_LogMessage`, `fopen`/`fprintf`/`fclose`/`raise`/`ExitProcess`.
7. **Name:** `GfxVertexBufferFactory_PostRestoreDevice_Inferred` (Ghidra `FUN_00986570`; **Inferred** from product path + sealed string + Reset caller). **Reject** sole scaffold `Named_gfxVertexBufferFactory_00986570`.
8. **Family:** PreRestore sibling `FUN_009864e0` (W38-AD); IB PostRestore twin `FUN_00985610`.
9. **Decompile vs bytes:** CF ≡ raw; **bytes win** on EAX-this.  
   Full hex: raw W38-AE append (482 B).

### Gaps

- Full VB / pool map C++ types beyond used fields.  
- Unowned `FUN_00746640` dual (CreateVertexBuffer path).  
- Exact product demangle beyond sealed error string.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00986570_GfxVertexBufferFactory_PostRestoreDevice_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00986570_GfxVertexBufferFactory_PostRestoreDevice_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00986570_FUN_00986570.md` |
| Annotated | `docs/reconstruction/raw/aa_00986570_FUN_00986570.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GfxVertexBufferFactory_PostRestoreDevice_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00986570.cpp` |
| Function | `docs/reconstruction/functions/aa_00986570_FUN_00986570.md` |
| Function named | `docs/reconstruction/functions/aa_00986570_GfxVertexBufferFactory_PostRestoreDevice_Inferred.md` |

---

## VA `0x00744ea0` — sealed facts

1. **Body:** `0x00744ea0`–`0x007450ae` exclusive (**526 B** / `0x20E`; pad `CC` then next).
2. **ABI:** **`__thiscall`**; **ECX=`host*`**; stack **`int* pId`**, **`char recurse`**; **`RET 8`** (`C2 08 00`); returns **bool AL** (init 1 / fail 0).
3. **Semantics:** **Remove resource id** from ND dependency host (erase-only; no insert):
   - Key box via `FUN_00426f60(*pId → local)`.
   - Map object **`this+0x1c`** (head field **`this+0x20`**): equal_range count; if **==1** and `node[6]==*(this+4)` → `FUN_0044d630` erase; recount; if **≠0** → **return false**.
   - Linear vector **`[this+0x50, this+0x54)`**: find `*pId` → `FUN_00744cc0` (optional `DAT_00d1f050` ref--).
   - Equal_range walk map head **`*(this+0x14)`**; for each node, equal_range map head **`*(this+0x20)`**; if `entry[6]==*pId` erase; if **recurse≠0** self-call `(this, &node[6], 1)`.
   - Map nodes: key `@[3]`, payload `@[6]`, isnil `@+0x25`.
4. **Classification:** worker.
5. **Callers (4):** self @ `0x00745078` (recurse=1); `NDXml_LoadDocumentFromPath` @ `0x007b6df5` (0); `FUN_007b7420` @ `0x007b7524` (0); `FUN_009701d0` EffEffectSlot_BindByPath @ `0x00970241` (1, after `FUN_00965600`).
6. **Callees:** `FUN_00426f60`, `FUN_0044d920`, `FUN_0044d8c0`, `FUN_0044d630`, `FUN_0044dc00`, `FUN_00744cc0`, self.
7. **Name:** `NDResDepHost_RemoveResourceId_Inferred` (Ghidra `FUN_00744ea0`; **Inferred** from erase CF + `DAT_00d1f050` host wiring). **Reject** `Named_CalleeOf_Named_CalleeOf_CVOGTacArc_InitializeMesh_00744ea0`.
8. **Decompile vs bytes:** CF ≡ raw; **bytes win** on `RET 8` + bool AL.  
   Full hex: raw W38-AE append (526 B).

### Gaps

- Product/PDB host class English.  
- Precise typed identity of maps @+0x14 vs @+0x1c.  
- Cascade policy product name for recurse flag.  
- Unowned map helper duals (`FUN_0044d630` family).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00744ea0_NDResDepHost_RemoveResourceId_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00744ea0_NDResDepHost_RemoveResourceId_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00744ea0_FUN_00744ea0.md` |
| Annotated | `docs/reconstruction/raw/aa_00744ea0_FUN_00744ea0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDResDepHost_RemoveResourceId_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00744ea0.cpp` |
| Function | `docs/reconstruction/functions/aa_00744ea0_FUN_00744ea0.md` |
| Function named | `docs/reconstruction/functions/aa_00744ea0_NDResDepHost_RemoveResourceId_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00986570` | Client graphics only: after D3D device Reset, recreate DEFAULT-pool VBs (**EAX=factory**). Honor flag mask **0x28** skip; propagate HRESULT; surface callbacks log-only. Do **not** ECX-thiscall. |
| `00744ea0` | Port as **dependency unbind**: thiscall host + `int* id` + recurse char, **RET 8**, bool. Erase-only; fail if primary map still has equal_range hits after optional single owned erase. Cascade when recurse≠0. Wired from NDXml / FX bind notify via `DAT_00d1f050+0x64` host. |
| Shared | Unrelated domains (VB Reset vs res-dep host); co-owned only as W38-AE partition pair. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x0075eff0` | gfxDevice Reset orchestrator (caller of VB PostRestore) |
| `0x009864e0` | VB factory PreRestore (W38-AD) |
| `0x00985610` | IB factory PostRestore twin |
| `0x00746640` | CreateVertexBuffer / recreate helper (`gfxDeviceVB.cpp`) |
| `0x009701d0` | EffEffectSlot_BindByPath (W37-Q) — recurse=1 caller |
| `0x007b6c70` | NDXml_LoadDocumentFromPath — recurse=0 caller |
| `0x00d1f050` | `DAT_00d1f050` NDResourceCache global |
| `0x0044d630` | std::map erase |
| `0x0044d920` | equal_range distance/count |
| `0x00744cc0` | vector remove + optional cache ref-- |

Closes W38-AE OWN pair: VB factory **PostRestoreDevice** left open under device Reset chain + ND res-dep host **RemoveResourceId** left open under NDXml / effect-slot notify paths.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names; `_Inferred` structural names only.  
- Rejected long Named_CalleeOf / bare Named_gfxVertexBufferFactory scaffold aliases as sole plates.  
- Distinguished EAX-this VB PostRestore from ECX-thiscall dep host.  
- Distinguished erase-only dep remove from registration/insert.  
- Terminal coverage: **false** always.
