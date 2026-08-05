# Review B (skeptical / adversarial): `aa_0052aa20` CVOGCharacter_HasCompletedMission

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052aa20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Tighten date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0052aa20_CVOGCharacter_HasCompletedMission.md` |
| **Verdict** | **accept** on hash CF + dual-path truth table; **needs-more-evidence** on continent/`+0xfc` product names and mode-field writers |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Simple OR of `+0x538` and `+0x53c` | **Falsified** — fast path never touches `+0x53c`; Path B mode-gated; **when attached + mode + continent match, a hit only in `+0x538` returns false** |
| 2 | Continent match required for all true returns | **Falsified** — null-`+0xa8` path has no `+0xfc` compare; Path A returns true on mismatch / missing def / `!mode` with `+0x538` hit |
| 3 | `WeaponAllowsKillXpBonus` is weapon XP here | **Name attacked** — body is `+0x100`/`+0xac` field gate only (`aa_004ce340`); multi-system mode switch |
| 4 | Function is pure | **Body store-free High**; callees not proven pure (hash lookup + mode are field reads — likely pure, unproven for hash impl) |
| 5 | Null `+0xa8` means “not in instance world” | **Unproven** — could be unloaded continent, pre-init, or other subsystem |
| 6 | Clean seals machine recovery | **Overclaim** — clean ≡ raw CF only; no bit-exact |
| 7 | Plate “completed OR instance with continent match” | **Oversimplified / false as universal** — match+mode path is instance-only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Hash offsets 538 / 53c | **High** | Wrong completed state → wrong re-offers / prereqs |
| Fast-path only 538 | **High** | Instance-completed ignored when no attach |
| Match+mode → only 53c can true | **High** (static CF) | Server that ORs both hashes re-blocks / false-completes wrong |
| Mode gate polarity vs GiveMission | **High** | Dual-path drift between grant skip and query |
| Mode body fields `+0x100`/`+0xac` | **High** | Mis-port “weapon” gate |
| `+0xfc` = continent id | **Tentative** | Wrong match field → false prereq fails |
| Null `+0xa8` semantic | **Tentative** | Mis-model world/instance gating |
| Runtime dual-hash population | **Open** | Port parity without login/instance restore |

---

## 3. Cross-check against raw (re-decompile 2026-07-29)

```
if continent_obj(+0xa8) == 0:
  return lookup(char+0x538, id) != null
// attached:
// Path A: (no table OR no def OR +0xfc mismatch OR !mode) AND lookup(+0x538)
// Path B: mode AND lookup(+0x53c)
// else false
```

Clean preserves nesting. Live decompile ≡ raw capture.

**GiveMission (`0x005327c0`) polarity:** when mode false, blocks re-grant on `+0x538`; when mode true, blocks on `+0x53c` — same dual-hash policy switch as this query.

**Mode gate (`0x004ce340`):** AL=1 only if `+0x100==0` and `+0xac!=2`. Not a weapon scan. Xrefs span AddExperience, HasCompletedMission, GiveMission, vehicle pools.

---

## 4. Surviving contract for AutoCore

```
HasCompletedMission(character, missionId) -> bool
  if no continent attach (+0xa8 null):
      completed-hash (+0x538) only
  else:
      Path A: permanent (+0x538) when table/def missing OR +0xfc mismatch OR !mode
      Path B: instance (+0x53c) when mode
      when mode AND def present AND +0xfc match: Path A is dead — only Path B
  Does not mutate character state (body).
```

Do **not** implement as naïve `hash538 || hash53c`.

**Server note (AutoCore today):** single `CompletedMissionIds` HashSet — no instance hash / mode gate. Acceptable interim for open-world permanent completes; **will diverge** for instance-completed missions once those exist on wire.

---

## 5. Open questions

1. Exact type of object at entity `+0xa8`.
2. Whether `+0xfc` is continent id or another identity.
3. Producers of mode fields `+0x100` / `+0xac` (when mode is “instance policy”).
4. Live inject: completed vs instance-completed vs null continent.
5. Whether `FUN_0053fff0` owner is global mission manager (lazy `+0xf18`) — Probable, shared.

---

## 6. Concrete checks performed (tighten)

1. Live re-decompile `0x0052aa20` — matches raw CF.
2. Expanded Path A/B truth table including **match+mode → 538-only is false**.
3. Cross-read `WeaponAllowsKillXpBonus` dual (`aa_004ce340`) — field gate sealed.
4. Cross-read GiveMission dual-hash skip polarity.
5. Enumerated 13 xrefs / named callers (requirements, offer, interact icons, logic var type 9).
6. Confirmed clean introduces no CF delta.

**Tighten note (2026-07-29):** Adversarial re-check — plate OR wording remains **false** as universal; truth table High static; product names for `+0xa8`/`+0xfc`/mode writers still open. Do not claim runtime/bit-exact complete.

**Verdict:** Accept client lookup CF and dual-path contract; reject oversimplified “OR of two hashes” and XP-weapon naming. Runtime still required for sealed product semantics of continent attach and mode field writers.
