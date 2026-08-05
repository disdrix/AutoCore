# Review B (skeptical / adversarial): `aa_0040d890` Class_009c7948_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d890` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W32-C) |
| **Counterpart** | `reviews/A_aa_0040d890_Class_009c7948_CompleteDtor.md` |
| **Scratch** | `tmp/a_0040d890.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is the scalar-deleting dtor | **Falsified** — no flags arg; no `operator_delete(this)`; scalar is `FUN_0040d870` |
| 2 | Installs base vtbl `009c7938` here | **Falsified** — installs `009c7948`; base complete reinstalls `009c7938` |
| 3 | Does own clear/free | **Falsified** — only chains `0040d820`; clear is nested |
| 4 | Same body as base complete | **Falsified** — thinner; no clear/7c0 inline |
| 5 | No SEH | **Falsified** — full SEH + ADD ESP,0x10 |
| 6 | Product class name sealed | **Careful** — structural from vtbl only |
| 7 | Derived adds member teardown | **Falsified in body** — only vtbl + base call |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Complete vs scalar | **High** | Double free / leak |
| Derived then base chain | **High** | Wrong dtor order |
| Vtbl install address | **High** | Wrong type identity |
| SEH epilogue | **High** | Stack imbalance |
| Product plate | **Low** | Naming only |
| Slots [1]/[2] | **Open** | Unknown methods |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// Scalar FUN_0040d870:
//   FUN_0040d890(this);
//   if (flags & 1) operator_delete(this);
// Base FUN_0040d820:
//   *this = PTR_FUN_009c7938; clear; FUN_0040d7c0(this+4);
// Vtbl 009c7948[0]=0040d870
```

Live decompile 2026-07-29 ≡ raw 2026-07-23; body hex seals install + call + epilogue.

---

## 4. Surviving contract for AutoCore

```
// Port as DERIVED complete dtor only:
void Class_009c7948_CompleteDtor(Host* self) {
  self->vtbl = &PTR_FUN_009c7948;
  StdTreeHost_PtrVal_CompleteDtor(self); // base: 009c7938 + clear + this+4
  // scalar path deletes self if flags&1
}
// Do not invent derived member teardown beyond this body.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/vtbl/chain. Residual product + vtbl slots → **accept-with-gaps**.
