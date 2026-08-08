# Review A (reconstruction fidelity): `aa_00416f00` Class_00a733ec_ScalarDeletingDtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00416f00` |
| **VA** | `0x00416f00`–`0x00416f2e` inclusive (**47 B**) |
| **Canonical name** | `Class_00a733ec_ScalarDeletingDtor_Inferred` |
| **Ghidra name** | `FUN_00416f00` |
| **Review date** | `2026-08-05` (WQ9J-E dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9J-E) |
| **Counterpart** | `reviews/B_aa_00416f00_Class_00a733ec_ScalarDeletingDtor_Inferred.md` |
| **System** | MSVC scalar-deleting destructor (`PTR_FUN_00a733ec`) |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (47 B body) + `disassemble_function` + `analyze_function_complete` + bulk xrefs |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory (+ analyze/xrefs/disassemble_function). **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC **scalar-deleting destructor** for the class whose primary vtbl is `PTR_FUN_00a733ec`. Complete object teardown is **inline** (vtbl reinstall + optional free-callback), then heap free iff `(flags & 1)`. Returns `this`.

```text
self->vtbl = PTR_FUN_00a733ec
if (self->free_cb @ +0x10):
  free_cb(self->context @ +0x04)   // cdecl
if (flags & 1):
  operator_delete(self)            // returns
return self
```

Object size **0x14** (factories `00416830` / `004168c0`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00416f00_FUN_00416f00.md` (+ WQ9J-E append) |
| Annotated | `docs/reconstruction/raw/aa_00416f00_FUN_00416f00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Class_00a733ec_ScalarDeletingDtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00416f00.cpp` |
| Function record | `docs/reconstruction/functions/aa_00416f00_FUN_00416f00.md` |
| Named record | `docs/reconstruction/functions/aa_00416f00_Class_00a733ec_ScalarDeletingDtor_Inferred.md` |
| Live | decompile ≡ CF; full body hex; vtbl[0] DATA binding |
| Factories (context) | `FUN_00416830`, `FUN_004168c0` install same vtbl |

---

## 3. Signature (sealed)

```c
// ECX = this; stack flags; RET 4; returns this*
void *__thiscall Class_00a733ec_ScalarDeletingDtor_Inferred(void *self, uint8_t flags);
```

| Slot | Source | Conf |
|---|---|---|
| self | **ECX** (`MOV ESI,ECX`) | **High** |
| flags | stack `[ESP+8]` after push (TEST bit0) | **High** |
| return | **EAX** = ESI (this) | **High** |
| cleanup | **`RET 4`** (`C2 04 00`) | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| thiscall entry | **Yes** | **High** |
| vtbl write `0x00a733ec` | **Yes** | **High** |
| optional cdecl free @ +0x10 / arg +0x04 | **Yes** | **High** |
| flags&1 → operator_delete | **Yes** | **High** |
| operator_delete returns (not noreturn) | **Yes** (fallthrough) | **High** |
| return this + RET 4 | **Yes** | **High** |
| vtbl[0] = this function | **Yes** (`*(u32*)0xa733ec == 0x416f00`) | **High** |
| Product class English | open (vtbl stamp) | **Inferred** |

---

## 5. Gaps / open

1. Product / RTTI demangle for `PTR_FUN_00a733ec` class.
2. Free-callback body `LAB_00573240` (factory path) undualed.
3. Factories not OWN.
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
