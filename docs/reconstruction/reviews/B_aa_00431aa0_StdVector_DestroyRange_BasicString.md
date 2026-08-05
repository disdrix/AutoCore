# Review B (skeptical / adversarial): `aa_00431aa0` StdVector_DestroyRange_BasicString

| Field | Value |
|---|---|
| **Stable ID** | `aa_00431aa0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W33-H) |
| **Counterpart** | `reviews/A_aa_00431aa0_StdVector_DestroyRange_BasicString.md` |
| **Scratch** | `docs/reconstruction/tmp/a_00431aa0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | POD / dword destroy (no dtor) | **Falsified** — IAT `~basic_string` each step |
| 2 | Frees the buffer | **Falsified** — no `operator_delete`; parent frees after |
| 3 | `RET 0` / cdecl only | **Falsified** — `C2 08 00` two stack args |
| 4 | Stride 0x10 / SSO modern string | **Falsified** — `ADD ESI,0x1C` |
| 5 | Domain-specific non-STL | **Falsified** — generic range destroy; only used under string vector insert |
| 6 | Scaffold `Named_CalleeOf_Named_*` | **Reject** — structural destroy-range name preferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Destroy-range shape | **High** | Leaks / double-free if port skips |
| ABI RET 0x08 | **High** | Stack corruption |
| Stride 0x1c | **High** | Wrong elem step |
| Product demangle | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// insert grow path (W32-B):
//   FUN_0046a2c0(prefix); fill; FUN_0046a2c0(suffix);
//   FUN_00431aa0(old_begin, old_end);
//   operator_delete(old_begin);
// Catch paths also destroy partial ranges via this unit.
```

Live decompile 2026-07-29 ≡ scaffold raw CF. Bytes seal `RET 8` + stride. Closes W32-B residual nested `FUN_00431aa0`.

---

## 4. Surviving contract for AutoCore

```
// Port as destroy [first, last) of basic_string (0x1c):
void DestroyRange(string* first, string* last) {
  for (; first != last; ++first) first->~basic_string();
}
// Do not free the buffer here. RET 8 / two stack formals.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/stride. Residual product demangle → **accept-with-gaps**.
