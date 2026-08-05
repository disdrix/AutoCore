# Review B (skeptical / adversarial): `aa_005462b0` CVOGCharacter_CheckMissionRequirements

| Field | Value |
|---|---|
| **Stable ID** | `aa_005462b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005462b0_CVOGCharacter_CheckMissionRequirements.md` |
| **System** | `missions-progression` |
| **Dual status** | **Present — residual refresh 2026-07-29** |
| **Verdict** | **accept-with-gaps** on CF + corrected binding + sealed modes; **reject raw C parameter names** |
| **Scratch** | `reviews/a_005462b0.md` |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Raw names: `this`=character, `pMissionDef`=mission def | **Falsified** — mission fields on ECX; character uses stack0 |
| 2 | Symbol prefix `CVOGCharacter_` ⇒ character thiscall | **Misleading** — body is mission-def thiscall + character arg |
| 3 | Three stack formals / `unaff_ESI` required | **Falsified** — `RET 4`; all call sites one push (**sealed 2026-07-29**) |
| 4 | Clean invents prereq-mode English | **Superseded** — `RequirementsOred` / `RequirementsNegative` from `Mission.Read` + WAD layout |
| 5 | Function grants or mutates mission state | **Falsified** — pure query; returns codes only |
| 6 | Mode `+0x124!=0` is retail “exclusive OR” only | **Partial** — boolean matrix exact; name is **Negative**, not XOR |
| 7 | Plate “currency” at `+0x104/+0x108` is WAD field name | **Attacked** — product fields are **Discipline** / **DisciplineValue**; helper is shared balance map |
| 8 | `FUN_0052ada0` / `FUN_005405e0` fully named | **Open symbols**; **roles sealed** from image |
| 9 | Portable for AutoCore without Negative | **Attacked** — server `MeetsMissionPrerequisites` omits Negative |
| 10 | Prior legacy skeptical “needs-revision” still applies to **clean** | **Superseded for clean** — rebind + residual seals; still reject raw param names |

---

## 2. Decisive dataflow (raw + residual)

```
this +0x90  ReqRace u16          (0xFFFF skip)
this +0x92  ReqClass u16         (0xFFFF skip; plate “faction”)
this +0x94  ReqLevelMin i32
this +0x98  ReqLevelMax i32     (0 = no max)
this +0x9c  ReqMissionId[4]     (0xFFFFFFFF empty)
this +0x104 Discipline type     (skip < 0)
this +0x108 DisciplineValue thr
this +0x118 RequirementEventId  (-1 skip)
this +0x120 RequirementsOred
this +0x124 RequirementsNegative

stack0 character → race/class bytes (+0x532 / +0x531)
                 → HasCompletedMission(this=stack0, id)
                 → FUN_0052ada0(this=stack0, type)  // map char+0x584
(no stack1)
```

Offsets are **body-backed**. Product names from WAD/`Mission.cs` sequential layout (Id@0 → race@`+0x90`).

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Mission field offsets on ECX | **High** | Wrong eligibility entirely |
| Character via stack0 | **High** | `HasCompletedMission` / balance on wrong object |
| ABI = 2-arg thiscall only | **High** | Signature mismatch |
| Return codes `-1` / `0` / prereq id | **High** | Auto-award always/never |
| Race/class/level cascade order | **High** | Early-exit parity |
| Discipline field offsets | **High** | Silent fail/pass on wrong fields |
| `FUN_0052ada0` balance role | **High** | Wrong resource table |
| `FUN_005405e0` event membership | **High** | Wrong event gate |
| Prereq mode **names** Ored/Negative | **High** | — sealed residual |
| Prereq mode **boolean CF** | **High** | — |
| No side effects | **High** | Over-port as mutator would be wrong |
| Server Negative parity | **Open** | Offer false positives if Negative used in retail data |
| FUN product symbols | **Open** | Cosmetic only if roles ported |

---

## 4. Offset attack checklist (must stay body-backed)

| Offset | Attack | Result |
|--------|--------|--------|
| `+0x90` race | Invented? | **No** — raw compare |
| `+0x92` class | Invented? | **No** — raw; product ReqClass |
| `+0x94` / `+0x98` level | Invented? | **No** — min + guarded max |
| `+0x104` / `+0x108` | “currency” invent? | **Body loads yes**; name = **Discipline/Value** not cash enum |
| `+0x118` event | Invented? | **No** — helper arg; = RequirementEventId |
| `+0x9c` prereqs | Invented? | **No** — 4-slot loop |
| `+0x120` / `+0x124` | Invented? | **No** — evaluate block; names Ored/Negative |
| Side-effect stores | Hidden? | **None found** in body |
| Third formal | Real ABI? | **No** — RET 4 |

---

## 5. Prereq matrix (raw CF + sealed names)

Accumulators after loop over 4 slots:

- `allPass` — AND of completion results for nonempty slots (starts 1)
- `anyPass` — OR of completion results
- `firstFailId` — first failing mission id, else `0xFFFFFFFF`

| `RequirementsNegative` | `RequirementsOred` | Condition (from raw) | Return |
|------------------------|--------------------|----------------------|--------|
| `0` | `0` | `!allPass` | `firstFailId` |
| `0` | ≠0 | `!anyPass` | `firstFailId` |
| ≠0 | `0` | `allPass` | `-1` |
| ≠0 | ≠0 | `anyPass` | `-1` |

**Attack on “all prereqs required” story:** Incomplete without Ored/Negative.  
**Attack on “exclusive OR” story for Negative:** Over-label — polarity is invert-require, not XOR.

---

## 6. Surviving contract for AutoCore

```
// Correct binding (do NOT use raw C names; do NOT invent stack1)
int CheckMissionRequirements(MissionDef* mission /*ECX*/,
                             Character* character /*stack0*/);
// → -1 | 0 | blockingPrereqId
// thiscall, RET 4

Gates (fail → -1):
  ReqRace, ReqClass, ReqLevelMin/Max,
  Discipline balance (FUN_0052ada0), RequirementEventId membership (FUN_005405e0)

Prereqs: up to 4 ids @ mission+0x9c via HasCompletedMission(character, id)
Combine: RequirementsOred (+0x120) / RequirementsNegative (+0x124)  // CF exact
Success → 0

NO side effects. NO GiveMission. NO balance write. NO event write.
Do NOT bind ECX as character.
Server: port Negative before claiming full client parity.
```

---

## 7. Open questions

1. PDB/product names for `FUN_0052ada0` / `FUN_005405e0`.
2. Whether discipline type ids share one global resource map with cash currencies.
3. Typed character race/class chain (entity vs create-packet blob).
4. Retail missions that set `RequirementsNegative != 0` (frequency / design intent).
5. Runtime capture of multi-prereq + inverted mode cases.
6. GetLevel string evidence for vtbl `+0x27c`.

---

## 8. Concrete checks performed

1. Traced every load base: `this` vs stack0 (no stack1 loads).
2. Matched `HasCompletedMission` / `FUN_0052ada0` this to stack0.
3. **Image bytes** `FUN_0052ada0` (`0x0052ada0`): map @ `+0x584`/`+0x588`, value `+0x10`, `RET 4`.
4. **Image bytes** `FUN_005405e0`: scan `[DAT_00b04718, DAT_00b0471c)`.
5. Call-site context: one-push ABI at SearchAutoMissions / EvalOfferable / `FUN_004d2e50` / `FUN_004d5c10`.
6. Requirements epilogue `RET 4`.
7. WAD layout math: Id@0 → Discipline@`+0x104`, Event@`+0x118`, Ored@`+0x120`, Negative@`+0x124`.
8. Compared plate offset list to raw body — all listed offsets present; mode English no longer Probable-only.
9. Verified clean ≡ raw CF; clean must drop phantom third arg.
10. Confirmed absence of GiveMission / store side effects in body.

**Not done:** `disassemble_bytes`; Launcher; live prereq matrix.

---

## 9. Verdict

### **accept-with-gaps** (CF + corrected binding + residual seals)

| Layer | Verdict |
|-------|---------|
| Clean control flow vs raw | **Accept** |
| Mission-def offsets | **Accept** (body-backed) |
| Product mode/field names | **Accept** (WAD-backed) |
| ABI 2-arg thiscall | **Accept** (asm-backed) |
| Clean parameter rebind | **Accept** |
| Raw decompiler parameter names | **Reject** (do not port) |
| FUN product symbols | **Gaps** (roles sealed) |
| Side-effect inventing | **Rejected** — none in body |
| Server Negative port | **Gap** |

**Final:** Accept clean CF, sealed Ored/Negative/Discipline/Event field names, and 2-arg ABI for
AutoCore **read-only eligibility** ports; never trust raw parameter names; implement Negative before
claiming full prereq parity; leave FUN_* symbols until string/RTTI.
