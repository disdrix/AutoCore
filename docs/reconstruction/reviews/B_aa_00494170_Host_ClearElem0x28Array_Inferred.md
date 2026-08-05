# Review B (skeptical / adversarial): `aa_00494170` Host_ClearElem0x28Array_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00494170` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W30-Q) |
| **Counterpart** | `reviews/A_aa_00494170_Host_ClearElem0x28Array_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is Class_009c7a1c complete dtor | **Falsified** — no vtbl install; no buffer/list free chain; body only 64 B free+zero |
| 2 | This is the rebuild path | **Falsified** — no alloc/ctor/scale; only free + zero dims |
| 3 | Stride is not 0x28 | **Falsified** — immediate `push 0x28` into vector-dtor iter; dtor DATA is `FUN_005b8000` |
| 4 | Stack this / cdecl | **Falsified** — `mov esi, ecx`; bare RET; no stack formals |
| 5 | Zeros more than +0x28/+4/+8 | **Falsified** — three `mov dword [esi+off], 0` only |
| 6 | Must have static callers to be real | **Careful** — zero xrefs is a **usage** gap, not body invalidation; adjacent rebuild uses same free fragment inline |
| 7 | Merges with Class_009c7a1c_CompleteDtor | **Falsified** — complete dtor continues into six buffer frees + list destroy; this VA returns after vector free |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Free-only role | **High** | Wrong port unit |
| Stride 0x28 + dtor | **High** | Heap corruption |
| Zero triple | **High** | Stale dims |
| Product host name | **Low** | Naming only |
| Static usage | **Open** | Dead-code assumption |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + body + peers

```
// This VA:
if arr@+0x28: vector_dtor(0x28, FUN_005b8000); delete[]; zero +0x28/+4/+8

// Class_009c7a1c_CompleteDtor (W28-M) starts with the same free fragment, then more.
// FUN_004941b0 free arm matches free but does not zero +4/+8 (rewrites them).
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Body end abuts rebuild entry.

---

## 4. Surviving contract for AutoCore

```
// Port as free-only helper (stride 0x28):
void Host_ClearElem0x28Array(void* host) {
  // destroy cookie-vector @ +0x28 via Elem0x28_CompleteDtor
  // zero +0x28, +4, +8
}
// Do NOT treat as full class complete dtor.
// Do NOT invent product plate without evidence.
// No proven static callers — call only if host ownership path needs explicit free.
```

---

## 5. Verdict

Adversarial pass confirms A on role/ABI/stride/zeros. Residual product type + static-use → **accept-with-gaps**.
