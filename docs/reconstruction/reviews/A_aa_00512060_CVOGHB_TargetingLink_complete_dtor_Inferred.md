# Review A (reconstruction fidelity): `aa_00512060` CVOGHB_TargetingLink_complete_dtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00512060` |
| **VA** | `0x00512060`–`0x0051206a` |
| **Body** | 11 B + `CC` pad |
| **Canonical name** | `CVOGHB_TargetingLink_complete_dtor_Inferred` |
| **Ghidra name** | `FUN_00512060` |
| **Review date** | `2026-07-29` (W20-A OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00512060_CVOGHB_TargetingLink_complete_dtor_Inferred.md` |
| **System** | `heartbeat` / targeting-link |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, xrefs (no `disassemble_bytes`) |
| **Verdict** | **accept** — complete-dtor CF + bytes sealed; product mangled open |

---

## 1. Purpose

**MSVC complete object destructor** for base targeting-link heartbeat family (`PTR_FUN_009cdfb0`):

1. `*this = &PTR_FUN_009cdfb0` (family vtbl restore).
2. **Tail** into `FUN_00508390` (base `CVOGHBBase` dtor: vtbl → `009cdab0`, conditional owner-list detach).

Scalar-deleting wrapper is the **caller** `FUN_00512070` (not this VA). Derived PlayerTargetingLink scalar uses `thunk_FUN_00512060` → same body.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | Ghidra `decompile_function` @ `0x00512060` |
| Base dtor | live decompile `FUN_00508390` @ `0x00508390` |
| Machine | `read_memory` @ `0x00512060` length 32 |
| Vtbl family | `read_memory` @ `0x009cdfb0` — dword0 = scalar `0x00512070` |
| Sibling dual | `A_aa_00512070_CVOGHB_TargetingLink_scalar_dtor_Inferred` |
| Ctor dual | `A_aa_00604d40_CVOGHB_TargetingLink_ctor_Inferred` |
| Raw / clean | `raw/aa_00512060_*`, `reconstructed-exact/CVOGHB_TargetingLink_complete_dtor_Inferred.cpp` |

---

## 3. Authoritative body

```c
void __fastcall FUN_00512060(undefined4 *param_1)
{
  *param_1 = &PTR_FUN_009cdfb0;
  FUN_00508390(); // retail: tail jmp; this remains in ECX / stack shape of base
  return;
}
```

---

## 4. Machine seal (`read_memory` @ `0x00512060`)

Hex:  
`c7 01 b0 df 9c 00 e9 25 63 ff ff cc cc …`

| Claim | Evidence | Conf |
|---|---|---|
| `this` in ECX | `c7 01` = `mov dword ptr [ecx], imm32` | **Confirmed** |
| Imm vtbl `0x009cdfb0` | little-endian `b0 df 9c 00` | **Confirmed** |
| Tail jmp to `FUN_00508390` | `e9` rel32 → next-IP `0x0051206b` + `0xffff6325` = `0x00508390` | **Confirmed** |
| No local `ret` in body | jmp replaces call+ret | **Confirmed** |
| Decompile ≡ raw CF | vtbl write + base dtor | **Confirmed** |
| Body end exclusive `0x0051206b` | `get_function_by_address` | **Confirmed** |

---

## 5. Lifecycle context (not owned)

| Step | VA | Role |
|---|---|---|
| Base targeting ctor | `0x00604d40` | vtbl `009cdfb0`, AttachOwner, period, Start |
| Derived ctor | `0x00512090` | promote vtbl → `009cdfd4` |
| **This complete dtor** | **`0x00512060`** | family vtbl + base detach path |
| Scalar deleting (base) | `0x00512070` | calls this; maybe `operator_delete` |
| Derived scalar | `0x0051b870` | via thunk → this body |
| Base dtor | `0x00508390` | vtbl `009cdab0` + conditional `FUN_005085b0` |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Role = MSVC complete dtor | **Yes** (vtbl restore + base dtor; sibling scalar dual) |
| Vtbl family from ctor dual | **Yes** — `CVOGHB_TargetingLink_*_Inferred` |
| Product RTTI string on this VA | **No** |
| PDB / mangled | **No** |

**Decision:** promote **`CVOGHB_TargetingLink_complete_dtor_Inferred`** (role Confirmed; class family Inferred → keep `_Inferred`). Reject naming as scalar dtor or as `CVOGHBBase` sole dtor.

---

## 7. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Complete-dtor CF | **High** | 11-byte seal |
| Tail not call | **High** | `e9` bytes |
| Family vtbl imm | **High** | `009cdfb0` |
| Not scalar-deleting | **High** | no flags/`delete` |
| Product symbol | **Open** | no string in body |

---

## 8. Gaps

1. Original mangled / PDB name.
2. Whether any virtual-base / member dtor ever interleaved (none in this body).
3. Runtime / bit-exact / differential — open.

**Verdict:** **accept**
