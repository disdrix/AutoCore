# Review B (skeptical / adversarial): `aa_00438040` StdVector_Resize_Elem8_ViaInsertN_00438d80

| Field | Value |
|---|---|
| **Stable ID** | `aa_00438040` |
| **VA** | `0x00438040` |
| **Canonical name** | `StdVector_Resize_Elem8_ViaInsertN_00438d80` (**Inferred**) |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00438040_StdVector_Resize_Elem8_ViaInsertN_00438d80.md` |
| **System** | STL / container utility |
| **Live tools** | Independent decompile + `read_memory` + caller assembly context + grow/shrink callees |
| **Verdict** | **accept-with-gaps** — accept CF/ABI/stride; reject thiscall / dword-stride / POD-only / gfxBody product claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | `__thiscall` with ECX = vector (like `00410420`) | **Falsified** — `mov esi,ecx` uses ECX as **newCount**; `mov eax,[edx+4]` uses **EDX** as vector |
| 2 | Element stride 4 (`>>2`) | **Falsified** — `c1 f9 03` (`>>3`); shrink `lea … *8` |
| 3 | `ret 4` / single stack arg | **Falsified** — exit `c2 08 00` (**ret 8**); 8-byte fill |
| 4 | POD shrink (no element dtors) | **Falsified** — shrink callee `FUN_00438d00` walks elems and calls `(**elem)(0)` |
| 5 | Decompiler `undefined4` fill is full story | **Incomplete** — machine passes `&stack fill` as 8-byte region; second dword optional rep |
| 6 | Scaffold `Named_CalleeOf_…gfxBody…` is product | **Rejected** — parent-seed noise; multi-caller utility |
| 7 | Capacity field read in this body | **Falsified** — only begin/end here; capacity inside `FUN_00438d80` |
| 8 | Shrink on equal size | **Falsified** — needs strict `newCount < size` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| size via `>>3` | **High** | Wrong element stride / OOB |
| grow vs shrink branch | **High** | Overrun / wrong length |
| `ret 8` / 8-byte stack fill | **High** | Stack imbalance |
| `__fastcall` ECX/EDX | **High** | Wrong call-site port |
| Grow callee `00438d80` | **High** | Wrong insert policy |
| Non-POD shrink | **High** | UAF if treated as POD |
| Product element English | **None** | Registry pollution |
| Exact shared_ptr identity | **Low** | Over-claim on STL type |

---

## 3. Decompiler pitfalls (must survive port)

1. **Not thiscall** — ECX is count; EDX is vector (callers `lea edx,[obj+off]`).
2. **Fill is 8 bytes** — do not treat as single dword only.
3. **Shrink runs element dtors** — unlike dword POD resize twins.
4. **Fill-rep release** at end is **parameter** cleanup, not vector element teardown.
5. Scaffold gfxBody naming — **ignore**.

---

## 4. What is safe to claim

| Safe | Unsafe |
|---|---|
| 8-byte element vector resize CF | Exact `std::vector<shared_ptr<T>>::resize` mangling |
| Grow `00438d80` / shrink `00438d00` | Product T English |
| Fastcall + ret 8 | Claiming POD-only storage |
| Structural inferred name | Product registry name without PDB |

---

## 5. CF challenge of Review A

- Body CF + `ret 8` + 171 B: **agree Confirmed**
- Fastcall ECX/EDX + stride 8: **agree**
- Reject thiscall / dword twin merge / gfxBody product: **agree**
- Element product type gap: **agree open**

**Verdict:** **accept-with-gaps**
