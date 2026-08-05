# Dual A/B report — W36-F OWN `aa_005575c0` + `aa_005c6ad0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W36-F  
**Scope:** VAs `0x005575c0`, `0x005c6ad0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + xrefs + caller decompile. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave36_partition_map.md` → **W36-F**.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005575c0` WeatherHost_ApplyEnvTime_Inferred | **accept-with-gaps** — ECX host + slot + RET 4 + nfx fill/activate + AssPreload yield + 5000 ms blend sealed; product host English open |
| `aa_005c6ad0` CLoadNode_WaitAssPreloadKeyRing_Inferred | **accept-with-gaps** — ECX node + stack ring + RET 4 + EAX 0/3 + counter 1..6 + ProcessKeyRingStep sealed; product method English open |

---

## VA `0x005575c0` — sealed facts

1. **Body:** `0x005575c0`–`0x005579be` exclusive (**1022 B** / `0x3FE`); terminal **`C2 04 00`**; pad `CC` then `FUN_005579c0`.
2. **ABI:** **`__thiscall`**; **ECX = weather host** (`MOV ESI,ECX`); stack **`uint8_t env_time_slot`**; **`RET 0x4`**.
3. **Semantics:** Apply env-time / TOD slot on weather host:
   - Gate `host+0x178`; lookup via `FUN_00558eb0`; forgotten-weather path seeds `env_time_{dawn,midday,sunset,night}` + log string.
   - If current weather* (`+0x17c`) non-null and `weather+0x54c == slot` → return.
   - On slot change vs `+0x1b8`: **fill** nfx list `+0x190` (mode 0, sealed W32-I), coop `AssPreloader_ProcessKeyRingStep` (W35-A) → `+0x1bc`; yield → ExpandDeps (W32-K, **ECX=AssPreloader**) and return.
   - Retry fill step with flag=1 if needed; then **activate** list `+0x1a4` (mode 1) + same key-ring pattern → `+0x1bd`.
   - Transition blend over **`_DAT_00af2ce8 = 5000.0f`** ms (tick wrap `2^32`); commit prev/cur; optional unload when `DAT_00b03e64`; `FUN_00555f10(+0x188)`.
4. **Classification:** worker — weather transition orchestrator over sealed nfx + AssPreloader.
5. **Callers (1 / 2 xrefs):** `FUN_005579c0` @ `00557a61`, `00557a7b`.
6. **Name:** `WeatherHost_ApplyEnvTime_Inferred` (Ghidra `FUN_005575c0`; **Inferred** structural).
7. **Decompile ≡ raw CF**; **bytes win** on ExpandDeps ECX=AssPreloader (decompiler shows thiscall on ring).  
   Entry/epilogue/call-site hex: raw W36-F append.

### Gaps

- Product/PDB weather host class English.  
- Unowned lookup/seed/apply helpers (`00558eb0`, `00556da0`, `00555f10`).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005575c0_WeatherHost_ApplyEnvTime_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005575c0_WeatherHost_ApplyEnvTime_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005575c0_FUN_005575c0.md` |
| Annotated | `docs/reconstruction/raw/aa_005575c0_FUN_005575c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/WeatherHost_ApplyEnvTime_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005575c0.cpp` |
| Function | `docs/reconstruction/functions/aa_005575c0_FUN_005575c0.md` |
| Function named | `docs/reconstruction/functions/aa_005575c0_WeatherHost_ApplyEnvTime_Inferred.md` |

---

## VA `0x005c6ad0` — sealed facts

1. **Body:** `0x005c6ad0`–`0x005c6b3e` exclusive (**110 B** / `0x6E`); both exits **`C2 04 00`**; pad `CC`.
2. **ABI:** **`__thiscall`**; **ECX = CLoadNode / wait host**; stack **`GuardedVector* ring`**; **`RET 0x4`**; **EAX = 0 ready / 3 wait**.
3. **Semantics:** Cooperative stage wait on AssPreloader key ring:
   - Empty ring (`size@+0x10 == 0`): counter `host+0x54 = 0`; return **0**.
   - If counter **∉ [1,6]**: reset if **>6**; if AssPreloader `*(DAT_00d1f050+0x6c)` live → ExpandDeps(preloader, ring).
   - `progress_flag = 1`; `ProcessKeyRingStep(ring, &flag, &host->cursor@+0x5c)`.
   - Yield (AL 0): counter++; return **3**. Ready: counter=0; return **0**.
4. **Classification:** worker — thin CLoadNode wait shell over sealed AssPreloader step.
5. **Callers (5 / 6 xrefs):** `FUN_005c72f0` (`_initPreload`, ring **+0x174**), `FUN_005c7400`, `FUN_005c76f0` (`_initPhysics`, **+0x14c**), `FUN_005c78a0`, `FUN_005c79f0`.
6. **Name:** `CLoadNode_WaitAssPreloadKeyRing_Inferred` (Ghidra `FUN_005c6ad0`; **Inferred**). Reject scaffold `Named_CalleeOf_*`.
7. **Decompile ≡ bytes** for CF; **bytes win** on ECX=host (not ring) and ExpandDeps this; decompiler `CONCAT31` is flag-slot reuse.  
   Full hex: raw W36-F append (110 B).

### Gaps

- Product/PDB CLoadNode method English.  
- Product meaning of counter band 1..6 beyond structural retry budget.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005c6ad0_CLoadNode_WaitAssPreloadKeyRing_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005c6ad0_CLoadNode_WaitAssPreloadKeyRing_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005c6ad0_FUN_005c6ad0.md` |
| Annotated | `docs/reconstruction/raw/aa_005c6ad0_FUN_005c6ad0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CLoadNode_WaitAssPreloadKeyRing_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005c6ad0.cpp` |
| Function | `docs/reconstruction/functions/aa_005c6ad0_FUN_005c6ad0.md` |
| Function named | `docs/reconstruction/functions/aa_005c6ad0_CLoadNode_WaitAssPreloadKeyRing_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005575c0` | Port as weather host **apply env-time**: **ECX=host**, stack **slot**, **RET 0x4**. Yielding nfx preload (fill `+0x190` / activate `+0x1a4`) must call sealed ProcessKeyRingStep and ExpandDeps with **AssPreloader this**. Transition window **5000 ms**. Do **not** treat as single-shot non-yielding TOD set. |
| `005c6ad0` | Port as CLoadNode **coop wait**: **ECX=node**, stack **ring***, **RET 0x4**, return **0/3**. Counter `+0x54` band 1..6; cursor `+0x5c`. Do **not** put ring in ECX. Do **not** map returns to ProcessKeyRingStep AL 0/1 alone. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x00556b10` | `Weather_NfxListFillOrActivate_Inferred` (W32-I) — fill/activate lists |
| `0x004ed310` | `AssPreloader_ProcessKeyRingStep_Inferred` (W35-A) — both units call |
| `0x00971820` | `AssPreloader_ExpandDepsAndEnqueueFromRing_Inferred` (W32-K) — both units call |
| `0x005579c0` | sole weather parent of `005575c0` |
| `0x005c72f0`… | CLoadNode stage parents of `005c6ad0` |
| `0x00af2ce8` | 5000.0f transition window |
| `0x00d1f050+0x6c` | AssPreloader* gate |

Together they close two high-level **AssPreloader consumers**: weather nfx transition orchestration and CLoadNode stage wait — both layered on the already-sealed key-ring step + ExpandDeps pair.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory (+ complete analysis / xrefs / caller decompile). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; `_Inferred` structural names only.  
- Rejected scaffold `Named_CalleeOf_*` for `005c6ad0`.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).

---

## This report

`docs/agents/task-dual-ab-005575c0-005c6ad0-w36f-report.md`
