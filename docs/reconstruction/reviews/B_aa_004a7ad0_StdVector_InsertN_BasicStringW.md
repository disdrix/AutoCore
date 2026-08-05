# Review B (skeptical / adversarial): `aa_004a7ad0` StdVector_InsertN_BasicStringW

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a7ad0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W34-R) |
| **Counterpart** | `reviews/A_aa_004a7ad0_StdVector_InsertN_BasicStringW.md` |
| **Scratch** | `tmp/a_004a7ad0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Insert-one only (always count=1) | **Falsified as restriction** — ABI takes general `count`; caller `FUN_004a7ff0` happens to pass 1 |
| 2 | Char-string twin `004306b0` identity | **Falsified as unify** — separate body/SEH/helpers; same *shape*, different element domain (wchar) |
| 3 | POD / Elem28 insert (no dtor) | **Falsified** — wstring IAT ctor/dtor + destroy-range `FUN_004a7aa0` before delete |
| 4 | `RET 4` / two stack args | **Falsified** — `C2 0C 00` three stack args |
| 5 | Max 0x3fffffff (dword vectors) | **Falsified** — `0x9249249` for 0x1c elems |
| 6 | Scaffold `Named_CalleeOf_Named_*` plate | **Reject** — structural insert-n name preferred |
| 7 | Growth is exact size+count only | **Falsified** — 1.5× then floor |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Insert-n shape | **High** | Wrong container port |
| ABI RET 0x0C | **High** | Stack corruption |
| Stride 0x1c wstring | **High** | Wrong destroy/copy |
| Max / 1.5× | **High** | OOB / throw path |
| Product demangle | **Low** | Naming only |
| Nested helper English | **Med** | Port detail |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// FUN_004a7ff0:
//   FUN_004a7ad0(where, /*count*/1, value);  // thiscall vec
//   *out_it = begin + index * 0x1c;
```

Live decompile 2026-07-29 ≡ scaffold raw CF. Epilogue `C2 0C 00` + magic `/0x1c` seal ABI/elem. Distinct from POD twin `0055be00` (same wave) and char twin `004306b0` (W32-B).

---

## 4. Surviving contract for AutoCore

```
// Port as vector<wstring>::insert(where, count, value):
void InsertN(VectorWString* v, wstring* where, uint32_t count, const wstring& val) {
  if (count == 0) return;
  // capacity/size in elements; throw if size+count > 0x9249249
  // if cap < size+count: grow 1.5x (floor size+count); reallocate; relocate; fill
  // else in-place shift + fill
}
// Callers may wrap as insert-one + iterator rebind (FUN_004a7ff0).
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/stride/max/wstring. Residual product demangle + nested helpers → **accept-with-gaps**.
