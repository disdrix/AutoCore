# Review B (skeptical / adversarial): `FUN_008ab340` @ `0x008ab340`

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ab340` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Counterpart** | `reviews/A_aa_008ab340_MissionSelect_ClearRowWidgetVectors_Inferred.md` |
| **Verdict** | **accept-with-gaps** on ESI ABI + dual-vector destroy/clear + call sites; **needs-more-evidence** on product virtual English and bank A/B roles |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | `unaff_ESI` is decompiler junk | Callers `MOV ESI,ECX` before use; all body loads `[ESI+disp]` | **Falsified** — ESI is deliberate ABI |
| 2 | This **builds** select-mission list rows | No `operator_new`, no XML load, no insert into vectors; only destroy + end=begin | **Falsified** — clear/destroy only |
| 3 | Fixed 8-slot bank like `008aa560` | Counts from `(end-begin)>>2`; dynamic vectors | **Falsified** as fixed-8 |
| 4 | ECX thiscall (standard) | No `MOV ECX,ESI` at entry; host loaded from ESI; dtor/parent pass this in ESI | **Falsified ECX-this** — ESI register this |
| 5 | Frees vector capacity buffers | Buffer `operator_delete` is in dtor `008ac340` after this returns | **Falsified** — used-range clear only |
| 6 | Sole caller is Select-a-Mission | xrefs: 2 in `008ab550` + 1 in dtor `008ac340` | **Falsified sole-caller** — 3 sites / 2 functions |
| 7 | Scaffold `Named_CalleeOf_*` is product | Auto plate from parent string/context | **Demote** to retired alias |
| 8 | memmove size is non-zero shrink | Disasm: `sub eax,ecx` with eax=ecx → size 0; then end=begin | **Survives** as end=begin clear |
| 9 | vtbl+0x3d8 is AppendText | Ordinal 0x3d8 ≠ paint 0x250; returns AL tested as bool | **Falsified AppendText** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ESI host this | **High** | Wrong object wiped |
| Dual vector offsets | **High** | Wrong chrome banks |
| Destroy ordinals | **High** role | UI leak / double-free if mis-ported |
| end=begin clear | **High** | Stale iterators if skipped |
| Call-site set | **High** | Miss dtor path |
| Product names | **Open** | Registry noise |
| A vs B bank meaning | **Tentative** | Wrong UI page if swapped on port |

---

## 3. Cross-check spine

```
// ESI = host
clear_vec(host+0x72c, host+0x730)
clear_vec(host+0x73c, host+0x740)

clear_vec(begin, end):
  n = (end-begin)/4
  for i in 0..n-1:
    w = begin[i]
    if !w: continue
    if w->vtbl[0x3d8](): w->vtbl[0x440]()
    if *(w+0x2b0): host->vtbl[0xB0](w)
    if begin[i]: begin[i]->vtbl[0](1)
    begin[i] = 0
  if begin && n && begin!=end: end = begin
```

### What this unit is **not**

| Non-claim | Why |
|---|---|
| Response button clear (`FUN_008aa560`) | fixed 8; banks +0x518/+0x708; EBX ABI |
| Select-a-Mission panel fill (`FUN_008ab550`) | parent residual; title/chrome visibility |
| Markup paint (`FUN_008aab00`) | no strings/tags |
| Packet send | no sector send |

---

## 4. Residual attacks left open

1. Exact product meaning of widget+0x2b0 gate (parent link? refcount?).
2. Whether +0x3d8 is "is attached" vs "needs detach" (both bool gates).
3. Why two vectors (primary list vs alternate page?) — needs consumers of +0x72c/+0x73c outside this VA.
4. Image variants with different layout (this binary sealed).

---

## 5. Verdict

**accept-with-gaps** — adversarial pass cannot break ESI ABI, dual-vector destroy/clear, ordinal map, or three call sites; product English and A/B bank roles remain open. No runtime Confirmed.
