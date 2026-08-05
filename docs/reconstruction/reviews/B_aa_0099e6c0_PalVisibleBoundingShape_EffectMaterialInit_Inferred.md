# Review B (skeptical / adversarial): `aa_0099e6c0` PalVisibleBoundingShape_EffectMaterialInit_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0099e6c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W36-H) |
| **Counterpart** | `reviews/A_aa_0099e6c0_PalVisibleBoundingShape_EffectMaterialInit_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | No formals / void | **Falsified** — ECX = self; decomp `__fastcall int param_1` |
| 2 | Returns constructed object | **Falsified** — returns status OR of six uint stages |
| 3 | Generic mesh init (no product plate) | **Falsified** — image string `PalVisibleBoundingShape.fx` + four `*Mat*` names |
| 4 | Multiple callers | **Falsified** — single xref from `FUN_0073c810` @ `0x0073c869` |
| 5 | Operates on wrong offset | **Falsified** — `LEA ESI,[EDI+0x20]` resource slot consistent |
| 6 | Name invents "Palantir" product class | **Careful** — FX filename is product evidence for **effect** identity; host class English still open; `_Inferred` retained |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX self + status OR | **High** | Wrong ABI |
| FX + material string set | **High** | Wrong asset bind |
| Sole HostPtrTable12 caller | **High** | Lifecycle only |
| Helper internals | **Low** | Port stubs needed |
| Host class English | **Low** | Naming only |

---

## 3. Cross-check against raw + bytes + xrefs

- Full 469 B hex ends `83 c4 68 c3` then `CC` pad.
- Immediate pushes of string VAs match `read_memory` ASCII.
- W35-E slot 0 sequence: `new(0xC4)` → `FUN_00748960` → dual vtbl → **this** — not interchangeable with sibling slot inits (`FUN_0099e4a0` etc.).

---

## 4. Surviving contract for AutoCore

```
// Port as ECX post-ctor FX/material init for PalVisibleBoundingShape host:
uint32_t InitPalVisibleBoundingShape(MeshHost* self /* ECX */) {
  LoadFx("PalVisibleBoundingShape.fx"); // via self+0x20
  BindMat("SolidMatDiffuse");
  BindMat("SolidMatEmissive");
  BindMat("WireMatDiffuse");
  BindMat("WireMatEmissive");
  RefcountSwap(self+0x20);
  return statusOr; // 0 = all stages OK
}
// Only known caller: HostPtrTable12 slot 0 after base ctor + dual vtbl.
// Do not reuse for other slot FX inits without their own strings.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI, product FX/material strings, sole-caller wiring, status OR. Residual helper contracts + host plate → **accept** (not accept-with-gaps: sealed unit CF is complete; residuals are unowned callees).
