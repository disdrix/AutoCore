# Review B (skeptical / adversarial): `aa_00469d10` StdVector_AssignFrom_BasicString

| Field | Value |
|---|---|
| **Stable ID** | `aa_00469d10` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W34-S) |
| **Counterpart** | `reviews/A_aa_00469d10_StdVector_AssignFrom_BasicString.md` |
| **Scratch** | `tmp/a_00469d10.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Classic `dest.operator=(src)` with ECX=dest | **Falsified** — ECX=src (`8B F1`); dest on stack; buy reloads ECX=dest |
| 2 | POD range memcpy assign (like 0068a1d0 family) | **Falsified** — callee is `StdUninitCopy_BasicString` (string copy-ctors) |
| 3 | Full operator= that destroys old dest elems | **Weakened** — buy zeros triad **without** free; not a complete owning assign |
| 4 | Bare `C3` / zero stack args | **Falsified** — `C2 04 00` |
| 5 | Returns void / returns src | **Falsified** — `8B C7` returns dest |
| 6 | Unrelated to W33-G uninit_copy | **Falsified** — sole non-trivial callee after buy is `0046a2c0` @ `0x00469d76` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Src-this assign shape | **High** | Wrong call-site ABI |
| RET 4 + return dest | **High** | Stack / chain bugs |
| String uninit_copy | **High** | Wrong element lifetime |
| Buy no-free | **High** | Port leak if misused |
| Product demangle | **Low** | Naming only |
| Caller dest-empty invariant | **Med** | Leak if violated |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// Fs_ExpandPathSpecToStringVec (W33-E residual named this):
//   FUN_00469d10(collector → out_string_vec)
//
// FUN_00431b30(dest, n):
//   dest.begin=end=capEnd=0;
//   if (n==0) return 0;
//   if (n > 0x9249249) FUN_004540b0();
//   p = new (n*0x1c); begin=end=p; capEnd=p+n*0x1c; return 1;
//
// Then FUN_0046a2c0(src.begin, src.end, dest.begin) → dest.end
```

Live decompile ≡ scaffold. Bytes seal dest-as-buy-this and RET 4. Closes W33-G residual naming `FUN_00469d10` as range-assign consumer of uninit_copy; closes W33-E Fs expand assign step plate.

---

## 4. Surviving contract for AutoCore

```
// Port carefully — NOT full owning operator=:
VectorString* AssignFrom(VectorString* src, VectorString* dest) {
  n = src empty ? 0 : (end-begin)/0x1c;
  // Blank dest triad WITHOUT free; if n>0 allocate capacity n
  if (!BuyEmpty(dest, n)) return dest;  // n==0 leaves empty
  dest->end = UninitCopyStrings(src->begin, src->end, dest->begin);
  return dest;
}
// Call sites must pass empty/default dest (or accept leak of prior buffer).
// ABI: ECX=src, stack dest*, RET 4, EAX=dest.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/string path and sharpens the **no-free buy** hazard. Residual product demangle + caller dest invariant → **accept-with-gaps**.
