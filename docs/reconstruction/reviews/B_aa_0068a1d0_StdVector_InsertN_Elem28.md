# Review B (skeptical / adversarial): `aa_0068a1d0` StdVector_InsertN_Elem28

| Field | Value |
|---|---|
| **Stable ID** | `aa_0068a1d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W34-S) |
| **Counterpart** | `reviews/A_aa_0068a1d0_StdVector_InsertN_Elem28.md` |
| **Scratch** | `tmp/a_0068a1d0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Same as `StdVector_InsertN_BasicString` (`004306b0`) — string elems | **Falsified** — helpers are 7-dword memcpy; no string IAT ctor/dtor; local is `rep movsd` not copy-ctor |
| 2 | Insert-one only (always count=1) | **Falsified as restriction** — ABI takes general count; caller `0068a620` happens to pass 1 |
| 3 | Dword vector insert (`/4`, max `0x3fffffff`) | **Falsified** — stride 0x1c, max `0x9249249` |
| 4 | `RET 4` / two stack args | **Falsified** — `C2 0C 00` three stack args |
| 5 | `operator_delete` is noreturn (decompiler WARNING) | **Falsified by bytes** — `ADD ESP,4` then triad update |
| 6 | Scaffold `Named_CalleeOf_Named_*` plate | **Reject** — structural `StdVector_InsertN_Elem28` |
| 7 | Growth is exact size+count only | **Falsified** — 1.5× then floor via size helper |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Insert-n shape | **High** | Wrong container port |
| ABI RET 0x0C | **High** | Stack corruption |
| POD 0x1c (not string) | **High** | Wrong destroy/copy in port |
| Max / 1.5× | **High** | OOB / throw path |
| Product T English | **Low** | Naming only |
| Nested helper English | **Med** | Port detail |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// FUN_0068a620 insert-one wrapper:
//   size_idx = (where - begin) / 0x1c  (or 0)
//   FUN_0068a1d0(where, /*count*/1, value);  // thiscall vec
//   *out_it = begin + size_idx * 0x1c;
//
// FUN_00688550 fill: for count: memcpy 7 dwords
// FUN_00687d10 copy: for [first,last): memcpy 7 dwords
```

Live decompile 2026-07-29 ≡ scaffold raw CF. Epilogue `C2 0C 00` + magic `/0x1c` seal ABI/elem. POD proof from nested helper decompiles (same session, context only). Closes W33-J residual naming this as caller of `StdVector_Elem28_Size`.

---

## 4. Surviving contract for AutoCore

```
// Port as vector<POD0x1c>::insert(where, count, value):
void InsertN(VectorElem28* v, Elem28* where, uint32_t count, const Elem28& val) {
  if (count == 0) return;
  // capacity/size in elements; throw if size+count > 0x9249249
  // if cap < size+count: grow 1.5x (floor size+count); reallocate;
  //   raw 0x1c memcpy relocate + fill; delete old buffer (no elem dtors)
  // else in-place shift + fill (raw memcpy)
}
// Do NOT unify with StdVector_InsertN_BasicString (string-aware destroy/copy).
// Wrapper FUN_0068a620 is insert-one + iterator rebind.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/POD-stride/max. Rejects basic_string alias and scaffold Named_* plate. Residual product T + nested helpers → **accept-with-gaps**.
