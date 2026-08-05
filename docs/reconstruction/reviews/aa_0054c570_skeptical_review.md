# Skeptical / adversarial review: `CVOGReaction_ResolveSkillTargets` @ `0x0054c570`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054c570` |
| **Review type** | Skeptical / adversarial |
| **Date** | 2026-07-23 |
| **Scope** | Named “resolve targets” unit vs actual body behavior |
| **Verdict** | **needs-more-evidence** |

---

## 1. What was inspected

| Path | Role |
|------|------|
| `raw/aa_0054c570_CVOGReaction_ResolveSkillTargets.md` | Body + plate algorithm |
| `raw/aa_0054c570_CVOGReaction_ResolveSkillTargets.annotated.md` | Scaffold |
| `reconstructed-exact/CVOGReaction_ResolveSkillTargets.cpp` | Clean |
| `functions/aa_0054c570_CVOGReaction_ResolveSkillTargets.md` | Record |
| `systems/skills-abilities.md` | Role listing |
| `docs/topic-extractions/skill-cast.md` | `Skill_SetRankAndReevaluate` / `Skill_ResolveTargetList` names |
| Sibling | `CVOGReaction_CastSkillOnTarget` uses `Skill_ResolveTargetList` — different function |

**Not performed:** re-decompile, callers, map structure at `DAT_00b04738`.

---

## 2. Evidence used

### What the body actually does

1. Ensure skill data subsystem init flag.
2. Lookup something keyed by `pSkillData` in a structure (`FUN_00418890`).
3. If result is end/sentinel `DAT_00b04738`, return **null**.
4. Else allocate **0x630** bytes, initialize via `FUN_0054f3c0`, **memcpy-equivalent** of `0x18c` dwords from `result+0x10`.
5. Call **`Skill_SetRankAndReevaluate(buffer, uSkillID, unaff_DI)`**.
6. Return buffer pointer.

### What target resolution looks like elsewhere

`CVOGReaction_CastSkillOnTarget` calls `Skill_ResolveTargetList` (`0x00550300` per topic map) into a TFID array — **completely different** from this unit.

---

## 3. Attack results

### Claim 1 — Function resolves skill effect targets

| Sub-claim | Attack result |
|-----------|----------------|
| Canonical name | **FALSIFIED as description of body** |
| Plate “resolved target buffer (0x630)” | **FALSIFIED.** 0x630 matches skill runtime/template footprint copy (`0x18c*4`), not a TFID list (TFID slots are 0x10/0x18 class objects elsewhere) |
| System map “Resolve targets” | **Overclaim / wrong role** |

**What body is:** skill definition/runtime **materialize + rank reevaluate**, or clone-from-table.

---

### Claim 2 — Null means “already resolved / cached”

| Sub-claim | Attack result |
|-----------|----------------|
| Plate “already cached” | **Speculation.** Equality to `DAT_00b04738` is classic **map end iterator** / miss |
| Alternate: not found → null | **Fits equally** |
| Alternate: found end → null, found node → clone | **Fits** |

Cannot seal “cache hit returns null” vs “lookup miss returns null” without map API knowledge. Plate picked a story.

---

### Claim 3 — Parameters are (skill data buffer, skill id)

| Sub-claim | Attack result |
|-----------|----------------|
| Two formals used as lookup key + rank reevaluate arg | **Holds at call shape** |
| Types `void*` meaningful | **Tentative** |
| `unaff_DI` is rank | **Unproven** — not a formal; decompiler register leak into `Skill_SetRankAndReevaluate` |

---

### Claim 4 — Part of reaction cast target pipeline

| Sub-claim | Attack result |
|-----------|----------------|
| CVOGReaction_ prefix | Suggests reaction system ownership only |
| Feeds CastSkillOnTarget target list | **Not shown** — CastSkillOnTarget uses `Skill_ResolveTargetList` |
| Importance | May still be skill factory used before cast; **not target resolution** |

---

### Claim 5 — Clean/port can implement “target resolve” from this unit

| Sub-claim | Attack result |
|-----------|----------------|
| Implementing target TFID gather from this CF | **Would be wrong product** |
| Implementing skill instance clone+rank | **Closer to body** |

---

## 4. Alternate interpretations

| Story | Fits? |
|-------|-------|
| `Skill_CloneRuntimeFromTableAndSetRank` | **Best fit** |
| Target buffer allocator | Poor (no TFID writes) |
| Cache: null if present | Speculative |
| Miss: null if absent | Speculative |

Recommended temporary mental rename: **`Skill_MaterializeRuntimeFromLookup`** (INFERRED) until callers seal.

---

## 5. What was confirmed despite skepticism

1. Init flag + lookup + conditional alloc/copy + SetRankAndReevaluate + return pointer/null.
2. Size math `0x18c` dwords = `0x630` bytes.
3. Clean CF matches raw.
4. Body does **not** walk entities, TFID lists, or range checks.
5. Distinct from `Skill_ResolveTargetList`.

---

## 6. Critical contradictions found

### C1 — Name/plate/system-map vs body

Strongest contradiction in this review batch: **“ResolveSkillTargets” does not resolve targets.**

### C2 — Confusion with `Skill_ResolveTargetList`

Topic map has a real target-list function at `0x00550300`. This unit is not that function. Risk of agent/port mix-up is high.

### C3 — “Already cached” narrative

Unfalsified only because map semantics are unknown — equally compatible with miss.

---

## 7. Residual uncertainty

| # | Item | Blocks sealing? |
|---|------|-----------------|
| R1 | Real purpose / callers | **Yes** |
| R2 | Map hit vs miss meaning of null | Yes |
| R3 | Buffer layout after copy | Yes (skill field map) |
| R4 | Rank register | Yes |
| R5 | Whether reaction cast needs this at all | Yes |

---

## 8. Concrete checks performed

1. Confirmed zero TFID / Object_Resolve / range calls in body.
2. Verified `0x18c*4=0x630`.
3. Compared to CastSkillOnTarget’s actual target resolve callee.
4. Checked system map wording vs body.
5. Clean vs raw CF parity.
6. Noted plate algorithm steps 1–4 match structure but mislabel output as “targets.”

---

## 9. Verdict

### **`needs-more-evidence`**

CF is simple and solid; **the interpretation package is misnamed**. Accepting the name as semantics would poison ports and system docs.

### Port guidance

- Do **not** implement entity/target gathering here.
- Demote name in mental model until rename pass with callers.
- Wire real target resolution to `Skill_ResolveTargetList` / CastSkillOnTarget path instead.

### Acceptance bar later

1. Caller xrefs for `0x0054c570`.
2. Type of map at lookup + sentinel.
3. Compare output buffer fields to known skill runtime offsets (`+0x5fc`, etc.).
4. Rename if confirmed.

---

## 10. Summary table

| # | Claim | Result |
|---|-------|--------|
| 1 | Resolves targets | **Falsified** |
| 2 | Null = already cached | **Unproven** |
| 3 | Param types sealed | **Weak** |
| 4 | Reaction target pipeline | **Not shown** |
| 5 | Port as target resolve | **Wrong** |

**Final verdict: `needs-more-evidence`**
