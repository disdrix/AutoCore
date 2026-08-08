# Review A (reconstruction fidelity): `aa_008327f0` CMenuChatlog_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_008327f0` |
| **VA** | `0x008327f0`–`0x0083282a` (**59 B**) |
| **Canonical name** | `CMenuChatlog_CompleteDtor` |
| **Ghidra name** | `FUN_008327f0` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9J-C) |
| **Counterpart** | `reviews/B_aa_008327f0_CMenuChatlog_CompleteDtor.md` |
| **System** | MSVC derived complete dtor — `CMenuChatlog` / `PTR_FUN_00a70524` |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` (body + vtbl + RTTI) + xrefs + `disassemble_function`. **No** `disassemble_bytes`. |
| **Partition** | `WAVE_2026-08-04_wq009_depth7_partition_map.md` → **WQ9J-C** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Derived complete destructor for product class **CMenuChatlog**: install `PTR_FUN_00a70524`, then chain intermediate base complete `FUN_0082d540`. Does not free `this`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ WQ9J-C) | `docs/reconstruction/raw/aa_008327f0_FUN_008327f0.md` |
| Annotated | `docs/reconstruction/raw/aa_008327f0_FUN_008327f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CMenuChatlog_CompleteDtor.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_008327f0.cpp` |
| Function record | `docs/reconstruction/functions/aa_008327f0_CMenuChatlog_CompleteDtor.md` |
| Intermediate base | `FUN_0082d540` (not OWN) |
| Scalar caller | `FUN_004165f0` (vtbl[0]; WQ9I-J) |
| RTTI | COL `0x00ab5e54` → type_info `0x00affb04` → `.?AVCMenuChatlog@@` |
| Live | decompile ≡ disasm; body hex 59 B; vtbl slot0=`004165f0` |

---

## 3. Signature (sealed)

```c
// ECX = this; SEH; ADD ESP,0x10; RET; void; complete dtor
void __fastcall CMenuChatlog_CompleteDtor(void* self);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`89 0C 24` store / thiscall) | **High** |
| epilogue | `83 C4 10; C3` | **High** |
| free this? | no | **High** |

---

## 4. Control flow (bytes authority)

```
SEH prologue (LAB_009b453f)
*this = PTR_FUN_00a70524          // C7 01 24 05 A7 00
EH = -1
FUN_0082d540(this)                // intermediate base complete
SEH epilogue; ADD ESP,0x10; RET
```

| Stage | Match | Conf |
|---|---|---|
| Derived vtbl install | Yes | **High** |
| Chain base complete only | Yes | **High** |
| Complete (no delete this) | Yes | **High** |
| SEH / ADD ESP,0x10 | Yes | **High** |
| Product = CMenuChatlog | Yes (RTTI) | **High** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | wrapper (thin complete over base) |
| Callers | `FUN_004165f0` scalar-deleting |
| Callees | `FUN_0082d540` |

Vtbl `0x00a70524`: [0]=`0x004165f0`, [1]=`0x00790cc0`, [2]=`0x007a7de0`, [3]=`0x007567e0`.

---

## 6. Gaps

1. Intermediate base `0082d540` / deep base `00792c20` dual residual.  
2. Vtbl slots [1+] English.  
3. Runtime / bit-exact / differential — open.

---

## 7. Verdict

ABI/SEH, derived vtbl install, base-complete chain, complete-vs-scalar, and **RTTI product name CMenuChatlog** sealed. Residual base duals + runtime → **accept-with-gaps**.
