# Review B (skeptical / adversarial): `aa_00436ef0` Mem_FillDwordN_FromSrc_EaxEcxEdx

| Field | Value |
|---|---|
| **Stable ID** | `aa_00436ef0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W34-D) |
| **Counterpart** | `reviews/A_aa_00436ef0_Mem_FillDwordN_FromSrc_EaxEcxEdx.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Stack formals / stdcall | **Falsified** — bare `C3`; no stack arg loads |
| 2 | Decompiler 2-arg `__fastcall` is complete ABI | **Incomplete** — omits EAX dest; bytes + callers set EAX before call |
| 3 | Same as `Mem_FillDwordN_ReturnEnd` | **Falsified** — different registers (EDI/ESI vs EAX/ECX); this unit no end-return; has null gate |
| 4 | Hoists `*src` once | **Falsified** — `MOV ESI,[EDX]` inside loop |
| 5 | Null dest aborts whole fill | **Falsified** — still advances EAX/decrements ECX |
| 6 | Has callees | **Falsified** — leaf |
| 7 | Scaffold `Named_CalleeOf_*` is product | **Rejected** |
| 8 | Only used by Ass bags | **Falsified** — 14+ callers / 18 xrefs across modules |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Register ABI EAX/ECX/EDX | **High** | Wrong port linkage |
| Null-safe + always-advance | **High** | Miss OOM path behavior |
| Leaf / bare RET | **High** | Invented callees |
| Product role per caller | **Open** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + parent

```
// PtrVecShell_InitFill (FUN_004646e0) fill path (sealed W33-B):
//   p = operator_new(count*4)
//   EAX = p; EDX = fill_src; ECX = count
//   call FUN_00436ef0
//   shell.end = p + count*4
```

Full 23 B hex:

```
85c976125685c074048b32893083c00483e90175f05ec3
```

Decompile 2026-07-29 ≡ scaffold. Parent W33-B dual already documented this helper as `ECX=count, EDX=src, EAX=dst; *dst++=*src`.

---

## 4. Surviving contract for AutoCore

```
// Register ABI helper — do not invent stdcall formals:
void fill_n(uint32_t* dst /*EAX*/, int n /*ECX*/, uint32_t const* src /*EDX*/) {
  for (; n != 0; --n) {
    if (dst) *dst = *src;
    ++dst;
  }
}
// Pair with PtrVecShell_InitFill; do not conflate with Mem_FillDwordN_ReturnEnd.
```

---

## 5. Verdict

Adversarial pass confirms A on full leaf contract. Residual multi-caller product English does not block the sealed helper → **accept**.
