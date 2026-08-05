# Review B (skeptical / adversarial): `Gfx_SurfaceFormat_AssertUnknownFormat` @ `0x0044b1f0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044b1f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0044b1f0_Gfx_SurfaceFormat_AssertUnknownFormat.md` |
| **Verdict** | **accept** on size CF; **reject** treating unit as pure assert-only helper |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function only asserts / never returns size | **Falsified** — most paths `return w*h*k` or DXT block products |
| 2 | Canonical name fully describes role | **Overstated** — `AssertUnknownFormat` is the **unknown** tail only |
| 3 | Pure `__fastcall` single ECX arg | **Falsified / incomplete** — width in **EAX**, height in **ESI** are required formals |
| 4 | Stack args for w/h | **Falsified** — plain `ret`; formals in registers |
| 5 | DXT uses raw `w*h/16` without max(1,·) | **Falsified** — ceil-div4 + select max with constant 1 |
| 6 | FourCC table wrong endian | **Falsified** — `0x31545844` is little-endian `'DXT1'` |
| 7 | Crashes / aborts on unknown | **Falsified** — logs via `vog_LogMessage` and returns **0** |
| 8 | Many call sites / hot path critical | **Weakened** — only **2** static callers |
| 9 | Clean invents CF vs decompile | **Falsified** — scaffold tracks raw |
| 10 | Runtime bit-exact sealed | **Open** — static only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Size products for discrete case IDs | **High** | Wrong GPU upload / pitch |
| Register formals ECX/EAX/ESI | **High** | Wrong caller ABI → garbage size |
| Unknown returns 0 + log | **High** | Port that aborts loses retail tolerance |
| Enum→English D3D names | **Medium** | docs only; IDs still sealed |
| `AssertUnknownFormat` as sole product name | **Low–Med** | misleads search; prefer CalcByteSize role |
| Pitch vs total size semantics | **Medium** | body returns full surface product, not row pitch |

---

## 3. Surviving contract for AutoCore

```
// custom register formals: ECX=format, EAX=width, ESI=height
int Gfx_SurfaceFormat_CalcByteSize(int format, int width, int height)
{
  // switch/FourCC → width*height*{1,2,3,4,8,16}
  // DXT1:  max(1,ceil(w/4))*max(1,ceil(h/4))*8
  // DXT2-5: max(1,ceil(w/4))*max(1,ceil(h/4))*16
  // default: log effSurfaceFormat.h:0x1f2 "Unknown Texture format..." ; return 0
}
```

Port rule: treat as **size helper with soft fail**, not hard assert. Do not invent stack args.

---

## 4. Residual attacks that survive as open gaps

1. Exact product enum names for non-DXT case IDs (`0x14`…`0x75`) — need D3D / engine header crosswalk.
2. Whether `width`/`height` are pixels vs blocks for non-DXT (assume pixels; High from `w*h*bpp`).
3. Caller sites `FUN_0096c730` / `FUN_0096c810` not dualed — how they set EAX/ESI unsealed here.
4. `FUN_0076cec0` format-buffer API surface only as string producer.

**Verdict:** **accept** size calculator CF; document name as partial; never port as assert-only.
