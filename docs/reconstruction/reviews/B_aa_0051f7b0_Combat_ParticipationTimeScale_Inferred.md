# Review B (skeptical / adversarial): `aa_0051f7b0` Combat_ParticipationTimeScale_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051f7b0` |
| **VA** | `0x0051f7b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0051f7b0_Combat_ParticipationTimeScale_Inferred.md` |
| **System** | missions-progression / combat XP + loot scale |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Returns remaining cooldown (1→0) | Formula `dt/300000` clamped to 1; grows with age | **Falsified** as decay — **grows to full** |
| 2 | Stamp 0 means “just started” → 0 scale | stamp 0 fails gate → return **1.0** | **Falsified** |
| 3 | Window is 5 minutes exact 300000 | Compare uses **300001** (`0x493e1`) | **Survives** (off-by-one ms) |
| 4 | No float fixup needed | Large unsigned dt uses +2^32 when cast negative | **Survives** |
| 5 | Clears stamp only on success | Clears on **failure/stale** path only | **Survives** |
| 6 | Multiple callers | Only OnDeath static | **Survives** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Linear ramp min(1, dt/300000) | **High** | XP mult inverted |
| 300001 window | **High** | Edge timing |
| Default full credit when unstamped | **High** | Wrong nerf |
| Product “participation” naming | **Probable** | Docs only |
| Stamp writer | **Open** | Scale always 1 if never set |

---

## 3. Cross-check

`read_memory`: `009cef00` → 3.333e-6 (=1/300000); `00aaa5dc` → 4294967296.0.

Parent: `fVar14 = FUN_0051f7b0(); local_74 = (float)fVar14;` then XP `*(iStack_6c+0x500) * local_74 * fStack_70`.

---

## 4. Surviving contract

```
float ParticipationScale(Obj* o) {
  uint stamp = o->tickStamp504;
  uint dt = GetTickCount() - stamp;
  if (dt < 300001 && stamp != 0)
    return min(1.0f, uint_as_float(dt) / 300000.0f);
  o->tickStamp504 = 0;
  return 1.0f;
}
// Do NOT invert to (1 - t). Do NOT treat stamp0 as zero reward.
```

---

## 5. What would overturn

1. Writer sets stamp to “future” deadline (would invert product meaning).
2. Evidence parent multiplies inverse.
3. Different constant image in another build.

**Verdict:** **accept-with-gaps.**
