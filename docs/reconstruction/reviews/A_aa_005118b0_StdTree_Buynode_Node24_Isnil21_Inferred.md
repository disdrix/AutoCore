# Review A (reconstruction fidelity): `aa_005118b0` StdTree_Buynode_Node24_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005118b0` |
| **VA** | `0x005118b0` |
| **Body** | `0x005118b0`–`0x00511935` inclusive (**134 B** / `0x86`) |
| **Canonical name** | `StdTree_Buynode_Node24_Isnil21_Inferred` |
| **Ghidra symbol** | `FUN_005118b0` |
| **Review date** | `2026-08-05` (R13-030 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_005118b0_StdTree_Buynode_Node24_Isnil21_Inferred.md` |
| **System** | skills-abilities / STL map-set buynode (Node24 isnil@+0x21) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_callers` / `get_function_xrefs` / `get_function_callees` + `read_memory` + `disassemble_function` + `get_function_by_address`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Allocate and construct one **Node24 / isnil@+0x21** tree node for parent always-insert `StdTree_InsertAndRebalance_Node24_Isnil21_Inferred` (`0x00511950`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ R13-030 re-verify) | `docs/reconstruction/raw/aa_005118b0_FUN_005118b0.md` |
| Annotated | `docs/reconstruction/raw/aa_005118b0_FUN_005118b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Buynode_Node24_Isnil21_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_005118b0.cpp` |
| Function record | `docs/reconstruction/functions/aa_005118b0_StdTree_Buynode_Node24_Isnil21_Inferred.md` |
| Live body bytes | `read_memory` @ `0x005118b0` (full body) / epilogue `C2 14 00` |
| Payload helper | residual `FUN_005114e0` decompile (vector elem stride 0x10) |
| Parent insert | dualed `0x00511950` (R12-014); call site `0x005119e2` |

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Body inclusive end | `0x00511935` (`RET 0x14` ends; next is EH tail then `CC` before `FUN_00511950`) |
| Size | **134** B / `0x86` |
| Epilogue | `RET 0x14` (`C2 14 00` @ `0x00511933`) |
| Alloc size | `PUSH 0x24` (`6A 24`) + `CALL operator_new` |
| Color write | `MOV [ESI+0x20], DL` (`88 56 20`) |
| isnil write | `MOV byte [ESI+0x21], 0` (`C6 46 21 00`) |
| Key write | `MOV [ESI+0x0C], ECX` from `*value` |
| Payload | `LEA ECX,[ESI+0x10]` + `CALL FUN_005114e0` |
| Stack args | `[EBP+8..+0x18]` = left, parent, right, value*, color |
| thiscall on entry | **No** — prolog `PUSH EBP; MOV EBP,ESP` only |
| Xrefs | 1 UNCONDITIONAL_CALL / 1 caller |

Key entry / construct / epilogue hex:

```
558bec6aff68e1349a00...6a24e8ba7ff7ff...885620c6462100...c21400
```

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw | **pass** |
| Body size inclusive end | **pass** (`00511935`) |
| `RET 0x14` / 5 stack args | **pass** |
| stdcall (not thiscall map) | **pass** |
| `operator_new(0x24)` | **pass** |
| color@+0x20 / isnil@+0x21 | **pass** |
| key@+0x0C + vec ctor @+0x10 | **pass** |
| Sole caller parent insert `00511950` | **pass** |
| Distinct from Val16 peer `00408990` | **pass** (node 0x24≠0x28; key@+0x0C path) |
| Clean has no bare `undefined4` | **pass** (`int32_t` / `uint8_t`) |
| Product demangle | **gap** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | live ≡ raw; RET 0x14 sealed |
| Buynode identity | **High** | new + construct + return node* |
| isnil@+0x21 / color@+0x20 / node 0x24 | **High** | bytes + parent family |
| Name `StdTree_Buynode_Node24_Isnil21_Inferred` | **Inferred** | structural; product English open |
| Runtime / differential | Open | |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Node size 0x24 + isnil@+0x21 | **Yes** |
| color@+0x20 from arg | **Yes** |
| Parent dual insert Node24 family | **Yes** (`00511950` R12-014) |
| Peer Val16 buynode dualed (distinct) | **Yes** (`00408990`) |
| Product/PDB English | **No** |

**Decision:** promote **`StdTree_Buynode_Node24_Isnil21_Inferred`**. Reject merge with Val16 peer `00408990`, Val24/isnil29 buynodes, freelist/CNDHash names, skill-only alias, thiscall-map mislabel.

---

## 7. Gaps

1. Product / MSVC demangle for value_type (int key + vector element type).
2. Full dual of residual vector ctor `FUN_005114e0` (R13-029, not OWN).
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
