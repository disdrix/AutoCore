# Review B (skeptical / adversarial): `aa_0073cb70` HostEDI_VecCursor44_GetOrCreate_PalDiffMap14c_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0073cb70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W36-G) |
| **Counterpart** | `reviews/A_aa_0073cb70_HostEDI_VecCursor44_GetOrCreate_PalDiffMap14c_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | ECX-thiscall method | **Falsified** — EDI is host; ECX used as temp for new objects / grow |
| 2 | Returns 0 / void success code | **Falsified** — returns **0x14c pointer** (hit or new); early path returns cached entry |
| 3 | Always allocates | **Falsified** — cursor-fast path returns existing without `operator_new` |
| 4 | Same as W35-E HostPtrTable12 bootstrap | **Falsified** — neighbor constructs 12 fixed slots once; this is **cursor vector** get-or-create with **PalDiffMap.fx** string |
| 5 | Stack argc formals | **Falsified** — plain RET; no arg pops beyond SEH frame `ADD ESP,0x64` |
| 6 | Product name from Multikill blend global | **Careful** — `g_flMultiKillCountBlend` is color fill input only; do not rename whole function Multikill |
| 7 | Dead / unused | **Falsified** — 2 live callers `FUN_0073d020` / `FUN_0073d0a0` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EDI host + vector offsets | **High** | Wrong object layout |
| Get-or-create CF | **High** | Wrong lifecycle |
| PalDiffMap.fx string | **High** | Naming only |
| 0x14c / 0xC4 sizes | **High** | Wrong alloc |
| Material pipeline detail | **Low** | Wrong helper ports |
| Product host English | **Low** | Naming |
| Runtime | **Open** | Matrix |

---

## 3. Cross-check against raw + bytes + xrefs

- Full 506 B hex ends `83c464 c3`.
- Early path: `8B 4F 4C` / `8B 47 50` / `8B 4F 44` cursor compare; store-return without PUSH 0x14C.
- Slow path: `68 4C 01 00 00` (0x14C), `68 C4 00 00 00` (0xC4).
- String push to `0x00a2ddcc` = `"PalDiffMap.fx"` (read_memory confirmed).
- Grow: `8D 4F 48` + `FUN_004367f0`; store `89 2C 81` with EBP=host14c.
- Xrefs: `0x0073d025`, `0x0073d0a5` only.

---

## 4. Surviving contract for AutoCore

```
// Port as EDI-host cursor vector get-or-create (not ECX thiscall, not bootstrap-once):
void *GetOrCreatePalDiffMapHost14c(Host *h /* EDI */) {
  if (h->cursor < h->count()) return h->vec[h->cursor++];
  auto *host = new Host14c; // 0x14c + FUN_00764030
  auto *mat  = new MatC4;   // 0xC4 + FUN_00748960
  LoadFx(mat, "PalDiffMap.fx"); BindParam(mat, "DiffuseMap");
  // optional 16x16 fmt 0x16 surface
  Wire(host, mat); // FUN_007647c0
  h->ensure(h->cursor + 1);
  h->vec[h->cursor++] = host;
  return host;
}
// Host span must cover through +0x50. Expect wrappers to bind DiffuseMap again + vcall +0x18.
// Do not invent Multikill / GfxToolFactory product plates without body evidence.
```

---

## 5. Verdict

Adversarial pass confirms A on EDI ABI, cursor-vector get-or-create, sizes, PalDiffMap string, 2 callers. Residual product English + unowned material helpers → **accept-with-gaps**.
