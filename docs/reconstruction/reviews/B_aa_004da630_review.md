# Review B (skeptical / adversarial): `aa_004da630` CVOGCombat_OnDeathAwardKillXp

| Field | Value |
|---|---|
| **Stable ID** | `aa_004da630` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Verdict** | **needs-more-evidence** for full loot/credit semantics; XP fan-out structure **probable** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Function is “kill XP only” | **Falsified** — large credit + loot + special drop tail after XP |
| 2 | Convoy always awards all 4 slots | **Falsified** — null slot, vehicle flag `+0x198`, and range gate skip awards |
| 3 | List path uses dynamic member count | **Falsified** — hardcodes `4` into `CalculateAndAwardKillXP` |
| 4 | Solo path uses convoy blend | **Falsified** — `nConvoyMemberCount = 0` |
| 5 | Template kinds 0xe/0x12 are vehicle/creature | **Probable** — reinforced by RTTI casts later; not symbol-proven at first branch |
| 6 | `+0x500` is XPPercent | **Probable** (XP.md / plate); not re-proven from wad this pass |
| 7 | Client death path is multiplayer authority | **Falsified for XP amount** — callee multiplies GLOBAL=0 |

---

## 2. Surviving structure for AutoCore port

```
killerChar = killerObj->vtbl[0x210]()
if victim is vehicle(0xe) or creature(0x12) with template:
  mult = XPPercent * shareOrOne * participation
  if no share-list:
    if !convoyFlag(+0xcb0): award(killer, count=0)
    else: for i in 0..3: if in range: award(member, count=convoySize)
  else:
    for node in tfidList: if in range: award(resolved, count=4)
// then credits if |levelDelta| policy, loot rolls…
```

Server should reimplement **recipient selection + mult product**, then award via server `GiveXp` with GLOBAL=1.0 policy — not call this client blob.

---

## 3. Highest-risk open questions

1. Exact meaning of `FUN_004c4b20` / `FUN_0051f7b0` share floats.
2. What `+0xcb0` convoy flag producers are.
3. Distance constant `DAT_00aaa8a8` ≈ 300 — 2D XZ only (Y ignored) — intentional?
4. Level delta `< 11` credit gate interaction with grey XP (≥10 no XP) — off-by-policy risk.

---

## 4. Verdict

Do not treat clean as a drop-in port. Use it as a **map of call order and gates**. XP math authority remains `CalculateAndAwardKillXP` + `LevelDiffBaseXp` + server GLOBAL policy.
