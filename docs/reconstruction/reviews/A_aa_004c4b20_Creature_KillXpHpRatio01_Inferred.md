# Review A (reconstruction fidelity): `aa_004c4b20` Creature_KillXpHpRatio01_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c4b20` |
| **VA** | `0x004c4b20` |
| **Canonical name** | `Creature_KillXpHpRatio01_Inferred` |
| **Ghidra name** | `FUN_004c4b20` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_004c4b20_Creature_KillXpHpRatio01_Inferred.md` |
| **System** | `missions-progression` / combat kill XP |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

**Kill-XP HP ratio** in ST0 (`float10`), used as participation factor in `OnDeathAwardKillXp`:

```text
// ECX = creature* (same VB layout as 004c4aa0)
vbOff = *(*(this+4)+4)
cur   = *(float*)(this + vbOff + 0x64)   // +100
maxI  = vcall(..., vtbl+0x244)()
ratio = cur / (float)maxI
if (DAT_009cb8b8 <= ratio) return 1.0f   // DAT_009cb8b8 = 0.4f (read_memory)
if (ratio < g_flMultiKillCountBlend) return 0.0f  // global 0.1f @ known site
return ratio
```

OnDeath multiplies: `templateXPPercent(+0x500) * local_74 * ratio` into `CalculateAndAwardKillXP`.

---

## 2. ABI

| Slot | Role |
|------|------|
| **ECX** | creature* |
| **ST0** | clamped ratio in **[0, 1]** with knees at **0.1** and **0.4** |

---

## 3. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `batch_decompile` |
| `read_memory` `0x009cb8b8` | `cd cc cc 3e` = **0.4f** |
| Callers | `OnDeathAwardKillXp` ×2 (`004da903`, `004daae8`) — vehicle **0xe** and creature **0x12** branches |
| Sibling gate | `004c4aa0` |

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| ratio = cur/max | **High** |
| ≥0.4 → 1.0 | **High** |
| <0.1 → 0.0 | **High** |
| Used as XP scale factor | **High** (caller product) |
| Semantic “remaining HP fraction” | **Probable** |
| Div-by-zero if maxI==0 | **Open** (no guard in body) |

---

## 5. Gaps

1. Why knee at **0.4** (full mult above 40% pool) — design intent.
2. maxI==0 behavior.
3. Whether vehicle path uses same creature method after cast.

**Verdict:** **accept-with-gaps**.
