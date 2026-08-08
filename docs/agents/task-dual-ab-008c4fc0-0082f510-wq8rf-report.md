# Dual A/B report — WQ8R-F OWN `aa_008c4fc0` + `aa_0082f510`

**Date:** 2026-08-04  
**Agent:** WQ8R-F (OWN-ONLY dual seal)  
**Scope:** OWN ONLY VAs `0x008c4fc0`, `0x0082f510`. Trio + clean + dual A/B + artifacts.  
**Work item:** **WQ-008** residual (inventory-transfer priority 94 — nested callees of dualed host/UI paths; these two are **skill-cast / UI command** leaves, not grid transfer).  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ function meta / callees / callers / xrefs). **No** `disassemble_bytes`.  
**Programs open:** `autoassault.exe` only (dual A/B = fidelity vs adversarial reviews).  
**Image base:** `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_008c4fc0` Client_CastFirstHardpointSkillFlag200_Inferred | **accept-with-gaps** — host gate, list lock-walk, RTTI skill filter, flag **0x200**, cast ABI sealed |
| `aa_0082f510` UI_Window_OnCommand_Class8_Inferred | **accept-with-gaps** — thiscall/`RET 8`, class-8 case map, skill **0xED5**, DATA vtable entry sealed |

---

## VA `0x008c4fc0` — Client_CastFirstHardpointSkillFlag200_Inferred

### Sealed facts

1. **Body:** `0x008c4fc0`–`0x008c50ca` (**267 B**). Live decompile ≡ 2026-07-23 raw.
2. **ABI:** no stack formals; `SUB ESP,8` / `ADD ESP,8` / `RET`.
3. **Gate:** `DAT_00d1b6d8 != 0` and `*(char*)(player+0x6b8) != 0`.
4. **List host:** if `player+0x30c==0` **or** `player+0x250==0` → list `*(MI(player)+0xb4)`; else list on **vehicle** `*(MI(vehicle)+0xb4)`.
5. **Walk:** `List_TraversalLock` (`FUN_004294f0`) + `List_IterateNext` (`FUN_004022a0`); unlock LeaveCS if `list+0x28`.
6. **Filter:** node `+0x1c==1`, `__RTDynamicCast` `CVOGHBBase`→`CVOGHBSkillBase`, `skillHb+0x140≠0` → skill runtime = **base+0x24**; **first** match only.
7. **Cast:** if `skill+0x614 & 0x200`: `PUSH [skill+0x5fc]`; `MOV ESI,&DAT_00d1a840`; `CALL Client_CastSkillFromQuickBarSlot`.
8. **Sole caller:** `FUN_008c50f4` @ `0x008c510f` when `+0x6b8 && !+0x6b9` (else parent may call `Client_Input_TryUseModChip`).
9. **Three-rep:** raw CF + annotated + named clean; full body hex in raw append.

### Gaps

1. Product English for `+0x6b8` / `+0x30c` / list at `MI+0xb4`.  
2. Product name of skill flag bit **0x200**.  
3. PDB / retail symbol.  
4. Runtime case-8 / `0x9c40` path capture; bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_008c4fc0_Client_CastFirstHardpointSkillFlag200_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_008c4fc0_Client_CastFirstHardpointSkillFlag200_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_008c4fc0_Client_CastFirstHardpointSkillFlag200_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_008c4fc0_Client_CastFirstHardpointSkillFlag200_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_008c4fc0_Client_CastFirstHardpointSkillFlag200_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_008c4fc0_FUN_008c4fc0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_CastFirstHardpointSkillFlag200_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_008c4fc0.cpp` |
| Raw (+ WQ8R-F append) | `docs/reconstruction/raw/aa_008c4fc0_FUN_008c4fc0.md` |
| Annotated | `docs/reconstruction/raw/aa_008c4fc0_FUN_008c4fc0.annotated.md` |

Sibling context (not owned): parent `FUN_008c50f4` / cmd `(8,0x9c40)` gate; `Client_Input_TryUseModChip` `0x0091f6b0`; `Client_CastSkillFromQuickBarSlot` `0x009418e0`; `List_TraversalLock` / `List_IterateNext`.

---

## VA `0x0082f510` — UI_Window_OnCommand_Class8_Inferred

### Sealed facts

1. **Body:** `0x0082f510`–`0x0082f78f` (**640 B**). Live decompile ≡ 2026-07-23 raw.
2. **ABI:** `__thiscall` ECX=`this`; stack `(cmdClass, cmdId)`; **`RET 8`**.
3. **Entry:** **0** direct CALL; DATA vtable slot **`0x00a72514`** = this VA.
4. **Dead-vehicle gate:** if `cmdId!=10` && player && vehicle@`+0x250` && vehicle MI `vtbl+0x194()` → `this.vtbl+0x47c()`; return `FUN_0082c780(class,id)`.
5. **Class-8 switch** (jump table `@0x0082f794`, cases 1..0xd):
   - **1:** `Client_CastSkillFromQuickBarSlot(0xED5)` with ESI=`&DAT_00d1a840`; return 1  
   - **2,3:** no-op → return 1  
   - **4 / 5 / 0xb:** dialog globals `DAT_00d1b874` / `870` / `880` + `vtbl+0x3d8` + `FUN_007fca10` / `FUN_007fef20` / show helpers  
   - **6..10, 0xc, 0xd:** `FUN_007fef20` with indices **2, 0x12, 0x13, 0x11, 0x29, 3, 5** (case map sealed in raw/annotated)
6. **Fallback:** if not handled and `cmdId!=70000` → `FUN_0082c780`; else return 1.
7. **Three-rep:** raw CF + annotated + named clean; full body hex + jump table in raw append.

### Gaps

1. Product / RTTI class for vtable containing `0x00a72514`.  
2. Skill product name for id **0xED5**.  
3. Dialog global / `FUN_007fef20` index English.  
4. Why cmdId **10** skips dead-vehicle divert.  
5. Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_0082f510_UI_Window_OnCommand_Class8_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_0082f510_UI_Window_OnCommand_Class8_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0082f510_UI_Window_OnCommand_Class8_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0082f510_UI_Window_OnCommand_Class8_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_0082f510_UI_Window_OnCommand_Class8_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_0082f510_FUN_0082f510.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_Window_OnCommand_Class8_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0082f510.cpp` |
| Raw (+ WQ8R-F append) | `docs/reconstruction/raw/aa_0082f510_FUN_0082f510.md` |
| Annotated | `docs/reconstruction/raw/aa_0082f510_FUN_0082f510.annotated.md` |

Sibling context (not owned): base `FUN_0082c780`; dualed `Client_CastSkillFromQuickBarSlot`; dialog patterns shared with `Client_Input_PollBoundActions` (menu section).

---

## This report

`docs/agents/task-dual-ab-008c4fc0-0082f510-wq8rf-report.md`

Shared: both are **callers of** sealed `Client_CastSkillFromQuickBarSlot` (hardpoint flag path vs UI hardcoded **0xED5**). Co-owned only by WQ8R-F partition assignment. Trio (raw/annotated/clean) + dual A/B filed per VA. **No parent ledger edits.**

---

## AutoCore impact

- **Host hardpoint cast (`0x008c4fc0`):** When implementing host-mode UI (parent `+0x6b8 && !+0x6b9`), port must TraversalLock-walk HB list on player/vehicle, pick first enabled `CVOGHBSkillBase`, and cast only if skill flags include **0x200** — do not invent multi-cast or inventory mutate. Client for cast is global singleton (`DAT_00d1a840` / ESI), skill id at **`+0x5fc`**.
- **UI class-8 OnCommand (`0x0082f510`):** Window command class **8** id **1** fires fixed skill **0xED5** through the same cast helper; other ids are dialog toggles / base forward — not inventory transfer. Dead vehicle diverts via `vtbl+0x194` / `+0x47c` except cmdId **10**.
- Neither unit requires Launcher for static seal completeness; runtime Confirmed remains open. Terminal false.
