# Review B (skeptical / adversarial): `aa_005575c0` WeatherHost_ApplyEnvTime_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005575c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W36-F) |
| **Counterpart** | `reviews/A_aa_005575c0_WeatherHost_ApplyEnvTime_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | ExpandDeps is thiscall on the nfx ring | **Falsified** — bytes load ECX from `*(DAT_00d1f050+0x6c)` AssPreloader*, push ring |
| 2 | Always completes transition in one call | **Falsified** — multiple early returns on key-ring yield / incomplete ready flags |
| 3 | `fVar7` is a true IEEE float weather id only | **Partial** — compared as key; also used as pointer bits (`+0x10` weather object). Type is dual-use; port as opaque entry pointer |
| 4 | cdecl / no stack cleanup | **Falsified** — **`RET 0x4`** |
| 5 | Same as FxCache_ApplyWithNfxEnsure | **Falsified** — weather host TOD path; no entity FX attach |
| 6 | Product method name retail | **Overstated** — `_Inferred` only |
| 7 | `DAT_00b03e64` always forces unload | **Partial** — when set, clears prev/ticks and may call unload; when clear, different early-outs |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX host + slot + RET 4 | **High** | Stack imbalance |
| Nfx fill/activate + yield | **High** | Stuck weather / missing FX |
| ExpandDeps AssPreloader this | **High** | Crash on wrong this |
| 5000 ms window | **High** | Wrong blend length |
| Lookup entry as pointer+0x10 | **High** (use-site) | Wrong weather object |
| Product English | **Inferred** | Naming only |
| Seed blob exact layout | **Medium** | Rare missing-weather path only |
| Runtime | **Open** | Timing races |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  gate +0x178; lookup; optional forgotten-weather seed;
  if cur weather: slot match return;
  fill ring +0x190 mode0 / act +0x1a4 mode1;
  ProcessKeyRingStep × up to 4; ExpandDeps on yield;
  5000ms blend; swap prev/cur; apply

bytes:
  MOV ESI,ECX; RET 4
  ExpandDeps: ECX=[cache+6C]; PUSH ring
  float 00af2ce8 = 5000.0f

caller FUN_005579c0: 2 xrefs only
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF; **bytes win** on ExpandDeps this.

---

## 4. Surviving contract for AutoCore

```
// Weather host apply env-time slot:
//   ECX = weather host; stack uint8_t slot; RET 0x4
//   Resolve weather; on miss seed default env_time_* and re-lookup
//   If current weather TOD already == slot: return
//   Else fill nfx list host+0x190 (mode0) then AssPreload step;
//        activate list host+0x1a4 (mode1) then AssPreload step;
//        yield returns mid-path after ExpandDeps(AssPreloader, ring)
//   Blend transition over 5000 ms when previous TOD matches; commit pointers
// Do NOT treat ExpandDeps ECX as the ring.
// Do NOT model as single-shot non-yielding transition.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/constants and rejects ExpandDeps-this-on-ring / single-shot / product-name claims. Residuals product English + unowned helpers → **accept-with-gaps**.
