# Review A (reconstruction fidelity): `aa_0040d590` Class_009c7938_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d590` |
| **VA** | `0x0040d590`–`0x0040d5ad` exclusive (**29 B**) |
| **Canonical name** | `Class_009c7938_ScalarDeletingDtor` |
| **Ghidra name** | `FUN_0040d590` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W31-E) |
| **Counterpart** | `reviews/B_aa_0040d590_Class_009c7938_ScalarDeletingDtor.md` |
| **System** | MSVC scalar-deleting destructor / `PTR_FUN_009c7938` |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full body hex) + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

MSVC scalar-deleting destructor (vtbl[0]): always run complete dtor `FUN_0040d820`; if `(flags & 1)` free the host with `operator_delete`; return `this`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W31-E append) | `docs/reconstruction/raw/aa_0040d590_FUN_0040d590.md` |
| Annotated | `docs/reconstruction/raw/aa_0040d590_FUN_0040d590.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Class_009c7938_ScalarDeletingDtor.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_0040d590.cpp` |
| Function record | `docs/reconstruction/functions/aa_0040d590_Class_009c7938_ScalarDeletingDtor.md` |
| Peer pattern | `Class_009c7a1c_ScalarDeletingDtor` (W29-F **accept**) |
| Live | decompile ≡ bytes; vtbl dword @ `0x009c7938` = `0x0040d590` |

---

## 3. Signature (sealed)

```c
// ECX=this; stack flags; RET 4; returns this*
void* __thiscall Class_009c7938_ScalarDeletingDtor(void* self, uint8_t flags);
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
call FUN_0040d820              // complete dtor
if (flags & 1):
  operator_delete(this)
return this                    // RET 4
```

| Stage | Match | Conf |
|---|---|---|
| Complete-then-optional-free | decompile ≡ 29 B hex | **High** |
| bit0 gate only (not vector) | `test …,1` / `je` | **High** |
| False noreturn ignored | epilogue present after delete | **High** |
| vtbl[0] | DATA `009c7938` → `0040d590` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (29 B):

```
568bf1e888020000f644240801740956e87dc2070083c4048bc65ec20400
```

Pad `CC CC` then `FUN_0040d5b0`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | DATA vtbl[0] only (no code CALL sites in bulk xrefs) |
| Callees | `FUN_0040d820`, `operator_delete` |

---

## 7. Gaps

1. Product/MSVC demangle for host class (naming only).  
2. Complete dtor body / member map not owned here (`FUN_0040d820`).  
3. Runtime / bit-exact / differential — open.

---

## 8. Verdict

ABI, CF, vtbl slot, and scalar-vs-complete separation are sealed with high confidence. Residual product English is naming-only → **accept**.
