# Dual A/B report — W38-AC OWN `aa_00985580` + `aa_00985610`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W38-AC  
**Scope:** VAs `0x00985580`, `0x00985610` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + `get_assembly_context` + callee decompile. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave38_partition_map.md` (W38-AC).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00985580` GfxIndexBufferFactory_PreRestoreDevice_Inferred | **accept-with-gaps** — EAX factory / plain RET / void / 129 B / map@+0x14 + flag0x28 + stride0x20 → `FUN_00743c50` sealed; product PreRestore English **Inferred** |
| `aa_00985610` GfxIndexBufferFactory_PostRestoreDevice | **accept-with-gaps** — EAX factory / plain RET / 0\|hr / 491 B / recreate+callback + product PostResoreDevice string sealed; callback-host English residual |

**Terminal coverage:** false (no Launcher / runtime / bit-exact Confirmed).

---

## VA `0x00985580` — sealed facts

1. **Body:** `0x00985580`–`0x00985601` exclusive (**129 B** / `0x81`; pad `CC`×15 then `FUN_00985610`).
2. **ABI:** **EAX=factory\***, plain **`RET`** (`C3` @ `0x00985600`); void (parent does not consume EAX). **Not** ECX-thiscall. Decompiler `in_EAX` correct; **bytes win** on ESI formal into callee.
3. **Semantics:** Index-buffer factory **pre-Reset / device-lost release**:
   - Map sentinel @ `factory+0x14`; MSVC RB in-order walk (`is_nil` @ node `+0x21`).
   - Skip when `(flags@node+0x0C & 0x28) != 0`.
   - Else slots `[node+0x14, node+0x18)` stride **0x20**: `ESI=*slot; FUN_00743c50()` unlock-all + COM Release + clear + stats (`gfxDeviceIB.cpp`).
4. **Classification:** worker.
5. **Callers (1):** `FUN_0075eff0` (`GfxDevice_Reset`) @ `0x0075f0dc` — shutdown cascade: `MOV EAX,[EBP+0x750]; CALL` between texture-factory pre and VB-factory pre.
6. **Callees:** `FUN_00743c50` only.
7. **Name:** `GfxIndexBufferFactory_PreRestoreDevice_Inferred` (Ghidra `FUN_00985580`; **Inferred** method plate from Reset cascade + PostRestore twin). Reject scaffold `Named_CalleeOf_Named_gfxDevice_00985580`.
8. **Decompile ≡ bytes** for CF/map walk; **bytes win** on ESI into release leaf.  
   Full hex: raw W38-AC append (129 B).

### Gaps

- Product method English (PreRestoreDevice vs OnLostDevice / ReleaseDeviceObjects).  
- Flag `0x28` product meaning.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00985580_GfxIndexBufferFactory_PreRestoreDevice_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00985580_GfxIndexBufferFactory_PreRestoreDevice_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00985580_FUN_00985580.md` |
| Annotated | `docs/reconstruction/raw/aa_00985580_FUN_00985580.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GfxIndexBufferFactory_PreRestoreDevice_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00985580.cpp` |
| Function | `docs/reconstruction/functions/aa_00985580_FUN_00985580.md` |
| Function named | `docs/reconstruction/functions/aa_00985580_GfxIndexBufferFactory_PreRestoreDevice_Inferred.md` |

---

## VA `0x00985610` — sealed facts

1. **Body:** `0x00985610`–`0x009857fb` exclusive (**491 B** / `0x1EB`; pad `CC`×5 then `FUN_00985800`).
2. **ABI:** **EAX=factory\***, plain **`RET`**; returns **0** success / **HRESULT `<0`** soft-fail (ESI passthrough from create). Hard path: `raise(0x16)` + `ExitProcess(3)` when errReport code `==3`. **Not** ECX-thiscall.
3. **Semantics:** Product **PostRestoreDevice** (string typo *PostResoreDevice*) on index buffers:
   - Same map @ `factory+0x14`, flag gate `0x28`, stride **0x20**.
   - Per slot: `EDI=*slot`; `FUN_00743cd0(count@+4, usage@+8, is32=(*(+0x10)==4))` recreate D3D IB.
   - On create fail: `FUN_0076d1b0(gfxIndexBufferFactory.cpp, 0x180, "Failed PostResoreDevice() on Index Buffers")`; soft return hr or hard abort.
   - Secondary tree @ `slot+8` (`is_nil@+0x11`): optional RestoreSurfaceCallback via `*(host+0x20)` vtbl[0]; fail → format + `vog_LogMessage` line **400** (non-fatal).
4. **Classification:** worker.
5. **Callers (1):** `FUN_0075eff0` (`GfxDevice_Reset`) @ `0x0075f281` — post-Reset rebuild; `TEST EAX,EAX; JGE` else parent logs `"Failed to Reset() device on IB Factory"` @ gfxDevice.cpp `0x236`.
6. **Callees:** `FUN_00743cd0`, `FUN_0076d1b0`, `FUN_0076cec0`, `vog_LogMessage`, `fopen`/`fprintf`/`fclose`, `raise`, `ExitProcess`.
7. **Name:** `GfxIndexBufferFactory_PostRestoreDevice` (Ghidra `FUN_00985610`; product string sealed). Reject scaffold `Named_gfxIndexBufferFactory_00985610` as sole plate.
8. **Decompile ≡ bytes** for CF/strings/returns; **bytes win** on EDI into create leaf + soft-fail ESI return.  
   Full hex: raw W38-AC append (491 B).

### Gaps

- Callback host / secondary-tree product English.  
- Nested `FUN_00743cd0` pool/usage mapping (not OWN).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00985610_GfxIndexBufferFactory_PostRestoreDevice.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00985610_GfxIndexBufferFactory_PostRestoreDevice.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00985610_FUN_00985610.md` |
| Annotated | `docs/reconstruction/raw/aa_00985610_FUN_00985610.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GfxIndexBufferFactory_PostRestoreDevice.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00985610.cpp` |
| Function | `docs/reconstruction/functions/aa_00985610_FUN_00985610.md` |
| Function named | `docs/reconstruction/functions/aa_00985610_GfxIndexBufferFactory_PostRestoreDevice.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00985580` | Port as **IB factory pre-Reset release**: **EAX=factory**, plain RET, void. Walk map@`+0x14`; honor flag gate `0x28` and stride **0x20**; call device-IB release with **object in ESI** (not stack). Do **not** recreate or touch VB factory here. |
| `00985610` | Port as **IB factory PostRestoreDevice**: **EAX=factory**, plain RET, return **0/hr**. Recreate via device-IB create leaf; soft-fail returns create HRESULT; hard-fail only on errReport code 3. Callback failures log-only. Do **not** implement VB PostRestore (`00986570`) here. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x0075eff0` | `GfxDevice_Reset` (W37-N) — sole parent of both |
| `0x00743c50` | gfxDeviceIB release leaf (ESI) |
| `0x00743cd0` | gfxDeviceIB recreate-on-device (EDI) |
| `0x009864e0` / `0x00986570` | VB factory Pre/Post twins (W38-AD/AE) |
| `0x00985f40` | texture-factory pre (Reset shutdown) |
| `0x0096e8e0` | texture-factory post (Reset rebuild) |

Together they close the **index-buffer factory Pre/Post RestoreDevice** residual pair called from `GfxDevice_Reset` shutdown/rebuild.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers + assembly_context at call sites + callee decompile. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates without evidence; PreRestore **`_Inferred`**; PostRestore sealed by product string (typo preserved in quotes).  
- Avoided bare `undefined4` in clean contracts (`uint32_t` / explicit offsets).
