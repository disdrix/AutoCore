# OWN-ONLY dual agent report — W25-G

| Field | Value |
|---|---|
| Agent | W25-G |
| Workspace | `C:\Users\josh\Documents\GitHub\AutoCore` |
| Module | `autoassault.exe` base `0x400000` |
| Owned VAs | `0x0051c1c0`, `0x00829ac0` |
| Tools | Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`) |
| Launcher | **not** started |
| Parent ledger | **not** edited |
| Date | 2026-07-29 |

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_0051c1c0` Map_TreeInsertAndRebalance_Val12 | **accept-with-gaps** — Val12 tree always-insert + RB rebalance; `ret 0x10`; throw `"map/set<T> too long"` @ size>`0x15555553` |
| `aa_00829ac0` UI_MissionJournal_ApplyStatusCompleteLabel_Inferred | **accept-with-gaps** — ESI panel / AL flag; status `+0x50c` SetText clear/`"(complete)"` + tail refresh `+0x34c` |

---

## VA `0x0051c1c0` — Map_TreeInsertAndRebalance_Val12

| Field | Value |
|---|---|
| Ghidra | `FUN_0051c1c0` |
| Canonical | `Map_TreeInsertAndRebalance_Val12` (**Inferred**) |
| Body | `0x0051c1c0`–`0x0051c3aa` exclusive (**490** B) |
| Role | MSVC `_Tree` always-insert + red-black rebalance for Val12 nodes (0x1c; color@+0x18) |
| ABI | `__thiscall` ECX=map; stack `(outIt*, addLeft, where, value*)`; **`ret 0x10`** |
| Callers | `Skill_CategoryCooldownMap_Insert` @ `0x0051d2f0` only (xrefs `0051d349`, `0051d380`) |
| Callees | `FUN_005ae220` (StdTree_Buynode_Val12), `FUN_00573170`, `FUN_00418c10`, STL string/exception, `_CxxThrowException` |
| Live ≡ raw | Yes |
| **Verdict** | **accept-with-gaps** |

### Sealed facts

1. **Body / epilogue:** exclusive end `0x0051c3aa`; `add esp,0x50; ret 0x10`.
2. **Prologue:** SEH `LAB_009a3502`; `mov edi,ecx`; `cmp [edi+8], 0x15555553`.
3. **Throw:** `"map/set<T> too long"` @ `0x00a1530c` → `_CxxThrowException(..., DAT_00acc388)`.
4. **Buynode:** `FUN_005ae220(head, where, head, value, color=0)` — sealed W24-I Val12 buy.
5. **Link:** empty head → root/leftmost/rightmost; else left or right of `where` (+ extremity updates).
6. **RB loop:** while parent red → recolor uncle or rotate; exit paints root black; `*outIt = n`.
7. **Not** a key walk — parent owns lower-bound / duplicate gate.
8. **Max size `0x15555553`** is **not** the SkillElementTypeMap constant `0x1ffffffd`.

### Gaps

1. Product/MSVC demangle for map type.  
2. Rotate helper product names (`FUN_00573170` / `FUN_00418c10`).  
3. Buynode null OOM path (no check in decomp).  
4. Runtime / bit-exact / differential.

### Artifacts

- `docs/reconstruction/raw/aa_0051c1c0_FUN_0051c1c0.md`
- `docs/reconstruction/raw/aa_0051c1c0_FUN_0051c1c0.annotated.md`
- `docs/reconstruction/reconstructed-exact/Map_TreeInsertAndRebalance_Val12.cpp`
- `docs/reconstruction/reconstructed-exact/FUN_0051c1c0.cpp`
- `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Skill_CategoryCooldownMap_Insert_0051c1c0.cpp`
- `docs/reconstruction/functions/aa_0051c1c0_Map_TreeInsertAndRebalance_Val12.md`
- `docs/reconstruction/functions/aa_0051c1c0_FUN_0051c1c0.md`
- `docs/reconstruction/reviews/A_aa_0051c1c0_Map_TreeInsertAndRebalance_Val12.md`
- `docs/reconstruction/reviews/B_aa_0051c1c0_Map_TreeInsertAndRebalance_Val12.md`

---

## VA `0x00829ac0` — UI_MissionJournal_ApplyStatusCompleteLabel_Inferred

| Field | Value |
|---|---|
| Ghidra | `FUN_00829ac0` |
| Canonical | `UI_MissionJournal_ApplyStatusCompleteLabel_Inferred` |
| Body | `0x00829ac0`–`0x00829aff` exclusive (**64** B) |
| Role | Store complete flag; set status widget text clear/`"(complete)"`; refresh |
| ABI | **ESI**=journal panel*; **AL**=flag; plain `ret` / tail `jmp vtbl+0x34c` |
| Callers | `UI_MissionJournal_SelectMission_Inferred` (`00829b20`); `FUN_00829ce0` (status build) |
| Callees | status `vtbl+0x1d8` SetText; `vtbl+0x34c` Refresh (tail) |
| Live ≡ raw | Yes (bytes strengthen SetText arity) |
| **Verdict** | **accept-with-gaps** |

### Sealed facts

1. **Body hex (64 B)** fully sealed via `read_memory`.
2. **Stores** `[esi+0x4fd] = al` always; status at `[esi+0x50c]`.
3. **Null status** → early `ret`.
4. **Both arms** push `1`,`1` then either `0` or `"(complete)"` @ `0x00a7496c` → `call [vtbl+0x1d8]`.
5. **Tail** reload status → `jmp [vtbl+0x34c]` (not a normal call/return when status live).
6. **SelectMission** calls `IsMissionJournalReady` then this — AL **is consumed** here (parent does not branch on it).
7. **Falsifies** W24-J B sketch naming this "RefreshObjectiveList".

### Gaps

1. Product English / plate spelling.  
2. Whether ready AL truly means mission-complete for the badge.  
3. SetText trailing int meanings.  
4. Construct-path (`FUN_00829ce0`) AL intent.  
5. Runtime / differential.

### Artifacts

- `docs/reconstruction/raw/aa_00829ac0_FUN_00829ac0.md`
- `docs/reconstruction/raw/aa_00829ac0_FUN_00829ac0.annotated.md`
- `docs/reconstruction/reconstructed-exact/UI_MissionJournal_ApplyStatusCompleteLabel_Inferred.cpp`
- `docs/reconstruction/reconstructed-exact/FUN_00829ac0.cpp`
- `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Client_UpdateMissionJournal_00829ac0.cpp`
- `docs/reconstruction/functions/aa_00829ac0_UI_MissionJournal_ApplyStatusCompleteLabel_Inferred.md`
- `docs/reconstruction/functions/aa_00829ac0_FUN_00829ac0.md`
- `docs/reconstruction/reviews/A_aa_00829ac0_UI_MissionJournal_ApplyStatusCompleteLabel_Inferred.md`
- `docs/reconstruction/reviews/B_aa_00829ac0_UI_MissionJournal_ApplyStatusCompleteLabel_Inferred.md`

---

## Notes

- No Launcher. No parent ledger / `ACTIVE_WORK` / partition map / COVERAGE_LEDGER edits.
- Did not write artifacts for non-owned helpers (`005ae220` already dualed W24-I; `00573170`, `00418c10`, `00829b20`, `00829ce0`, `0052b3b0`, …).
- Named clean plates preferred over 2026-07-23 auto scaffolds; FUN_* / Named_* aliases updated to point at sealed CF.
- Prior raw bodies preserved; W25-G live seal sections appended only.
