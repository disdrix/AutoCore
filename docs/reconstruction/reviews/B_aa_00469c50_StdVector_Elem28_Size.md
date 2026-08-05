# Review B (skeptical / adversarial): `aa_00469c50` StdVector_Elem28_Size

| Field | Value |
|---|---|
| **Stable ID** | `aa_00469c50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W33-J) |
| **Counterpart** | `reviews/A_aa_00469c50_StdVector_Elem28_Size.md` |
| **Scratch** | `tmp/a_00469c50.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Capacity = `(cap-begin)/0x1c` | **Falsified** — only reads +4/+8 |
| 2 | Stride 4 / 0x18 / 0x38 | **Falsified** — magic `0x92492493` is ÷28 only |
| 3 | Mutates vector | **Falsified** — pure read |
| 4 | Same as `StdVector_DwordSize` | **Falsified** — different VA, different stride |
| 5 | Null begin undefined | **Falsified** — explicit 0 via early RET |
| 6 | Stack args / stdcall | **Falsified** — ECX only, bare `C3` |
| 7 | Product name retail string | **Overstated** — inferred structural |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Size formula /28 | **High** | Off-by-factor loop bounds |
| Null-safe | **High** | Spurious empty |
| ECX ABI | **High** | Wrong register load |
| Domain-agnostic helper | **High** | Over-specializing name to basic_string only |
| Runtime | **Open** | rare edge |

---

## 3. Cross-check against raw + bytes

```
bytes: mov eax,[ecx+4]; test; jnz; ret;
       mov ecx,[ecx+8]; sub; imul magic 0x92492493; sar/sign-fix; ret
raw ≡ live ≡ clean: (end-begin)/0x1c with null begin → 0
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. 9 xrefs all CALL.

Sibling `0x004024b0` uses `SAR 2` for dword stride — confirms this unit is the 0x1c twin, not a misnamed dword size.

---

## 4. Surviving contract for AutoCore

```
StdVector_Elem28_Size(vec) → n:
  begin==0 ? 0 : (end-begin)/0x1c
  // ECX=vec; bare RET
```

---

## 5. Open questions

None for this leaf beyond product English / runtime.

**Verdict:** **accept**
