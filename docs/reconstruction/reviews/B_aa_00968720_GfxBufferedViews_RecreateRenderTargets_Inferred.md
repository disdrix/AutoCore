# Review B (skeptical / adversarial): `aa_00968720` GfxBufferedViews_RecreateRenderTargets_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00968720` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W38-AA) |
| **Counterpart** | `reviews/A_aa_00968720_GfxBufferedViews_RecreateRenderTargets_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Per-view virtual method on gfxBufferedView | **Falsified** — global list walk; no `this` from caller |
| 2 | Returns failure HRESULT to parent | **Falsified** — bytes always `XOR EAX,EAX`; log-and-continue on ReCreate fail |
| 3 | Parent plate proves this function can fail | **Weakened** — parent **tests** `<0` and has string, but **body never returns −1** → plate currently dead |
| 4 | Scaffold single-view name is enough | **Over-narrow** — unit is **list-level** recreate for all BufferedViews |
| 5 | Shutdown-phase helper | **Falsified** — call site after Texture Factory reset on **rebuild** path |
| 6 | `0x3000` branch is also ReCreate | **Falsified** — bytes take COM `Release` vcall path instead |
| 7 | Failure aborts the list walk | **Falsified** — after log, reloads head and continues |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Product file + ReCreate string | **High** | wrong subsystem |
| Always return 0 | **High** | wrong parent error handling |
| List + rebuild placement | **High** | wrong lifecycle |
| Flag `0x3000` meaning | **Low–Med** | wrong special-case docs |
| Nested ReCreate field map | **Med** | wrong texture args |
| Runtime | **Open** | matrix |

---

## 3. Cross-check against raw + bytes + callers

```
// GfxDevice_Reset rebuild (success path after pd3dDevice->Reset)
IB Factory reset    → fail plate "IB Factory"
VB Factory reset    → fail plate "VB Factory"
Texture Factory     → fail plate "Texture Factory"
CALL 0x00968720     // this unit; TEST EAX / JGE; dead fail plate "gfxBufferedViews"
Effect Factory      → ...
// later success: FUN_00968680 clears view flags, etc.
```

Release twin `0x009686e0` is the matching **shutdown** walker (same list/gate).

---

## 4. Surviving contract for AutoCore

Port as **list ReCreate after device reset**: for each registered buffered view needing texture reset, either full `effTextureImpl` ReCreate or special-flag COM Release. **Always return success (0)**; surface failures only via `vog_LogMessage`. Do not invent a failing return without new evidence. Do not call during shutdown (use release twin).

---

## 5. Verdict

**accept-with-gaps** — adversarial checks strengthen list/rebuild/ReCreate contract and expose dead parent fail plate; residuals are nested English and flag semantics.
