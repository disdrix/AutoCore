# Review A (reconstruction fidelity): `aa_00573910` InventoryGrid_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00573910` |
| **VA** | `0x00573910`–`0x0057392d` exclusive (**29 B**) |
| **Canonical name** | `InventoryGrid_ScalarDeletingDtor` |
| **Ghidra name** | `FUN_00573910` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ8R-E) |
| **Counterpart** | `reviews/B_aa_00573910_InventoryGrid_ScalarDeletingDtor.md` |
| **System** | inventory-transfer / InventoryGrid MSVC scalar-deleting dtor / `PTR_FUN_009d3390` |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full body hex) + xrefs/callees + `analyze_data_region` on vtbl. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

MSVC scalar-deleting destructor (vtbl[0]): always run complete dtor `FUN_005725a0`; if `(flags & 1)` free the host with `operator_delete`; return `this`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ WQ8R-E append) | `docs/reconstruction/raw/aa_00573910_FUN_00573910.md` |
| Annotated | `docs/reconstruction/raw/aa_00573910_FUN_00573910.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/InventoryGrid_ScalarDeletingDtor.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00573910.cpp` |
| Function record | `docs/reconstruction/functions/aa_00573910_InventoryGrid_ScalarDeletingDtor.md` |
| Peer pattern | `Class_009c7938_ScalarDeletingDtor` (W31-E **accept**) |
| Live | decompile ≡ bytes; vtbl dword @ `0x009d3390` = `0x00573910` |
| Parent | `Vehicle_CreateCargoInventoryFromPageCount` — `vtbl[0](1)` destroy cargo grid |
| Ctor | `InventoryGrid_ctor_Inferred` @ `0x00572650` installs same vtbl |

---

## 3. Signature (sealed)

```c
// ECX=this; stack flags; RET 4; returns this*
void* __thiscall InventoryGrid_ScalarDeletingDtor(void* self, uint8_t flags);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`56 8B F1`) | **High** |
| flags | stack (`F6 44 24 08 01`) | **High** |
| return | EAX = ESI = this | **High** |
| cleanup | `C2 04 00` | **High** |

---

## 4. Control flow (bytes authority)

```
ESI = this
call FUN_005725a0              // complete dtor
if (flags & 1):
  operator_delete(this)
return this                    // RET 4
```

| Stage | Match | Conf |
|---|---|---|
| Complete-then-optional-free | decompile ≡ 29 B hex | **High** |
| bit0 gate only (not vector) | `test …,1` / `je` | **High** |
| False noreturn ignored | epilogue present after delete | **High** |
| vtbl[0] | DATA `009d3390` → `00573910` | **High** |
| InventoryGrid family | ctor + cargo parent dual | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (29 B):

```
568bf1e888ecfffff644240801740956e8fd5ef1ff83c4048bc65ec20400
```

Pad `CC CC` then next function @ `0x00573930`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | DATA vtbl[0] only (no bulk code CALL sites); virtual from cargo create destroy path |
| Callees | `FUN_005725a0`, `operator_delete` @ `0x00489822` |

---

## 7. Gaps

1. Product/MSVC demangle for host class (naming only; family sealed as InventoryGrid).  
2. Complete dtor body / member map not owned here (`FUN_005725a0`).  
3. Runtime / bit-exact / differential — open.

---

## 8. Verdict

ABI, CF, vtbl slot, scalar-vs-complete separation, and InventoryGrid family link are sealed with high confidence. Residual product demangle is naming-only → **accept**.
