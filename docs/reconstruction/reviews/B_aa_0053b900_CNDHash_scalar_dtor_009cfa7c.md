# Review B (skeptical / adversarial): `aa_0053b900` CNDHash_scalar_dtor_009cfa7c

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053b900` |
| **VA** | `0x0053b900` |
| **Canonical name** | `CNDHash_scalar_dtor_009cfa7c` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Skeptical / adversarial (Path B — OWN-ONLY W25-H) |
| **Counterpart** | `reviews/A_aa_0053b900_CNDHash_scalar_dtor_009cfa7c.md` |
| **System** | container / CNDHash |
| **Live tools** | Independent `decompile_function` + `read_memory` entry/vtbl; callees; contrast body `0053b920` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This **is** the full hash dtor (merge with `0053b920`) | **Falsified** — 30 B wrapper; body is separate dual with FreeBuckets/SEH |
| 2 | `operator_delete` is noreturn / body unreachable after | **Falsified** — CRT delete returns; machine has `mov eax,esi; ret 4` after call |
| 3 | Frees freelist / buckets itself | **Falsified** — only body + optional this free; no freelist bytes |
| 4 | Multiple direct callers | **Falsified** — DATA xref from vtbl only (virtual) |
| 5 | `flags` uses bit1+ for array delete | **Overclaim** — body tests **only bit0**; other bits ignored here |
| 6 | Product name known | **Open** — role inferred from MSVC pattern + sibling seal |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Scalar wrapper CF | **High** | Double dtor or leak if port merges body |
| vtbl slot 0 identity | **High** | Wrong delete dispatch |
| Separation from body `0053b920` | **High** | Coverage double-count / wrong FreeBuckets ownership |
| Product mangled name | **None** | Cosmetics only |

---

## 3. CF challenge of Review A

- Body always then optional delete: **agree High**
- ret 4 / return this: **agree High**
- vtbl[0] dword seal: **agree High** (independent `read_memory` on `009cfa7c`)
- accept-with-gaps (product name): **agree**

### Residual flagged (not blocking)

Ghidra decompile prints `operator_delete` as noreturn — **presentation only**; machine epilogue proves fall-through. Clean plate must not treat delete as `__declspec(noreturn)`.

---

## 4. Safe vs unsafe

| Safe | Unsafe |
|---|---|
| Scalar deleting dtor; vtbl `009cfa7c`[0] | Invent product `CNDHash::~CNDHash` mangling |
| Always call body before free | Claim array-deleting (bit1) support |
| flags&1 → free this only | Claim this frees individual hash values |

**Verdict:** **accept-with-gaps** — reject merge with body dtor; accept scalar CF seal.
