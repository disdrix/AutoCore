# OWN-ONLY dual agent report — W24-L

| Field | Value |
|---|---|
| Agent | W24-L |
| Workspace | `C:\Users\josh\Documents\GitHub\AutoCore` |
| Module | `autoassault.exe` base `0x400000` |
| Owned VAs | `0x0060bb80`, `0x00539150` |
| Tools | Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`) |
| Launcher | **not** started |
| Parent ledger | **not** edited |
| Date | 2026-07-29 |

---

## VA `0x0060bb80` — CVOGRegionMissions_ResyncMissionObjectives_Inferred

| Field | Value |
|---|---|
| Ghidra | `FUN_0060bb80` |
| Canonical | `CVOGRegionMissions_ResyncMissionObjectives_Inferred` (**Inferred**) |
| Body | `0x0060bb80`–`0x0060be1e` (last `ret 4`) |
| Role | Lookup mission def by id; cold-load catalog; compare objectives; on mismatch strip+reinsert objective hash; materialize via `FUN_00546e40` |
| ABI | ECX=`CVOGRegionMissions*`, stack `missionId`, **`ret 4`**, AL status |
| Callers | **Open** (no static CODE xrefs) |
| Callees | `CNDHash_LookupByKey`, DB trio, `FUN_00546e40`, `CNDHash_Insert`/`FUN_0053c460`, `FUN_00537d30`, `CoTaskMemFree`, `FUN_007a4480` |
| Live ≡ raw | Yes |
| **Verdict** | **accept-with-gaps** |

### Artifacts

- `docs/reconstruction/raw/aa_0060bb80_FUN_0060bb80.md`
- `docs/reconstruction/raw/aa_0060bb80_FUN_0060bb80.annotated.md`
- `docs/reconstruction/reconstructed-exact/CVOGRegionMissions_ResyncMissionObjectives_Inferred.cpp`
- `docs/reconstruction/reconstructed-exact/FUN_0060bb80.cpp`
- `docs/reconstruction/functions/aa_0060bb80_CVOGRegionMissions_ResyncMissionObjectives_Inferred.md`
- `docs/reconstruction/functions/aa_0060bb80_FUN_0060bb80.md`
- `docs/reconstruction/reviews/A_aa_0060bb80_CVOGRegionMissions_ResyncMissionObjectives_Inferred.md`
- `docs/reconstruction/reviews/B_aa_0060bb80_CVOGRegionMissions_ResyncMissionObjectives_Inferred.md`

---

## VA `0x00539150` — MissionStagingTree_EraseRange

| Field | Value |
|---|---|
| Ghidra | `FUN_00539150` |
| Canonical | `MissionStagingTree_EraseRange` (**Inferred** — peer DestroySubtree/EraseNode) |
| Body | `0x00539150`–`0x00539203` (last `ret 0xc`) |
| Role | MSVC map range erase `[first,last)`; full-clear arm bulk-destroys; else successor+EraseNode |
| ABI | ECX=`map*`, stack `(outIter*, first, last)`, **`ret 0xc`** |
| Callers | `FUN_0053ae70` @ `0x0053ae82`; char dtor @ `0x0052f607` (map `char+0x508`) |
| Callees | `FUN_00537ef0` DestroySubtree, `FUN_00538780` EraseNode |
| Live ≡ raw | Yes |
| **Verdict** | **accept-with-gaps** |

### Artifacts

- `docs/reconstruction/raw/aa_00539150_FUN_00539150.md`
- `docs/reconstruction/raw/aa_00539150_FUN_00539150.annotated.md`
- `docs/reconstruction/reconstructed-exact/MissionStagingTree_EraseRange.cpp`
- `docs/reconstruction/reconstructed-exact/FUN_00539150.cpp`
- `docs/reconstruction/functions/aa_00539150_MissionStagingTree_EraseRange.md`
- `docs/reconstruction/functions/aa_00539150_FUN_00539150.md`
- `docs/reconstruction/reviews/A_aa_00539150_MissionStagingTree_EraseRange.md`
- `docs/reconstruction/reviews/B_aa_00539150_MissionStagingTree_EraseRange.md`

---

## Notes

- No Launcher. No parent ledger / `ACTIVE_WORK` / partition map edits.
- Did not write artifacts for non-owned helpers (`00537ef0`, `00538780`, `0053c460`, `00546e40`, `0060b870`, `007e1d80`, …).
- Named clean plates preferred; FUN_* scaffolds point at sealed CF.
- Prior raw bodies preserved; W24-L live seal sections appended only.
- Supersedes misleading `Named_VOG_DEBUG_STOP_0060bb80` for `0x0060bb80`.
