# Review B (skeptical / adversarial): `aa_004306b0` StdVector_InsertN_BasicString

| Field | Value |
|---|---|
| **Stable ID** | `aa_004306b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W32-B) |
| **Counterpart** | `reviews/A_aa_004306b0_StdVector_InsertN_BasicString.md` |
| **Scratch** | `tmp/a_004306b0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Insert-one only (always count=1) | **Falsified as restriction** — ABI takes general `count`; caller `FUN_00430310` happens to pass 1 |
| 2 | Dword / POD vector insert twin | **Falsified** — stride 0x1c, string ctor/dtor, destroy-range `FUN_00431aa0` |
| 3 | `RET 4` / two stack args | **Falsified** — `C2 0C 00` three stack args |
| 4 | Max 0x3fffffff (dword vectors) | **Falsified** — `0x9249249` for 0x1c elems |
| 5 | Domain-specific AssManager-only | **Weakened** — only one direct caller, but algorithm is generic vector insert-n |
| 6 | Scaffold `Named_CalleeOf_Named_*` plate | **Reject** — structural insert-n name preferred |
| 7 | Growth is exact size+count only | **Falsified** — 1.5× then floor |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Insert-n shape | **High** | Wrong container port |
| ABI RET 0x0C | **High** | Stack corruption |
| Stride 0x1c string | **High** | Wrong destroy/copy |
| Max / 1.5× | **High** | OOB / throw path |
| Product demangle | **Low** | Naming only |
| Nested helper English | **Med** | Port detail |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// FUN_00430310:
//   FUN_004306b0(where, /*count*/1, value);  // thiscall vec
//   *out_it = begin + index * 0x1c;
// StringVec_PushFront (W31-E) → FUN_00430310(ESI, &out, begin, local)
```

Live decompile 2026-07-29 ≡ scaffold raw CF. Epilogue `C2 0C 00` + magic `/0x1c` seal ABI/elem. Closes W31-E residual nested `FUN_004306b0` product plate (structural).

---

## 4. Surviving contract for AutoCore

```
// Port as vector<string>::insert(where, count, value):
void InsertN(VectorString* v, string* where, uint32_t count, const string& val) {
  if (count == 0) return;
  // capacity/size in elements; throw if size+count > 0x9249249
  // if cap < size+count: grow 1.5x (floor size+count); reallocate; relocate; fill
  // else in-place shift + fill
}
// Callers may wrap as insert-one + iterator rebind (FUN_00430310).
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/stride/max. Residual product demangle + nested helpers → **accept-with-gaps**.
