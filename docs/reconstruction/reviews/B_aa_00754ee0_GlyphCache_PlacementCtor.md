# Review B (skeptical / adversarial): `aa_00754ee0` GlyphCache_PlacementCtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00754ee0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W35-H) |
| **Counterpart** | `reviews/A_aa_00754ee0_GlyphCache_PlacementCtor.md` |
| **Scratch** | `tmp/a_00754ee0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | ECX-thiscall ctor | **Falsified** — `MOV ESI,[ESP+…]`; `RET 4` |
| 2 | Decompiler/analyze void = full ABI | **Falsified** — stack this* + return this |
| 3 | Object is generic / unknown class | **Falsified** — vtbl string `"Failed to create texture for glyph cache"` |
| 4 | Size unknown | **Falsified** — caller `operator_new(0xB8)` |
| 5 | Nested call is ECX-thiscall into bag | **Falsified** — W34-G stack this* `FUN_004438c0` |
| 6 | All fields zeroed | **Falsified** — `+0x08` and `+0x84..+0x93` unwritten |
| 7 | Scaffold gfxFont name is product | **Rejected** — parent-seed alias only |
| 8 | This unit frees host | **Falsified** — no `operator_delete`; scalar dtor is vtbl[0] path |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Stack this* RET 4 | **High** | ABI crash |
| GlyphCache product class | **High** | wrong domain port |
| Nested bag +0x44 | **High** | layout skew |
| Unwritten gaps acknowledged | **High** | false full-init claim |
| Default global semantics | **Low** | wrong defaults |
| Runtime | **Open** | matrix |

---

## 3. Cross-check against raw + bytes + callers

```
// FUN_00754ee0
ESI = stack this; vtbl; string; NestedHashBag(self+0x44); zeros; RET 4

// FUN_0073bc50
p = new(0xB8); if (p) p = FUN_00754ee0(p);
// on font texture fail: (*p->vtbl)(1)  // scalar deleting
// on success: p->refcount++
```

Decompile CF matches; product string is adjacent to vtbl dwords (not a random .rdata hit).

---

## 4. Surviving contract for AutoCore

```
// Port as placement ctor (stack this, RET 4), size 0xB8:
GlyphCache* GlyphCache_PlacementCtor(GlyphCache* self);
// Must: set vtbl 00a9f584 family; refcount0; string @+0x18;
//        NestedHashBag @+0x44 via W34-G helper; copy DAT_00d1f01c/020 pairs.
// Must not: assume ECX-thiscall; assume full zero of 0xB8; free self.
// Do not invent field English for unwritten slots.
```

---

## 5. Verdict

Adversarial pass confirms A: ABI + product + nest sealed; gaps are residual only → **accept-with-gaps**.
