# Dual A/B report — R10-014 OWN-ONLY (`0x005792d0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R10-014**  
**Scope:** VA `0x005792d0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs; parent dual `0x00521800` edits.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `get_function_callers` / `get_function_xrefs` + `read_memory` + `list_strings`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** Residual dual wave R10 — undualed callee of dualed race display helper; partition system missions-progression; parent dual `0x00521800`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005792d0` Mission_FormatDialogTokenValue_Inferred | **accept-with-gaps** — CF/ABI/7-way case table/faction string/dualed race+class helpers/sole dialog caller sealed; product English + vtbl names + case-6 intent + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): void-return / cdecl / multi-caller / float-only arg4 / unaff multi-buffer / scaffold-product / case-6-success claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x005792d0` — sealed facts

1. **Body:** `0x005792d0`–`0x00579584` inclusive (**693 B** / `0x2B5`); align `8D 49 00` @ `0x00579585`; jump table @ `0x00579588` (7 dwords); pad `CC`.
2. **ABI:** **`__thiscall`** `ECX` = context* (TFID at `+0x30`); **5 stack dwords** (`outBuf`, `formatOrTokenText`, `tokenDesc*`, `objectOrFloatSlot`, `mapOrCharacter*`); **`RET 0x14`**; returns **`uint8` in AL** (`1` success / `0` fail).
3. **Semantics:** **mission-dialog per-token value formatter** switched on `*tokenDesc` (0..6):
   - **0** float/var: TFID gate → embedded float or `CVOGMap_LookupVariable`; `sprintf(out, fmt, double)`.
   - **1** object name via nested vtbl **`+0x160`** → strcpy.
   - **2** class of object → dualed `Character_GetClassDisplayName_Inferred` (`0x00521900`) + ring `007a6de0` → strcpy.
   - **3** race of object → dualed `Character_GetRaceDisplayName_Inferred` (`0x00521800`) + ring → strcpy.
   - **4** faction: character `vtbl+0x210` path → race name; else `"!Non-Character Faction not implemented yet!"` @ `0x009d4104` (always return 1).
   - **5** display name: character `+0x210`/`+0x160` or entity string at `this[0x2a]+0x40`.
   - **6** class of character → write class name then **return 0** (machine-confirmed).
4. **Callees:** `FUN_007a69d0`, `FUN_007a6de0`, `TFID_EqualsObjectId`, `CVOGMap_LookupVariable`, `sprintf`, `FUN_00521800`, `FUN_00521900`.
5. **Callers:** **1** — `FUN_00579fb0` @ `0x0057a080` (mission dialog token-walk string builder).
6. **Xrefs:** 1 UNCONDITIONAL_CALL.
7. **Name:** `Mission_FormatDialogTokenValue_Inferred` (Ghidra `FUN_005792d0`). Scaffolds `Named_CalleeOf_…Mission_Dialog_has_005792d0` and `Named_Non_Character_Faction_not_implemented_yet` **retired as product**.
8. **Decompile ≡ raw CF**; ABI + jump table + epilogues + string sealed via `read_memory` (no `disassemble_bytes`).

### Gaps

- Product/PDB method English + token type enum names.  
- Official vtbl `+0x160` / `+0x210` method names.  
- Full C++ types (context / map / character / TokenDesc).  
- Case **6** product intent (write-then-fail).  
- Runtime / bit-exact / differential.  
- Parent walker `FUN_00579fb0` / parser `FUN_00578f80` residual (not owned).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005792d0_Mission_FormatDialogTokenValue_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005792d0_Mission_FormatDialogTokenValue_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify append) | `docs/reconstruction/raw/aa_005792d0_FUN_005792d0.md` |
| Annotated | `docs/reconstruction/raw/aa_005792d0_FUN_005792d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Mission_FormatDialogTokenValue_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005792d0.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_Dialog_has_005792d0.cpp` |
| Function | `docs/reconstruction/functions/aa_005792d0_FUN_005792d0.md` |
| Function named | `docs/reconstruction/functions/aa_005792d0_Mission_FormatDialogTokenValue_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_00579fb0  mission dialog token-walk string builder  [residual]
  loop tokens:
    FUN_00578f80  parse next format segment              [residual]
    CALL 0x005792d0  Mission_FormatDialogTokenValue_Inferred  [OWN R10-014]
      AL==0 → wrap raw token text in marker words
      AL!=0 → append formatted value; advance token iterator

Character_GetRaceDisplayName_Inferred   0x00521800  [dualed — partition parent]
Character_GetClassDisplayName_Inferred  0x00521900  [dualed]
  used by cases 3/4 and 2/6 respectively

Mission_ExpandPlayerTokenPlaceholders_Inferred  0x005465c0  [dualed, different path]
  fixed [$name]/[$class]/[$race]/… replace-all — NOT this VA
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-005792d0-r10-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005792d0` | Port as **mission-dialog typed token value formatter**. **thiscall** context* + **5 stack args**, **`RET 0x14`**, return **bool in AL**. Switch on token type 0..6. Pair with dualed race/class display helpers. Preserve case **6 write-then-return-0**. Do **not** treat as void/cdecl/strlen or as the fixed `[$race]` expander (`0x005465c0`). Sole parent is dialog token walker. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history (retire Mission_Dialog / Faction string scaffolds)  
- `systems/missions-progression.md` residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).
