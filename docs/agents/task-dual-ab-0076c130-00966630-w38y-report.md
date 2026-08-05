# Dual A/B report — W38-Y OWN `aa_0076c130` + `aa_00966630`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W38-Y  
**Scope:** VAs `0x0076c130`, `0x00966630` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + call-site context + sibling/consumer decompile. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave38_partition_map.md` (W38-Y).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0076c130` Debug_OutputDebugStringFmt_Inferred | **accept** — cdecl varargs / 2048 `_vsnprintf` / ODS / null no-op / 59 B / 78 xrefs sealed |
| `aa_00966630` Gfx_DeviceStateCache_Clear_Inferred | **accept** — EDX host / dual 16-dword stage zero / host+0..8+0x3C / leaf / 68 B / sole Reset caller sealed |

**Terminal coverage:** false (no Launcher / runtime / bit-exact Confirmed).

---

## VA `0x0076c130` — sealed facts

1. **Body:** `0x0076c130`–`0x0076c16b` exclusive (**59 B** / `0x3B`; pad `CC` then `FUN_0076c170`).
2. **ABI:** **cdecl varargs** — stack **`const char* format`**, remaining stack = `va_list`; plain **`RET`** (`C3`); **void**. Callers clean with **`ADD ESP,4/8/C/20`**.
3. **Semantics:**
   - Null format → no-op.
   - Else `_vsnprintf(buf, 0x800, format, &vararg0)` then `OutputDebugStringA(buf)`.
   - Stack buffer **2048** bytes (`SUB ESP,0x800`).
4. **Classification:** worker.
5. **Callers (78 xrefs / 19+ named):** includes `GfxDevice_Reset` (`FUN_0075eff0`), `FUN_0075e710`, voice (`FUN_00671aa0` family), `Client_RecvLoginFail`, pack/texture diagnostics (`FUN_0096b470`, …). Full list in raw W38-Y append.
6. **Callees:** `_vsnprintf` (IAT `0x009c64b4`), `OutputDebugStringA` (IAT `0x009c61a4`).
7. **Name:** `Debug_OutputDebugStringFmt_Inferred` (Ghidra `FUN_0076c130`; **Inferred**). **Reject** `Named_CalleeOf_Client_RecvLoginFail_0076c130`.
8. **Distinct from:** `FUN_0076cec0` (vog log format builder used with `vog_LogMessage`).
9. **Decompile vs bytes:** CF ≡ raw; **bytes win** on frame size / null gate / plain RET.  
   Full hex: raw W38-Y append (59 B).

### Gaps

- Product/PDB English.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0076c130_Debug_OutputDebugStringFmt_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0076c130_Debug_OutputDebugStringFmt_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0076c130_FUN_0076c130.md` |
| Annotated | `docs/reconstruction/raw/aa_0076c130_FUN_0076c130.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Debug_OutputDebugStringFmt_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0076c130.cpp` |
| Function | `docs/reconstruction/functions/aa_0076c130_FUN_0076c130.md` |
| Function named | `docs/reconstruction/functions/aa_0076c130_Debug_OutputDebugStringFmt_Inferred.md` |

---

## VA `0x00966630` — sealed facts

1. **Body:** `0x00966630`–`0x00966674` exclusive (**68 B** / `0x44`; pad `CC` then `FUN_00966680`).
2. **ABI:** **EDX=`host*`** only; **ECX unused** (decompiler phantom `param_1`); plain **`RET`**; **void**; **leaf**.
3. **Semantics:** Clear device-bound state caches:
   - `REP STOSD` zero **`DAT_00d0e128[16]`** and **`DAT_00d0e0e8[16]`** (per-stage texture/object + companion caches; consumer `FUN_0043f4b0` / D3D `vtbl+0x190`).
   - Zero scalars **`DAT_00d1a568`**, **`DAT_00d1a564`**, **`DAT_00d1a558`**, **`DAT_00d1a55c`**.
   - Zero **`host[+0,+4,+8,+0x3C]`** (`[0]..[2]`, `[0xf]`).
4. **Classification:** leaf.
5. **Callers (1):** `FUN_0075eff0` `GfxDevice_Reset` @ `0x0075f48f` — `MOV EDX,[DAT_00d1f048]`; after clear, republish `host[0..2]` from device slots.
6. **Callees:** none.
7. **Name:** `Gfx_DeviceStateCache_Clear_Inferred` (Ghidra `FUN_00966630`; **Inferred**). **Reject** `Named_CalleeOf_Named_gfxDevice_00966630`.
8. **Twin:** `FUN_00966690` full host init (`DAT_00d1f048=param_2` + floats/flags + **same zero block**). `FUN_00966680` nulls the global pointer only.
9. **Decompile vs bytes:** CF ≡ raw; **bytes win** on drop-ECX + `REP STOSD` layout.  
   Full hex: raw W38-Y append (68 B).

### Gaps

- Host product English (Stats Monitor sibling string vs broader state tracker).  
- Scalar global product names.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00966630_Gfx_DeviceStateCache_Clear_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00966630_Gfx_DeviceStateCache_Clear_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00966630_FUN_00966630.md` |
| Annotated | `docs/reconstruction/raw/aa_00966630_FUN_00966630.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Gfx_DeviceStateCache_Clear_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00966630.cpp` |
| Function | `docs/reconstruction/functions/aa_00966630_FUN_00966630.md` |
| Function named | `docs/reconstruction/functions/aa_00966630_Gfx_DeviceStateCache_Clear_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0076c130` | Port as **cdecl varargs ODS printf**: null-safe, **2048** stack buffer, `_vsnprintf` + `OutputDebugStringA`, plain RET. Do **not** treat as `vog_LogMessage` / file logger. Callers own stack cleanup. |
| `00966630` | Port as **EDX-host state-cache clear** on device reset: zero two **16-dword** stage tables + four scalars + host **+0/+4/+8/+0x3C**. Do **not** free host or Release COM. Pair with `GfxDevice_Reset` republish of host[0..2]. Drop phantom ECX. |
| Shared | Co-owned as W38-Y partition pair; both hang under **`GfxDevice_Reset`** success/fail paths (ODS for HRESULT fail; cache clear on success). Domains differ (debug util vs gfx cache). |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x0075eff0` | `GfxDevice_Reset` (W37-N) — sole clear caller; heavy ODS consumer |
| `0x0075e710` | Present-params dump via multi-arg ODS |
| `0x00966690` | Full state-host init (twin zero block) |
| `0x00966680` | `DAT_00d1f048 = 0` |
| `0x00966760` | Stats Monitor query factory (Reset fail plate) |
| `0x0043f4b0` | Stage-cache consumer (SetTexture-class) |
| `0x00d1f048` | Global host pointer |
| `0x00d0e128` / `0x00d0e0e8` | 16-stage cache tables |

Closes W38-Y OWN pair: universal **debug ODS fmt** helper left open under Reset/voice/login, plus **device state-cache clear** nested under successful Reset.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers + sibling/consumer decompile. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names; `_Inferred` structural names only.  
- Rejected long Named_CalleeOf scaffold aliases.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit arrays).  
- Distinguished ODS fmt from vog `FUN_0076cec0`.  
- Distinguished clear leaf from full init twin `FUN_00966690`.  
- Terminal coverage: **false** always.
