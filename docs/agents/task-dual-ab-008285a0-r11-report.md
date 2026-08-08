# Dual A/B report — R11-026 OWN-ONLY (`0x008285a0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R11-026**  
**Scope:** VA `0x008285a0` (`aa_008285a0`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs/callees. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r11_residual_partition_map.md` → **R11-026**.  
**Work item:** Residual dual seal — skills-abilities QuickBar slot-button **assign item object** (clonebase id mirror + skill clear).  
**Partition parent:** `0x005208c0` `CVOGCharacter_SetQuickBarSkill` (score parent / sealed callee — not structural caller).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_008285a0` UI_QuickBarSlotButton_AssignItemObject_Inferred | **accept-with-gaps** — item-object QB bind; kind=2; SetQuickBarItem then SetQuickBarSkill(−1); EAX/ESI ABI; rel32 sealed; product English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): skill-assign / AssignItem-merge / skill-twin-ABI / column-only-slot / leave-skill / always-clear-select / packet-send / path-string-DAT_00afdf0c / argless-0085d970 / parent-is-caller claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x008285a0` — sealed facts

1. **Body:** `0x008285a0`–`0x00828756` exclusive (**439 B** / `0x1B7`); terminal plain **`C3`**; pad `CC`.
2. **ABI:** **item object* in EAX**, **button in ESI**; plain **`ret`**; AL = **0** (null) or **1**. **Not** pure thiscall / not skill-twin stack/`ret 4` / not AssignItem EAX-button+ECX-id.
3. **Semantics:** MSVC-style QuickBar **item-object** slot assign (`payloadKind = 2`):
   - Null item → return 0.
   - Same-bind: kind==2 && id64 matches `cdq(*( *(item+0xa8)+0x34 ))` → skip selection clear.
   - Cache id (cdq); kind=2; pSkill=0; flat slot page*10+col.
   - Character: SetQuickBarItem then SetQuickBarSkill(−1) on `DAT_00d1b6d8`.
   - Optional SetSelected(0); destroy owned child; icon via `FUN_0085d970(item,path)`; chrome; button vtbl+0x448; return 1.
4. **rel32 Confirmed:** `0082864c→00520890`, `0082866a→005208c0`, `00828681→00826780`, `008286ad→0085d970`.
5. **Xrefs (2):** `0x00828b00` (char+0xcd0 item), `0x00828ef8` (EBX item / EBP button).
6. **Callees:** SetQuickBarItem, SetQuickBarSkill, SetSelected, FUN_0085d970, virtuals.
7. **Family:** dualed AssignItem `008283a0` (id ECX), AssignSkill `00826860` (skill*), SetSelected `00826780`, ClearActiveSlot `008274c0`. **Do not merge** with id-based AssignItem.
8. **Name:** `UI_QuickBarSlotButton_AssignItemObject_Inferred` (Ghidra `FUN_008285a0`). Product demangle open → `_Inferred`.
9. **Decompile ≡ raw CF**; ABI/args for `FUN_0085d970` sealed via disasm + `read_memory` (decompiler arity incomplete, not CF conflict).
10. **Partition parent** `0x005208c0` is wave score parent / callee; **live structural xrefs** are UI sites above.

### Gaps

- Product / PDB English method name.  
- Exact item-object class + `+0xa8` English; `char+0xcd0` producer.  
- `FUN_0085d970` undualed (not OWN).  
- Caller C2S QuickBarUpdate residual.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_008285a0_UI_QuickBarSlotButton_AssignItemObject_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_008285a0_UI_QuickBarSlotButton_AssignItemObject_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_008285a0_FUN_008285a0.md` |
| Annotated | `docs/reconstruction/raw/aa_008285a0_FUN_008285a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_QuickBarSlotButton_AssignItemObject_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_008285a0.cpp` |
| Function | `docs/reconstruction/functions/aa_008285a0_FUN_008285a0.md` |
| Function named | `docs/reconstruction/functions/aa_008285a0_UI_QuickBarSlotButton_AssignItemObject_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
UI sites @ 0x00828b00 / 0x00828ef8
  └─ FUN_008285a0  UI_QuickBarSlotButton_AssignItemObject_Inferred  [OWN R11-026]
        ├─ CVOGCharacter_SetQuickBarItem   0x00520890  [sealed]
        ├─ CVOGCharacter_SetQuickBarSkill  0x005208c0  [partition parent / sealed]
        ├─ UI_QuickBarSlotButton_SetSelected 0x00826780 [sealed]
        └─ FUN_0085d970  inventory texture path  [residual]

Contrast:
  UI_QuickBarSlotButton_AssignItem_Inferred      0x008283a0  [dualed W24-J] id ECX + GiveItemByCbid
  UI_QuickBarSlotButton_AssignSkill_Inferred     0x00826860  [dualed W23-D] skill* EAX, ret 4
  QuickBar_ClearActiveSlot_INFERRED              0x008274c0  [dualed] — not used by this body
```

Partition host "skills-abilities" names the **host system**; leaf is QB UI item-object bind (clears skill on exclusive slot).

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-008285a0-r11-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `008285a0` | Port as QB slot **item-object assign**: read id from clonebase `+0x34` via `item+0xa8`; set item COID array; clear skill id −1; rebuild inventory icon from object path helper. ABI: EAX item*, ESI button*, plain ret, bool. |
| Distinct from | id-based AssignItem `008283a0` (ECX id + GiveItemByCbid); skill AssignSkill `00826860`. |
| Pair with | sealed SetQuickBarItem/Skill; SetSelected; residual path extract `0085d970`; UI drag/char+0xcd0 callers. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / `NAMING_REGISTRY.md` / coverage ledgers — **not touched** by this agent.
- Name to register: `UI_QuickBarSlotButton_AssignItemObject_Inferred` @ `0x008285a0` / `aa_008285a0`.
- Verdict: **accept-with-gaps**; Terminal **false**.

---

## Process

- OWN VA only (`0x008285a0`); no Launcher; no parent ledger edits.
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context. **No** `disassemble_bytes`.
- Dual A (fidelity) + B (adversarial) both filed.
- Scaffold raw body preserved; re-verify **appended** only.
- Clean source uses meaningful name; machine ABI corrections (EAX item / ESI button / plain ret; FUN_0085d970 args).
- Odd behavior preserved: null returns 0 (not clear-slot); no GiveItemByCbid; skill forced −1 on item bind; DAT_00afdf0c is color.
- `_Inferred` where English unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
