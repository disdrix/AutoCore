# Review B (skeptical / adversarial): `aa_0052b140` CVOGCharacter_MeetsDisciplineLearnRequirements_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052b140` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R13-036 OWN-ONLY dual B; dual start 2686) |
| **Counterpart** | `reviews/A_aa_0052b140_CVOGCharacter_MeetsDisciplineLearnRequirements_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Identity is skill-window description helper / `Named_CalleeOf_Skill_i_w_skill_2d_wnd_*` | Scaffold alias | **Falsified as unit identity** — leaf is character thiscall gate; window is one of five callers; learn-fail string is explicit Discipline requirements |
| 2 | Is SkillDefMap eligibility / skill prereq | “skill” UI xml names | **Falsified** — map `0x00b045b0` / end `DAT_00b045b4` / payload `0x1FC` is DisciplineDef (parent R12-020); SkillDefMap is `DAT_00b04734` / nil `+0x641` |
| 3 | Is only `DisciplineDefMap_TryCopyPayloadById` | Shares callees | **Falsified** — this is thiscall character gate with level + balance OR-chain; parent leaf is cdecl pure try-copy |
| 4 | Is `GetResourceBalanceByType` | Nested five times | **Falsified** — that is `RET 4` balance int; this returns bool eligibility after multi-step checks |
| 5 | cdecl / bare RET / two stack args | Decompiler noise | **Falsified** — `MOV EBX,ECX` this capture; dual exits `RET 4`; single stack formal `[EBP+8]` |
| 6 | stdcall without this / ECX unused | Multi-arg intuition | **Falsified** — ECX required; `MOV ECX,EBX` before every balance call |
| 7 | AND of all five prereqs | Typical “prereq list” | **Falsified** — each satisfied slot `JGE` → success; fail only after all slots miss and not all-`-1` |
| 8 | Always requires at least one prereq def | Optimistic | **Falsified** — all five ids `== -1` is explicit success path after level check |
| 9 | Mutates map / trains / spends resources | Side-effect fear | **Falsified** — read-only find + stack copies + queries; no insert/erase/write to character maps |
| 10 | Miss still evaluates prereqs | Buffer reuse | **Falsified** — early `JZ` miss before copy/level/prereq |
| 11 | Runtime Confirmed | Wave seal claim | **Fails (open)** — no Launcher; dual CF seal only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + RET 4 + bool AL | **High** | Wrong cleanup / wrong this in ports |
| Map/end + 0x1FC copy | **High** | Wrong table / underrun |
| OR prereq semantics | **High** | AND would reject alternate unlock paths |
| Min level short @ `+0x26` | **High** | Wrong gate |
| Discipline learn domain | **High** | Mis-port into skill train |
| Product English name | **Low–Med** | Doc only (`_Inferred`) |
| Balance unit English | **Med** | rank vs resource wording |
| Runtime | **Open** | Not claimed |

---

## 3. Cross-check against raw ≡ live

```text
// sealed CF (this = character, stack0 = disciplineId)
it = FUN_00538ab0(&g_map_00b045b0, &disciplineId)
if (*it == DAT_00b045b4) return false;          // AL=0
memcpy(stackDef, (*it)+0x10, 0x1FC);            // REP MOVSD x 0x7f
level = this->nested_vtbl[+0x27c]()
if (level < (int16)stackDef[+0x26]) return false;
for i in 0..4:
  id = *(int*)(stackDef + 0x08 + 4*i)
  thr = *(int16*)(stackDef + 0x1C + 2*i)
  if id != -1
     && DisciplineDefMap_TryCopyPayloadById(id, scratch)
     && GetResourceBalanceByType(this, id) >= thr:
       return true;                             // AL=1
if all five ids == -1: return true;
return false;                                   // AL=0
// RET 4; __thiscall
```

Sibling contrast (evidence only; not OWN dual):

* `DisciplineDefMap_TryCopyPayloadById_Inferred` (`0x0052b040`): cdecl try-copy; **parent** of this residual.
* `CVOGCharacter_GetResourceBalanceByType` (`0x0052ada0`): thiscall balance; nested query only.
* `FUN_0052d180`: train residual — maps this fail → code **4**.
* `FUN_00931cf0`: client learn path — fail chat string + pass opcode **0x2097**.
* SkillDefMap family: distinct globals — do not merge.

Bytes seal (`read_memory` entry + exits):

```text
55 8B EC 83 E4 F8 81 EC 0C 04 00 00 8B 45 08 53 56 8B D9 57 …
B9 B0 45 B0 00 … E8 … 3B 05 B4 45 B0 00 0F 84 …
8D 70 10 B9 7F 00 00 00 … F3 A5 … FF 92 7C 02 00 00 …
… E8 … 83 C4 08 84 C0 … 8B CB E8 …   ; try-copy cdecl + balance thiscall
…
8B E5 5D C2 04 00                 ; success RET 4
5F 5E 32 C0 5B 8B E5 5D C2 04 00 ; fail XOR AL,AL; RET 4
CC…                              ; pad
```

---

## 4. Surviving contract for AutoCore

```
CVOGCharacter_MeetsDisciplineLearnRequirements_Inferred(character, disciplineId) -> bool:
  def = try_copy DisciplineDef(disciplineId)   // map @ 0x00b045b0, 0x1FC
  if missing: return false
  if character.level_vfunc(+0x27c) < def.minLevel(+0x26): return false
  for each of 5 alternate prereq slots:
    if id != -1 and def_exists(id) and balance(character, id) >= thr: return true
  if all slots empty (-1): return true
  return false
```

**Port tests:**

* Unknown discipline id → false (no level/prereq eval).
* Known id, level below `+0x26` → false even if prereqs empty.
* Known id, level OK, all prereq ids `-1` → true.
* Known id, level OK, one alternate prereq met (balance ≥ thr, def exists) → true even if other slots fail.
* Known id, level OK, some prereqs set but none met → false.
* Do **not** AND the five slots.
* Do **not** route through SkillDefMap.
* ABI: thiscall character + one int; callee cleans 4; bool in AL/low byte.

**Verdict:** **accept-with-gaps** — adversarial skill-merge / AND-prereq / cdecl / always-require-prereq / scaffold-window-identity / Runtime Confirmed claims **falsified**. Product English + full schema + runtime remain open (terminal **false**).
