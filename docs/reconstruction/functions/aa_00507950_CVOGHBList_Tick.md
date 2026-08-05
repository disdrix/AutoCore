# Function record: CVOGHBList_Tick

| Field | Value |
|---|---|
| **Stable ID** | `aa_00507950` |
| **Canonical name** | `CVOGHBList_Tick` |
| **Address** | `0x00507950` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `heartbeat` / timed-actions |
| **Completion status** | **Partial** — dual A/B strengthened 2026-07-29; CF+layout+promote **High**; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00507950_CVOGHBList_Tick.md` · `reviews/B_aa_00507950_CVOGHBList_Tick.md` → **accept-with-gaps** |

## Purpose

Frame advance for a map-owned heartbeat list: update `g_dwClientTickMs`, TryFire every active HB, destroy Remove (`status & 0x10`) via swap-pop under critical section, then promote Enqueue pending into active under the same CS.

## Signature (decompiler + callers)

```c
void __thiscall CVOGHBList_Tick(void *this /*CVOGHBList**/, int nForcedDeltaMsOrNull);
// nForcedDeltaMsOrNull == 0 → g_dwClientTickMs = GetTickCount()
// else g_dwClientTickMs += nForcedDeltaMsOrNull
// Live callers both pass 0.
```

## Layout (CVOGHBList)

| Off | Field |
|---|---|
| `+0x04` | `CRITICAL_SECTION` |
| `+0x1c` / `+0x20` / `+0x24` | active buf / count / cap-raw |
| `+0x28` / `+0x2c` / `+0x30` | pending buf / count / cap-raw |

## Globals

| Symbol | VA | Role |
|---|---|---|
| `g_dwClientTickMs` | `0x00b041cc` | shared client tick ms (written here; read by TryFire / physics / AI timers) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00507950_CVOGHBList_Tick.md`
- Annotated: `docs/reconstruction/raw/aa_00507950_CVOGHBList_Tick.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBList_Tick.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00507950_CVOGHBList_Tick.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00507950_CVOGHBList_Tick.md`
- Report: `docs/agents/task-dual-ab-00507950-cvoghb-list-tick-report.md`

## Callers / callees

**Callers (static, High):**

| Address | Function | Notes |
|---|---|---|
| `0x0093e084` | `FUN_0093e010` | `Tick(*(void**)(client+0xd38), 0)` when `client+0xa1 != 0` |
| `0x0094b62b` | `FUN_0094b520` | same list/args; main frame path when focused / not alt mode |

**Callees:**

| Target | Role |
|---|---|
| `GetTickCount` | wall clock when delta==0 |
| `CVOGHBBase` vtbl+8 (`TryFire`) | per active entry |
| `EnterCriticalSection` / `LeaveCriticalSection` | remove + promote |
| vtbl+0x18 (when `cStopped==0`) | pre-dtor lifecycle **INFERRED** |
| vtbl+0 deleting dtor | free HB |
| `FUN_005b3370` | grow active vector (elem size 4) |

## Related units

- `aa_005078f0` `CVOGHBList_Enqueue` — pending append under CS
- `aa_005082c0` `CVOGHBBase_TryFire` — status Continue/Inactive/Remove
- `aa_005081c0` `CVOGHBBase_Start` — clear dormant (not enqueue)
- `aa_00508200` `CVOGHBBase_ctor` — dormant=1, lastFire=tick, cStopped=0

## Confidence

| Claim | Level |
|---|---|
| Control flow from live decompiler | **High** |
| Dual-vector layout + CS | **High** |
| Promote-pending full CF | **High** (2026-07-29 seal) |
| Live callers pass delta 0 | **High** |
| Parameter semantic names | **High** (plate + CF) |
| vtbl+0x18 product name | **Low / INFERRED** |
| Types (full CVOGHBBase) | **Partial** (offsets from ctor/TryFire) |

## Sealed facts (summary)

1. Tick updates global tick then walks active array.
2. Remove = status bit `0x10`; swap-remove without index advance.
3. Inactive (2) keeps entry.
4. Pending fully promotes after active loop; count cleared.
5. Production frame always uses GetTickCount path (delta 0).
