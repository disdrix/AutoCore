# Review B (skeptical / adversarial): `aa_005304a0` CVOGCharacter_UpsertSkillRankAndReapply_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005304a0` |
| **VA** | `0x005304a0` |
| **Canonical name** | `CVOGCharacter_UpsertSkillRankAndReapply_Inferred` / `FUN_005304a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W16-R) |
| **Counterpart** | `reviews/A_aa_005304a0_CVOGCharacter_UpsertSkillRankAndReapply_Inferred.md` |
| **System** | skills-abilities / character |
| **Verdict** | **accept-with-gaps** on CF/ABI; **needs-more-evidence** on `param_4` + this-adjust product types |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Always inserts a new skill | Hit path updates existing; no push | **Falsified** as insert-only |
| 2 | Always reapplies even on materialize miss | Null from ResolveSkillTargets → early return | **Falsified** |
| 3 | `unaff_DI` is a real third SetRank formal | Bytes: single `PUSH rank`; callee `RET 4` | **Falsified** (decomp phantom) |
| 4 | `FUN_0053aea0(&triple)` this = character | Bytes: `LEA ECX,[EDI+0x54c]` | **Falsified** as char-primary this |
| 5 | Free function / no character this | `MOV EDI,ECX`; bag on EDI; `RET 0xC` | **Falsified** |
| 6 | This **is** the medal award itself | Medal dual only **chains** here after notify/dirty | **Falsified** ownership |
| 7 | Reapply uses unadjusted character ECX | this-adjust lea before both ApplyLocal calls | **Falsified** as raw char |
| 8 | `+0x5fc` is rank field | Rank is `+0x5f6` (SetRank dual); `+0x5fc` compared to skillId | **Falsified** |
| 9 | clean invents branches | Scaffold CF matches raw; only ABI notes fixed | **Survives** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Hit/miss + reapply CF | **High** | Wrong skill grant port |
| ABI RET 0xC / 3 args | **High** | Stack corruption |
| Materialize null = no-op | **High** | Spurious reapply |
| skill+0x5fc is id key | **High** CF / Probable name | Wrong match field |
| `param_4` semantics | **Tentative** | Dropping meta may desync bag |
| this-adjust meaning | **Tentative** | Wrong host for ApplyLocal |
| Product symbol | **Open** | Cosmetic |
| Thread-safe bag | **Open / weak** | double insert |

---

## 3. Cross-check against raw / live / related duals

```
live decompile ≡ raw CF skeleton
bytes seal: RET 0xC; vector @+0x54c; stride 0xC; key +0x5fc; flag=1 insert
SetRank: no DI arg (matches ResolveSkillTargets dual anti-phantom)
Medal 00530550: PUSH 0; PUSH [def+0x18]; PUSH [def+0x14]; MOV ECX,char; CALL 5304a0
00514e70 dual lists FUN_005304a0 as "after bag insert/set-rank; re-apply skill id"
```

### Merge traps

- Do **not** treat as `AwardMedalById` body.
- Do **not** skip ApplyLocal on hit (rank change needs refresh).
- Do **not** call ResolveSkillTargets on hit (would leak a second 0x630).
- Do **not** pass `unaff_DI` into SetRank ports.

---

## 4. Surviving contract for AutoCore

```
// Character skill bag upsert
UpsertSkillRankAndReapply(char, skillId, rank, meta=0):
  find entry by skill->key5fc == skillId
  if found:
    SetRank(entry.skill, rank)
    entry.meta = meta
  else:
    skill = Materialize(skillId, rank)   // may null
    if !skill: return
    bag.push({skill, meta, 1})
  ApplyLocalById(skill_host_base(char), skillId)

AutoCore must NOT:
  - implement as insert-only or set-only
  - reapply when materialize fails
  - invent SetRank(DI) third parameter
  - use character primary this for ApplyLocal without the observed adjust
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Hit/miss upsert + reapply | **Agree Confirmed** |
| unaff_DI phantom | **Agree Confirmed** |
| vector @ +0x54c | **Agree Confirmed** |
| accept-with-gaps | **Agree** |
| param_4 / this-adjust English | **Agree Open/Tentative** |

---

## 6. Open questions

1. What is `param_4` when non-zero (any live packet path)?
2. Document complete object / MI layout for this-adjust.
3. Bag dtor / skill free policy.
4. Create-from-packet call-site arg map (skill id list offsets).
5. Runtime grant capture (medal → skill appears in bag).

**What would overturn**

1. Proof `+0x5fc` is not skill id (e.g. def pointer with different compare).
2. Call site with non-character ECX.
3. Image change at VA.

**Verdict:** **accept-with-gaps** — agree with A; block insert-only / phantom-DI / medal-merge mistakes.
