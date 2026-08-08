# Review A (reconstruction fidelity): `aa_00409f30` StdVector_PodCopyElement_0x28_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409f30` |
| **VA** | `0x00409f30`–`0x00409f43` inclusive (**20 B** / `0x14`) |
| **Canonical name** | `StdVector_PodCopyElement_0x28_Inferred` |
| **Ghidra name** | `FUN_00409f30` |
| **Review date** | `2026-08-05` (WQ9I-B OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00409f30_StdVector_PodCopyElement_0x28_Inferred.md` |
| **System** | MSVC-style POD element copy (vector elem 0x28) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` + `get_assembly_context` + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Leaf **POD copy** of one **0x28**-byte element: if dest non-null, copy **10 dwords** from src. Shared by ConstructN and range-copy for the elem-0x28 vector family (paired with dualed `StdVector_ConstructN_Elem0x28_Inferred` @ `0x00409d40`).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ raw CF (2026-08-05) |
| Bytes | full body `57 8B F8 … F3 A5 … C3` |
| Call sites | ConstructN `00409d78` (EAX=dest, EDX=value); range `0040a558` (EAX/EDI dest, EDX/ESI src; both +0x28) |
| Parent dual | WQ9H-B ConstructN `aa_00409d40` |

---

## 3. Signature (sealed)

```c
// Register ABI; plain RET
void StdVector_PodCopyElement_0x28_Inferred(
    /*EAX*/ void* dest,
    /*EDX*/ const void* src);
```

| Formal | Source | Conf |
|---|---|---|
| dest | EAX → EDI | **Confirmed** |
| src | EDX → ESI | **Confirmed** |
| count | ECX imm **10** | **Confirmed** |
| cleanup | bare `C3` | **Confirmed** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| Null dest → skip copy | `TEST EDI` / `JZ` | **Confirmed** |
| REP MOVSD 10 dwords | `B9 0A…` + `F3 A5` | **Confirmed** |
| Restore ESI/EDI + RET | epilogue bytes | **Confirmed** |
| Decomp loop vs REP | bytes override (equiv) | **High** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | leaf |
| External callers | `FUN_00409d40`, `FUN_0040a520` (`xref_count=2`) |
| Callees | none |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| 10-dword / 0x28 byte copy | **Yes** |
| ConstructN / range callers with +0x28 | **Yes** |
| Product/PDB English for T | **No** |

**Decision:** promote **`StdVector_PodCopyElement_0x28_Inferred`**.

---

## 7. Gaps

- Product element type demangle.
- Full dual of range worker `FUN_0040a520` (role sealed as +0x28 copy).
- Runtime / bit-exact / differential.

---

## 8. Verdict

CF/ABI/size sealed; product residual → **accept-with-gaps**.
