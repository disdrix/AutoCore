# Dual A/B report — R12-021 OWN-ONLY (`0x0052eb90`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R12-021**  
**Scope:** VA `0x0052eb90` (`aa_0052eb90`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs/callees + call-site context. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r12_residual_partition_map.md` → **R12-021**.  
**Work item:** Residual dual seal — inventory-transfer craft station proximity gate (parent craft host `0x008e6b50`).  
**Dual start:** 2646.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0052eb90` Character_Craft_HasMatchingStationInRange_Inferred | **accept-with-gaps** — thiscall RET4 / bool AL / 50.0f / DisciplineDef flags / subtype 0xD–0xF / craft `+0x7e2` consumers sealed; product English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): mission-UI Named_CalleeOf / inventory-grid / skill-cast / SkillDefMap / always-stub / cdecl / map-miss-deny / Runtime Confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0052eb90` — sealed facts

1. **Body:** `0x0052eb90`–`0x0052ed73` exclusive (**483 B** / `0x1E3`); terminal **`C2 04 00`**; pad `CC` after.
2. **ABI:** **`__thiscall`** — **ECX=character** (`DAT_00d1b6d8` at live sites), stack **craft/object***, **AL** bool, **`RET 0x4`**. Frame `SUB ESP,0x220`.
3. **Semantics:** craft / DisciplineDef **station proximity gate**:
   - Null MI `+0xa8` object or null arg → **false**.
   - `character+0x6b4 > 0` → **true** (free / RE-open bypass).
   - `DisciplineDefMap_TryCopyPayloadById` (`0052b040`) miss on `craftObject.def+0x4ac` → **true**.
   - Else scan TFID vector at char-object `+0xe7f8` (via `004e5810`), resolve with ctx `+0xe4e8`.
   - If pose-ok (`vtbl+0x1c8`) and `Object_SurfaceDistance3D` ≤ **`DAT_00a0f524` = 50.0f**:
     - subtype short `def+0x3f4` ∈ {`0xD`,`0xE`,`0xF`} with matching DisciplineDef payload flags at `+0x1F0/+0x1F4/+0x1F8` non-zero → **true**.
   - Loop exhaust → **false**.
4. **Callers (4 xrefs):** craft CreateChildWidgets `008e6b50` → `host+0x7e2`; craft refresh `008e55e0`; craft tick site `008e63cc` → `+0x7e2`; `UI_BuildItemTooltipStats` greyscale.
5. **Xrefs:** 4 UNCONDITIONAL_CALL.
6. **Callees:** dualed `0052b040` DisciplineDef try-copy; `004e5810`; `CVOGReaction_ResolveObjectTarget`; dualed `0053e510` SurfaceDistance3D; `operator_delete`.
7. **Family:** craft host UI gate (parent dual `008e6b50`); DisciplineDef map (R12-020); RE free flag `+0x6b4` shared with RE required-level zero path. **Do not merge** with inventory footprint place/find or mission refresh helpers.
8. **Name:** `Character_Craft_HasMatchingStationInRange_Inferred` (Ghidra `FUN_0052eb90`). Product demangle open → `_Inferred`. Retire Named_CalleeOf mission scaffold.
9. **Decompile ≡ raw CF**; RET 4 + bool AL sealed via `disassemble_function` + `read_memory` + call sites (decompiler return width incomplete, not CF conflict).
10. **Partition parent** `0x008e6b50` is wave score parent and primary CreateChildWidgets consumer; **not** sole live caller.

### Gaps

- Product English for station subtypes `0xD/0xE/0xF` and DisciplineDef flag fields.  
- Product English for `character+0x6b4`.  
- Dual of `FUN_004e5810` / craft refresh `FUN_008e55e0` (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0052eb90_Character_Craft_HasMatchingStationInRange_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0052eb90_Character_Craft_HasMatchingStationInRange_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0052eb90_FUN_0052eb90.md` |
| Annotated | `docs/reconstruction/raw/aa_0052eb90_FUN_0052eb90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Character_Craft_HasMatchingStationInRange_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0052eb90.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow_0052eb90.cpp` |
| Function | `docs/reconstruction/functions/aa_0052eb90_FUN_0052eb90.md` |
| Function named | `docs/reconstruction/functions/aa_0052eb90_Character_Craft_HasMatchingStationInRange_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
UI_CraftHost_CreateChildWidgets_Inferred (0x008e6b50)  [dualed R11-036 parent]
  ├─ UI_CraftHost_BindResolvedObject_Inferred (0x008e5990)  [dualed]
  └─ FUN_0052eb90  Character_Craft_HasMatchingStationInRange_Inferred  [OWN R12-021]
        → host+0x7e2 = AL
        ├─ DisciplineDefMap_TryCopyPayloadById_Inferred (0x0052b040)  [dualed R12-020]
        ├─ FUN_004e5810  TFID vector @ +0xe7f8  [residual]
        ├─ CVOGReaction_ResolveObjectTarget  [shared]
        └─ Object_SurfaceDistance3D_Inferred (0x0053e510)  [dualed W25-H]

FUN_008e55e0 / site 0x008e63cc  craft host refresh/tick
  └─ same gate → enable / host+0x7e2

UI_BuildItemTooltipStats (0x00847ad0)
  └─ greyscale color from bool
```

Partition host "inventory-transfer" names the **craft inventory UI family**, not a grid place/find leaf.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0052eb90-r12-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0052eb90` | Port as **character thiscall bool** craft-station proximity gate. **ECX=character**, stack=craft object, **RET 4**, AL out. |
| Threshold | Surface distance ≤ **50.0f**. |
| Requirements | DisciplineDef row by `def+0x4ac`; flags at payload `+0x1F0/+0x1F4/+0x1F8` for subtypes `0xD/0xE/0xF`. |
| Bypass | `character+0x6b4 > 0` or DisciplineDef miss → **true**. |
| Distinct from | inventory footprint place/find; mission UI refresh; skill-cast target resolve. |
| Pair with | dualed craft host `008e6b50`; dualed DisciplineDef map `0052b040`; dualed SurfaceDistance3D `0053e510`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / `NAMING_REGISTRY.md` / coverage ledgers / `systems/inventory-transfer.md` — **not touched** by this agent.
- Name to register: `Character_Craft_HasMatchingStationInRange_Inferred` @ `0x0052eb90` / `aa_0052eb90`.
- Verdict: **accept-with-gaps**; Terminal **false**.

---

## Process

- OWN VA only (`0x0052eb90`); no Launcher; no parent ledger edits.
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context + related dual callee records. **No** `disassemble_bytes`.
- Dual A (fidelity) + B (adversarial) both filed.
- Scaffold raw body preserved; re-verify **appended** only.
- Clean source uses meaningful name; machine ABI corrections (thiscall RET 4; bool AL; 50.0f; DisciplineDef tail flags).
- Odd behavior preserved: map miss allows craft; index is a wrapping byte; dual `004e5810` materialize per iteration.
- `_Inferred` where English unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
