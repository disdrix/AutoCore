# Dual A/B report — W18-L OWN `0x009210e0` + `0x006173a0`

**Date:** 2026-07-29  
**Scope:** OWN ONLY VAs `0x009210e0`, `0x006173a0`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER.  
**Ghidra:** `decompile_function` + `read_memory` (+ complete analysis / callers / callees). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_009210e0` `Client_RefreshInteractPromptTarget_Inferred` | **accept-with-gaps** — 15f cascade + prompt UI sealed; product host names open |
| `aa_006173a0` `Map_ConstructIntKeyNode_0x18` | **accept-with-gaps** — new(0x18)+layout+RET 0x14 sealed; mangled name open |

---

## `0x009210e0` — Client_RefreshInteractPromptTarget_Inferred

### Sealed facts

1. **Body** `0x009210e0`–`0x00921355`; stack frame; **`RET 4`**.
2. **ABI:** caller `FUN_009216e0` does `PUSH ESI` (client this) then CALL; **body never loads the stack formal** — globals-only. Selected object left in **ESI** for `FUN_008a81a0`.
3. **Gates:** `DAT_00d1b8c8 != 0` and `host->vtbl[+0x3d8]() != 0`.
4. **Geometry:** player pos via adj-this(`DAT_00d1b6d8`)+`vtbl+0x1a0`; keep `DAT_00d1d888` if not self (`vtbl+0x210`) and dist² ≤ **`DAT_00aaaca4` = 225.0f**; else re-query.
5. **Cascade:** `FUN_0058cd60` mode **6** r=**15** → resolve; tip **3**; else `Skill_GatherTargetsInArea` mode **3** r=15; else (if `world+0xf5`) mode **7** filterA **0x14**; else `Client_FindFirstObjectInRadius(15)`.
6. **Terminal:** `FUN_008a81a0(DAT_00d1b8c8)` — interact prompt chrome (**not** UseObject send).
7. **Callers (1):** `FUN_009216e0` timer after `vtbl+0x478`.
8. **Live ≡ raw 2026-07-23** decompile.

### Gaps

1. Product names of `DAT_00d1b8c8`, `FUN_008a81a0`, `FUN_009216e0`, `vtbl+0x3d8`.  
2. Writers of `DAT_00d1d888` (not this unit).  
3. Runtime / bit-exact / image diff.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_009210e0_Client_RefreshInteractPromptTarget_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_009210e0_Client_RefreshInteractPromptTarget_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_009210e0_Client_RefreshInteractPromptTarget_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_009210e0_Client_RefreshInteractPromptTarget_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_009210e0_Client_RefreshInteractPromptTarget_Inferred.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_009210e0_FUN_009210e0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_RefreshInteractPromptTarget_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_009210e0.cpp` |
| Raw | `docs/reconstruction/raw/aa_009210e0_FUN_009210e0.md` |
| Annotated | `docs/reconstruction/raw/aa_009210e0_FUN_009210e0.annotated.md` |
| Scratch | `tmp/a_009210e0.md` |

---

## `0x006173a0` — Map_ConstructIntKeyNode_0x18

### Sealed facts

1. **Body** `0x006173a0`–`0x006173de`; **63 B**.
2. **ABI:** five stack args; **`RET 0x14`**; returns **node\*** in **EAX** (decompiler `void` trap); OOM → 0.
3. **Algorithm:** `operator_new(0x18)`; if non-null fill left/parent/right from args 1–3; key/mapped from `*value` / `value[1]`; color byte; **isnil = 0**.
4. **Bytes ≡ decompile**  
   `6a18e8eb24e7ff83c40485c0742e8b4c24048b54240889088b4c240c8948088b4c24108950048b1189500c8b49048a542414894810885014c6401500c21400`.
5. **Callers (14):** includes sealed `Map_InsertNodeAndRebalance_IntKey` (`0x005d20b0`) plus 13 sibling insert-style sites.
6. **Sole callee:** `operator_new` @ `0x00489892`.
7. **Family:** int-key MSVC map/set node ctor shared with W17-Q insert duals.

### Gaps

1. Product / mangled C++ template name.  
2. Exhaustive proof every caller is int/int (layout is 2 dwords; typedef open).  
3. Runtime / bit-exact / image diff.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_006173a0_Map_ConstructIntKeyNode_0x18.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_006173a0_Map_ConstructIntKeyNode_0x18.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_006173a0_Map_ConstructIntKeyNode_0x18.md` |
| Review B | `docs/reconstruction/reviews/B_aa_006173a0_Map_ConstructIntKeyNode_0x18.md` |
| Function record | `docs/reconstruction/functions/aa_006173a0_Map_ConstructIntKeyNode_0x18.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_006173a0_FUN_006173a0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Map_ConstructIntKeyNode_0x18.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_006173a0.cpp` |
| Raw | `docs/reconstruction/raw/aa_006173a0_FUN_006173a0.md` |
| Annotated | `docs/reconstruction/raw/aa_006173a0_FUN_006173a0.annotated.md` |
| Scratch | `tmp/a_006173a0.md` |

---

## AutoCore impact

- **Interact chrome:** client has a **timer path** separate from bound-action Activate that only refreshes the proximity prompt target (15f / 225 dist²). Server ports need not mirror UI; selection geometry matches Activate for consistency.
- **Map nodes:** any int-key `std::map` insert path allocating **0x18** nodes should use this ctor layout (color `+0x14`, isnil `+0x15`) when reconstructing client AI timer maps and siblings.
- Do **not** merge `0x009210e0` with PollBoundActions Activate or with `Client_FindFirstObjectInRadius` alone.

---

## This report

`docs/agents/task-dual-ab-009210e0-006173a0-w18l-report.md`
