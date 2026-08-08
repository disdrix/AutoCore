# Review A (reconstruction fidelity): `aa_00834520` CWndVehicle_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00834520` |
| **VA** | `0x00834520`–`0x008345b1` (**146 B**) |
| **Canonical name** | `CWndVehicle_CompleteDtor` |
| **Ghidra name** | `FUN_00834520` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9J-B) |
| **Counterpart** | `reviews/B_aa_00834520_CWndVehicle_CompleteDtor.md` |
| **System** | UI / CWndVehicle complete destructor |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `disassemble_function` + `read_memory` (full body hex) + xrefs + RTTI COL. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Complete destructor for **CWndVehicle**: re-stamp primary vtbl `PTR_FUN_00a6fbcc`, notify nested object at `+0x2A8`, run derived helper `FUN_00833d50` (EDI=this), chain base `FUN_0078ca80`. Does not free `this`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ WQ9J-B append) | `docs/reconstruction/raw/aa_00834520_FUN_00834520.md` |
| Annotated | `docs/reconstruction/raw/aa_00834520_FUN_00834520.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CWndVehicle_CompleteDtor.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00834520.cpp` |
| Function records | `aa_00834520_FUN_00834520.md`, `aa_00834520_CWndVehicle_CompleteDtor.md` |
| Scalar peer | `aa_004160d0` CWndVehicle_ScalarDeletingDtor (WQ9I-F) |
| Live | decompile ≡ bytes; RTTI type_info string; sole caller scalar |

---

## 3. Signature (sealed)

```c
// ECX = this; SEH LAB_009b4563; ADD ESP,0x18; C3; void
void __fastcall CWndVehicle_CompleteDtor(void* self);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`8B F9`) | **High** |
| return | void (no free this) | **High** |
| cleanup | `83 C4 18 C3` | **High** |

---

## 4. Control flow (bytes authority)

```
SEH prolog; EDI=this
*this = PTR_FUN_00a6fbcc
EH=0
ESI = *(this+0x2A8)
if ESI:
  flag ESI+0x48=1; copy via ESI+0x10 (+0x30→+0x34)
  FUN_0076c4d0(ESI+0x10)
  binder {00a9f4d8, ESI}; vcall [*(ESI+8)][+0x20], [+0x10](0)
FUN_00833d50()          // EDI=this
EH=-1
FUN_0078ca80(EDI)       // base
SEH restore; RET
```

| Stage | Match | Conf |
|---|---|---|
| Vtbl install `00a6fbcc` | `C7 07 CC FB A6 00` | **High** |
| Nested load `+0x2A8` | `8B B7 A8 02 00 00` | **High** |
| Nested notify + dual vcall | decompile ≡ disasm | **High** |
| `FUN_00833d50` then base | call order + `8B CF` before `0078ca80` | **High** |
| Reaches RET | full 146 B hex | **High** |
| RTTI CWndVehicle | COL→type_info `.?AVCWndVehicle@@` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (146 B) — see raw WQ9J-B append.  
Entry SEH: `6A FF 68 63 45 9B 00 64 A1 …`.  
Epilogue: `… 83 C4 18 C3` then `CC` pad.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (complete dtor body) |
| Callers | `FUN_004160d0` (scalar; vtbl[0] of `00a6fbcc`) |
| Pattern | scalar: `complete(this); if (flags&1) delete this;` |

---

## 7. Gaps

1. Nested object at `+0x2A8` product type / binder vtbl `00a9f4d8` English.  
2. Full dual of `FUN_00833d50` (vehicle `+0x508` / wheelset path) — not OWN.  
3. Full dual of base `FUN_0078ca80` / `FUN_0076c4d0`.  
4. Runtime / bit-exact / differential — open.

---

## 8. Verdict

Complete-dtor role, ABI/SEH, vtbl+RTTI, nested notify, derived helper, and base chain sealed. Residual nested/helper product English → **accept-with-gaps**.
