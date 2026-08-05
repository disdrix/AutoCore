# Review B (skeptical / adversarial): `aa_00785e00` Profiler_StartZoneTimer

| Field | Value |
|---|---|
| **Stable ID** | `aa_00785e00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00785e00_Profiler_StartZoneTimer.md` |
| **Verdict** | **accept-with-gaps** on CF; reject listed false claims |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Free function with no operand | Decompiler `in_EAX`; enter leaves zone in **EAX** | **Falsified** “no operand” |
| 2 | Clears entire timer including divisor | No stores to `pDVar1[4]`/`[5]` (`+0x10/+0x14`) | **Falsified** |
| 3 | Stack `this` / ECX zone | ECX not used; **EAX** only | **Falsified** |
| 4 | Domain / mission helper | Only nest++, zero counters, QPC | **Falsified** |
| 5 | Accumulates elapsed time | **Start** only; stop is `FUN_00780690` | **Falsified** |
| 6 | Writes hierarchical total `zone+0x28` | Only nest at `+0x3c` and timer fields | **Falsified** |
| 7 | Many call sites | Bulk xrefs: **one** (`0x00786a33`) | **Confirmed single** |
| 8 | Scaffold “void()” port without EAX note | Would call with wrong zone / garbage | **Overstated** if ABI omitted |
| 9 | Runtime sealed | Static only | **Fail** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX zone ABI | **High** | Times wrong node / AV |
| Field zero list | **High** | Sticky last/max |
| Divisor preserved | **High** | Scale blow-up if zeroed by mistake |
| QPC start | **High** | Leave delta wrong |
| Nest++ | **High** | Accounting only |
| µs divisor from ctor | **High** (other unit) | Unit mislabel if ignored |
| Nest lifetime semantics | **Med** | No matching -- seen on leave |

---

## 3. Cross-check

| Item | Result |
|---|---|
| Raw ≡ live decompile | **Yes** |
| Enter: `CALL FindOrCreate` → `MOV EDI,EAX` → `CALL Start` | EAX still zone at call (EDI copy; EAX not clobbered before call) |
| Inline twin in `0x007866e0` | Same zero set + QPC — reinforces field list |

---

## 4. Surviving contract for AutoCore

```
// After zone = FindOrCreateChild(...):
//   StartZoneTimer(zone)  // register EAX
// Must pair with Leave → QpcAccumulate(timer) for exclusive sample.
```

**Falsified port mistakes:**

- Calling with no zone / wrong register.
- Zeroing divisor on start.
- Treating as leave/stop.

---

## 5. Open questions

1. Nest counter consumers / decrement sites.
2. Whether start is valid if timer* null (ctor always sets).
3. Runtime QPC monotonicity under suspend.

**Verdict:** **accept-with-gaps** — start timer sealed; single enter caller.
