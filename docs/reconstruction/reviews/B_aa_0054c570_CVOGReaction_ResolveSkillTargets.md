# Review B (skeptical / adversarial): `aa_0054c570` CVOGReaction_ResolveSkillTargets

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054c570` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0054c570_CVOGReaction_ResolveSkillTargets.md` |
| **Verdict** | **accept-with-gaps** on CF/ABI; **reject** target-list + DI-rank + “cached” plate stories |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Resolves skill *targets* (TFIDs) | **Falsified** — no TFID walk; def-map clone + rank |
| 2 | Null = “already resolved / cached” | **Falsified** — `CMP` vs map **end sentinel** `DAT_00b04738`; EnsureLoaded logs *unable to find skill* |
| 3 | Rank carried in `DI` (`unaff_DI`) | **Falsified** — SetRank (`0x005535a0`) is thiscall + **one** stack arg (`RET 4`); EDI is REP MOVSD dest only |
| 4 | Second formal is skill ID | **Falsified as sole role** — callers push **rank** as arg1; skill ID is arg0 |
| 5 | Clean SEH ≡ retail ExceptionList | **Overstated** — simplified in clean (acceptable scaffold) |
| 6 | Ctor alone defines runtime contents | **Partial** — full `0x630` overwrite follows ctor; ctor useful only for new-fail / residual fields if copy incomplete (copy is full size) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Alloc/copy/rank CF | High | Broken skill materialize |
| Name-as-targets | **Falsified** | Wrong AutoCore API / double work with ResolveTargetList |
| Miss-vs-cache null | High (miss) | Double-alloc myths; wrong cache layer |
| Rank register DI | **Falsified** | Wrong rank applied in ports |
| Caller free policy | Probable (caller-specific) | Leaks if port assumes this unit frees |

---

## 3. Cross-check against true target resolvers

| Unit | VA | Role |
|---|---|---|
| **This** | `0x0054c570` | Materialize ranked skill **instance** from def map |
| `Skill_ResolveTargetList` | `0x00550300` | Build TFID list + outFlags |
| `Skill_GatherTargetsInArea` | `0x0058d330` | Area gather |
| `CVOGReaction_CastSkillOnTarget` | `0x004d09a0` | Cast packer consuming skill* + targets |

Outpost paths: materialize via this unit → `Skill_ValidateTargetForSkill` → `CastSkillOnTarget` → **delete** skill*.

---

## 4. Surviving contract for AutoCore

```
// MISNOMER index name kept; port semantics:
MaterializeSkillRuntime(skillId, rank) -> SkillRuntime* | null
  map at DAT_00b04734; miss sentinel DAT_00b04738
  new 0x630; ctor FUN_0054f3c0; copy node+0x10 (0x18c dwords)
  skill+0x5f6 = (short)rank; reevaluate
  caller owns pointer (insert tree OR delete after cast)
```

Do **not** implement as target TFID resolver. Do **not** pass phantom DI rank.

---

## 5. Open questions

1. True retail name / PDB symbol.
2. Product struct name for 0x630 object.
3. Whether any caller treats null as soft-success (none sampled; EnsureLoaded treats as error log).
4. Runtime / diff / bit-exact.

**Verdict:** CF accept; semantic name reject for “targets”; DI-rank and cached-null plate reject.
