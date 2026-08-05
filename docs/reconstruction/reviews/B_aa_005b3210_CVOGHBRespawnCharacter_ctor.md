# Review B (skeptical / adversarial): `aa_005b3210` CVOGHBRespawnCharacter_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b3210` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W23-S) |
| **Counterpart** | `reviews/A_aa_005b3210_CVOGHBRespawnCharacter_ctor.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Is a skill-HB ctor | **Falsified** — RTTI `CVOGHBRespawnCharacter`; alloc 0x24 not 0x6c0; no skill blob |
| 2 | SetPeriod(1,true) is the real pulse | **Falsified** — period dual writes `+0x0C/10` only; pulse is `+0x08 = param_3` |
| 3 | Always attaches raw `param_2` | **Falsified** — non-null path uses this-adjust expression |
| 4 | Multiple production callers | **Falsified** — `get_function_callers` sole `00802170` |
| 5 | Starts / enqueues itself | **Falsified** — ctor only; caller Enqueue+Start |
| 6 | Class name uncertain | **Falsified** — RTTI string Confirmed |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Ctor CF + RTTI name | **Confirmed** | Wrong death-timer type |
| Period layout split | **High** | 5-min timer miswired to sentinel field |
| Sole death-UI caller | **High** | Invented extra spawn sites |
| Fire-path semantics | **Open** | Port may stub OnHeartBeat incorrectly — not this unit's body |

---

## 3. Cross-check

```
raw: base; vtbl 009d957c; SetPeriod(1,true); [2]=period; attach null/adjust
live: identical
bytes: push1 push1 SetPeriod; mov [esi+8]; test/jz null attach; lea adjust attach; ret 8
RTTI: COL 00aaffac → ".?AVCVOGHBRespawnCharacter@@"
caller 00802170: new(0x24); FUN_005b3210(client+0xe98, 300000); Enqueue; Start
```

---

## 4. Surviving contract for AutoCore

```
CVOGHBRespawnCharacter_ctor(this, pObject, periodMs):
  CVOGHBBase_ctor(this)
  this.vtbl = CVOGHBRespawnCharacter_vtbl
  SetPeriodAndCounter(this, 1, true)   // +0x0C and +0x10 = 1
  this.pulsePeriodMs = periodMs        // +0x08
  AttachOwner(this, pObject ? this_adjust(pObject) : null)
  return this
```

Port local death as **schedule a 300000 ms respawn HB** on the client HB list — construct, enqueue, start. Do not fold skill-cast machinery into this class.

---

## 5. Open questions

OnHeartBeat body residual (what fires at pulse) — out of this unit; does not block ctor seal.

**Verdict:** **accept**
