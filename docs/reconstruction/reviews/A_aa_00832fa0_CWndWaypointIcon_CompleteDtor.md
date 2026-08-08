# Review A (reconstruction fidelity): `aa_00832fa0` CWndWaypointIcon_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00832fa0` |
| **VA** | `0x00832fa0`–`0x0083300f` (**112 B**) |
| **Canonical name** | `CWndWaypointIcon_CompleteDtor` |
| **Ghidra name** | `FUN_00832fa0` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9J-B) |
| **Counterpart** | `reviews/B_aa_00832fa0_CWndWaypointIcon_CompleteDtor.md` |
| **System** | UI / CWndWaypointIcon complete destructor |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `disassemble_function` + `read_memory` (full body hex) + xrefs + RTTI COL. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Complete destructor for **CWndWaypointIcon**: re-stamp primary vtbl `PTR_FUN_00a7000c`, free owned heap at `+0x488` after `FUN_0096efd0`, always null field, chain base `FUN_007b5be0`. Does not free `this`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ WQ9J-B append) | `docs/reconstruction/raw/aa_00832fa0_FUN_00832fa0.md` |
| Annotated | `docs/reconstruction/raw/aa_00832fa0_FUN_00832fa0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CWndWaypointIcon_CompleteDtor.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00832fa0.cpp` |
| Function records | `aa_00832fa0_FUN_00832fa0.md`, `aa_00832fa0_CWndWaypointIcon_CompleteDtor.md` |
| Scalar peer | `aa_00416350` Class_00a7000c_ScalarDeletingDtor_Inferred (WQ9I-H) |
| Live | decompile ≡ bytes (post-delete fall-through); RTTI type_info string |

---

## 3. Signature (sealed)

```c
// ECX = this; SEH LAB_009b33be; ADD ESP,0x10; C3; void
void __fastcall CWndWaypointIcon_CompleteDtor(void* self);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`8B F1`) | **High** |
| return | void (no free this) | **High** |
| cleanup | `83 C4 10 C3` | **High** |

---

## 4. Control flow (bytes authority)

```
SEH prolog; ESI=this
*this = PTR_FUN_00a7000c
EH=0
EDI = *(this+0x488)
if EDI:
  FUN_0096efd0(EDI)      // ECX=owned
  operator_delete(EDI)   // cdecl; ADD ESP,4 — continues
*(this+0x488) = 0        // always
EH=-1
FUN_007b5be0(ESI)        // base
SEH restore; RET
```

| Stage | Match | Conf |
|---|---|---|
| Vtbl install `00a7000c` | `C7 06 0C 00 A7 00` | **High** |
| Owned load `+0x488` | `8B BE 88 04 00 00` | **High** |
| Free path + always-null | decompile ≡ disasm (`C7 86 88 04 … 00`) | **High** |
| Fall-through past delete | `83 C4 04` then null/base/RET | **High** |
| Base `007b5be0` | `8B CE; E8 …` | **High** |
| RTTI CWndWaypointIcon | COL→type_info `.?AVCWndWaypointIcon@@` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (112 B) — see raw WQ9J-B append.  
Entry SEH: `6A FF 68 BE 33 9B 00 64 A1 …`.  
Epilogue: `… 83 C4 10 C3`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (complete dtor body) |
| Callers | `FUN_00416350` (scalar; vtbl[0] of `00a7000c`) |
| Pattern | scalar: `complete(this); if (flags&1) delete this;` |

---

## 7. Gaps

1. Owned block at `+0x488` product layout / English.  
2. Full dual of `FUN_0096efd0` / `FUN_007b5be0` — not OWN.  
3. Parent rename of scalar peer to product name (WQ9I-H left `_Inferred`).  
4. Runtime / bit-exact / differential — open.

---

## 8. Verdict

Complete-dtor role, ABI/SEH, vtbl+RTTI product name, owned free/null, and base chain sealed. Residual owned-block English → **accept-with-gaps**.
