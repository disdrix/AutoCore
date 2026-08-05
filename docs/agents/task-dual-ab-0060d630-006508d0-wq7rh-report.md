# Dual A/B report — WQ7R-H OWN `aa_0060d630` + `aa_006508d0`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual WQ7R-H  
**Scope:** VAs `0x0060d630`, `0x006508d0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` + callers/callees/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Wave:** WQ-007 residual — callers of GiveMission / CompleteObjective.

---

## Verdict

| Unit | Name | Verdict |
|------|------|---------|
| `aa_0060d630` | `CVOGObjectiveRequirement_UseItem_ApplyObjectUseProgress` | **accept-with-gaps** — UseItem identity + progress/GiveMission CF sealed; world-obj local + flag English residual |
| `aa_006508d0` | `CVOGHBMissionEscort_OnHeartBeat` | **accept-with-gaps** — Escort OnHeartBeat identity + Complete/Fail arms sealed; distance field English residual |

---

## VA `0x0060d630` — sealed facts

1. **Body:** `0x0060d630`–`0x0060d7e1`.
2. **ABI:** **`__thiscall`**; three stack args; **`ret 0x0C`** (`C2 0C 00`); **AL** = 0|1.
3. **Class:** **`CVOGObjectiveRequirement_UseItem`** — vtable `PTR_FUN_009dfc1c`, COL→RTTI `.?AVCVOGObjectiveRequirement_UseItem@@`.
4. **Caller (1):** `FUN_0060df70` @`0x0060e061` — object-use events **9/10** after MatchTargetCore; calls this when event==10 or `req[0xd]==0`.
5. **Progress:** slot float at `progress+4+(byte)(req+0x08)*4` **+= 1.0** (same slot as `UseItem_Eval` `0x0060cfe0`).
6. **GiveMission residual:** on re-eval success, if `*(req+0x4c) != -1` → `CVOGReaction_GiveMission`.
7. **Also:** optional give CBIDs @+0x28 / @+0x48 via `FUN_005310a0`; remove inventory; optional world destroy (`FUN_004d0e90`).
8. **String:** `"Failed to give item %d to %I64d, objective %d mission: %S(%d)"` @`0x009e00a0` (shared with InitActive).
9. **Name:** `CVOGObjectiveRequirement_UseItem_ApplyObjectUseProgress` (Ghidra `FUN_0060d630`).
10. **Decompile ≡ image** for ABI entry/exit + CF arms.

### Gaps

- Decompiler `unaff_EBX` world-object binding (entry loads stack; mid-body residual).  
- Flag dictionary @+0x1c..+0x32 product English.  
- Event 9 vs 10 product labels.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0060d630_CVOGObjectiveRequirement_UseItem_ApplyObjectUseProgress.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0060d630_CVOGObjectiveRequirement_UseItem_ApplyObjectUseProgress.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0060d630_FUN_0060d630.md` |
| Annotated | `docs/reconstruction/raw/aa_0060d630_FUN_0060d630.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGObjectiveRequirement_UseItem_ApplyObjectUseProgress.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0060d630.cpp` |
| Function named | `docs/reconstruction/functions/aa_0060d630_CVOGObjectiveRequirement_UseItem_ApplyObjectUseProgress.md` |
| Function FUN | `docs/reconstruction/functions/aa_0060d630_FUN_0060d630.md` |
| Scratch | `docs/reconstruction/tmp/a_0060d630.md` |

---

## VA `0x006508d0` — sealed facts

1. **Body:** `0x006508d0`–`0x00650cf6`.
2. **ABI:** **`__thiscall`**; stack `EHBStatus* out`; **`ret 4`**; returns `out`.
3. **Class:** **`CVOGHBMissionEscort`** — COL `0x00ab1e9c` → TD `0x00af4a10` `.?AVCVOGHBMissionEscort@@`.
4. **Role:** **OnHeartBeat** — vtable `PTR_FUN_009e52c4` slot **+0x0C** (after dtor / StampLastFire / TryFire). Ctor `FUN_006507c0` installs vtable.
5. **Callers:** no static CALL; DATA bind only — invoked via `CVOGHBBase_TryFire` virtual.
6. **CompleteObjective residual:** on complete-zone hit → `CVOGReaction_CompleteObjective(missionKey, −1, −1, force=1)`.
7. **FailMission residual:** on target/mission lost → `CVOGReaction_FailMission` then **`FUN_005307e0` drain** (matches FailMission dual drain-YES table).
8. **Else:** `CVOGHBBase_RescheduleAfterFire`.
9. **Out status:** `*out = DAT_00af514c` = **16** (EHBStatus Remove family; not combat period).
10. **Not outpost:** adjacent string `"outpost"` @`0x009e52a4` is **not** class evidence (`CVOGHBOutpost` is separate RTTI).
11. **Name:** `CVOGHBMissionEscort_OnHeartBeat` (Ghidra `FUN_006508d0`).

### Gaps

- Product English for max escort distance / complete-zone object pair fields.  
- Exact Escort subclass field overlay vs Ghidra `CVOGHBBase` array view.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_006508d0_CVOGHBMissionEscort_OnHeartBeat.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_006508d0_CVOGHBMissionEscort_OnHeartBeat.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_006508d0_FUN_006508d0.md` |
| Annotated | `docs/reconstruction/raw/aa_006508d0_FUN_006508d0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBMissionEscort_OnHeartBeat.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_006508d0.cpp` |
| Function named | `docs/reconstruction/functions/aa_006508d0_CVOGHBMissionEscort_OnHeartBeat.md` |
| Function FUN | `docs/reconstruction/functions/aa_006508d0_FUN_006508d0.md` |
| Scratch | `docs/reconstruction/tmp/a_006508d0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0060d630` UseItem apply | Client optimistic UseItem progress: slot += 1, optional give/remove, **optional GiveMission** on complete. Server must still own grant authority; do not double-grant from this alone. |
| `006508d0` Escort HB | Client escort tracker: **CompleteObjective(force=1)** in zone; **FailMission+drain** if target lost. Mirror drain-after-fail; do not confuse with Patrol HB or Outpost HB. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory (+ callers/callees/xrefs).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Names evidence-backed: UseItem (mission requirement) + Escort (mission HB) — not outpost despite nearby string.
