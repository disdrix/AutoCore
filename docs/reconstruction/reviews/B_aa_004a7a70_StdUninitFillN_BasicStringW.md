# Review B (skeptical / adversarial): `aa_004a7a70` StdUninitFillN_BasicStringW

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a7a70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W36-S) |
| **Counterpart** | `reviews/A_aa_004a7a70_StdUninitFillN_BasicStringW.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | In-place memcpy of value bytes | **Falsified** — delegates wstring copy-ctor fill loop `FUN_004a74f0` |
| 2 | cdecl / bare RET | **Falsified** — `C2 0C 00` three stack args + ECX |
| 3 | Returns void / dest only | **Falsified** — returns `dest + count*0x1c` |
| 4 | Shared with non-string vectors | **Falsified as this body** — hard `*0x1c` + wstring fill callee |
| 5 | Same as destroy-range sibling | **Falsified** — fill-n wrapper vs dtor loop; different ABI |
| 6 | Scaffold `Named_CalleeOf_*` | **Reject** — structural fill-n name preferred |
| 7 | Multiple independent callers | **Falsified** — sole static caller insert-n hole arm |
| 8 | Used on grow path | **Falsified** — grow calls `FUN_004a74f0` directly; wrapper only @ hole |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Fill-n wrapper shape | **High** | Wrong insert port |
| ABI RET 0x0C + ECX | **High** | Stack corruption |
| `*0x1c` end pointer | **High** | Bad end iterator |
| Nested loop plate | **Med** | Port detail in `FUN_004a74f0` |
| Product demangle | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// FUN_004a7ad0 hole arm (W34-R):
//   FUN_004a6b50(where, end, where+count*0x1c);  // shift suffix
//   FUN_004a7a70(end, remaining_count, value);    // uninit fill tail of hole
//   end += count*0x1c;
//   FUN_004a68a0(...);                            // assign-fill constructed prefix
// Grow path: FUN_004a74f0(dest, count, value, ...) directly — no 004a7a70.
// Twin: char FUN_00430390 under StdVector_InsertN_BasicString.
```

Live decompile 2026-07-29 ≡ thin wrapper. Relative call seals `FUN_004a74f0`. Closes W34-R residual nested fill wrapper plate.

---

## 4. Surviving contract for AutoCore

```
// Port as uninit_fill_n for vector<wstring> (elem 0x1c):
wstring* UninitFillN(void* /*alloc*/, wstring* dest, int count, const wstring& val) {
  for (int i = 0; i < count; ++i)
    new (dest + i) wstring(val);
  return dest + count;
}
// thiscall-ish host/alloc may be unused; preserve RET 0x0C if matching ABI.
// Prefer implementing fill in one place; retail splits wrapper vs loop (004a7a70 / 004a74f0).
// Grow may call the loop helper directly — do not require this wrapper on all fill sites.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/return math/sole hole caller. Residual nested product + demangle → **accept-with-gaps**.
