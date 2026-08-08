# Review A (reconstruction fidelity): `aa_0082d540` CVOGMenu_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0082d540` |
| **VA** | `0x0082d540`–`0x0082d58e` (**79 B**) |
| **Canonical name** | `CVOGMenu_CompleteDtor` |
| **Ghidra name** | `FUN_0082d540` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9K-G) |
| **Counterpart** | `reviews/B_aa_0082d540_CVOGMenu_CompleteDtor.md` |
| **System** | MSVC intermediate complete dtor — `CVOGMenu` / `PTR_FUN_00a72f6c` |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` (body + vtbl + RTTI) + xrefs + `disassemble_function`. **No** `disassemble_bytes`. |
| **Partition** | `WAVE_2026-08-04_wq009_depth8_partition_map.md` → **WQ9K-G** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Intermediate complete destructor for product class **CVOGMenu**: install `PTR_FUN_00a72f6c`, run menu hash teardown `FUN_0082ce20`, chain shared UI base complete `FUN_00792c20` (**CNDUIDialog**). Does not free `this`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ WQ9K-G) | `docs/reconstruction/raw/aa_0082d540_FUN_0082d540.md` |
| Annotated | `docs/reconstruction/raw/aa_0082d540_FUN_0082d540.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGMenu_CompleteDtor.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0082d540.cpp` |
| Function record | `docs/reconstruction/functions/aa_0082d540_CVOGMenu_CompleteDtor.md` |
| Deep base | `FUN_00792c20` CNDUIDialog_CompleteDtor (OWN WQ9K-G) |
| Scalar caller | `FUN_004166d0` (vtbl[0]) |
| Derived caller | `FUN_008327f0` CMenuChatlog_CompleteDtor (WQ9J-C) |
| RTTI | COL `0x00ab6214` → type_info `0x00afe39c` → `.?AVCVOGMenu@@` |
| Live | decompile ≡ disasm; body hex 79 B; vtbl slot0=`004166d0` |

---

## 3. Signature (sealed)

```c
// ECX = this; SEH; ADD ESP,0x10; RET; void; complete dtor
void __fastcall CVOGMenu_CompleteDtor(void* self);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`8B F1`) | **High** |
| epilogue | `83 C4 10; C3` | **High** |
| free this? | no | **High** |

---

## 4. Control flow (bytes authority)

```
SEH prologue (LAB_009b4443)
*this = PTR_FUN_00a72f6c          // C7 06 6C 2F A7 00
EH = 0
FUN_0082ce20(this)                // menu hash teardown
EH = -1
FUN_00792c20(this)                // CNDUIDialog complete
SEH epilogue; ADD ESP,0x10; RET
```

| Stage | Match | Conf |
|---|---|---|
| Intermediate vtbl install | Yes | **High** |
| Hash helper then base complete | Yes | **High** |
| Complete (no delete this) | Yes | **High** |
| SEH / ADD ESP,0x10 | Yes | **High** |
| Product = CVOGMenu | Yes (RTTI) | **High** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | wrapper (thin intermediate complete) |
| Callers | scalar `004166d0`; CMenuChatlog complete; other menu completes; Unwind |
| Callees | `FUN_0082ce20`, `FUN_00792c20` |

Vtbl `0x00a72f6c`: [0]=`0x004166d0`, [1]=`0x00790cc0`, [2]=`0x007a7de0`, [3]=`0x007567e0`.

---

## 6. Gaps

1. Dual residual of menu hash helper `0082ce20` (field English).  
2. Vtbl slots [1+] English.  
3. Runtime / bit-exact / differential — open.

---

## 7. Verdict

ABI/SEH, intermediate vtbl install, hash+base-complete chain, complete-vs-scalar, and **RTTI product name CVOGMenu** sealed. Residual helper dual + runtime → **accept-with-gaps**.
