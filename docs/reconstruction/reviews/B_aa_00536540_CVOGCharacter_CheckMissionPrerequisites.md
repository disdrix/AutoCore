# Review B (skeptical / adversarial): `aa_00536540` CVOGCharacter_CheckMissionPrerequisites

| Field | Value |
|---|---|
| **Stable ID** | `aa_00536540` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual residual edges strengthen) |
| **Counterpart** | `reviews/A_aa_00536540_CVOGCharacter_CheckMissionPrerequisites.md` |
| **System** | `missions-progression` |
| **Dual status** | **Present — residual edges sealed 2026-07-29** |
| **Verdict** | **accept-with-gaps** on CF + mutator contract + call-arg edges; **reject pure-predicate / Requirements-equivalent / sole-caller stories** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function only *checks* prerequisites | **Falsified** — GiveMission, AddExperience, CompleteMissionObjectives |
| 2 | Equivalent to CheckMissionRequirements | **Falsified** — character thiscall vs mission-def thiscall; different gates; mutates |
| 3 | Race/faction always enforced | **Overstated** — only when `checkLevel != 0`; sites 3–4 pass `0` |
| 4 | Race supports `0xFFFF` unrestricted like Requirements | **Falsified for this unit** — race compare is strict equality when checked |
| 5 | Prereqs always walked | **Overstated** — only when `def+0x124 == 0` (`RequirementsNegative`) |
| 6 | Recursive call validates then returns | **Overstated** — discards recursive return; side-effect only |
| 7 | Body reads completed hash `+0x538` (missionState.md) | **Falsified** — body walks **active** `+0x540`; completed is **caller** `FUN_00536740` |
| 8 | Level gap XP is server-safe client authority | **Attacked** — local XP award before grant; server authority unknown |
| 9 | Active mission always blocks award | **Partial** — inactive/null payload falls through to award (`goto LAB`) |
| 10 | Clean invents thiscall `this` on GiveMission | **Survives as correction** — sibling GiveMission is character thiscall; raw Ghidra drop |
| 11 | Suitable as SearchAutoMissions eligibility | **Falsified** — SearchAutoMissions uses Requirements then GiveMission |
| 12 | Max level / currency / flag applied here | **Falsified** — not in body |
| 13 | Sole external caller is `FUN_00536740` | **Falsified** — xrefs also `0x00950915`, `0x00954575` |
| 14 | `autoComplete` always 1 in production | **Overstated** — debug force-add site uses `0` |
| 15 | `checkLevel` always 1 outside recursion | **Falsified** — client sites pass `0` |
| 16 | `+0x124` English unknown / invented | **Closed** — product `RequirementsNegative` (WAD + Requirements dual) |
| 17 | Prep `+0x88`/`+0xfc` unknown | **Closed names** — **NPC** / **AutoAssign** via `Mission.Read` layout |

---

## 2. Decisive dataflow (raw + asm)

```
this (ECX) = character
  +0x540  active mission hash  (bucket walk first)
  entity chain → +0x532 race u8, +0x531 faction u8
  entity vtbl+0x27c → level (s32)

missionDef (lookup)
  +0x90  race u16     (strict == when checkLevel)
  +0x92  faction u16  (0xFFFF skip)
  +0x94  min level i32
  +0x9c  prereq[4] u32 (0xFFFFFFFF empty)
  +0x88  NPC (prep)
  +0xfc  AutoAssign (prep, i16 in WAD)
  +0x124 RequirementsNegative — if ==0 → recursive award prereqs

Side effects (award path):
  recurse(prereq, auto=1) × up to 4
  maybe AddExperience(XpToReach(min-level))
  FUN_0052c700(prep)   // 12 dwords → char map ~+0x50c
  GiveMission(id)
  maybe CompleteMissionObjectives(id, 1)
```

### Call-arg attack surface (asm-sealed)

| Site | auto | check | Survives as |
|---|---|---|---|
| self `0x00536631` | 1 | parent | force-complete children, inherit race gate |
| `FUN_00536740` `0x005368ef` | 1 | 1 | full auto-award cascade |
| client `0x00950915` | 1 | **0** | force-complete prereqs **without** race/faction re-gate |
| debug `0x00954575` | **0** | **0** | award only; no bulk complete; no race/faction |

Contrast Requirements (`0x005462b0`):

```
this (ECX) = mission def
stack0 = character
return -1 | 0 | blockingPrereqId
NO GiveMission / NO XP / NO complete
```

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Character `this` + missionId args | **High** | Wrong object mutated |
| Hash `+0x540` active lookup | **High** | Double-grant / miss active |
| Live payload `node+8` gate | **High** | Wrong already-active semantics |
| Side-effect grant path | **High** | Silent no-op in port |
| Pure-check semantics for AutoCore API | **Low** | Server/client design mismatch |
| Race strict when `checkLevel` | **High** | Wrong race-any missions |
| Recursive prereq force-complete | **High** CF | Cascading auto-complete surprises |
| Recursive failure aborts parent award | **Falsified** | Parent still awards |
| `+0x124` = RequirementsNegative | **High** | Wrong multi-prereq design language |
| Prep NPC / AutoAssign field names | **High** | Wrong prep content labels |
| `FUN_0052c700` map-store shape | **High** | Missing pending structure |
| `FUN_0052c700` product English | **Tentative** | Naming only |
| Call-site arg matrix (4 sites) | **High** | Wrong flag defaults in ports |
| Outer client-cmd full CF | **Tentative** | Ghidra undefined-fn gap |
| XP bridge exact formula | **Tentative** | Wrong level boost amount (callee unit) |
| Server mirror of XP+grant | **Open** | Client-only package |
| Clean CF ≡ raw | **High** | — |

---

## 4. Offset attack checklist (must stay body-backed)

| Offset | Attack | Result |
|--------|--------|--------|
| `char+0x540` active | Invented? | **No** — first walk |
| `char+0x538` completed | In body? | **No** — only in caller site 2 |
| `node+0x10` key | Invented? | **No** |
| `node+8` payload | Invented? | **No** |
| `def+0x90` race | Invented? | **No** |
| `def+0x92` faction | Invented? | **No** |
| `def+0x94` min level | Invented? | **No** |
| `def+0x98` max level | Present here? | **No** — Requirements only |
| `def+0x9c` prereqs | Invented? | **No** — 4-slot loop |
| `def+0x104/+0x108` currency | Present here? | **No** |
| `def+0x118` flag | Present here? | **No** |
| `def+0x124` | Invented? | **No** — `==0` award recurse gate; name **RequirementsNegative** |
| `def+0x88` / `+0xfc` | Invented? | **No** — prep copies; names NPC / AutoAssign |
| GiveMission / XP stores | Hidden? | **Explicit** in body |

---

## 5. Control flow: clean ≡ raw (skeptical)

| Stage | Clean invents? | Match |
|---|---|---|
| Active chain + early complete/0 | No | **Yes** |
| Award path label vs LAB | Rename only | **Yes** |
| checkLevel race/faction | No | **Yes** |
| Recurse ignore return | No | **Yes** |
| XP path triple GetLevel | No | **Yes** |
| Prep 12 dwords | Structured as `prep[12]` | **Yes** |
| Restored thiscall `this` | **Correction of Ghidra drop** | **Accept** |
| No max/currency/flag | None added | **Yes** |

---

## 6. Surviving contract for AutoCore

```
// Character thiscall — NOT mission-def thiscall
char CheckMissionPrerequisites(Character* ch /*ECX*/,
                               uint32_t missionId,
                               char autoComplete,
                               char checkLevel);
// → 0 | 1

if live_active(ch+0x540, missionId):
  if autoComplete: CompleteMissionObjectives(id, 1); return 1
  else return 0

lookup def; fail → 0
if checkLevel:
  require def.race == char.race          // NO 0xFFFF race skip
  require def.faction == 0xFFFF || match
if def.RequirementsNegative == 0:        // +0x124
  for each prereq id @ +0x9c (skip 0xFFFFFFFF):
    CheckMissionPrerequisites(ch, id, autoComplete=1, checkLevel)  // ignore return
if level < def.min:
  AddExperience(ch, XpToReach(min - level), PacketOrNonKill)
FUN_0052c700(ch, id, prepBlob)           // 12 dwords; NPC@+0x88, AutoAssign@+0xfc
GiveMission(ch, id)
if autoComplete: CompleteMissionObjectives(id, 1)
return 1

SIDE EFFECTS. NOT pure eligibility.
Do NOT use as SearchAutoMissions gate (use CheckMissionRequirements).
Do NOT bind ECX as mission def.

Known callers (args):
  FUN_00536740:           (1, 1) after completed-hash skip
  self recurse:           (1, parent checkLevel)
  client 0x00950915:      (1, 0) external prereq force
  debug  0x00954510 path: (0, 0) "Forced add mission"
```

---

## 7. Open residual (this unit only — not Requirements)

1. ~~Who calls with `checkLevel=0` vs `1` besides `FUN_00536740`?~~ **Sealed** — matrix §2 / dual A §4.
2. Why recursive returns ignored — intentional force-chain even on child fail? (**Still open** — CF yes; design intent unstated.)
3. Server parity of level-gap XP award.
4. ~~Relationship of `+0x124` award gate vs Requirements polarity~~ **Sealed** — same field `RequirementsNegative`; query vs award use differs.
5. ~~`FUN_0052c700` prep fields `+0x88`/`+0xfc`~~ **Names sealed**; product English of helper open.
6. Runtime capture of recursive auto-complete cascade.
7. Correct missionState.md docs that mis-attribute completed-hash to this body.
8. Full dual of undefined client functions hosting sites 3–4 (out of OWN).

**Out of scope residual (Requirements dual already owns):** currency helpers, flag helpers, max level, return codes `-1/0/id`, `+0x120` combine English / truth table.

---

## 8. Concrete checks performed

1. Fresh Ghidra decompile @ `0x00536540` vs 2026-07-23 raw — CF identical.
2. Traced every load base: character vs missionDef.
3. Confirmed completed `+0x538` absent from body; present in caller `FUN_00536740`.
4. Confirmed race has no `0xFFFF` skip (contrast Requirements).
5. Confirmed recursive return discarded; parent continues to GiveMission.
6. Compared clean ≡ raw stage table; verified no invented Requirements gates.
7. **Xrefs + assembly context on all 4 call sites** — sealed auto/check arg matrix.
8. Decompiled `FUN_00536740`, `FUN_0052c700`, `FUN_0053fff0`.
9. Cross-checked `+0x124` / prep offsets against `Mission.Read` + Requirements dual.
10. String `Forced add mission (%i)` @ `0x00a28af4` for site 4.
11. Did not re-open GiveMission / Requirements duals as primary work.

**Not done:** `disassemble_bytes`; Launcher; live XP/award matrix; create missing Ghidra functions for client cmd VAs.

---

## 9. Verdict

### **accept-with-gaps** (CF + mutator contract + call-arg edges)

**Reject** packaging this as:

- pure prerequisite check,
- Requirements equivalent,
- completed-hash reader,
- SearchAutoMissions eligibility API,
- single-caller auto-only helper.

**Accept** as character award bootstrap with documented side effects, sealed CF vs raw, sealed 4-site call matrix, and sealed `RequirementsNegative` / prep field names.

**Gaps:** helper product English, XP authority, runtime, outer client-cmd duals.
