# Review B (skeptical / adversarial): `aa_00965ab0` MeshWeightDebugOverlay_Update

| Field | Value |
|---|---|
| **Stable ID** | `aa_00965ab0` |
| **VA** | `0x00965ab0` |
| **Canonical name** | `MeshWeightDebugOverlay_Update` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial (OWN-ONLY W36-N) |
| **Counterpart** | `reviews/A_aa_00965ab0_MeshWeightDebugOverlay_Update.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks considered

| Attack | Result |
|---|---|
| Is this `gfxDevice` itself / BeginScene? | **No** — parent `FUN_0075fb90` owns BeginScene; this is overlay object at `device+0x7A0` |
| Is this the RC resize/erase helper? | **No** — consumer of `004611e0` (which shrinks via `00461720`) |
| Product plate `Named_CalleeOf_*gfxDevice*`? | **Reject** — naming residual only; domain from mesh-weight strings |
| cdecl RET 0? | **No** — parent leaves arg on stack without cleanup → **stdcall RET 4** |
| Progress always increases? | **No** — rate_mode 0 uses **−0.005f** fade-out |
| Empty mesh path same as full? | **No** — empty skips mode loops; uses placeholder string path |
| Can we bit-exact clean whole body? | **No** — 2650 B with noisy stack types; seal structure + integration only |
| Hard-kill combat system? | **No** — only reuses `g_flHardKillInterpolate` float as a 0.005 rate |

---

## Residual risks

1. Product class name / exact file beyond gfxDevice parent residual.  
2. Complete contracts for `00759730` / `00755ab0` / layout helpers.  
3. Mesh-entry full layout.  
4. No runtime.

---

## Minimal sealed model

```
MeshWeightDebugOverlay_Update(self):  // ret 4
  dt = now - self.last_time; fixup; × rate(±0.005 by self.rate_mode)
  self.progress = clamp(progress + delta, 0, 1)
  if progress == 0: ui.vtbl+4(); return
  if dirty or progress != 1:
    nest UI; alpha = progress*255
    if no meshes: placeholder draw
    else: Resize_RcElem28(lines, …); foreach mesh/mode: sprintf + push_back
    layout; dirty = 0
```

---

## Verdict

Do not treat as gfxDevice core or as vector primitive. Domain + fade + RC UI list integration sealed. **accept-with-gaps**.
