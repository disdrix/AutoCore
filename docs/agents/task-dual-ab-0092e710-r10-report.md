# Dual A/B report — R10-016 OWN-ONLY (`0x0092e710`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R10-016**  
**Scope:** VA `0x0092e710` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs; parent dual `0x00521800` edits.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `get_function_callers` / `get_function_xrefs` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** Residual dual wave R10 — undualed callee of dualed HP manager; partition system missions-progression; parent dual `0x00521800`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0092e710` Character_FormatLevelRaceClassLine_Inferred | **accept-with-gaps** — CF/ABI/line shape/`"Level "`/space sep/dualed race+class helpers/sole UI caller sealed; product English + vtbl+0x27c name + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): void-return / EBX-noise / thiscall-only / ring-return / level-only / multi-caller / scaffold-product claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0092e710` — sealed facts

1. **Body:** `0x0092e710`–`0x0092e8a7` inclusive (**408 B** / `0x198`); pad `CC` @ `0x0092e8a8+`.
2. **ABI:** stack **`character*`** (cdecl; caller `ADD ESP,4`); register **`EBX = char* outBuf`**; returns **`int` strlen** (or **0** on null args); plain **`RET`** after `POP EBP; ADD ESP,0xC`.
3. **Semantics:** **level/race/class display-line formatter**:
   - Ring-copy `"Level "` @ `0x00a2d280`.
   - Level int from nested character vtbl **`+0x27c`**; `_itoa` radix 10 into 12-byte stack scratch; append.
   - Append space (`DAT_00a2a000` = `0x0020`); dualed **`Character_GetRaceDisplayName_Inferred`** (`0x00521800`); ring re-buffer; append.
   - Append space; dualed **`Character_GetClassDisplayName_Inferred`** (`0x00521900`); ring re-buffer; append.
   - Return `strlen(outBuf)`.
4. **Output shape:** `Level <n> <Race> <Class>`.
5. **Callees:** `FUN_007a69d0`, `FUN_007a6de0`, `_itoa`, `FUN_00521800`, `FUN_00521900`.
6. **Callers:** **1** — `FUN_008f97c0` @ `0x008f9806` (character-sheet UI refresh; player `DAT_00d1b6d8`; widget `this[0x520]` set-text vtbl `+0x1d8`).
7. **Xrefs:** 1 UNCONDITIONAL_CALL.
8. **Name:** `Character_FormatLevelRaceClassLine_Inferred` (Ghidra `FUN_0092e710`). Scaffold `Named_CalleeOf_Skill_Combat_Fighting_and_driving_ability_Affect_0092e710` **retired**.
9. **Decompile ≡ raw CF**; ABI + epilogue + call site sealed via `read_memory` (no `disassemble_bytes`).

### Gaps

- Product/PDB method English.  
- Official name of vtbl slot `+0x27c` (role sealed as level getter).  
- Full Character C++ type / intermediate objects.  
- Class English table residual `FUN_0051f940` (not owned).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0092e710_Character_FormatLevelRaceClassLine_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0092e710_Character_FormatLevelRaceClassLine_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify append) | `docs/reconstruction/raw/aa_0092e710_FUN_0092e710.md` |
| Annotated | `docs/reconstruction/raw/aa_0092e710_FUN_0092e710.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Character_FormatLevelRaceClassLine_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0092e710.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Skill_Combat_Fighting_and_driving_ability_Affect_0092e710.cpp` |
| Function | `docs/reconstruction/functions/aa_0092e710_FUN_0092e710.md` |
| Function named | `docs/reconstruction/functions/aa_0092e710_Character_FormatLevelRaceClassLine_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_008f97c0  character-sheet UI refresh  [residual]
  when DAT_00d1b6d8 (player) != 0 && this[0x520] widget:
    PUSH player
    LEA  EBX, local_buf   ; zero first byte
    CALL 0x0092e710  Character_FormatLevelRaceClassLine_Inferred  [OWN R10-016]
    ADD  ESP, 4
    widget vtbl+0x1d8 set-text(local_buf)
    …
    (nearby skill tooltip strings — source of retired scaffold name)

Character_GetRaceDisplayName_Inferred   0x00521800  [dualed — partition parent]
Character_GetClassDisplayName_Inferred  0x00521900  [dualed]
  └─ FUN_0051f940 class English lookup   [residual]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0092e710-r10-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0092e710` | Port as **character level/race/class line formatter**. **Stack character\*** + **EBX out buffer**, return **strlen**. Output: `"Level " + n + " " + race + " " + class`. Pair with dualed race/class display helpers. Do **not** treat as void/thiscall/ring-return. UI-only sole caller. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history (retire `Named_CalleeOf_Skill_Combat_…0092e710`)  
- `systems/missions-progression.md` residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).
