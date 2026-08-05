# Dual A/B report — W32-R OWN-ONLY (`0x0048f370`, `0x0048ed00`)

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W32-R  
**Scope:** VAs `0x0048f370`, `0x0048ed00` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `batch_decompile` / `analyze_function_complete` / `get_function_by_address` / `read_memory` (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave32_partition_map.md` → **W32-R**.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0048f370` PalantirEnv_RebuildDefaultLights_Inferred | **accept-with-gaps** — rebuild CF/ABI/slots/strings/floats/3 callers sealed; first light type string + product demangle open |
| `aa_0048ed00` PalantirEnv_InitEffectTextures_Inferred | **accept-with-gaps** — dual texture CF/ABI/slots/format/half-dims/sole caller sealed; `0x4011` + slot English open |

---

## VA `0x0048f370` — sealed facts

1. **Body:** `0x0048f370`–`0x0048f65f` exclusive (**751 B** / `0x2EF`). Final **`C3`** @ `0x0048f65e`; pad `CC`. SEH `LAB_009a0822`.
2. **ABI:** **`__thiscall`**; ECX=`env*` (`8B F1`); no stack formals; **void**; bare RET.
3. **Semantics:** rebuild-safe default **light pair** on Palantir env host:
   - Prelude `FUN_0048eb10` tears prior `+0x104` / `+0x108`.
   - `operator_new(0x94)` + `FUN_0096e4b0` → `+0x108` (directional): `"Direction"` + `"Color"`; dir seed `DAT_00aaa6d4`/`DAT_00aaa6cc`/`g_flOne` = **(-0.1, -0.5, 1.0)** via `DAT_00b03530..38` + `FUN_0076f5f0`.
   - `operator_new(0x94)` + `FUN_0096e4b0` → `+0x104` (hemispheric): `FUN_0096e430("Hemispheric")`; `"ColorTop"` / `"ColorBottom"`; ARGB **`0xFF707B8F`**, **`0xFFD1A56D`**, **`0xFF3E2F2D`** via `FUN_009733d0`.
   - Each light effect core @ light`+0x8c`; vcall `+0x40` lookup, `+0x4c`/`+0x50` set; refcount `+0xdc++`; flag `+0xd0=1`.
   - If `env+0xC4 != 0` → `FUN_005b3520` (owned-phase notify; cold on first InitPhases before phase alloc).
4. **Classification:** worker (env method).
5. **Callers (3):**
   - `FUN_0048fc90` (`PalantirEnv_InitPhases_Inferred`, W31-P) @ `0x0048fcb8`
   - `FUN_0091aa30` @ `0x0091add8` (ECX=`[ctx+0xE894]`)
   - `FUN_00944b20` (`Client_TeardownGameplaySession_Inferred`) @ `0x00944cee` (ECX via `[client+0xE04]+0xE894`)
6. **Xrefs:** 3.
7. **Related:** texture peer `FUN_0048ed00`; light teardown `FUN_0048eb10`; InitPhases / factory W31-P / W30-F.
8. **Name:** `PalantirEnv_RebuildDefaultLights_Inferred` (Ghidra `FUN_0048f370`). **Reject** scaffold `Named_CalleeOf_Named_CalleeOf_Client_RecvLoginCallback_3_0048f370`.
9. **Decompile ≡ raw CF** (live 2026-07-29 ≡ raw 2026-07-23); ABI/bounds/floats sealed by `read_memory`.

### Gaps

- Product English / MSVC demangle for light host (`FUN_0096e4b0`) and helpers.  
- First `FUN_0096e430` has no stack type string in bytes (Directional not proven as literal).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0048f370_PalantirEnv_RebuildDefaultLights_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0048f370_PalantirEnv_RebuildDefaultLights_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0048f370_FUN_0048f370.md` |
| Annotated | `docs/reconstruction/raw/aa_0048f370_FUN_0048f370.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PalantirEnv_RebuildDefaultLights_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0048f370.cpp` |
| Function | `docs/reconstruction/functions/aa_0048f370_FUN_0048f370.md` |
| Function named | `docs/reconstruction/functions/aa_0048f370_PalantirEnv_RebuildDefaultLights_Inferred.md` |
| Legacy scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Client_RecvLoginCallback_3_0048f370.cpp` (**reject** as canonical) |

---

## VA `0x0048ed00` — sealed facts

1. **Body:** `0x0048ed00`–`0x0048ed81` exclusive (**129 B** / `0x81`). Final **`C3`** @ `0x0048ed80`; pad `CC`.
2. **ABI:** **`__thiscall`**; ECX=`env*` (`8B F1`); no stack formals; **void**; bare RET.
3. **Semantics:** dual **effect-texture** create/bind via `FUN_0096f0e0` (`effTexture.cpp` "Failed to create instance of texture."):
   - Slot **`env+0xDC`**: format **`0x15`** (D3DFMT_A8R8G8B8); dims `*(DAT_00d1f058+0x2c)+0x80`; args `1`, **`0x4011`**, `0`; related **`env+0xD4`**.
   - Slot **`env+0xE0`**: same format/args; dims stack half of device `+0x80`/`+0x84` (`width/2`, `height/2`); related **0**.
   - Bytes seal this-adjusts: `LEA ECX,[ESI+0xDC]` / `LEA ECX,[ESI+0xE0]` (decompiler omits this).
4. **Classification:** worker (env method).
5. **Callers (1):** `FUN_0048fc90` @ `0x0048fcbf` — immediately after light rebuild in InitPhases prelude.
6. **Xrefs:** 1.
7. **Related:** light peer `FUN_0048f370`; InitPhases W31-P; nested `+0xD4` from env ctor W31-P.
8. **Name:** `PalantirEnv_InitEffectTextures_Inferred` (Ghidra `FUN_0048ed00`). **Reject** scaffold `Named_CalleeOf_Drive_NDRiver_fx_0048ed00`.
9. **Decompile ≡ raw CF**; ABI/slots/format sealed by full-body `read_memory`.

### Gaps

- Product English for texture slots / related `+0xD4`.  
- Exact product enum for `0x4011`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0048ed00_PalantirEnv_InitEffectTextures_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0048ed00_PalantirEnv_InitEffectTextures_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0048ed00_FUN_0048ed00.md` |
| Annotated | `docs/reconstruction/raw/aa_0048ed00_FUN_0048ed00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PalantirEnv_InitEffectTextures_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0048ed00.cpp` |
| Function | `docs/reconstruction/functions/aa_0048ed00_FUN_0048ed00.md` |
| Function named | `docs/reconstruction/functions/aa_0048ed00_PalantirEnv_InitEffectTextures_Inferred.md` |
| Legacy scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Drive_NDRiver_fx_0048ed00.cpp` (**reject** as canonical) |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0048f370` | Port as **rebuild-safe env method**: tear lights first; dir @ `+0x108`, hemi @ `+0x104`, each host size **0x94**. Default dir **(-0.1, -0.5, 1.0)** before normalize helper. Do **not** merge into InitPhases or ctor. Call with env from `parent+0xE894`. |
| `0048ed00` | Port as **env method** after lights: full-res texture → `+0xDC` (related `+0xD4`); half-res → `+0xE0`. Format **0x15**. Requires device dims via `DAT_00d1f058+0x2c`. Reject NDRiver naming. |
| Pair with | `PalantirEnv_InitPhases_Inferred` (`0x0048fc90`, W31-P); `PalantirEnv_Ctor_Inferred` (`0x00492dd0`); `Client_InitPalantirViewBundle_Inferred` (`0x004cda90`, W30-F); light teardown `FUN_0048eb10`; texture helper `FUN_0096f0e0`. |

### InitPhases prelude order (sealed W31-P + this dual)

```
FUN_00756320(env, flag)
PalantirEnv_RebuildDefaultLights(env)   // 0048f370
PalantirEnv_InitEffectTextures(env)     // 0048ed00
// then water / distort / owned phases / NDRiver.fx ...
```

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/xrefs/body bounds). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; `_Inferred` structural names only (PalantirEnv from factory slot + InitPhases peer evidence).  
- Rejected scaffolds: login-callback long name; Drive_NDRiver_fx callee name.  
- Pattern: `docs/agents/task-dual-ab-00492dd0-0048fc90-w31p-report.md`.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
