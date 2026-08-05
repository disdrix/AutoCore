# Review A (reconstruction fidelity): `aa_00583f10` NDSpecialFX_ForEachHostPtrTablePair_ApplyFxToggle_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00583f10` |
| **VA** | `0x00583f10` |
| **Body** | `0x00583f10`–`0x00583f9e` (143 bytes) |
| **Canonical name** | `NDSpecialFX_ForEachHostPtrTablePair_ApplyFxToggle_Inferred` |
| **Prior scaffold** | `FUN_00583f10` |
| **Review date** | `2026-07-29` (W25-D dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00583f10_NDSpecialFX_ForEachHostPtrTablePair_ApplyFxToggle_Inferred.md` |
| **System** | client-fx / NDSpecialFX |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Fan-out **sealed** `NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred` across **two host-pointer vectors** on a vbase-adjusted table owner. Stack args are pure passthrough.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x00583f10` |
| Bytes | `read_memory` 160 B — thiscall, dual loops, `ret 0x10` |
| Bounds | `get_function_by_address` body `00583f10`–`00583f9e` |
| Callees | `get_function_callees` → `004b7030` only |
| Callers | `004c8110`, `004ff6f0`, `00584290`, `00584330`, `005857a0`, `00586060` + xref |
| Nested | sealed W24-D `NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred` |
| Raw / clean | `aa_00583f10_*`, `NDSpecialFX_ForEachHostPtrTablePair_ApplyFxToggle_Inferred.cpp` |

**Not performed:** Launcher, runtime, parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| thiscall + `ret 0x10` | **Confirmed** | `C2 10 00` |
| Vbase `this+*(*(this+4)+4)` | **Confirmed** | entry sequence |
| Tables `+0x128/+0x12c` and `+0x13c/+0x140` | **Confirmed** | immediates in bytes |
| `mov ecx,[edi]` host this | **Confirmed** | decompiler miss |
| Args passthrough | **Confirmed** | stack reload each iter |
| Callee `004b7030` | **Confirmed** | rel32 ×2 |
| Fan-out (not +0x204 list) | **Confirmed** | no own-list walk |
| Product name | **Inferred** | role-sealed |
| EAX return meaningful | **Residual** | leftover base |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Save args / this | Yes |
| Vbase adjust | Yes |
| Loop table A empty-skip | Yes |
| Apply per host A | Yes (+ ECX from *it) |
| Loop table B | Yes |
| `ret 0x10` | Yes |

### 4.1 Sealed contract

```
// thiscall RET 0x10
void NDSpecialFX_ForEachHostPtrTablePair_ApplyFxToggle_Inferred(
    void *table_owner,
    int want_start,
    int want_stop,
    char use_slot_filter,
    int slot_filter);

// for host in tables A then B:
//   NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred(
//       host, want_start, want_stop, use_slot_filter, slot_filter)
```

---

## 5. Gaps / open

1. Product C++ type of table owner / table labels.
2. Whether any caller depends on EAX.
3. Full product semantics of start/stop args (owned by `004b7030` dual).
4. Runtime / bit-exact / differential.

**Verdict:** **accept**
