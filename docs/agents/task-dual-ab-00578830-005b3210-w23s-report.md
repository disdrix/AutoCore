# Dual A/B report — W23-S OWN-ONLY (`aa_00578830`, `aa_005b3210`)

**Date:** 2026-07-29  
**Agent:** W23-S OWN-ONLY  
**Scope:** OWN ONLY VAs `0x00578830`, `0x005b3210`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / other parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00578830` CVOGHBSkillBase_DefaultCtor | **accept** — RTTI SkillBase empty shell; factory intermediate sealed (152 B) |
| `aa_005b3210` CVOGHBRespawnCharacter_ctor | **accept** — RTTI RespawnCharacter; dual-period + sole death-UI caller sealed (77 B) |

---

## Sealed facts — `0x00578830`

1. **ABI:** `__thiscall` ECX=`this`; **no stack formals**; returns `this`. Body **`0x00578830`–`0x005788c8`** (**152 bytes**). SEH `LAB_009a51f8`.

2. **RTTI:** vtbl `PTR_FUN_009d3fdc`; COL `0x00aaede0` → type_info `0x00af8cec` → **`.?AVCVOGHBSkillBase@@`** (**Confirmed**).

3. **Algorithm:** `CVOGHBBase_ctor` → install SkillBase vtbl → `FUN_0054f3c0` with **ECX=`this+0x24`** → zero tails (`+0x688`, `+0x6a0`, `+0x6b0..0x6b8`) → `AttachOwner(null)` → TFID block `+0x678` ← invalid sentinel `DAT_009d3f88` = `{FFFFFFFF,FFFFFFFF,0,0}`.

4. **Not full ctor:** sibling `CVOGHBSkillBase_ctor` @ `0x005788d0` adds blob copy, type tag `+0x1c=1`, ValidateTarget, attach target, SetPeriod.

5. **Callers:** skill-element factories (`operator_new(0x6c0)` → this → **subclass vtbl overwrite**); also catalog/register intermediates (`0054a640`, `0054f250`, `00618100`, …).

6. **Name:** `CVOGHBSkillBase_DefaultCtor` — class Confirmed; empty/default role High. Ghidra: `FUN_00578830`.

7. **Distinct from:** full cast ctor `005788d0`; other HB bases (Regeneration, WakeupSkill, RespawnCharacter).

---

## Sealed facts — `0x005b3210`

1. **ABI:** `__thiscall` ECX=`this`; stack **`pObject`**, **`periodMs`**; **`ret 8`**. Body **`0x005b3210`–`0x005b325d`** (**77 bytes**).

2. **RTTI:** vtbl `PTR_FUN_009d957c`; COL `0x00aaffac` → type_info `0x00af3e88` → **`.?AVCVOGHBRespawnCharacter@@`** (**Confirmed**).

3. **Algorithm:** `CVOGHBBase_ctor` → install RespawnCharacter vtbl → `SetPeriodAndCounter(1, true)` (`+0x0C`/`+0x10`=1) → **`this+0x08 = periodMs`** → AttachOwner null **or** MI this-adjust `pObject + 4 + *(*(pObject+4)+4)`.

4. **Sole caller:** `Client_LocalDeathUiSequence_Inferred` @ `0x00802170`: `operator_new(0x24)` → ctor(`*(client+0xe98)`, **300000**) → `CVOGHBList_Enqueue` + `CVOGHBBase_Start`.

5. **Name:** `CVOGHBRespawnCharacter_ctor` — class Confirmed. Ghidra: `FUN_005b3210`.

6. **Open residual:** OnHeartBeat / fire vfunc body (not this unit).

---

## Gaps

### `00578830`
1. Product/PDB English for this overload vs compiler default-ctor mangling.  
2. Full product names of zeroed tail fields (shared with full SkillBase ctor residual).  
3. Runtime / bit-exact / differential — open.

### `005b3210`
1. OnHeartBeat product semantics (vfunc residual).  
2. Precise product type of owner after this-adjust (expression sealed).  
3. Runtime / bit-exact / differential — open.

---

## Files

### `aa_00578830`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00578830_CVOGHBSkillBase_DefaultCtor.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00578830_CVOGHBSkillBase_DefaultCtor.md` |
| Function record | `docs/reconstruction/functions/aa_00578830_CVOGHBSkillBase_DefaultCtor.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00578830_FUN_00578830.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBSkillBase_DefaultCtor.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00578830.cpp` |
| Raw (authoritative body + re-verify append) | `docs/reconstruction/raw/aa_00578830_FUN_00578830.md` |
| Annotated | `docs/reconstruction/raw/aa_00578830_FUN_00578830.annotated.md` |
| Scratch | `docs/reconstruction/tmp/a_00578830.md` |

### `aa_005b3210`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_005b3210_CVOGHBRespawnCharacter_ctor.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005b3210_CVOGHBRespawnCharacter_ctor.md` |
| Function record | `docs/reconstruction/functions/aa_005b3210_CVOGHBRespawnCharacter_ctor.md` |
| Scaffold record | `docs/reconstruction/functions/aa_005b3210_FUN_005b3210.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBRespawnCharacter_ctor.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_005b3210.cpp` |
| Raw (authoritative body + re-verify append) | `docs/reconstruction/raw/aa_005b3210_FUN_005b3210.md` |
| Annotated | `docs/reconstruction/raw/aa_005b3210_FUN_005b3210.annotated.md` |
| Scratch | `docs/reconstruction/tmp/a_005b3210.md` |

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00578830-005b3210-w23s-report.md` |

---

## AutoCore impact

### `00578830`
- Port skill-element factories as **allocate large skill-HB → default SkillBase shell → install concrete subclass**.
- Do **not** merge with full cast ctor (`005788d0`) paths (ValidateTarget / period / attach target).
- Skill runtime at **`+0x24`** starts from partial default, not catalog blob, until subclass/full ctor fills it.

### `005b3210`
- Port local death as **client HB**: construct `CVOGHBRespawnCharacter` with period **300000** ms, enqueue, start.
- Dual-period layout: sentinel/counter via `SetPeriodAndCounter`; real pulse at **`+0x08`**.
- Keep distinct from skill-HB and other timed actions; fire path is a separate residual.
