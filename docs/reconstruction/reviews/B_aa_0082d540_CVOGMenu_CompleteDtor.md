# Review B (skeptical / adversarial): `aa_0082d540` CVOGMenu_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0082d540` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY WQ9K-G) |
| **Counterpart** | `reviews/A_aa_0082d540_CVOGMenu_CompleteDtor.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is the scalar-deleting dtor | **Falsified** — no flags arg; no `operator_delete(this)`; scalar is `FUN_004166d0` |
| 2 | Installs derived CMenuChatlog vtbl `00a70524` here | **Falsified** — installs `00a72f6c`; derived reinstalls its own before chaining |
| 3 | Installs deep base `00a98f44` here | **Falsified** — that install is inside `00792c20` |
| 4 | Does own clear of all NDUI dialog members inline | **Falsified** — only hash helper + chain; dialog slots are in base |
| 5 | Same body as CMenuChatlog complete | **Falsified** — 79 B intermediate vs 59 B derived; different vtbl |
| 6 | Product is unproven “chatlog intermediate” only | **Falsified** — RTTI `.?AVCVOGMenu@@` at type_info `0x00afe39c` |
| 7 | Vector-deleting form | **Falsified** — no count; no array delete loop |
| 8 | Direct free of host | **Falsified** — epilogue RET without delete; scalar free is optional |
| 9 | Merge with `00792c20` as same class | **Falsified** — different RTTI, vtbl, body size, callees |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Complete vs scalar | **High** | Double free / leak |
| Intermediate then CNDUIDialog chain | **High** | Wrong dtor order |
| Vtbl install address | **High** | Wrong type identity |
| SEH epilogue | **High** | Stack imbalance |
| Product plate CVOGMenu | **High** (RTTI) | Naming only if wrong |
| Hash helper dual | **Open** | Nested teardown detail |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// Scalar FUN_004166d0:
//   FUN_0082d540(this);
//   if (flags & 1) operator_delete(this);
// Derived FUN_008327f0:
//   *this = PTR_FUN_00a70524; FUN_0082d540(this);
// This body:
//   *this = PTR_FUN_00a72f6c; FUN_0082ce20(); FUN_00792c20();
// RTTI: .?AVCVOGMenu@@
```

Live decompile 2026-08-05 ≡ disasm listing; body hex 79 B seals install + two calls + epilogue.

---

## 4. Surviving contract for AutoCore

```
// Port as INTERMEDIATE complete dtor only:
void CVOGMenu_CompleteDtor(CVOGMenu* self) {
  self->vtbl = &PTR_FUN_00a72f6c;
  FUN_0082ce20(self);      // menu hash teardown
  FUN_00792c20(self);      // CNDUIDialog_CompleteDtor
  // scalar path deletes self if flags&1
}
// Do not free this here.
// Do not invent CMenuChatlog-only fields in this body.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/vtbl/chain/RTTI. Residual hash helper dual + runtime → **accept-with-gaps**.
