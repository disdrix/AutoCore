# Review B (skeptical / adversarial): `aa_0056c0a0` Weapon_SelectMultiTargets_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0056c0a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W20-H) |
| **Counterpart** | `reviews/A_aa_0056c0a0_Weapon_SelectMultiTargets_Inferred.md` |
| **Verdict** | **accept** on sealed CF; reject listed false claims |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Same as `Weapon_TryFireResolveHits` (`0x0056c860`) | Different VA; no heat/power gate; no damage dispatch `004d7e30`/`004da2e0`; ret 8 vs ret 4 | **Falsified** |
| 2 | Same as area gather `Skill_GatherTargetsInArea` / `0056d600` | No `GetObjectsInArea` (`004ea350`) in this body; locked-list walk + preferred seed | **Falsified** as same unit |
| 3 | cdecl / bare ret | Exit `c2 08 00` | **Falsified** |
| 4 | Returns bool success only | Many paths return `uStack_21c` count; fails return `0xffffffff` | **Falsified** if bool-only |
| 5 | maxTargets hard-coded 100 always | `FUN_0056ac50` first; clamp only when `>100` | **Falsified** |
| 6 | String is product class name | Typo **Weaopn** warning only; not RTTI | **Falsified** as class name |
| 7 | Direct code callers | Only DATA vtable xrefs | **Falsified** if claimed call-site density |
| 8 | Fires weapons / applies damage | No heat apply; no hit resolve; only list fill | **Falsified** |
| 9 | Bit-exact / runtime verified | Static dual only | **Fail** if claimed |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + ret 8 | **High** | ABI break |
| −1 fail / count success | **High** | wrong client branch |
| Weaopn clamp path | **High** | silent wrong max |
| Not TryFire / not damage | **High** | invent fire side effects |
| Product method spelling | **Low–Med** | naming only |
| Full filter semantics | **Partial** | over/under select residual |

---

## 3. Cross-check

| Item | Result |
|---|---|
| Raw ≡ live decompile | **Yes** |
| Body end `c2 08 00` | **Yes** via `read_memory` near exclusive end |
| String @ `0x009d2fcc` | **Yes** full Weaopn text |
| Vtable DATA `@ 0x009d3330` | **Yes** dword `a0 c0 56 00` |
| Sibling TryFire slot 0 | **Different function** |
| FindDistanceToTarget caller list includes this | **Yes** (prior dual) |

**Attack on “this fires the weapon”:** **Fails** — selection/list commit only.

**Attack on “this is area GetObjectsInArea multi-hit builder 0056d600”:** **Fails** — different ABI and callees.

---

## 4. Surviving contract for AutoCore

```
// __thiscall ret 8
// uint SelectMultiTargets(Weapon *this, LockedList *worldList, Object *preferred)
// fail: return 0xffffffff (may clear list host)
// success: fill this+0x13c via 0056eca0 slots; return count ≤ maxTargets≤100
// range via CVOGPhysicsUtils_FindDistanceToTarget; no damage apply here
```

**Falsified port mistakes:**

- Calling as fire/damage path (use TryFire dual instead).
- Ignoring −1 fail vs count.
- Hard-coding max=100 without `FUN_0056ac50` / clamp log path.
- Assuming direct non-virtual callers.

---

## 5. Open questions

1. Product/RTTI class + slot English.
2. Complete filter-bit dictionary.
3. Runtime / bit-exact.

**Verdict:** **accept** — sealed CF/ABI/string/vtable role; reject fire-path and area-gather identity myths.
