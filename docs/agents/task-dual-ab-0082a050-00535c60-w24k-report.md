# OWN-ONLY dual agent report — W24-K

| Field | Value |
|---|---|
| Agent | W24-K |
| Workspace | `C:\Users\josh\Documents\GitHub\AutoCore` |
| Module | `autoassault.exe` base `0x400000` |
| Owned VAs | `0x0082a050`, `0x00535c60` |
| Tools | Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`) |
| Launcher | **not** started |
| Parent ledger | **not** edited |
| Date | 2026-07-29 |

---

## VA `0x0082a050` — UI_MissionJournalRow_ApplySelection_Inferred

| Field | Value |
|---|---|
| Ghidra | `FUN_0082a050` |
| Canonical | `UI_MissionJournalRow_ApplySelection_Inferred` (**Probable**) |
| Body | `0x0082a050`–`0x0082a35d` |
| Role | Journal-row selection apply: kind1 `"[level] name"`, kind2 secondary title, `(Complete)` via `IsMissionJournalReady` |
| ABI | ECX=row, EAX=selection triple*, **`ret`** |
| Callers | `FUN_008a4900`, `FUN_008a5240` (×2) |
| Callees | `FUN_0052b3b0`, `FUN_00829fa0`, `FUN_007a6de0`, `sprintf`, … |
| Live ≡ raw | Yes |
| **Verdict** | **accept** / **accept-with-gaps** (product English) |

### Artifacts

- `docs/reconstruction/raw/aa_0082a050_FUN_0082a050.md`
- `docs/reconstruction/raw/aa_0082a050_FUN_0082a050.annotated.md`
- `docs/reconstruction/reconstructed-exact/UI_MissionJournalRow_ApplySelection_Inferred.cpp`
- `docs/reconstruction/reconstructed-exact/FUN_0082a050.cpp`
- `docs/reconstruction/functions/aa_0082a050_UI_MissionJournalRow_ApplySelection_Inferred.md`
- `docs/reconstruction/functions/aa_0082a050_FUN_0082a050.md`
- `docs/reconstruction/reviews/A_aa_0082a050_UI_MissionJournalRow_ApplySelection_Inferred.md`
- `docs/reconstruction/reviews/B_aa_0082a050_UI_MissionJournalRow_ApplySelection_Inferred.md`

---

## VA `0x00535c60` — CVOGCharacter_TryEvalInteractObjectivesNearObject_Inferred

| Field | Value |
|---|---|
| Ghidra | `FUN_00535c60` |
| Canonical | `CVOGCharacter_TryEvalInteractObjectivesNearObject_Inferred` (**Probable**) |
| Body | `0x00535c60`–`0x00535ec1` |
| Role | Inventory-or-≤20.0f range → active-hash type-0xC match → `EvaluatePendingObjectives` kind **9** |
| ABI | `__thiscall` ECX=character, stack object*, **`ret 4`**, bool AL |
| Callers | **none static** recovered (gap) |
| Callees | `InventoryGrid_FindItemByCoid`, `FUN_0053e510`, `EvaluatePendingObjectives`, hash asserts |
| Constant | `DAT_00aaa6e8` = **20.0f** |
| Live ≡ raw | Yes |
| **Verdict** | **accept-with-gaps** (static entry open; CF High) |

### Artifacts

- `docs/reconstruction/raw/aa_00535c60_FUN_00535c60.md`
- `docs/reconstruction/raw/aa_00535c60_FUN_00535c60.annotated.md`
- `docs/reconstruction/reconstructed-exact/CVOGCharacter_TryEvalInteractObjectivesNearObject_Inferred.cpp`
- `docs/reconstruction/reconstructed-exact/FUN_00535c60.cpp`
- `docs/reconstruction/functions/aa_00535c60_CVOGCharacter_TryEvalInteractObjectivesNearObject_Inferred.md`
- `docs/reconstruction/functions/aa_00535c60_FUN_00535c60.md`
- `docs/reconstruction/reviews/A_aa_00535c60_CVOGCharacter_TryEvalInteractObjectivesNearObject_Inferred.md`
- `docs/reconstruction/reviews/B_aa_00535c60_CVOGCharacter_TryEvalInteractObjectivesNearObject_Inferred.md`

---

## Notes

- No Launcher. No parent ledger / `ACTIVE_WORK` / partition map edits.
- Did not write artifacts for non-owned helpers (`00571010`, `0052b3b0`, `00534920`, `00535ed0`, `008a5240`, `00829fa0`, …) beyond citing sealed duals.
- Prior raw bodies preserved; W24-K live seal sections appended only.
- Legacy `Named_*VOG_DEBUG_STOP*` plates redirected to named cleans (string is hash assert, not product role).
