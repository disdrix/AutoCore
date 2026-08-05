# Review A (reconstruction fidelity): `aa_0040d5b0` StdTree_Clear_PtrVal_Vtbl0C

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d5b0` |
| **VA** | `0x0040d5b0`–`0x0040d62a` (**123 B**) |
| **Canonical name** | `StdTree_Clear_PtrVal_Vtbl0C` |
| **Ghidra name** | `FUN_0040d5b0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W30-P) |
| **Counterpart** | `reviews/B_aa_0040d5b0_StdTree_Clear_PtrVal_Vtbl0C.md` |
| **System** | MSVC `_Tree` clear / Val12 + pointer values |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full body hex) + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Clear a Val12 red-black tree hosted at `this+8`/`this+0xc`: destroy each `T*` value via thiscall `vtbl[+0x0c]`, free all nodes, reset empty sentinel.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W30-P append) | `docs/reconstruction/raw/aa_0040d5b0_FUN_0040d5b0.md` |
| Annotated | `docs/reconstruction/raw/aa_0040d5b0_FUN_0040d5b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Clear_PtrVal_Vtbl0C.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_0040d5b0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0040d5b0_StdTree_Clear_PtrVal_Vtbl0C.md` |
| Inc dual | `aa_005ae0b0` StdTree_Inc_Val12 (W28-N **accept**) |
| Live | decompile ≡ value-loop CF; free path sealed from full-body hex |

---

## 3. Signature (sealed)

```c
// ECX = tree host; bare C3; void
void __fastcall StdTree_Clear_PtrVal_Vtbl0C(void* self);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`8B F1`) | **High** |
| return | void | **High** |
| cleanup | bare `C3` | **High** |

---

## 4. Control flow (bytes authority)

```
// destroy values
it = head->left
while it != head:
  obj = *(it+0x14)
  obj->vtbl[+0x0c]()          // thiscall
  StdTree_Inc_Val12(&it)

// free nodes
root = head->parent
if !root.isnil:
  node = root
  while !node.isnil:
    FUN_0040d630(node.right)  // ECX = this+4
    left = node.left
    operator_delete(node)
    node = left

// empty reset
head.parent = head; size = 0; head.left = head; head.right = head
```

| Stage | Match | Conf |
|---|---|---|
| Value loop + Inc | decompile ≡ bytes | **High** |
| vtbl[+0xc] on `*(node+0x14)` | `8B 48 14; 8B 01; FF 50 0C` | **High** |
| Free left-walk | bytes (decompiler collapsed) | **High** |
| Empty sentinel reset | decompile ≡ bytes | **High** |
| Val12 isnil@+0x19 | `80 7B 19 00` / family | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (123 B) — see raw W30-P append.

Entry: `51 53 56 8B F1` (push ecx/ebx/esi; mov esi,ecx).  
Epilogue: `5F 5E 5B 59 C3`.  
Pad `CC` then `FUN_0040d630`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | `FUN_0040d820` (complete dtor of `PTR_FUN_009c7938`); DATA vtbl[2] |
| Callees | `FUN_005ae0b0`, `FUN_0040d630`, `operator_delete` |

---

## 7. Gaps

1. Product/MSVC demangle for map instantiation and vtbl[+0xc] method English.  
2. Nested free helper `FUN_0040d630` not dual-owned here.  
3. Host class full layout beyond head/size (parent dual).  
4. Runtime / bit-exact / differential — open.

---

## 8. Verdict

Value-destroy CF, ABI, Val12 layout hooks, free-loop bytes, and empty reset are sealed. Residual product types + nested free helper → **accept-with-gaps**.
