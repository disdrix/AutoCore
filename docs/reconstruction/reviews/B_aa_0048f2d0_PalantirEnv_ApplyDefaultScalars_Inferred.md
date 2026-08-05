# Review B (skeptical / adversarial): `aa_0048f2d0` PalantirEnv_ApplyDefaultScalars_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0048f2d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W32-Q) |
| **Counterpart** | `reviews/A_aa_0048f2d0_PalantirEnv_ApplyDefaultScalars_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is phase init / NDRiver load | **Falsified** — no FX strings, no phase news, body only scalar stores + optional child call |
| 2 | Stack formals / RET 4 | **Falsified** — bare `C3`; no stack args; `ADD ESP,0x10` is local frame only |
| 3 | `FUN_00497c80()` is a free function with no this | **Falsified** — bytes `mov ecx,[esi+0x100]; call`; decompiler omission only |
| 4 | Floats are not 100/200 | **Falsified** — `00 00 C8 42` / `00 00 48 43` at globals |
| 5 | Bank order is 7748 then 774c | **Falsified** — first store from `009c774c` into `+0x60`, then `009c7748` into `+0x64/+0x68` |
| 6 | Sole call site is ctor only | **Partial** — Ghidra callers list ctor; second xref `0x004d966b` is real CALL with `ecx=[esi+0xE894]` but sits outside a recognized function |
| 7 | Must invent product plate for field English | **Reject** — structural `_Inferred` name only; 100/200 are sealed values without plate names |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Scalar apply role | **High** | Wrong port unit |
| Child optional reset | **High** | Miss side effect on `+0x100` |
| Float constants | **High** | Wrong defaults |
| Product field English | **Low** | Naming only |
| Orphan site owner | **Open** | Miss second lifecycle call |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + body + peers

```
// This VA: optional child reset + write defaults + clear +0x178
// PalantirEnv_Ctor: ... new child@+0x100; call this; return this
// PalantirEnv_InitPhases: zeros +0x178 again after phases; does NOT re-run this
// Second site: reload env from parent+0xE894 and re-apply defaults
```

Live decompile 2026-07-29 ≡ raw scaffold CF; bytes seal child ECX and all stores.

---

## 4. Surviving contract for AutoCore

```
// Port as env method (ECX = 0x198 host):
void PalantirEnv_ApplyDefaultScalars(void* env) {
  if (env->child_at_0x100) FUN_00497c80(env->child_at_0x100);
  env->f_0x10c = 100.f;
  env->f_0x110 = 200.f;
  env->bank60 = { ~0.215646f, ~0.254894f, ~0.254894f, 1.f };
  env->u_0x178 = 0;
}
// Call after child install in ctor; may re-run when parent rebinds env@+0xE894.
// Do NOT fold into InitPhases.
// Do NOT use scaffold parent-seed name.
```

---

## 5. Verdict

Adversarial pass confirms A on role/ABI/constants/child thiscall. Residual product English + orphan site identity → **accept-with-gaps**.
