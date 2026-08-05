# Review B (skeptical / adversarial): `aa_004c4440` Object_ResolveStoredTFID_Vtbl1dc_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c4440` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W27-G) |
| **Counterpart** | `reviews/A_aa_004c4440_Object_ResolveStoredTFID_Vtbl1dc_Inferred.md` |
| **Scratch** | `tmp/a_004c4440.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | cdecl / stack formal | **Falsified** — `MOV ESI,ECX`; epilogue `RET` not `RET n` |
| 2 | Always resolves | **Falsified** — invalid TFID short-circuits to 0 |
| 3 | Invalid test is lo==0 only | **Falsified** — `(lo&hi)==~0` **and** `(char)w2==0` |
| 4 | Returns resolved object pointer always | **Falsified** — returns **vtbl+0x1dc** result, and only if nonzero |
| 5 | Leaf / no callees | **Falsified** — CALL `Object_ResolveFromTFID` + virtual |
| 6 | Decompiler shows full thiscall of resolve | **Residual** — surface omits manager ECX; bytes rebuild `+0xE4E8` ctx (matches 004bb950 dual) |
| 7 | Product name of vtbl+0x1dc is known | **Overstated** — offset sealed; English residual → `_Inferred` suffix |
| 8 | Static CALL callers exist | **Falsified** — DATA/vtable xrefs only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall RET 0 | **High** | ABI break |
| TFID_16 @ +0x108 | **High** | Wrong identity field |
| Invalid predicate ≡ 004c4620 | **High** | Wrong gate vs mode leaf |
| Resolve callee 0x004bb950 | **High** | Wrong world lookup |
| Manager ECX residual | **High** | Port missing ctx → always NULL |
| vtbl+0x1dc semantics | **Medium** | Wrong related-object interpretation |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
thiscall Object_ResolveStoredTFID_Vtbl1dc_Inferred(this)
if invalid_tfid(this+0x108): return 0
local = copy TFID_16
ctx = chain(*(this+4), +0xA8, +0xE4E8)
obj = Object_ResolveFromTFID(ctx, &local)
if !obj: return 0
r = obj->vtbl[0x1dc/4]()
return r ? r : 0
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Rel32 from `0x004c449d` → `0x004bb950`. Sibling `FUN_004c4620` pure mode; `FUN_004c4880` mode writer uses same predicate.

---

## 4. Surviving contract for AutoCore

```
// When needing the related entity behind object identity:
related = Object_ResolveStoredTFID_Vtbl1dc_Inferred(obj);
// returns 0 if TFID unassigned OR resolve miss OR virtual returns 0
// Port must supply resolve ctx (manager) — decompiler surface alone is incomplete
// Do not treat return as the TFID-resolved object* without verifying vtbl+0x1dc role
```

---

## 5. Verdict

Adversarial pass **confirms** A: CF/ABI/predicate/resolve/virtual sealed; product English for +0x1dc residual only → **accept**.
