# Review A (reconstruction fidelity): `aa_00584330` Object_ApplySingleFxSlot_NoSlotFilter_ThenTeardown_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00584330` |
| **VA** | `0x00584330`–`0x005843af` (**127 B**) |
| **Canonical name** | `Object_ApplySingleFxSlot_NoSlotFilter_ThenTeardown_Inferred` |
| **Ghidra name** | `FUN_00584330` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B W26-K) |
| **Reviewer role** | Reconstruction fidelity (clean ≡ raw ≡ live decompile ≡ bytes) |
| **Counterpart** | `reviews/B_aa_00584330_Object_ApplySingleFxSlot_NoSlotFilter_ThenTeardown_Inferred.md` |
| **System** | client-fx / object FX slot apply + teardown chain |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

If effect* at `this-0x88` is non-null, apply FX toggle pack **`(0, effect, 0, -1)`** (no slot filter → `0058e300` path) via sealed host-table fan-out + local host* vector, then **tail-jmp** container teardown `FUN_005179e0`.

Chain peer of `Object_ApplyDualFxSlots_SlotFilterWild_Inferred` (`0x004c8110`), which tail-jmps here at `self-0x430` with **filter char 1** pack — this unit is the **filter char 0** sibling.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00584330_FUN_00584330.md` (+ 2026-07-29 W26-K append) |
| Annotated | `docs/reconstruction/raw/aa_00584330_FUN_00584330.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00584330.cpp` |
| Named | `docs/reconstruction/reconstructed-exact/Object_ApplySingleFxSlot_NoSlotFilter_ThenTeardown_Inferred.cpp` |
| Function | `docs/reconstruction/functions/aa_00584330_FUN_00584330.md` |
| Live | decompile ≡ raw CF; `read_memory` 127 B body; bounds `00584330`–`005843af` |
| Nested seals | W25-D `00583f10`; W24-D `004b7030`; chain peek `004c8110` |

**Not performed:** Launcher, runtime, bit-exact, parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 127 B | **Confirmed** | `get_function_by_address` |
| thiscall `mov esi,ecx` | **Confirmed** | entry bytes |
| Effect gate `this-0x88` | **Confirmed** | `mov eax,[esi-0x88]; test; jz` |
| Pack `(0, effect, 0, -1)` | **Confirmed** | push `-1`, `0`, `eax`, `0` |
| `00583f10` this = `self-0x90` | **Confirmed** | `lea ecx,[esi-0x90]` |
| Local vector vb+`0xac`/`0xb0` | **Confirmed** | immediates |
| `004b7030` this = `*it` | **Confirmed** | `mov ecx,[edi]` (decomp miss) |
| Tail jmp `005179e0` + vbase ECX | **Confirmed** | `e9 …` not `e8`; lea before jmp |
| Product class/slot English | **Inferred** | `_Inferred` suffix |
| `005179e0` product name | Open | teardown role High from decomp |

---

## 4. Control flow: clean ≡ raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| Null gate effect | **Yes** |
| Table-pair fan-out | **Yes** |
| Local host* loop | **Yes** |
| Always teardown tail | **Yes** (even if effect null) |
| No invented free of effect | **Yes** |

### 4.1 Sealed contract

```
// thiscall; no stack formals; tail jmp
void Object_ApplySingleFxSlot_NoSlotFilter_ThenTeardown_Inferred(void *self);

// if effect = *(self-0x88):
//   ForEachHostPtrTablePair(self-0x90, 0, effect, 0, -1)
//   for host in vector(vb(self-0x8c), +0xac, +0xb0):
//     ForEachOwnedBit7(*it, 0, effect, 0, -1)
// jmp FUN_005179e0(vbase_adjust(self, -0x8c))
```

---

## 5. Callers / callees (live)

**Callers (4 named / 12 xrefs):** `FUN_004c8110`, `FUN_004fd950`, `FUN_00505ba0`, `FUN_005a9220`.

**Callees:** `FUN_00583f10`, `FUN_004b7030`, tail `FUN_005179e0`.

---

## 6. Gaps

1. Product C++ type / single-slot member name.  
2. Full dual of `FUN_005179e0` (not OWN).  
3. Runtime / bit-exact / differential.

**Verdict:** **accept** — CF, ABI, pack, ECX setups, and tail chain sealed; product name inferred only.
