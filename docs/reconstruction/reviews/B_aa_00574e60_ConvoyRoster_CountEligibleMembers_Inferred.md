# Review B (skeptical / adversarial): `aa_00574e60` ConvoyRoster_CountEligibleMembers_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00574e60` |
| **VA** | `0x00574e60` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual A/B **create**) |
| **Counterpart** | `reviews/A_aa_00574e60_ConvoyRoster_CountEligibleMembers_Inferred.md` |
| **Verdict** | **accept-with-gaps** — algorithm sealed; flag-on-member vs award-loop vehicle flag nuance kept open as Probable |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Counts **in-range** members by increment | Invert polarity | **Falsified** — seed headcount then **decrement** bad members |
| 2 | Distance gate is `< 300` keep vs `≥ 300` drop | Inequality flip | **Sealed as ≥ 300 drops** — `DAT <= SQRT` triggers decrement |
| 3 | Uses full 3D distance (includes Y) | Wrong metric | **Falsified** — only `*p` and `p[2]` (X/Z) |
| 4 | Radius is Collect-only / different DAT | Constant drift | **Falsified** — same `DAT_00aaa8a8` = 300.0f |
| 5 | Empty slots decrement count | Off-by-null | **Falsified** — null slots skip body |
| 6 | Can return 0 | No clamp | **Falsified** — min clamp to 1 |
| 7 | Same soft-flag object as award loop (`member+0x250` vehicle) | Equate call sites | **Partially sustained difference** — **this** unit calls `+0x198` on **slot member** adjusted-this; award loop uses vehicle at `+0x250`. Do **not** claim identical target without more proof |
| 8 | Pure no-op like 00574900 | Cluster confuse | **Falsified** — full body + `ret 4` |
| 9 | Many general callers | Over-general API | **Falsified** — **1** CALL only |
| 10 | `this` is killer character | Ignore roster layout | **Probable falsify** — `+0x1a0` slot array + `+0x1d8` headcount are roster fields; killer is stack `param_2` at sole site |
| 11 | Product name sealed | Over-promote | **Sustained** — keep `_Inferred` |
| 12 | Indirect callees “none” means no vtbl | Tool empty list | **Tool artifact** — body has virtual calls; not zero work |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Seed / decrement / clamp CF | **High** | Wrong XP share divisor |
| Radius 300.0f XZ | **High** | Wrong eligibility |
| 4×0x10 slots @ +0x1a0 | **High** | Wrong roster walk |
| Null skip | **High** | Phantom decrements |
| Sole caller XP path | **High** | Missed ports |
| Flag target object | **Medium–Probable** | Mismatch vs award filter |
| `this` roster type name | **Probable** | Wrong owner |
| English product name | **Low** | Bad NAMING |
| Runtime golden | **Open** | Share wrong under edge rosters |

---

## 3. Cross-check formula

```
count = (u8)roster->headcount_at_1d8
ref = GetPos(param_2)   // vtbl+0x1a0
for i in 0..3:
  m = roster->slot[i]   // +0x1a0 + i*0x10
  if m == null: continue
  if SoftFlag(m) || dist_xz(ref, GetPos(m)) >= 300.0f:
    count -= 1
return max(count, 1)
```

Hex constant `DAT_00aaa8a8`: `00 00 96 43` → 300.0f.

Epilogue includes `ret 4` (`c2 04 00`) — one stack arg.

---

## 4. Surviving contract for AutoCore

```
ConvoyRoster_CountEligibleMembers_Inferred(roster, refCharacter):
  count = u8(roster+0x1d8)
  refPos = refCharacter.GetWorldPos()   // vtbl+0x1a0
  for slot in roster.slots[0..3]:       // base +0x1a0, stride 0x10
    if slot.member == null: continue
    if member.SoftOutFlag() or dist_xz(refPos, member.Pos) >= 300:
      count -= 1
  return max(count, 1)

// OnDeathAward only static consumer (this image)
// Pair guards: Lock_NoOp before, Unlock_NoOp after award loop
// Do NOT:
//  - invent increment-from-zero without seed
//  - use Y in distance
//  - return 0
//  - assume flag is taken from vehicle+0x250 (award loop differs)
```

**Port tests:** All far → 1; all good with seed N → N (if slots match seed); null slots don’t force decrement; stack pops 4.

---

## 5. Open questions

1. Exact C++ type of roster / meaning of `+0x1d8` vs filled slots.
2. Precise product meaning of vtbl `+0x198` on **member** vs vehicle path in award loop.
3. Whether share math wants “eligible now” vs “roster size” when seed desyncs from filled slots.
4. Runtime multi-member capture.
5. PDB symbol.

**Verdict:** **accept-with-gaps** — polarity, radius, clamp, and sole-caller attacks **closed**; flag-object nuance + names remain residual.
