# Dual A/B report — MEGA-020 OWN-ONLY (`0x00802b70`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-020**  
**Scope:** VA `0x00802b70` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs/callees + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` → **MEGA-020**.  
**Work item:** Mega residual dual seal — skills-abilities client OnEnd UI cleanup; parent dual `Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred` `0x00578ce0`.  
**Hint:** `Client_SkillHB_OnEndUiCleanup` → sealed as `Client_SkillHB_OnEndUiCleanup_Inferred`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00802b70` Client_SkillHB_OnEndUiCleanup_Inferred | **accept-with-gaps** — CF/ABI RET8/registration/OnEnd invoker/local-vs-non-local UI paths sealed; product English + residual nested callees open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): InitInstance-direct-call / thiscall / single-arg / FireTail-merge / always-rebuild / product-name / runtime-Confirmed claims **falsified**; `Named_CalleeOf_*InitInstance*` scaffold **retired**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00802b70` — sealed facts

1. **Body:** `0x00802b70`–`0x00802c7b` exclusive (**267 B** / `0x10B`); terminal **`C2 08 00`**.
2. **ABI:** **`__stdcall`**; stack `skillHb*, unused`; **RET 0x8**; void. **Not** thiscall. Arg2 unused (OnEnd pushes `0`).
3. **Semantics:** client skill HB **OnEnd UI cleanup**:
   - If UI tracker `DAT_00d1d8e0+0x514 == hb` → `FUN_007fc970` (ESI = client `0x00d1a840`) clear sheet bind.
   - Require local player `DAT_00d1b6d8` + owner `hb+0x18`.
   - Local-owned: optional `UI_VehicleInvSheet_RebuildStatsLabels_Inferred` (`DAT_00d1b8b8`, gate `vtbl+0x3d8`).
   - Non-local: gate `hb+0xfe`; resolve via dualed `Object_ResolveTargetViaReaction_Inferred` (3 sites); if local-related → `FUN_008027e0(owner)`.
   - Join: `FUN_0083bf40(*(DAT_00d1b8ec+0x590), hb)` when list present.
4. **Registration:** Client InitInstance `FUN_0094a6a0` @ `0x0094a981` → `PTR_FUN_00af31e0 = this`. Sibling `PTR_FUN_00af31e4 = FUN_00802c80`.
5. **Invoker:** dualed OnEnd `0x00578ce0` first action `PTR_FUN_00af31e0(hb, 0)`. No direct CODE callers (`get_function_callers` empty).
6. **Xrefs:** 1 DATA from InitInstance.
7. **Callees:** `FUN_007fc970`, `FUN_00578270` (dualed), `FUN_008027e0`, `FUN_0087d810` (dualed), `FUN_0083bf40` + owner/sheet vfuncs.
8. **Name:** `Client_SkillHB_OnEndUiCleanup_Inferred` (Ghidra `FUN_00802b70`). Product open → `_Inferred`. Scaffold `Named_CalleeOf_Named_Client_InitInstance_*` **retired**.
9. **Decompile ≡ raw CF**; ABI/ESI sealed via `disassemble_function` + `read_memory` + call-site context (decompiler under-counts args — documented gap, not CF conflict).

### Gaps

- Product / PDB English.  
- Residual nested duals: `007fc970`, `008027e0`, `0083bf40` (not OWN).  
- Owner/target `vtbl+0x1dc`/`+0x1d4` and UI host global English.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00802b70_Client_SkillHB_OnEndUiCleanup_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00802b70_Client_SkillHB_OnEndUiCleanup_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00802b70_FUN_00802b70.md` |
| Annotated | `docs/reconstruction/raw/aa_00802b70_FUN_00802b70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_SkillHB_OnEndUiCleanup_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00802b70.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_Client_InitInstance_00802b70.cpp` |
| Function | `docs/reconstruction/functions/aa_00802b70_FUN_00802b70.md` |
| Function named | `docs/reconstruction/functions/aa_00802b70_Client_SkillHB_OnEndUiCleanup_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Client InitInstance  FUN_0094a6a0
  ├─ PTR_FUN_00af31e0 = FUN_00802b70  Client_SkillHB_OnEndUiCleanup_Inferred  [OWN MEGA-020]
  └─ PTR_FUN_00af31e4 = FUN_00802c80  FireTail client hook twin  [residual]

Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred  0x00578ce0  [dualed WQ9D-F]
  ├─ PTR_FUN_00af31e0(hb, 0)  →  THIS UNIT  [OWN MEGA-020]
  │     ├─ FUN_007fc970                 [residual]  ESI=client 0xd1a840
  │     ├─ Object_ResolveTargetViaReaction_Inferred  0x00578270  [dualed]
  │     ├─ FUN_008027e0                 [residual]  owner UI panel teardown
  │     ├─ UI_VehicleInvSheet_RebuildStatsLabels_Inferred  0x0087d810  [dualed]
  │     └─ FUN_0083bf40                 [residual]  UI list remove
  ├─ resolve / clear +0x6b0 / owner notify / cast clear …
  └─ tail empty base OnEnd

Skill_HB_FireTail_FxTargetAndPeriodStamp  0x00578b30  [dualed]
  └─ PTR_FUN_00af31e4 → FUN_00802c80  [not OWN; do not merge]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00802b70-mega-020-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00802b70` | Port as **client skill-HB OnEnd UI cleanup** hook. **`__stdcall` RET 0x8** — `(skillHb*, unused)`. Install at the function-pointer slot parent OnEnd calls (`PTR_FUN_00af31e0`). Do **not** model as thiscall skill body or as InitInstance CODE callee. |
| Distinct from | FireTail twin `00802c80` / `00af31e4`; combat OnEnd work in `00578ce0` after the PTR call. |
| Pair with | dualed OnEnd `00578ce0`; dualed resolve `00578270`; dualed sheet rebuild `0087d810`; residual `007fc970` / `008027e0` / `0083bf40`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / `NAMING_REGISTRY.md` / coverage ledgers — **not touched** by this agent.
- Name to register: `Client_SkillHB_OnEndUiCleanup_Inferred` @ `0x00802b70` / `aa_00802b70`.
- System: `skills-abilities`.
- Verdict: **accept-with-gaps**; Terminal **false**.

---

## Process

- OWN VA only (`0x00802b70`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs/callees + assembly context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean sources use meaningful `_Inferred` name; machine ABI corrections (stdcall RET 8; ESI for `007fc970`).  
- `Named_CalleeOf_*InitInstance*` retired (registration ≠ invocation).  
- Odd behavior preserved: unused second arg; triple re-resolve; ESI-fixed clear helper.  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
