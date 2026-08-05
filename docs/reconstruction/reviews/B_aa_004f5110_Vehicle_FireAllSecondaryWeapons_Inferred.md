# Review B (skeptical / adversarial): `aa_004f5110` Vehicle_FireAllSecondaryWeapons_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f5110` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004f5110_Vehicle_FireAllSecondaryWeapons_Inferred.md` |
| **System** | `combat` / vehicle weapons |
| **Dual status** | **Written this pass** |
| **Verdict** | **accept-with-gaps** on 3-slot walker + vtbl+0x3C + OR fire; **reject** overclaims that this unit heat-checks, fires primary group, includes turret, or is bit-exact sealed |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Unit also heat-checks weapons | Body has only vtbl+0x3C + `FUN_0056d520`; heat is `FUN_004f52e0` | **Falsified** — heat is caller-side |
| 2 | Fires turret at +0x264 | Loop only reads `+0x260` table | **Falsified** — hardpoints only |
| 3 | Same as primary fire-all | Primary twin uses vtbl **+0x38** | **Falsified as identical** — group offset differs |
| 4 | Returns true only if **all** secondaries started | `or bl,al` is existential aggregate | **Falsified** — any success → non-zero |
| 5 | `FUN_0056d520` is vehicle thiscall | Asm reloads `ecx,esi` (weapon) before call | **Falsified** — weapon this |
| 6 | Inline `weapon*[3]` at +0x260 | Asm double load `[ebp+0x260]` then `[edi+eax]` | **Falsified** — pointer-to-table |
| 7 | Product name is sealed retail | No string / RTTI in unit | **Hold `_Inferred`** |
| 8 | Also used by AI / primary input | Sole xref from `Input_TryFireSecondaryWeapons` | **Falsified multi-caller** (static) |
| 9 | Ready for bit-exact port seal | Runtime / 0056d520 residual open | **Fail** complete seal claim |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 3-slot hardpoint walk CF | **High** | Fire wrong slot count |
| Secondary vs primary group vtbl | **High** CF | Fire wrong group / both groups |
| OR return semantics | **High** | UI/chrome gated on “all started” wrongly |
| Caller-only heat | **High** | Double heat gate or miss overheat |
| Weapon this into 0056d520 | **High** | Corrupt vehicle as weapon |
| Product English names | **Probable** | Premature registry rename |
| Null table base safety | **Medium** | Crash on unequipped vehicle if caller wrong |
| Full 0056d520 side effects | **Probable** | Miss ammo/net/HB edge |

---

## 3. Cross-check against raw / live

```
any=0
for off in 0,4,8:
  w = *(*(veh+0x260) + off)
  if w && w.vtbl+0x3C(): any |= FUN_0056d520(w)
return any
```

Live Ghidra re-decompile 2026-07-29 matches 2026-07-23 raw body. Asm seals ECX/loop/OR/`call [edx+0x3c]`.

---

## 4. Surviving contract for AutoCore

```
Client secondary gun fire (after heat probe elsewhere):
  Vehicle_FireAllSecondaryWeapons_Inferred(vehicle):
    for each of 3 hardpoint weapon*:
      if weapon && IsSecondaryGroup(weapon):  // vtbl+0x3C
        try StartWeaponFire(weapon)           // FUN_0056d520
    return (any start succeeded)

Do NOT:
  - re-check heat inside this loop
  - include turret +0x264
  - require all secondaries to start
  - treat primary group (+0x38) as secondary
Mirror OR-return if client-sim reports “did fire this frame”.
```

---

## 5. Open questions

1. Live: mixed primary/secondary hardpoints → only +0x3C weapons fire.
2. Live: `FUN_0056d520` returns 0 (e.g. `weapon+0xCB` set) → aggregate may still be non-zero from siblings.
3. Global rename of `FUN_0056d520` / vtbl+0x3C once product evidence lands.

**Verdict:** **accept-with-gaps**
