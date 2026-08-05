# Review A (reconstruction fidelity): `aa_0051b870` CVOGHBPlayerTargetingLink_scalar_dtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051b870` |
| **VA** | `0x0051b870` |
| **Body** | `0x0051b870`–`0x0051b88d` (**`ret 4`**, 30 B + pad) |
| **Canonical name** | `CVOGHBPlayerTargetingLink_scalar_dtor` (**Inferred**; Ghidra `FUN_0051b870`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0051b870_CVOGHBPlayerTargetingLink_scalar_dtor.md` |
| **System** | `heartbeat` / targeting link |
| **Live tools** | Ghidra `decompile_function`, `analyze_function_complete`, `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** — MSVC scalar-deleting dtor CF **High**; product mangled name open |

---

## 1. Purpose

**Scalar deleting destructor** for `CVOGHBPlayerTargetingLink` (vtbl **slot 0** at `PTR_FUN_009cdfd4`):

1. Call base dtor path `FUN_00512060` / thunk (restores base vtbl `PTR_FUN_009cdfb0`, then `FUN_00508390` which detaches owner list if linked).
2. If **`flags & 1`**: `operator_delete(this)`.
3. Return `this`.

Classic MSVC `__thiscall` scalar-deleting dtor pattern. Placed as **derived vtbl[0]** by `CVOGHBPlayerTargetingLink_ctor` (`0x00512090`); base family uses sibling `FUN_00512070` at the same slot shape.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | Ghidra `decompile_function` @ `0x0051b870` |
| Complete analysis | xref from DATA `0x009cdfd4` (derived vtbl slot 0) |
| Machine | `read_memory` @ `0x0051b870` length 32 |
| Base dtor body | `FUN_00512060` → vtbl=`009cdfb0` + `FUN_00508390` detach |
| Base scalar dtor twin | `FUN_00512070` (same shape, calls `FUN_00512060`) |
| Ctor dual | `A_aa_00512090_CVOGHBPlayerTargetingLink_ctor` — slot 0 = this VA |
| Raw / clean scaffold | `raw/aa_0051b870_*`, `reconstructed-exact/FUN_0051b870.cpp` |
| Function record | `functions/aa_0051b870_FUN_0051b870.md` |

---

## 3. Authoritative body

```c
void * __thiscall FUN_0051b870(void *param_1, byte param_2)
{
  thunk_FUN_00512060(); // this in ECX — base dtor
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}
```

---

## 4. Machine seal (`read_memory`)

Hex:  
`56 8b f1 e8 18 00 00 00 f6 44 24 08 01 74 09 56 e8 … 83 c4 04 8b c6 5e c2 04 00`

| Claim | Evidence | Conf |
|---|---|---|
| `this` in ECX → ESI | `push esi; mov esi,ecx` | **High** |
| Call base dtor (near) | `e8 18 00 00 00` relative | **High** |
| Test `flags & 1` | `f6 44 24 08 01` | **High** |
| Conditional `operator_delete` | `push esi; call …; add esp,4` | **High** |
| Return this; **`ret 4`** | `mov eax,esi; pop esi; c2 04 00` | **High** |
| Vtbl slot 0 of `009cdfd4` | DATA xref `009cdfd4` | **High** |
| Class family | RTTI / ctor dual `CVOGHBPlayerTargetingLink` | **High** (class) |

---

## 5. Lifecycle context (not owned)

| Step | VA | Role |
|---|---|---|
| Base targeting ctor | `0x00604d40` | vtbl `009cdfb0`, AttachOwner, period, Start |
| Derived ctor | `0x00512090` | promote vtbl → `009cdfd4` |
| **This dtor** | **`0x0051b870`** | slot 0 derived |
| Base dtor scalar | `0x00512070` | slot 0 base |
| Base dtor body | `0x00512060` | vtbl demote + list detach |

---

## 6. Gaps / open

1. Exact product mangled name (`??_G…` / `??_E…`).
2. Whether array-deleting dtor exists separately (not this body).
3. Runtime golden — open.

**Verdict:** **accept-with-gaps**
