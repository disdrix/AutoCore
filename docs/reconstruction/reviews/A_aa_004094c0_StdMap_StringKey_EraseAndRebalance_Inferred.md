# Review A (reconstruction fidelity): `aa_004094c0` StdMap_StringKey_EraseAndRebalance_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004094c0` |
| **VA** | `0x004094c0` |
| **Body** | `0x004094c0`–`0x0040977d` exclusive (**701** B / `0x2BD`) |
| **Canonical name** | `StdMap_StringKey_EraseAndRebalance_Inferred` |
| **Ghidra symbol** | `FUN_004094c0` |
| **Review date** | `2026-08-04` (WQ9J-F OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_004094c0_StdMap_StringKey_EraseAndRebalance_Inferred.md` |
| **System** | MSVC `std::_Tree` erase + RB rebalance (StringKey / isnil@+0x2D) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` / `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Erase one red-black tree node (string key @+0x0C, isnil@+0x2D): nil-iterator throw, capture successor, unlink, rebalance if erased black, destroy string, free node, size--, write out-iterator.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ WQ9J-F re-verify) | `docs/reconstruction/raw/aa_004094c0_FUN_004094c0.md` |
| Annotated | `docs/reconstruction/raw/aa_004094c0_FUN_004094c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_StringKey_EraseAndRebalance_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_004094c0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004094c0_StdMap_StringKey_EraseAndRebalance_Inferred.md` |
| Live body | `read_memory` entry/mid/epilogue; string @ `0x00a152f0` |
| Caller | `FUN_00407f90` + assembly context @ `0x0040802e` |
| Insert peer | dual `StdMap_StringKey_InsertNodeAndRebalance` @ `0x00430b60` |

---

## 3. Calling convention (assembly-sealed)

| Slot | Role | Evidence |
|---|---|---|
| stack0 | MapShell* | decompile `param_1+4` head / `+8` size; caller push |
| stack1 | outIt** | epilogue `mov [eax], edx` |
| stack2 | node* | early load; isnil check `+0x2d` |
| cleanup | **`ret 0x0C`** | `C2 0C 00` @ `0x0040977a` |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span + `ret 0x0C` | **Confirmed** | bytes past false noreturn |
| Single-node erase (not range) | **Confirmed** | range is caller loop |
| isnil@+0x2D / color@+0x2C | **Confirmed** | opcodes + recolor path |
| string key @+0x0C | **Confirmed** | `~basic_string(param_3+3)` |
| Throw plate | **Confirmed** | `"invalid map/set<T> iterator"` |
| size-- when size>0 | **Confirmed** | epilogue `test eax; jbe; add -1; mov [ecx+8]` |
| L/R rotates isnil2d pair | **Confirmed** | `0044e010` / `0042a840` |
| StringKey family vs insert peer | **High** | shared layout with `00430b60` |
| Product map English name | **Open** | `_Inferred` |
| Runtime / bit-exact / differential | **Open** | deferred |

---

## 5. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| isnil throw | **Yes** |
| successor prep `FUN_0042ac40` | **Yes** |
| unlink + extremity fix (min/max) | **Yes** |
| RB rebalance if black | **Yes** (decomp may mark mid blocks unreachable) |
| ~string + delete + size-- + *outIt + ret 0xC | **Yes** (bytes seal epilogue) |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| invalid map/set iterator string | **Yes** |
| basic_string key dtor | **Yes** |
| color/isnil match StringKey insert peer | **Yes** |
| Product/PDB English host type | **No** |

**Decision:** promote **`StdMap_StringKey_EraseAndRebalance_Inferred`**. Reject freelist; reject isnil29 erase merge; reject void/noreturn-on-delete as full body.

---

## 7. Gaps

1. Product/PDB demangle for host map type.
2. Dual of erase-range parent `FUN_00407f90` and rotate/min/max helpers.
3. Full two-child successor-swap plate fidelity (decomp unreachable warnings).
4. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**
