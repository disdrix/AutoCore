# Review A (reconstruction fidelity): `aa_004b7030` NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b7030` |
| **VA** | `0x004b7030` |
| **Body span** | `004b7030` – `004b708a` (**90** bytes; `ret 0x10` @ `004b7087`) |
| **Canonical name (Ghidra)** | `FUN_004b7030` |
| **Proposed name** | `NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred` (**High** role; product string absent) |
| **Prior scaffold alias** | `Named_CalleeOf_Drive_s_VEHICLE_EXHAUST_d_004b7030` — **too narrow** |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B W24-D) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile ≡ bytes) |
| **Counterpart** | `reviews/B_aa_004b7030_NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred.md` |
| **System** | `client-fx` / NDSpecialFX lifecycle |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

---

## 1. Purpose

NDSpecialFX host helper: **iterate owned children** and **toggle FX payloads** on those marked with **`+0x90e` bit7**, choosing unrestricted vs slot-filtered apply based on a stack char gate.

```
for child in host.owned_list(+0x204):
  if child.flags(+0x90e) & 0x80:
    if !use_slot_filter: 0058e300(child, want_start, want_stop)
    else:                0058e270(child, want_start, want_stop, slot_filter)
```

**Calling convention:** MSVC **thiscall**, four stack dwords, **`ret 0x10`**.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004b7030_FUN_004b7030.md` |
| Annotated | `docs/reconstruction/raw/aa_004b7030_FUN_004b7030.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004b7030.cpp` |
| Named | `docs/reconstruction/reconstructed-exact/NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_004b7030_NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred.md` |
| Layout peer | `NDSpecialFX_DeactivateClear_Inferred` @ `0x004b7150` (W23-H dual) |

**This pass (live):** `decompile_function` @ `0x004b7030` + callees `0x0058e270`/`0x0058e300` + callers `0x004c8110`/`0x004ff850`/`0x005829d0`/`0x00583f10`/`0x00584330`; `get_function_by_address`; `get_function_callers`/`callees`/`xrefs_to`; `read_memory` entry + epilogue. **Not performed:** Launcher, runtime, bit-exact, ledgers. **No** `disassemble_bytes`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span 90 B + `ret 0x10` | **Confirmed** | epilogue `C2 10 00` |
| thiscall ECX = host | **Confirmed** | entry `push ecx` / `mov eax,[ecx+0x204]` |
| Circular list at `+0x204` | **Confirmed** | decomp + peer dual |
| Child = `node[2]` | **Confirmed** | `mov ecx,[esi+8]` |
| Bit7 gate `+0x90e & 0x80` | **Confirmed** | `test byte [ecx+0x90e],80` |
| Callee this = child (decompiler miss) | **Confirmed** | bytes before both calls |
| `param_4==0` → e300 else e270 | **Confirmed** | `cmp [esp+..],0` branch |
| e270 gets third stack = `param_5` | **Confirmed** | three pushes vs two |
| NDSpecialFX host family | **High** | same `+0x204`/`+0x90e` as `004b7150` |
| Product method name | **Tentative** | `_Inferred` |
| Bit7 English label | Open | phys-detach vs FX-capable may overlap |
| Full e270/e300 dual | Open | residual from W23-H |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Load list head from `host+0x204` | **Yes** |
| Empty list early out | **Yes** |
| Walk until sentinel | **Yes** |
| Bit7 filter | **Yes** |
| Branch on slot-filter char | **Yes** |
| Advance `node = *node` | **Yes** |
| Void return / `ret 0x10` | **Yes** |
| No invented free/unlink | **Yes** |

### 4.1 Sealed contract

```
// thiscall RET 0x10
void NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred(
    void *host,
    int want_start,
    int want_stop,
    char use_slot_filter,
    int slot_filter);

// for each owned child with (+0x90e & 0x80):
//   use_slot_filter==0 ? 0058e300(child, want_start, want_stop)
//                      : 0058e270(child, want_start, want_stop, slot_filter)
```

### 4.2 Caller samples

| Caller | Shape |
|---|---|
| `FUN_005829d0` | `(fx, 0, 0, -1)` → e300 path (char 0) |
| `FUN_004c8110` | `(0, effect*, 1, -1)` → e270 wild slot |
| `FUN_004ff850` | `(*slot, 0, 1, i)` near VEHICLE_EXHAUST string path |
| `FUN_00583f10` | passthrough over attachment pointer tables |

---

## 5. Callers / callees (live)

**Callers (5 functions / 7 sites):**

| VA | Function |
|---|---|
| `0x004c8110` | `FUN_004c8110` |
| `0x004ff850` | `FUN_004ff850` |
| `0x005829d0` | `FUN_005829d0` |
| `0x00583f10` | `FUN_00583f10` |
| `0x00584330` | `FUN_00584330` |

**Callees:**

| VA | Role |
|---|---|
| `0x0058e300` | child FX toggle, no slot filter (`+0x25c < 0`) |
| `0x0058e270` | child FX toggle, slot filter |

---

## 6. Gaps

1. Product / PDB symbol.  
2. Authoritative English for `+0x90e` bit7.  
3. Full dual of `0058e270` / `0058e300` / particle helpers `0096d*`.  
4. Runtime / bit-exact / diff.

**Verdict:** **accept** — CF, ABI, list/flag layout, and callee this sealed; product name inferred only.
