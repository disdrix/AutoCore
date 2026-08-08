# Dual A/B report — gap-close OWN `aa_008c50f4`

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual gap-close  
**Scope:** VA `0x008c50f4` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Note:** Live Ghidra VA was **missing from inventory.jsonl** at task start — sealed from live tools.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_008c50f4` Client_UI_Cmd8_Id9c40_HostSkillOrModChip_Inferred | **accept-with-gaps** — ESI this + RET 8 ABI, host/mod-chip CF, callees, widget float tail sealed; product UI class / cmd English / widget type / runtime open |

**Terminal:** false (partial — runtime/diff open; not reject).

---

## VA `0x008c50f4` — sealed facts

1. **Body:** `0x008c50f4`–`0x008c516A` exclusive (**118 B** / `0x76`; pad `CC×6` then next @ `0x008c5170`). Last insn `RET 8` (`C2 08 00`).
2. **ABI (bytes win over Ghidra `void`):**  
   - No CALL sites. Entry via **JZ** from gate @ `0x008c50e5` (preceding trampoline `0x008c50d0`, **not** a Ghidra function).  
   - Gate: thiscall `ECX=self`, stack `(cmdClass, cmdId)`; on **`(8, 0x9c40)`** does `PUSH ESI; MOV ESI,ECX; JZ body`.  
   - Body: consumes **`ESI=self`**, ends **`MOV AL,1; POP ESI; RET 8`**.  
   - Decompiler `unaff_ESI` = intentional this, **not** free register noise.  
   - Logical signature: `bool __thiscall (void* self, int cmdClass, int cmdId)`.
3. **Semantics:** UI OnCommand specialized island for **class 8 / id 0x9c40**:
   - If `DAT_00d1b6d8==0` → still return 1 (no action).  
   - If `player+0x6b8 && !player+0x6b9` → `Client_CastFirstHardpointSkillFlag200_Inferred` (`0x008c4fc0`).  
   - Else if `DAT_00d1b778 && vtbl+0x3d8()` → `Client_Input_TryUseModChip` (`0x0091f6b0`, **EDX**=`DAT_00d1b778`).  
   - If `self+0x514` → child widget float **get** `vtbl+0x3c8` then **set** `vtbl+0x3b0`.  
   - Always **return 1** (handled).
4. **Classification:** worker.
5. **Callers:** 0 CALL; 1 CONDITIONAL_JUMP from gate. Non-match gate path → `FUN_0087b500` (context).
6. **Name:** `Client_UI_Cmd8_Id9c40_HostSkillOrModChip_Inferred` (Ghidra `FUN_008c50f4`; **Inferred** from cmd pair + dualed branches). Reject bare void / inventory / full class-8 switch names.
7. **Decompile ≡ bytes** for CF/callees/flags; **bytes win** on ESI this, RET 8, body bounds, return 1. Full hex in raw.

### Gaps

- Product/PDB UI class; DATA vtable slot for gate `0x008c50d0`.  
- Product English for `(8, 0x9c40)` in this dialog (`0x9c40` is close-id elsewhere).  
- Type of `DAT_00d1b778` and `vtbl+0x3d8` probe semantics.  
- Type of `self+0x514` widget; why get-then-set float.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_008c50f4_Client_UI_Cmd8_Id9c40_HostSkillOrModChip_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_008c50f4_Client_UI_Cmd8_Id9c40_HostSkillOrModChip_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_008c50f4_FUN_008c50f4.md` |
| Annotated | `docs/reconstruction/raw/aa_008c50f4_FUN_008c50f4.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_UI_Cmd8_Id9c40_HostSkillOrModChip_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_008c50f4.cpp` |
| Function | `docs/reconstruction/functions/aa_008c50f4_FUN_008c50f4.md` |
| Function named | `docs/reconstruction/functions/aa_008c50f4_Client_UI_Cmd8_Id9c40_HostSkillOrModChip_Inferred.md` |
| Report | `docs/agents/task-dual-ab-008c50f4-gap-close-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `008c50f4` | Port as **UI OnCommand special-case `(8, 0x9c40)`**: thiscall **`self, cmdClass, cmdId`**, **`RET 8`**, always **true**. Host path → dualed hardpoint cast; else optional dualed mod-chip via `DAT_00d1b778`. Preserve optional `self+0x514` float get/set. Do **not** implement as bare `void f(void)` or invent stack formals inside the body without the gate ESI frame. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x008c50d0` | Gate trampoline (not a Ghidra function) |
| `0x0087b500` | Generic thiscall forward for other `(class,id)` |
| `0x008c4fc0` | `Client_CastFirstHardpointSkillFlag200_Inferred` (host leaf) |
| `0x0091f6b0` | `Client_Input_TryUseModChip` (mod-chip leaf) |
| `0x0082f510` | `UI_Window_OnCommand_Class8_Inferred` (related class-8 switch, different VA) |
| `DAT_00d1b6d8` | Local character |
| `DAT_00d1b778` | UI probe / mod-chip EDX |

Together this closes the **missing inventory parent** that dispatches dualed host-cast vs mod-chip leaves under UI command `(8, 0x9c40)`.

---

## Process

- OWN VA only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze + read_memory + callers/xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- ABI sealed carefully: `unaff_ESI` = custom thiscall ESI from gate.  
- No invented product plates; `_Inferred` name only.  
- Avoided bare `undefined4` in clean (`bool` / `void*` / explicit vtbl helpers).
