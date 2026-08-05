# Review B (skeptical / adversarial): `CVOGHBAICreatureBase_OnHeartBeat` @ `0x005d0310`

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d0310` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005d0310_CVOGHBAICreatureBase_OnHeartBeat.md` |
| **Verdict** | **accept-with-gaps** on outer CF; **needs-more-evidence** on helper names + flag polarities |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | `owner+0x26c` is exactly idle/engage/combat enum | **Probable** — matches Driver + docs, not sealed enum type |
| 2 | OnHeartBeat is the only creature AI tick | **Overstated** — Driver uses DoLogic; HB list may host other types |
| 3 | `AI_CheckSlotTimerReady` is weapon cooldown only | **Fragile** — stride/offset shared with generic timer array; skill slots too |
| 4 | Idle path always “return home” | **Incomplete** — compound of FUN_005cd220 / vtbl+0x54 / position latch |
| 5 | Plate offset table is authoritative | **Partial** — decomp shows overlapping word/byte views; +0x6 vs +0x18 owner confusion in older notes |

---

## 2. Surviving contract for AutoCore

```
CreatureBase_OnHeartBeat:
  if no owner -> default HB status
  if no target and no vehicle -> reschedule; return
  clear stale idle flags on timer
  branch behavior on owner state (+0x26c family):
    patrol/leash helpers vs engage timers vs combat fire/pursue
  gate combat pulses with AI_CheckSlotTimerReady
  reschedule HB period
```

Server port should **not** copy client-only discovery tick coupling without a separate sim schedule.

---

## 3. Open questions

1. Seal `owner+0x26c` enum and transitions from SetState vtbl+0x2c callers.
2. Name FUN_005cc* / FUN_005cd* via Ghidra decompile (no disassemble_bytes).
3. Confirm timer array layout vs `AI_CheckSlotTimerReady` (+0x70 stride 0xC vs +0x1e flags).
4. Runtime: one creature idle→engage→combat capture with state byte log.

**Verdict:** Usable creature AI tick map; helper identity and flag polarities need more evidence before parity work.
