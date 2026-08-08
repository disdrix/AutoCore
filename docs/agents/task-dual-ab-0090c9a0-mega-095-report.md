# Dual A/B report — MEGA-095 OWN-ONLY (`0x0090c9a0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-095**  
**Scope:** VA `0x0090c9a0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + callers/xrefs + `read_memory` + parent listing `0x0090cbc0`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — Medal UI apply/toggle slot button (parent `0x0090cbc0`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0090c9a0` MedalUi_ApplyAchievementSlotButton_Inferred | **accept-with-gaps** — CF/ABI/RET8/ESI·EBX/2 call sites/string/grid/flag-path sealed; product host/widget English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): VOG_DEBUG_STOP purpose / void-no-args / cdecl / skill-award / 4-col layout claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0090c9a0` — sealed facts

1. **Body:** `0x0090c9a0`–`0x0090cbbb` inclusive (**540 B** / `0x21C`).
2. **ABI:** **ESI** = medal UI host; **EBX** = slot index; stack `MedalDef*`, `earnedFlag`; void; **`RET 8`**.
3. **Semantics:** Medal UI **apply/toggle** one achievement slot button:
   - `operator_new(0x488)` + `FUN_007b5dd0` widget ctor.
   - Store at `host+0x540[slot]`; host attach vfunc `+0xa8`.
   - Load layout `"i_d_a_2d_btn_achievement.xml"`.
   - **3-column** grid: `row=slot/3`, `col=slot%3`; scales `DAT_00aaa678≈0.0008333334f`, `DAT_00aaa67c≈0.000625f` × runtime `DAT_00d1e81c/818`.
   - Bind texture: C-string at `medalDef+0x10` + `".dds"` (`DAT_00a2c53c`).
   - Control id `slot+0x9c43`; per-slot byte `host+0x510+slot = medalDef[0]`.
   - If `earnedFlag==0`: dim/lock via vfunc `+0x164(2)` → `+0x154(0,mode)`.
4. **Callees (named):** `operator_new` @ `0x00489892`; `FUN_007b5dd0` @ `0x007b5dd0`.
5. **Callers:** sole `FUN_0090cbc0` — sites `0x0090ccea` (flag=1 owned) and `0x0090cdb4` (flag=0 unowned).
6. **Xrefs:** 2 UNCONDITIONAL_CALL.
7. **Name:** `MedalUi_ApplyAchievementSlotButton_Inferred` (Ghidra `FUN_0090c9a0`). Retire `Named_CalleeOf_Named_VOG_DEBUG_STOP_0090c9a0`. Plate alias `UI_a_btn_achievement` retained as evidence.
8. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + parent call-site context + `read_memory`.

### Gaps

- Product English for host panel / `FUN_007b5dd0` widget class.  
- Vtable method English for offsets used.  
- Runtime values of `DAT_00d1e818` / `DAT_00d1e81c`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0090c9a0_MedalUi_ApplyAchievementSlotButton_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0090c9a0_MedalUi_ApplyAchievementSlotButton_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0090c9a0_FUN_0090c9a0.md` |
| Annotated | `docs/reconstruction/raw/aa_0090c9a0_FUN_0090c9a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MedalUi_ApplyAchievementSlotButton_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0090c9a0.cpp` |
| Function | `docs/reconstruction/functions/aa_0090c9a0_FUN_0090c9a0.md` |
| Function named | `docs/reconstruction/functions/aa_0090c9a0_MedalUi_ApplyAchievementSlotButton_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0090cbc0  Medal UI panel fill  [partition parent; residual]
  ├─ FUN_0090c700 / FUN_0090c810   clear/count helpers  [residual]
  ├─ MedalDef_LookupById (FUN_0051a0e0)  [dualed]
  ├─ owned vector walk @ char+0x574..578
  │     └─ FUN_0090c9a0(medalDef, 1)  [OWN MEGA-095]
  └─ hash traverse @ char+0x540 (lock +0x1d)
        └─ FUN_0090c9a0(medalDef, 0)  [OWN MEGA-095]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0090c9a0-mega-095-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0090c9a0` | Port as **medal UI slot button apply/toggle**. Register formals **ESI=host**, **EBX=slot**; stack **MedalDef\*** + **earnedFlag**; **RET 8**. Create 0x488 widget, load `i_d_a_2d_btn_achievement.xml`, 3-col grid, bind `name+".dds"`, id `slot+0x9c43`, dim when unowned. |
| Pair with | parent panel fill `0090cbc0`; dualed `MedalDef_LookupById` `0051a0e0`; widget ctor `007b5dd0`. |
| Do not | treat as VOG_DEBUG_STOP helper; award medals; use cdecl; ignore ESI/EBX. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` missions-progression residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x0090c9a0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs + parent call-site context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean sources use meaningful name; machine twin `FUN_0090c9a0.cpp` kept; **Named_CalleeOf_** scaffold retired.  
- Odd behavior preserved: static `DAT_00d1e818/81c` are zero in image; decompiler void/unaff corrected via listing.  
- `_Inferred` where product English unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
