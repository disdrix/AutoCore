# Dual A/B report — W38-AD OWN `aa_00985f40` + `aa_009864e0`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W38-AD  
**Scope:** VAs `0x00985f40`, `0x009864e0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + xrefs/callers (+ callee/parent decompiles for context). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave38_partition_map.md` (W38-AD).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00985f40` PoolHost_ForEachTrackedNested_CallVtable0C_Inferred | **accept-with-gaps** — EAX host / 75 B / double ptr-vector walk / thiscall vtbl+0xC / sole Device Reset site sealed; vtbl method + container product English open |
| `aa_009864e0` GfxVertexBufferFactory_PreResetReleaseAll_Inferred | **accept-with-gaps** — EAX factory / 129 B / tree@+0x14 / flag@+0xE / stride 0x20 / ESI→FUN_007465c0 / sole Device Reset site sealed; flag-bit + full slot plate English open |

**Terminal coverage:** false (no Launcher / runtime / bit-exact Confirmed).

---

## VA `0x00985f40` — sealed facts

1. **Body:** `0x00985f40`–`0x00985f8a` inclusive (**75 B** / `0x4B`); pad `CC` @ `0x00985f8b+`.
2. **ABI:** **EAX = host\***; no stack formals; bare **`C3`**; void. Prologue saves ECX/EBX/EBP/ESI/EDI.
3. **Semantics:** PoolHost **track** walk (pre-reset notify):
   - Outer: ptr vector `[host+4, host+8)`.
   - Per container: nested ptr vector `[c+8, c+0xC)`; skip if begin==0 or `(end-begin)>>2==0`.
   - Per object: **thiscall** `obj->vtbl[+0xC]()` — bytes `8B 0E; 8B 01; FF 50 0C` (decompiler omits ECX).
4. **Classification:** worker (pre-reset notify walk).
5. **Callers / xrefs:** **1** — `FUN_0075eff0` (gfxDevice Device Reset) @ `0x0075f0d1` with `EAX = *(device+0x73C)`.
6. **Callees:** indirect vtbl only.
7. **Related:** GfxDevice ctor slot `+0x73C` / `DAT_00d1f624` PoolHost seed (W35-R); PoolHost track push (W33-R); sequence before IB/VB factory pre-reset.
8. **Name:** `PoolHost_ForEachTrackedNested_CallVtable0C_Inferred` (Ghidra `FUN_00985f40`; **Inferred** structural). Reject scaffold `Named_CalleeOf_Named_gfxDevice_*`.
9. **Decompile ≡ raw CF skeleton**; **bytes win** on thiscall ECX.

### Gaps

- Product English for vtbl+0xC.  
- Tracked container class demangle.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00985f40_PoolHost_ForEachTrackedNested_CallVtable0C_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00985f40_PoolHost_ForEachTrackedNested_CallVtable0C_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00985f40_FUN_00985f40.md` |
| Annotated | `docs/reconstruction/raw/aa_00985f40_FUN_00985f40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PoolHost_ForEachTrackedNested_CallVtable0C_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00985f40.cpp` |
| Function | `docs/reconstruction/functions/aa_00985f40_FUN_00985f40.md` |
| Function named | `docs/reconstruction/functions/aa_00985f40_PoolHost_ForEachTrackedNested_CallVtable0C_Inferred.md` |

---

## VA `0x009864e0` — sealed facts

1. **Body:** `0x009864e0`–`0x00986560` inclusive (**129 B** / `0x81`); pad `CC`×15 then `FUN_00986570` (VB PostRestore).
2. **ABI:** **EAX = factory\***; no stack formals; bare **`C3`**; void. Per-slot **ESI = \*(dword\*)slot** before callee.
3. **Semantics:** VB factory **pre-reset release-all**:
   - Tree sentinel `@factory+0x14`; MSVC successor with **isnil @ node+0x21**.
   - Skip node if `(node[+0xE] & 0x28) != 0` (`F6 47 0E 28`).
   - Range `[node+0x14, node+0x18)` stride **0x20**; `FUN_007465c0` (gfxDeviceVB unlock-all + COM Release + `DAT_00d1f614` stats).
4. **Decompiler bug:** omits `MOV ESI,[slot]` before `FUN_007465c0`.
5. **Classification:** worker (factory pre-reset release-all).
6. **Callers / xrefs:** **1** — `FUN_0075eff0` @ `0x0075f0e7` with `EAX = *(device+0x74C)`.
7. **Callees:** `FUN_007465c0`.
8. **Related:** GfxDevice ctor slot `+0x74C` (W35-R); IB twin `FUN_00985580`→`FUN_00743c50`; PostRestore sibling `FUN_00986570` (`gfxVertexBufferFactory.cpp` strings).
9. **Name:** `GfxVertexBufferFactory_PreResetReleaseAll_Inferred` (Ghidra `FUN_009864e0`; **Inferred** from parent path + callee/sibling strings). Reject scaffold `Named_CalleeOf_Named_gfxDevice_*`.
10. **Decompile ≡ raw CF skeleton**; **bytes win** on ESI + flag@+0xE.

### Gaps

- Product English for flag bits `0x28`.  
- Full 0x20 slot plate beyond +0 VB*.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_009864e0_GfxVertexBufferFactory_PreResetReleaseAll_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_009864e0_GfxVertexBufferFactory_PreResetReleaseAll_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_009864e0_FUN_009864e0.md` |
| Annotated | `docs/reconstruction/raw/aa_009864e0_FUN_009864e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GfxVertexBufferFactory_PreResetReleaseAll_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_009864e0.cpp` |
| Function | `docs/reconstruction/functions/aa_009864e0_FUN_009864e0.md` |
| Function named | `docs/reconstruction/functions/aa_009864e0_GfxVertexBufferFactory_PreResetReleaseAll_Inferred.md` |

---

## Shared Device Reset context (not owned)

Parent `FUN_0075eff0` (`C:\vog\1_code\palantir\palantir\graphics\gfxDevice.cpp`) after `"Beginning shutdown for Device Reset()"`:

| Order | CALL | EAX host | Role |
|---|---|---|---|
| 1 | **`FUN_00985f40`** (OWN) | `device+0x73C` | PoolHost track → vtbl+0xC notify |
| 2 | `FUN_00985580` (W38-AC) | `device+0x750` | IB factory pre-reset release-all |
| 3 | **`FUN_009864e0`** (OWN) | `device+0x74C` | VB factory pre-reset release-all |
| … | other factories | … | … |
| later | D3D `Reset` + PostRestore (`00985610` IB / `00986570` VB) | … | recreate |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00985f40` | Port as **pre-reset notify walk** on PoolHost track host: double vector; **thiscall** vtbl+0xC per nested object. **EAX=host** (`device+0x73C`). Do **not** treat as COM factory release or tree walk. |
| `009864e0` | Port as **VB factory pre-reset release-all**: map tree @+0x14; skip `(flags@+0xE & 0x28)`; slots stride **0x20**; `ESI=*slot` → unlock-all+Release (`FUN_007465c0`). **EAX=factory** (`device+0x74C`). Do **not** implement PostRestore/HRESULT recreate here. |
| Pair with | GfxDevice ctor `0x0075f7f0` (W35-R); Device Reset parent `0x0075eff0`; IB twin `0x00985580`; VB PostRestore `0x00986570`; PoolHost acquire `0x00986070` (W33-R); gfxDeviceVB `0x007465c0`. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ xrefs / callers / context decompiles). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** (W38-AD sections).  
- No invented product names without evidence; `_Inferred` structural names only.  
- Pattern: Device Reset pre-shutdown pair — PoolHost nested vtbl notify + VB factory tree release-all.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
