# OWN-ONLY dual agent report — W25-A

| Field | Value |
|---|---|
| Agent | W25-A |
| Workspace | `C:\Users\josh\Documents\GitHub\AutoCore` |
| Module | `autoassault.exe` base `0x400000` |
| Owned VAs | `0x00535ed0`, `0x0058dc30` |
| Tools | Ghidra `decompile_function` + `read_memory` (+ function meta/xrefs/callees; no `disassemble_bytes`) |
| Launcher | **not** started |
| Parent ledger | **not** edited |
| Date | 2026-07-29 |

---

## VA `0x00535ed0` — CVOGCharacter_ResolveUseObjectPending_Inferred

| Field | Value |
|---|---|
| Ghidra | `FUN_00535ed0` |
| Canonical | `CVOGCharacter_ResolveUseObjectPending_Inferred` (**Probable**) |
| Body | `0x00535ed0`–`0x0053607e` |
| Role | Resolve/clear pending use-object: vtbl cancel/commit, UI packet **0x14**, or EvaluatePending **kind 10** |
| ABI | `__thiscall` ECX=character, stack commit char, bool AL, **`ret 4`** |
| Callers | `FUN_005360f0`, `FUN_0060b410`, `FUN_0060b440`, `FUN_00515520` |
| Callees | `Object_ResolveFromTFID`, `EvaluatePendingObjectives`, `Client_SendLogicUiPacket`, `FUN_0060b410` |
| Constant | `DAT_009cee98` null TFID = `ff×8 00×8` |
| Live ≡ raw | Yes |
| **Verdict** | **accept** / **accept-with-gaps** (product English + secondary type) |

### Artifacts

- `docs/reconstruction/raw/aa_00535ed0_FUN_00535ed0.md`
- `docs/reconstruction/raw/aa_00535ed0_FUN_00535ed0.annotated.md`
- `docs/reconstruction/reconstructed-exact/CVOGCharacter_ResolveUseObjectPending_Inferred.cpp`
- `docs/reconstruction/reconstructed-exact/FUN_00535ed0.cpp`
- `docs/reconstruction/functions/aa_00535ed0_CVOGCharacter_ResolveUseObjectPending_Inferred.md`
- `docs/reconstruction/functions/aa_00535ed0_FUN_00535ed0.md`
- `docs/reconstruction/reviews/A_aa_00535ed0_CVOGCharacter_ResolveUseObjectPending_Inferred.md`
- `docs/reconstruction/reviews/B_aa_00535ed0_CVOGCharacter_ResolveUseObjectPending_Inferred.md`

---

## VA `0x0058dc30` — MapFloatTfid_EraseNode_Inferred

| Field | Value |
|---|---|
| Ghidra | `FUN_0058dc30` |
| Canonical | `MapFloatTfid_EraseNode_Inferred` (**High** structural family) |
| Body | `0x0058dc30`–`0x0058dee5` (Ghidra truncated `…deb6`) |
| Role | MSVC map single-node erase (isnil `+0x29`); size--; ret 8 |
| ABI | `__thiscall` ECX=tree, 2 stack args, **`ret 8`** |
| Callers | **only** `MapFloatTfid_EraseRange_Inferred` (`FUN_0058df60`) |
| Callees | rotates `004192a0`/`004192f0`, leftmost/rightmost, `operator_delete`, throw |
| String | `"invalid map/set<T> iterator"` @ `0x00a152f0` |
| Live ≡ raw | Yes (+ byte epilogue beyond decompiler) |
| **Verdict** | **accept** / **accept-with-gaps** (PDB K/V English) |

### Artifacts

- `docs/reconstruction/raw/aa_0058dc30_FUN_0058dc30.md`
- `docs/reconstruction/raw/aa_0058dc30_FUN_0058dc30.annotated.md`
- `docs/reconstruction/reconstructed-exact/MapFloatTfid_EraseNode_Inferred.cpp`
- `docs/reconstruction/reconstructed-exact/FUN_0058dc30.cpp`
- `docs/reconstruction/functions/aa_0058dc30_MapFloatTfid_EraseNode_Inferred.md`
- `docs/reconstruction/functions/aa_0058dc30_FUN_0058dc30.md`
- `docs/reconstruction/reviews/A_aa_0058dc30_MapFloatTfid_EraseNode_Inferred.md`
- `docs/reconstruction/reviews/B_aa_0058dc30_MapFloatTfid_EraseNode_Inferred.md`

---

## Notes

- No Launcher. No parent ledger / `ACTIVE_WORK` / `WORK_QUEUE` / `COVERAGE_LEDGER` / progress / inventory edits.
- Did not write artifacts for non-owned helpers (`005360f0`, `0060b410`, `0060b440`, `004192a0`, `004cb270`, `00535c60`, …) beyond citing sealed duals.
- Prior raw bodies preserved; W25-A live seal sections appended only.
- Legacy `Named_*` plates redirected to named cleans.
