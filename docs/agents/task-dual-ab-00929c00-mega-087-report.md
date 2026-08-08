# Dual A/B report — MEGA-087 OWN-ONLY (`0x00929c00`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-087**  
**Scope:** VA `0x00929c00` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + parent call-site disasm. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — missions-progression **Tracker UI/state companion** (partition peer of residual `0x0092a590`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00929c00` MissionTracker_ResetUiStateFields_Inferred | **accept-with-gaps** — CF/ABI/RET/AL=1/EAX-object/MOVSS-25.0f/3 call sites/leaf sealed; product field English + RTTI class open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): thiscall / cdecl-stack-this / full-ctor / mission-dialog-primary / integer-DAT / dead-helper / non-leaf claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00929c00` — sealed facts

1. **Body:** `0x00929c00`–`0x00929c50` inclusive (**81 B** / `0x51`); terminal **`C3`**; `CC` pad after.
2. **ABI:** **EAX** = mission-tracker object; no stack formals; **`AL = 1`**; bare **`RET`**. **Not** ECX thiscall.
3. **Semantics:** reset derived tracker UI/state fields:
   - `+0x18/+0x20/+0x24/+0x108/+0x10c` ← `-1`
   - `+0x54/+0x80/+0xac/+0x28` ← `0`
   - `+0x100/+0x101/+0x102` ← `0` (bytes)
   - `+0x104` ← float **25.0f** from `DAT_00aaa6fc` (`MOVSS`)
4. **Callees:** none (leaf; cyclomatic 1; 18 instructions; 1 BB).
5. **Callers (code):**  
   - `FUN_0092a590` @ `0x0092a5a8`, `0x0092a5ef` (`MOV EAX,EDI`) — clear/miss arms of set-active.  
   - `FUN_0092c080` @ `0x0092c47f` (`MOV EAX,ESI`) — region/sector id change.
6. **Xrefs:** 3 UNCONDITIONAL_CALL (matches callers).
7. **Upstream:** dualed `Client_TryBindActiveMissionTracker` `0x0092fd00` → `FUN_0092a590` (tracker = client+`0x4d0`); residual `FUN_0092c640` → `FUN_0092c080`.
8. **Name:** `MissionTracker_ResetUiStateFields_Inferred` (Ghidra `FUN_00929c00`). Product field English open → `_Inferred`. Scaffold `Named_CalleeOf_*MissionDial*` **retired**.
9. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + full-body `read_memory` + call-site context.

### Gaps

- Product English for each written offset.  
- Formal RTTI / C++ class name of tracker blob.  
- Dual of residual parents `FUN_0092a590` / `FUN_0092c080` / `FUN_0092a3d0`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00929c00_MissionTracker_ResetUiStateFields_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00929c00_MissionTracker_ResetUiStateFields_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00929c00_FUN_00929c00.md` |
| Annotated | `docs/reconstruction/raw/aa_00929c00_FUN_00929c00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MissionTracker_ResetUiStateFields_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00929c00.cpp` |
| Function | `docs/reconstruction/functions/aa_00929c00_FUN_00929c00.md` |
| Function named | `docs/reconstruction/functions/aa_00929c00_MissionTracker_ResetUiStateFields_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
Client_TryBindActiveMissionTracker  0x0092fd00  [dualed]
  └─ FUN_0092a590  Tracker_SetActiveMissionObjective  [residual]
        ├─ FUN_0092a3d0   tidy vector @ tracker+0x11c     [residual]
        └─ FUN_00929c00   ResetUiStateFields              [OWN MEGA-087]
              (clear id==0 path @ 0x0092a5a8;
               hash-miss path @ 0x0092a5ef)

FUN_0092c640  [residual]
  └─ FUN_0092c080  tracker derived rebuild               [residual]
        ├─ (inline same field plate at entry)
        └─ FUN_00929c00  on region change @ 0x0092c47f   [OWN MEGA-087]

Related chrome (not caller of this leaf):
  Client_MissionTrackerHud_Refresh_Inferred  0x008a8770  [dualed]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00929c00-mega-087-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00929c00` | Port as **mission-tracker field reset leaf**. Object in **EAX** (not thiscall). Bare RET. Always return **1**. Restore float **`+0x104 = 25.0f`** from shared global. Do **not** treat as full ctor or mission-dialog handler. |
| Pair with | dualed `Client_TryBindActiveMissionTracker` `0092fd00`; residual set-active `0092a590`; residual rebuild `0092c080`; dualed HUD refresh `008a8770`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history (retire `Named_CalleeOf_*MissionDial*00929c00`)  
- `systems/*` residual tables (missions-progression / tracker)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN residual).

---

## Process

- OWN VA only (`0x00929c00`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs + call-site context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful name; machine ABI (EAX object, MOVSS float) corrected vs decompiler `void`/phantom-only display.  
- Odd behavior preserved: always-success return; shared plate also inlined in `0092c080`.  
- `_Inferred` where product field English unproven; tracker role High via dualed bind. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
