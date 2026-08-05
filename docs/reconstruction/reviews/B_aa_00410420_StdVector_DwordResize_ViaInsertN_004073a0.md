# Review B (skeptical / adversarial): `aa_00410420` StdVector_DwordResize_ViaInsertN_004073a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_00410420` |
| **VA** | `0x00410420` |
| **Canonical name** | `StdVector_DwordResize_ViaInsertN_004073a0` (**Inferred**) |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00410420_StdVector_DwordResize_ViaInsertN_004073a0.md` |
| **System** | STL / container utility |
| **Live tools** | Independent decompile + `read_memory` + twin `004367f0` + caller context |
| **Verdict** | **accept** — accept CF; reject wrong-ABI / single-domain / non-POD / same-as-004367f0-engine claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | `ret 4` / one stack arg only | **Falsified** — both exits `c2 08 00` (**ret 8**); fill is second stack dword |
| 2 | Decompiler `FUN_00410420(0,0)` with no this | **Falsified as complete ABI** — callers `lea ecx,[obj+off]` then call |
| 3 | Identical to `004367f0` including grow callee | **Falsified** — grow is `004073a0` here, `004507a0` there; do not merge binaries |
| 4 | Runs element destructors on shrink | **Falsified** — shrink is `FUN_00410490` memmove/end only |
| 5 | Capacity field read in this body | **Falsified** — only begin/end; capacity inside grow callee |
| 6 | Scaffold `Named_CalleeOf_…gfxGeometryPiece…` is product | **Rejected** — parent-seed noise |
| 7 | Gfx-only API | **Falsified** — 30 xrefs across UI, mission, inventory, geometry, etc. |
| 8 | Shrink on equal size | **Falsified** — needs strict `newCount < size` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| size via `>>2` | **High** | Wrong element stride |
| grow vs shrink branch | **High** | Overrun / wrong length |
| `ret 8` / two stack args | **High** | Stack imbalance |
| Grow callee identity `004073a0` | **High** | Wrong insert policy |
| POD-only shrink | **High** | UAF if misused on non-trivial T |
| Multi-domain utility | **High** | Over-narrow rename |
| Product STL symbol | **None** | Registry pollution |

---

## 3. Decompiler pitfalls (must survive port)

1. **Missing this** at call sites — recover ECX (`lea` into embedded vector).  
2. **Fill as `&stack0x00000008`** — third logical arg after `this`, `newCount`.  
3. Scaffold geometry naming — **ignore**.  
4. Do **not** substitute `004367f0` body without verifying grow engine.

---

## 4. What is safe to claim

| Safe | Unsafe |
|---|---|
| Dword-vector resize CF | Exact `std::vector::resize` mangling |
| Grow `004073a0` / shrink `00410490` | Non-POD element destroy |
| Multi-caller utility | Single-owner “geometry only” API |
| Structural inferred name | Product registry name without PDB |

---

## 5. CF challenge of Review A

- Body CF + `ret 8` + 105 B: **agree Confirmed**  
- Twin distinction vs `004367f0`: **agree**  
- Reject non-POD destroy / gfx-only: **agree**  

**Verdict:** **accept**
