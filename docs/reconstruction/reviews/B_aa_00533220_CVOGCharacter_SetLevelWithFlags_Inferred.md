# Review B (skeptical / adversarial): `aa_00533220` CVOGCharacter_SetLevelWithFlags_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00533220` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W19-J) |
| **Counterpart** | `reviews/A_aa_00533220_CVOGCharacter_SetLevelWithFlags_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only. No `disassemble_bytes`. No Launcher.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is `CVOGCharacter_LevelUp` | **Falsified** — absolute set; LevelUp is `0x00532d30` (+1, UI packet) |
| 2 | Always rebuilds all three pools | **Falsified** — only flag bits `0x1` / `0x4` / `0x40` |
| 3 | `+0x6ce` is attribute pool | **Falsified** — sealed AddSkillPoints uses `+0x6ce`; this unit adds row `+0x16` there |
| 4 | `+0x6cc` is skill pool | **Falsified** — AddAttributePoints / row `+0x14` |
| 5 | `+0x730` is quickbar only | **Falsified in this unit** — stores table `intExperience` thresholds (XP.md total XP) |
| 6 | cdecl / no stack cleanup | **Falsified** — `ret 8` |
| 7 | Multiple independent callers | **Falsified** — sole `FUN_0080bec0` |
| 8 | Leaf / no nested systems | **Falsified** — skills, vehicle, missions, equip, hash tables |
| 9 | Scaffold name `Named_VOG_DEBUG_STOP_*` is product name | **Falsified** — HashError string noise only |
| 10 | Decompiler third arg to Skill_SetRank is sealed product rank | **Not proven** — `unaff_EDI` residual |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI thiscall + ret 8 | **High** | Crash on hook |
| Flag masks → pools | **High** | Wrong CharacterLevel apply |
| Pool offsets skill/attrib/research | **High** | Silent economy desync |
| XP clamp `+0x730` | **High** | Level/XP UI mismatch |
| Name `SetLevelWithFlags` | **Inferred** | Cosmetic |
| Equip rebind completeness | **Medium** | Wrong port of gear on level apply |
| Runtime golden | **Open** | Edge-case level 0/1 / empty table |

---

## 3. Cross-check against raw + bytes

Must preserve:

```
if flags&1: race_seed(); skill=0
if flags&4: attrib=0
if flags&0x40: research=0; dirty research flags
nLevel = newLevel
for L in 2..newLevel: accumulate grants for set flags; maybe clamp XP
if flags&4: reevaluate skills; wipe +0x74c×100
Vehicle_RecalcCombatPools if vehicle
vtable+0x5c; copy +0x12e→+0x12c; +0x4f2=1
SearchAutoMissions if local
vehicle equip rebind block
buff/item list additives for set flags
ret 8
```

Clean **must not**:

- Treat as LevelUp (+1 only) or LevelDown
- Swap skill/attrib offsets against sealed Add* duals
- Drop flag gating
- Invent multi-caller surface

---

## 4. Surviving contract for AutoCore

```c
// Port shape — normal thiscall
void CVOGCharacter_SetLevelWithFlags(
    Character* self,
    int newLevel,
    unsigned flags /* bit0 skill, bit2 attrib, bit6 research */);
```

Server ports applying CharacterLevel snapshots should:

1. Set absolute level.
2. Rebuild only the pools indicated by flags (retail recomputes from table rows 2..N, not delta).
3. Keep total XP consistent with `tExperienceLevel.intExperience` band.
4. Trigger skill re-eval / vehicle pool refresh / equip validity as needed.

Do **not** require client HashError HB lock strings on server.

---

## 5. Open questions

1. Exact packet layout feeding `FUN_0080bec0` flags at `+0x8`.
2. Whether level `< 2` skips all table grants by design (loop starts at 2).
3. Product name / vtable slot ownership of this method.

**Verdict:** **accept-with-gaps**
