# Review B (skeptical / adversarial): `aa_00416410` StdString_OperatorPlus_String

| Field | Value |
|---|---|
| **Stable ID** | `aa_00416410` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W33-F) |
| **Counterpart** | `reviews/A_aa_00416410_StdString_OperatorPlus_String.md` |
| **Scratch** | `tmp/a_00416410.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Same function as 00416490 (duplicate) | **Falsified as identity** — distinct IAT for `+=`; different callers; adjacent but separate bodies |
| 2 | thiscall member | **Falsified** — free cdecl; three stack args; plain `C3` |
| 3 | rhs is `char const*` | **Falsified** — IAT `[0x009c62a0]` string `+=`; decompiler types both params as basic_string* |
| 4 | In-place mutate of lhs | **Falsified** — lhs only used as copy source; temp is mutated |
| 5 | Product demangle sealed | **Careful** — structural name only |
| 6 | Body ends at 00416490 | **Partial** — exclusive end 0041648a with CC pad then 00416490 starts |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Free operator+ CF | **High** | Wrong string concat |
| cdecl + 3 stack + C3 | **High** | ABI crash |
| rhs string | **High** | Wrong overload |
| Twin of 00416490 | **High** | Mis-pair |
| Product plate | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// Byte twin of 00416490: only ff15 a0629c00 vs ff15 b0629c00
// Shared SEH LAB_009bc093 + shared copy/dtor IAT
// Fewer callers (6 xrefs) than cstr twin (12)
// Callers: FUN_006874b0, FUN_00750260, FUN_009839b0, FUN_00984340
```

Live decompile 2026-07-29 ≡ raw 2026-07-23; body hex seals size + RET.

---

## 4. Surviving contract for AutoCore

```
// Port as free operator+(string, string) return-by-value:
MsvcBasicString* StdString_OperatorPlus_String(
    MsvcBasicString* out, const MsvcBasicString* lhs, const MsvcBasicString* rhs) {
  MsvcBasicString tmp;
  copy_ctor(&tmp, lhs);
  op_plus_eq_string(&tmp, rhs);
  copy_ctor(out, &tmp);
  dtor(&tmp);
  return out;
}
// cdecl; do not invent thiscall. Pair with StdString_OperatorPlus_Cstr (00416490).
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/IAT overload/twin. Residual demangle + runtime → **accept-with-gaps**.
