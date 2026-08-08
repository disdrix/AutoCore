# Review A (reconstruction fidelity): `aa_00409f70` StdVector_PodCopyElement_0x10_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409f70` |
| **VA** | `0x00409f70`–`0x00409f8a` inclusive (**27 B** / `0x1B`) |
| **Canonical name** | `StdVector_PodCopyElement_0x10_Inferred` |
| **Prior scaffold** | `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_00409f70` (**retired**) |
| **Ghidra name** | `FUN_00409f70` |
| **Review date** | `2026-08-05` (R10-023 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00409f70_StdVector_PodCopyElement_0x10_Inferred.md` |
| **System** | MSVC-style POD element copy (vector elem **0x10**); partition interaction-activation via ConstructN parent |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` + `get_function_xrefs` + `read_memory` + `analyze_control_flow`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Leaf **POD copy** of one **16-byte** element: if dest non-null, copy **4 dwords** from src. Shared by ConstructN and range uninit_copy for the Elem0x10 vector family (paired with dualed `StdVector_ConstructN_Elem0x10_Inferred` @ `0x00409e20`).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ raw CF (2026-08-05) |
| Bytes | full body `85 C0 74 16 8B 11 … 89 48 0C C3` |
| Disassembly | `disassemble_function` 11 insns; RET @ `00409f8a` |
| Call sites | ConstructN `00409e58` (EAX=dest, ECX=value); range `0040a6a8` (EAX/EDI dest, ECX/ESI src; both +0x10) |
| CF metrics | size 27, CC 2, 0 loops, 0 calls |
| Parent dual | MEGA-044 ConstructN `aa_00409e20` |
| Twin duals | PodCopy 0x28 `00409f30`; PodCopy Elem12 `00409f50` |

**Not performed:** Launcher, runtime Confirmed, parent ledgers, dual of other VAs.

---

## 3. Signature (sealed)

```c
// Register ABI; plain RET
void StdVector_PodCopyElement_0x10_Inferred(
    /*EAX*/ void* dest,
    /*ECX*/ const void* src);
```

| Formal | Source | Conf |
|---|---|---|
| dest | EAX | **Confirmed** |
| src | ECX (param storage register:00000004) | **Confirmed** |
| size | 4 dwords / 0x10 | **Confirmed** |
| cleanup | bare `C3` | **Confirmed** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| Null dest → skip copy | `TEST EAX` / `JZ` | **Confirmed** |
| dword0/4/8/0xC stores | four MOV pairs | **Confirmed** |
| RET | epilogue `C3` | **Confirmed** |
| No REP / no loop | linear stores | **Confirmed** |
| Decompile ≡ raw CF | 4 stores + null guard | **Confirmed** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | leaf |
| External callers | `FUN_00409e20`, `FUN_0040a670` (`xref_count=2`) |
| Callees | none |
| Xrefs | 2 UNCONDITIONAL_CALL (`00409e58`, `0040a6a8`) |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| 4-dword / 0x10 byte copy | **Yes** |
| ConstructN / range callers with +0x10 | **Yes** |
| Product/PDB English for T | **No** |

**Decision:** promote **`StdVector_PodCopyElement_0x10_Inferred`**. Scaffold Named_CalleeOf_* **retired**.

---

## 7. Gaps

- Product element type demangle (0x10 POD English).
- Full dual of range worker `FUN_0040a670` (role sealed as +0x10 uninit_copy; residual).
- Runtime / bit-exact / differential.

---

## 8. Verdict

CF/ABI/size sealed; product residual → **accept-with-gaps**.
