# Review B (skeptical / adversarial): `aa_00536740` CVOGCharacter_CompleteRegionMissions

| Field | Value |
|---|---|
| **Stable ID** | `aa_00536740` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00536740_CVOGCharacter_CompleteRegionMissions.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This **is** `SearchAutoMissions` | **Falsified** — different VA `0x00532b60`; no AutoAssign `+0xF8`; no Requirements/GiveMission; takes region/pocket |
| 2 | Pure eligibility check (no mutation) | **Falsified** — calls `CheckMissionPrerequisites(...,1,1)` which awards/completes |
| 3 | Completed skip is inside prereq body | **Falsified** — walk of `char+0x538` is **in this unit** before the call (prereq dual already sealed this) |
| 4 | Pocket always required | **Falsified** — `cmp edi,-1` short-circuits `def+0x12c` compare; caller ORs EDI to `-1` before optional parse |
| 5 | Void / no stack args | **Falsified** — `ret 8`, always `AL=1` |
| 6 | Multiple production callers | **Falsified as of live xrefs** — sole `0x009544aa` (debug chat); production auto path is SearchAutoMissions |
| 7 | Builds list only for convenience | **Not falsified** — unlock-before-cascade is the structural reason (Probable re-entrancy); not proven beyond structure |
| 8 | `def+0x90` is continent | **Unresolved** — shared with ReqRace surface in prereq dual; compared to `game+0x532` byte. English open |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Region/pocket filter CF | **High** | Wrong bulk complete scope |
| Prereq `(1,1)` cascade | **High** | Miss award side effects |
| Debug-only caller | **High** | Invent production wiring |
| Product name string | **Probable** | Rename later if PDB surfaces |
| game+0x531/532 identity | **Tentative** | Wrong server mirror of race/class gate |

---

## 3. Surviving contract

```
// thiscall character; ret 8; always 1
snapshot mission-def hash (lock +0x1d)
for each def:
  if def.region(+0x128)!=region: continue
  if pocket!=-1 && def.pocket(+0x12c)!=pocket: continue
  if race/class gates fail vs game blob: continue
  if completed(+0x538) live: continue
  CheckMissionPrerequisites(this, id, auto=1, checkLevel=1)
return 1
```

**Verdict:** **accept-with-gaps**
