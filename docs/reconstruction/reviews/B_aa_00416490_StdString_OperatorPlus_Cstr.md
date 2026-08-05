# Review B (skeptical / adversarial): `aa_00416490` StdString_OperatorPlus_Cstr

| Field | Value |
|---|---|
| **Stable ID** | `aa_00416490` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W33-F) |
| **Counterpart** | `reviews/A_aa_00416490_StdString_OperatorPlus_Cstr.md` |
| **Scratch** | `tmp/a_00416490.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is member `operator+=` | **Falsified** — free function; 3 stack args; no ECX-this for the free op; `+=` is nested IAT call on temp |
| 2 | thiscall / `__stdcall` with RET 0xC | **Falsified** — plain `C3`; caller cleans |
| 3 | rhs is `basic_string` (same as 410) | **Falsified** — IAT `[0x009c62b0]` (`+=cstr`) not `[0x009c62a0]` |
| 4 | Body is a thin jmp thunk | **Falsified** — full 122 B SEH + local temp + three IAT calls |
| 5 | Product demangle sealed | **Careful** — structural `StdString_OperatorPlus_Cstr` only |
| 6 | Decompiler invented basic_string types | **Partial** — types from Ghidra symbols; bytes confirm copy/`+=`/dtor IAT shape matching known string helpers (`aa_009694e0`) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Free operator+ CF | **High** | Wrong string concat semantics |
| cdecl + 3 stack + C3 | **High** | ABI crash |
| rhs C-string | **High** | Wrong overload / call site |
| Twin of 00416410 | **High** | Mis-pair callees |
| Product plate | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// Byte twin of 00416410: only ff15 b0629c00 vs ff15 a0629c00
// Shared SEH LAB_009bc093
// Shared IAT copy-ctor 009c62ec / dtor 009c62f4 with path helpers
// Callers include path/string builders (FUN_009839b0, FUN_00984340, FUN_00985010, …)
```

Live decompile 2026-07-29 ≡ raw 2026-07-23; body hex seals size + RET.

---

## 4. Surviving contract for AutoCore

```
// Port as free operator+(string, cstr) return-by-value:
MsvcBasicString* StdString_OperatorPlus_Cstr(
    MsvcBasicString* out, const MsvcBasicString* lhs, const char* rhs) {
  MsvcBasicString tmp;
  copy_ctor(&tmp, lhs);
  op_plus_eq_cstr(&tmp, rhs);
  copy_ctor(out, &tmp);
  dtor(&tmp);
  return out;
}
// cdecl; do not invent thiscall. Pair with StdString_OperatorPlus_String (00416410).
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/IAT overload/twin. Residual demangle + runtime → **accept-with-gaps**.
