# Review B (skeptical / adversarial): `aa_0073bc50` GlyphCache_GetOrCreate_ByFontKey_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0073bc50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W37-AE) |
| **Counterpart** | `reviews/A_aa_0073bc50_GlyphCache_GetOrCreate_ByFontKey_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Returns gfxFontImpl* (RTTI exists) | **Falsified** — alloc size **0xB8** + W35-H **GlyphCache** placement ctor; gfxFont is the **caller** layer |
| 2 | Always creates (no cache) | **Falsified** — hit path returns `*(node+0x2c)` without new |
| 3 | Arial is only font | **Falsified** — Arial is **fallback** after requested name fails `FUN_00754a10` |
| 4 | ECX is `this` map object | **Attacked** — map is a **stack** formal; ECX packs into key / rasterize size. Decompiler `thiscall` label is ABI shape, not "map is this" |
| 5 | Scaffold gfxFont name is product plate | **Rejected as unit name** — use GlyphCache get-or-create; product path still seals domain via sole caller |
| 6 | Fail path leaks the 0xB8 | **Falsified** — scalar deleting `vtbl[0](1)` before null return |
| 7 | Hit path AddRefs | **Falsified in this unit** — hit returns raw pointer; wrapper `0099ed40` AddRefs after |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| RET 12 / 503 B / SEH | **High** | ABI crash |
| GlyphCache 0xB8 product | **High** | wrong type port |
| Arial fallback order | **High** | wrong font policy |
| Hit value +0x2c | **High** | wrong cache pointer |
| Map helper full dual | **Low** | insert/lookup edge cases |
| Key field English | **Medium** | wrong font size mapping |
| Runtime | **Open** | matrix |

---

## 3. Cross-check against raw + bytes + callers

```
// FUN_0099ed40 (gfxFont.cpp):
p = FUN_0073bc50(DAT_00d1f628, name, ...);
if (!p) log "Failed to create font: %s"; return -1;
AddRef p; swap into *out_font_slot

// FUN_0073bc50 miss:
new(0xB8) → GlyphCache_PlacementCtor → FUN_00754a10(name|Arial)
// hit: return *(it+0x2c)
```

Live decompile 2026-08-04 ≡ raw 2026-07-23 CF. `"Arial"` xrefs include this body @ `0x0073bd2c`.

---

## 4. Surviving contract for AutoCore

```
// Port as map get-or-create (not a bare ctor; not gfxFontImpl):
GlyphCache* GlyphCache_GetOrCreate_ByFontKey_Inferred(
    int size_or_style, void* font_map, const char* face, int key_b);
// Must: hit → node+0x2c; miss → 0xB8 GlyphCache + rasterize + insert.
// Must: Arial fallback; fail → scalar dtor + null.
// Must not: treat as ECX-this map method; AddRef on hit inside this unit;
//           invent full node layout beyond +0x2c without dualing insert helper.
```

---

## 5. Verdict

Adversarial pass confirms A: product + CF + ABI sealed; residual map duals and key English → **accept-with-gaps**.
