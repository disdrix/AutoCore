# Review B (skeptical / adversarial): `aa_008327f0` CMenuChatlog_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_008327f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY WQ9J-C) |
| **Counterpart** | `reviews/A_aa_008327f0_CMenuChatlog_CompleteDtor.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is the scalar-deleting dtor | **Falsified** — no flags arg; no `operator_delete(this)`; scalar is `FUN_004165f0` |
| 2 | Installs base vtbl `00a72f6c` / `00a98f44` here | **Falsified** — installs `00a70524`; intermediate base reinstalls its own |
| 3 | Does own clear/free of nested members inline | **Falsified** — only chains `0082d540`; teardown is nested |
| 4 | Same body as scalar | **Falsified** — 59 B SEH complete vs 30 B scalar |
| 5 | No SEH / cdecl free-stack | **Falsified** — full SEH + ADD ESP,0x10; RET |
| 6 | Product class is unproven chatlog-from-string only | **Falsified** — RTTI `.?AVCMenuChatlog@@` at type_info `0x00affb04` |
| 7 | Vector-deleting form | **Falsified** — no count; no array delete loop |
| 8 | Direct call to `00792c20` | **Falsified** — sole callee is `0082d540` (which later reaches `00792c20`) |
| 9 | Merge with neighbor complete `0097a8a0` | **Falsified** — different vtbl, RTTI class, base chain |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Complete vs scalar | **High** | Double free / leak |
| Derived then base chain | **High** | Wrong dtor order |
| Vtbl install address | **High** | Wrong type identity |
| SEH epilogue | **High** | Stack imbalance |
| Product plate CMenuChatlog | **High** (RTTI) | Naming only if wrong |
| Intermediate base dual | **Open** | Nested teardown detail |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// Scalar FUN_004165f0:
//   FUN_008327f0(this);
//   if (flags & 1) operator_delete(this);
// Intermediate FUN_0082d540:
//   *this = PTR_FUN_00a72f6c; FUN_0082ce20(); FUN_00792c20();
// Vtbl 00a70524[0]=004165f0
// RTTI: .?AVCMenuChatlog@@
```

Live decompile 2026-08-05 ≡ disasm listing; body hex 59 B seals install + call + epilogue.

---

## 4. Surviving contract for AutoCore

```
// Port as DERIVED complete dtor only:
void CMenuChatlog_CompleteDtor(CMenuChatlog* self) {
  self->vtbl = &PTR_FUN_00a70524;
  FUN_0082d540(self); // intermediate base complete chain
  // scalar path deletes self if flags&1
}
// Do not invent derived member teardown beyond this body.
// Do not free this here.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/vtbl/chain/RTTI. Residual intermediate-base dual + runtime → **accept-with-gaps**.
