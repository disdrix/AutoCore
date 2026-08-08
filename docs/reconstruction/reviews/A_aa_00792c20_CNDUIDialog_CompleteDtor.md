# Review A (reconstruction fidelity): `aa_00792c20` CNDUIDialog_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00792c20` |
| **VA** | `0x00792c20`–`0x00792d12` (**243 B** true); Ghidra DB end `00792ceb` truncated |
| **Canonical name** | `CNDUIDialog_CompleteDtor` |
| **Ghidra name** | `FUN_00792c20` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9K-G) |
| **Counterpart** | `reviews/B_aa_00792c20_CNDUIDialog_CompleteDtor.md` |
| **System** | MSVC shared UI base complete dtor — `CNDUIDialog` / `PTR_FUN_00a98f44` |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` (full body incl. tail past delete) + xrefs + `disassemble_function`. **No** `disassemble_bytes`. |
| **Partition** | `WAVE_2026-08-04_wq009_depth8_partition_map.md` → **WQ9K-G** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Shared complete destructor for product class **CNDUIDialog**: install `PTR_FUN_00a98f44`, tear down child hash + owned helpers + list shell + member at `+0x4e0`, chain deeper window complete `FUN_007b5be0`. Does not free host `this`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ WQ9K-G) | `docs/reconstruction/raw/aa_00792c20_FUN_00792c20.md` |
| Annotated | `docs/reconstruction/raw/aa_00792c20_FUN_00792c20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDUIDialog_CompleteDtor.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00792c20.cpp` |
| Function record | `docs/reconstruction/functions/aa_00792c20_CNDUIDialog_CompleteDtor.md` |
| Intermediate caller | `FUN_0082d540` CVOGMenu_CompleteDtor (OWN WQ9K-G) |
| Scalar caller | `FUN_004280d0` (vtbl[0]) |
| Peer ctor | `FUN_00792d20` (prior NDUIContainerPanel_Ctor_Inferred) |
| Deep base | `FUN_007b5be0` (not OWN) |
| RTTI | COL `0x00ab7e6c` → type_info `0x00afe1c8` → `.?AVCNDUIDialog@@` |
| Live | decompile truncated at member delete; **bytes seal** zero + `CALL 007b5be0` + `ADD ESP,0x10; RET` |

---

## 3. Signature (sealed)

```c
// ECX = this; SEH; ADD ESP,0x10; RET; void; complete dtor
void __fastcall CNDUIDialog_CompleteDtor(void* self);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`8B F9`) | **High** |
| epilogue | `83 C4 10; C3` @ `00792d0f` | **High** (bytes; past Ghidra end) |
| free this? | no | **High** |

---

## 4. Control flow (bytes authority)

```
SEH prologue (LAB_009b4054)
*this = PTR_FUN_00a98f44          // C7 07 44 8F A9 00
EH = 1
FUN_007917c0(this)                // child hash @ +0x4c0
scalar_delete_if(+0x4c0)
// skip +0x4c4
scalar_delete_if(+0x4c8..+0x4d8)  // five more
LEA ESI,[this+0x4dc]; FUN_00415e90()
operator_delete([this+0x4e0]); ADD ESP,4; [this+0x4e0]=0   // RETURNS
EH = -1
FUN_007b5be0(this)                // deeper window complete
SEH epilogue; ADD ESP,0x10; RET
```

| Stage | Match | Conf |
|---|---|---|
| Shared vtbl install | Yes | **High** |
| Owned slot teardown + skip +0x4c4 | Yes | **High** |
| Member delete returns (not host) | Yes | **High** (bytes) |
| Base chain `007b5be0` | Yes | **High** |
| Complete (no delete this) | Yes | **High** |
| Product = CNDUIDialog | Yes (RTTI) | **High** |
| Decompiler full body | **No** | truncated — prefer bytes |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (fat complete over helpers + deep base) |
| Callers | hundreds (CVOGMenu, CWndTutorial, grids, …) + Unwind |
| Callees | `007917c0`, `00415e90`, `operator_delete`, `007b5be0` |

Vtbl `0x00a98f44`: [0]=`0x004280d0`, [1]=`0x00790cc0`, [2]=`0x007a7de0`, [3]=`0x007567e0`.

---

## 6. Gaps

1. English roles of owned slots / list shell / `+0x4e0`.  
2. Dual residual of `007917c0` / `00415e90` / `007b5be0`.  
3. Ghidra function-body repair residual.  
4. Runtime / bit-exact / differential — open.

---

## 7. Verdict

ABI/SEH, shared vtbl install, owned-offset map, member-free-returns, deep base chain, complete-vs-scalar, and **RTTI product name CNDUIDialog** sealed (bytes correct decompiler tail). Residual helper duals + slot English + runtime → **accept-with-gaps**.
