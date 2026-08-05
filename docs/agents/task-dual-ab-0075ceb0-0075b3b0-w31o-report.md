# Dual A/B report — W31-O OWN-ONLY (`0x0075ceb0`, `0x0075b3b0`)

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W31-O  
**Scope:** VAs `0x0075ceb0`, `0x0075b3b0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave31_partition_map.md` → **W31-O**.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0075ceb0` GfxView_Ctor_Inferred | **accept-with-gaps** — ctor ABI/CF/size/path/camera defaults sealed; nested D3D product English + transform return pairing open |
| `aa_0075b3b0` GfxView_SetNear_Inferred | **accept** — ECX this + float near + dirty pair + RET 4 fully sealed; leaf; decompile ≡ full body hex |

---

## VA `0x0075ceb0` — sealed facts

1. **Body:** `0x0075ceb0`–`0x0075d1fc` inclusive (**0x54D** / **1357 B**); pad `CC`.
2. **ABI:** **ECX=`GfxView*`**; no stack formals; returns **this**; SEH `LAB_009b25d7`; epilogue **`ADD ESP,0x2C; RET`**.
3. **Semantics:** Product **ctor** (`…\graphics\gfxView.cpp`):
   - Vtbl `PTR_FUN_00a9edc8`; zoom **1.0** (`g_flOne` → `+0x0C`).
   - `_aligned_malloc(0xC0,0x10)` + `FUN_00972cc0` → transform at **`+0x08`**.
   - Sub-ctor `FUN_0073f590(this+0x10)`.
   - Two identity 4×4 mats (`FUN_0043f780` + copy `DAT_00afdf70`) → `+0x50` / `+0x54`.
   - Defaults: **near 0.5** (`+0xF0`), **far 10000** (`+0xF4`), **FOV π/3** (`+0x10C`), **`+0x104=1000`**, mode **0** (`+0xEC`), dirty **`+0x48/+0xCC=1`**.
   - Background VB: `FUN_00414bc0(0x144)` + `FUN_00414c20(4,…,3,0)` (line **0x45**).
   - Effect `"PalViewBackground.fx"` (line **0x48**).
   - Success: `+0x40=this`, zero **0x18** dwords from `+0x5C`, return this.
   - Hard fail: `c:\VOGCRASH.txt` + `raise(0x16)` + `ExitProcess(3)`.
4. **Object size:** factories allocate **`0x150`** before call.
5. **Classification:** worker (ctor).
6. **Callers (2):** `FUN_004cda90` @ `0x004cdac8`; `FUN_00968a50` @ `0x00968a71`.
7. **Name:** `GfxView_Ctor_Inferred` (Ghidra `FUN_0075ceb0`; path-sealed class; method English structural).
8. **Decompile ≡ raw CF**; constants sealed by `read_memory`.

### Gaps

- Nested D3D / matrix helper product English.  
- `FUN_00972cc0` return EAX/EDX pairing under live ABI.  
- Secondary field English / nested `PTR_FUN_00a9db18` objects.  
- Runtime / bit-exact / differential.  
- MSVC demangle residual.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0075ceb0_GfxView_Ctor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0075ceb0_GfxView_Ctor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0075ceb0_FUN_0075ceb0.md` |
| Annotated | `docs/reconstruction/raw/aa_0075ceb0_FUN_0075ceb0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GfxView_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0075ceb0.cpp` |
| Function | `docs/reconstruction/functions/aa_0075ceb0_FUN_0075ceb0.md` |
| Function named | `docs/reconstruction/functions/aa_0075ceb0_GfxView_Ctor_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_0075ceb0.md` |

---

## VA `0x0075b3b0` — sealed facts

1. **Body:** `0x0075b3b0`–`0x0075b3cb` inclusive (**28 B** / `0x1C`); pad `CC`.
2. **ABI:** **ECX=`GfxView*`**; stack **`float near`**; cleanup **`RET 4`**.
3. **Semantics:** Store near at **`+0xF0`**; set dirty **`+0x48=1`** and **`+0xCC=1`** (projection rebuild gates).
4. **Full hex:** `f30f10442404b001f30f1181f00000008841488881cc000000c20400`
5. **Classification:** leaf — no callees.
6. **Callers (4):** `FUN_004cda90` @ `0x004cdae6` (**0.5f**); `FUN_004c0a90` @ `0x004c0b17`; `FUN_0055ca90` @ `0x0055cb17` (~0.2f); `FUN_005b3420` @ `0x005b348b`.
7. **Polarity twin:** `FUN_0075b390` writes **far** at `+0xF4` (not owned this wave).
8. **Name:** `GfxView_SetNear_Inferred` (Ghidra `FUN_0075b3b0`).
9. **Decompile ≡ raw ≡ bytes** (MOVSS proves float; decompiler `undefined4` is width-only).

### Gaps

- Product method English (cosmetic).  
- Runtime / bit-exact under EnsureProjection rebuild.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0075b3b0_GfxView_SetNear_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0075b3b0_GfxView_SetNear_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0075b3b0_FUN_0075b3b0.md` |
| Annotated | `docs/reconstruction/raw/aa_0075b3b0_FUN_0075b3b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GfxView_SetNear_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0075b3b0.cpp` |
| Function | `docs/reconstruction/functions/aa_0075b3b0_FUN_0075b3b0.md` |
| Function named | `docs/reconstruction/functions/aa_0075b3b0_GfxView_SetNear_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_0075b3b0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0075ceb0` | Port as **GfxView ctor** on **0x150**: vtbl, zoom 1, aligned transform, identity mats, **near 0.5 / far 10000 / FOV π/3**, dirty flags, background VB + `PalViewBackground.fx`. Do **not** use far=1000 as ctor default (`DAT_00a0f520` → `+0x104` only). Factories may overwrite near/far after construct. |
| `0075b3b0` | Port as **leaf SetNear**: `+0xF0` float + dirty `+0x48` and `+0xCC`; **RET 4**. Pair with far twin `FUN_0075b390` (`+0xF4`). Required after ctor when factory sets 0.5f (W30-F). |
| Pair with | `Client_InitPalantirViewBundle_Inferred` (`0x004cda90`), `GfxView_EnsureProjection_Inferred` (`0x0075b7f0`), `GfxView_UnprojectScreenToWorldRay_Inferred` (`0x0075c340`), far setter `FUN_0075b390`. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names; class path-sealed (`gfxView.cpp`).  
- Avoided bare `undefined4` in clean (used `uint32_t` / `float` / explicit partial structs).  
- For `0075b3b0`, bytes override decompiler float-as-undefined4 typing.
