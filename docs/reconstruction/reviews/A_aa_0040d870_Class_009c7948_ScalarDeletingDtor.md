# Review A (reconstruction fidelity): `aa_0040d870` Class_009c7948_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d870` |
| **VA** | `0x0040d870`–`0x0040d88e` exclusive (**30 B**) |
| **Canonical name** | `Class_009c7948_ScalarDeletingDtor` |
| **Ghidra name** | `FUN_0040d870` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W33-A) |
| **Counterpart** | `reviews/B_aa_0040d870_Class_009c7948_ScalarDeletingDtor.md` |
| **System** | MSVC scalar-deleting destructor / `PTR_FUN_009c7948` |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (body + vtbl) + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC scalar-deleting destructor (vtbl[0] of `PTR_FUN_009c7948`): always run derived complete dtor `FUN_0040d890`; if `(flags & 1)` free host with `operator_delete`; return `this`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W33-A append) | `docs/reconstruction/raw/aa_0040d870_FUN_0040d870.md` |
| Annotated | `docs/reconstruction/raw/aa_0040d870_FUN_0040d870.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Class_009c7948_ScalarDeletingDtor.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0040d870.cpp` |
| Function record | `docs/reconstruction/functions/aa_0040d870_Class_009c7948_ScalarDeletingDtor.md` |
| Complete peer | `aa_0040d890` Class_009c7948_CompleteDtor (W32-C) |
| Base-family peer | `aa_0040d590` Class_009c7938_ScalarDeletingDtor (W31-E **accept**) |
| Live | decompile ≡ 30 B hex; vtbl dword @ `0x009c7948` = `0x0040d870` |

---

## 3. Signature (sealed)

```c
// ECX=this; stack flags; RET 4; returns this*
void* __thiscall Class_009c7948_ScalarDeletingDtor(void* self, uint8_t flags);
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
call FUN_0040d890              // derived complete
if (flags & 1):
  operator_delete(this)
return this                    // RET 4
```

| Stage | Match | Conf |
|---|---|---|
| Complete-then-optional-free | decompile ≡ 30 B hex | **High** |
| bit0 gate only (not vector) | `test …,1` / `je` | **High** |
| False noreturn ignored | epilogue present after delete | **High** |
| vtbl[0] | DATA `009c7948` → `0040d870` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (30 B):

```
568bf1e818000000f644240801740956e89dbf070083c4048bc65ec20400
```

Pad `CC CC` then `FUN_0040d890` complete body.

Vtbl `0x009c7948` slots: [0]=`0x0040d870`, [1]=`0x0074d470`, [2]=`0x0074d440`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | DATA vtbl[0] only (no code CALL sites in bulk xrefs) |
| Callees | `FUN_0040d890`, `operator_delete` |

---

## 7. Gaps

1. Product/MSVC demangle for derived class (naming only).  
2. Complete dtor member map owned under `aa_0040d890` (W32-C; residual product there).  
3. Vtbl slots [1]/[2] English.  
4. Runtime / bit-exact / differential — open.

---

## 8. Verdict

ABI/CF, complete-then-flags&1-free, vtbl[0], and RET 4 sealed. Residual product + extra vtbl slots → **accept-with-gaps**.
