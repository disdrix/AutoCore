# Review A (reconstruction fidelity): `aa_004160f0` CWidgetRotateVehicle_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004160f0` |
| **VA** | `0x004160f0`–`0x0041610f` exclusive (**31 B**) |
| **Canonical name** | `CWidgetRotateVehicle_ScalarDeletingDtor` |
| **Ghidra name** | `FUN_004160f0` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9I-F) |
| **Counterpart** | `reviews/B_aa_004160f0_CWidgetRotateVehicle_ScalarDeletingDtor.md` |
| **System** | CWidgetRotateVehicle / MSVC scalar-deleting destructor |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` (full body hex) + xrefs + RTTI COL + ctor install. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

MSVC scalar-deleting destructor for **CWidgetRotateVehicle**: always run complete dtor `FUN_00416110` (stack this → install base `PTR_LAB_00a9bbe8`); if `(flags & 1)` free host; return `this`. DATA site is `PTR_LAB_00a6ff94[+0x0C]` (virtual dtor slot after three base virtuals).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ WQ9I-F append) | `docs/reconstruction/raw/aa_004160f0_FUN_004160f0.md` |
| Annotated | `docs/reconstruction/raw/aa_004160f0_FUN_004160f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CWidgetRotateVehicle_ScalarDeletingDtor.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_004160f0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004160f0_CWidgetRotateVehicle_ScalarDeletingDtor.md` |
| Peer pattern | `CWndVehicle_ScalarDeletingDtor` (sibling OWN) / W31-E scalar family |
| Live | decompile ≡ bytes; dword @ `0x00a6ffa0` = this VA; COL → `.?AVCWidgetRotateVehicle@@`; ctor `FUN_00833500` installs `00a6ff94` |

---

## 3. Signature (sealed)

```c
// ECX=this; stack flags; RET 4; returns this*
void* __thiscall CWidgetRotateVehicle_ScalarDeletingDtor(void* self, uint8_t flags);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`56 8B F1`) | **High** |
| flags | stack (`F6 44 24 08 01`) | **High** |
| return | EAX = ESI = this | **High** |
| cleanup | `C2 04 00` | **High** |
| complete ABI | stack this (`PUSH ESI` + callee `RET 4`) | **High** |

---

## 4. Control flow (bytes authority)

```
ESI = this
push ESI
call FUN_00416110              // complete dtor (stack this)
if (flags & 1):
  operator_delete(this)
return this                    // RET 4
```

| Stage | Match | Conf |
|---|---|---|
| Complete-then-optional-free | decompile ≡ 31 B hex | **High** |
| bit0 gate only (not vector) | `test …,1` / `je` | **High** |
| False noreturn ignored | epilogue present after delete | **High** |
| DATA slot | `00a6ffa0` → `004160f0` | **High** |
| RTTI product name | COL → `.?AVCWidgetRotateVehicle@@` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (31 B):

```
568bf156e817000000f644240801740956e81c37070083c4048bc65ec20400
```

Pad `CC` then `FUN_00416110`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | DATA only @ `0x00a6ffa0` (no code CALL sites) |
| Callees | `FUN_00416110`, `operator_delete` |

---

## 7. Gaps

1. Complete dtor dual owned by WQ9I-G (`0x00416110`) — role sealed here, not dualed.  
2. Runtime / bit-exact / differential — open.

---

## 8. Verdict

**accept** — scalar-dtor CF/ABI/DATA slot/RTTI/`RET 4`/false-noreturn sealed.
