# Dual A/B report — W32-S OWN-ONLY (`0x005769c0`, `0x00576860`)

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W32-S  
**Scope:** VAs `0x005769c0`, `0x00576860` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` only. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave32_partition_map.md` → **W32-S**.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005769c0` WaterPhase_Ctor_Inferred | **accept-with-gaps** — 71 B SEH ctor; vtbl `009d3b04`; view@+4; zero +0xC..+0x1C; skip +0x08; RET 4 sealed |
| `aa_00576860` WaterPhase_RegisterToken_Inferred | **accept-with-gaps** — 41 B; new(4)+token vtbl; registry `DAT_00d1f620`; returns -1/0/1; parent fails only on `< 0` |

---

## VA `0x005769c0` — sealed facts

1. **Body:** `0x005769c0`–`0x00576a07` exclusive (**71 B** / `0x47`). Final **`C2 04 00`** (`RET 4`); pad `CC`.
2. **ABI:** **`__thiscall`**; ECX=`self*`; stack formal **view***; returns **self** (EAX); SEH `LAB_009a50ef`.
3. **Semantics:** complete ctor of **0x20** water-phase object:
   - `*this = PTR_FUN_009d3b04`.
   - `this+0x04 = view`.
   - Zero dwords at `+0x0C`, `+0x10`, `+0x14`, `+0x18`, `+0x1C`.
   - **`+0x08` never written**.
4. **Classification:** worker (complete ctor).
5. **Callers (context):** `PalantirEnv_InitPhases_Inferred` (`0x0048fc90`) water arm — `new(0x20)` + ctor(view from env+0xC0) → `DAT_00b04808`; owner `DAT_00b0480c=env`; then vcall(+0x20).
6. **Vtbl peek `0x009d3b04`:** slots include `EmptyRet` @ `[6]`, init target `[8]=0x00576640` (vcall+0x20). Nearby rdata `RTTextureExt`.
7. **Related:** peer `FUN_00576860`; env method W31-P; factory W30-F.
8. **Name:** `WaterPhase_Ctor_Inferred` (Ghidra `FUN_005769c0`). **Reject** scaffold `Named_CalleeOf_Drive_NDRiver_fx_005769c0`.
9. **Decompile ≡ raw CF** (live 2026-07-29 ≡ raw 2026-07-23); ABI/bounds/layout sealed by `read_memory`.

### Gaps

- Product English / MSVC demangle for water class.  
- Field meanings for zero bank and unset `+0x08`.  
- Full vtbl product names.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005769c0_WaterPhase_Ctor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005769c0_WaterPhase_Ctor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005769c0_FUN_005769c0.md` |
| Annotated | `docs/reconstruction/raw/aa_005769c0_FUN_005769c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/WaterPhase_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005769c0.cpp` |
| Function | `docs/reconstruction/functions/aa_005769c0_FUN_005769c0.md` |
| Function named | `docs/reconstruction/functions/aa_005769c0_WaterPhase_Ctor_Inferred.md` |

---

## VA `0x00576860` — sealed facts

1. **Body:** `0x00576860`–`0x00576889` exclusive (**41 B** / `0x29`). Final **`C3`** (bare `ret`); pad `CC`.
2. **ABI:** no stack formals; bare **`ret`**; returns **int32** status in EAX.
3. **Semantics:** water-arm registry helper (after ctor + vcall+0x20):
   - `operator_new(4)`.
   - `FUN_00576c40(token)` — install token vtbl `PTR_FUN_009d3ac4` (nearby `"CVOGPhas…"`).
   - **`mov ecx,[DAT_00d1f620]; push token; call FUN_00746400`** — find-or-append in global host (decompiler omitted this-arg; **bytes seal**).
   - Returns **1** if already present, **0** if appended, **-1** on OOM/null.
4. **Parent policy:** `PalantirEnv_InitPhases_Inferred` logs `"Water phase initialization failed"` only when **`hr < 0`**.
5. **Classification:** worker (free helper).
6. **Callers (context):** sole water arm of `FUN_0048fc90` after water vcall(+0x20).
7. **Twin CF:** distort `FUN_00576d70` — same skeleton / same `DAT_00d1f620` / different micro-ctor.
8. **Related:** ctor peer `FUN_005769c0`; env method W31-P.
9. **Name:** `WaterPhase_RegisterToken_Inferred` (Ghidra `FUN_00576860`). **Reject** scaffold `Named_CalleeOf_Drive_NDRiver_fx_00576860`.
10. **Decompile ≡ raw CF** for control structure; host ECX sealed only by `read_memory`.

### Gaps

- Product demangle for 4-byte phase token.  
- Full type of registry host `DAT_00d1f620`.  
- Possible token leak when find-hit returns 1 (new token unused).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00576860_WaterPhase_RegisterToken_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00576860_WaterPhase_RegisterToken_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00576860_FUN_00576860.md` |
| Annotated | `docs/reconstruction/raw/aa_00576860_FUN_00576860.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/WaterPhase_RegisterToken_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00576860.cpp` |
| Function | `docs/reconstruction/functions/aa_00576860_FUN_00576860.md` |
| Function named | `docs/reconstruction/functions/aa_00576860_WaterPhase_RegisterToken_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005769c0` | Port as **complete ctor** of 0x20 water object: `water = Ctor(raw, view)`. Must install vtbl `009d3b04`, view@`+0x04`, zero `+0x0C..+0x1C`. Do **not** write `+0x08`. Do **not** register token or vcall here. |
| `00576860` | Port as **free helper** after water vcall(+0x20): `hr = RegisterToken()`. Fail only if `hr < 0`. Uses process registry host `DAT_00d1f620`. May allocate a 4-byte token each call. |
| Pair with | `PalantirEnv_InitPhases_Inferred` (`0x0048fc90`, W31-P); water singleton `DAT_00b04808` / owner `DAT_00b0480c`; distort twins `FUN_00576ed0` / `FUN_00576d70` (not this dual). |

### Water arm order (sealed from W31-P caller)

```
if DAT_00b04808 == 0:
  raw = new(0x20)
  DAT_00b04808 = WaterPhase_Ctor(raw, env->view@+0xC0)   // this dual 005769c0
  DAT_00b0480c = env
  vcall(water, +0x20)                                     // vtbl[8]
  hr = WaterPhase_RegisterToken()                         // this dual 00576860
  if hr < 0: log "Water phase initialization failed"
```

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + `read_memory` only. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; `_Inferred` structural names only (WaterPhase from env water arm + VOGEnvironmentSector path evidence).  
- Rejected scaffold `Named_CalleeOf_Drive_NDRiver_fx_*`.  
- Pattern: `docs/agents/task-dual-ab-00492dd0-0048fc90-w31p-report.md`.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
