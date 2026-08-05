# Dual A/B report — W38-AA OWN `aa_009686e0` + `aa_00968720`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W38-AA  
**Scope:** VAs `0x009686e0`, `0x00968720` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + `get_function_by_address` + callers/xrefs/callees + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave38_partition_map.md` (W38-AA).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_009686e0` GfxBufferedViews_ReleaseDeviceTextures_Inferred | **accept-with-gaps** — 53 B list walk + thiscall release gate + sole Reset-shutdown caller sealed; field English + nested `FUN_0096c8e0` open |
| `aa_00968720` GfxBufferedViews_RecreateRenderTargets_Inferred | **accept-with-gaps** — 273 B list ReCreate/Release + product plates + always-0 return sealed; flag English + dead parent fail plate + nested ReCreate open |

---

## VA `0x009686e0` — sealed facts

1. **Body:** `0x009686e0`–`0x00968715` exclusive (**53 B** / `0x35`; final `C3` @ `0x00968714`; pad `CC`×11 then `FUN_00968720`). Ghidra end `00968714` — **bytes win**.
2. **ABI:** No stack formals; plain **`RET`** (`C3`); ESI push/pop scratch.
3. **Semantics:** Walk circular list head **`DAT_00d1ee30`** (gfxBufferedView registry from ctor `FUN_00968a50`):
   - payload = `node[2]` (`+0x08`);
   - `tex = *(view + 0x44)`;
   - if `*(tex + 0x30) == 0`: **thiscall** `FUN_0096c8e0(tex)` (`MOV ECX,EAX; CALL`).
   - Does **not** unlink nodes or destroy views.
4. **Classification:** worker.
5. **Callers (1):** `FUN_0075eff0` (`GfxDevice_Reset`) @ `0x0075f0ec` — **shutdown** chain after IB/VB/Texture factory shutdown helpers.
6. **Callees:** `FUN_0096c8e0` only.
7. **Name:** `GfxBufferedViews_ReleaseDeviceTextures_Inferred` (Ghidra `FUN_009686e0`; **Inferred**). **Reject** scaffold `Named_CalleeOf_Named_gfxDevice_009686e0`.
8. **Decompile ≡ bytes** for CF; **bytes win** on thiscall ECX to release.  
   Full hex: `8b 0d 30 ee d1 00 56 8b 31 3b f1 74 26 8d 49 00 8b 46 08 85 c0 74 16 8b 40 44 83 78 30 00 75 0d 8b c8 e8 d9 41 00 00 8b 0d 30 ee d1 00 8b 36 3b f1 75 dd 5e c3`

### Gaps

- Product English for `view+0x44` / `tex+0x30`.  
- Nested `FUN_0096c8e0` dual (W38-AB owns `0x0096c8e0`).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_009686e0_GfxBufferedViews_ReleaseDeviceTextures_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_009686e0_GfxBufferedViews_ReleaseDeviceTextures_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_009686e0_FUN_009686e0.md` |
| Annotated | `docs/reconstruction/raw/aa_009686e0_FUN_009686e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GfxBufferedViews_ReleaseDeviceTextures_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_009686e0.cpp` |
| Function | `docs/reconstruction/functions/aa_009686e0_FUN_009686e0.md` |
| Function named | `docs/reconstruction/functions/aa_009686e0_GfxBufferedViews_ReleaseDeviceTextures_Inferred.md` |

---

## VA `0x00968720` — sealed facts

1. **Body:** `0x00968720`–`0x00968831` exclusive (**273 B** / `0x111`; final `C3` @ `0x00968830`; pad `CC…`). Ghidra end `00968830` — **bytes win**.
2. **ABI:** No stack formals; SEH `LAB_009b11e5`; **always returns 0** (`XOR EAX,EAX`); plain `RET` after `ADD ESP,0x2C`.
3. **Semantics:** Same list/gate as release twin. For each needing-reset texture:
   - If `!(*(tex+0x2c) & 0x3000)`: thiscall **`FUN_0096cad0`** ReCreate with fields `+0x24/+0x1c/+0x20/+0x34/+0x30/+0xc`; on `<0` log  
     `"Failure on ReCreate() of effTextureImpl %s for gfxBufferedView render target"` at  
     `gfxBufferedView.cpp` line **0xCA**, level 5 — **continue list** (no −1).
   - Else: COM **`Release`** via `(**(tex+0x4c))->vtbl[+8]`.
4. **Classification:** worker.
5. **Callers (1):** `FUN_0075eff0` (`GfxDevice_Reset`) @ `0x0075f2d9` — **rebuild** chain after IB/VB/Texture factory resets; parent fail plate `"Failed to Reset() device on gfxBufferedViews"` is **unreachable** given always-0 return.
6. **Callees:** `FUN_0096cad0`, `FUN_0096a630`, `FUN_0076cec0`, `vog_LogMessage`, IAT `~basic_string`, COM vcall.
7. **Name:** `GfxBufferedViews_RecreateRenderTargets_Inferred` (Ghidra `FUN_00968720`; **Inferred**). **Reject** scaffold `Named_gfxBufferedView_00968720` as single-view plate.
8. **Decompile ≡ bytes** for CF/plates/return-0; product strings confirmed via `read_memory`.  
   Full hex: `64 a1 00 00 00 00 6a ff 68 e5 11 9b 00 50 a1 30 ee d1 00 64 89 25 00 00 00 00 83 ec 20 53 55 8b 28 3b e8 56 57 0f 84 d1 00 00 00 eb 03 8d 49 00 8b 5d 08 85 db 0f 84 b6 00 00 00 8b 4b 44 83 79 30 00 0f 85 a4 00 00 00 8b 41 2c f6 c4 30 75 58 8b 51 0c 8b 71 30 8b 79 34 52 56 8b 71 1c 57 83 ec 08 8b d4 89 32 8b 71 20 89 72 04 8b 51 24 52 e8 3b 43 00 00 85 c0 7d 73 8b 43 44 8b 40 4c 85 c0 8d 48 04 75 05 b9 24 ed d1 00 8d 54 24 14 52 e8 7b 1e 00 00 c7 44 24 38 00 00 00 00 83 78 18 10 72 0f 8b 40 04 eb 0d 8b 49 4c 8b 01 ff 50 08 eb 3a 83 c0 04 50 8d 44 24 14 68 c8 22 aa 00 50 e8 db 46 e0 ff 50 6a 05 68 ca 00 00 00 68 18 23 aa 00 e8 c9 e5 02 00 83 c4 1c 8d 4c 24 14 c7 44 24 38 ff ff ff ff ff 15 f4 62 9c 00 a1 30 ee d1 00 8b 6d 00 3b e8 0f 85 34 ff ff ff 8b 4c 24 30 5f 5e 5d 33 c0 64 89 0d 00 00 00 00 5b 83 c4 2c c3`

### Gaps

- Product English for flag bits `0x3000` and full texture field map.  
- Nested `FUN_0096cad0` / `FUN_0096a630` duals open.  
- Dead parent `<0` fail plate vs always-0 body.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00968720_GfxBufferedViews_RecreateRenderTargets_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00968720_GfxBufferedViews_RecreateRenderTargets_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00968720_FUN_00968720.md` |
| Annotated | `docs/reconstruction/raw/aa_00968720_FUN_00968720.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GfxBufferedViews_RecreateRenderTargets_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00968720.cpp` |
| Function | `docs/reconstruction/functions/aa_00968720_FUN_00968720.md` |
| Function named | `docs/reconstruction/functions/aa_00968720_GfxBufferedViews_RecreateRenderTargets_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `009686e0` | Port as **void BufferedViews shutdown walker**: for each list entry, if texture gate `+0x30==0`, thiscall texture device-release. Call only from device-reset **shutdown**. Not a view dtor. |
| `00968720` | Port as **BufferedViews rebuild walker**: ReCreate render targets (or special-flag COM Release); **always return 0**; log per-view ReCreate failures. Call only from device-reset **rebuild** after Texture Factory. Do not invent failing HRESULT without new evidence. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x0075eff0` | `GfxDevice_Reset` parent (W37-N) — both call sites |
| `0x00968a50` | `GfxBufferedView_Ctor_Inferred` — list insert (W37-I) |
| `0x0096c8e0` | texture release leaf (W38-AB) |
| `0x0096cad0` | ReCreate (starts with release) |
| `0x00968680` | post-success list flag clear (W38-Z) |
| `0x00d1ee30` | global gfxBufferedView list head |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + function/xref helpers + assembly context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; structural `_Inferred` names only; reject gfxDevice/single-view scaffolds.  
- Terminal coverage remains **false** (no runtime Confirmed).
