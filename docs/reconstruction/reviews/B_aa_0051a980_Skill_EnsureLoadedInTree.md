# Review B (skeptical / adversarial): `aa_0051a980` Skill_EnsureLoadedInTree

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051a980` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual strengthen) |
| **Counterpart** | `reviews/A_aa_0051a980_Skill_EnsureLoadedInTree.md` |
| **Verdict** | **accept-with-gaps** on CF/ABI; **reject** return-as-pointer, DI-rank, always-create, cast-validate |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Always creates a new skill | **Falsified** — `CNDHash_LookupByKey` first; hit path never materializes |
| 2 | Returns skill* / handle | **Falsified** — `void`; exits are `ret 8` with no defined EAX contract; callers re-lookup |
| 3 | Validates range / cast readiness | **Falsified** — load/rank ensure only; no LocalCastValidate |
| 4 | Hash key is cbid / template id | **Falsified for this unit** — key is the same `int skillId` arg; log string `"skill #%d"` |
| 5 | Rank carried in `unaff_DI` | **Falsified** — SetRank uses stack rank; DI is callee-saved noise |
| 6 | `_sRank` is a separate global | **Falsified** — decomp alias of stack rank / packing artifact |
| 7 | Equal rank re-runs reevaluate | **Falsified** — `CMP [skill+0x5f6], rank; JGE skip` (only **strictly less**) |
| 8 | Higher requested rank always wins; lower requested demotes | **Partial** — upgrades only when existing **<** requested; **never demotes** |
| 9 | Materialize null = “already cached” | **Falsified** (via materialize dual) — miss of def map; this unit logs *unable to find skill* |
| 10 | This unit frees failed materialize | **Falsified** — null only logs; no delete |
| 11 | `aa_004c8a60` *is* EnsureLoadedInTree | **Falsified** — bulk loader that **calls** this VA |
| 12 | Insert flag `0` means “replace existing” | **Falsified** — `FUN_0051e6d0` with flag≠0 would early-ok if present; flag 0 skips that; still fails on true duplicate |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Lookup-before-create CF | **High** | Dup tree entries / double materialize |
| Miss materialize + insert ownership | **High** | Leak or orphan skills |
| Void return | **High** | Port returns null and skips re-lookup → false “no skill” |
| Key = skill id | **High** | Wrong map key → silent miss every cast |
| Rank upgrade gate `<` only | **High** | Wrong reevaluate spam or accidental demote |
| Log helper role | **High** (intent); emit with flag 0 **Tentative** | Silent failure vs noisy |
| Host type of `+0x70` | **Probable** (skill-bearing object) | Wrong owner field in port |

---

## 3. Cross-check against related units

| Unit | VA | Relation |
|---|---|---|
| **This** | `0x0051a980` | Ensure ranked skill in owner tree hash |
| `CVOGReaction_ResolveSkillTargets` | `0x0054c570` | Materialize 0x630 from def map (misnomer) |
| `FUN_0051e6d0` | `0x0051e6d0` | CNDHash insert (key, value*, flag) |
| `Skill_SetRankAndReevaluate` | `0x005535a0` | `skill+0x5f6 = rank`; reevaluate |
| `Skill_ApplyStatusEffectLocal` | `0x0051aa00` | ensure then vfunc re-get; rank may reapply after |
| `FUN_00521650` (summon HB) | `0x00521650` | ensure if vfunc miss, rank arg `1` |
| `FUN_004c8a60` | `0x004c8a60` | bulk walk; **calls** EnsureLoadedInTree |
| `Skill_LocalCastValidate` | `0x0051a790` | **not** this unit |

Sample caller ranks:

| Caller | skillId source | rank |
|---|---|---|
| ApplyStatusEffectLocal | `packet+8` | **0** (then may SetRank from `packet+0xc`) |
| Summon HB `0x00521650` | active cast skill id | **1** |
| `FUN_0051b550` | clonebase +0x3bc/+0x3c0/+0x3c4 | vfunc-derived bytes |
| `FUN_0058be30` NPC spawn | skill slots +0x150…+0x15c | rank from +0xdc (min 1) |
| `FUN_004c8a60` bulk | loadout entry +0 / +8 | short at entry+8 |

---

## 4. Surviving contract for AutoCore

```
// Port semantics (Ghidra name kept as index):
void EnsureSkillLoadedInTree(Owner owner, int skillId, short rank)
  if skillId <= 0: return
  tree = owner.skillHash   // offset +0x70
  s = tree.Lookup(skillId)
  if s == null:
    s = MaterializeSkillRuntime(skillId, rank)   // aa_0054c570
    if s: tree.Insert(skillId, s)                // FUN_0051e6d0, flag 0
    else: log AddSkillToTree miss
  else if s.rank (+0x5f6) < rank:
    SetRankAndReevaluate(s, rank)
// does not return s — caller must Lookup / GetSkillById again
```

Do **not**:

- treat as cast validation
- assume return pointer
- demote rank on lower request
- confuse with `aa_004c8a60` bulk alias
- free the inserted skill (tree owns)

---

## 5. Open questions

1. Full product name for insert helper `FUN_0051e6d0`.
2. Struct documenting owner `+0x70` skill hash across creature/character.
3. Whether retail ever enables log channel for flag-0 `FUN_007a4480` calls.
4. Runtime capture / bit-exact.

**Verdict:** CF + key + rank gate + void return **sealed**. Scaffold claims of “returns pointer/handle” and DI-rank **rejected**. **accept-with-gaps** only for residual names/layout.
