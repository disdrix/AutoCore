# Dual A/B report — W18-F OWN `0x007252d0` + `0x004ba310`

**Date:** 2026-07-29  
**Scope:** OWN ONLY VAs `0x007252d0`, `0x004ba310`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER.  
**Ghidra:** `decompile_function` + `read_memory` (+ complete analysis / callers / callees). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_007252d0` `CSoundManager_TickHardKillAndRegions_Inferred` | **accept-with-gaps** — EBX-this + two-phase hard-kill/region CF sealed; product name open |
| `aa_004ba310` `NDSpecialFX_Ctor` | **accept-with-gaps** — thiscall ctor + 0x240 host + name/list inits sealed; nested factory product names open |

---

## `0x007252d0` — CSoundManager_TickHardKillAndRegions_Inferred

### Sealed facts

1. **Body** `0x007252d0`–`0x0072589f` (1487 B).
2. **ABI:** **this in EBX**; stack **`int enableFlag`**, **`float dt`**; **`RET 8`**.
3. **Caller (1):** `Snd_UpdateSounds_UpdateSoundRegions` `0x00727440` — profile string `"UpdateSounds::updateSoundRegions()"` then `CALL`.
4. **Gates:** `DAT_00afa9b1`; non-empty `+0x28c` or `+0x29c` vectors; `enableFlag != 0`.
5. **Phase A:** hard-kill timers on `+0x28c` with dist/radius/re-arm (`g_flHardKillInterpolate`, clamp **4.0f**, random×**≈1/65536**).
6. **Phase B:** region walk under `DAT_00afa9b2`; may call `CSoundManager_StopMatchingSounds` `0x00723b20`.
7. **Tail:** `FUN_00415d60()`.

### Gaps

1. Product/PDB method name.  
2. Byte-level EBX setup at call site.  
3. Nested helper product names.  
4. Runtime / bit-exact / image diff.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_007252d0_CSoundManager_TickHardKillAndRegions_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_007252d0_CSoundManager_TickHardKillAndRegions_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_007252d0_CSoundManager_TickHardKillAndRegions_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_007252d0_CSoundManager_TickHardKillAndRegions_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_007252d0_CSoundManager_TickHardKillAndRegions_Inferred.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_007252d0_FUN_007252d0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CSoundManager_TickHardKillAndRegions_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_007252d0.cpp` |
| Raw | `docs/reconstruction/raw/aa_007252d0_FUN_007252d0.md` |
| Annotated | `docs/reconstruction/raw/aa_007252d0_FUN_007252d0.annotated.md` |
| Scratch | `tmp/a_007252d0.md` |

---

## `0x004ba310` — NDSpecialFX_Ctor

### Sealed facts

1. **Body** `0x004ba310`–`0x004ba545` (565 B).
2. **ABI:** **`__thiscall`** ECX=this; stack **`char *name`**; **`RET 4`**; returns **this**.
3. **Host size 0x240** (callers `operator_new(0x240)`).
4. **Inits:** flag clear; `DAT_009cb2a0` blocks; `g_flOne` scales; nested `FUN_0074ba00` @ `+0xa0`; six empty list heads; tree @ `+0x228`; tick @ `+0xd0`; **`strncpy(+0xd5, name, 0x104)`**.
5. **Callers (2):** `NDSpecialFX_InstantiateFromTemplate` `0x004a0b90`; `NDSpecialFX_ParseXmlEventNode` `0x004a4fa0`.
6. **Does not** set event type `+0x28` (callers write after).

### Gaps

1. Nested factory product names.  
2. Full 0x240 field map.  
3. `DAT_009cb2a0` exact type.  
4. Runtime / bit-exact / image diff.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_004ba310_NDSpecialFX_Ctor.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_004ba310_NDSpecialFX_Ctor.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004ba310_NDSpecialFX_Ctor.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004ba310_NDSpecialFX_Ctor.md` |
| Function record | `docs/reconstruction/functions/aa_004ba310_NDSpecialFX_Ctor.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_004ba310_FUN_004ba310.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDSpecialFX_Ctor.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_004ba310.cpp` |
| Raw | `docs/reconstruction/raw/aa_004ba310_FUN_004ba310.md` |
| Annotated | `docs/reconstruction/raw/aa_004ba310_FUN_004ba310.annotated.md` |
| Scratch | `tmp/a_004ba310.md` |

---

## AutoCore impact

- **FX load path:** client FX scripts allocate 0x240 hosts via `NDSpecialFX_Ctor` before parse/clone. Server need not mirror.
- **Audio:** hard-kill interpolate and region culling are pure client `CSoundManager` behavior.
- Do not merge `007252d0` with parent `00727440` — parent still owns slot volume/fade loops.

---

## This report

`docs/agents/task-dual-ab-007252d0-004ba310-w18f-report.md`
