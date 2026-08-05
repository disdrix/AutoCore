# Review B (skeptical / adversarial): `aa_00532d30` CVOGCharacter_LevelUp

| Field | Value |
|---|---|
| **Stable ID** | `aa_00532d30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00532d30_CVOGCharacter_LevelUp.md` |
| **Verdict** | **accept-with-gaps** on grant CF; **needs-more-evidence** on table layout & helper names |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Awards skill/attrib/research for “current level” | **Nuanced** — map key is **`nLevel+1`** before increment; row is for the *new* level |
| 2 | Always notifies UI | **Falsified** — LogicUI only if `bNotifyUi` |
| 3 | Always SearchAutoMissions | **Falsified** — gated on character flag `…+0x7e` |
| 4 | `nHpDelta_INFERRED` is always HP | **Overstated** — local reused; vehicle path stores combat-pool delta; UI packet carries that delta |
| 5 | Row `+0x10` XP threshold used in body | **Weak in-body** — loaded to `nRowExperience` but **not** applied as a store in the shown path (threshold check is caller-side) |
| 6 | Clean renames prove retail struct | **Falsified** — scaffold renames only; FUN_* remain |
| 7 | De-levels also use this | **Falsified** — sibling `CVOGCharacter_LevelDown` @ `0x005330E0` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Level++ + skill/attrib/research adds | High | Wrong pool economy on level |
| Map miss → no grant | High | Silent level stall if table incomplete |
| bNotifyUi gate | High | Extra/missing LogicUI 0x2D spam |
| Local-player SearchAutoMissions | Probable | Auto-grants on wrong characters |
| Vehicle pool recalc necessity | Probable | Pool desync after level in vehicle |
| Full ExperienceLevel row semantics | Tentative | Wrong point packs if packing endian wrong |

---

## 3. Cross-check against raw

Raw body (authoritative):

1. `key = *(this+0x6c8)+1` → map lower_bound.
2. On hit: dirty `\|0x80`; `*(this+0x6c8)++`; add packed skill/attrib; skill HB dual pass; research short; four attribute helpers; optional vehicle; `vtbl+0x5c`; flag `0x4f2=1`; conditional SearchAutoMissions; optional LogicUI `0x2d`.
3. On miss: fall through return (no level change).

Clean mirrors these stages without inventing multi-level loops or XP subtraction. Cross-doc `docs/XP.md` agrees on skill/attrib/research + LogicUI 0x2D + SearchAutoMissions.

---

## 4. Surviving contract for AutoCore

```
CVOGCharacter_LevelUp(char, bNotifyUi):
  ensure ExperienceLevel table
  row = map[lower_bound(char.level + 1)]
  if no row: return
  dirty |= 0x80
  char.level++
  char.skillPts  += LOWORD(row+0x14)
  char.attribPts += HIWORD(row+0x14)
  // skill HB refresh passes
  char.research  += LOWORD(row+0x18)
  // attribute helpers; optional vehicle pool delta
  if localPlayer(+0x7e): SearchAutoMissions
  if bNotifyUi: LogicUI type 0x2D (level, hpDelta, extra)
```

Caller remains responsible for *when* to level (XP threshold), including multi-level loops.

---

## 5. Open questions

1. Exact packing of research dword at `row+0x18` (only low short used).
2. Meaning of unused `nRowExperience` local (row+0x10).
3. What the four `FUN_004c2e*` helpers recompute.
4. Whether NPC/remote characters ever call with `bNotifyUi=true`.
5. Runtime observe of multi-level from large GiveXP.

**Verdict:** Accept as level-grant kernel; do not treat as full XP system or sealed table schema.
