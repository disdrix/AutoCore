# Review A (reconstruction fidelity): `aa_00405650` StdTree_EraseAndRebalance_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00405650` |
| **VA** | `0x00405650` |
| **Body** | `0x00405650`–`0x004058e4` exclusive (**660** B / `0x294`) |
| **Canonical name** | `StdTree_EraseAndRebalance_Isnil21_Inferred` |
| **Ghidra name** | `FUN_00405650` |
| **Review date** | `2026-08-05` (R12-009 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00405650_StdTree_EraseAndRebalance_Isnil21_Inferred.md` |
| **System** | skills-abilities — MSVC `std::_Tree` erase + RB rebalance (isnil@+0x21) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Erase one red-black tree node (isnil@+0x21, color@+0x20, node size 0x28): nil-iterator throw, capture successor via iterator++ isnil21 (`FUN_004e12c0`), unlink (incl. two-child successor-swap), rebalance if erased black, free node (no value dtor), size--, write out-iterator. **`__thiscall` + `ret 8`**.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ R12-009 re-verify) | `docs/reconstruction/raw/aa_00405650_FUN_00405650.md` |
| Annotated | `docs/reconstruction/raw/aa_00405650_FUN_00405650.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Isnil21_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00405650.cpp` |
| Function record | `docs/reconstruction/functions/aa_00405650_StdTree_EraseAndRebalance_Isnil21_Inferred.md` |
| Live body | `read_memory` entry/epilogue; string @ `0x00a152f0` |
| Callers | `FUN_00407140` @ `0x004071df`; `FUN_00932c80` @ `0x00933018` |
| Parent dual | `StdTree_Rrotate_Isnil21_Inferred` @ `0x005a27f0` (R11-007) |
| Twin Lrotate | `FUN_0050e9f0` (R10 dualed) |
| Insert twin | `StdTree_InsertAndRebalance_Isnil21_Inferred` @ `0x00407200` |

---

## 3. Calling convention (assembly-sealed)

| Slot | Role | Evidence |
|---|---|---|
| ECX | MapShell* | prolog `MOV EBP,ECX`; call sites `MOV ECX,EDI` / `ADD ECX,0xed8` |
| stack0 | outIt** | epilogue `mov eax,[esp+0x5c]; mov [eax],ecx` |
| stack1 | node* | early `MOV EAX,[ESP+0x14]`; isnil check `+0x21` |
| cleanup | **`ret 8`** | `C2 08 00` @ `0x004058e1` |
| Call sites | 2× PUSH + ECX | `004071df`, `00933018` |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span + `ret 8` | **Confirmed** | bytes past false noreturn |
| Single-node erase (not range) | **Confirmed** | range is caller `FUN_00407140` loop |
| isnil@+0x21 / color@+0x20 | **Confirmed** | opcodes `80 78 21 00`, color `@+0x20` |
| Throw plate | **Confirmed** | `"invalid map/set<T> iterator"` @ `0x00a152f0` |
| size-- when size>0 | **Confirmed** | epilogue `test eax; jbe; add -1; mov [ebp+8]` |
| Succ via iterator++ isnil21 | **Confirmed** | `CALL FUN_004e12c0` |
| Min/max extremity fix | **Confirmed** | `004cb2c0` / `00421a60` |
| L/R rotate isnil21 | **Confirmed** | `0050e9f0` / `005a27f0` |
| No value dtor | **Confirmed** | bare `operator_delete` only |
| Thiscall RET 8 (not stack RET 0xC) | **Confirmed** | `C2 08 00` + ECX this |
| Product map English name | **Open** | `_Inferred` |
| Runtime / bit-exact / differential | **Open** | deferred |

---

## 5. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| isnil throw | **Yes** |
| successor prep `FUN_004e12c0` | **Yes** |
| unlink + extremity fix (min/max) | **Yes** |
| two-child successor-swap @ `0x0040574b` | **Yes** (bytes; decomp "unreachable") |
| RB rebalance if black | **Yes** |
| delete + size-- + *outIt + ret 8 | **Yes** (bytes seal epilogue) |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| invalid map/set iterator string | **Yes** |
| color/isnil match isnil21 family (+0x20/+0x21) | **Yes** |
| Thiscall RET 8 (matches isnil21 insert/rotate family ABI style) | **Yes** |
| No string/value dtor | **Yes** |
| Product/PDB English host type | **No** |
| skills-abilities system assignment | Partition map R12-009 only (structural role is generic STL erase) |

**Decision:** promote **`StdTree_EraseAndRebalance_Isnil21_Inferred`**. Reject freelist; reject merge with isnil29/isnil2d/isnil31 erase; reject void/noreturn-on-delete as full body; reject inventing product map English from `FUN_00932c80` host alone.

---

## 7. Gaps

1. Product/PDB demangle for host map type / value payload English (Val16 fields).
2. Dual of erase-range parent `FUN_00407140`, succ `FUN_004e12c0`, min/max helpers.
3. Full two-child successor-swap plate fidelity (decomp unreachable warnings).
4. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**
