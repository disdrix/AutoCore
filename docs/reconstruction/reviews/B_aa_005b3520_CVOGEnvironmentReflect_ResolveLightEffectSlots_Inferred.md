# Review B (skeptical / adversarial): `aa_005b3520` CVOGEnvironmentReflect_ResolveLightEffectSlots_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b3520` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W37-F) |
| **Counterpart** | `reviews/A_aa_005b3520_CVOGEnvironmentReflect_ResolveLightEffectSlots_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler `void __fastcall` without this | **Partial** — ECX is this; convention is thiscall; no stack args sealed by bare RET |
| 2 | Enter when **both** lights non-null | **Falsified** — bytes `CMP [host+0x104],0` / `JNZ ret` require hemi **null**; dataflow CBRANCH → `0x005b357a` |
| 3 | Useful notify after `RebuildDefaultLights` | **Weakened** — rebuild sets both lights → this no-ops; “notify” is cold/no-op after full rebuild |
| 4 | Body is fog-specific math | **Falsified** — pure pointer copy + one bind; no fog math |
| 5 | Scaffold `Named_CalleeOf_*` is plate | **Reject** — Reflect RTTI + enable/rebuild callers seal structural name |
| 6 | Many callers | **Falsified** — exactly 2 xrefs (`005b39a0`, `0048f370`) |
| 7 | Clean should “fix” hemi gate to `!=0` | **Reject** — would invent CF; keep residual explicit |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 91 B body + bare RET | **High** | Size/ABI |
| Slot offsets `+0x150`/`+0x154`/`+0x15c`/`+0xe894`/`+0x108`/`+0x104`/`+0x8c` | **High** | Wrong layout |
| Hemi-null gate | **High** (bytes) | Port mismatch if assumed both-lights |
| Reflect host class | **High** | Naming only |
| When body actually mutates state in retail sessions | **Low/Open** | Runtime residual |
| Runtime / bit-exact | **Open** | Matrix |

---

## 3. Cross-check against raw + bytes + xrefs

- Full 91 B hex ends `…8B 49 04 50 E8 … C3`.
- `get_function_by_address`: body `005b3520–005b357a`.
- Callers tool: `FUN_005b39a0`, `FUN_0048f370` only.
- Callee: `FUN_0074e310` only.
- Ctor `005b35a0` zeros `+0x150`/`+0x154`, stores parent at `+0x15c`.
- W32-R seals light pair at host `+0x108`/`+0x104` with cores at `+0x8c`.

---

## 4. Surviving contract for AutoCore

```
// Port as Reflect once-resolve of nested light effect cores (not fog math):
void Reflect_ResolveLightEffectSlots(CVOGEnvironmentReflect* self) {
  if (self->slot154) return;
  auto* host = self->parent->obj_e894; // parent @ +0x15c
  if (!host->dir_light_108) return;
  if (host->hemi_light_104) return;   // byte-faithful residual gate
  self->slot154 = host->dir_light_108->effect_core_8c;
  self->slot150 = host->hemi_light_104->effect_core_8c; // null-deref if gate held
  FUN_0074e310(self->aux4, self->slot150);
}
// Do not assume this runs productively after full light rebuild.
// Do not invent product English for +0x8c cores without further RTTI.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI, offsets, callers, and the **hemi-null** gate (often no-op). Residual product intent + runtime open. **accept-with-gaps**.
