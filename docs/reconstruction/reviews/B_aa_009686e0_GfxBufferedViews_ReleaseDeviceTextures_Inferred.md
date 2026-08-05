# Review B (skeptical / adversarial): `aa_009686e0` GfxBufferedViews_ReleaseDeviceTextures_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_009686e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W38-AA) |
| **Counterpart** | `reviews/A_aa_009686e0_GfxBufferedViews_ReleaseDeviceTextures_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Single-view method / thiscall `ECX=view` | **Falsified** — no `MOV ECX` of view; global list walk; no formals |
| 2 | Destroys / unlinks gfxBufferedView objects | **Falsified** — only `FUN_0096c8e0` on texture; nodes remain |
| 3 | Rebuild / ReCreate role | **Falsified** — sole call site is **shutdown** chain before D3D Reset; recreate is twin `0x00968720` |
| 4 | Scaffold `Named_CalleeOf_Named_gfxDevice_*` is product role | **Over-narrow** — reject; role is **BufferedViews list texture release** |
| 5 | Multiple callers | **Falsified** — single xref `0075f0ec` |
| 6 | `FUN_0096c8e0()` has zero args / static | **Falsified** — bytes `MOV ECX,EAX; CALL` thiscall |
| 7 | Gate `+0x30` means “destroyed” | **Unproven product English** — sealed only as **zero-check before release**; keep Inferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| List walk + body 53 B | **High** | wrong unit bounds |
| Thiscall release callee | **High** | ABI crash |
| Shutdown placement in Reset | **High** | wrong lifecycle phase |
| Field English | **Low–Med** | wrong texture map docs |
| Runtime | **Open** | matrix |

---

## 3. Cross-check against raw + bytes + callers

```
// GfxDevice_Reset shutdown (W37-N)
log "Beginning shutdown for Device Reset()"
FUN_00985f40 / FUN_00985580 / FUN_009864e0
CALL 0x009686e0          // this unit
FUN_0073d8d0
// then other texture-list releases, device Release, IDirect3DDevice9::Reset, rebuild...
```

Pairs with recreate twin `FUN_00968720` on rebuild path and list registration in `GfxBufferedView_Ctor_Inferred`.

---

## 4. Surviving contract for AutoCore

Port as **void list walker**: for each registered buffered view, if texture gate `+0x30==0`, call texture device-release (`FUN_0096c8e0`). Invoke only from device-reset **shutdown**, not rebuild. Do **not** treat as view dtor or ReCreate.

---

## 5. Verdict

**accept-with-gaps** — adversarial checks strengthen list/shutdown/release contract; residuals are field English and nested duals.
