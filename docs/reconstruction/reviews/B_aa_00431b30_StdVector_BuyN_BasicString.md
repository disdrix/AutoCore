# Review B (skeptical / adversarial): `aa_00431b30` StdVector_BuyN_BasicString

| Field | Value |
|---|---|
| **Stable ID** | `aa_00431b30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W37-E) |
| **Counterpart** | `reviews/A_aa_00431b30_StdVector_BuyN_BasicString.md` |
| **Scratch** | `tmp/a_00431b30.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Full owning reallocate (free old buffer first) | **Falsified** — triad zero only; no `operator_delete` |
| 2 | Constructs n live strings (size=n) | **Falsified** — begin==end after buy (size 0); capacity only |
| 3 | POD elem size other than 0x1c | **Falsified** — `n*0x1c` lea/sub/add chain; max `0x9249249` |
| 4 | Bare `C3` / zero stack args | **Falsified** — dual `C2 04 00` |
| 5 | Returns void / returns pointer | **Falsified** — AL 0/1 (`32 C0` / `B0 01`) |
| 6 | `FUN_004540b0` returns a clamped n | **Falsified** — nested decompile is noreturn throw `"vector<T> too long"`; decomp assign into n is false |
| 7 | Unrelated to string vector | **Falsified** — sole caller is string-vector assign; throw plate is `vector<T>` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| No-free blank buy | **High** | Port leak if callers hold prior buffer |
| RET 4 + 0/1 return | **High** | Stack / branch bugs |
| Stride 0x1c + max | **High** | Wrong capacity math |
| basic_string product T | **High** | Wrong element ctor assumptions on follow-up fill |
| Product demangle | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// Sole caller StdVector_AssignFrom_BasicString (W34-S):
//   n = src size / 0x1c
//   FUN_00431b30(dest, n)   // blank-buy
//   if ready: uninit_copy strings; dest.end = …
//
// This unit:
//   dest.begin=end=capEnd=0;   // NO free
//   if (n==0) return 0;
//   if (n > 0x9249249) throw;
//   p = new (n*0x1c); begin=end=p; capEnd=p+n*0x1c; return 1;
```

Live decompile ≡ scaffold CF. Bytes seal no-free, dual RET 4, and 0/1 returns. Closes W34-S residual “nested buy `FUN_00431b30` plate unowned”.

---

## 4. Surviving contract for AutoCore

```
// Port carefully — NOT grow-from-owned:
bool BuyN(VectorString* dest, uint32_t n) {
  dest->begin = dest->end = dest->capEnd = nullptr; // leak if prior owned!
  if (n == 0) return false;
  if (n > 0x9249249) throw length_error("vector<T> too long");
  auto* p = (Elem*)operator_new(n * 0x1c);
  dest->begin = dest->end = p;
  dest->capEnd = p + n;
  return true;
}
// ABI: ECX=dest, stack n, RET 4, AL=0/1.
// Call sites must pass empty/default dest.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/no-free/stride and sharpens the **leak-if-owned** hazard. Residual product demangle + runtime → **accept-with-gaps**.
