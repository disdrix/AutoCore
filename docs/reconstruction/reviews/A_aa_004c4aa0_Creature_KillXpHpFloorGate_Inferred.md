# Review A (reconstruction fidelity): `aa_004c4aa0` Creature_KillXpHpFloorGate_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c4aa0` |
| **VA** | `0x004c4aa0` |
| **Canonical name** | `Creature_KillXpHpFloorGate_Inferred` |
| **Ghidra name** | `FUN_004c4aa0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_004c4aa0_Creature_KillXpHpFloorGate_Inferred.md` |
| **System** | `missions-progression` / combat kill XP |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

**Creature kill-XP eligibility gate** (sole caller `CVOGCombat_OnDeathAwardKillXp` on template type **0x12** path):

```text
// ECX = creature* (virtual-base adjusted object)
vbOff = *(*(this+4)+4)                 // vbtable[1]
cur   = *(float*)(this + vbOff + 0x64) // +100 decimal — combat pool current (HP-like)
maxI  = vcall(this+vbOff+4, vtbl+0x244)()  // int max pool
thr   = (float)maxI * (float)_DAT_00aaa6e0 // _DAT_00aaa6e0 = double 0.1 → thr = 10% max
// banker's-style ± g_flMissionXpRoundBias (0x00aaa6d0 ≈ 0.5001f) then (int) trunc
if (cur < (float)(int)rounded_thr)
  return 0;                            // low byte 0 (ineligible)
return *(uint8_t*)(this + 0x309);      // flag byte; caller treats as char
```

OnDeath: `cVar3 = FUN_004c4aa0(); if (cVar3 == 0) skip award`.

---

## 2. ABI

| Slot | Role |
|------|------|
| **ECX** | creature* |
| **AL/EAX** | 0 if current HP-like float **below** ~10% max; else `*(u8*)(this+0x309)` |

---

## 3. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `batch_decompile` / `analyze_function_complete` |
| Constants | `read_memory` `0x00aaa6e0` → double **0.1**; `0x00aaa6d0` → float **≈0.5001** (`g_flMissionXpRoundBias`) |
| Caller | `CVOGCombat_OnDeathAwardKillXp` @ `0x004da8d8` only |
| Sibling | `FUN_004c4b20` ratio scale same vb/vtbl pattern |

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| VB adjust + float @ base+0x64 | **High** |
| vtbl **+0x244** int max | **High** |
| Scale **0.1** via `aaa6e0` | **High** (bytes) |
| Round bias same mission XP constant | **High** |
| Return 0 vs `+0x309` byte | **High** |
| English name of `+0x309` | **Tentative** |
| Pool is HP (not power/shield) | **Probable** (kill-XP context) |

---

## 5. Gaps

1. Confirm `+0x309` product flag meaning (alive/valid/killable).
2. Confirm `+0x64` is current HP vs another pool (same offset family as `004c4b20`).
3. Runtime: low-HP kill skips XP when flag set.

**Verdict:** **accept-with-gaps**.
