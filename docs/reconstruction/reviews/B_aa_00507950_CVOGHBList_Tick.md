# Review B (skeptical / adversarial): `aa_00507950` CVOGHBList_Tick

| Field | Value |
|---|---|
| **Stable ID** | `aa_00507950` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00507950_CVOGHBList_Tick.md` |
| **Verdict** | **accept-with-gaps** on CF; prior "promote tail residual" **closed** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Only uses wall clock | Forced `nForcedDeltaMsOrNull != 0` adds to `g_dwClientTickMs` | **Falsified** for exclusive wall-clock — but **both live callers pass 0** |
| 2 | Remove is `status == 16` equality only | Body uses `(*status & 0x10) == 0` | **Falsified** equality-only; 16 still is Remove token from TryFire/cStopped |
| 3 | No pending queue | Promote loop `+0x28/+0x2c` after active | **Falsified** |
| 4 | Promote-pending CF unfinished / open residual (2026-07-23 A/B) | Live decompile shows full promote + grow + clear | **Falsified open residual** — **sealed High** |
| 5 | Inactive removes entry | Inactive=2 has bit0x10 clear → `i++` keep | **Falsified** |
| 6 | TryFire runs under CS | CS only around remove + promote | **Falsified** |
| 7 | 16 ms is combat regen period | Shared token is Remove status / reschedule delay; regen periods 3000/5000 | **Falsified** (cross-unit TryFire/Regeneration) |
| 8 | Start alone arms the list | Start clears dormant only; Enqueue → pending → Tick promote | **Falsified** Start-as-enqueue |
| 9 | Finished exact dtor rules | vtbl+0x18 gated on `cStopped==0` then always `ref++` + vtbl0(1) | **Overstated** product names; CF sealed |
| 10 | Forced delta is production path | Callers `FUN_0093e010`, `FUN_0094b520` both pass **0** | **Overstated** as live path; static path remains |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Remove bit 0x10 swap-pop | **High** | Leaked / double-free HB |
| Promote pending full CF | **High** | Start/Enqueue never arms |
| Active TryFire outside CS | **High** | Race model wrong for server port |
| Inactive keeps entry | **High** | Premature free of dormant HBs |
| Live delta always 0 | **High** (2 xrefs) | Missed sim/tool caller |
| vtbl+0x18 English | **Low** | Wrong lifecycle port |
| Thread model beyond CS | **Low** | Deadlocks if ported naively |

---

## 3. Cross-check against live decompile (2026-07-29)

```
if delta==0: tick=GetTickCount else tick+=delta;
foreach active: TryFire(out); if status&0x10: CS swap-pop + optional vtbl+0x18 + dtor;
CS: append pending→active (grow if full); pendingCount=0; LeaveCS.
```

Clean ≡ raw ≡ live Ghidra CF. Prior shallow duals understated promote (full loop + `FUN_005b3370` + count clear present).

**Callers:**

| Caller | Site | Call |
|---|---|---|
| `FUN_0093e010` | `0x0093e084` | `CVOGHBList_Tick(*(void**)(client+0xd38), 0)` when `client+0xa1 != 0` |
| `FUN_0094b520` | `0x0094b62b` | same list, `0`, under frame path when `+0xb7` and `+0xa1==0` |

No third static caller within `limit=50` xrefs.

---

## 4. Surviving contract for AutoCore

```
// Client map heartbeat list (not sector authority by default)
HBList_Tick(list, forcedDeltaOr0):
  advance g_dwClientTickMs   // wall or forced
  for each active HB:
    status = TryFire(hb)     // may OnHeartBeat; may return Inactive without fire
    if status & Remove(0x10): swap-remove + destroy
  promote Enqueue-pending → active under lock
  clear pending count

// Port notes:
// - combat regen / OKToCastAgain / MissionPatrol ride this list
// - do NOT treat 16 as combat-pool period (use 3000/5000 from Regeneration ctor)
// - Enqueue + Start both required for first fire (Start clears dormant; Enqueue queues)
// - server may own a different scheduler; client Tick is local sim
```

---

## 5. Open questions (residual only)

1. Product name of **vtbl+0x18** when removing non-stopped HB.
2. Extra status bits beyond Continue/Inactive/Remove (mask-only test).
3. Forced-delta producers outside static call graph.
4. Runtime capture of list population during combat / cast-again.
5. Bit-exact / image diff.

**Verdict:** **accept-with-gaps** on CF; promote-pending residual **closed**; product English + runtime remain open
