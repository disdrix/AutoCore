# Review B (skeptical / adversarial): `CVOGHBBase_AppendRemainingText` / `FUN_00578550` @ `0x00578550`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00578550` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00578550_CVOGHBBase_AppendRemainingText.md` |
| **Verdict** | **accept-with-gaps** on CF/ABI/cascade; reject replace-vs-append and period-vs-counter sentinel confusions |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Overwrites dest from start (strcpy) | **Falsified** — walks dest to NUL then copies |
| 2 | Gates on `nPeriodSentinel (+0x0C) == -1000` | **Falsified** — bytes compare **`[this+0x10]`** (nPeriodCounter) |
| 3 | cdecl / plain ret | **Falsified** — **`ret 0x10`** thiscall |
| 4 | Always formats seconds only | **Falsified** — day/hour/min cascade with scales |
| 5 | Scale constants are “E.B7” string data misread | **Falsified as blocker** — float `1/86400` shares bytes with ASCII view; numeric decode sealed |
| 6 | enable formal unused | **Falsified** — first gate on Stack[0x10] |
| 7 | Returns remaining seconds float | **Falsified** — returns bool AL |
| 8 | Product name sealed | **Open** |
| 9 | Quantize leaves bit-exact | **Open** / residual |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + ret 0x10 | **Confirmed** | Stack smash |
| Append not replace | **Confirmed** | Tooltip wipe |
| Counter -1000 gate (not sentinel field) | **Confirmed** | Wrong skip for combat pool |
| Thresholds / scales | **Confirmed** | Wrong unit bucket |
| Unit string keys | **Confirmed** | Loc miss |
| Quantize exact | **Medium** | Display off-by-0.01/0.1 |
| Unused middle formals | **Low** (unused) | Docs only |
| Product C++ name | **Open** | Docs only |

---

## 3. Surviving contract for AutoCore

```
// __thiscall; ret 0x10
uint8_t CVOGHBBase_AppendRemainingText(self, char* dest, void*, void*, char enable):
  if !enable or self->nPeriodCounter == -1000: return 0
  rem = GetRemainingSeconds(self)   // float seconds
  if rem > 86400:  val = quant2(rem/86400); unit="days"
  elif rem > 3600: val = quant1(rem/3600);  unit="hrs"
  elif rem > 60:   val = quant1(rem/60);    unit="min"
  else:            val = rem;               unit="sec"; fmt=%.0f
  sprintf(buf, fmt, val, loc(unit), loc("Remaining"))
  strcat(dest, buf)
  return 1

// NOT strcpy. NOT period-sentinel@+0x0C. NOT float return.
// Thunk FUN_005786f0 always enable=1.
```

---

## 4. Falsification notes

### 4.1 Sentinel field mix-up

`SetPeriodAndCounter(-1000)` writes both `+0x0C` and often `+0x10`. This body only reads **`+0x10`**. Ports that gate on `nPeriodSentinel` alone can diverge if fields ever desync.

### 4.2 Threshold inequality direction

Decompiler uses `<=` tree equivalent to exclusive upper bounds via inverted `jbe`/`ja` structure: remaining **exactly 86400** takes the non-day path (≤86400). Scale path for days is **strictly greater than 86400**. Same pattern for 3600 and 60. Ports using `>= 86400` for days shift the boundary.

### 4.3 Float/string alias at `0x009d3fc0`

Bytes `45 2e 42 37` decode as float ≈ `1/86400` **and** ASCII `E.B7` before `"Remaining"`. Adversarial take: do not treat as string load; mulss consumes float.

---

## 5. Open questions

1. Retail symbol.
2. Why four stack formals when only dest+enable used (vtable width?).
3. Full dual of quantize helpers.
4. Runtime golden tooltips.

**Verdict:** **accept-with-gaps** on sealed CF, thiscall/`ret 0x10`, append semantics, unit cascade. Reject strcpy / wrong-sentinel / float-return overclaims.