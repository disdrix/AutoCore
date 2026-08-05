# Review B (skeptical / adversarial): `aa_004382c0` Struct_TwoBasicString_DefaultCtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004382c0` |
| **VA** | `0x004382c0` |
| **Canonical name** | `Struct_TwoBasicString_DefaultCtor_Inferred` (**Inferred**) |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_004382c0_Struct_TwoBasicString_DefaultCtor_Inferred.md` |
| **System** | MSVC basic_string composite |
| **Live tools** | Independent decompile + `read_memory` + IAT + caller assembly context |
| **Verdict** | **accept-with-gaps** — accept dual-string ctor; reject thiscall / single-string / gfxBody product claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | ECX-thiscall | **Falsified** — `mov esi, [esp+0x14]` loads stack arg; no `mov reg, ecx` this capture |
| 2 | Only one string | **Falsified** — two IAT ctor calls; second `lea ecx, [esi+0x1c]` |
| 3 | `ret 0` / cdecl without cleanup | **Falsified** — `c2 04 00` (**ret 4**) |
| 4 | Non-string members initialized here | **Falsified** — only two string default ctors; no other stores |
| 5 | Scaffold `Named_CalleeOf_…gfxBody…` is product | **Rejected** — 4 distinct callers; default-ctor leaf |
| 6 | Decompiler `basic_string*` return type as sole identity | **Incomplete** — object is **pair** of strings (0x38), not a single string |
| 7 | Always only used with gfxBody | **Falsified** — also `FUN_009895c0`, `FUN_0095e3e0`, `FUN_00437ad0` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Two strings at 0 / 0x1c | **High** | Wrong layout / fill size |
| Stack this + ret 4 | **High** | Stack imbalance |
| IAT = basic_string default ctor | **High** | Wrong construction semantics |
| Object span ≥ 0x38 | **High** | Buffer underrun if undersized |
| Product field English | **None** | Registry pollution |
| Exact product class name | **None** | Over-claim |

---

## 3. Decompiler pitfalls (must survive port)

1. **Not thiscall** — recover stack arg as object pointer.
2. **Two members** — decompiler types param as `basic_string*` but body constructs **pair**.
3. Scaffold gfxBody naming — **ignore**.
4. Pair with `FUN_00437e40` (0x38-elem vector resize) is **caller pattern**, not owned by this VA.

---

## 4. What is safe to claim

| Safe | Unsafe |
|---|---|
| Dual basic_string default ctor CF | Product struct/field names |
| Stack ABI + ret 4 + return this | Assuming only one consumer domain |
| Structural `_Inferred` name | PDB / RTTI plate without evidence |

---

## 5. CF challenge of Review A

- Body CF + 70 B + dual +0x1c: **agree Confirmed**
- Stack ABI / ret 4: **agree**
- Reject thiscall / single-string / gfxBody product: **agree**
- Product English gap: **agree open**

**Verdict:** **accept-with-gaps**
