# Review B (skeptical / adversarial): `aa_00522bc0` CVOGReaction_RecordFirstTimeEvent

| Field | Value |
|---|---|
| **Stable ID** | `aa_00522bc0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00522bc0_CVOGReaction_RecordFirstTimeEvent.md` |
| **Verdict** | **accept-with-gaps** on HB start; **needs-more-evidence** vs account FirstTimeFlags |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Sets account FirstFlags1..4 | **Falsified for this body** — no +0xD30 / 0x20B1 |
| 2 | Always starts event | **Falsified** — needs +0x7e and not already +0xc7c |
| 3 | Idempotent re-entry while +0xc7c set | **Falsified** — second call fails low-byte clear |
| 4 | Name proves tutorial tip index N | **Unsealed** — event id via param_2+0x25c only |
| 5 | Clean modern types prove CVOGHBBase | **Overstated** — name from decompiler; layout open |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Gate + HB start CF | High | Missing/stuck tips |
| Equivalence to FirstTimeFlags packet | Low | Wrong persistence model |
| Event object fields | Tentative | Wrong tip content |

---

## 3. Cross-check against raw

```
if related.flag7e && !char.recording(+0xc7c):
  stop prior HB; build new HB from event; enqueue; start
  mark recording; return true
return false-ish
```

FIRST_TIME_FLAGS.md describes account bitfield + C2S 0x20B1 — **different pipeline**. May be upstream/downstream of this HB, not this unit.

---

## 4. Surviving contract for AutoCore

```
RecordFirstTimeEvent(character, eventObj) -> bool
  require local related authority (+0x7e) and not already recording
  replace any active first-time HB; start new HB from event
  set recording flags / snapshots
Does NOT by itself write account FirstFlags or send 0x20B1.
```

---

## 5. Open questions

1. Who sets FirstFlags bits after this HB runs.
2. What clears +0xc7c.
3. Event catalog for +0x25c.
4. Live first-time reaction → tip UI → 0x20B1 sequence.

**Verdict:** Accept HB starter; keep account flags system separate until linked.
