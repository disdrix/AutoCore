# Review B (skeptical / adversarial): `aa_0058c0a0` Skill_RangeCheckTargetForResolveList_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058c0a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual residual strengthen: return0→outFlags bit2) |
| **Counterpart** | `reviews/A_aa_0058c0a0_Skill_RangeCheckTargetForResolveList_Inferred.md` |
| **Verdict** | **accept** on role + bit2 zero-signal producer; **accept-with-gaps** on distance semantics |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Also writes outFlags bit 2 itself | **Falsified** — no outFlags formal; OR is at caller `005504d1` |
| 2 | Return is always true Euclidean distance | **Falsified** — auto-pass returns `g_flOne` without measuring; fail returns `g_flZero` |
| 3 | skill+0x28 is min and +0x2c is max | **Falsified by body** — band is `param_3(+0x2c) <= dist <= param_4(+0x28)` so **min at +0x2c, max at +0x28** |
| 4 | Multiple callers | **Falsified** — sole caller ResolveTargetList (xref `00550416` only) |
| 5 | Name is product-original | **Holds as false** — `_Inferred` required |
| 6 | This is the same as `Skill_LocalRangeTargetCheck` | **Falsified** — different VA (`0x00553130`), different callers (LocalCastValidate path), int eSkillResponses-style return |
| 7 | Bit2 OR could fire on non-zero return | **Falsified** — asm: `FLD g_flZero` + `FUCOMIP` + MSVC `TEST AH,0x44` / `JNP` equal-only path to `OR …, 0x2` |
| 8 | Another resolve-list helper also feeds bit2 | **Falsified for primary path** — only `|= 2` site in ResolveTargetList is after this CALL; Filter writes 4/8/0x10 only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Sole caller | **Confirmed** | Miss other range writers |
| Bit2 producer contract (return0) | **Confirmed** | Wrong cast fail UX (code 0x0D) |
| Asm OR site exclusive for bit2 in caller | **Confirmed** | Over-claim “only writer in binary” (other systems may OR bit2 elsewhere — **not** this chain) |
| Zero/non-zero gate only at caller | **High** | Overclaim “accuracy score” if dist unused |
| Auto-pass set completeness | **High CF** | Miss a fail path as pass |
| FUN_004e9aa0 = pure distance | Partial | LOS/pathing changes range behavior |
| Product C++ name | Unknown | Cosmetic only under `_Inferred` |

---

## 3. Surviving contract (dual residual sealed)

```
RangeCheckForResolve(pTarget, pSource, min(+0x2c), max(+0x28), skill+0x34, skill+0x5e7)
  -> float10
  0.0  => ResolveTargetList @ 005504d1: outFlags |= 2; goto no-primary
  else => range OK (value may be measured dist OR synthetic 1.0)
Does NOT set bits 1/4/8/0x10.
Does NOT write outFlags itself.
```

Constants (`read_memory`):

| Symbol | VA | Bytes | Value |
|--------|-----|-------|------:|
| `g_flZero` | `0x00a0f518` | `00 00 00 00` | 0.0f |
| `g_flOne` | `0x00a0f2a0` | `00 00 80 3f` | 1.0f |

---

## 4. Residual uncertainty

| # | Item | Blocks bit2 seal? |
|---|---|---|
| R1 | FUN_004e9aa0 full physics | **No** |
| R2 | skill field English | **No** |
| R3 | Original C++ name | **No** (`_Inferred`) |
| R4 | Whether measured dist is used elsewhere | **No** for ResolveTargetList |
| R5 | Other binary sites that OR bit2 outside resolve-list chain | **No** for this unit’s contract |

---

## 5. Concrete checks (executed 2026-07-29 residual)

1. Re-decompile `0x0058c0a0` — returns only `g_flOne` / measured / `g_flZero`. **Pass**
2. Callers list = only `Skill_ResolveTargetList`. **Pass**
3. ResolveTargetList decomp: `if (fVar7 == g_flZero) *outFlags |= 2`. **Pass**
4. Asm at `00550416`…`005504d1`: `CALL` → compare vs `[0x00a0f518]` → `OR [outFlags], 2`. **Pass**
5. Filter dual: does not set bit 2 (`aa_0054ff00`). **Pass** (cross-link)
6. CastSkillOnTarget maps bit2 → `0x0D` (prior chain notes). **High** (not re-owned)

---

## 6. Verdict

**accept** — range helper after filter sealed as the exclusive **primary-path producer of the zero signal** for outFlags bit **2**. Asm closes residual “decomp-only” doubt on the OR. Name remains `_Inferred`. Geometry of `FUN_004e9aa0` and skill field English are residual, not blockers.
