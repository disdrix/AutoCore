# Review A (reconstruction fidelity): `aa_0040d820` StdTreeHost_PtrVal_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d820` |
| **VA** | `0x0040d820`–`0x0040d86f` (**80 B**) |
| **Canonical name** | `StdTreeHost_PtrVal_CompleteDtor` |
| **Ghidra name** | `FUN_0040d820` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W31-A) |
| **Counterpart** | `reviews/B_aa_0040d820_StdTreeHost_PtrVal_CompleteDtor.md` |
| **System** | MSVC host complete dtor — Val12 pointer-value tree |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (body + vtbl) + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Complete destructor for host of Val12 pointer-value tree (`PTR_FUN_009c7938`): install vtbl, clear tree, teardown tree subobject at `this+4`. Does not free `this`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W31-A append) | `docs/reconstruction/raw/aa_0040d820_FUN_0040d820.md` |
| Annotated | `docs/reconstruction/raw/aa_0040d820_FUN_0040d820.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTreeHost_PtrVal_CompleteDtor.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0040d820.cpp` |
| Function record | `docs/reconstruction/functions/aa_0040d820_StdTreeHost_PtrVal_CompleteDtor.md` |
| Clear dual | `aa_0040d5b0` StdTree_Clear_PtrVal_Vtbl0C (W30-P) |
| Free-subtree dual | `aa_0040d630` StdTree_FreeSubtree_Val12 (this wave) |
| Live | decompile ≡ stage order; `this+4` sealed from bytes |

---

## 3. Signature (sealed)

```c
// ECX = this; SEH; ADD ESP,0x10; RET; void; complete dtor
void __fastcall StdTreeHost_PtrVal_CompleteDtor(TreeHost_Head8* self);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`8B F1`) | **High** |
| epilogue | `83 C4 10; C3` | **High** |
| free this? | no | **High** |

---

## 4. Control flow (bytes authority)

```
SEH prologue (LAB_009be2bb)
*this = PTR_FUN_009c7938
EH=0; FUN_0040d5b0(this)          // clear
EH=-1; FUN_0040d7c0(this+4)       // LEA ECX,[ESI+4]
SEH epilogue; ADD ESP,0x10; RET
```

| Stage | Match | Conf |
|---|---|---|
| Vtbl install | `C7 06 38 79 9C 00` | **High** |
| Clear ECX=this | call before LEA | **High** |
| `FUN_0040d7c0` this+4 | `8D 4E 04; E8 …` | **High** |
| Complete (no delete this) | no `operator_delete(self)` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (80 B) — see raw W31-A append.

Vtbl `0x009c7938`: slot0 `0x0040d590` (scalar), slot2 `0x0040d5b0` (clear).

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (complete dtor body) |
| Callers | `FUN_0040d590` scalar; `FUN_0040d890` derived complete; Unwind |
| Callees | `FUN_0040d5b0`, `FUN_0040d7c0` |

---

## 7. Gaps

1. Product/MSVC demangle for host class and map T.  
2. Nested `FUN_0040d7c0` full product meaning (not owned).  
3. Vtbl slot[1] `0x00489918`.  
4. Runtime / bit-exact / differential — open.

---

## 8. Verdict

Stage order, ABI/SEH, vtbl install, clear + `this+4` teardown sealed. Residual product + nested head free → **accept-with-gaps**.
