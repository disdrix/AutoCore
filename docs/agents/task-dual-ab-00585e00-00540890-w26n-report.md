# Dual A/B report — W26-N OWN `aa_00585e00` + `aa_00540890`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W26-N  
**Scope:** VAs `0x00585e00`, `0x00540890` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers/callees). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00585e00` CVOGGraphicsBase_PostLoadScaleAndSelectFx | **accept-with-gaps** — ABI/CF/constants + caller class sealed; method English Probable |
| `aa_00540890` Host_AIProfileMap_GetOrReset | **accept-with-gaps** — ABI/CF/map layout sealed; product host/map English open |

---

## VA `0x00585e00` — sealed facts

1. **Body:** `0x00585e00`–`0x00586056` (**599 B** inclusive last RET; pad `CC` after).
2. **ABI:** **thiscall**; ECX=`this`; stack `char skipSideFx`; **`RET 4`**; return **x87 ST0** float (early `g_flZero`).
3. **Semantics:** Gate on graphics `this+8` + `FUN_005130e0(1)`; compute **reciprocal mesh scale** via `2.0/(s*2.0)`; host vtbl `+0xB8(scale)`; Y-lift + `FUN_004e88e0`; graphics vtbl `+0x10(3,&xyz)`; if `!skipSideFx`: optional near-**50** `Object_PlayPickupSpecialFX` + LogicUI type **0x1F** (payload **3.5**).
4. **Classification:** **worker**.
5. **Caller (1):** `FUN_00586060` / `CVOGGraphicsBase::InitializeGraphics` @ `0x0058645a` with `(0)` when `(obj+0x188)&1`.
6. **Name:** `CVOGGraphicsBase_PostLoadScaleAndSelectFx` (Ghidra `FUN_00585e00`; class from caller plate).
7. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product method English (no plate on this VA).  
- Vtbl slot English (`+0x10` mode 3, host `+0xB8`).  
- Misnamed `g_flLevelUpUiBase_Inferred` (value **2.0** sealed).  
- Runtime FPU / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00585e00_CVOGGraphicsBase_PostLoadScaleAndSelectFx.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00585e00_CVOGGraphicsBase_PostLoadScaleAndSelectFx.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00585e00_FUN_00585e00.md` |
| Annotated | `docs/reconstruction/raw/aa_00585e00_FUN_00585e00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGGraphicsBase_PostLoadScaleAndSelectFx.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00585e00.cpp` |
| Function | `docs/reconstruction/functions/aa_00585e00_FUN_00585e00.md` |
| Function named | `docs/reconstruction/functions/aa_00585e00_CVOGGraphicsBase_PostLoadScaleAndSelectFx.md` |
| Scratch | `docs/reconstruction/tmp/a_00585e00.md` |

---

## VA `0x00540890` — sealed facts

1. **Body:** `0x00540890`–`0x005408e9` (**90 B** inclusive last RET; pad `CC` after).
2. **ABI:** **thiscall**; ECX=host (callers: `DAT_00b041fc`); stack `char forceReset`; **`RET 4`**; **EAX** = `host+0xF00`.
3. **Semantics:** If `size==0` **OR** `forceReset!=0`: free RB tree (`FUN_005436c0`), re-link MSVC sentinel head, size=0, `FUN_007c3b80(map)`; always return map base.
4. **Layout:** map `@+0xF00`, head `@+0xF04`, size `@+0xF08`.
5. **Callers (5+):** HBAI DoLogic twins + `FUN_004c9430` / `FUN_004c9120` / `FUN_005d7ca0` (profile lower_bound pair with `FUN_004cbd50`).
6. **Callees:** `FUN_005436c0`, `FUN_007c3b80` (ECX=`DAT_00b0469c`).
7. **Name:** `Host_AIProfileMap_GetOrReset` (Ghidra `FUN_00540890`).
8. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product host / map value_type English.  
- Nested `FUN_007c3b80` / `FUN_005436c0` (not OWN).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00540890_Host_AIProfileMap_GetOrReset.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00540890_Host_AIProfileMap_GetOrReset.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00540890_FUN_00540890.md` |
| Annotated | `docs/reconstruction/raw/aa_00540890_FUN_00540890.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Host_AIProfileMap_GetOrReset.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00540890.cpp` |
| Function | `docs/reconstruction/functions/aa_00540890_FUN_00540890.md` |
| Function named | `docs/reconstruction/functions/aa_00540890_Host_AIProfileMap_GetOrReset.md` |
| Scratch | `docs/reconstruction/tmp/a_00540890.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00585e00` | After graphics init flag bit0: apply `scale=1/meshScale`, mode-3 pose, optional near-50 pickup FX + LogicUI **0x1F**/3.5. Do not treat the 2.0 constant as level-up UI. |
| `00540890` | HBAI profile lookup requires this map get (with skip-clear when populated) before `FUN_004cbd50` lower_bound; end-it = head at map+4. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/callees).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.
