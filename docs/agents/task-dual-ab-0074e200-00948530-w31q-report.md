# Dual A/B report — W31-Q OWN `aa_0074e200` + `aa_00948530`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W31-Q  
**Scope:** VAs `0x0074e200`, `0x00948530` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave31_partition_map.md` (W31-Q).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0074e200` EnvSlot_SetActiveBumpGen | **accept-with-gaps** — ABI/CF/offsets/caller wiring sealed; product class English residual |
| `aa_00948530` Client_InitRenderEngine | **accept-with-gaps** — stage map/ABI/returns/strings/sole-caller sealed; nested helper product plates open |

---

## VA `0x0074e200` — sealed facts

1. **Body:** `0x0074e200`–`0x0074e23c` inclusive (**61 B** / `0x3D`; pad `CC CC`).
2. **ABI:** **ECX=`slot`**; stack **`char enable`**; **`RET 4`** (`C2 04 00`); void; **leaf**.
3. **Semantics:**
   - `related = *(slot+0x3c)`; if null → return.
   - Always `++*(related+0xdc)`.
   - `*(related+0xd1) = 1` only if `enable != 0` **and** `*(DAT_00d1f048+0x0f) != 0`; else `0`.
4. **Classification:** leaf.
5. **Callers:** sole static `FUN_004cda90` (`Client_InitPalantirViewBundle_Inferred`) ×2 — disable old `DAT_00d1a54c` (push 0) then enable `*(env+4)` (push 1); caller stores global after. Caller bytes @ `0x004cdbf0` seal ECX wiring.
6. **Callees:** none.
7. **Name:** `EnvSlot_SetActiveBumpGen` (Ghidra `FUN_0074e200`; **Inferred** structural). Reject scaffold `Named_CalleeOf_Named_CalleeOf_Named_Could_not_get_Palantir_desk_0074e200`.
8. **Sibling (not owned):** `FUN_00442b90` inlines same related offsets + publishes `DAT_00d1a54c`.
9. **Decompile ≡ bytes** for both paths; full 61 B hex in raw W31-Q append.

### Gaps

- Product/MSVC demangle for slot + related classes.  
- English for gen/dirty counter at `+0xdc`.  
- Full product plate for `DAT_00d1f048` host.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0074e200_EnvSlot_SetActiveBumpGen.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0074e200_EnvSlot_SetActiveBumpGen.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0074e200_FUN_0074e200.md` |
| Annotated | `docs/reconstruction/raw/aa_0074e200_FUN_0074e200.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/EnvSlot_SetActiveBumpGen.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0074e200.cpp` |
| Function | `docs/reconstruction/functions/aa_0074e200_FUN_0074e200.md` |
| Function named | `docs/reconstruction/functions/aa_0074e200_EnvSlot_SetActiveBumpGen.md` |
| Scratch | `docs/reconstruction/tmp/a_0074e200.md` |

---

## VA `0x00948530` — sealed facts

1. **Body:** `0x00948530`–`0x00948ba7` inclusive (**1656 B** / `0x678`).
2. **ABI:** **ECX=`client app`**; frame prologue/epilogue; bare **`RET`**; returns **0** success / **`0x80004005`** (`E_FAIL`).
3. **Semantics (stages):**
   - `DAT_00afa250 = app+0x9c1`; `EnumDisplayMonitors` → monitor table `DAT_00d1a830` (stride **0xC**); clamp index `app+0xa14`.
   - Build outer rect `app+0x3190..`; `RegisterClassA` style **0x302B**, class **`"XutoAssault"`**, WndProc `LAB_009484d0`, icon **0x65**.
   - Style **WS_POPUP** `0x80000000` unless (`+0x9c1` && `+0x9c2`) → `DAT_00ca0000`; exstyle **0x40000**; optional `AdjustWindowRectEx`.
   - `CreateWindowExA` title **`"Auto Assault"`** → `app+0x3188`; fail string **`"Failed to CreateWindowEx!"`**.
   - Ensure `app+0x1168` (`new 0x590` + `FUN_007fb0a0`); vcall slot1(0); Show/Update.
   - `FUN_007a3e90(hwnd, size@+0xa18, !+0x9c1, +0x9c6, **"aa.bmp"**)`: **0** → **`"Failed to initialize the RenderEngine!"`**; **2** → `SetWindowPos` flags **6**.
   - Center `+0x31b0/+0x31b4`; optional `DAT_00d1f050` guarded-vector rewrite (`FUN_0043c5f0` / `FUN_0040af40` / `FUN_0040d9c0`) — ignore Ghidra false-noreturn on mid-loop delete.
   - Flag fuse `+0xa0d` / `+0xb5`; stamp `*(app+0xe04)+0xe89c = app+0xde8`; **`FUN_004cda90`** (Palantir view bundle).
   - Success if `*(app+0xde8)+0x2c != 0` → subsystem hooks → **return 0**; else **`"Could not get Palantir desktop window."`**.
   - Fail: `FUN_007a4480(1, msg)` → **`0x80004005`**.
4. **Classification:** worker.
5. **Callers:** sole `Client_InitInstance` (`FUN_0094a6a0`) @ `0x0094ab16` — banners **`@@InitRenderEngine`** / **`InitRenderEngine`**; nonzero → **`_exit(1)`**.
6. **Name:** `Client_InitRenderEngine` (product). Reject scaffold `Named_Could_not_get_Palantir_desktop_window_00948530` as sole plate.
7. **Decompile ≡ raw** for sealed stages; entry+epilogue hex in raw W31-Q append.

### Gaps

- Product C++ class for client app / flag English (`+0x9c1` family).  
- Nested `FUN_007a3e90` / success-path helper product plates.  
- WndProc `LAB_009484d0` body (not owned).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00948530_Client_InitRenderEngine.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00948530_Client_InitRenderEngine.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00948530_FUN_00948530.md` |
| Annotated | `docs/reconstruction/raw/aa_00948530_FUN_00948530.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_InitRenderEngine.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00948530.cpp` |
| Function | `docs/reconstruction/functions/aa_00948530_FUN_00948530.md` |
| Function named | `docs/reconstruction/functions/aa_00948530_Client_InitRenderEngine.md` |
| Scratch | `docs/reconstruction/tmp/a_00948530.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0074e200` | Port as **thiscall** slot helper (not free `enable`-only). Caller owns `DAT_00d1a54c` store order: disable old → enable new → publish. Gate active=1 through `DAT_00d1f048[+0xf]`. Always bump related `+0xdc`. Fix W30-F clean stub that declared `void FUN_0074e200(uint32_t enable)` without ECX. |
| `00948530` | Port as **InitRenderEngine** orchestrator: monitors → window → render → optional table → Palantir bundle → hooks. Return **0** / **E_FAIL**; InitInstance must hard-fail on nonzero. Do not treat as Palantir-only. |
| Pair with | `Client_InitInstance` (`0x0094a6a0`), `Client_InitPalantirViewBundle` (`0x004cda90`), sibling publish `FUN_00442b90`. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; structural `_Inferred` only where needed; product banners used for InitRenderEngine.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).  
- Rejected Named_* scaffold aliases as sole plates.
