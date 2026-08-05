# Dual A/B report — W38-X OWN `aa_0074f0c0` + `aa_0075e710`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W38-X  
**Scope:** VAs `0x0074f0c0`, `0x0075e710` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave38_partition_map.md` (W38-X).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0074f0c0` Gfx_NotifyResHolders_GlobalsVtbl10c_HostVtbl114_Inferred | **accept-with-gaps** — ESI host + triple global vtbl notify sealed (100 B); product holder/method English open |
| `aa_0075e710` D3DPresentParams_Log_Inferred | **accept** — 14-dword D3DPRESENT_PARAMETERS logger via ESI; plates + layout sealed (194 B) |

---

## Trio (context — not OWN)

Both units are helpers on the **GfxDevice device-reset / present-params** spine sealed in W37-N:

| VA | Role | Wave |
|---|---|---|
| `0x0075eff0` | `GfxDevice_Reset` (parent worker) | W37-N |
| `0x0075e710` | Present-params log (**this dual B**) | W38-X |
| `0x0074f0c0` | Global/host resource-holder notify (**this dual A**) | W38-X |

Parent `Palantir_ResetDevice` (`0x00754480`, W35-K) → `GfxDevice_Reset` → these leaves. Co-owned only by partition pair; domains: **notify leaf** vs **debug logger**.

---

## VA `0x0074f0c0` — sealed facts

1. **Body:** `0x0074f0c0`–`0x0074f124` exclusive (**100 B** / `0x64`); pad `CC` then sibling `FUN_0074f130` @ `0x0074f130`.
2. **ABI:** **ESI** = host object with optional **`iface*` @ +0xc**; void; bare **`RET`** (`C3`). **Not** stack thiscall/stdcall.
3. **Semantics:**
   - For each global holder in order **`DAT_00afe034`**, **`DAT_00afe01c`**, **`DAT_00afe010`**: if holder ≠ 0 and `holder+0xc` ≠ 0 → thiscall **`iface->vtbl[+0x10c](iface)`**.
   - If `ESI+0xc` ≠ 0 → thiscall **`iface->vtbl[+0x114](iface)`** (**different** slot than globals).
4. **Family:** sibling `FUN_0040d340` (not OWN) hits `DAT_00afe010` / `DAT_00afe034` with **`vtbl[+0x104]`** only — same holder layout, earlier method index.
5. **Classification:** **leaf**.
6. **Callers (2 sites / 2 funcs):**
   - `GfxDevice_Reset` (`0x0075eff0`) @ `0x0075f153` — `ESI = *[*(device+0x760)+4]` (device slot `+0x760` is 0x150-byte subobject from ctor factory `FUN_00969df0`, W35-R).
   - `FUN_0073d8d0` @ `0x0073d8e5` — walk `[EAX+4, EAX+8)` stride **0x14**; `ESI = *elem`; then nested ptr walk `FUN_00752640`.
7. **Callees:** virtual only (no direct `FUN_*`).
8. **Name:** `Gfx_NotifyResHolders_GlobalsVtbl10c_HostVtbl114_Inferred` (Ghidra `FUN_0074f0c0`; **Inferred** structural). **Reject** scaffold `Named_CalleeOf_Named_gfxDevice_0074f0c0`.
9. **Decompile ≡ bytes** for CF; ESI formal sealed by callers + `[ESI+0xc]` use. Full hex in raw W38-X append.

### Gaps

- Product class names for the three `DAT_00afe0xx` holders and host at `device+0x760`.  
- Product English for vtbl methods at +0x10c / +0x114 (OnLost/OnReset **family only inferred**).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0074f0c0_Gfx_NotifyResHolders_GlobalsVtbl10c_HostVtbl114_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0074f0c0_Gfx_NotifyResHolders_GlobalsVtbl10c_HostVtbl114_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0074f0c0_FUN_0074f0c0.md` |
| Annotated | `docs/reconstruction/raw/aa_0074f0c0_FUN_0074f0c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Gfx_NotifyResHolders_GlobalsVtbl10c_HostVtbl114_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0074f0c0.cpp` |
| Function | `docs/reconstruction/functions/aa_0074f0c0_FUN_0074f0c0.md` |
| Function named | `docs/reconstruction/functions/aa_0074f0c0_Gfx_NotifyResHolders_GlobalsVtbl10c_HostVtbl114_Inferred.md` |

---

## VA `0x0075e710` — sealed facts

1. **Body:** `0x0075e710`–`0x0075e7d2` exclusive (**194 B** / `0xC2`); pad `CC` then sibling `FUN_0075e7e0` @ `0x0075e7e0`.
2. **ABI:** **ESI** = pointer to **14 dwords** (`0x38`); void; bare **`RET`** after internal `ADD ESP` cleanup of printf args (`ADD ESP,0x20` mid; `ADD ESP,0x40` epilog; `C3`).
3. **Semantics:** Log full **D3DPRESENT_PARAMETERS**-shaped block via **`FUN_0076c130`** ×10:
   - BackBuffer `[W×H]`, format, count  
   - MultiSampleType / Quality  
   - SwapEffect string: **`2 → "FLIP"`**, **`3 → "COPY"`**, else **`"DISCARD"`**  
   - hDeviceWindow  
   - **Fullscreen = (dword[8] == 0)** i.e. inverted Windowed  
   - EnableAutoDepthStencil / AutoDepthStencilFormat  
   - Flags / FullScreen_RefreshRateInHz / PresentationInterval  
4. **Layout:** matches sealed GfxDevice present bank at **`device+0x2B8`** (W35-R ctor / W37-N Reset); callers copy with **`MOV ECX,0xE; MOVSD`**.
5. **Classification:** **worker** (logger).
6. **Callers (3 sites / 2 funcs):**
   - `GfxDevice_Reset` @ `0x0075f084` — `LEA ESI,[device+0x2B8]` (pre/shutdown path)  
   - `GfxDevice_Reset` @ `0x0075f387` — ESI after rebuild copy  
   - `FUN_00735c90` @ `0x007365fd` — stack present local; then store into device  
7. **Callees:** `FUN_0076c130` only.
8. **Name:** `D3DPresentParams_Log_Inferred` (Ghidra `FUN_0075e710`; **Inferred** from plates + layout). **Reject** incomplete `Gfx_SwapEffect` and scaffold `Named_CalleeOf_Named_gfxDevice_0075e710`.
9. **Decompile ≡ bytes** for CF/strings/SwapEffect branch. Full hex in raw W38-X append.

### Gaps

- Product name for `FUN_0076c130` (printf-style sink; not `vog_LogMessage`).  
- Product source file/line for the plate strings.  
- Runtime / bit-exact / differential (log-only unit).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0075e710_D3DPresentParams_Log_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0075e710_D3DPresentParams_Log_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0075e710_FUN_0075e710.md` |
| Annotated | `docs/reconstruction/raw/aa_0075e710_FUN_0075e710.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/D3DPresentParams_Log_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0075e710.cpp` |
| Function | `docs/reconstruction/functions/aa_0075e710_FUN_0075e710.md` |
| Function named | `docs/reconstruction/functions/aa_0075e710_D3DPresentParams_Log_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0074f0c0` | Port as **ESI-host notify leaf**: for each of three global holders, optional **vtbl+0x10c** on `holder+0xc`; then optional **vtbl+0x114** on host `+0xc`. Bare RET. Do **not** invent OnLost/OnReset product names. Do **not** merge with `FUN_0040d340` (+0x104 subset). Call from device reset after loading host from `*(device+0x760)+4` and from any stride-0x14 resource table walk. |
| `0075e710` | Port as **`D3DPRESENT_PARAMETERS` debug dump**: ESI → 14 dwords; log via printf-style sink. SwapEffect map 2/3/else → FLIP/COPY/DISCARD. Fullscreen log = `!Windowed`. Pure observer — no mutation. Prefer over incomplete `Gfx_SwapEffect` alias. |
| Shared | Both sit under **GfxDevice_Reset** (`0x0075eff0`) on the Palantir device lifecycle; unrelated internal logic (notify vs log). |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x0075eff0` | `GfxDevice_Reset` (W37-N) — trio parent |
| `0x00754480` | `Palantir_ResetDevice` (W35-K) |
| `0x0076c130` | printf-style logger used by present dump |
| `0x0040d340` | Sibling global notify with vtbl **+0x104** |
| `0x0073d8d0` | Vector walk caller of notify leaf |
| `0x00735c90` | Device-create path caller of present log |
| `DAT_00afe034` / `01c` / `010` | Global resource holders |
| `device+0x2B8` | Present params bank (0x38) |
| `device+0x760` | Host subobject for notify ESI |

Closes W38-X OWN pair: resource-holder vtbl notify leaf + D3D present-params logger under GfxDevice reset/create.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers + assembly context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product method names; `_Inferred` structural / layout names only.  
- Rejected long Named_CalleeOf scaffold aliases and incomplete `Gfx_SwapEffect`.  
- Clean avoids bare `undefined4` (`uint32_t` / explicit structs).
