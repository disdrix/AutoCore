# Review A (reconstruction fidelity): `aa_004130d0` CVOGDialog_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004130d0` |
| **VA** | `0x004130d0`–`0x004130ee` exclusive (**30 B**) |
| **Canonical name** | `CVOGDialog_ScalarDeletingDtor` |
| **Ghidra name** | `FUN_004130d0` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY R12-010) |
| **Counterpart** | `reviews/B_aa_004130d0_CVOGDialog_ScalarDeletingDtor.md` |
| **System** | missions-progression / CVOGDialog / MSVC scalar-deleting destructor |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` (full body hex) + xrefs/callers + parent RTTI. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

MSVC scalar-deleting destructor (vtbl[0] of `PTR_FUN_00a58c6c`): always run complete dtor `FUN_0087b7d0`; if `(flags & 1)` free the host with `operator_delete`; return `this`. Product class **CVOGDialog** sealed by RTTI (parent dual R11-030) and this DATA slot.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ R12-010 append) | `docs/reconstruction/raw/aa_004130d0_FUN_004130d0.md` |
| Annotated | `docs/reconstruction/raw/aa_004130d0_FUN_004130d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGDialog_ScalarDeletingDtor.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_004130d0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004130d0_CVOGDialog_ScalarDeletingDtor.md` |
| Parent dual | `CVOGDialog_Ctor` @ `0x0087b890` (R11-030) — installs same vtbl |
| Peer pattern | `CWndVehicle_ScalarDeletingDtor` (WQ9I-F **accept**) |
| Live | decompile ≡ bytes; vtbl dword @ `0x00a58c6c` = `0x004130d0`; COL → `.?AVCVOGDialog@@` |

---

## 3. Signature (sealed)

```c
// ECX=this; stack flags; RET 4; returns this*
void* __thiscall CVOGDialog_ScalarDeletingDtor(void* self, uint8_t flags);
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
call FUN_0087b7d0              // complete dtor (thiscall)
if (flags & 1):
  operator_delete(this)
return this                    // RET 4
```

| Stage | Match | Conf |
|---|---|---|
| Complete-then-optional-free | decompile ≡ 30 B hex | **High** |
| bit0 gate only (not vector) | `test …,1` / `je` | **High** |
| False noreturn ignored | epilogue present after delete | **High** |
| vtbl[0] | DATA `00a58c6c` → `004130d0` | **High** |
| RTTI product name | parent COL → `.?AVCVOGDialog@@` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (30 B):

```
568bf1e8f8864600f644240801740956e83d67070083c4048bc65ec20400
```

Pad `CC CC` after body.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | DATA vtbl[0] only (no code CALL sites) |
| Callees | `FUN_0087b7d0`, `operator_delete` |

---

## 7. Gaps

1. Complete dtor body / member map not owned here (`FUN_0087b7d0`).  
2. Runtime / bit-exact / differential — open.

---

## 8. Verdict

**accept** — scalar-dtor CF/ABI/vtbl[0]/RTTI CVOGDialog/`RET 4`/false-noreturn sealed. Terminal **false**.
