# Review A (reconstruction fidelity): `aa_0097a8a0` CWndTutorial_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0097a8a0` |
| **VA** | `0x0097a8a0`–`0x0097a8da` (**59 B**) |
| **Canonical name** | `CWndTutorial_CompleteDtor` |
| **Ghidra name** | `FUN_0097a8a0` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9J-C) |
| **Counterpart** | `reviews/B_aa_0097a8a0_CWndTutorial_CompleteDtor.md` |
| **System** | MSVC derived complete dtor — `CWndTutorial` / `PTR_FUN_00a6f61c` |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` (body + vtbl + RTTI) + xrefs + `disassemble_function`. **No** `disassemble_bytes`. |
| **Partition** | `WAVE_2026-08-04_wq009_depth7_partition_map.md` → **WQ9J-C** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Derived complete destructor for product class **CWndTutorial**: install `PTR_FUN_00a6f61c`, then chain deep UI base complete `FUN_00792c20`. Does not free `this`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ WQ9J-C) | `docs/reconstruction/raw/aa_0097a8a0_FUN_0097a8a0.md` |
| Annotated | `docs/reconstruction/raw/aa_0097a8a0_FUN_0097a8a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CWndTutorial_CompleteDtor.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0097a8a0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0097a8a0_CWndTutorial_CompleteDtor.md` |
| Deep base | `FUN_00792c20` (not OWN) |
| Scalar caller | `FUN_004160b0` (vtbl[0]; WQ9I-E) |
| RTTI | COL `0x00ab5cec` → type_info `0x00affaa4` → `.?AVCWndTutorial@@` |
| Live | decompile ≡ disasm; body hex 59 B; vtbl slot0=`004160b0` |

---

## 3. Signature (sealed)

```c
// ECX = this; SEH; ADD ESP,0x10; RET; void; complete dtor
void __fastcall CWndTutorial_CompleteDtor(void* self);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`89 0C 24` store / thiscall) | **High** |
| epilogue | `83 C4 10; C3` | **High** |
| free this? | no | **High** |

---

## 4. Control flow (bytes authority)

```
SEH prologue (LAB_009b4587)
*this = PTR_FUN_00a6f61c          // C7 01 1C F6 A6 00
EH = -1
FUN_00792c20(this)                // deep base complete
SEH epilogue; ADD ESP,0x10; RET
```

| Stage | Match | Conf |
|---|---|---|
| Derived vtbl install | Yes | **High** |
| Chain base complete only | Yes | **High** |
| Complete (no delete this) | Yes | **High** |
| SEH / ADD ESP,0x10 | Yes | **High** |
| Product = CWndTutorial | Yes (RTTI) | **High** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | wrapper (thin complete over base) |
| Callers | `FUN_004160b0` scalar-deleting |
| Callees | `FUN_00792c20` |

Vtbl `0x00a6f61c`: [0]=`0x004160b0`, [1]=`0x00790cc0`, [2]=`0x007a7de0`, [3]=`0x007567e0`.

---

## 6. Gaps

1. Deep base `00792c20` dual residual.  
2. Vtbl slots [1+] English.  
3. Runtime / bit-exact / differential — open.

---

## 7. Verdict

ABI/SEH, derived vtbl install, base-complete chain, complete-vs-scalar, and **RTTI product name CWndTutorial** sealed. Residual base dual + runtime → **accept-with-gaps**.
