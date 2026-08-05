# Dual A/B report — W34-T OWN-ONLY (`0x0078caf0`, `0x0048eb10`)

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W34-T  
**Scope:** OWN ONLY VAs `0x0078caf0`, `0x0048eb10`. Dual A/B + artifacts (trio + function + A/B).  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave34_partition_map.md` → **W34-T**.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `decompile_function` / `get_function_by_address` / `get_function_xrefs` / `get_function_callers` / `get_function_callees` / `read_memory_bytes` (+ RTTI COL). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_0078caf0` CNDUIWndBuffered_Ctor_Inferred | **accept-with-gaps** — RTTI/size/ABI/ret12/HostBase@+0x2A8/6 callers sealed; field-bank + arg product English open |
| `aa_0048eb10` PalantirEnv_TearDefaultLights_Inferred | **accept-with-gaps** — CF/ABI/slots/mgr+4/Reflect tail/primary callers sealed; 0074e* product English + orphan site open |

---

## `aa_0078caf0` — CNDUIWndBuffered_Ctor_Inferred

### Sealed facts

1. **Body:** `0x0078caf0`–`0x0078cecb` exclusive (**987 B** / `0x3DB`). Final **`C2 0C 00`** (`ret 12`); pad `CC`. SEH `LAB_009b400b`.

2. **ABI:** Stack **`this`** + **2** formals; returns **this**; **`ret 12`**. Call sites push three dwords (`(this,0,0)` or `(this,0,1)`).

3. **Host RTTI:** vtbl `PTR_FUN_00a99f74`; COL `0x00ab8280` → type_info `0x00afe4d0` → **`.?AVCNDUIWndBuffered@@`** (**Confirmed**). Bases: `CNDUIWindow` ← `gfxUIWindow`.

4. **Algorithm:**
   - `FUN_007b5dd0(this, arg1)` — `CNDUIWindow` base ctor
   - Install `CNDUIWndBuffered` vtbl
   - Field bank (identity floats, flags, colors via `DAT_00b017e8`×literal channels, `+0x488=arg2`, `+0x134=2.0f` @ `DAT_00a10e74`)
   - `operator_new(0x80)` + `HostBase_DefaultCtor` (`FUN_007560d0`) → **`+0x2A8`**
   - `HostBase_EnsureAuxPtrs_Inferred(host, 1)` (`FUN_00756320`)
   - return this

5. **Instance size:** **`0x4FC`** (`68 FC 04 00 00` before `operator_new` at three sites).

6. **Classification:** complete constructor.

7. **Callers (6):**
   - `FUN_00856490` — subclass **CWndPortrait** (`(this,0,0)`)
   - `FUN_008345c0` — subclass **CWndVehicle** (`(this,0,1)`)
   - `FUN_0097c720` — subclass **CWndParticles** (`(this,0,1)`)
   - `FUN_008ff260` / `FUN_008a9af0` / `FUN_008e6b50` — `new(0x4FC)` + ctor

8. **Related:** dtor `FUN_0078ca80`; HostBase W32-O (`007560d0`) / W32-Q (`00756320`).

9. **Name:** `CNDUIWndBuffered_Ctor_Inferred` (Ghidra `FUN_0078caf0`). **Reject** scaffold `Named_CalleeOf_Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_list_veh_0078caf0`.

10. **Decompile ≡ raw CF** (live 2026-07-29 ≡ raw 2026-07-23); ABI/RTTI/size sealed by `read_memory`.

### Gaps

1. Product English for full field bank / color rows.  
2. `arg1`/`arg2` product meaning beyond observed 0/1.  
3. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_0078caf0_CNDUIWndBuffered_Ctor_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_0078caf0_CNDUIWndBuffered_Ctor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0078caf0_CNDUIWndBuffered_Ctor_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0078caf0_CNDUIWndBuffered_Ctor_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_0078caf0_CNDUIWndBuffered_Ctor_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_0078caf0_FUN_0078caf0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDUIWndBuffered_Ctor_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0078caf0.cpp` |
| Raw (+ W34-T append) | `docs/reconstruction/raw/aa_0078caf0_FUN_0078caf0.md` |
| Annotated | `docs/reconstruction/raw/aa_0078caf0_FUN_0078caf0.annotated.md` |

---

## `aa_0048eb10` — PalantirEnv_TearDefaultLights_Inferred

### Sealed facts

1. **Body:** `0x0048eb10`–`0x0048eb99` exclusive (**137 B** / `0x89`). Final **`C3`** @ `0x0048eb98`; pad `CC`.

2. **ABI:** **`__thiscall`**; ECX=`env*` (`56 8B F1`); **void**; bare RET.

3. **Algorithm:**
   - Manager `mgr = *(env+4)` (bytes seal; decompiler omits).
   - If `env+0x104` (hemi light): `FUN_0074e260(mgr, *(light+0x8c))`; scalar dtor(1); null.
   - If `env+0x108` (dir light): `FUN_0074e0d0(mgr, 0)`; same unregister/dtor/null.
   - If `env+0xC4` (Reflect): tail-jmp `FUN_005b3580` with **ECX=reflect** (tears `reflect+0x150`).

4. **Classification:** worker (env method; rebuild-safe tear).

5. **Callers (3 CODE xrefs):**
   - `PalantirEnv_RebuildDefaultLights_Inferred` (`FUN_0048f370`) @ `0x0048f38d` — prelude
   - `FUN_00492be0` @ `0x00492c16` — `CVOGEnvironmentSector` dtor path (vtbl RTTI Confirmed)
   - `0x0091e1d7` — orphan bounds; ECX via `[DAT_00d1b644]+0xE894` env pointer

6. **Related:** rebuild W32-R `0048f370`; textures peer `0048ed00`; Reflect enable W33-T; light hosts size **0x94**.

7. **Name:** `PalantirEnv_TearDefaultLights_Inferred` (Ghidra `FUN_0048eb10`). **Reject** scaffold `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvLoginCa_0048eb10`.

8. **Decompile ≡ raw CF**; ABI/slots/mgr/`this` sealed by `read_memory`.

### Gaps

1. Product English for `FUN_0074e260` / `FUN_0074e0d0`.  
2. Orphan site `0x0091e1d7` enclosing function.  
3. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_0048eb10_PalantirEnv_TearDefaultLights_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_0048eb10_PalantirEnv_TearDefaultLights_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0048eb10_PalantirEnv_TearDefaultLights_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0048eb10_PalantirEnv_TearDefaultLights_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_0048eb10_PalantirEnv_TearDefaultLights_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_0048eb10_FUN_0048eb10.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PalantirEnv_TearDefaultLights_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0048eb10.cpp` |
| Raw (+ W34-T append) | `docs/reconstruction/raw/aa_0048eb10_FUN_0048eb10.md` |
| Annotated | `docs/reconstruction/raw/aa_0048eb10_FUN_0048eb10.annotated.md` |

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0078caf0-0048eb10-w34t-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0078caf0` | Port as **`CNDUIWndBuffered` complete ctor**, size **0x4FC**. Base `CNDUIWindow` first; nested HostBase **0x80** at **`+0x2A8`** then `EnsureAux(1)`. Subclasses (Portrait/Vehicle/Particles) call then replace vtbl. Reject shopveh naming. |
| `0048eb10` | Port as **env light tear** paired with `PalantirEnv_RebuildDefaultLights_Inferred`: destroy hemi `@+0x104` and dir `@+0x108` via mgr `@+4`; dir clears attach first; optional Reflect `@+0xC4` residual. Do **not** merge into rebuild. |

### Pairing (sealed peers)

```
// Lights lifecycle
PalantirEnv_TearDefaultLights(env)      // 0048eb10  (this dual)
PalantirEnv_RebuildDefaultLights(env)   // 0048f370  (W32-R) — calls tear first

// UI buffered window
CNDUIWndBuffered_Ctor(this, a, b)       // 0078caf0  (this dual)
  → HostBase_DefaultCtor + EnsureAux    // 007560d0 / 00756320 (W32-O/Q)
```

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + function metadata + xrefs + `read_memory_bytes` + RTTI COL. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; RTTI Confirmed name for UI ctor; `_Inferred` structural name for env tear (PalantirEnv from peer factory evidence).  

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
