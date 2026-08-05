# Skeptical / adversarial review: `CVOGReaction_AddExperience` @ `0x00533c30`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00533c30` |
| **Review type** | Skeptical / adversarial (try to falsify current interpretation) |
| **Date** | 2026-07-23 |
| **Scope** | Client XP apply kernel and claims in plate / docs/XP.md |
| **Verdict** | **needs-more-evidence** |

**Generic approval is insufficient.** Claims that survive are those that survived attack, not restatement of the plate comment.

---

## 1. Inspected artifacts

### Primary unit artifacts

| Path | Role |
|------|------|
| `docs/reconstruction/raw/aa_00533c30_CVOGReaction_AddExperience.md` | Immutable decompile |
| `docs/reconstruction/raw/aa_00533c30_CVOGReaction_AddExperience.annotated.md` | Notes |
| `docs/reconstruction/reconstructed-exact/CVOGReaction_AddExperience.cpp` | Human-refined clean |
| `docs/reconstruction/functions/aa_00533c30_CVOGReaction_AddExperience.md` | Status: Human-refined |
| `docs/XP.md` | Algorithm narrative under attack |

### Cross-check / attack surfaces

| Path | Why |
|------|-----|
| `raw/aa_0052c860_Experience_GetCumulativeThreshold.md` | Sentinel / threshold semantics |
| `raw/aa_00532d30_CVOGCharacter_LevelUp.md` (if present) | LevelUp side effects |
| Mission complete raw | Non-kill call site |

**Not performed:** CE XP grant, kill-path spree timing, re-read of DAT floats from image.

---

## 2. Evidence used

### A. Authoritative body (raw)

1. KillPath-only spree + optional weapon scale.
2. Personal float scalar always applied.
3. Soft cap at max level unless specialMode.
4. Early false if scaled==0.
5. Mutate total XP then conditional level loops.

### B. Plate / XP.md claims under attack

- “Single client kernel that mutates total XP and levels”
- Packet grants use `isKillPath=0` so no spree
- Soft cap “at max level”
- Level loops “guard ~300”
- Character field map in XP.md

### C. Negative evidence

- DAT table values not sealed this pass.
- `WeaponAllowsKillXpBonus` name reused elsewhere as non-weapon gate.
- No runtime of multi-level grant or negative XP.

---

## 3. Attack results (claim-by-claim)

### Claim 1 — Sole kernel for XP mutation

| Sub-claim | Attack result |
|-----------|----------------|
| This body writes `+0x730` and calls LevelUp/Down | **Not broken** |
| No other client writer exists | **Unproven** — not exhaustively searched this review; plate claim, not body-proven exclusivity |

### Claim 2 — KillPath enables spree; packets skip it

| Sub-claim | Attack result |
|-----------|----------------|
| Spree block under `isKillPath != PacketOrNonKill` | **Not broken** |
| Mission / GiveXP use 0 | **External** — call sites elsewhere; body allows either |
| Spree byte always drives weapon table index | **Falsified** — table index is entity `+0xe818`, not `+0x738` spree byte |

### Claim 3 — Soft cap formula

| Sub-claim | Attack result |
|-----------|----------------|
| Condition uses `nMaxLevel < playerLevel+1` and `specialMode < 1` | **Not broken** |
| Equivalent to “at max level” prose | **Probable** — vtable level vs `+0x6c8` both appear; soft-cap uses vtable level, loops use `+0x6c8` — potential dual-level source |
| Clamp uses threshold(level)-1 room | **Not broken** |

### Claim 4 — Level-up guard “~300”

| Sub-claim | Attack result |
|-----------|----------------|
| LevelDown loop guard `300` | **Not broken** |
| LevelUp loop guard | **Uses `0x12d` (301)** — same ballpark; XP.md “~300” is fine as prose, not identical constants |

### Claim 5 — Returns false only when no XP applied

| Sub-claim | Attack result |
|-----------|----------------|
| `scaled==0` → false | **Not broken** |
| All other exits true (including clamps / guards) | **Not broken** |
| Distinguishes “leveled” vs “applied only” | **No** — bool is apply-success only |

### Claim 6 — Clean float[16] vs raw float[4]+locals

| Sub-claim | Attack result |
|-----------|----------------|
| Behavior of `table[nTmp]` for nTmp≤15 | **Not broken** if stack layout contiguous (standard for this decompiler pattern) |
| Proven identical stack frame | **Probable only** — not assembly-verified |

### Claim 7 — `WeaponAllowsKillXpBonus` is a weapon XP check

| Sub-claim | Attack result |
|-----------|----------------|
| Name as semantic truth | **Attacked** — same symbol gates completed vs instance hashes in mission code; may be misnamed global mode |
| Gate exists and scales when non-zero | **Not broken** |

---

## 4. Alternate interpretations

### Minimal hard-to-attack reading

```
if killPath:
  update 5s spree counter 0..5
  maybe scale amount by (bonusTable[entityIndex] + 1)
scaled = (int)(amount * personalGain)
if atMax (vtable level) and not specialMode: clamp scaled
if scaled == 0: return false
totalXp += scaled
if authority_flag:
  if scaled < 0: maybe LevelDown loop / floor 0
  else if atMax field-level: clamp total
  else: LevelUp while total >= threshold
return true
```

### Competing stories not ruled out

1. Vtable level and `+0x6c8` can diverge → soft cap vs loop disagree.
2. Weapon bonus index is not spree (spree may be UI/hint only).
3. Personal scalar could be convoy/UI modified outside this function.
4. SpecialMode may be GM / event / tutorial, not only “skip cap.”

---

## 5. What was confirmed despite skepticism

1. KillPath-only spree window and clamp.
2. Personal scalar multiply and zero early-out.
3. Total XP mutation at `+0x730`.
4. Flag-gated level loops with dual guards (300 / `0x12d`).
5. Threshold sentinel `0x7FFFFFFF` aborts loops.
6. Clean ≡ raw CF.
7. Function record does not claim runtime seal.

---

## 6. Residual uncertainty

| # | Uncertainty | Blocks sealing? |
|---|-------------|-----------------|
| R1 | DAT_* spree table floats | Yes for kill XP parity |
| R2 | `+0xe818` index meaning | Yes for weapon bonus |
| R3 | Vtable level vs `+0x6c8` consistency | Yes for cap correctness |
| R4 | `WeaponAllowsKillXpBonus` true meaning | Yes |
| R5 | Server GiveXp mirror policy | Yes for AutoCore multiplayer |
| R6 | Runtime multi-level / negative XP | Yes |

---

## 7. Concrete checks performed

1. Re-derived kill / scale / cap / loop structure from raw alone.
2. Compared clean to raw for invented branches (none material).
3. Attacked XP.md “spree drives table index” (index is `+0xe818`).
4. Noted LevelUp guard `0x12d` vs LevelDown `300`.
5. Cross-checked threshold sentinel with GetCumulativeThreshold unit.
6. Confirmed record/runtime honesty.

**Not done:** re-decompile, CE, DAT float dump.

---

## 8. Verdict

### **`needs-more-evidence`**

**Why not accept-with-gaps (for *interpretation package*):**  
Clean fidelity is good, but XP.md/package claims about weapon-spree coupling, exclusive kernel status, and dual level sources need more evidence. Accepting the package would overstate sealed kill-XP behavior.

**Why not needs-revision:**  
Raw CF is consistent; clean matches. Gaps are semantic/evidence, not a broken reconstruction CF.

**Bar for stronger verdict:**

1. Dump DAT floats for bonus table.
2. Identify `+0xe818` field.
3. Prove vtable level ≡ `+0x6c8` or document divergence.
4. Rename or re-decompile `WeaponAllowsKillXpBonus`.
5. Runtime: packet grant, kill path, max-level clamp, multi-level grant.

**Final verdict: `needs-more-evidence`**
