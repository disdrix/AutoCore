# Review A (reconstruction fidelity): `aa_00604dd0` CVOGHBTargeting_OnHeartBeat

| Field | Value |
|---|---|
| **Stable ID** | `aa_00604dd0` |
| **VA** | `0x00604dd0` |
| **Body** | `0x00604dd0`–`0x00604e01` (**`ret 4`**) |
| **Canonical name** | `CVOGHBTargeting_OnHeartBeat` (**Inferred**; Ghidra `FUN_00604dd0`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00604dd0_CVOGHBTargeting_OnHeartBeat.md` |
| **System** | `heartbeat` / targeting |
| **Live tools** | Ghidra `decompile_function`, `force_decompile`, `analyze_function_complete`, `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** — CF **High**; flag predicate + vtbl+0x18 product names open |

---

## 1. Purpose

**OnHeartBeat** implementation for the targeting HB family (shared **vtbl slot 3** / `+0x0C` on both base `009cdfb0` and derived `009cdfd4`):

1. If `pOwnerObject` (`this+0x18`) **non-null**:
   - Call `FUN_005134e0(owner)` — owner (or linked) flag test: **`*(obj+0x184) & 8`** (with vehicle-seat fallback path inside callee).
   - If true: invoke **`this->vtbl+0x18 (slot 6)`** with stack args **`(1, 1)`** (pre-dtor / remove-style virtual; same slot family used on list destroy paths).
2. Always call **`CVOGHBBase_RescheduleAfterFire(this, pOutStatus)`**.
3. Return the stack status object / out pointer (ABI residual — TryFire treats OnHeartBeat return as pointer to status dword).

Installed by `FUN_00604d40` (base targeting HB ctor) which sets period fields and `Start`s the action.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | Ghidra `decompile_function` @ `0x00604dd0` |
| Force re-decompile | `force_decompile` (**identical** CF) |
| Complete analysis | DATA xrefs `009cdfbc` / `009cdfe0` (base + derived slot 3) |
| Machine | `read_memory` @ `0x00604dd0` length 50 |
| Predicate | `FUN_005134e0` decompile — bit 8 at `+0x184` |
| Reschedule | `CVOGHBBase_RescheduleAfterFire` dual surface |
| TryFire | `A_aa_005082c0_*` — OnHeartBeat = vtbl+0x0C |
| Ctor context | `FUN_00604d40` / `CVOGHBPlayerTargetingLink_ctor` |
| Raw / clean scaffold | `raw/aa_00604dd0_*`, `reconstructed-exact/FUN_00604dd0.cpp` |
| Function record | `functions/aa_00604dd0_FUN_00604dd0.md` |

---

## 3. Authoritative body (machine-aligned)

```c
// __thiscall OnHeartBeat(this, /* TryFire may pass extra frame */, pOutStatus)
undefined4 FUN_00604dd0(CVOGHBBase *this, /*…*/, undefined4 pOutStatus)
{
  if (this->pOwnerObject != NULL) {
    if (FUN_005134e0(this->pOwnerObject)) { // ECX=owner
      (**(code **)((int)this->pVTable + 0x18))(1, 1);
    }
  }
  CVOGHBBase_RescheduleAfterFire(this, /* out delay/status */);
  return pOutStatus; // residual — TryFire reads *returned_ptr
}
```

---

## 4. Machine seal (`read_memory`)

Hex:  
`56 8b f1 8b 4e 18 85 c9 57 74 14 e8 … 84 c0 74 0b 8b 06 6a 01 6a 01 8b ce ff 50 18 8b 7c 24 0c 57 8b ce e8 … 8b c7 5f 5e c2 04 00`

| Claim | Evidence | Conf |
|---|---|---|
| `this` ESI from ECX | `mov esi,ecx` | **High** |
| Owner load `+0x18` into ECX for predicate | `mov ecx,[esi+0x18]; test ecx,ecx` | **High** |
| Null owner skips predicate + vcall | `jz` over block | **High** |
| `FUN_005134e0` then `test al,al` | relative `call` + `84 c0` | **High** |
| `push 1; push 1; call [vtbl+0x18]` | `6a 01 6a 01 … ff 50 18` | **High** |
| Always `CVOGHBBase_RescheduleAfterFire` | second relative call with `push edi; mov ecx,esi` | **High** |
| **`ret 4`** | `c2 04 00` | **High** |
| Shared base+derived slot 3 | DATA at `009cdfbc` and `009cdfe0` | **High** |

---

## 5. Related contracts

| Unit | Role |
|---|---|
| `CVOGHBBase_TryFire` | Invokes this as OnHeartBeat when period due + not dormant |
| `FUN_005134e0` | Owner flag `+0x184` bit 8 (+ seat/link fallback) |
| `CVOGHBBase_RescheduleAfterFire` | Writes next delay / continue; combat-pool sentinel −1000 path |
| `vtbl+0x18` | Shared remove/pre-dtor virtual (product English open — list Tick dual cites same slot) |

---

## 6. Gaps / open

1. Exact product name of OnHeartBeat / of `vtbl+0x18`.
2. Semantic English for owner flag bit 8 (`+0x184`).
3. Full OnHeartBeat return-object ABI vs TryFire residual (sibling gap).
4. Whether `(1,1)` means “delete+remove” vs other flags (list Tick uses `(1,1)` before dtor on stopped actions).

**Verdict:** **accept-with-gaps**
