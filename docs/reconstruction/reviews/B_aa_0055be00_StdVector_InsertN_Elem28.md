# Review B (skeptical / adversarial): `aa_0055be00` StdVector_InsertN_Elem28

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055be00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W34-R) |
| **Counterpart** | `reviews/A_aa_0055be00_StdVector_InsertN_Elem28.md` |
| **Scratch** | `tmp/a_0055be00.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Same function as wstring insert `004a7ad0` | **Falsified** — no string IAT; POD copy; delete without destroy-range |
| 2 | Char-string insert `004306b0` identity | **Falsified** — separate body/SEH/helpers; POD vs string |
| 3 | Dword insert (`InsertN_Dword`) | **Falsified** — stride **0x1c**, max `0x9249249` not `0x3fffffff` |
| 4 | Insert-one only | **Falsified as restriction** — general `count`; `FUN_0055c250` resize can pass `param_2 - size` |
| 5 | Non-trivial element dtor | **Falsified** — reallocation calls `operator_delete` only |
| 6 | Scaffold VOG_DEBUG / Named_CalleeOf plate | **Reject** — structural `StdVector_InsertN_Elem28` preferred |
| 7 | Growth exact size+count only | **Falsified** — 1.5× then floor |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Insert-n shape | **High** | Wrong container port |
| ABI RET 0x0C | **High** | Stack corruption |
| Stride 0x1c POD | **High** | Wrong destroy/copy |
| Max / 1.5× | **High** | OOB / throw path |
| Product Elem28 type | **Low** | Domain labeling only |
| Nested helper English | **Med** | Port detail |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// FUN_0055c310: insert-one rebind
//   FUN_0055be00(where, 1, value); *out = begin + idx*0x1c;
// FUN_0055c250: resize grow
//   FUN_0055be00(end, need, &stack_value);
```

Live decompile 2026-07-29 ≡ scaffold raw CF. movss ladder + delete-without-destroy seals POD. Shares `FUN_00469c50` with wstring twin and other 0x1c hosts (W33-J).

---

## 4. Surviving contract for AutoCore

```
// Port as vector<Elem28>::insert(where, count, value) with trivial T:
void InsertN(VectorElem28* v, Elem28* where, uint32_t count, const Elem28& val) {
  if (count == 0) return;
  // capacity/size in elements; throw if size+count > 0x9249249
  // if cap < size+count: grow 1.5x; reallocate; relocate (memcpy-like); fill; delete old (no dtor)
  // else in-place shift + fill
}
// Used by insert-one rebind and resize-growth wrappers.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/stride/max/POD. Residual product Elem28 type + nested helpers → **accept-with-gaps**.
