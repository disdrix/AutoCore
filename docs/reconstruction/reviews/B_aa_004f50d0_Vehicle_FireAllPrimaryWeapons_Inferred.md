# Review B (skeptical / adversarial): `aa_004f50d0` Vehicle_FireAllPrimaryWeapons_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f50d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004f50d0_Vehicle_FireAllPrimaryWeapons_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Unit also heat-checks weapons | Body has only vtbl+0x38 + `FUN_0056d520`; heat is `FUN_004f5290` | **Falsified** — heat is caller-side |
| 2 | Fires turret at +0x264 | Loop only reads `+0x260` table | **Falsified** — hardpoints only |
| 3 | Same as secondary fire-all | Secondary twin `FUN_004f5110` uses vtbl **+0x3C** | **Falsified as identical** — group offset differs |
| 4 | Returns true only if **all** primaries started | `or bl,al` is existential aggregate | **Falsified** — any success → non-zero |
| 5 | `FUN_0056d520` is vehicle thiscall | Asm reloads `ecx,esi` (weapon) before call | **Falsified** — weapon this |
| 6 | Inline `weapon*[3]` at +0x260 | Asm double load `[ebp+0x260]` then `[edi+eax]` | **Falsified** — pointer-to-table |
| 7 | Product name is sealed retail | No string / RTTI in unit | **Hold `_Inferred`** |
| 8 | Also used by AI / secondary input | Sole xref `0092236c` in `FUN_00922270` | **Falsified multi-caller claim** (static) |
| 9 | Skill cast path also hits this | Parent skill success `goto` skips heat+this | **Out of unit**; parent dual already sealed skip |
| 10 | +0x260 is only “stabilizer” (physics notes) | Combat equip, IsAnyWeaponFiring, heat/fire family all weapons | **Combat weapon seal stands**; physics wording residual elsewhere |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 3-slot hardpoint walk CF | **High** | Fire wrong slot count |
| Primary vs secondary group vtbl | **High** CF | Fire wrong group / both groups |
| OR return semantics | **High** | UI/chrome gated on “all started” wrongly |
| Caller-only heat | **High** | Double heat gate or miss overheat |
| Weapon this into 0056d520 | **High** | Corrupt vehicle as weapon |
| Product English names | **Probable** | Premature registry rename |
| Null table base safety | **Medium** | Crash on unequipped vehicle if caller wrong |
| Full 0056d520 side effects | **Probable** | Miss ammo/net/HB edge |

---

## 3. Cross-check against raw

```
any=0
for off in 0,4,8:
  w = *(*(veh+0x260) + off)
  if w && w.vtbl+0x38(): any |= FUN_0056d520(w)
return any
Clean ≡ raw CF. Names residual (_Inferred + FUN_0056d520).
Sibling secondary: same skeleton, vtbl+0x3C.
```

Live Ghidra re-decompile 2026-07-29 matches 2026-07-23 raw body. Asm read seals ECX/loop/OR.

---

## 4. Surviving contract for AutoCore

```
Client primary gun fire (after heat probe elsewhere):
  Vehicle_FireAllPrimaryWeapons_Inferred(vehicle):
    for each of 3 hardpoint weapon*:
      if weapon && IsPrimaryGroup(weapon):  // vtbl+0x38
        try StartWeaponFire(weapon)         // FUN_0056d520
    return (any start succeeded)

Do NOT:
  - re-check heat inside this loop
  - include turret +0x264
  - require all primaries to start
  - treat secondary group (+0x3C) as primary
Mirror OR-return if client-sim reports “did fire this frame”.
```

---

## 5. Open questions

1. Live: mixed primary/secondary hardpoints → only +0x38 weapons fire.
2. Live: `FUN_0056d520` returns 0 (e.g. `weapon+0xCB` set) → aggregate may still be non-zero from siblings.
3. Global rename of `FUN_0056d520` / vtbl+0x38 once product evidence lands.
4. Reconcile physics “stabilizer +0x260” wording with combat weapon table (doc hygiene, not CF).

**Verdict:** **accept-with-gaps**
