# Review B (skeptical / adversarial): `aa_004941b0` Host_RebuildElem0x28ArrayFromMap_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004941b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W30-Q) |
| **Counterpart** | `reviews/A_aa_004941b0_Host_RebuildElem0x28ArrayFromMap_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Primary name is VOG_DEBUG_STOP | **Falsified** — string only on null-map assert; body is free+rebuild grid |
| 2 | cdecl / no stack arg | **Falsified** — `RET 4` both paths; stack `mapCtx` used at `+0xe4f8`/`+0xf5` |
| 3 | Host is caller's ECX directly | **Falsified** — caller loads `ecx = *([caller+0x340]+0xe898)`; pushes map as stack arg |
| 4 | Scale constants are ints | **Falsified** — `read_memory` yields IEEE floats 64.0f / 32.0f |
| 5 | Formula omits +1 or ROUND | **Falsified** — decompile has ROUND(...) + 1 on both dims |
| 6 | Element stride differs from free helper | **Falsified** — same 0x28 + same dtor `FUN_005b8000`; ctor `FUN_005b7db0` zeros matching fields |
| 7 | Decompiler invented map offsets | **Falsified** — body bytes reference `+0xe4f8` and `+0xf5` on stack-restored ctx; map `+0x10/+0x14/+0x18` via FPU loads |
| 8 | Early exit zeros dims like free helper | **Falsified** — only `+0x28` zeroed before assert; `+4/+8` not cleared on VOG path |
| 9 | Multiple callers | **Falsified** — sole code xref `FUN_004ac100` @ `0x004ac12e` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Free+rebuild role | **High** | Wrong port unit |
| Scale 64/32 branch | **High** | Wrong grid density |
| ROUND×scale +1 dims | **High** | Off-by-one grid |
| Stride 0x28 ctor/dtor | **High** | Heap corruption |
| Caller host @ map+0xe898 | **High** | Wrong this |
| Product field English | **Low** | Naming / over-port |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + constants + caller

```
// Scales (image):
DAT_00a11088 = 0x42800000 = 64.0f
DAT_00aaa8a4 = 0x42000000 = 32.0f

// Caller:
host   = *(*(caller+0x340) + 0xe898)
mapCtx = *(caller+0x340)

// Body:
free arr@host+0x28; rebuild count = dimX*dimY elements of 0x28
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF. Reject scaffold VOG plate name.

---

## 4. Surviving contract for AutoCore

```
// Port as free+rebuild (not assert wrapper):
void Host_RebuildElem0x28ArrayFromMap(void* host, void* mapCtx) {
  // free cookie-vec @ host+0x28 (Elem0x28_CompleteDtor)
  // if !*(mapCtx+0xe4f8): debug-stop; return  (dims may stay stale)
  // scale = (mapCtx+0xf5) ? 64.f : 32.f
  // dimX/Y = ROUND(mapInt/scale * mapFloat) + 1
  // alloc count=dimX*dimY elements stride 0x28; default-ctor each
}
// Call with host pointer and map/ctx (not void).
// Do NOT promote Named_VOG_DEBUG_STOP.
// Pair element dtor with W29-F Elem0x28_CompleteDtor.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/formula/scales/caller. Residual product English → **accept-with-gaps**.
