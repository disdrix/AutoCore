# Review B (skeptical / adversarial): `aa_00512d10` Object_ApplyFxWithTargetBind_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00512d10` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W21-A) |
| **Counterpart** | `reviews/A_aa_00512d10_Object_ApplyFxWithTargetBind_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Always uses full `ApplyWithNfxEnsure` | **Falsified** — only when `param_8==0` && subsystem live && null out-FX |
| 2 | Always creates FX even if `param_9` provided | **Falsified** — provided FX skips ensure; only ORs bit 2 |
| 3 | `param_7` is pure signed float cast | **Falsified as machine** — FILD + add `2^32` when negative → **unsigned** float |
| 4 | Offset is full XYZ from entity | **Falsified** — only third component from `param_7`; x=y=w=0 |
| 5 | TFID always from `this` | **Falsified** — from optional **target** `param_6` (`+0x160` or nested) |
| 6 | Direct CALL callers dominate | **Falsified** — DATA vtbl installs; no CALL callers |
| 7 | `FUN_004b68c0` this = target entity | **Falsified** — machine ECX = FX (`ESI`/`param_9`) |
| 8 | Leaf / no post side effects | **Falsified** — `FUN_004b7e50` after attach |
| 9 | `ret 0x1c` like ApplyWithNfx | **Falsified** — `ret 0x20` (8 stack args) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Dual path gate order | **High** | Wrong FX master load path |
| `ret 0x20` ABI | **High** | Stack corruption on port |
| Flag `\|2` | **High** | Missing FX state bit |
| TFID +0x160 | **High** | Bind wrong identity |
| Unsigned float `param_7` | **High** | Negative offset wrong magnitude |
| Nested +0xf8 arg list | **Medium** | Attach may drop args in port |
| Product name | **Low** | Cosmetic / search only |

---

## 3. Cross-check against raw + sealed callees

```
if (!skip && subsystem_live && !fx)
  return ApplyWithNfxEnsure(...);          // host DAT_00b041fc
if (!fx) fx = EnsureMasterAndResolve(..., 1);
if (!fx) return 0;
*fx |= 2;
if (target) SetTargetTfidAndOffset(fx, tfid, {0,0,u32float(z),0});
attach via vtbl+0xf8;
PostFx(fx, zeros...);
return 1;
```

Clean must **not** invent network send, damage apply, or full XYZ from entity pose. Must not treat `param_7` as signed-only float without `2^32` adjust.

---

## 4. Surviving contract for AutoCore

```c
// Port sketch — client FX apply method (vtbl)
bool Object_ApplyFxWithTargetBind(
    Object* self,
    /* cache keys / args */ ...,
    Object* targetOpt,
    int offsetZ_as_u32_bits_source,
    bool skipFullNfx,
    FxInstance*& fxInOut)
{
  if (!skipFullNfx && ResourceSubsystemLive() && fxInOut == nullptr)
    return FxCache_ApplyWithNfxEnsure(...); // includes full path return
  if (fxInOut == nullptr)
    fxInOut = FxCache_EnsureMasterAndResolve(..., /*mode*/1);
  if (fxInOut == nullptr) return false;
  fxInOut->flags |= 2;
  if (targetOpt) {
    Tfid16 tfid = ResolveTargetTfid(targetOpt); // +0x160 or nested +0x164
    float off[4] = {0, 0, U32ToFloat(offsetZ_as_u32_bits_source), 0};
    NDSpecialFX_SetTargetTfidAndOffset(fxInOut, tfid, off);
  }
  AttachFxViaVtable(self, fxInOut); // vtbl+0xf8
  FUN_004b7e50(fxInOut, /*zeros*/);
  return true;
}
```

---

## 5. Open questions

1. Product method name on vtbls.
2. Whether flag bit 2 means "has target" / "active" / other (only OR observed).
3. Nested attach args vs direct `(fx,1,0)` — decompiler residual.
4. Runtime golden for both resolve paths.

**Verdict:** **accept-with-gaps**
