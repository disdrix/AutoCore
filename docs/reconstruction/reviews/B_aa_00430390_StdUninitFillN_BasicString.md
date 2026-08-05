# Review B (skeptical / adversarial): `aa_00430390` StdUninitFillN_BasicString

| Field | Value |
|---|---|
| **Stable ID** | `aa_00430390` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W33-G) |
| **Counterpart** | `reviews/A_aa_00430390_StdUninitFillN_BasicString.md` |
| **Scratch** | `tmp/a_00430390.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | In-place memcpy of value bytes | **Falsified** — delegates string copy-ctor fill loop `FUN_00431700` |
| 2 | cdecl / bare RET | **Falsified** — `C2 0C 00` three stack args + ECX |
| 3 | Returns void / dest only | **Falsified** — returns `dest + count*0x1c` |
| 4 | Shared with non-string vectors | **Falsified as this body** — hard `*0x1c` + string fill callee |
| 5 | Scaffold `Named_CalleeOf_Named_*` | **Reject** — structural fill-n name preferred |
| 6 | Multiple independent callers | **Falsified** — sole static caller insert-n (`FUN_004306b0`) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Fill-n wrapper shape | **High** | Wrong insert port |
| ABI RET 0x0C + ECX | **High** | Stack corruption |
| `*0x1c` end pointer | **High** | Bad end iterator |
| Nested loop plate | **Med** | Port detail in `FUN_00431700` |
| Product demangle | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// FUN_004306b0:
//   ... grow path: relocate via FUN_0046a2c0; fill inserted via FUN_00430390(dest, count, value)
//   ... in-place path: also calls FUN_00430390 at second site
// FUN_00431700: for count: copy-ctor(dest, value); dest += 0x1c
```

Live decompile 2026-07-29 ≡ thin wrapper. Relative call seals `FUN_00431700`. Closes W32-B residual nested fill helper plate (structural).

---

## 4. Surviving contract for AutoCore

```
// Port as uninit_fill_n for vector<string> (elem 0x1c):
string* UninitFillN(void* /*alloc*/, string* dest, int count, const string& val) {
  for (int i = 0; i < count; ++i)
    new (dest + i) string(val);
  return dest + count;
}
// thiscall-ish host/alloc may be unused; preserve RET 0x0C if matching ABI.
// Prefer implementing fill in one place; retail splits wrapper vs loop (00430390 / 00431700).
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/return math/sole caller. Residual nested product + demangle → **accept-with-gaps**.
