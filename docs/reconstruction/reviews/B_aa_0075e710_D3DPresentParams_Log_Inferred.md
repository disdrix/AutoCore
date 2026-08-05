# Review B (skeptical / adversarial): `aa_0075e710` D3DPresentParams_Log_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075e710` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W38-X) |
| **Counterpart** | `reviews/A_aa_0075e710_D3DPresentParams_Log_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Name is `Gfx_SwapEffect` only | **Falsified** — logs all 14 present fields; SwapEffect is one branch |
| 2 | Fullscreen field is raw Windowed | **Falsified** — logs `(esi[8]==0)` i.e. **inverted** Windowed |
| 3 | FLIP/COPY/DISCARD map is invente | **Falsified** — exact `==2 FLIP`, `==3 COPY`, else `DISCARD` matches D3DSWAPEFFECT_* |
| 4 | cdecl stack params for present block | **Falsified** — callers set **ESI** only; bare RET |
| 5 | Only one call site | **Falsified** — 3 xrefs: GfxDevice_Reset ×2 + device-create path `FUN_00735c90` |
| 6 | Structure size unknown | **Falsified** — callers copy **0xE** dwords; body reads through `esi[0xd]` |
| 7 | Scaffold Named_CalleeOf must stay | **Falsified** — plate strings seal present-params logger |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ESI 14-dword present log | **High** | wrong layout |
| D3DPRESENT_PARAMETERS overlay | **High** | field misnames |
| SwapEffect enum map | **High** | wrong strings |
| Windowed invert for Fullscreen log | **High** | inverted fullscreen flag |
| Product logger name (`FUN_0076c130`) | **Med** | wrong log sink |
| Runtime | **Open** | matrix |

---

## 3. Cross-check against raw + bytes + callers

```
// GfxDevice_Reset
LEA ESI, [device+0x2B8]   // early log
CALL D3DPresentParams_Log
// ... later ...
// copy 0xE dwords then ESI=local/EAX
CALL D3DPresentParams_Log  // post-rebuild log

// FUN_00735c90 create path
LEA ESI, [stack present]
CALL D3DPresentParams_Log
// then MOVSD present into device+0x2B8
```

---

## 4. Surviving contract for AutoCore

Port as **debug log of D3DPRESENT_PARAMETERS** via ESI. Map SwapEffect 2/3/other → FLIP/COPY/DISCARD. Log Fullscreen as `!Windowed`. Do **not** treat as mutator. Do **not** use incomplete alias `Gfx_SwapEffect`.
