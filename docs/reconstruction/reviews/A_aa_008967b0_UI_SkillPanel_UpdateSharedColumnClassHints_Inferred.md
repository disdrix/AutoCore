# Review A (reconstruction fidelity): `aa_008967b0` UI_SkillPanel_UpdateSharedColumnClassHints_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008967b0` |
| **VA** | `0x008967b0`–`0x00896986` inclusive (**471 B** / `0x1D7`); pad `CC` |
| **Canonical name** | `UI_SkillPanel_UpdateSharedColumnClassHints_Inferred` |
| **Ghidra name** | `FUN_008967b0` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (Path A) |
| **Counterpart** | `reviews/B_aa_008967b0_UI_SkillPanel_UpdateSharedColumnClassHints_Inferred.md` |
| **System** | `skills-abilities` |
| **Agent** | R11-034 OWN-ONLY dual |
| **Parent (partition)** | `0x0051f940` `LookupClassDisplayName_Inferred` |
| **Verdict** | **accept-with-gaps** — CF/ABI/table/strings/sprintf-arity/EDI-this sealed; product method + vtbl+0x308 English open |

---

## 1. Purpose

Skill-panel helper: for mode `panel+0x51c == 1`, write localized **shared-column class hints** onto widgets at `panel+0x744` and `panel+0x748`:

```text
"This column of skills is shared by the <ClassName> class."
```

`<ClassName>` = dualed `LookupClassDisplayName_Inferred(sharedClassId, raceId)` where `sharedClassId` comes from a 12-pair hard-coded table indexed by local character `(class@+0x531, race@+0x532)`.

```c
// EDI-this; plain RET; no stack args
void UI_SkillPanel_UpdateSharedColumnClassHints_Inferred(void /* EDI = panel* */);
```

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Raw (+ R11-034 re-verify append) | `docs/reconstruction/raw/aa_008967b0_FUN_008967b0.md` |
| Annotated | `docs/reconstruction/raw/aa_008967b0_FUN_008967b0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/UI_SkillPanel_UpdateSharedColumnClassHints_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_008967b0.cpp` |
| Prior scaffolds | `Skill_This_column_of_skills_is_shared_by_the*.cpp` (string-plate; superseded by role name) |
| Live Ghidra | `decompile_function`, `analyze_function_complete`, `disassemble_function`, `get_function_by_address`, xrefs, `get_assembly_context`, `read_memory` |
| Parent dual | `A_aa_0051f940_LookupClassDisplayName_Inferred` |
| Locale helpers | dualed `007a69d0` / `007a6de0` |

**No** `disassemble_bytes`. **No** Launcher.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body `0x008967b0`–`0x00896986` incl. 471 B | **Confirmed** | `get_function_by_address` + epilogue `C3` + `CC` pad |
| EDI-this; plain `RET`; no stack args | **Confirmed** | disasm + caller `MOV EDI,EBP` @ `0x00897a87` |
| Sole xref `0x00897a89` UNCONDITIONAL_CALL | **Confirmed** | xrefs |
| Live decompile ≡ raw CF skeleton | **Confirmed** | 2026-08-05 re-decompile |
| Gate `DAT_00d1b6d8 != 0` | **Confirmed** | |
| Gate `*(EDI+0x51c) == 1` | **Confirmed** | CMP/JNZ around table fill |
| Widgets `+0x744` / `+0x748` + null checks | **Confirmed** | |
| class@+0x531 / race@+0x532 on local blob | **Confirmed** | loads + peer duals |
| 24-dword share table constants | **Confirmed** | sequential stack MOVs |
| Index `classId + raceId*4`, pair×2 | **Confirmed** | `LEA`/`MOV` scale |
| `LookupClassDisplayName` cdecl 2-arg + `ADD ESP,8` | **Confirmed** | parent dual + site cleanup |
| sprintf 3-string arity (`ADD ESP,0x14`) | **Confirmed** | decompiler undercount corrected |
| Product English prefix + `"class"` + format | **Confirmed** | `read_memory` string VAs |
| Role = shared skill-column class hints | **High** | product string + UI path |
| Product/PDB method name | **Inferred** | `_Inferred` |
| `vtbl+0x308` English | **Tentative** | SetText-class likely |
| Host function identity @ `0x00897a89` | **Open** | no Ghidra function; XML `i_d_s_2d_wnd_*` nearby |
| Runtime / bit-exact | **Open** | Terminal false |

---

## 4. Control flow summary

| Stage | Behavior |
|---|---|
| Locale | `FUN_007a69d0` → ESI pool |
| Session gate | early-out if `DAT_00d1b6d8 == 0` |
| Table | 12 pairs on stack (see annotated) |
| Mode gate | `panel+0x51c == 1` else exit |
| Column A | if widget `+0x744`: lookup pair.A → format → `vtbl+0x308` |
| Column B | if widget `+0x748`: lookup pair.B → format → `vtbl+0x308` |
| Exit | restore ESI / frame; plain RET |

---

## 5. Gaps (acceptable)

1. Product / PDB C++ method name (keep `_Inferred`).
2. Exact English for `vtbl+0x308` and `panel+0x51c` mode.
3. Ghidra function recovery for caller host (orphan range).
4. Nested callees not OWN (already dualed peers).
5. Runtime golden matrix / bit-exact / differential.

**Verdict:** **accept-with-gaps** under `_Inferred` name.

---

## Checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **Pass** |
| ABI / epilogue sealed (EDI-this, plain RET) | **Pass** |
| Share table + sprintf arity sealed | **Pass** |
| Named clean + FUN twin | **Pass** |
| Dual A/B pair | **Pass** |
| Verdict | **accept-with-gaps** |
