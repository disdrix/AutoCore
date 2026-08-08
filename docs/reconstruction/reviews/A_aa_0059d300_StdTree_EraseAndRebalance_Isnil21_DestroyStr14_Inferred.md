# Review A (reconstruction fidelity): `aa_0059d300` StdTree_EraseAndRebalance_Isnil21_DestroyStr14_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059d300` |
| **VA** | `0x0059d300` |
| **Body** | `0x0059d300`–`0x0059d5d2` inclusive (**723 B** / `0x2D3`) |
| **Canonical name** | `StdTree_EraseAndRebalance_Isnil21_DestroyStr14_Inferred` |
| **Ghidra name** | `FUN_0059d300` |
| **Review date** | `2026-08-05` (R12-029 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0059d300_StdTree_EraseAndRebalance_Isnil21_DestroyStr14_Inferred.md` |
| **System** | skills-abilities — MSVC `std::_Tree` erase + RB rebalance (isnil@+0x21) + DestroyStr14 |
| **Parent dual** | `0x005a27f0` StdTree_Rrotate_Isnil21_Inferred (R11-007) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_callers` / `get_function_xrefs` + `read_memory` + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Erase one red-black tree node (isnil@+0x21, color@+0x20, node size 0x28): nil-iterator throw, capture successor via iterator++ isnil21, unlink, rebalance if erased black, **DestroyStr14** (free heap at +0x14 + zero three dwords), free node, size--, write out-iterator.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ R12-029 re-verify) | `docs/reconstruction/raw/aa_0059d300_FUN_0059d300.md` |
| Annotated | `docs/reconstruction/raw/aa_0059d300_FUN_0059d300.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Isnil21_DestroyStr14_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_0059d300.cpp` |
| Function record | `docs/reconstruction/functions/aa_0059d300_StdTree_EraseAndRebalance_Isnil21_DestroyStr14_Inferred.md` |
| Live body | `read_memory` entry/epilogue; string @ `0x00a152f0` |
| Caller | `FUN_0059d620` + assembly context @ `0x0059d6bf` |
| Parent Rrotate | dual `StdTree_Rrotate_Isnil21_Inferred` @ `0x005a27f0` (R11-007) |
| Peer Lrotate | dual `StdTree_Lrotate_Isnil21_Inferred` @ `0x0050e9f0` |
| Peer no-dtor erase | `0x00405650` / `0x004e3e70` (same family, **no** DestroyStr14) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden, parent ledgers.

---

## 3. Calling convention (assembly-sealed)

| Slot | Role | Evidence |
|---|---|---|
| ECX | MapShell* | entry `mov ebx,ecx`; caller `MOV ECX,EDI` |
| stack0 | outIt** | epilogue `mov [eax], ecx` |
| stack1 | node* | early `mov eax,[esp+0x5c]`; isnil `+0x21` |
| cleanup | **`ret 8`** | `C2 08 00` @ `0x0059d5d0` |

---

## 4. Byte / constant seal

| Item | Evidence |
|---|---|
| Body inclusive end | `0x0059d5d2` (`CC` pad after last `C2 08 00`) |
| Size | **723** B / `0x2D3` |
| isnil test | `80 78 21 00` on node |
| color black test | `param_3[8] == 1` → color@+0x20 |
| DestroyStr14 | `mov eax,[ebp+0x14]`; free if non-null; zero +0x14/18/1C |
| size-- | `mov eax,[ecx+8]`; `jbe`; `add eax,-1`; `mov [ecx+8],eax` |
| Throw string | `"invalid map/set<T> iterator"` @ `0x00a152f0` |
| Callers / xrefs | 1 / 1 UNCONDITIONAL_CALL |

---

## 5. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF (throw/unlink/RB) | **pass** |
| Body size inclusive end | **pass** (`0059d5d2`) |
| `RET 8` / thiscall 2 stack args | **pass** |
| isnil@+0x21 / color@+0x20 | **pass** |
| DestroyStr14 (differs from 00405650/004e3e70) | **pass** |
| size-- + *outIt past false noreturn | **pass** (bytes) |
| Rotates L `0050e9f0` / R `005a27f0` | **pass** |
| Product demangle | **gap** |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | live ≡ raw; RET 8 sealed |
| Single-node erase (not range) | **High** | range is caller `FUN_0059d620` |
| isnil@+0x21 layout | **High** | bytes + parent dual family |
| DestroyStr14 | **High** | free+zero path in epilogue bytes |
| Name `…_DestroyStr14_Inferred` | **Inferred** | structural; product English open |
| Two-child successor-swap plate | Medium | decomp unreachable mid blocks |
| Runtime / differential | Open | |

---

## 7. Naming gate

| Evidence | Present? |
|---|---|
| invalid map/set iterator string | **Yes** |
| color/isnil match isnil21 family (rotates/succ/min) | **Yes** |
| DestroyStr14 (not bare delete only) | **Yes** |
| Parent dual Rrotate isnil21 | **Yes** (`005a27f0`) |
| Product/PDB English host type | **No** |

**Decision:** promote **`StdTree_EraseAndRebalance_Isnil21_DestroyStr14_Inferred`**. Reject merge with no-dtor isnil21 erase clones; reject isnil29/2d/31 erase; reject freelist; reject void/noreturn-on-delete as full body; reject skill-only product alias.

---

## 8. Gaps

1. Product/PDB demangle for host map type / value payload English.
2. Full two-child successor-swap plate fidelity (decomp unreachable warnings).
3. Dual of erase-range parent `FUN_0059d620` and residual succ/min/max helpers.
4. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**
