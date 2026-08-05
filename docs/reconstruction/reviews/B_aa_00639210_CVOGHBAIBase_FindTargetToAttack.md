# Review B (skeptical / adversarial): `CVOGHBAIBase_FindTargetToAttack` @ `0x00639210`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00639210` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00639210_CVOGHBAIBase_FindTargetToAttack.md` |
| **Verdict** | **accept-with-gaps** on filter pipeline; **needs-more-evidence** on spatial API + “closest” claim |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Function always picks closest enemy | **Weak** — loop returns first entity that passes filters and r² test; order is buffer order, not sorted distance |
| 2 | `FUN_005134e0` is pure “hostile” | **Probable only** — may include faction/team mix; needs caller/type seal |
| 3 | Bit 10 of `+0x180` is team | **Inferred** — name from plate; not string-sealed |
| 4 | Level clamp 11 and radius floor constants are final design | **Opaque** — DAT_* floats; do not hardcode into server without dump |
| 5 | FindTarget is the only acquisition path | **False** — `GetTargetFromAggro` is a parallel path |

---

## 2. Surviving contract for AutoCore

```
FindTargetToAttack(ai):
  if owner missing/invalid or dead/respawn: clear/no target
  seed AI random period field
  spatial query around owner with profile attack radius
  for each hit (buffer order):
    skip non-hostile / team-bit / non-aggro / dead / race-sentinel
    shrink radius^2 by positive level delta (capped)
    if dist^2 <= adjusted: commit target; break
  commit result (possibly null)
```

Prefer **aggro path first** in server design if retail combat prefers hate list; this unit is world scan.

---

## 3. Open questions

1. Name `FUN_004ea350` spatial query and document mode 0xd/0x11.
2. Confirm selection is first-hit vs true nearest (buffer sort?).
3. Seal `+0x180` bit10 and `FUN_005134e0` via faction code xrefs.
4. Runtime: two-candidate arena to see which entity is committed.

**Verdict:** Filter pipeline is usable; do not treat as proven nearest-neighbor or complete acquisition stack without aggro path.
