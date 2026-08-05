# Review B (skeptical / adversarial): `aa_00416510` StdString_OperatorPlus_Char

| Field | Value |
|---|---|
| **Stable ID** | `aa_00416510` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W34-C) |
| **Counterpart** | `reviews/A_aa_00416510_StdString_OperatorPlus_Char.md` |
| **Scratch** | `tmp/a_00416510.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is member `operator+=` | **Falsified** — free function; 3 stack args; `+=` is nested IAT on temp |
| 2 | thiscall / `__stdcall` with RET 0xC | **Falsified** — plain `C3`; caller cleans |
| 3 | rhs is `const char*` (same as 490) | **Falsified** — IAT `[0x009c6294]` (`+=char`) not `[0x009c62b0]` |
| 4 | rhs is `basic_string` (same as 410) | **Falsified** — not `[0x009c62a0]` |
| 5 | Body is a thin jmp thunk | **Falsified** — full 122 B SEH + local temp + three IAT calls |
| 6 | Multiple product callers | **Falsified** — single xref from `FUN_009694e0` only |
| 7 | Product demangle sealed | **Careful** — structural `StdString_OperatorPlus_Char` only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Free operator+ CF | **High** | Wrong string concat semantics |
| cdecl + 3 stack + C3 | **High** | ABI crash |
| rhs single char | **High** | Wrong overload / call site |
| Peer of 00416490/00416410 | **High** | Mis-pair callees |
| Product plate | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// Byte twin of 00416490: only ff15 94629c00 vs ff15 b0629c00
// Shared SEH LAB_009bc093
// Shared IAT copy-ctor 009c62ec / dtor 009c62f4 with path helpers + W33-F peers
// Sole caller: aa_009694e0 BasicString_CopyEnsureTrailingDirSep appends '/'
```

Live decompile 2026-07-29 ≡ raw 2026-07-23; body hex seals size + RET.

---

## 4. Surviving contract for AutoCore

```
// Port as free operator+(string, char) return-by-value:
MsvcBasicString* StdString_OperatorPlus_Char(
    MsvcBasicString* out, const MsvcBasicString* lhs, char rhs) {
  MsvcBasicString tmp;
  copy_ctor(&tmp, lhs);
  op_plus_eq_char(&tmp, rhs);
  copy_ctor(out, &tmp);
  dtor(&tmp);
  return out;
}
// cdecl; do not invent thiscall.
// Peers: StdString_OperatorPlus_Cstr (00416490), StdString_OperatorPlus_String (00416410).
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/IAT overload/peer triple. Residual demangle + runtime → **accept-with-gaps**.
