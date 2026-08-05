# Review A (reconstruction fidelity): `aa_005078f0` CVOGHBList_Enqueue

| Field | Value |
|---|---|
| **Stable ID** | `aa_005078f0` |
| **VA** | `0x005078f0` |
| **Canonical name** | `CVOGHBList_Enqueue` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_005078f0_CVOGHBList_Enqueue.md` |
| **System** | `heartbeat` / map-owned timed-action list |
| **Verdict** | **accept** (CF + layout sealed; residual: product type names only) |

---

## 1. Purpose

Thread-safe **append** of a `CVOGHBBase*` into the list's **pending** pointer array (not active). Later `CVOGHBList_Tick` (`0x00507950`) promotes pending → active under the same CS. Null action → HRESULT **`E_INVALIDARG` `0x80070057`**; success → **`0`**.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Live decompile | Ghidra MCP `decompile_function` @ `0x005078f0` |
| Grow helper | Ghidra MCP `decompile_function` @ `0x005b3370` |
| List ctor (layout seed) | Ghidra MCP `decompile_function` @ `0x00507d10` |
| Raw | `docs/reconstruction/raw/aa_005078f0_CVOGHBList_Enqueue.md` |
| Annotated | `docs/reconstruction/raw/aa_005078f0_CVOGHBList_Enqueue.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBList_Enqueue.cpp` |
| Function record | `docs/reconstruction/functions/aa_005078f0_CVOGHBList_Enqueue.md` |
| Sibling Tick | `docs/reconstruction/reconstructed-exact/CVOGHBList_Tick.cpp` |

---

## 3. Authoritative body (Ghidra 2026-07-29)

```c
uint __thiscall CVOGHBList_Enqueue(void *this, CVOGHBBase *pAction)
{
  if (pAction != (CVOGHBBase *)0x0) {
    EnterCriticalSection((LPCRITICAL_SECTION)((int)this + 4));
    if (*(uint *)((int)this + 0x2c) == (*(uint *)((int)this + 0x30) & 0x7fffffff)) {
      FUN_005b3370((int *)((int)this + 0x28), 4);
    }
    *(CVOGHBBase **)(*(int *)((int)this + 0x28) + *(int *)((int)this + 0x2c) * 4) = pAction;
    *(int *)((int)this + 0x2c) = *(int *)((int)this + 0x2c) + 1;
    LeaveCriticalSection((LPCRITICAL_SECTION)((int)this + 4));
    return 0;
  }
  return 0x80070057;
}
```

Body range: `0x005078f0`–`0x00507946`. Convention: MSVC **`__thiscall`**.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Null `pAction` → `0x80070057` (`E_INVALIDARG`) | **High** | Exact constant in body |
| Success return `0` | **High** | HRESULT-style |
| CS at `this+0x04` | **High** | Enter/Leave; ctor `InitializeCriticalSectionAndSpinCount(this+4, 4000)` |
| Pending buf `+0x28`, count `+0x2c`, cap-raw `+0x30` | **High** | Enqueue + ctor `param_1[10..12]` |
| Cap compare uses `cap & 0x7fffffff` | **High** | High bit is alloc-sentinel (ctor seeds `0x80000000`) |
| Grow when `count == (cap & 0x7fffffff)` | **High** | Full or both-zero first push |
| Grow `FUN_005b3370(this+0x28, elementSize=4)` | **High** | Pointer-array elements |
| Grow policy: **double count (≡ cap when full), or 1 if 0** | **High** | Sealed from `FUN_005b3370`; copies old elems; frees old only if `(int)cap >= 0` |
| Store is **pending only** — not active `+0x1c/+0x20` | **High** | Tick promotes pending→active |
| Clean CF ≡ raw | **High** | Clean re-reads count after grow (count unchanged by grow) |

---

## 5. Layout (list object — sealed subset)

| Offset | Role |
|---|---|
| `+0x00` | vtable (`PTR_FUN_009cda94` from ctor) |
| `+0x04` | `CRITICAL_SECTION` (spin 4000) |
| `+0x1c` | active `CVOGHBBase**` buffer |
| `+0x20` | active count |
| `+0x24` | active capacity raw (`& 0x7fffffff`; high bit = no-owned-heap sentinel) |
| `+0x28` | **pending** `CVOGHBBase**` buffer |
| `+0x2c` | **pending** count (Enqueue mutates) |
| `+0x30` | **pending** capacity raw |

Ctor seeds active/pending capacity raw to **`0x80000000`** (cap bits 0, high bit set → first grow allocates 1 slot without free).

---

## 6. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Null gate before CS | **Yes** |
| CS + capacity check + grow | **Yes** |
| Append at `pending[count++]` | **Yes** |
| LeaveCS + return 0 | **Yes** |
| No active-list insert | **Yes** |

---

## 7. Call graph (this unit)

**Callees:** `EnterCriticalSection`, `LeaveCriticalSection`, `FUN_005b3370`.

**Callers (representative, Ghidra xrefs — many):**
`Vehicle_EnsureRegenerationHeartbeat`, `Skill_StartCastAgainHeartbeat`, `Skill_ApplyStatusEffectLocal`, `Vehicle_ActivateEnterWorld`, `Client_CreateVehicleObjectApply`, `CVOGReaction_RecordFirstTimeEvent`, `CVOGObjectiveRequirement_Patrol_InitActive`, `VehicleNet_UnpackGhostVehicle`, plus numerous status/effect HB factories. Common list pointer: **map/world `+0xe4ec`**.

---

## 8. Gaps / residual

1. Product/RTTI name of grow helper `FUN_005b3370` / allocator `DAT_00b05060` vtbl+0x10/+0x14.
2. Whether every `CVOGHBBase_Start` site also Enqueues (caller-policy; not this body).
3. Bit-for-bit / live CE not run this pass.

**Verdict:** **accept** — CF, HRESULT, pending layout, and grow doubling sealed from decompile.
