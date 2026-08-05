# Dual A/B report — W31-H OWN `aa_00984ee0` + `aa_00948bd0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W31-H  
**Scope:** VAs `0x00984ee0`, `0x00948bd0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + xrefs/callers. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** wave31 H.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00984ee0` AssPackManager_OpenPackFile_Inferred | **accept-with-gaps** — EBX/ECX/stack/RET4 + CS/vector CF sealed (295 B); nested open free + product residual |
| `aa_00948bd0` Client_CompileEffectsBootstrap_Inferred | **accept-with-gaps** — sole `-compileeffects` caller + window/AssManager/36-FX stages sealed; nested render/FX English open |

---

## VA `0x00984ee0` — sealed facts

1. **Body:** `0x00984ee0`–`0x00985006` (**295 B** / `0x127`; pad `CC` then `FUN_00985010`).
2. **ABI:** **EBX=`AssPackManager* this`**; **ECX=`const char* path`**; stack **`char flag`**; **`RET 4`**; returns **`0` / `-1`**. Decompiler thiscall/ECX conflates path with this — **bytes + call sites win**.
3. **Semantics:** Optional CS (`+0x50` gate, CS `@+0x38`) → log Opening (`assPackManager.cpp:0x75`) → `new(0x44)` + `FUN_00719970(pack, flag)` → open `FUN_0071a9d0` → fail log `:0x7b` return −1 → success log `:0x80` + push pack* into vector **`this+0x28`** via `FUN_004406e0`.
4. **Classification:** worker.
5. **Callers:** `FUN_007b75b0` (batch `.glm` opens, W30-D), `FUN_00985010`, `FUN_009963f0` (36 xrefs).
6. **Callees:** CS enter/leave, `FUN_0076cec0`, `vog_LogMessage`, `operator_new`, `FUN_00719970`, `FUN_0071a9d0`, `FUN_004406e0`.
7. **Name:** `AssPackManager_OpenPackFile_Inferred` (Ghidra `FUN_00984ee0`; **Inferred** from plate path + open strings). Legacy `Named_assPackManager_00984ee0` twin.
8. **Decompile ≡ bytes** for CF; full hex seals dual epilogues + `LEA EAX,[EBX+0x28]`.

### Gaps

- Nested open (`FUN_0071a9d0`) product English / file flags.  
- Fail-path pack free residual.  
- Product/MSVC demangle.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00984ee0_AssPackManager_OpenPackFile_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00984ee0_AssPackManager_OpenPackFile_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00984ee0_FUN_00984ee0.md` |
| Annotated | `docs/reconstruction/raw/aa_00984ee0_FUN_00984ee0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssPackManager_OpenPackFile_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00984ee0.cpp` |
| Function | `docs/reconstruction/functions/aa_00984ee0_FUN_00984ee0.md` |
| Function named | `docs/reconstruction/functions/aa_00984ee0_AssPackManager_OpenPackFile_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_00984ee0.md` |

---

## VA `0x00948bd0` — sealed facts

1. **Body:** `0x00948bd0`–`0x009492c7` (**1784 B** / `0x6F8`; pad `CC`).
2. **ABI:** **ESI=`client host`**; bare **`C3`**; void. Offsets: helper **`+0xde8`**, HINSTANCE **`+0x3180`**, HWND **`+0x3188`**.
3. **Semantics:**
   - `new(0x2ec)` + `FUN_007a26c0` → `self+0xde8`.
   - AssManager get; set flags `@+4 = 3`; **`FUN_007b75b0(mgr, mode=1)`** (W30-D sealed).
   - `RegisterClassA("XutoAssault")`; `CreateWindowExA(..., "Auto Assault", … 32×32)` → HWND.
   - `FUN_007a3e90` RenderEngine init; fail strings for CreateWindowEx / RenderEngine.
   - `ShowWindow(hwnd, 0)`; **36×** `FUN_00989e00` + `FUN_009701d0` FX preload list (ND* + Pal* shaders).
4. **Classification:** worker (offline tool bootstrap).
5. **Callers (1):** `FUN_0094ba40` @ `0x0094bb33` — only when cmdline has **`-compileeffects`** (after `-developer`); then `_exit(0)`.
6. **Callees:** `operator_new`, `FUN_007a26c0`, `FUN_007b6a20`×2, `FUN_007b75b0`, Win32 window APIs, `FUN_007a3e90`, `FUN_00989e00`×36, `FUN_009701d0`×36, `FUN_007a4480`×2.
7. **Name:** `Client_CompileEffectsBootstrap_Inferred` (Ghidra `FUN_00948bd0`; **Inferred**). **Reject** scaffold `Drive_NDRiver_fx_00948bd0`.
8. **Decompile ≡ raw** for stages; entry/epilogue hex sealed. Unreachable blocks = SEH string dtor only.

### Gaps

- Nested `FUN_007a3e90` / FX loader product English.  
- Exact 0x2ec helper type.  
- Dim argument packing nuance for render init.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00948bd0_Client_CompileEffectsBootstrap_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00948bd0_Client_CompileEffectsBootstrap_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00948bd0_FUN_00948bd0.md` |
| Annotated | `docs/reconstruction/raw/aa_00948bd0_FUN_00948bd0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_CompileEffectsBootstrap_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00948bd0.cpp` |
| Function | `docs/reconstruction/functions/aa_00948bd0_FUN_00948bd0.md` |
| Function named | `docs/reconstruction/functions/aa_00948bd0_Client_CompileEffectsBootstrap_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_00948bd0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00984ee0` | Port as **pack open** under optional CS: **EBX=manager**, **ECX=path**, stack flag, **RET 4**. Construct 0x44 pack, open nested, push into vector `@+0x28`. Return 0/−1. Do **not** invent ECX=this. Pair with W30-D AssManager batch of `.glm` paths. |
| `00948bd0` | Port as **offline `-compileeffects` bootstrap only** — not `Client_InitInstance`. AssManager mode=1 → tiny hidden AA window → RenderEngine → fixed 36 FX list. Caller exits process. Reject `Drive_NDRiver_fx` alias. |
| Pair with | `AssManager_InitPrecompileAndResolvers_Inferred` (`0x007b75b0`), pack open batch strings `../effects.glm` / `../misc.glm`, general init `Client_InitInstance` (`0x0094a6a0`). |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only (W31-H sections).  
- No invented product plates; structural `_Inferred` names only.  
- Rejected false FX plate for `00948bd0`; corrected ABI for `00984ee0` (EBX this / ECX path).
