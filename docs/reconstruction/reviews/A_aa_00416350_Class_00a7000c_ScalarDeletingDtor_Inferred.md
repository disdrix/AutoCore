# Review A (reconstruction fidelity): `aa_00416350` Class_00a7000c_ScalarDeletingDtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00416350` |
| **VA** | `0x00416350`–`0x0041636e` exclusive (**30 B** / `0x1E`) |
| **Canonical name** | `Class_00a7000c_ScalarDeletingDtor_Inferred` |
| **Ghidra name** | `FUN_00416350` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9I-H) |
| **Counterpart** | `reviews/B_aa_00416350_Class_00a7000c_ScalarDeletingDtor_Inferred.md` |
| **System** | MSVC scalar-deleting destructor / `PTR_FUN_00a7000c` |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` (body + vtbl) + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC scalar-deleting destructor (vtbl[0] of `PTR_FUN_00a7000c`): always run complete dtor `FUN_00832fa0`; if `(flags & 1)` free host with `operator_delete`; return `this`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ WQ9I-H append) | `docs/reconstruction/raw/aa_00416350_FUN_00416350.md` |
| Annotated | `docs/reconstruction/raw/aa_00416350_FUN_00416350.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Class_00a7000c_ScalarDeletingDtor_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00416350.cpp` |
| Function record | `docs/reconstruction/functions/aa_00416350_Class_00a7000c_ScalarDeletingDtor_Inferred.md` |
| Complete peer | `FUN_00832fa0` (installs vtbl `00a7000c`; not OWN) |
| Live | decompile ≡ 30 B hex; vtbl dword @ `0x00a7000c` = `0x00416350` |

---

## 3. Signature (sealed)

```c
// ECX=this; stack flags; RET 4; returns this*
void* __thiscall Class_00a7000c_ScalarDeletingDtor_Inferred(void* self, uint8_t flags);
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
call FUN_00832fa0              // complete
if (flags & 1):
  operator_delete(this)
return this                    // RET 4
```

| Stage | Match | Conf |
|---|---|---|
| Complete-then-optional-free | decompile ≡ 30 B hex | **High** |
| bit0 gate only (not vector) | `test …,1` / `jz` | **High** |
| False noreturn ignored | epilogue present after delete | **High** |
| vtbl[0] | DATA `00a7000c` → `00416350` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (30 B):

```
568bf1e848cc4100f644240801740956e8bd34070083c4048bc65ec20400
```

Vtbl `0x00a7000c` slot0: `0x00416350` (bytes `50 63 41 00`).

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | DATA vtbl[0] only (no code CALL sites) |
| Callees | `FUN_00832fa0`, `operator_delete` |

---

## 7. Gaps

1. Product/MSVC demangle for class of `PTR_FUN_00a7000c` (naming only).  
2. Complete dtor member map owned under `FUN_00832fa0` / base chain (not OWN).  
3. Vtbl slots [1+] English.  
4. Runtime / bit-exact / differential — open.

---

## 8. Verdict

ABI/CF, complete-then-flags&1-free, vtbl[0], and RET 4 sealed. Residual product + complete dual → **accept-with-gaps**.
