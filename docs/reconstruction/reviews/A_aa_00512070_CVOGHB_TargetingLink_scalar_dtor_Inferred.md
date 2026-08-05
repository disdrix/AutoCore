# Review A (reconstruction fidelity): `aa_00512070` CVOGHB_TargetingLink_scalar_dtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00512070` |
| **VA** | `0x00512070`–`0x0051208d` |
| **Body** | 30 B + `CC` pad (`ret 4`) |
| **Canonical name** | `CVOGHB_TargetingLink_scalar_dtor_Inferred` |
| **Ghidra name** | `FUN_00512070` |
| **Review date** | `2026-07-29` (W19-G OWN dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00512070_CVOGHB_TargetingLink_scalar_dtor_Inferred.md` |
| **System** | `heartbeat` / targeting-link |
| **Live tools** | Ghidra `decompile_function`, `analyze_function_complete`, `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** — MSVC scalar-deleting dtor CF **Confirmed**; product mangled/RTTI class open |

---

## 1. Purpose

**Scalar deleting destructor** for base targeting-link heartbeat family (`PTR_FUN_009cdfb0` **vtbl slot 0**):

1. Call complete dtor `FUN_00512060` (restore vtbl `009cdfb0`, then `FUN_00508390` detach owner list).
2. If **`flags & 1`**: `operator_delete(this)`.
3. Return `this`.

Classic MSVC `__thiscall` scalar-deleting dtor. Derived family uses twin `CVOGHBPlayerTargetingLink_scalar_dtor` @ `0x0051b870` (vtbl `009cdfd4` slot 0) with the same complete-dtor body.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | Ghidra `decompile_function` @ `0x00512070` |
| Complete analysis | DATA xref `0x009cdfb0`; callees `FUN_00512060`, `operator_delete` |
| Machine | `read_memory` @ `0x00512070` length 64 |
| Base dtor body | live decompile `FUN_00512060` |
| Vtbl bytes | `read_memory` @ `0x009cdfb0` — first dword `0x00512070` |
| Ctor dual | `A_aa_00604d40_CVOGHB_TargetingLink_ctor_Inferred` |
| Derived twin dual | `A_aa_0051b870_CVOGHBPlayerTargetingLink_scalar_dtor` |
| Raw / clean | `raw/aa_00512070_*`, `reconstructed-exact/CVOGHB_TargetingLink_scalar_dtor_Inferred.cpp` |

---

## 3. Authoritative body

```c
void * __thiscall FUN_00512070(void *param_1, byte param_2)
{
  FUN_00512060(); // this in ECX — complete dtor
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}
```

---

## 4. Machine seal (`read_memory`)

Hex:  
`56 8b f1 e8 e8 ff ff ff f6 44 24 08 01 74 09 56 e8 … 83 c4 04 8b c6 5e c2 04 00`

| Claim | Evidence | Conf |
|---|---|---|
| `this` in ECX → ESI | `push esi; mov esi,ecx` | **Confirmed** |
| Call complete dtor `FUN_00512060` | near `e8` relative to `0x00512060` | **Confirmed** |
| Test `flags & 1` | `f6 44 24 08 01` | **Confirmed** |
| Conditional `operator_delete` | `push esi; call …; add esp,4` | **Confirmed** |
| Return this; **`ret 4`** | `mov eax,esi; pop esi; c2 04 00` | **Confirmed** |
| Vtbl slot 0 of `009cdfb0` | DATA xref + dword0 = this VA | **Confirmed** |
| Class family base targeting-link | ctor dual installs same vtbl | **High** (family) / RTTI string **open** |
| Product mangled name | none | open |

---

## 5. Lifecycle context (not owned)

| Step | VA | Role |
|---|---|---|
| Base targeting ctor | `0x00604d40` | vtbl `009cdfb0`, AttachOwner, period, Start |
| Derived ctor | `0x00512090` | promote vtbl → `009cdfd4` |
| **This dtor** | **`0x00512070`** | slot 0 base |
| Derived scalar dtor | `0x0051b870` | slot 0 derived |
| Complete dtor body | `0x00512060` | vtbl write + list detach |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Role = MSVC scalar deleting dtor | **Yes** (pattern Confirmed) |
| Vtbl family from ctor dual | **Yes** — `CVOGHB_TargetingLink_*_Inferred` |
| Product RTTI string on this VA | **No** |
| PDB / mangled | **No** |

**Decision:** promote **`CVOGHB_TargetingLink_scalar_dtor_Inferred`** (role Confirmed; class family Inferred → keep `_Inferred`).

---

## 7. Gaps / open

1. Exact product mangled name (`??_G…` / `??_E…`).
2. Base family RTTI type string (if any) not sealed on this unit.
3. Whether array-deleting dtor exists separately (not this body).
4. Runtime golden — open.

**Verdict:** **accept-with-gaps**
