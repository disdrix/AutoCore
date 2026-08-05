# Review A (reconstruction fidelity): `aa_00507950` CVOGHBList_Tick

| Field | Value |
|---|---|
| **Stable ID** | `aa_00507950` |
| **VA** | `0x00507950` |
| **Canonical name** | `CVOGHBList_Tick` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (HB list frame advance) |
| **Counterpart** | `reviews/B_aa_00507950_CVOGHBList_Tick.md` |
| **System** | `heartbeat` / timed-actions (skills combat-pool / cast-again / regen ride this list) |
| **Verdict** | **accept-with-gaps** (CF + layout + promote sealed; product English / runtime open) |

---

## 1. Purpose

Advance one map-owned **CVOGHBList** frame:

1. Update global **`g_dwClientTickMs`** (`0x00b041cc`): if `nForcedDeltaMsOrNull==0` → `GetTickCount()`, else **add** forced delta (sim/test hook).
2. For each **active** HB (`+0x1c` / count `+0x20`): call **vtbl+8 TryFire** with out-status on stack; if `*status & 0x10` → **Remove** (swap-pop + destroy under CS at `+0x04`); else advance index.
3. Under same CS: **promote all pending** (`+0x28` / count `+0x2c`) into active (grow via `FUN_005b3370` when full), then zero pending count.

Not a combat regen period driver — only the scheduler shell. Period math lives in `CVOGHBBase_TryFire` / subclass `OnHeartBeat`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00507950_CVOGHBList_Tick.md` |
| Annotated | `docs/reconstruction/raw/aa_00507950_CVOGHBList_Tick.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBList_Tick.cpp` |
| Function record | `docs/reconstruction/functions/aa_00507950_CVOGHBList_Tick.md` |
| Sibling | `CVOGHBList_Enqueue` `0x005078f0`, `CVOGHBList_ctor`, `CVOGHBBase_TryFire` `0x005082c0`, grow `FUN_005b3370` |
| Live Ghidra | `decompile_function` `0x00507950`; `batch_decompile` Enqueue/TryFire/ctor/grow/Start/Reschedule; `get_function_callers` / `get_function_xrefs`; `read_memory` `0x00b041cc` |
| Callers (2) | `FUN_0093e010` @ `0093e084`, `FUN_0094b520` @ `0094b62b` — both `Tick(client+0xd38, 0)` |

---

## 3. Signature

```c
// MSVC __thiscall
void __thiscall CVOGHBList_Tick(
    void *this,                 // CVOGHBList*
    int   nForcedDeltaMsOrNull  // 0 → GetTickCount wall clock; else g_dwClientTickMs += delta
);
```

**Live callers:** both production sites pass **`0`**. Forced-delta path is static-sealed but **unused** by known xrefs (sim/test residual).

Decompiler reuses the `nForcedDeltaMsOrNull` stack slot as TryFire's **out-status** buffer after the tick update — that is **not** passing delta into TryFire.

---

## 4. Layout (list) — sealed from Tick + Enqueue + ctor

| Offset | Field | Evidence |
|---|---|---|
| `+0x00` | vtbl | ctor `PTR_FUN_009cda94` |
| `+0x04` | `CRITICAL_SECTION` | Enter/Leave; ctor `InitializeCriticalSectionAndSpinCount(..., 4000)` |
| `+0x1c` | active `CVOGHBBase**` buf | Tick TryFire loop; grow slot |
| `+0x20` | active count (int) | loop bound / swap-remove |
| `+0x24` | active cap raw (`& 0x7fffffff`) | full → `FUN_005b3370(+0x1c, 4)` |
| `+0x28` | pending `CVOGHBBase**` buf | Enqueue write; Tick promote read |
| `+0x2c` | pending count | Enqueue ++; Tick promote then **= 0** |
| `+0x30` | pending cap raw | Enqueue grow only |

Ctor seeds active/pending cap words to **`0x80000000`** (count 0, high bit set); min grow targets active ≥1000 / pending ≥100 elements.

---

## 5. Control flow (sealed)

```
if nForcedDeltaMsOrNull == 0:
    g_dwClientTickMs = GetTickCount()
else:
    g_dwClientTickMs += nForcedDeltaMsOrNull

i = 0
while i < activeCount:
    hb = active[i]
    status = hb->vtbl[+8] TryFire(out)     // out on stack (decomp reuses delta slot)
    if (*status & 0x10) == 0:             // Continue(0) or Inactive(2) etc.
        i++
    else:                                 // Remove (bit 0x10 / value 16)
        EnterCS(this+4)
        activeCount--
        active[i] = active[activeCount]   // swap-remove; do NOT i++
        if hb->cStopped (+0x20) == 0:
            hb->vtbl[+0x18](1, 1)         // pre-dtor path when not already stopped
        hb->refCount (+0x04)++
        hb->vtbl[+0](1)                   // scalar deleting dtor
        LeaveCS

EnterCS(this+4)
for j in 0 .. pendingCount-1:
    if activeCount == (activeCap & 0x7fffffff):
        FUN_005b3370(&activeBuf, 4)       // double grow, elem size 4
    active[activeCount++] = pending[j]
pendingCount = 0
LeaveCS
return
```

### Remove path details (High)

| Claim | Confidence |
|---|---|
| Test is **`(*status & 0x10) == 0`**, not equality to 16 only | **High** |
| Swap-remove leaves hole filled by last; **same index re-fired** next iter | **High** |
| Destroy under CS; TryFire itself runs **outside** CS | **High** |
| `cStopped==0` → extra **vtbl+0x18(1,1)** before always dtor | **High** (product name open) |
| `refCount++` then `vtbl[0](1)` = MSVC deleting dtor pattern | **High** |

### Promote-pending (High — closed prior residual)

| Claim | Confidence |
|---|---|
| Entire pending batch promotes in one CS section after active loop | **High** |
| Order preserved: pending[0]..[n-1] append to active | **High** |
| Grow uses same `FUN_005b3370` as Enqueue, element size **4** | **High** |
| Pending count cleared; buffer contents not zeroed | **High** |
| Enqueue only writes pending; **Start alone does not arm list** | **High** (cross-unit) |

### Inactive / Continue

| Status | Value | Tick behavior |
|---|---|---|
| Continue | `0` | keep entry, `i++` |
| Inactive | `2` (from TryFire when `fDormant`) | keep entry, `i++` (**not** remove) |
| Remove | `0x10` / 16 | pop + destroy |

**Sealed:** Inactive keeps the HB in the active array without calling destroy. Start must clear dormant before fires occur.

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Tick source GetTickCount vs forced delta | **High** | body |
| Live callers always pass 0 | **High** | 2 xrefs |
| List at client object `+0xd38` | **High** | both callers |
| Active / pending dual vectors + CS | **High** | Tick+Enqueue+ctor |
| TryFire via vtbl+8 | **High** | call site |
| Remove bit 0x10 → swap-pop + dtor | **High** | body |
| Promote pending after active loop under CS | **High** | body (prior gap closed) |
| `g_dwClientTickMs` @ `0x00b041cc` | **High** | skill-cast map + ctor/tick |
| vtbl+0x18 product name | **Low** | OnEnd/Stop **INFERRED** only |
| Forced-delta runtime use | **Low** | no live callers |

---

## 7. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Tick update | **Yes** |
| TryFire loop + swap-remove | **Yes** |
| Pending promote + clear | **Yes** |
| CS enter/leave pairs | **Yes** |

---

## 8. Gaps / open

1. Product English for **vtbl+0x18** pre-dtor (OnEnd vs Stop vs other).
2. Whether OnHeartBeat can return composite status with extra bits beyond 0x10 (mask test allows it).
3. Thread affinity / which threads Enqueue vs Tick (CS implies multi-thread possible).
4. Forced-delta callers outside static xrefs (tests, tools).
5. Runtime / bit-exact / image diff.
6. Full client object type at `+0xd38` product name.

**Verdict:** **accept-with-gaps**
