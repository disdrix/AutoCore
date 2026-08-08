# Review A (reconstruction fidelity): `aa_00402850` StdTree_EraseAndRebalance_Isnil29_RetC_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402850` |
| **VA** | `0x00402850` |
| **Body** | `0x00402850`–`0x00402ae0` exclusive (**656** B / `0x290`) |
| **Canonical name** | `StdTree_EraseAndRebalance_Isnil29_RetC_Inferred` |
| **Ghidra name** | `FUN_00402850` |
| **Review date** | `2026-08-05` (MEGA-034 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00402850_StdTree_EraseAndRebalance_Isnil29_RetC_Inferred.md` |
| **System** | MSVC `std::_Tree` erase + RB rebalance (isnil@+0x29, stack RET 0xC) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs + `get_assembly_context` + `disassemble_function`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Erase one red-black tree node (isnil@+0x29, color@+0x28): nil-iterator throw, capture successor via iterator++ isnil29, unlink (incl. two-child successor-swap), rebalance if erased black, free node (no value dtor), size--, write out-iterator. Stack ABI with **`ret 0x0C`**.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ MEGA-034 re-verify) | `docs/reconstruction/raw/aa_00402850_FUN_00402850.md` |
| Annotated | `docs/reconstruction/raw/aa_00402850_FUN_00402850.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Isnil29_RetC_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00402850.cpp` |
| Function record | `docs/reconstruction/functions/aa_00402850_StdTree_EraseAndRebalance_Isnil29_RetC_Inferred.md` |
| Live body | `read_memory` entry/epilogue; string @ `0x00a152f0` |
| Callers | `FUN_004079a0`, `FUN_00407bf0`, `Client_Input_OnKeyDown_MatchAction`, `FUN_00942e20`, `FUN_00944d50` |
| Dualed throw ctor | `Std_OutOfRange_CtorFromString` @ `0x00401bc0` |
| Twin stack erase | dualed `StdTree_EraseAndRebalance_Isnil31_Inferred` @ `0x00408ed0` |

---

## 3. Calling convention (assembly-sealed)

| Slot | Role | Evidence |
|---|---|---|
| stack0 | MapShell* | prolog `MOV EBP,[ESP+0x58]` after SEH; `EBP+4` head / `EBP+8` size |
| stack1 | outIt** | epilogue `mov [eax], edx` |
| stack2 | node* | early `MOV EAX,[ESP+0x18]`; isnil check `+0x29` |
| cleanup | **`ret 0x0C`** | `C2 0C 00` @ `0x00402add` |
| Call sites | 3× PUSH | `00407a3e`, `00911260`, etc. (map / outIt / node) |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span + `ret 0x0C` | **Confirmed** | bytes past false noreturn |
| Single-node erase (not range) | **Confirmed** | range is callers `FUN_004079a0` / `FUN_00407bf0` loops |
| isnil@+0x29 / color@+0x28 | **Confirmed** | opcodes `80 78 29 00`, `CMP [EAX+0x28]` |
| Throw plate | **Confirmed** | `"invalid map/set<T> iterator"` @ `0x00a152f0` |
| size-- when size>0 | **Confirmed** | epilogue `test eax; jbe; add -1; mov [ebp+8]` |
| Succ via iterator++ isnil29 | **Confirmed** | `CALL FUN_004040a0` |
| Min/max extremity fix | **Confirmed** | `004031e0` / `004031c0` |
| No value dtor | **Confirmed** | bare `operator_delete` only |
| Distinct from thiscall isnil29 erase | **Confirmed** | ABI + rotate helpers differ from `004cb740` |
| Product map English name | **Open** | `_Inferred` / RetC qualifier |
| Runtime / bit-exact / differential | **Open** | deferred |

---

## 5. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| isnil throw | **Yes** |
| successor prep `FUN_004040a0` | **Yes** |
| unlink + extremity fix (min/max) | **Yes** |
| two-child successor-swap @ `0x00402949` | **Yes** (bytes; decomp "unreachable") |
| RB rebalance if black | **Yes** |
| delete + size-- + *outIt + ret 0xC | **Yes** (bytes seal epilogue) |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| invalid map/set iterator string | **Yes** |
| color/isnil match isnil29 family (+0x28/+0x29) | **Yes** |
| Stack 3-arg RET 0xC (not thiscall RET 8) | **Yes** → **RetC** qualifier |
| No string/value dtor (contrast Val28 / StringKey) | **Yes** |
| Product/PDB English host type | **No** |
| Scaffold `Named_CalleeOf_*` | **Retired** — role is tree erase, not input-specific |

**Decision:** promote **`StdTree_EraseAndRebalance_Isnil29_RetC_Inferred`**. Reject freelist; reject merge with thiscall isnil29 `004cb740`, Val28 `00603830`, isnil31 `00408ed0`; reject void/noreturn-on-delete as full body; reject product invent from OnKeyDown caller alone.

---

## 7. Gaps

1. Product/PDB demangle for host map type / value payload English.
2. Dual of erase-range parents `FUN_004079a0` / `FUN_00407bf0` and rotate/min helpers.
3. Full two-child successor-swap plate fidelity (decomp unreachable warnings).
4. Runtime / bit-exact / image diff.
