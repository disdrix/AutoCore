# Review A (reconstruction fidelity): `aa_0053b900` CNDHash_scalar_dtor_009cfa7c

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053b900` |
| **VA** | `0x0053b900`–`0x0053b91d` |
| **Canonical name** | `CNDHash_scalar_dtor_009cfa7c` |
| **Ghidra name** | `FUN_0053b900` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W25-H) |
| **Counterpart** | `reviews/B_aa_0053b900_CNDHash_scalar_dtor_009cfa7c.md` |
| **System** | container / CNDHash |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `get_function_by_address` + `get_bulk_xrefs` + `get_function_callees`; sibling W24-M body dual |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC **scalar-deleting destructor** — **vtbl[0]** of **`PTR_FUN_009cfa7c`**: run owning body dtor `FUN_0053b920`, then if `flags&1` heap-free `this`, return `this` (`ret 4`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0053b900_FUN_0053b900.md` (+ W25-H append) |
| Annotated | `docs/reconstruction/raw/aa_0053b900_FUN_0053b900.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CNDHash_scalar_dtor_009cfa7c.cpp` |
| Clean scaffold | `docs/reconstruction/reconstructed-exact/FUN_0053b900.cpp` |
| Function record | `docs/reconstruction/functions/aa_0053b900_CNDHash_scalar_dtor_009cfa7c.md` |
| Live | decompile `0x0053b900`; `read_memory` entry 32 B; vtbl `0x009cfa7c`; bulk xrefs |
| Sibling | `aa_0053b920` CNDHash_Dtor_009cfa7c (body) |

---

## 3. Signature

```c
// Ghidra: void * __thiscall FUN_0053b900(void *param_1, byte param_2)
// Bytes:  push esi; mov esi,ecx; call body; test flags&1; optional delete; mov eax,esi; ret 4
void *__thiscall CNDHash_scalar_dtor_009cfa7c(void *thisHash, unsigned char flags);
```

| Item | Evidence | Conf |
|---|---|---|
| thiscall ECX=this | `8B F1` | **High** |
| ret 4 | `C2 04 00` | **High** |
| returns this | `8B C6` | **High** |
| flags&1 delete this | `F6 44 24 08 01` + push esi | **High** |
| body = `0053b920` | relative call +0x18 | **High** |
| vtbl[0] | dword0 of `009cfa7c` = `0x0053b900` | **High** |

---

## 4. Control flow (sealed)

```
scalar_dtor(this, flags):
  body_dtor(this)          // FUN_0053b920 — always
  if (flags & 1):
    operator_delete(this)
  return this
```

| Stage | Match | Conf |
|---|---|---|
| Entry ESI=this | **Yes** | **High** |
| Unconditional body call | **Yes** | **High** |
| Conditional heap free of this only | **Yes** | **High** |
| No value-field free in this unit | **Yes** (body owns reclaim) | **High** |
| Epilogue ret 4 | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

| Addr | Bytes | Decode |
|---|---|---|
| `0x0053b900` | `56 8B F1 E8 18 00 00 00` | ESI=this; call `0053b920` |
| | `F6 44 24 08 01 74 09` | test flags&1; jz |
| | `56 E8 … 83 C4 04` | delete this |
| | `8B C6 5E C2 04 00` | return this; ret 4 |

**No `disassemble_bytes` used.**

---

## 6. Call surface

| Kind | Detail |
|---|---|
| Xrefs | **DATA** only from `0x009cfa7c` |
| Callees | `FUN_0053b920`, `operator_delete` |

---

## 7. Confidence

| Claim | Level |
|---|---|
| ABI / CF / vtbl[0] | **High** |
| Owning body always run before optional free | **High** |
| Product mangled name | **Open** |
| Runtime / bit-exact | **Open** |

---

## 8. Gaps

1. Product RTTI / mangled name for this CNDHash specialization.
2. Exhaustive method map of vtbl `009cfa7c` (not owned here).
3. Live delete differential.

**Verdict:** **accept-with-gaps** — classic MSVC scalar dtor fully machine-sealed; product name open.
