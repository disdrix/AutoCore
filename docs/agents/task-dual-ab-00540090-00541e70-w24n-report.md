# Dual A/B report — W24-N OWN `aa_00540090` + `aa_00541e70`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W24-N  
**Scope:** VAs `0x00540090`, `0x00541e70` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ xrefs / caller decompile). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00540090` SkillDef_BuildFxMasterName_Inferred | **accept** — cdecl basename CF + string table + callers sealed |
| `aa_00541e70` CloneBase_Load | **accept-with-gaps** — thiscall/`ret 0xC` + phase order + host hashes sealed; flag product names + nested duals residual |

---

## VA `0x00540090` — sealed facts

1. **Body:** `0x00540090`–`0x00540282` (498 B / `0x1F2`; plain `ret`).
2. **ABI:** **`__cdecl`** — stack `skillPayload*`, `char* out`, `size_t cap`; caller `add esp,0xC`.
3. **Semantics:** Build FX master basename `"skill_" + classTag + categoryTag + name`.
4. **Class `+0x180`:** 0→`h_`, 1→`m_`, 2→`c_`, else→`n_` (strings sealed `read_memory`).
5. **Category `+0x17c`:** 0→`c_`, 1→`e_`, 2→`o_`, 3→`r_`, default→`fixme_`.
6. **Name:** C-string at payload `+0x5a6` (≡ RB node+0x5B6 when caller passes node+0x10).
7. **Callee:** `strncpy` only.
8. **Callers (3):** `FxCache_EnsureMasterAndResolve` @ `0x00540979`; `FxCache_ApplyWithNfxEnsure` @ `0x005428f2`; `FUN_005c74e0` @ `0x005c761a`.
9. **Name:** `SkillDef_BuildFxMasterName_Inferred` (Ghidra `FUN_00540090`).
10. **Decompile ≡ bytes** for CF + string table.

### Gaps

- Product English for class/category enums.  
- Runtime / bit-exact golden strings.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00540090_SkillDef_BuildFxMasterName_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00540090_SkillDef_BuildFxMasterName_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00540090_FUN_00540090.md` |
| Annotated | `docs/reconstruction/raw/aa_00540090_FUN_00540090.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SkillDef_BuildFxMasterName_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00540090.cpp` |
| Function | `docs/reconstruction/functions/aa_00540090_FUN_00540090.md` |
| Function named | `docs/reconstruction/functions/aa_00540090_SkillDef_BuildFxMasterName_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_00540090.md` |

---

## VA `0x00541e70` — sealed facts

1. **Body:** `0x00541e70`–`0x00542757` (~2279 B / `0x8E7`; **`ret 0x0C`**).
2. **ABI:** **`__thiscall`** — ECX=host*; stack `flagA`, `flagB`, `flagC`; SEH `LAB_009a40ca`.
3. **Semantics:** Full **CloneBase load** orchestrator (`"CloneBase: start"` … `"CloneBase: end"`).
4. **Host hashes:** `+0xF10`, `+0xF14`, `+0xF0C` (skills FX), `+0xEF0` after `new(0x34)` + hash ctors.
5. **First-time** (`DAT_00b04690==1`): global name hash, PrepareDataConnection, ReadConfigCosts/NewChars, ReadRemovedObjects.
6. **WAD:** `CloneBase_LoadWadFile` — fail throws.
7. **Array:** stride **`0x114`** → `new(0x200)` objects; type switch; loot path when flagB&&!flagC.
8. **Maps:** stride **`0x154`** → `FUN_005ea260` + 0x21 bucket inserts when !flagC.
9. **Late:** optional RegionMissions `+0xF18`; TypeDef hash `+0xF1C` + `FUN_00541950`; LoadSkillsFX (`FUN_00541aa0`) + SpecialFXMaster (`FUN_004a6790`) gated by globals.
10. **Caller (1):** `FUN_00542aa0` @ `0x00542bf9` when `param_5==0`.
11. **Name:** `CloneBase_Load` (supersedes auto-alias `Mission_after_CVOGRegionMissions_*`).
12. **Decompile ≡ bytes** for CF + ABI.

### Gaps

- Product English for three bool flags (gate roles Probable).  
- Full 0x114 / 0x154 record layouts.  
- Nested callee duals (not OWN).  
- Runtime flag matrix / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00541e70_CloneBase_Load.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00541e70_CloneBase_Load.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00541e70_FUN_00541e70.md` |
| Annotated | `docs/reconstruction/raw/aa_00541e70_FUN_00541e70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CloneBase_Load.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00541e70.cpp` |
| Superseded alias | `docs/reconstruction/reconstructed-exact/Mission_after_CVOGRegionMissions_00541e70.cpp` |
| Function | `docs/reconstruction/functions/aa_00541e70_FUN_00541e70.md` |
| Function named | `docs/reconstruction/functions/aa_00541e70_CloneBase_Load.md` |
| Scratch | `docs/reconstruction/tmp/a_00541e70.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00540090` | Skill FX master basename format — preserve `skill_` + tag tables + name@payload+0x5a6; cdecl; pass node+0x10 not raw RB node. |
| `00541e70` | Client CloneBase load sequence — preserve hash field map, first-time gate, WAD-before-array, flag matrix, LoadSkillsFX host+0xF0C population order. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- This report: `docs/agents/task-dual-ab-00540090-00541e70-w24n-report.md`
