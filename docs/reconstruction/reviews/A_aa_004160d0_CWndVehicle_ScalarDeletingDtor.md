# Review A (reconstruction fidelity): `aa_004160d0` CWndVehicle_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004160d0` |
| **VA** | `0x004160d0`–`0x004160ee` exclusive (**30 B**) |
| **Canonical name** | `CWndVehicle_ScalarDeletingDtor` |
| **Ghidra name** | `FUN_004160d0` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9I-F) |
| **Counterpart** | `reviews/B_aa_004160d0_CWndVehicle_ScalarDeletingDtor.md` |
| **System** | CWndVehicle / MSVC scalar-deleting destructor |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` (full body hex) + xrefs + RTTI COL. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

MSVC scalar-deleting destructor (vtbl[0] of `PTR_FUN_00a6fbcc`): always run complete dtor `FUN_00834520`; if `(flags & 1)` free the host with `operator_delete`; return `this`. Product class **CWndVehicle** sealed by RTTI.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ WQ9I-F append) | `docs/reconstruction/raw/aa_004160d0_FUN_004160d0.md` |
| Annotated | `docs/reconstruction/raw/aa_004160d0_FUN_004160d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CWndVehicle_ScalarDeletingDtor.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_004160d0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004160d0_CWndVehicle_ScalarDeletingDtor.md` |
| Peer pattern | `Class_009c7938_ScalarDeletingDtor` (W31-E **accept**) |
| Live | decompile ≡ bytes; vtbl dword @ `0x00a6fbcc` = `0x004160d0`; COL → `.?AVCWndVehicle@@` |

---

## 3. Signature (sealed)

```c
// ECX=this; stack flags; RET 4; returns this*
void* __thiscall CWndVehicle_ScalarDeletingDtor(void* self, uint8_t flags);
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
call FUN_00834520              // complete dtor (thiscall)
if (flags & 1):
  operator_delete(this)
return this                    // RET 4
```

| Stage | Match | Conf |
|---|---|---|
| Complete-then-optional-free | decompile ≡ 30 B hex | **High** |
| bit0 gate only (not vector) | `test …,1` / `je` | **High** |
| False noreturn ignored | epilogue present after delete | **High** |
| vtbl[0] | DATA `00a6fbcc` → `004160d0` | **High** |
| RTTI product name | COL → `.?AVCWndVehicle@@` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (30 B):

```
568bf1e848e44100f644240801740956e83d37070083c4048bc65ec20400
```

Pad `CC CC` then `FUN_004160f0`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | DATA vtbl[0] only (no code CALL sites) |
| Callees | `FUN_00834520`, `operator_delete` |

---

## 7. Gaps

1. Complete dtor body / member map not owned here (`FUN_00834520`).  
2. Runtime / bit-exact / differential — open.

---

## 8. Verdict

**accept** — scalar-dtor CF/ABI/vtbl[0]/RTTI/`RET 4`/false-noreturn sealed.
