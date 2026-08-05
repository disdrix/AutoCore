# Dual A/B report — W37-F OWN `aa_005b3520` + `aa_004c0fe0`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W37-F  
**Scope:** VAs `0x005b3520`, `0x004c0fe0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/callees/xrefs + `analyze_dataflow` (hemi gate) + neighbor/ctor context. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave37_partition_map.md` (W37-F).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005b3520` CVOGEnvironmentReflect_ResolveLightEffectSlots_Inferred | **accept-with-gaps** — 91 B thiscall once-resolve of light effect cores into `+0x150`/`+0x154` sealed; hemi-null gate residual (often no-op after full rebuild) |
| `aa_004c0fe0` VOGEnvironmentLiquid_InitFilterPipeline_Inferred | **accept-with-gaps** — 1776 B liquid-child filter/RT pipeline (UIFluid*.fx, VOGEnvironmentLiquid.cpp) sealed; nested helper English + contract-level clean residual |

---

## VA `0x005b3520` — sealed facts

1. **Body:** `0x005b3520`–`0x005b357a` inclusive (**91 B** / `0x5B`); pad `CC` then peer `FUN_005b3580`.
2. **ABI:** **`__thiscall`**; ECX=`CVOGEnvironmentReflect*`; no stack formals; **void**; bare **`C3`**.
3. **Semantics:** once-only resolve when `self+0x154 == 0`:
   - `parent = *(self+0x15c)` (ctor stores parent there).
   - `host = *(parent+0xe894)` — nested light-table host (W32-R family: dir `+0x108`, hemi `+0x104`, cores at light `+0x8c`).
   - Require `host+0x108 != 0`.
   - **Byte gate:** enter only if `host+0x104 == 0` (`JNZ` → ret; dataflow CBRANCH sealed).
   - `self+0x154 = *(*(host+0x108)+0x8c)`.
   - Reload host; `self+0x150 = *(*(host+0x104)+0x8c)`.
   - `FUN_0074e310(*(self+4), hemi_core)` — thiscall aux bind.
4. **Classification:** **worker** (once-resolve / notify).
5. **Callers (2):**
   - `FUN_005b39a0` (`CVOGEnvironmentReflect_Enable_Inferred`, W33-T) @ `0x005b39af`
   - `FUN_0048f370` (`PalantirEnv_RebuildDefaultLights_Inferred`, W32-R) @ `0x0048f64b` when `env+0xC4 != 0`
6. **Callees:** `FUN_0074e310` only.
7. **Name:** `CVOGEnvironmentReflect_ResolveLightEffectSlots_Inferred` (Ghidra `FUN_005b3520`; **Inferred** structural). Host RTTI **Confirmed** via ctor/enable family (W32-T/W33-T). **Reject** scaffold `Named_CalleeOf_*`.
8. **Family:** Reflect enable chain; Palantir light rebuild notify; peer `0x005b3580` re-binds `+0x150` (unowned).
9. **Residual:** hemi-null enter gate then hemi load — after full RebuildDefaultLights both lights non-null → **no-op**. Do not invent `!=0` gate.
10. **Decompile ≡ bytes** for gates/slots/bind. Full 91 B hex in raw W37-F append.

### Gaps

- Product English for effect-core objects at light `+0x8c`.  
- When body mutates state in live sessions (often no-op).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005b3520_CVOGEnvironmentReflect_ResolveLightEffectSlots_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005b3520_CVOGEnvironmentReflect_ResolveLightEffectSlots_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005b3520_FUN_005b3520.md` |
| Annotated | `docs/reconstruction/raw/aa_005b3520_FUN_005b3520.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGEnvironmentReflect_ResolveLightEffectSlots_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005b3520.cpp` |
| Function | `docs/reconstruction/functions/aa_005b3520_FUN_005b3520.md` |
| Function named | `docs/reconstruction/functions/aa_005b3520_CVOGEnvironmentReflect_ResolveLightEffectSlots_Inferred.md` |

---

## VA `0x004c0fe0` — sealed facts

1. **Body:** `0x004c0fe0`–`0x004c16cf` inclusive (**1776 B** / `0x6F0`); next function `0x004c16d0`.
2. **ABI:** **`__thiscall`**; ECX=`liquid_child*` (`0x40`); `MOV ESI,ECX`; bare **RET**; returns **0** (`XOR EAX,EAX`); SEH `LAB_009a1a6d`.
3. **Semantics:** post-ctor **filter/RT pipeline init** for liquid child:
   - Device dims from `*(DAT_00d1f058+0x2c)+0x80/0x84`.
   - Four× `new(0x18)+FUN_009886d0` → child `+0x20/+0x28/+0x30/+0x38`.
   - Load **UIFluidDownsample.fx**, **UIFluidBlurHorizontal.fx**, **UIFluidBlurVertical.fx**, **UIFluidSurfaceBlend.fx** (fail logs → `VOGEnvironmentLiquid.cpp`).
   - Bind **BackBufferTexture** from `*parent+0x94`; set **UIMapExtents0** to `(1,1,1/w,1/h)`.
   - Four× `new(0xd4)+FUN_009685e0` RT hosts: full dims @ `+0x3c`; cascaded `>>2` @ `+0x24/+0x2c/+0x34` with vcall `vtbl+8`.
   - `FUN_0096f0e0(0x15, rt+0x80, 1, 0x4011, 0, 0)` ×3; refcount wire `rt+0xb8`; clear `+0xc0`.
   - `*parent+0x98 = tex`; optional **NormalMapTexture** if `parent+0x8c`.
   - Pair `FUN_007567b0` / `FUN_009888b0`; surface-blend `+0x14=1`; cleanup locals; **return 0**.
4. **Classification:** **worker** (child pipeline init).
5. **Callers (1):** `FUN_004c1960` (`ParticleFluidPhase_CreateLiquidChild_Inferred`, W34-O) @ `0x004c19ae`.
6. **Callees:** `operator_new`, `FUN_009886d0`, `FUN_009685e0`, FX load/bind helpers, `FUN_0096f0e0`, `FUN_007567b0`, `FUN_009888b0`, `FUN_00752310`, `FUN_00752a00`, `vog_LogMessage`, …
7. **Name:** `VOGEnvironmentLiquid_InitFilterPipeline_Inferred` (Ghidra `FUN_004c0fe0`; **Inferred**). Product path + UIFluid*.fx seal family. Prefer over bare `Named_VOGEnvironmentLiquid_004c0fe0`.
8. **Family:** fluid phase child lifecycle (W33-S Init → W34-O CreateLiquidChild → **this** → activate).
9. **Decompile ≡ raw CF**; thiscall + ret 0 + slots sealed by prologue/store bytes. Clean is **contract-level** (not full 1776 B EH dump).

### Gaps

- Product demangle for 0x18 filter / 0xd4 RT hosts.  
- Unowned FX/RT helper full contracts.  
- Exact runtime graph of which RT feeds which pass.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004c0fe0_VOGEnvironmentLiquid_InitFilterPipeline_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004c0fe0_VOGEnvironmentLiquid_InitFilterPipeline_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004c0fe0_FUN_004c0fe0.md` |
| Annotated | `docs/reconstruction/raw/aa_004c0fe0_FUN_004c0fe0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/VOGEnvironmentLiquid_InitFilterPipeline_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004c0fe0.cpp` |
| Function | `docs/reconstruction/functions/aa_004c0fe0_FUN_004c0fe0.md` |
| Function named | `docs/reconstruction/functions/aa_004c0fe0_VOGEnvironmentLiquid_InitFilterPipeline_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005b3520` | Port as **Reflect thiscall once-resolve**: when `+0x154` empty, pull dir/hemi effect cores from `*(parent+0xe894)` lights into `+0x154`/`+0x150`, bind hemi via `FUN_0074e310(aux+4)`. Keep **hemi-null** enter gate byte-faithful (often no-op after full light rebuild). Not fog math. Pair with W33-T Enable and W32-R RebuildDefaultLights. |
| `004c0fe0` | Port as **liquid-child pipeline init**: ECX=`child` (0x40), return 0; four UIFluid filters + cascaded RTs; device dims; fmt `0x15` / `0x4011`. Call only after `FUN_004c1800`. Do **not** treat as CreateFluidParticles or phase create. Nested FX helpers stay free. Pair with W34-O CreateLiquidChild. |

Shared: co-owned only by W37-F partition assignment — **different subsystems** (Reflect light slots vs fluid liquid pipeline). Both are **thiscall workers** with prior wave context (W32-R/W33-T vs W34-O).

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers + limited neighbor decompile. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names; RTTI / product path strings used where sealed.  
- Rejected bare scaffold-only plates; kept Reflect RTTI and VOGEnvironmentLiquid path roles.  
- Avoided bare `undefined4` in clean (used `uint32_t` / explicit pointers).  
- Documented 005b3520 hemi-null residual without “fixing” CF.
