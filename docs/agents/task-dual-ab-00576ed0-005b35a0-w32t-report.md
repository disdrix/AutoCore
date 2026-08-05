# Dual A/B report — W32-T OWN-ONLY (`0x00576ed0`, `0x005b35a0`)

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W32-T  
**Scope:** OWN ONLY VAs `0x00576ed0`, `0x005b35a0`. Dual A/B + artifacts (trio + function + A/B).  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave32_partition_map.md` → **W32-T**.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `batch_decompile` / `get_function_by_address` / `get_function_xrefs` / `get_bulk_xrefs` / `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_00576ed0` CVOGPhaseDistort_ctor | **accept** — RTTI PhaseDistort; leaf ctor CF/ABI/ret4/size 0x18/sole singleton factory sealed |
| `aa_005b35a0` CVOGEnvironmentReflect_ctor | **accept-with-gaps** — RTTI EnvironmentReflect; complete ctor CF/ABI/ret4/size 0x170/sole owned factory sealed; base/matrix product English open |

---

## `aa_00576ed0` — CVOGPhaseDistort_ctor

### Sealed facts

1. **Body:** `0x00576ed0`–`0x00576f11` exclusive (**65 B** / `0x41`). Final **`C2 04 00`** (`ret 4`); pad `CC`. SEH `LAB_009a514a`.

2. **ABI:** **`__thiscall`**; ECX=`this`; stack formal **view***; returns **this** (EAX from early `mov eax,ecx`).

3. **RTTI:** vtbl `PTR_FUN_009d3bc0`; COL `0x00aaed0c` → type_info `0x00af31a0` → **`.?AVCVOGPhaseDistort@@`** (**Confirmed**).

4. **Algorithm:** store view @ `+0x04` → install PhaseDistort vtbl → zero `+0x0C` / `+0x10` / `+0x14`. Leaf (no callees beyond SEH).

5. **Classification:** worker (complete ctor).

6. **Callers (1):** `PalantirEnv_InitPhases_Inferred` (`FUN_0048fc90`) @ `0x0048fd60` — if `DAT_00b04818==0`: `new(0x18)` + ctor(view@env`+0xC0`) → singleton; owner `DAT_00b0481c=env`; vcall `+0x20`; `FUN_00576d70`; log `"Distort phase initialization failed"` (`VOGEnvironmentSector.cpp` L0xBB).

7. **Related:** dtor `FUN_00576f20`; plate method `FUN_00576f70` (`CVOGPhaseDistort::AddPieceInstance()`); Water peer `FUN_005769c0` (size 0x20, different vtbl).

8. **Name:** `CVOGPhaseDistort_ctor` (Ghidra `FUN_00576ed0`). **Reject** scaffold `Named_CalleeOf_Drive_NDRiver_fx_00576ed0`.

9. **Decompile ≡ raw CF** (live 2026-07-29 ≡ raw 2026-07-23); ABI/bounds sealed by `read_memory`.

### Gaps

1. Product English for tails / untouched `+0x08`.  
2. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00576ed0_CVOGPhaseDistort_ctor.md` | **accept** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00576ed0_CVOGPhaseDistort_ctor.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00576ed0_CVOGPhaseDistort_ctor.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00576ed0_CVOGPhaseDistort_ctor.md` |
| Function record | `docs/reconstruction/functions/aa_00576ed0_CVOGPhaseDistort_ctor.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00576ed0_FUN_00576ed0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGPhaseDistort_ctor.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00576ed0.cpp` |
| Raw (+ W32-T append) | `docs/reconstruction/raw/aa_00576ed0_FUN_00576ed0.md` |
| Annotated | `docs/reconstruction/raw/aa_00576ed0_FUN_00576ed0.annotated.md` |

---

## `aa_005b35a0` — CVOGEnvironmentReflect_ctor

### Sealed facts

1. **Body:** `0x005b35a0`–`0x005b366f` exclusive (**207 B** / `0xCF`). Final **`C2 04 00`** (`ret 4`); pad `CC`; next body dtor `FUN_005b3670`. SEH `LAB_009a67ed`.

2. **ABI:** **`__thiscall`**; ECX=`this`; stack formal **parent***; returns **this** (`mov eax,esi`).

3. **RTTI:** vtbl `PTR_FUN_009d95a0`; COL `0x00aafff8` → type_info `0x00af3eb0` → **`.?AVCVOGEnvironmentReflect@@`** (**Confirmed**).

4. **Algorithm:**
   - `FUN_007560d0` base
   - Install EnvironmentReflect vtbl
   - `FUN_00972cc0` matrix/transform @ **`this+0x90`**
   - `+0x15C`=parent; `+0x158`=0; `+0x160`=`*(parent+0xE4E8)`; `+0x150`/`+0x154`=0; `+0x164`=`*(parent+0xE894)`
   - `FUN_0044b440(this+0x90, 1.0f, -1.0f, 1.0f)` — floats from `DAT_00a0f2a0` / `DAT_00aaa668` (decompiler elided formals; **bytes win**)
   - if `*(u8*)(this+0x14C) & 1`: `FUN_00972e50(this+0x90)`
   - `*(u8*)(this+0x78)=1`; `*(u8*)(this+0x80)=1`

5. **Classification:** worker (complete ctor).

6. **Callers (1):** `FUN_0048fc90` @ `0x0048fdc7` — always `new(0x170)` + ctor(parent@env`+0xB8`) → env`+0xC4`; `FUN_005b39a0(1)`.

7. **Related:** apply vtbl[1] `FUN_005b36f0` (`Env_ApplyFogShaderAndReflect_Inferred`, W29-I); body dtor `FUN_005b3670`; scalar dtor `FUN_005b3a30`.

8. **Name:** `CVOGEnvironmentReflect_ctor` (Ghidra `FUN_005b35a0`). **Reject** scaffold `Named_CalleeOf_Drive_NDRiver_fx_005b35a0`.

9. **Decompile ≡ raw CF**; ABI/float stamp/flags sealed by `read_memory`.

### Gaps

1. Product demangle for base `FUN_007560d0`.  
2. Product names for matrix helpers `FUN_00972cc0` / `FUN_00972e50` / `FUN_0044b440`.  
3. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_005b35a0_CVOGEnvironmentReflect_ctor.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_005b35a0_CVOGEnvironmentReflect_ctor.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_005b35a0_CVOGEnvironmentReflect_ctor.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005b35a0_CVOGEnvironmentReflect_ctor.md` |
| Function record | `docs/reconstruction/functions/aa_005b35a0_CVOGEnvironmentReflect_ctor.md` |
| Scaffold record | `docs/reconstruction/functions/aa_005b35a0_FUN_005b35a0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGEnvironmentReflect_ctor.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_005b35a0.cpp` |
| Raw (+ W32-T append) | `docs/reconstruction/raw/aa_005b35a0_FUN_005b35a0.md` |
| Annotated | `docs/reconstruction/raw/aa_005b35a0_FUN_005b35a0.annotated.md` |

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00576ed0-005b35a0-w32t-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00576ed0` | Port as **process-singleton Distort phase**: `if (!g_distort) g_distort = new CVOGPhaseDistort(view); owner=env`. Size **0x18**. Distinct from Water (**0x20**). Reject NDRiver-only naming. |
| `005b35a0` | Port as **owned env child** every InitPhases: `env.c4 = new CVOGEnvironmentReflect(parent)` size **0x170**, then enable(1). Wire parent + nested `E4E8`/`E894`. Default work flags `+0x78`/`+0x80` true; matrix sub at `+0x90` stamped (1,-1,1). Apply path is separate vfunc residual (W29-I). |
