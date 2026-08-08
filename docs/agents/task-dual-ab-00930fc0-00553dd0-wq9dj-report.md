# Dual A/B report — WQ9D-J OWN-ONLY (`aa_00930fc0`, `aa_00553dd0`)

**Date:** 2026-08-04  
**Agent:** WQ9D-J OWN-ONLY  
**Scope:** OWN ONLY VAs `0x00930fc0`, `0x00553dd0`. Dual A/B + trio raw/annotated/clean + function records.  
**Work item:** WQ-009 depth residual dual seal (skills-abilities / nested residual, priority depth beyond WQ-009 residual).  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + callers/xrefs/callees + function meta + `audit_globals_in_function`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth_partition_map.md` → **WQ9D-J**.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00930fc0` Ui_ResolveEntityNameColor_Inferred | **accept-with-gaps** — ABI/ret16/out ARGB/special colors/UI callers sealed; product English open |
| `aa_00553dd0` WorldClock_GetQuarterPhase01_Inferred | **accept-with-gaps** — ECX/FPU/cache/−1/quarter math/1/900/sole env caller sealed; product English open |

Path A (fidelity): both **accept-with-gaps** as above.  
Path B (adversarial): no CF rejects; cast-manager and skill-accuracy identity claims falsified; product symbols remain `_Inferred`.

---

## Sealed facts — `0x00930fc0`

1. **Body:** `0x00930fc0`–`0x009313bf` (**1023 B** / `0x3FF`). SEH frame; epilogue **`C2 10 00`** (`ret 16`).

2. **ABI:** MSVC **`__thiscall`**-style.  
   - `ECX` = **entity** (object with vtbl)  
   - stack: `clientCtx`, `uint32_t *outArgb`, `char flagAllowSelfStyle`, `char flagForcePalette`  
   - **`ret 16`**  
   - Writes **`*outArgb`**; decompiler `void` (EAX not the color)

3. **Role:** Client **UI entity name/label color** resolver relative to local player at **`clientCtx+0xe98`**. Callers are name-draw paths (`FUN_00836410` sprintf + color + text, `FUN_00838e20`, `FUN_00859bc0`, `FUN_009188c0`, `FUN_0091a350`) — **not** cast entry managers.

4. **Special ARGB (immediates):**  
   | Color | Value | Gate |  
   |---|---|---|  
   | Marked purple | `0xFFC364EB` | `vtbl+0x210` sub and `*(sub+0x6b4) > 0` |  
   | Dead gray | `0xFFEBEBEB` | `vtbl+0x1d8` + `Object_DefSubInt4e0_Equals1` (`0x0040b1b0`) |  
   | Owner lime | `0xDFCAFF0B` (α=`0xDF`) | `vtbl+0x214` → `Object_CopyTfid16At228` + `TFID_EqualsObjectId` vs local `+0x164` |  
   | Level band | pack RGB × **`255.0f`** (`DAT_00aaa6f8`), A=`0xFF` | identity present; `FUN_0092d580` band; levelDiff = `baseLevel - localLevel + entLevel` |

5. **Default path:** palette helper **`FUN_00930f40`** (not OWN) — fixed modes:  
   red `0xFFC41616`, beige `0xFFDCE0C8`, cyan `0xFF66D3EA`, green `0xFF14D314`, white `0xFFFFFFFF`.

6. **Other gates:** race via `Object_GetRootRaceId` + `FUN_00837e80`; **vehicle crew suppress** via dualed `VehicleCrew_ContainsMember_Inferred` (`0x005749d0`) on local `+0xcb0`; local `vtbl+0x298(entity)`; self/peer short-circuits to palette.

7. **Name:** `Ui_ResolveEntityNameColor_Inferred` — role **High**; product English **Inferred**. Supersedes scaffold `FUN_00930fc0`.

8. **Decompile ≡ raw CF** (live 2026-08-04 ≡ raw 2026-07-23).

### Gaps — `00930fc0`

1. Product/PDB symbol.  
2. English for `+0x6b4` purple counter.  
3. Product names for flagA / flagB.  
4. Full type of `clientCtx` beyond `+0xe98`.  
5. Dual of palette `FUN_00930f40` / band `FUN_0092d580` (not OWN).  
6. Runtime / bit-exact open.

---

## Sealed facts — `0x00553dd0`

1. **Body:** `0x00553dd0`–`0x00553f30` (**352 B** / `0x160`). Prologue `83 EC 14; 56; 8B F1`; bare **`C3`**.

2. **ABI:** **ECX = clock host**; result on **x87 ST0** (`float10` in decompiler); **no stack args**.

3. **Cache:** if `*(float*)(this+0x24) != DAT_00aaa668` (**-1.0**, `000080bf`) → return cached `+0x24`.

4. **Live compute:**  
   - `_time64` − int64 base at **`this+0x160/+0x164`**  
   - `_localtime64` → `secOfHour = tm_sec + tm_min * 60`  
   - `switch (this+0x154)`:  
     - 0: `phase = secOfHour`  
     - 1: `phase = secOfHour - 900` (`DAT_009cca58`)  
     - 2: `phase = secOfHour - 1800` (`DAT_009d25a4`)  
     - 3: `phase = secOfHour - 2700` (`DAT_009d25a0`)  
     - default: phase stays 0, **skip** scale  
   - cases 0–3: `phase *= DAT_00aaace0` ≈ **1/900** (`b4a2913a`)  
   - Sub-second: if `DAT_00b04750 == secOfHour`, add `Δtick * g_flMsToSeconds_Inferred * (1/900)` with wrap via `DAT_00aaa5dc` = **2^32**; else stamp tick + secOfHour  
   - Clamp to **`[0, g_flOne]`**

5. **Caller (1):** `FUN_004912c0` @ `0x00491300` — env light/audio day-cycle consumer (remaps phase by same mode). Sibling leaf `FUN_00553cd0` returns `this+0x15c` only.

6. **Not** `Skill_AccuracyHitCheck` (`0x00553240`): different body/callers; only shared global is the **-1.0** sentinel symbol.

7. **Name:** `WorldClock_GetQuarterPhase01_Inferred` — role **High** (quarter-hour phase ∈ [0,1]); product English **Inferred**.

8. **Decompile ≡ raw CF** (live re-verify 2026-08-04).

### Gaps — `00553dd0`

1. Product/PDB clock class name.  
2. Writers of `+0x24` cache and `+0x160` time base.  
3. Product English for modes 0..3 (math sealed as 15-min quarters).  
4. Runtime / bit-exact open.

---

## Files

### `aa_00930fc0`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00930fc0_Ui_ResolveEntityNameColor_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00930fc0_Ui_ResolveEntityNameColor_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00930fc0_Ui_ResolveEntityNameColor_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00930fc0_FUN_00930fc0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Ui_ResolveEntityNameColor_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00930fc0.cpp` |
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00930fc0_FUN_00930fc0.md` |
| Annotated | `docs/reconstruction/raw/aa_00930fc0_FUN_00930fc0.annotated.md` |
| Scratch | `docs/reconstruction/tmp/a_00930fc0.md` |

### `aa_00553dd0`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00553dd0_WorldClock_GetQuarterPhase01_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00553dd0_WorldClock_GetQuarterPhase01_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00553dd0_WorldClock_GetQuarterPhase01_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00553dd0_FUN_00553dd0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/WorldClock_GetQuarterPhase01_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00553dd0.cpp` |
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00553dd0_FUN_00553dd0.md` |
| Annotated | `docs/reconstruction/raw/aa_00553dd0_FUN_00553dd0.annotated.md` |
| Scratch | `docs/reconstruction/tmp/a_00553dd0.md` |

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00930fc0-00553dd0-wq9dj-report.md` |

---

## AutoCore impact

### `00930fc0`

- Port entity nameplate/label color as **out-param ARGB**, not EAX return.  
- Preserve specials: purple marked (`+0x6b4`), gray dead, lime owner TFID (α `0xDF`), level-band ×255, else fixed palette.  
- Reuse dualed leaves: `Object_CopyTfid16At228`, `TFID_EqualsObjectId`, `VehicleCrew_ContainsMember`.  
- Do **not** wire into cast RequestCast / LocalCastValidate — UI draw residual only.

### `00553dd0`

- Implement world-clock phase as **15-minute quarters of the hour** scaled by **1/900**, with **-1.0** cache sentinel at `+0x24` and optional sub-second tick blend.  
- Sole consumer is env blend (`FUN_004912c0`); not combat accuracy.  
- Keep mode field at `+0x154` and time base int64 at `+0x160`.

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` (and/or UI + environment system notes as appropriate)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).
