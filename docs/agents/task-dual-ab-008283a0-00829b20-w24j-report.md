# Dual A/B report — W24-J OWN `aa_008283a0` + `aa_00829b20`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W24-J  
**Scope:** VAs `0x008283a0`, `0x00829b20` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers/callees / xrefs / `get_function_by_address`). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `reviews/WAVE_2026-07-29_wave24_partition_map.md` → W24-J  

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_008283a0` UI_QuickBarSlotButton_AssignItem_Inferred | **accept** — item QB slot bind; kind=2; SetQuickBarItem then SetQuickBarSkill(-1); EAX/ECX ABI; rel32 sealed |
| `aa_00829b20` UI_MissionJournal_SelectMission_Inferred | **accept-with-gaps** — journal select CF + ABI + title string + ready framing sealed; color + list-helper residuals |

---

## VA `0x008283a0` — sealed facts

1. **Body:** `0x008283a0`–`0x0082859e` (510 B / `0x1FE`).
2. **ABI:** **button in EAX**, **itemId in ECX**; plain **`ret`** (`C3`); AL = **1**.
3. **Semantics:** MSVC-style QuickBar **item** slot assign (`payloadKind = 2`).
4. **`-1` path:** `QuickBar_ClearActiveSlot_INFERRED` @ `0x008274c0`; return 1.
5. **Same-bind:** `kind==2 && idLo==itemId && idHi==(itemId>>31)` → skip selection clear.
6. **Character mirror:** `SetQuickBarItem(char, slot, idLo, idHi)` then `SetQuickBarSkill(char, slot, -1)`.
7. **Slot:** `page * 10 + column` (`+0x504` / `+0x500`).
8. **Icon:** `CVOGReaction_GiveItemByCbid(idLo)` → path helper `FUN_0085d970`; null → clear slot.
9. **rel32 Confirmed:** `008283ae→008274c0`, `00828445→00520890`, `00828463→005208c0`, `00828479→00826780`, `008284ac→0051a170`.
10. **Callers (3):** `FUN_008a0e10` @ `0x008a0e9f`; UI sites `0x00828de4`, `0x00828fd3`.
11. **Name:** `UI_QuickBarSlotButton_AssignItem_Inferred` (Ghidra `FUN_008283a0`).
12. **Twin:** skill assign `0x00826860` (kind=1; different ABI: skill EAX, button stack, `ret 4`).

### Gaps

- Product / PDB English method name.  
- Exact item-id domain (template CBID vs instance COID).  
- `FUN_0085d970` path extract dual.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_008283a0_UI_QuickBarSlotButton_AssignItem_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_008283a0_UI_QuickBarSlotButton_AssignItem_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_008283a0_FUN_008283a0.md` |
| Annotated | `docs/reconstruction/raw/aa_008283a0_FUN_008283a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_QuickBarSlotButton_AssignItem_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_008283a0.cpp` |
| Function | `docs/reconstruction/functions/aa_008283a0_FUN_008283a0.md` |
| Function named | `docs/reconstruction/functions/aa_008283a0_UI_QuickBarSlotButton_AssignItem_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_008283a0.md` |

---

## VA `0x00829b20` — sealed facts

1. **Body:** `0x00829b20`–`0x00829ca5` (389 B / `0x185`).
2. **ABI:** **context in EAX**, **mission* in EDI**; plain **`ret`**; void.
3. **Gate:** context `vtbl+0x3d8()` non-zero **and** mission non-null.
4. **Title:** `sprintf(buf, "[%d] %s", level, name)` — string @ `0x00a4abb4` (`"[%d] %s"`).
5. **Mission fields:** id `*mission`; level int16 `@+0x11c`; name source `@+0x14c`.
6. **Context fields:** selected id `@+0x500`; title widget `@+0x508`; chrome `@+0x50c`.
7. **Ready path:** when `DAT_00d1b6d8` live: `CVOGCharacter_IsMissionJournalReady` then `FUN_00829ac0`. Ready AL **not branched** in this body.
8. **rel32 Confirmed:** `00829c5c→0052b3b0`, `00829c61→00829ac0`.
9. **Callers (2):** `Client_UpdateMissionJournal` @ `0x008ae4b9`, `0x008ae6b8`.
10. **Name:** `UI_MissionJournal_SelectMission_Inferred` (Ghidra `FUN_00829b20`).
11. **Decompile ≡ entry/exit bytes** for ABI + store; title string sealed.

### Gaps

- Product English method / panel class name.  
- Product field names for mission level/name.  
- Color residual duals (`FUN_0092d580`, `FUN_006a3db0`).  
- Whether `FUN_00829ac0` re-reads ready AL.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00829b20_UI_MissionJournal_SelectMission_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00829b20_UI_MissionJournal_SelectMission_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00829b20_FUN_00829b20.md` |
| Annotated | `docs/reconstruction/raw/aa_00829b20_FUN_00829b20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_MissionJournal_SelectMission_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00829b20.cpp` |
| Function | `docs/reconstruction/functions/aa_00829b20_FUN_00829b20.md` |
| Function named | `docs/reconstruction/functions/aa_00829b20_UI_MissionJournal_SelectMission_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_00829b20.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `008283a0` | Client item→QB bind; exclusive slot policy = **set item, clear skill**. Twin of skill assign but **different ABI** (do not call with skill-twin convention). Server already models exclusive slots via `QuickBarUpdate` / `CharacterSkillService.TryUpdateQuickBar`. |
| `00829b20` | Client journal **selection UI** only — title chrome + store selected mission id; not turn-in/claim. Ready predicate is sealed sibling `IsMissionJournalReady`; this unit does not branch on it. |

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x00826860` | skill twin `UI_QuickBarSlotButton_AssignSkill_Inferred` (sealed W23-D) |
| `0x00827670` | macro assign sibling (W24-I ownership) |
| `0x008a0e10` | QuickBar page-column rebind caller |
| `0x00520890` / `0x005208c0` | SetQuickBarItem / SetQuickBarSkill |
| `0x00826780` | `UI_QuickBarSlotButton_SetSelected` |
| `0x008274c0` | `QuickBar_ClearActiveSlot_INFERRED` |
| `0x0051a170` | `CVOGReaction_GiveItemByCbid` |
| `0x0052b3b0` | `CVOGCharacter_IsMissionJournalReady` (sealed) |
| `0x00829ac0` | journal list refresh helper |
| `0x008ae130` | `Client_UpdateMissionJournal` parent |
| `0x0082a050` | sibling journal path that **does** use ready for "(Complete)" |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/xrefs).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved conceptually; W24-J re-verify **appended** / rewritten with original CF + seal section.
