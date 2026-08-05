# Review B (skeptical / adversarial): `aa_004f5290` Vehicle_CanFireAnyPrimaryHeatOK_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f5290` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004f5290_Vehicle_CanFireAnyPrimaryHeatOK_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Same quantifier as secondary heat probe | Secondary returns 0 on first heat-**fail**; this returns 1 on first heat-**OK** | **Falsified as identical** — ∃ vs ∀ sealed |
| 2 | Checks vehicle heat directly (no weapon walk) | Body iterates `*(v+0x260)` and only then `Weapon_CanFireHeatCheck` | **Falsified** |
| 3 | Requires **all** primaries heat-OK | Early return 1 on first OK; never aggregates fails | **Falsified** |
| 4 | Fires weapons / applies heat | Only vtbl+0x38 + CanFireHeatCheck; no `FUN_0056d520` / AddHeat | **Falsified** — pure predicate |
| 5 | Scans turret at `+0x264` | No `+0x264` load; only `+0x260` table | **Falsified** for this unit |
| 6 | Inline array at `vehicle+0x260+i` | Asm: load pointer then `[base+index]` | **Falsified** — pointer-to-array |
| 7 | Empty hardpoints → allow fire (true) | Fallthrough returns 0 | **Falsified** (secondary empty→1) |
| 8 | Retail name without string | No product string / RTTI in unit | **Hold `_Inferred`** |
| 9 | Ghidra `void` / no-arg signature | ECX this + AL bool; decomp `undefined4 __fastcall(int)` | **Decomp catalog noise** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ∃ vs ∀ vs secondary | **High** | AutoCore blocks primary when one sibling overheats (wrong) |
| 3-slot `*(v+0x260)` walk | **High** | Wrong hardpoint count / miss weapons |
| vtbl+0x38 group filter | **High** CF / **Probable** product word | Gate secondary weapons as primary or reverse |
| CanFireHeatCheck = vehicle heat&lt;max | **High** | Local weapon heat field mistake |
| Empty → deny | **High** | Phantom allow-fire with no primaries |
| Product name | **Probable** | Premature registry rename |
| Turret exclusion intentional | **Medium** | Turret-primary heat ignored if not in table |

---

## 3. Cross-check against raw

```
Primary heat quantifier (this unit):
  for slot in hardpoints[0..2] via *(veh+0x260):
    if weapon && vtbl+0x38() && CanFireHeatCheck(weapon): return 1
  return 0

Secondary twin 0x004f52e0:
  for slot ... vtbl+0x3C:
    if weapon && vtbl+0x3C() && !CanFireHeatCheck: return 0
  return 1

Clean ≡ raw CF. "Primary" label residual (structural dual only).
```

Parent dual `aa_00922270` already treated this quantifier as **High**; this unit owns the formal seal of the callee.

---

## 4. Surviving contract for AutoCore

```
Client primary gun heat gate (vehicle thiscall):
  1) Only hardpoint table *(vehicle+0x260), slots 0..2 — not turret +0x264 in this fn.
  2) Consider only weapons with group predicate vtbl+0x38 true.
  3) Heat is vehicle-pool via Weapon_CanFireHeatCheck (heat+0x150 < max+0x244).
  4) Existential: ANY heat-OK primary allows the primary fire walker.
  5) No heat-OK primary → deny (silent at caller; no secondary heat log).
  6) Do NOT mirror secondary universal quantifier on primary path.
Mirror ∃ semantics in any client-sim / input harness primary fire gate.
```

---

## 5. Open questions

1. Live: two primaries, one at max heat → tip path + still fire cold primary.
2. Live: both overheat → no fire, no secondary-style log.
3. Is turret ever installed into a `+0x260` slot, or only `+0x264`?
4. Seal vtbl+0x38/3C names; optional Ghidra rename of this VA.

**Verdict:** **accept-with-gaps**
