# Dual A/B — `aa_00507950` CVOGHBList_Tick

**Date:** 2026-07-29  
**Owned VA:** `0x00507950` only  
**Tools:** Ghidra `decompile_function` / `batch_decompile` / `get_function_callers` / `get_function_xrefs` / `read_memory` (no Launcher; no WORK_QUEUE/RESUME/ACTIVE_WORK/CHANGE_LOG)  
**Verdict:** **accept-with-gaps**

Prior shallow duals (2026-07-23 wave3 CVOGHB batch) replaced with CF+layout+caller seal. **Promote-pending residual closed.**

---

## Sealed facts

### Role

| Fact | Evidence |
|---|---|
| Map-owned HB list **frame advance** | Live decompile; plate `CVOGHBList_Tick` |
| Updates **`g_dwClientTickMs`** then TryFire actives then promote pending | Body order |
| Scheduler shell only — period/regen math not here | TryFire / Regeneration siblings |
| List at **client `+0xd38`** | Both callers |

### Signature

```c
void __thiscall CVOGHBList_Tick(void *this /*CVOGHBList**/, int nForcedDeltaMsOrNull);
// 0 → GetTickCount(); else g_dwClientTickMs += delta
```

### Tick source

| Path | Behavior |
|---|---|
| `nForcedDeltaMsOrNull == 0` | `g_dwClientTickMs = GetTickCount()` |
| else | `g_dwClientTickMs += nForcedDeltaMsOrNull` |

**Live callers (exactly 2):** both pass **`0`**.

| Caller | Call site | Args |
|---|---|---|
| `FUN_0093e010` | `0x0093e084` | `Tick(*(void**)(client+0xd38), 0)` when `client+0xa1 != 0` |
| `FUN_0094b520` | `0x0094b62b` | same; main frame when `+0xb7` and `+0xa1==0` |

### List layout

| Off | Field |
|---|---|
| `+0x04` | `CRITICAL_SECTION` (spin 4000 from ctor) |
| `+0x1c` | active `CVOGHBBase**` |
| `+0x20` | active count |
| `+0x24` | active cap raw (`& 0x7fffffff`) |
| `+0x28` | pending `CVOGHBBase**` |
| `+0x2c` | pending count |
| `+0x30` | pending cap raw |

### Active loop

```
for i while i < activeCount:
  status = active[i]->vtbl[+8] TryFire(out)   // outside CS
  if (status & 0x10) == 0: i++                // Continue / Inactive keep
  else under CS:
    activeCount--
    active[i] = active[activeCount]           // swap-remove; re-process hole
    if HB.cStopped (+0x20) == 0: vtbl[+0x18](1,1)
    HB.refCount (+0x04)++
    vtbl[0](1)                                // deleting dtor
```

| Status | Value | Tick effect |
|---|---|---|
| Continue | `0` | keep, `i++` |
| Inactive | `2` | keep, `i++` (dormant) |
| Remove | `0x10` (16) | swap-pop + destroy |

**Sealed:** test is **bit mask** `& 0x10`, not equality-only. Value 16 is Remove token / shared with `g_dwTimedActionDefaultPeriodMs` — **not** combat regen period (3000/5000).

### Promote pending (prior residual — **closed**)

```
EnterCS
for j in 0..pendingCount-1:
  if activeCount == (activeCap & 0x7fffffff): FUN_005b3370(&active, 4)
  active[activeCount++] = pending[j]
pendingCount = 0
LeaveCS
```

Enqueue only writes pending; Start only clears `fDormant`. Both required for first fire after create.

### Global

| Symbol | VA | Role |
|---|---|---|
| `g_dwClientTickMs` | `0x00b041cc` | written by Tick; read by TryFire / many systems |

### Contract for AutoCore

```
HBList_Tick(list, forcedDeltaOr0):
  advance g_dwClientTickMs
  TryFire each active; remove status&0x10 via swap-pop under lock
  promote Enqueue pending → active under lock
// combat regen / cast-again / mission patrol ride this client list
// server may use a different scheduler — do not assume client Tick is authority
// do not treat 16 as combat-pool period
```

---

## Gaps

1. Product English for **vtbl+0x18** pre-dtor when `cStopped==0`.
2. Extra status bits beyond 0 / 2 / 0x10 (mask allows composites).
3. Forced-delta producers outside static 2-caller set.
4. Product name of client field `+0xd38` owner type.
5. Runtime population capture; bit-exact; image diff.
6. Thread affinity model beyond “CS present.”

---

## Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00507950_CVOGHBList_Tick.md` | accept-with-gaps |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00507950_CVOGHBList_Tick.md` | accept-with-gaps |

Prior 2026-07-23 duals understated promote-pending (now sealed High).

---

## Files touched / authoritative

| Role | Absolute path |
|---|---|
| Dual A | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\A_aa_00507950_CVOGHBList_Tick.md` |
| Dual B | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\B_aa_00507950_CVOGHBList_Tick.md` |
| Function record | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_00507950_CVOGHBList_Tick.md` |
| Raw | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_00507950_CVOGHBList_Tick.md` (re-verify append) |
| Annotated | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_00507950_CVOGHBList_Tick.annotated.md` |
| Clean | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\CVOGHBList_Tick.cpp` |
| Matrix row | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\VERIFICATION_MATRIX.md` |
| This report | `C:\Users\josh\Documents\GitHub\AutoCore\docs\agents\task-dual-ab-00507950-cvoghb-list-tick-report.md` |

No WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG edits. No Launcher.
