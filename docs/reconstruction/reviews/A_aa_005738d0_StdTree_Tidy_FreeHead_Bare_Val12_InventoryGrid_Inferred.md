# Review A (reconstruction fidelity): `aa_005738d0` StdTree_Tidy_FreeHead_Bare_Val12_InventoryGrid_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005738d0` |
| **VA** | `0x005738d0`–`0x005738fc` inclusive (**45 B** / `0x2D`) |
| **Canonical name** | `StdTree_Tidy_FreeHead_Bare_Val12_InventoryGrid_Inferred` |
| **Ghidra name** | `FUN_005738d0` |
| **Prior scaffold** | `FUN_005738d0` |
| **Rejected misname** | host complete dtor / free-this / partial erase-only |
| **Review date** | `2026-08-05` (R11-004 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_005738d0_StdTree_Tidy_FreeHead_Bare_Val12_InventoryGrid_Inferred.md` |
| **System** | inventory-transfer / MSVC `_Tree` bare tidy Val12 |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/callees/xrefs + `get_function_signature`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Bare Val12 tree tidy (no SEH): full-range erase via dualed InventoryGrid `StdTree_EraseRange_Val12_InventoryGrid_Inferred` (`0x00573700`), free header sentinel, null `head` and `size`. Peer of dualed `StdTree_Tidy_FreeHead_Bare_Val12` @ `0x0040d6d0` with erase leaf remapped to InventoryGrid.

```text
StdTree_Tidy_FreeHead_Bare_Val12_InventoryGrid_Inferred(map)
  EraseRange_InventoryGrid(map, &out, head->left, head)
  operator_delete(head)
  map->head = 0; map->size = 0
  RET  // bare; map shell not freed
```

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ scaffold CF (truncated after delete) |
| Full body | `disassemble_function` + `read_memory` **45 B** |
| Peer bare tidy | dualed `StdTree_Tidy_FreeHead_Bare_Val12` @ `0x0040d6d0` (W33-A) — hex clone except CALL relocs |
| Erase leaf | dualed `StdTree_EraseRange_Val12_InventoryGrid_Inferred` @ `0x00573700` (MEGA-120) |
| Unwind xrefs | 3 UNCONDITIONAL_CALL; two stubs `ADD ECX,0x5c` then `JMP` |
| Layout | InventoryGrid shell @ `+0x5c` / head `+0x60` / size `+0x64` |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Signature (sealed)

```c
// ECX=map; bare RET (C3); void
void __fastcall StdTree_Tidy_FreeHead_Bare_Val12_InventoryGrid_Inferred(
    StdTreeShell_Val12* map);
```

| Formal | Source | Conf |
|---|---|---|
| map | ECX → ESI (`MOV ESI,ECX`) | **Confirmed** |
| head@+4 | load / free / null | **Confirmed** |
| size@+8 | null store | **Confirmed** |
| cleanup | `RET` (`C3`) @ `0x005738fc` | **Confirmed** |
| free this? | no (frees head only) | **Confirmed** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| Full-range erase args `*head`, `head` | bytes + decomp | **Confirmed** |
| CALL erase `00573700` thiscall ECX=map | `MOV ECX,ESI; CALL` | **Confirmed** |
| `operator_delete(head)` cdecl + `ADD ESP,4` | bytes | **Confirmed** |
| Null head+size after delete | bytes (decomp drops) | **Confirmed** |
| Bare RET / no SEH | single BB, `C3` | **Confirmed** |
| Body 45 B / peer clone | hex compare to `0040d6d0` | **Confirmed** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | **worker** |
| Callers (3) | Unwind `@009a4f37`, `@009a4f57`, `@009a4f91` |
| Callees | `FUN_00573700`, `operator_delete` |
| Xrefs | 3 UNCONDITIONAL_CALL (unwind only) |

---

## 6. Gaps (non-blocking)

1. Product/MSVC demangle for map `T` / key English.  
2. Enclosing class identity per unwind frame (beyond `+0x5c` shell).  
3. Runtime / bit-exact / differential open.

---

## 7. Verdict rationale

**accept-with-gaps** — ABI (ECX map shell / bare RET), tidy order (erase → free head → null), InventoryGrid erase leaf, peer-clone shape, and `+0x5c` unwind ownership are sealed from live decompile + bytes + xrefs. Gaps are product naming and runtime, not ABI risk. Terminal **false** (no runtime Confirmed).
