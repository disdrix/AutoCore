# Review A (reconstruction fidelity): `aa_0040bc10` StdTree_EraseRange_Isnil19_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040bc10` |
| **VA** | `0x0040bc10`–`0x0040bcc2` exclusive (**178 B** / `0xB2`) |
| **Canonical name** | `StdTree_EraseRange_Isnil19_Inferred` |
| **Ghidra name** | `FUN_0040bc10` |
| **Review date** | `2026-08-05` (R13-020 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0040bc10_StdTree_EraseRange_Isnil19_Inferred.md` |
| **System** | inventory-transfer (partition); unit role = MSVC `std::_Tree` range erase isnil@+0x19 |
| **Parent dual** | `0x0092b2a0` (not dualled here) |
| **Dual start** | 2686 |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` (body + free `0040c100`) + `get_function_callers` / `get_function_xrefs` + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC-style red-black **map/set range erase** `[first, last)` for the **isnil@+0x19** (Val12) node family. Full-range fast path frees the tree via residual `FUN_0040c100` (free-subtree isnil19, ECX-threaded map, RET 4) then resets head/size; partial path inlines in-order successor (isnil@+0x19) then residual single-erase `FUN_0040b440` (R13-018 queue). Register-this **EDI** = map shell (not ECX thiscall).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ raw CF (2026-08-05); `unaff_EDI` = map |
| Bytes | `read_memory` 192 B @ `0040bc10`; dual epilogues `C2 0C 00`; free rel → `0040c100`; erase rel → `0040b440` |
| Free subtree | residual `FUN_0040c100` — isnil@+0x19; right recurse + left walk + `operator_delete`; RET 4 (`read_memory` 64 B) |
| Single erase | residual `FUN_0040b440` — isnil@+0x19 / color@+0x18; invalid-iterator throw; `FUN_00457cc0` successor; rebalance + `operator_delete` |
| Peer (do not merge) | dualed `StdTree_EraseRange_Val12` `0x0040d700` (ECX-thiscall; free `0040d630`; erase `004188e0`) |
| Callers | `FUN_0040b2d0`, `FUN_0040b410`, `FUN_0092b2a0` (×2 sites) |

---

## 3. Signature (sealed)

```c
// Register-this EDI; stack outIt / first / last; RET 0x0C; EAX = outIt
Node** StdTree_EraseRange_Isnil19_Inferred(
    /*EDI*/ MapShell* map, Node** outIt, Node* first, Node* last);
```

| Formal | Source | Conf |
|---|---|---|
| map | **EDI** (`MOV EAX,[EDI+4]` entry; callers `LEA EDI,…` / `MOV EDI,…`) | **High** |
| outIt / first / last | stack (`EBP`/`ESI`/`EBX` loads after PUSH) | **High** |
| cleanup | `POP ESI; MOV EAX,EBP; POP EBP; POP EBX; RET 0x0C` both exits | **High** |
| return | EAX = outIt | **High** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| Full clear: `first==head->left && last==head` | decomp ≡ bytes @ `0040bc22`–`0040bc28` | **High** |
| FreeSubtree(`head->parent`): `PUSH root; MOV ECX,EDI; CALL 0040c100` | rel `E8 CB040000` → `0040c100` | **High** |
| Head reset + size 0 + `*outIt=head->left` | bytes `0040bc35`–`0040bc56` | **High** |
| Partial: inline successor isnil@+0x19 then `PUSH node; LEA &outIt; PUSH EDI; CALL 0040b440` | bytes `0040bc61`–`0040bcb5` | **High** |
| `*outIt = first/next`; **RET 0x0C** ×2 | `C2 0C 00` @ `0040bc5a` / `0040bcbf` | **High** |
| Decompile ≡ raw CF | yes (ABI register-this via bytes + call-site EDI) | **High** |

Layout sealed from this body + erase callee: left@0, parent@4, right@8, color@**+0x18**, isnil@**+0x19**; shell head@+4, size@+8 (Val12 / node ~0x1c).

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| External callers | 3 functions / **4** UNCONDITIONAL_CALL sites |
| Xrefs | `0040b2fe` (`FUN_0040b2d0`), `0040b420` (`FUN_0040b410`), `0092b8fc` + `0092b947` (`FUN_0092b2a0`) |
| Call-site ABI | Parent / tidy wrappers preload **EDI** = map shell; push out / begin / end; post-call often `operator_delete(head)` via `00489822` |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| STL range-erase structure (full free + partial succ/erase) | **Yes** |
| isnil@+0x19 on successor and free/erase callees | **Yes** |
| Distinct clone from ECX Val12 peer `0040d700` | **Yes** (EDI + free `0040c100` + erase `0040b440`) |
| Product/PDB English | **No** |

**Decision:** promote **`StdTree_EraseRange_Isnil19_Inferred`**. Product demangle open → `_Inferred`. Not inventory-product-specific despite partition system.

---

## 7. Gaps

- Product map value_type / demangle (Val12 payload English).
- Residual undualed: free `0040c100`, single erase `0040b440` (R13-018), tidy wrappers `0040b2d0` / `0040b410`, parent `0092b2a0`.
- Free path value-dtor policy (body is `operator_delete` only — same plate as dualed Val12 free).
- Runtime / bit-exact / differential.

---

## 8. Verdict

CF/ABI/EDI-map/RET0xC/isnil19 full-clear+partial sealed; product + callee duals open → **accept-with-gaps**.
