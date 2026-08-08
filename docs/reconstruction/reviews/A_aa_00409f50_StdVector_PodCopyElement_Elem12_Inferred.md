# Review A (reconstruction fidelity): `aa_00409f50` StdVector_PodCopyElement_Elem12_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409f50` |
| **VA** | `0x00409f50`–`0x00409f64` inclusive (**21 B** / `0x15`) |
| **Canonical name** | `StdVector_PodCopyElement_Elem12_Inferred` |
| **Ghidra name** | `FUN_00409f50` |
| **Review date** | `2026-08-05` (WQ9J-A OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00409f50_StdVector_PodCopyElement_Elem12_Inferred.md` |
| **System** | MSVC-style POD element copy (vector elem 0x0C / Elem12) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` + callers/xrefs + call-site memory. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Leaf **POD copy** of one **12-byte** element: if dest non-null, copy **3 dwords** from src. Shared by ConstructN and range-copy for the Elem12 vector family (paired with dualed `StdVector_ConstructN_Elem12_Inferred` @ `0x00409db0`).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ raw CF (2026-08-05) |
| Bytes | full body `85 C0 74 10 8B 11 … 89 48 08 C3` |
| Call sites | ConstructN `00409de8` (EAX=dest, ECX=value); range `0040a5c8` (EAX/EDI dest, ECX/ESI src; both +0x0C) |
| Parent dual | WQ9I-A ConstructN `aa_00409db0` |
| ADV prior | `ADV_wq9i_spotcheck_vector_list.md` already flagged undualed leaf + EAX/ECX ABI |

---

## 3. Signature (sealed)

```c
// Register ABI; plain RET
void StdVector_PodCopyElement_Elem12_Inferred(
    /*EAX*/ void* dest,
    /*ECX*/ const void* src);
```

| Formal | Source | Conf |
|---|---|---|
| dest | EAX | **Confirmed** |
| src | ECX (param storage register:00000004) | **Confirmed** |
| size | 3 dwords / 0x0C | **Confirmed** |
| cleanup | bare `C3` | **Confirmed** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| Null dest → skip copy | `TEST EAX` / `JZ` | **Confirmed** |
| dword0/4/8 stores | three MOV pairs | **Confirmed** |
| RET | epilogue `C3` | **Confirmed** |
| No REP / no loop | linear stores | **Confirmed** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | leaf |
| External callers | `FUN_00409db0`, `FUN_0040a590` (`xref_count=2`) |
| Callees | none |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| 3-dword / 0x0C byte copy | **Yes** |
| ConstructN / range callers with +0x0C | **Yes** |
| Product/PDB English for T | **No** |

**Decision:** promote **`StdVector_PodCopyElement_Elem12_Inferred`**.

---

## 7. Gaps

- Product element type demangle.
- Full dual of range worker `FUN_0040a590` (role sealed as +0x0C copy).
- Runtime / bit-exact / differential.

---

## 8. Verdict

CF/ABI/size sealed; product residual → **accept-with-gaps**.
