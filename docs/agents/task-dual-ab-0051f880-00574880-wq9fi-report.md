# Dual A/B report — WQ9F-I OWN-ONLY (`aa_0051f880`, `aa_00574880`)

**Date:** 2026-08-04  
**Agent:** WQ9F-I OWN-ONLY  
**Scope:** OWN ONLY VAs `0x0051f880`, `0x00574880`. Dual A/B + trio raw/annotated/clean + function records.  
**Work item:** WQ-009 depth-3 residual — skill neighborhood host-mode flag leaf + crew/convoy leader residual leaf.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth3_partition_map.md`  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / VERIFICATION_MATRIX / NAMING_REGISTRY / systems residual / other parent ledgers.  
**Ghidra:** `batch_decompile` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Terminal:** **false**

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0051f880` Object_SetHostModeFlag_Inferred | **accept-with-gaps** — 13 B CF/ABI/offset sealed; host-mode role High from readers + Fire/OnEnd polarity; product English open |
| `aa_00574880` ConvoyRoster_GetLeaderMember_Inferred | **accept-with-gaps** — 28 B CF/ABI/slot algebra sealed; leader gate role High at UI consumers; product type name open |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): no CF rejects; sole-writer exclusivity, product demangle Confirmed, enhanced-flag confusion, ret-4 on leader getter all **rejected/falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## Sealed facts — `0x0051f880` Object_SetHostModeFlag_Inferred

1. **Body:** `0x0051f880`–`0x0051f88c` inclusive (**13 B**); `CC` pad from `0x0051f88d`.

2. **ABI:** MSVC **`__thiscall`**.  
   - `ECX` = character/object this  
   - stack `uint8_t` flag  
   - void  
   - **`ret 4`** (`C2 04 00`)

3. **Algorithm:**  
   - `MOV AL, [ESP+4]`  
   - `MOV [ECX+0x6b8], AL`  
   - return  
   - No branches, no callees

4. **Bytes:** `8a 44 24 04 88 81 b8 06 00 00 c2 04 00`

5. **Callers (2):**  
   - `Skill_HB_FireTail_FxTargetAndPeriodStamp` (`0x00578b30`) @ `0x00578c78` — **`push 1`** after target `vtbl+0x210(0)`  
   - `Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred` (`0x00578ce0`) @ `0x00578dd1` — **`push 0`** inverse

6. **Twin:** `Object_SetEnhancedStateFlag_Inferred` `0x0051f890` identical leaf for `+0x6b9`.

7. **Role:** host-mode / vehicle-host gate byte. Readers (not OWN): hardpoint cast when `player+0x6b8`; QuickBar remaps with `+0x6b9` pair; parent prefers `+0x6b8 && !+0x6b9`.

8. **Name:** `Object_SetHostModeFlag_Inferred` — role High; product English **Inferred**.  
   Reject prior `Named_CalleeOf_Skill_Skill_d_has_invalid_frequency_d_0051f880`.

9. **Decompile ≡ disasm ≡ bytes**.

### Gaps — `0051f880`

1. Product/PDB method name.  
2. Exhaustive writer catalog beyond 2 static CALLs.  
3. Neighboring status bytes `+0x6ba/+0x6bb` inventory.  
4. Runtime / bit-exact open.

### Dual A/B — `0051f880`

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0051f880_Object_SetHostModeFlag_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0051f880_Object_SetHostModeFlag_Inferred.md` | **accept-with-gaps** |

### Files — `0051f880`

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0051f880_FUN_0051f880.md` |
| Annotated | `docs/reconstruction/raw/aa_0051f880_FUN_0051f880.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_SetHostModeFlag_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0051f880.cpp` |
| Function | `docs/reconstruction/functions/aa_0051f880_FUN_0051f880.md` |
| Function named | `docs/reconstruction/functions/aa_0051f880_Object_SetHostModeFlag_Inferred.md` |

---

## Sealed facts — `0x00574880` ConvoyRoster_GetLeaderMember_Inferred

1. **Body:** `0x00574880`–`0x0057489b` inclusive (**28 B** / `0x1c`); `CC` pad after.

2. **ABI:** ECX = roster/crew host; **no stack args**; plain **`RET`** (`C3`); EAX = member* or 0.

3. **Algorithm:**  
   - If `*(uint8_t*)(this+0x1d8) == 0`: return 0  
   - `slot = *(int*)(this+0x194)`  
   - return `*(this + (slot + 0x1a) * 0x10)`  // = `this+0x1a0 + slot*0x10`

4. **Identity:** same slot algebra as `ConvoyRoster_GetMemberBySlot_Inferred` (`0x00574760`) without 0..3 bounds. Leader index at `+0x194` (byte-packed in convoy packet `0x800d` by sibling `FUN_00574c30`). Count byte `+0x1d8` shared with crew walkers.

5. **Callers (10 xrefs):** UI convoy Invite/Kick disable (`0x0082fb30` dual), roster residual, mission panel, drive-host compare — pattern `ECX=*(local+0xCB0); CALL; CMP EAX, DAT_00d1b6d8`.

6. **Name:** `ConvoyRoster_GetLeaderMember_Inferred` — structural High; pairs GetMemberBySlot. Reject mission-detail callee plate.

7. **Decompile ≡ disasm ≡ bytes**.

### Gaps — `00574880`

1. Product `map`/class demangle (Convoy vs VehicleCrew English).  
2. No body clamp — corrupt `+0x194` OOB risk.  
3. Full product verbs for all 10 sites.  
4. Runtime / bit-exact open.

### Dual A/B — `00574880`

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00574880_ConvoyRoster_GetLeaderMember_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00574880_ConvoyRoster_GetLeaderMember_Inferred.md` | **accept-with-gaps** |

### Files — `00574880`

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00574880_FUN_00574880.md` |
| Annotated | `docs/reconstruction/raw/aa_00574880_FUN_00574880.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ConvoyRoster_GetLeaderMember_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00574880.cpp` |
| Function | `docs/reconstruction/functions/aa_00574880_FUN_00574880.md` |
| Function named | `docs/reconstruction/functions/aa_00574880_ConvoyRoster_GetLeaderMember_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Skill_HB_FireTail_FxTargetAndPeriodStamp (0x00578b30)     [prior dual]
  └─ Object_SetHostModeFlag_Inferred(char, 1)               [OWN 0051f880]

Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred (0x00578ce0) [prior dual]
  └─ Object_SetHostModeFlag_Inferred(char, 0)               [OWN 0051f880]

Object_SetEnhancedStateFlag_Inferred (0x0051f890)           [prior dual twin +0x6b9]

UI_InteractionMenu_AddConvoyInviteOrKick_Inferred (0x0082fb30) [prior dual]
  └─ ConvoyRoster_GetLeaderMember_Inferred (crewHost)       [OWN 00574880]
       vs DAT_00d1b6d8 → disable if not leader

ConvoyRoster_GetMemberBySlot_Inferred (0x00574760)          [prior dual twin algebra]
VehicleCrew_ContainsMember / ClearMember                    [prior dual peers]
```

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0051f880` | Store **byte** at object `+0x6b8` only. thiscall + **ret 4**. FireTail sets **1**, OnEnd **0**. Do not fold ResolveTarget / `vtbl+0x210`. Pair with enhanced flag `+0x6b9`. |
| `00574880` | Leader getter: count `+0x1d8==0` → null; else `*(host + (*(host+0x194)+0x1a)*0x10)`. **Plain ret** (not ret 4). Do not invent 0..3 clamp. Compare to local player only at **callers**. |
