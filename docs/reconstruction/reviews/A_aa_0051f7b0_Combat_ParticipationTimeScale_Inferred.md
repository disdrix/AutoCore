# Review A (reconstruction fidelity): `aa_0051f7b0` Combat_ParticipationTimeScale_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051f7b0` |
| **VA** | `0x0051f7b0` |
| **Canonical name** | `Combat_ParticipationTimeScale_Inferred` (leave-FUN retail) |
| **Prior names** | `FUN_0051f7b0`; scaffold Named_CalleeOf_OnDeath… |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (fidelity / clean ≡ raw) |
| **Counterpart** | `reviews/B_aa_0051f7b0_Combat_ParticipationTimeScale_Inferred.md` |
| **System** | missions-progression / combat XP + loot scale |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Return a **0..1 participation / freshness scale** for combat rewards based on a **GetTickCount stamp** stored at `this+0x504`.

Used by `CVOGCombat_OnDeathAwardKillXp` as `local_74` multiplier into kill XP (`def+0x500 * scale * …`) after a vtable `+0x210` gate.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean / function record | `aa_0051f7b0_*` |
| Live decompile | Ghidra `0x0051f7b0` (2026-07-29) ≡ clean |
| Constants | `0x493e1` = **300001** ms; `_DAT_009cef00` = **1/300000**; `_DAT_00aaa5dc` = **4294967296.0** (unsigned→float fixup) |

---

## 3. Control flow (authoritative)

```
float10 __fastcall FUN_0051f7b0(int this):
  stamp = *(int*)(this + 0x504)
  dt = GetTickCount() - stamp          // uint wrap arithmetic
  if (dt < 300001 && stamp != 0):
    f = (float)(int)dt
    if ((int)dt < 0):                  // high bit set (large unsigned)
      f += 4294967296.0
    s = f * (1.0/300000)
    if (s >= 1.0): s = 1.0
    return s
  // stale or never stamped
  *(this + 0x504) = 0
  return 1.0
```

Interpretation: within **5 minutes** of stamp, scale ramps **linearly with age** toward 1.0 (full at ≥300000 ms). Missing/stale stamp → **clear stamp** and return **full 1.0** (no penalty).

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__fastcall` single this / object | **High** | |
| Stamp at `+0x504` | **High** | |
| Window 300001 ms exclusive upper | **High** | `uVar4 < 0x493e1` |
| Scale = min(1, dt_ms / 300000) | **High** | constants sealed |
| stamp==0 → treat as full 1.0 + clear | **High** | clear is redundant if already 0 |
| Stale (≥300001) → clear + 1.0 | **High** | |
| Used as XP mult in OnDeath | **High** | parent |
| Product name “participation” | **Probable** | stamp writer not dualed |
| Who writes `+0x504` | **Open** | |

---

## 5. Control flow: clean ≡ raw

**Yes.**

---

## 6. Gaps / open

1. Writer of `this+0x504` (combat engage time?).
2. Whether scale is meant to grow with fight length (as math) vs decay (product docs).
3. Object type of `this` at call site (character vs combat component).

**Verdict:** Math **High**. Semantic label **Probable**. **accept-with-gaps.**
