# Review B (skeptical / adversarial): `aa_004367f0` StdVector_DwordResize

| Field | Value |
|---|---|
| **Stable ID** | `aa_004367f0` |
| **VA** | `0x004367f0` |
| **Canonical name** | `FUN_004367f0` retained; role **Inferred** |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_004367f0_StdVector_DwordResize.md` |
| **System** | STL / container utility |
| **Live tools** | Independent decompile + `read_memory` + grow/shrink callees + caller dual |
| **Verdict** | **accept-with-gaps** — accept CF; reject single-domain / non-POD / wrong-ABI claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | `ret 4` / one stack arg | **Falsified** — two `c2 08 00` exits (**ret 8**) |
| 2 | Decompiler `FUN_004367f0(0,0)` with no this | **Falsified as complete ABI** — callers adjust ECX (`add ecx,0xA8` in gfx host path); thiscall required |
| 3 | Gfx-host-only API | **Falsified** — 23 xrefs across many FUN_* domains |
| 4 | Runs element destructors on shrink | **Falsified** — `FUN_00410490` is memmove end-update only |
| 5 | Capacity field used in this body | **Falsified** — only begin/end; capacity in grow callee |
| 6 | Alias `Named_CalleeOf_Named_gfxFontImpl_*` is product name | **Rejected** — scaffold noise |
| 7 | Grow without fill arg | **Falsified** — passes address of stack fill dword into `FUN_004507a0` |
| 8 | Shrinking to same size still calls erase | **Falsified** — needs `newCount < size` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| size via `>>2` | **High** | Wrong element stride |
| grow vs shrink branch | **High** | Buffer overrun / leak |
| `ret 8` / two stack args | **High** | Stack imbalance |
| POD-only shrink | **High** | UAF if used on non-trivial T |
| Multi-domain utility | **High** | Over-narrow rename |
| Product STL symbol | **None** | Registry pollution |

---

## 3. Decompiler pitfalls (must survive port)

1. **Missing this** in some call-site decompiles — always recover ECX from machine (see `A_aa_004962b0`).
2. **Fill as `&stack0x00000008`** — third logical arg after `this`, `newCount`.
3. Scaffold gfxFont naming — **ignore**.

---

## 4. What is safe to claim

| Safe | Unsafe |
|---|---|
| Dword-vector resize CF | Exact `std::vector::resize` mangling |
| Grow `FUN_004507a0` / shrink `FUN_00410490` | Non-POD element destroy |
| Multi-caller utility | Single-owner “font only” API |
| leave `FUN_*` in Ghidra | Promote registry name without PDB |

---

## 5. CF challenge of Review A

- Body CF + `ret 8`: **agree High**
- Role inferred, leave-FUN spelling: **agree**
- Reject non-POD destroy claim: **agree**
- Reject gfx-only: **agree**

**Verdict:** **accept-with-gaps**
