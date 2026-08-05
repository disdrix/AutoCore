# Review B (skeptical / adversarial): `Client_UI_MapView_DrawMarkersFovOverlay` / `FUN_00851630` @ `0x00851630`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00851630` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00851630_Client_UI_MapView_DrawMarkersFovOverlay.md` |
| **Verdict** | **accept-with-gaps** on CF/ABI/phases/constants; **needs-more-evidence** on product name + nested leaf math |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | cdecl with stack `this` | **Falsified** — entry `mov edi,ecx`; no stack this |
| 2 | stdcall / `ret N` | **Falsified** — epilogue plain **`C3`** |
| 3 | Server simulation / combat tick | **Falsified** — pure client draw (FUN_00757890 / screen project / UI textures) |
| 4 | Always runs every frame regardless of config | **Falsified** — requires `config+0x4fc != 0` plus world/local live |
| 5 | Draws only markers (no FOV) | **Falsified** — FOV quad + optional cone after squad phase |
| 6 | Same as entity-rich overlay `00859bc0` | **Falsified** — no world list A/B; uses `FUN_008513d0` not `FUN_00859a90`; has sin-cone path entity twin lacks |
| 7 | FOV scale is 1.0 | **Falsified** — `DAT_00aaa8a8 = 300.0f` sealed |
| 8 | Code callers exist | **Falsified** — DATA vtbl only `@00a68204` |
| 9 | Product name sealed | **Open** |
| 10 | Runtime / bit-exact | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall plain ret | **Confirmed** | Stack imbalance on port |
| this+0x488 config | **Confirmed** | Wrong host → null crash fantasy |
| +0x4fc enable | **Confirmed** | Always-on overlay |
| Phase order | **Confirmed** | Wrong draw z-order |
| 300 / 2.5 / 30 constants | **Confirmed** | FOV geometry wrong |
| Map overlay role | **High** | Mis-wire as physics |
| Icon type English | **Low** | Docs only |
| Product C++ name | **Open** | Docs only |
| Nested leaf formulas | **Open** | Port of project/draw |

---

## 3. Surviving contract for AutoCore

```
// client-only; do not port to sector sim as gameplay authority
// __thiscall
void Client_UI_MapView_DrawMarkersFovOverlay(MapView* self):
  cfg = self->config  // +0x488
  if !cfg or !world or !world.listHost or !local or !cfg.overlayEnable(+0x4fc): return

  // 1) markers DAT_00d1d964 → project → draw (tex +0x600[type] or default)
  // 2) bump layer (+0x68/+0x70/+0x74)
  // 3) auto-patrol → icon helper
  // 4) mission tree icons type 0x65
  // 5) bump; special point type 100; bump
  // 6) squad 0..3 if local+0xcb0
  // 7) bump; FOV quad scale 300/viewport; optional cone sin(angle*2.5)

// NOT entity list A/B walk (that is 0x00859bc0).
// NOT server authoritative.
```

---

## 4. Falsification notes

### 4.1 “Server map sync”

No network send/recv; callees are project/draw/texture. Porting into Sector as state mutation invents behavior.

### 4.2 Confusion with entity overlay

Sibling `0x00859bc0` walks world vectors and uses different icon helpers. Collapsing them drops entity icons or invents a cone on the wrong class.

### 4.3 thiscall trap

MSVC method: ECX = this. Ports that push this on stack and call as cdecl will misalign.

### 4.4 Decompiler float `1.4013e-45`

That is integer 1 retyped as float before division. Adversarial take: treat as **1.0f / dim * 300.0f**, not a denormal constant.

### 4.5 “Always draws cone”

Cone path requires `sin(cfg+0x514 * 2.5) > 0` and builds a second quad. Zero/negative sin skips cone.

---

## 5. Open questions

1. PDB / RTTI map panel class name.  
2. Exact meaning of icon type `0x65` vs `'d'`/`'e'`.  
3. Whether vtbl neighbor slots share the same C++ type hierarchy.  
4. Runtime golden frames.

---

## 6. Verdict

Sealed contract (ABI, gates, phases, constants) survives adversarial review. Residual gaps are product naming and nested leaves → **accept-with-gaps**.
