# Dual A/B report — W33-T OWN-ONLY (`0x0055cc50`, `0x005b39a0`)

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W33-T  
**Scope:** OWN ONLY VAs `0x0055cc50`, `0x005b39a0`. Dual A/B + artifacts (trio + function + A/B).  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave33_partition_map.md` → **W33-T**.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `batch_decompile` / `get_function_by_address` / `get_function_xrefs` / `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_0055cc50` CVOGEnvironmentDistort_Enable_Inferred | **accept-with-gaps** — host RTTI Distort; CF/ABI/ret0/ret4/sole InitPhases enable sealed; nested `0055ca90` English open |
| `aa_005b39a0` CVOGEnvironmentReflect_Enable_Inferred | **accept-with-gaps** — host RTTI Reflect; CF/ABI/ret0/ret4/sole InitPhases enable sealed; nested resolve/alloc English open |

---

## `aa_0055cc50` — CVOGEnvironmentDistort_Enable_Inferred

### Sealed facts

1. **Body:** `0x0055cc50`–`0x0055cc6a` exclusive (**26 B** / `0x1A`). Final **`C2 04 00`** (`ret 4`); pad `CC`.

2. **ABI:** **`__thiscall`**; ECX=`this` (CVOGEnvironmentDistort*); stack formal **flag**; returns **0** (`XOR EAX,EAX`).

3. **Host RTTI:** ctor `FUN_0055c8c0` vtbl `PTR_FUN_009d26ac`; COL `0x00aae6cc` → type_info `0x00af2d0c` → **`.?AVCVOGEnvironmentDistort@@`** (**Confirmed**).

4. **Algorithm:**
   - `HostBase_EnsureAuxPtrs_Inferred(this, flag)` (`FUN_00756320`)
   - `FUN_0055ca90(this)` — particle-distort child bring-up (`Particle_Distort.dds` / `NDParticleDistortBlendNormal.fx`)
   - return 0

5. **Classification:** worker (post-ctor enable).

6. **Callers (1):** `PalantirEnv_InitPhases_Inferred` (`FUN_0048fc90`) @ `0x0048fe20` — always `new(0xA0)` + `FUN_0055c8c0(parent)` → env`+0xC8`; then **this(1)**.

7. **Related:** ctor `FUN_0055c8c0` (size 0xA0); work `FUN_0055ca90`; peer enables `FUN_005b39a0` / `FUN_004c2080`.

8. **Name:** `CVOGEnvironmentDistort_Enable_Inferred` (Ghidra `FUN_0055cc50`). **Reject** scaffold `Named_CalleeOf_Drive_NDRiver_fx_0055cc50`. Distinct from process-singleton `CVOGPhaseDistort` (`0x00576ed0`, size 0x18).

9. **Decompile ≡ raw CF** (live 2026-07-29 ≡ raw 2026-07-23); ABI sealed by `read_memory`.

### Gaps

1. Product English for nested `FUN_0055ca90`.  
2. Flag formal product meaning beyond factory constant 1.  
3. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_0055cc50_CVOGEnvironmentDistort_Enable_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_0055cc50_CVOGEnvironmentDistort_Enable_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0055cc50_CVOGEnvironmentDistort_Enable_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0055cc50_CVOGEnvironmentDistort_Enable_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_0055cc50_CVOGEnvironmentDistort_Enable_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_0055cc50_FUN_0055cc50.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGEnvironmentDistort_Enable_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0055cc50.cpp` |
| Raw (+ W33-T append) | `docs/reconstruction/raw/aa_0055cc50_FUN_0055cc50.md` |
| Annotated | `docs/reconstruction/raw/aa_0055cc50_FUN_0055cc50.annotated.md` |

---

## `aa_005b39a0` — CVOGEnvironmentReflect_Enable_Inferred

### Sealed facts

1. **Body:** `0x005b39a0`–`0x005b39c1` exclusive (**33 B** / `0x21`). Final **`C2 04 00`** (`ret 4`); pad `CC`.

2. **ABI:** **`__thiscall`**; ECX=`this` (CVOGEnvironmentReflect*); stack formal **flag**; returns **0** (`XOR EAX,EAX`).

3. **Host RTTI:** ctor `FUN_005b35a0` vtbl `PTR_FUN_009d95a0`; COL `0x00aafff8` → type_info `0x00af3eb0` → **`.?AVCVOGEnvironmentReflect@@`** (**Confirmed** W32-T).

4. **Algorithm:**
   - `HostBase_EnsureAuxPtrs_Inferred(this, flag)` (`FUN_00756320`)
   - `FUN_005b3520(this)` — resolve nested fog slots into `+0x150`/`+0x154` when empty
   - `FUN_005b3420(this)` — alloc/bind fog child @ `+0x158` (size 0x198)
   - return 0

5. **Classification:** worker (post-ctor enable).

6. **Callers (1):** `PalantirEnv_InitPhases_Inferred` (`FUN_0048fc90`) @ `0x0048fdde` — always `new(0x170)` + `CVOGEnvironmentReflect_ctor(parent@+0xB8)` → env`+0xC4`; then **this(1)**.

7. **Related:** ctor `FUN_005b35a0` (W32-T); apply vtbl[1] `FUN_005b36f0` (W29-I); resolve `FUN_005b3520`; child `FUN_005b3420`; dtors `FUN_005b3670` / `FUN_005b3a30`.

8. **Name:** `CVOGEnvironmentReflect_Enable_Inferred` (Ghidra `FUN_005b39a0`). **Reject** scaffold `Named_CalleeOf_Drive_NDRiver_fx_005b39a0`.

9. **Decompile ≡ raw CF**; ABI sealed by `read_memory`.

### Gaps

1. Product English for nested `FUN_005b3520` / `FUN_005b3420` / `FUN_00968a50`.  
2. Flag formal product meaning beyond factory constant 1.  
3. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_005b39a0_CVOGEnvironmentReflect_Enable_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_005b39a0_CVOGEnvironmentReflect_Enable_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_005b39a0_CVOGEnvironmentReflect_Enable_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005b39a0_CVOGEnvironmentReflect_Enable_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_005b39a0_CVOGEnvironmentReflect_Enable_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_005b39a0_FUN_005b39a0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGEnvironmentReflect_Enable_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_005b39a0.cpp` |
| Raw (+ W33-T append) | `docs/reconstruction/raw/aa_005b39a0_FUN_005b39a0.md` |
| Annotated | `docs/reconstruction/raw/aa_005b39a0_FUN_005b39a0.annotated.md` |

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0055cc50-005b39a0-w33t-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0055cc50` | Port as **post-ctor enable** on owned env child: after `new CVOGEnvironmentDistort` (size **0xA0**) at `env+0xC8`, call `Enable(1)` → HostBase ensure + particle-distort child. Distinct from process-singleton PhaseDistort (**0x18**). Reject NDRiver naming. |
| `005b39a0` | Port as **post-ctor enable** on owned env child: after `new CVOGEnvironmentReflect` (size **0x170**) at `env+0xC4`, call `Enable(1)` → HostBase ensure + nested fog resolve + child @ `+0x158`. Apply path is separate vfunc residual (W29-I). |

### InitPhases owned-phase order (sealed)

```
new Reflect(0x170) + ctor → env+0xC4; EnableReflect(1)   // 005b39a0
new Distort(0xA0)  + ctor → env+0xC8; EnableDistort(1)   // 0055cc50
new Third(0xC8)    + ctor → env+0xCC; EnableThird(1)     // 004c2080 (peer)
```

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + `get_function_by_address` + xrefs + `read_memory`. **No** `disassemble_bytes`.  
