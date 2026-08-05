# Dual A/B report — W20-Q OWN-ONLY (`0x0058c850`, `0x00921f70`)

**Date:** 2026-07-29  
**Agent:** W20-Q OWN-ONLY  
**Scope:** OWN ONLY VAs `0x0058c850`, `0x00921f70`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / other parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_0058c850` Skill_ApplyMultiTargetHits_Inferred | **accept-with-gaps** — multi-target TFID list damage apply, skip-first accuracy, roll table, apply/floater, 3 callers, 1008 B body sealed; product English / list class open |
| `aa_00921f70` Client_SelectHostileUnderScreenPick_Inferred | **accept-with-gaps** — screen unproject → hostile mode-2 gather max1 → select/clear; constants 0.015/25/40 sealed; product bind / parent UI fn open |

---

## `aa_0058c850` — Skill_ApplyMultiTargetHits_Inferred

### Sealed facts

1. **Body:** `0x0058c850`–`0x0058cc3f` (**1008** bytes). SEH + bare **`ret`**.

2. **ABI:** `__cdecl` six stack formals; **param_4 unused**. Returns **int total damage**.

3. **Algorithm:** TFID list (stride 16, end `(lo&hi)==~0`) → CS object list → per target: accuracy **skip index 0**, else `Skill_AccuracyHitCheck_Inferred` with `rollTable[(idx%600)*2]`, roll index seed `*6` then `+6`/target; hit → damage from `param_3+0x54..+0x68` (method or modular) → scale `FUN_004cf080` → `Client_Combat_ApplySingleHitMaybeDefer_Inferred`; miss → `Client_EnqueueCombatFloater_INFERRED`.

4. **Callers (3):** `FUN_0054c720` @ `0x0054c79d`, `FUN_0058d8e0` @ `0x0058d952`, `FUN_0061c090` @ `0x0061c104`.

5. **Name:** role-sealed **INFERRED**. Ghidra `FUN_0058c850`. Obsolete parent-seed Named plate incomplete.

### Gaps

1. Product/PDB symbol.  
2. List class (`PTR_FUN_009cb368` / `0040b020` / `004bcbf0`).  
3. Damage field English.  
4. Runtime / bit-exact / differential — open.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0058c850_Skill_ApplyMultiTargetHits_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0058c850_Skill_ApplyMultiTargetHits_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_0058c850_Skill_ApplyMultiTargetHits_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_0058c850_FUN_0058c850.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_ApplyMultiTargetHits_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0058c850.cpp` |
| Raw | `docs/reconstruction/raw/aa_0058c850_FUN_0058c850.md` |
| Annotated | `docs/reconstruction/raw/aa_0058c850_FUN_0058c850.annotated.md` |

---

## `aa_00921f70` — Client_SelectHostileUnderScreenPick_Inferred

### Sealed facts

1. **Body:** `0x00921f70`–`0x009221de` (**623** bytes). Bare **`ret`**; returns **0/1**.

2. **Gate:** `DAT_00d1b6d8 != 0` && `*(u8*)(char+0x4f1)==0`.

3. **Algorithm:** screen XY → unproject ray → height `t` hit → range = `min(dist*0.015f*25.f, 40.f)` → `Skill_GatherTargetsInArea` **mode 2**, **maxTargets 1** → select or clear via `Client_SelectTargetObject_Inferred`.

4. **Constants (`read_memory`):** `0x00aaacbc=0.015f`, `0x00aaa6fc=25.0f`, `0x00a1109c=40.0f`, null TFID `0x00a158b8`, scoreArg `-1.0f`.

5. **Sole xref:** `0x00922262` (UI visibility fall-through; parent region `ret 8`).

6. **Name:** role-sealed **INFERRED**. Ghidra `FUN_00921f70`.

### Gaps

1. Product/PDB / keybind English.  
2. Parent function not defined in Ghidra (~`0x00922223`).  
3. `DAT_00d17944` / `FUN_004cd220` product types.  
4. Runtime / bit-exact / differential — open.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00921f70_Client_SelectHostileUnderScreenPick_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00921f70_Client_SelectHostileUnderScreenPick_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00921f70_Client_SelectHostileUnderScreenPick_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00921f70_FUN_00921f70.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_SelectHostileUnderScreenPick_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00921f70.cpp` |
| Raw | `docs/reconstruction/raw/aa_00921f70_FUN_00921f70.md` |
| Annotated | `docs/reconstruction/raw/aa_00921f70_FUN_00921f70.annotated.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

### Multi-target hits (`0x0058c850`)

- Port as **list consumer**, not world gather.
- **Skip accuracy on first target**; subsequent use shared `Skill_AccuracyHitCheck`.
- Preserve roll table stride (**%600**, index `*6` / `+6`).
- Return **damage sum** (callers test nonzero).
- Miss path must enqueue combat floater, not silent skip only.

### Screen hostile pick (`0x00921f70`)

- Port as **mode-2 single hostile** select under screen ray.
- Range **`0.375 * dist` capped 40** — do not hardcode 40-only.
- Honor busy flag `char+0x4f1` (return false/0).
- Clear selection when gather empty; retail still returns success (1) after clear path.
