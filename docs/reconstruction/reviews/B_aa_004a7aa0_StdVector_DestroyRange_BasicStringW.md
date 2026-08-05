# Review B (skeptical / adversarial): `aa_004a7aa0` StdVector_DestroyRange_BasicStringW

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a7aa0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W36-S) |
| **Counterpart** | `reviews/A_aa_004a7aa0_StdVector_DestroyRange_BasicStringW.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | POD / dword destroy (no dtor) | **Falsified** — IAT `~basic_string<wchar_t>` each step |
| 2 | Frees the buffer | **Falsified** — no `operator_delete`; parent frees after |
| 3 | `RET 0` / cdecl only | **Falsified** — `C2 08 00` two stack args |
| 4 | Stride 0x10 / SSO modern string | **Falsified** — `ADD ESI,0x1C` |
| 5 | Char `basic_string` dtor IAT | **Falsified** — wchar IAT `[0x009c62ac]` ≠ char twin `[0x009c62f4]` |
| 6 | Domain-specific non-STL | **Falsified** — generic range destroy; only under wstring vector insert |
| 7 | Scaffold `Named_CalleeOf_*` | **Reject** — structural destroy-range name preferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Destroy-range shape | **High** | Leaks / double-free if port skips |
| ABI RET 0x08 | **High** | Stack corruption |
| Stride 0x1c | **High** | Wrong elem step |
| Wchar vs char dtor IAT | **High** | Wrong string type |
| Product demangle | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// insert grow path (W34-R):
//   FUN_004a6b50(prefix); FUN_004a74f0(fill); FUN_004a6b50(suffix);
//   FUN_004a7aa0(old_begin, old_end);
//   operator_delete(old_begin);
// Catch paths also destroy partial ranges via this unit.
// Twin: char FUN_00431aa0 under StdVector_InsertN_BasicString (W32-B / W33-H).
```

Live decompile 2026-07-29 ≡ scaffold raw CF. Bytes seal `RET 8` + stride + wchar IAT. Closes W34-R residual nested `FUN_004a7aa0`.

---

## 4. Surviving contract for AutoCore

```
// Port as destroy [first, last) of basic_string<wchar_t> (0x1c):
void DestroyRange(wstring* first, wstring* last) {
  for (; first != last; ++first) first->~basic_string();
}
// Do not free the buffer here. RET 8 / two stack formals.
// Do not reuse char dtor IAT from 00431aa0.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/stride/wchar dtor. Residual product demangle → **accept-with-gaps**.
