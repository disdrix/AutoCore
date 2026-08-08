# Review B (skeptical / adversarial): `aa_0097a8a0` CWndTutorial_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0097a8a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY WQ9J-C) |
| **Counterpart** | `reviews/A_aa_0097a8a0_CWndTutorial_CompleteDtor.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is the scalar-deleting dtor | **Falsified** — no flags arg; no `operator_delete(this)`; scalar is `FUN_004160b0` |
| 2 | Installs deep base vtbl `00a98f44` here | **Falsified** — installs `00a6f61c`; base reinstalls its own |
| 3 | Does own clear/free of nested members inline | **Falsified** — only chains `00792c20`; teardown is nested |
| 4 | Same body as scalar | **Falsified** — 59 B SEH complete vs 30 B scalar |
| 5 | No SEH / cdecl free-stack | **Falsified** — full SEH + ADD ESP,0x10; RET |
| 6 | Product class is only circumstantial from dds string | **Falsified** — RTTI `.?AVCWndTutorial@@` at type_info `0x00affaa4` |
| 7 | Vector-deleting form | **Falsified** — no count; no array delete loop |
| 8 | Goes through intermediate `0082d540` like chatlog | **Falsified** — sole callee is **direct** `00792c20` |
| 9 | Merge with twin complete `008327f0` | **Falsified** — different vtbl, RTTI class, base chain depth |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Complete vs scalar | **High** | Double free / leak |
| Derived then base chain | **High** | Wrong dtor order |
| Vtbl install address | **High** | Wrong type identity |
| SEH epilogue | **High** | Stack imbalance |
| Product plate CWndTutorial | **High** (RTTI) | Naming only if wrong |
| Deep base dual | **Open** | Nested teardown detail |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// Scalar FUN_004160b0:
//   FUN_0097a8a0(this);
//   if (flags & 1) operator_delete(this);
// Base FUN_00792c20:
//   *this = PTR_FUN_00a98f44; teardown owned children; …
// Vtbl 00a6f61c[0]=004160b0
// RTTI: .?AVCWndTutorial@@
```

Live decompile 2026-08-05 ≡ disasm listing; body hex 59 B seals install + call + epilogue.

---

## 4. Surviving contract for AutoCore

```
// Port as DERIVED complete dtor only:
void CWndTutorial_CompleteDtor(CWndTutorial* self) {
  self->vtbl = &PTR_FUN_00a6f61c;
  FUN_00792c20(self); // deep UI base complete
  // scalar path deletes self if flags&1
}
// Do not invent derived member teardown beyond this body.
// Do not free this here.
// Do not merge with CMenuChatlog_CompleteDtor (different base path).
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/vtbl/chain/RTTI. Residual deep-base dual + runtime → **accept-with-gaps**.
