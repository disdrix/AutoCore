# Dual A/B report — MEGA-057 OWN-ONLY (`0x005d5cc0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-057**  
**Scope:** VA `0x005d5cc0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_by_address` + callers/xrefs + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA-057 residual dual seal — `CVOGWaypoint::DoFollowObjectShortcutsUpdate`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md`  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005d5cc0` CVOGWaypoint_DoFollowObjectShortcutsUpdate | **accept-with-gaps** — CF/ABI/RET0/plate/sole-caller/constants/field map sealed; residual callee English + candidate class + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): CVOGHBAI-misname / multi-caller / RET4 / surface-distance this=target / terminal-Confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x005d5cc0` — sealed facts

1. **Body:** `0x005d5cc0`–`0x005d62fb` inclusive (**1596 B** / `0x63C`).
2. **ABI:** **thiscall** ECX = `CVOGWaypoint* this`; no stack args; void; **`RET`** (not `RET n`). SEH `LAB_009a7110`.
3. **Semantics:** state-2 follow-object shortcuts update:
   - Scope plate `"CVOGWaypoint::DoFollowObjectShortcutsUpdate"`.
   - Resolve TFID `this+0x30`; flag `+0x52` from object `+0x17c` bit5.
   - RTDynamicCast → `CVOGPhysicsBase`; dual pose load (rb `+0xb0` / entity `+0x84`).
   - Surface distance owner↔target; `+0x53` vs patrol `+0x4c`; snap if dist &lt; **1.0**.
   - Path COID valid → `FUN_005d5960` + dir-dot **0.2** clear path / snap target world.
   - Else `FUN_004d5910` gather; pick nearest; COID from `+0x134` → `+0x40/44`; vtbl pose write.
4. **Constants:** `g_flOne=1.0f` (`00a0f2a0`); `DAT_00a0f70c=0.2f`; `_DAT_009dace0=1e7f`; plate @ `009dace4`.
5. **Callees:** resolve / dynamic_cast / surface-distance / GetWorldPositionPtr / `FUN_005d5960` / `FUN_004d5910` / `operator_delete` / scope pair / virtuals.
6. **Callers:** **1** UNCONDITIONAL_CALL — `CVOGWaypoint_UpdateState` @ `0x005d6353` (state case **2**).
7. **Xrefs:** 1 code xref (same).
8. **Name:** `CVOGWaypoint_DoFollowObjectShortcutsUpdate` (Ghidra `FUN_005d5cc0`). Product plate sealed — **not** `_Inferred`; **not** invented `CVOGHBAI*`.
9. **Decompile ≡ raw CF**; ABI/this-arg residuals sealed via `disassemble_function` + `read_memory`.
10. **Scaffold retired:** `Named_CalleeOf_CVOGWaypoint_UpdateState_005d5cc0`.

### Gaps

- Product English for residual callees `FUN_004d5910`, `FUN_005d5960`.  
- Candidate object class (vtbl `+0x10`/`+0x2c`, field `+0x134`).  
- Full flag `+0x17c` bit5 plate English.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005d5cc0_CVOGWaypoint_DoFollowObjectShortcutsUpdate.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005d5cc0_CVOGWaypoint_DoFollowObjectShortcutsUpdate.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_005d5cc0_FUN_005d5cc0.md` |
| Annotated | `docs/reconstruction/raw/aa_005d5cc0_FUN_005d5cc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGWaypoint_DoFollowObjectShortcutsUpdate.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005d5cc0.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_CVOGWaypoint_UpdateState_005d5cc0.cpp` |
| Function | `docs/reconstruction/functions/aa_005d5cc0_FUN_005d5cc0.md` |
| Function named | `docs/reconstruction/functions/aa_005d5cc0_CVOGWaypoint_DoFollowObjectShortcutsUpdate.md` |

---

## Chain context (not dualled; evidence only)

```text
CVOGWaypoint_InitFromSpawn  [dualed elsewhere]
  seeds +0x40/44/48 = -1; +0x4c patrol; +0x50 = 0 or 2

CVOGWaypoint_UpdateState  [dualed earlier; dispatcher]
  switch(+0x50):
    0 → FUN_005d5750
    1 → FUN_005d5960          [residual peer]
    2 → FUN_005d5cc0          [OWN MEGA-057]  CVOGWaypoint_DoFollowObjectShortcutsUpdate
    3 → FUN_005d5680

FUN_005d5cc0
  ├─ Object_ResolveFromTFID (follow TFID +0x30)
  ├─ Object_SurfaceDistance3D_Inferred (owner, target)
  ├─ FUN_005d5960 (when path COID valid)
  ├─ Object_GetWorldPositionPtr
  ├─ FUN_004d5910 (shortcut gather; residual)
  └─ vtbl +0x10 / +0x2c (candidate path/pose)
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-005d5cc0-mega-057-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005d5cc0` | Port as **`CVOGWaypoint::DoFollowObjectShortcutsUpdate`**. **thiscall void RET 0**. State-2 only. Write pose `+0x20`; maintain COIDs `+0x40/44/48`; flags `+0x52/+0x53`. Distance gates: **1.0** snap, **0.2** dir-dot clear. Pair with UpdateState case 2 and InitFromSpawn patrol `+0x4c`. Do **not** invent `CVOGHBAI*` plate. Keep residual gather/state-1 peers as FUN_* until dualed. |
| Pair with | dualed `CVOGWaypoint_UpdateState` `005d6300`; dualed `CVOGWaypoint_InitFromSpawn` `005d5580`; residual `FUN_005d5960` / `FUN_004d5910`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history (retire Named_CalleeOf scaffold)  
- `systems/*` waypoint / skills residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x005d5cc0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses product plate name; Named_CalleeOf scaffold **retired**.  
- Odd behavior preserved: decompiler surface-distance this residual; operator_delete continues; path-clear snap uses **target** world pos.  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
