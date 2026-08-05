# Review B (skeptical / adversarial): `Client_CastBlockFeedback` @ `0x0093b7f0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0093b7f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0093b7f0_Client_CastBlockFeedback.md` |
| **Verdict** | **accept-with-gaps** on sealed strings + return polarity; predicate semantics open |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Return 1 means "ok / success" | **Falsified** — both callers abort cast when nonzero; 1 = blocked |
| 2 | Null character allows cast | **Falsified** — null `+0xe98` returns 1 (block) without toast |
| 3 | "dead." / "waiting." / "in town." are shared multi-owner strings | **Falsified** — `get_bulk_xrefs`: each has **sole** DATA xref inside this function |
| 4 | Status flag bit value equals `FUN_00580a20` name id always | **Falsified for bit 8** — checks `&8` but calls `FUN_00580a20(2)` → "Stunned"; bits `0x80`/`0x40` match ids |
| 5 | Function only used by quickbar cast | **Partial** — also `FUN_00941ac0` → `Client_RequestCastSkill` path |
| 6 | Town check is a direct char field | **Partial** — via `*( *(entity_dual+0xa8) + 0xf5 )`, not `char+0xf5` |
| 7 | Message ends with single period | **Attack holds** — suffix has `.` and code appends `!` → `dead.!` shape unless localizer mutates |
| 8 | Blocks only "dead" | **Falsified** — enhanced / waiting / town / stun / confuse / afraid |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| dead/waiting/town string VAs + bytes | **Confirmed** | Wrong UX localization |
| Return polarity (1=block) | **Confirmed** | Cast while dead / silent fail inverted |
| Priority ladder order | **High CF** | Wrong toast for multi-flag states |
| vtbl +0x198 = "is dead" method | **High by string** | Wrong predicate if vtbl shared for other death-like state |
| vtbl +0x194 = "is waiting" | **High by string** | Same |
| Flag→name map for 0x80/0x40 | **High** | Wrong status English |
| Flag bit8 → name id 2 | **Confirmed CF** | Product "Silenced" misuse if assumed bit==id |
| Channel 0x18 toast | **High** | Wrong UI surface |

---

## 3. Surviving contract for AutoCore

```
Client_CastBlockFeedback (client in EAX; 0 formals):
  if localChar (+0xe98) == null → return 1  // block, no toast
  build toast: "You can't do that while you are " + <suffix> + "!"
  first matching gate wins:
    char+0x6b9 != 0           → "in your enhanced state."
    entity.vtbl[+0x198]()     → "dead."          // VA 0x00a2e078
    entity.vtbl[+0x194]()     → "waiting."       // VA 0x00a2e06c
    *(obj_at(entity+0xa8)+0xf5) → "in town."     // VA 0x00a2e060
    flags(+0xb8)&0x08         → StatusName(2)    // "Stunned"
    flags&0x80                → StatusName(0x80) // "Confused"
    flags&0x40                → StatusName(0x40) // "Afraid"
    else → return 0          // allow cast
  show chat toast (ch 0x18) if UI root live
  return 1                   // blocked
```

**Sealed string VAs (this unit only):**

| Suffix | VA |
|---|---|
| `in town.` | `0x00a2e060` |
| `waiting.` | `0x00a2e06c` |
| `dead.` | `0x00a2e078` |

---

## 4. Open questions

1. Implement / name the two vtbl predicates (dead / waiting) from their own dual reviews.
2. Product definition of "enhanced state" (`+0x6b9`) and "waiting".
3. Full status bitfield layout at dual-base `+0xb8` (only three bits consumed here).
4. Runtime capture of live toast text (period+bang).
5. Second caller `FUN_00941ac0` product name / entry conditions.

**Verdict:** Strings dead/waiting/town **sealed** with sole ownership in this helper. Do not invert return polarity. Do not assume flag bit == status name id for the stun path.
