# Skeptical / adversarial review: `Mission_ComputeObjectiveXp` @ `0x0059dde0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059dde0` |
| **Review type** | Skeptical / adversarial (try to falsify current interpretation) |
| **Date** | 2026-07-23 |
| **Scope** | Mission XP calculator unit and claims in plate / docs/XP.md / CompleteObjective packaging |
| **Verdict** | **needs-more-evidence** |

**Generic approval is insufficient.** Claims that survive are those that survived attack, not restatement of the plate comment.

---

## 1. Inspected artifacts

### Primary unit artifacts

| Path | Role |
|------|------|
| `docs/reconstruction/raw/aa_0059dde0_Mission_ComputeObjectiveXp.md` | Immutable decompile |
| `docs/reconstruction/raw/aa_0059dde0_Mission_ComputeObjectiveXp.annotated.md` | Notes |
| `docs/reconstruction/reconstructed-exact/Mission_ComputeObjectiveXp.cpp` | Human-refined clean |
| `docs/reconstruction/functions/aa_0059dde0_Mission_ComputeObjectiveXp.md` | Status: Human-refined |
| `docs/XP.md` | Mission XP formula under attack |

### Cross-check / attack surfaces

| Path | Why |
|------|-----|
| `raw/aa_00533f90_*` CompleteObjective | Caller bias + final-only call site |
| `Experience_GetCumulativeThreshold` | Same tExperienceLevel row+0x10 |
| Credits sibling `aa_0059df20` | Parallel table shape; different round policy |

**Not performed:** Fresh re-decompile, CE mission-complete XP measurement, WAD row dump for worked example.

---

## 2. Evidence used

### A. Authoritative body (raw)

1. Null mission → 0.
2. Quest XP map by short index; product of three floats.
3. Level span from cumulative thresholds with optional L-1 subtract.
4. Truncating float→int cast return.
5. No character fields written.

### B. Plate / XP.md claims under attack

- Formula `spanMult = XPBalanceScaler * frac * XPScaler`
- `xp = (int)(levelSpan * spanMult)` trunc toward zero **here**
- Complete path applies ±0.5001 bias **before** AddExperience
- Worked example: L=5 span 3200 × 0.10 × 1.0 = 320
- “Final objective only”
- Client prefers calculator over static `MissionObjective.XP`

### C. Negative evidence

- Table float payloads not re-read from image.
- Map iterator layout residual on L-1 path.
- No live complete measurement.

---

## 3. Attack results (claim-by-claim)

### Claim 1 — Formula matches XP.md

| Sub-claim | Attack result |
|-----------|----------------|
| Product order Balance * frac * Scaler | **Not broken** — matches raw multiply order |
| levelSpan = cum[L] − cum[L−1] when L>1 | **Not broken** |
| When L≤1 span = cum[L] | **Not broken** |
| Trunc toward zero in **this** function | **Not broken** — `(int)((float)span * mult)` |

### Claim 2 — Bias is part of this calculator

| Sub-claim | Attack result |
|-----------|----------------|
| Body references `g_flMissionXpRoundBias` | **Falsified** — no reference in raw |
| Plate “complete path applies ±0.5001” | **Not broken** as **caller** claim; must not be attributed to this VA |

### Claim 3 — Final objective only

| Sub-claim | Attack result |
|-----------|----------------|
| Body self-enforces final-only | **Falsified as body claim** — pure function; no sequence check |
| Advance path never calls it | **External** — CompleteObjective raw has no call on advance; not proven exclusive by this unit alone |

### Claim 4 — Worked example XP=320

| Sub-claim | Attack result |
|-----------|----------------|
| Arithmetic from stated table values | **Consistent** if table values true |
| Table values proven from this body | **Unproven** — body only reads maps; example is XP.md data narrative |

### Claim 5 — Clean is sealed port-ready formula module

| Sub-claim | Attack result |
|-----------|----------------|
| CF-faithful refined comments | **Not broken** |
| Map helpers fully typed / ABI sealed | **Overclaim** — `_INFERRED` names; iterator residual |

### Claim 6 — L-1 path definitely loads `node->intExperience`

| Sub-claim | Attack result |
|-----------|----------------|
| Raw subtracts `*(nPrevThreshold + 0x10)` | **Not broken** as raw shape |
| `nPrevThreshold` is always a node* | **Unproven** — decompiler assigns `*extraout_EAX` (iterator value); may be node* or iterator with payload at +0x10 depending on map node layout. Competing: missing double-deref |

### Claim 7 — Static MissionObjective.XP unused

| Sub-claim | Attack result |
|-----------|----------------|
| This body never reads a static XP int field | **Not broken** |
| Entire client never uses static XP | **Unproven** — out of scope; other types may use separate tables (XP.md crazy-taxi note) |

---

## 4. Alternate interpretations

### Minimal hard-to-attack reading

```
if no mission def: return 0
frac = questXpLookup[xpIndex].payload
mult = balance * frac * scaler
cumL = experienceLevel[targetLevel].payload
if targetLevel > 1 and prev found:
  span = cumL - cumPrev
else:
  span = cumL
return trunc(span * mult)
```

### Competing stories not ruled out

1. L-1 map access is slightly mis-decompiled (iterator vs node) but yields correct ints by accident of layout.
2. `Map_LowerBoundFindByIntKey` 4th arg is a real map `this` recovered poorly.
3. Negative spanMult could produce negative XP (trunc toward zero); untested.
4. “Final only” is a system convention, not a calculator invariant.

---

## 5. What was confirmed despite skepticism

1. Pure calculator: no character currency/XP fields written.
2. Bias is **not** in this function (caller CompleteObjective).
3. Truncation is here; nearest-int bias is later.
4. Product uses three objective/table floats in documented order.
5. Clean ≡ raw CF (refined fidelity).
6. Function record does not claim runtime seal.

---

## 6. Residual uncertainty

| # | Uncertainty | Blocks sealing? |
|---|-------------|-----------------|
| R1 | Map iterator vs node on L-1 path | Yes for bit-exact understanding |
| R2 | Table float payloads / worked example | Yes for economy tuning |
| R3 | Exclusivity of callers | Mild for port; High for “final only” prose |
| R4 | Negative / zero scaler edge cases | Yes for economy edge |
| R5 | Runtime complete XP measurement | Yes |

---

## 7. Concrete checks performed

1. Re-derived formula from raw alone without XP.md.
2. Compared clean to raw for invented bias/ceil/character writes (none).
3. Cross-checked product order and trunc cast.
4. Attacked attribution of ±0.5001 to this VA (false).
5. Attacked “final only” as body-enforced (false; caller-enforced).
6. Correlated caller CompleteObjective packaging with XP.md.

**Not done:** re-decompile, CE, WAD dump, xrefs exhaust.

---

## 8. Verdict

### **`needs-more-evidence`**

**Why not accept-with-gaps (for *interpretation package*):**  
Clean fidelity is strong, but sealing the **economy interpretation** (worked examples, table payloads, L-1 map layout, exclusive final-only caller set) needs more evidence than static CF matching.

**Why not needs-revision:**  
No evidence that filed raw CF is wrong; clean matches it. Revision means table/runtime recovery, not rewriting a broken CF.

**Bar for stronger verdict:**

1. Confirm L-1 path with map node layout or small re-decompile of that block.
2. Dump tQuestXPLookup / tExperienceLevel rows for the worked example.
3. Runtime: complete a mission and compare granted XP to calculator + bias.
4. Xref scan for other callers of `0x0059dde0`.

**Final verdict: `needs-more-evidence`**
