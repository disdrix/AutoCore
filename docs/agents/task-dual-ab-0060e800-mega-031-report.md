# Dual A/B report — MEGA-031 OWN-ONLY (`0x0060e800`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-031**  
**Scope:** VA `0x0060e800` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `analyze_control_flow` + callers/xrefs + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual partition — missions-progression; Requirement Action fail-distance/flag (Patrol).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0060e800` CVOGObjectiveRequirement_Patrol_EventAction_Inferred | **accept-with-gaps** — CF/ABI/RET 0x1C/vtable+0x04/AutoComplete·AutoFail fields/FailMission×2 no-drain sealed; event product English + virtual English residual |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): progress-Action merge / Eval merge / toast merge / Collect merge / drain-yes / inverted-distance claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0060e800` — sealed facts

1. **Body:** `0x0060e800`–`0x0060e9d0` inclusive (**467 B**); 16 BB; cyclomatic 13; 3 `RET 0x1C` exits.
2. **ABI:** **ECX** = Patrol requirement*; **7 stack args**; **AL** = 0\|1; **`RET 0x1C`**.
3. **Class / vtable:** `CVOGObjectiveRequirement_Patrol` — ctor `FUN_0060e090` installs `PTR_FUN_009e0404`; this method at **`vtable+0x04`** (DATA `0x009e0408`); type dword `req+0x0c = 9`.
4. **Semantics — event Action (fail-distance / flag):**
   - **`event == 0x0C`:** if **AutoFail** (`req+0x18`) → `CVOGReaction_FailMission(**(req+4)+0x14c)`; return 0. No distance.
   - **`event == 0x0B`** + entity ≠ null: match current pad `GenericTargetCOID` to entity COID; 3D distance vs player:
     - **AutoComplete** (`+0x10`): `dist < AutoCompleteDistance(+0x14) + 5.0` → slot float += 1.0; return 1.
     - **AutoFail** (`+0x18`): `dist > AutoFailDistance(+0x1c) - 5.0` → FailMission; else if character-complex `vtbl+0x198` → FailMission.
5. **Constants:** `DAT_00aaa688 = 5.0f` (`read_memory`); `g_flOne = 1.0f` @ `0x00a0f2a0`.
6. **Fields** (cross-sealed dualed GetFlags `0x0060e260` XML tags): AutoComplete/Distance, AutoFail/Distance, targets `+0x30`×8 count `+0xd0`, Laps `+0x24`, slot `+0x08`.
7. **Callees:** `CVOGReaction_FailMission` ×2 (`0x0060e82f` event 0xC; `0x0060e9c3` event 0xB) — **no drain**; entity `vtbl+0x144`; complex `+0x1a0` / `+0x198`.
8. **Callers:** **none** static CALL; virtual-only via DATA bind.
9. **Xrefs:** 1 DATA @ `0x009e0408`.
10. **Name:** `CVOGObjectiveRequirement_Patrol_EventAction_Inferred` (Ghidra `FUN_0060e800`). `_Inferred` — class High; method English not PDB-demangled.
11. **Decompile ≡ raw CF**; ABI/event typing corrected via `disassemble_function` + `read_memory`.

### Do-not-merge peers

| VA | Dualed name | Slot / role |
|----|-------------|-------------|
| `0x0060e120` | `CVOGObjectiveRequirement_Patrol_Action` | `vtable+0x10` progress **fraction only** |
| `0x0060e0f0` | `CVOGObjectiveRequirement_Patrol_Eval` | `vtable+0x08` complete gate |
| `0x00637de0` | Requirement progress toast Action | `vtable+0x20` shared toast |
| `0x00611f20` | `CVOGObjectiveRequirement_Collect_Action` | Collect event Action (same slot family, different class) |

### Gaps

- Product English for event codes **0x0B** / **0x0C**.  
- Product names for entity `+0x144` and character-complex `+0x1a0` / `+0x198`.  
- Static 7-arg Action dispatcher residual.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0060e800_CVOGObjectiveRequirement_Patrol_EventAction_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0060e800_CVOGObjectiveRequirement_Patrol_EventAction_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify append) | `docs/reconstruction/raw/aa_0060e800_FUN_0060e800.md` |
| Annotated | `docs/reconstruction/raw/aa_0060e800_FUN_0060e800.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGObjectiveRequirement_Patrol_EventAction_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0060e800.cpp` |
| Function FUN | `docs/reconstruction/functions/aa_0060e800_FUN_0060e800.md` |
| Function named | `docs/reconstruction/functions/aa_0060e800_CVOGObjectiveRequirement_Patrol_EventAction_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
PTR_FUN_009e0404  CVOGObjectiveRequirement_Patrol vtable
  +0x00  FUN_006126f0              scalar deleting dtor
  +0x04  FUN_0060e800              EventAction AutoComplete/Fail  [OWN MEGA-031]
  +0x08  0060e0f0                  Patrol_Eval                    [dualed]
  +0x10  0060e120                  Patrol_Action (fraction)       [dualed; name collision note]
  +0x20  00637de0                  shared progress toast          [dualed]
  +0x28  0060e3d0                  Patrol_InitActive (HB if AutoFail) [dualed]

FUN_0060e800
  ├─ event 0x0C + AutoFail → CVOGReaction_FailMission (no drain)
  └─ event 0x0B + pad COID match
        ├─ AutoComplete + near → slot += 1.0; AL=1
        └─ AutoFail + far / complex+0x198 → FailMission (no drain)

FailMission dual table lists both call sites as drain-NO consumers.
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0060e800-mega-031-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0060e800` Patrol EventAction | Port as client **Patrol event Action** (`vtable+0x04`): events **0x0B** (pad proximity AutoComplete/Fail distance) and **0x0C** (AutoFail flag). **thiscall RET 0x1C**, 7 stack args. Slot float absolute pad count += 1 on AutoComplete hit. FailMission **without** drain. Distance slop **±5.0f**. Keep distinct from progress-fraction `0060e120` and Eval `0060e0f0`. |
| Pair with | dualed GetFlags `0060e260` field dictionary; dualed FailMission `0052da30`; dualed Collect_Action `00611f20` (shared 7-arg Action ABI); dualed InitActive `0060e3d0` (HB when AutoFail). |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/missions-progression.md` residual tables (Patrol event Action)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  
- Optional: rename dualed progress method `0060e120` away from bare `Patrol_Action` to reduce slot-name collision  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x0060e800`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + analyze_control_flow + read_memory + callers/xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean sources use meaningful `_Inferred` name; machine twin `FUN_0060e800.cpp` kept.  
- Odd behavior preserved: FailMission without drain; inside-band AutoFail still gates on complex+0x198; decompiler float\* event typing corrected via assembly.  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
