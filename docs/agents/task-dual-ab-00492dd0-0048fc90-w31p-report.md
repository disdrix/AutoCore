# Dual A/B report — W31-P OWN-ONLY (`0x00492dd0`, `0x0048fc90`)

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W31-P  
**Scope:** VAs `0x00492dd0`, `0x0048fc90` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `batch_decompile` / `analyze_function_complete` / `get_function_by_address` / `read_memory` (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave31_partition_map.md` → **W31-P**.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00492dd0` PalantirEnv_Ctor_Inferred | **accept-with-gaps** — complete ctor CF/ABI/RET8/size 0x198/sole factory sealed; product demangle + FUN_0096ef70 this-adjusts open |
| `aa_0048fc90` PalantirEnv_InitPhases_Inferred | **accept-with-gaps** — phase method CF/ABI/RET4/return0/singleton+owned split/strings sealed; product phase demangle open |

---

## VA `0x00492dd0` — sealed facts

1. **Body:** `0x00492dd0`–`0x004930ab` exclusive (**731 B** / `0x2DB`). Final **`C2 08 00`** (`RET 8`); pad `CC`; next SEH @ `0x004930ab`.
2. **ABI:** **`__thiscall`**; ECX=`self*` (`8B F1`); stack formals **arg0** + **parent**; returns **this**; SEH `LAB_009a0b3b`.
3. **Semantics:** complete ctor of **0x198** Palantir env host:
   - `FUN_007560d0`; vtbl `PTR_FUN_009c7928`.
   - Flag bank `+0x80..`; `+0x87` / `+0x70` from `parent+0x7d`.
   - Six `FUN_0096ef70` subobject inits; nested `PTR_LAB_009c7744` @ `+0xD4` + this @ `+0xD8`.
   - Store arg0 @ `+0xBC`, parent @ `+0xB8`; two `FUN_004933f0` results.
   - RB sentinel `FUN_0044e100` → `+0x190` with self-links + flag `+0x2d=1`.
   - `+0x172` from desktop chain `parent+0xE89C→+0x28→+0x799`.
   - `new(0xC8)` + `FUN_00497920(parent)` → `+0x100`; tail `FUN_0048f2d0`.
4. **Classification:** worker (complete ctor).
5. **Callers (1):** `FUN_004cda90` (`Client_InitPalantirViewBundle_Inferred`, W30-F) @ `0x004cdb79` — `new(0x198); push parent; push 0; call` → `parent+0xE894`.
6. **Xrefs:** 1.
7. **Related:** phase peer `FUN_0048fc90`; `RbTree_AllocEmptyNode_0x30` (`0x0044e100`).
8. **Name:** `PalantirEnv_Ctor_Inferred` (Ghidra `FUN_00492dd0`). **Reject** scaffold `Named_CalleeOf_Named_CalleeOf_Named_Could_not_get_Palantir_desk_00492dd0`.
9. **Decompile ≡ raw CF** (live 2026-07-29 ≡ raw 2026-07-23); ABI/bounds sealed by `read_memory`.

### Gaps

- Product English / MSVC demangle for env class.  
- Exact this-adjust bases for each `FUN_0096ef70`.  
- Roles of `FUN_007560d0` / `FUN_0048f2d0` / `FUN_004933f0`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00492dd0_PalantirEnv_Ctor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00492dd0_PalantirEnv_Ctor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00492dd0_FUN_00492dd0.md` |
| Annotated | `docs/reconstruction/raw/aa_00492dd0_FUN_00492dd0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PalantirEnv_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00492dd0.cpp` |
| Function | `docs/reconstruction/functions/aa_00492dd0_FUN_00492dd0.md` |
| Function named | `docs/reconstruction/functions/aa_00492dd0_PalantirEnv_Ctor_Inferred.md` |

---

## VA `0x0048fc90` — sealed facts

1. **Body:** `0x0048fc90`–`0x0048fed0` exclusive (**576 B** / `0x240`). Final **`C2 04 00`** (`RET 4`); pad `CC`.
2. **ABI:** **`__thiscall`**; ECX=`env*`; stack formal **flag** (factory **1**); returns **0** (`XOR EAX,EAX`); SEH `LAB_009a08ac`.
3. **Semantics:** phase bootstrap method on env host:
   - Prelude `FUN_00756320(flag)` / `FUN_0048f370` / `FUN_0048ed00`.
   - If `DAT_00b04808==0`: `new(0x20)` + `FUN_005769c0(view@+0xC0)` water singleton; owner `DAT_00b0480c=this`; vcall `+0x20`; `FUN_00576860`; log `"Water phase initialization failed"` (`VOGEnvironmentSector.cpp` L0xAD).
   - If `DAT_00b04818==0`: `new(0x18)` + `FUN_00576ed0(view)` distort singleton; owner `DAT_00b0481c`; same pattern; log `"Distort phase initialization failed"` L0xBB.
   - Always: `new(0x170)`+`FUN_005b35a0(parent@+0xB8)` → `+0xC4` + `FUN_005b39a0(1)`.
   - Always: `new(0xA0)`+`FUN_0055c8c0(parent)` → `+0xC8` + `FUN_0055cc50(1)`.
   - Always: `new(0xC8)`+`FUN_004c0640(parent)` → `+0xCC` + `FUN_004c2080(1)`.
   - `FUN_004982d0`; load `"NDRiver.fx"`; zero `+0x178`.
4. **Classification:** worker (env method).
5. **Callers (1):** `FUN_004cda90` @ `0x004cdbf0` — `mov ecx,[esi+0xE894]; push 1; call` after view↔env cross-wire.
6. **Xrefs:** 1.
7. **Related:** ctor peer `FUN_00492dd0`; factory W30-F; NAMING_REGISTRY `VOGEnvironmentSector` / `CVOGEnvironmentSector_ProcessPreloads`.
8. **Name:** `PalantirEnv_InitPhases_Inferred` (Ghidra `FUN_0048fc90`). **Reject** scaffold `Drive_NDRiver_fx` (tail string only).
9. **Decompile ≡ raw CF**; ABI/strings/sizes sealed by `read_memory`.

### Gaps

- Product demangle for water/distort/owned phase classes.  
- Flag formal product meaning beyond factory constant 1.  
- `FUN_004982d0` / FX helper product roles.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0048fc90_PalantirEnv_InitPhases_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0048fc90_PalantirEnv_InitPhases_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0048fc90_FUN_0048fc90.md` |
| Annotated | `docs/reconstruction/raw/aa_0048fc90_FUN_0048fc90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PalantirEnv_InitPhases_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0048fc90.cpp` |
| Function | `docs/reconstruction/functions/aa_0048fc90_FUN_0048fc90.md` |
| Function named | `docs/reconstruction/functions/aa_0048fc90_PalantirEnv_InitPhases_Inferred.md` |
| Legacy scaffold | `docs/reconstruction/reconstructed-exact/Drive_NDRiver_fx.cpp` / `Drive_NDRiver_fx_0048fc90.cpp` (**reject** as canonical) |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00492dd0` | Port as **complete ctor** of 0x198 env: `env = Ctor(raw, 0, parent)`. Must install vtbl, parent@`+0xB8`, arg0@`+0xBC`, RB@`+0x190`, child@`+0x100`. Do **not** assume view@`+0xC0` yet (factory wires after return). Do **not** init water/distort here. |
| `0048fc90` | Port as **env method** after view cross-wire: `InitPhases(env, 1)` returns 0. Water/distort are **process singletons** (create once); three owned phases every call from parent@`+0xB8`. Requires view@`+0xC0`. Reject NDRiver-only naming. |
| Pair with | `Client_InitPalantirViewBundle_Inferred` (`0x004cda90`, W30-F); `RbTree_AllocEmptyNode_0x30` (`0x0044e100`); GfxView factory arm; `Class_009c7a1c_Ctor` (`0x00496f70`). |

### Factory order (sealed)

```
new GfxView → +0xE890
new env + Ctor(0, parent) → +0xE894     // this dual's 00492dd0
new Class_009c7a1c → +0xE898
view+4 = env; env+0xC0 = view
InitPhases(env, 1)                        // this dual's 0048fc90
publish *(env+4) → DAT_00d1a54c
```

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/xrefs/body bounds). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; `_Inferred` structural names only (PalantirEnv from factory slot + VOGEnvironmentSector path evidence).  
- Rejected scaffold `Drive_NDRiver_fx` and long auto parent-seed ctor name.  
- Pattern: `docs/agents/task-dual-ab-004cda90-0051b8a0-w30f-report.md`.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
