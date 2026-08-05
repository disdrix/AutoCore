# Review B (skeptical / adversarial): `AI_CheckSlotTimerReady` @ `0x005cced0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_005cced0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005cced0_AI_CheckSlotTimerReady.md` |
| **Verdict** | **accept-with-gaps** on CF/layout; **needs-more-evidence** on slot taxonomy / object type |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Three-arg thiscall `(this, pAiCtx, nSlotIndex)` | Decomp invents unused formal; body `RET 4`; all sites one push | **Falsified** — 2-arg thiscall only |
| 2 | `pAiCtx` is AI context pointer | Always used as integer index (`*0xC`, `*3`) | **Falsified** — slot index |
| 3 | Function is weapon-cooldown only | Callers: slot **0** (driver/HB combat pulses) **and** slot **2** (skill set) | **Fragile / overstated** — generic timer bank |
| 4 | Ready means “may fire now” end-to-end | Only sets flag + returns AL; no stamp, no cast, no validation | **Partial** — local gate only |
| 5 | Compare is `elapsed >= period` | Body `JBE` → equal is **not** ready; need strict `>` | **Corrected** — `elapsed > period` |
| 6 | Flag at “`(i*3+0x1e)*4`” is a separate array | Algebra collapses to `this+i*0xC+0x78` = same slot `+0x08` | **Unified** with timer record |
| 7 | Returns full `uint` meaning | Callers only `TEST AL` / store byte | **Overstated** — bool AL contract |
| 8 | `g_dwClientTickMs` always real wall ms | Plate notes forced delta path in list tick | **Open** — name sealed; timebase policy external |
| 9 | Unsigned wrap on `tick − last` is defined product policy | dword `SUB` then unsigned `CMP`/`JBE`; wrap ⇒ large elapsed ⇒ ready | **Open** (no clamp in body) |
| 10 | System = inventory-transfer | Zero inventory CF; pure AI timer | **Falsified** — npc-ai/HBAI |

---

## 2. Surviving contract for AutoCore

```
AI_CheckSlotTimerReady(hbai, slotIndex) -> bool AL:
  last   = hbai.slot[slotIndex].lastStampMs     // +0x70 + i*0xC
  period = hbai.slot[slotIndex].periodMs        // +0x74 + i*0xC
  if (g_dwClientTickMs - last) > period:
    hbai.slot[slotIndex].readyFlag = 1          // +0x78 + i*0xC
    return true
  return false
  // does NOT update last/period; does NOT clear readyFlag on miss
```

Server port notes:

- Need a **sim-time** source equivalent to `g_dwClientTickMs` (do not invent client GetTickCount coupling).
- Slot index **0** vs **2** are product conventions from callers — do not hard-map “weapon” without reschedule writers.
- Gate is **necessary but not sufficient** for fire/cast (callers stack more checks).

---

## 3. What this unit does **not** prove

1. How many slots exist / max legal `nSlotIndex`.
2. Writer(s) of last stamp + period (reschedule after fire family).
3. Clear / init of ready flag.
4. English product name of owning class (HBAI base vs creature vs driver controller).
5. Whether slot 1 (and others) are used in production paths.

---

## 4. Cross-check vs sibling dual notes

`B_aa_005d0310` already flagged: “`AI_CheckSlotTimerReady` is weapon cooldown only” as **Fragile** — this dual **confirms** that attack via slot-2 skill-set caller.

Timer array layout residual from that dual (`+0x70` stride `0xC` vs `+0x1e` flags) is **resolved** here: flag is `+0x78` = third dword of the same record, not a separate bank.

---

## 5. Open questions (residual)

1. Seal stamp/period writers (`CVOGHBBase_RescheduleAfterFire` and kin) against `+0x70/+0x74`.
2. Enumerate all store sites to `this+i*0xC+0x78`.
3. Map fixed indices 0/2 to data-driven skill/weapon banks with runtime or data RE.
4. Confirm signedness of last stamp loads under tick wrap (stress / long uptime).

**Verdict:** Body is a faithful, leaf cooldown **predicate + ready latch**. Do not overfit weapon-only semantics. **accept-with-gaps.**
