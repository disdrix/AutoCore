# Review B (adversarial): `aa_008967b0` UI_SkillPanel_UpdateSharedColumnClassHints_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008967b0` |
| **VA** | `0x008967b0` |
| **Canonical name** | `UI_SkillPanel_UpdateSharedColumnClassHints_Inferred` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Adversarial / claim-breaking (Path B) |
| **Counterpart** | `reviews/A_aa_008967b0_UI_SkillPanel_UpdateSharedColumnClassHints_Inferred.md` |
| **System** | `skills-abilities` |
| **Agent** | R11-034 OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** — alternate ABI/role/merge claims falsified; residual product-English gaps only |

---

## 1. Attack surface

Claims tested against machine + live decompile (no runtime):

| # | Hostile claim | Result |
|---|---|---|
| B1 | ECX-thiscall at entry | **Falsified** — entry never loads this from ECX; ECX used for locale pool / later vfunc this; live-in is **EDI** |
| B2 | stdcall / `RET n` stack args | **Falsified** — plain `C3`; frame only `0x164` locals |
| B3 | cdecl with stack `panel*` | **Falsified** — caller `MOV EDI,EBP; CALL` with no push of panel |
| B4 | Unit is class-name leaf / merge with `0051f940` | **Falsified** — UI side effects on widgets; table + sprintf + vfunc; parent is **callee** only |
| B5 | Unit is skill-HB / combat OnEnd | **Falsified** — product string is column-share UI; no HB/list teardown |
| B6 | Unit is inventory / trade dialog | **Falsified** — skills-column English; parent partition skills-abilities; nearby XML `i_d_s_2d_wnd_*` |
| B7 | sprintf only 2 format args (trust decompiler) | **Falsified** — `ADD ESP,0x14` = 5 dwords; format `"%s %s %s."`; third is ring(`"class"`) |
| B8 | `FUN_0051f940` takes 4 stack args here | **Falsified** — only 2 cleaned (`ADD ESP,8`); trailing decompiler args are stack leftovers for ring path |
| B9 | Both columns always written | **Falsified** — independent null checks on `+0x744` / `+0x748` |
| B10 | Table is race-major only / unrelated constants | **Falsified** — index `class + race*4`; values are classIds 0..3 matching parent switch |
| B11 | String-plate name `Skill_This_column_of_skills_is_shared_by_the` is product PDB | **Falsified as product** — auto string-plate only; role name keeps `_Inferred` |
| B12 | Runtime Confirmed without Launcher | **Rejected** — Terminal false |

---

## 2. What survives

| Sealed | Why attacks failed |
|---|---|
| EDI-this panel helper | Caller site + unaff_EDI + plain RET |
| Shared-column hint semantics | Immutable product English |
| 12-pair class share table | Explicit stack stores |
| Dual column widgets | Distinct offsets + twin blocks |
| Parent lookup leaf | Dualed `0051f940` + matching (class,race) loads |

---

## 3. Residual risks (not claim-breakers)

1. **Name** is role-Inferred, not PDB-backed.
2. **`vtbl+0x308`** could be tooltip vs label vs status text — UI effect sealed, English open.
3. **Caller host** not recovered as a Ghidra function — single call site still sealed.
4. **Mode `+0x51c == 1`** English (which tab/view) open.
5. No runtime matrix of all class×race → displayed pair.

None overturn CF/ABI/table/string seal.

---

## 4. Verdict

**accept-with-gaps** — adversarial path does **not** force reject or rename-to-unknown. Safe to port as:

> panel EDI-this helper that, when mode==1 and session live, sets two shared skill-column widget strings to  
> `"This column of skills is shared by the <LookupClassDisplayName(share, race)> class."`

Do **not** merge into `LookupClassDisplayName`. Do **not** treat as inventory/combat HB.
