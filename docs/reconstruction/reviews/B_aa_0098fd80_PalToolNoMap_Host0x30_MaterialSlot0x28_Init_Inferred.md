# Review B (skeptical / adversarial): `aa_0098fd80` PalToolNoMap_Host0x30_MaterialSlot0x28_Init_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0098fd80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W37-A) |
| **Counterpart** | `reviews/A_aa_0098fd80_PalToolNoMap_Host0x30_MaterialSlot0x28_Init_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | ECX-thiscall method | **Falsified** — stack formal `param_1`; caller `FUN_0098fd80(pvVar2)` |
| 2 | Dual material channels like `00731130` | **Falsified** — single slot `host+0x28` only |
| 3 | Returns OR of bind statuses | **Falsified** — constant `return 0` |
| 4 | Scaffold `Gfx_PalToolMaterialNoMap_0098fd80` sufficient sole name | **Careful** — plate real but omits Host0x30/+0x28; prefer structural `_Inferred` |
| 5 | Multiple static callers | **Falsified** — sole xref `0073cac3` |
| 6 | DepthBias means "ms-to-seconds" product | **Falsified as product English** — only reuses shared float **0.001f** |
| 7 | GhostAlpha means multi-kill blend | **Falsified as product English** — shared float **0.1f** only |
| 8 | Host size unknown | **Sealed** — caller `new(0x30)` + `FUN_00457ac0` |
| 9 | Emissive always written | **Mostly sealed** — only when handle ≥ 0 after null/-1 path |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Stack host* + sole caller | **Confirmed** | Wrong ABI / ownership |
| Slot `+0x28` | **Confirmed** | Wrong layout |
| Plate + param strings | **Confirmed** | Wrong effect binding |
| Float values 0.001 / 0.1 / (1,0.4,0.4,1) | **Confirmed** | Wrong look |
| Constant return 0 | **High** | Wrong error model |
| Product English | **Low** | Naming only |
| Helper thiscall ECX | **Probable** open | Port call wiring |
| Runtime | **Open** | Matrix |

---

## 3. Cross-check against raw + live + xrefs

- Live decompile **≡** raw body (no CF delta W37-A).
- Xref count 1: `FUN_0073c810` @ `0x0073cac3`.
- Caller sequence places this immediately after `unaff_EDI[9] = pvVar2` (HostPtrTable12 slot9).
- Sibling dual-channel unit `0x00731130` is **different** host (0x44, slots +0x34/+0x3c) — do not merge contracts.
- Emissive G/B load `DAT_00a0f720` as `undefined4` then used with floats — bits are **0.4f**; clean preserves width as uint32_t load matching decompiler.

---

## 4. Surviving contract for AutoCore

```
// Port as stack-arg post-ctor single-slot material init:
uint32_t InitPalToolNoMapHost0x30(void *host /* size 0x30 */) {
  // mat = host + 0x28
  // bind PalToolMaterialNoMap.fx
  // DepthBias=0.001; GhostAlpha=0.1
  // MatDiffuse / MatSpecular / MatEmissive(1,0.4,0.4,1)
  // refcount-swap mat holder
  // return 0
}
// Do not invent product class English beyond plate string.
// Pair with HostPtrTable12 slot9 allocation + FUN_00457ac0 ctor (FUN_0073c810).
```

---

## 5. Verdict

Adversarial pass confirms A on ABI, single slot, strings, float packs, sole caller, constant-0 return. Residual product English + unowned helpers → **accept-with-gaps**.
