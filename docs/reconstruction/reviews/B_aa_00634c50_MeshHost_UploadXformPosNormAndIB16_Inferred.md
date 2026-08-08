# Review B (skeptical / adversarial): `aa_00634c50` MeshHost_UploadXformPosNormAndIB16_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00634c50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY WQ9J-D) |
| **Counterpart** | `reviews/A_aa_00634c50_MeshHost_UploadXformPosNormAndIB16_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Full mesh rebuild / asset import | **Falsified** — runtime VB/IB lock-write-unlock of existing host buffers only |
| 2 | Software raster / draw call | **Falsified** — no Present/Draw; unlock strings are gfxDevice VB/IB |
| 3 | Thiscall ECX=object self of CVOGObject | **Falsified** — ECX is host entry from `this+0x1c4[i]`; owner at host+0x0C |
| 4 | Creates FieldBlock / is FieldBlock itself | **Falsified** — only **calls** `FUN_00416240` once into stack temp |
| 5 | Copies full xform via memcpy | **Falsified** — uses selective FieldBlock wrapper (WQ9I-H) |
| 6 | Index format stays u32 | **Falsified** — dest stride 2, src stride 4 (u16 pack) |
| 7 | Always runs every Tick | **Falsified** — gated by host fields + caller `+0x90d` bit1 |
| 8 | cdecl multi-arg | **Falsified** — fastcall ECX host, RET |
| 9 | Product name proven | **Open** — `_Inferred`; VB/IB strings are callees |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX host + gate offsets | **High** | Wrong upload source |
| VB then IB order | **High** | Wrong resource timing |
| Pos usage0 / nrm usage3 | **High** | Wrong FVF channels |
| FieldBlock temp at 00634ce5 | **High** | Wrong xform source |
| Unlock device pointer exact type | **Med** | Port crash if wrong this |
| Product class English | **Open** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check

- Live decompile 2026-08-05 ≡ scaffold 2026-07-23.  
- `FUN_007464e0` / `FUN_00743ba0` log paths prove VB/IB unlock domain.  
- `FUN_00416240` call site matches WQ9I-H sealed ABI (ECX=temp, PUSH src).  
- Caller `CVOGObject_Tick` optional multi-host loop documented in `aa_00595230` artifacts.

---

## 4. Surviving contract for AutoCore

```
// Port as mesh-host GPU buffer refresh, not asset loader:
// 1) require host pos/nrm/idx pointers + counts
// 2) dirty owner flags |= 1 at +0xBC
// 3) lock VB → write xformed pos+nrm by FVF offsets/stride → unlock
// 4) lock IB (0x800) → u32→u16 pack → unlock
// Pair with FieldBlock_CopyFrom_ClearFlags0xBC + selective assign for xform temp.
// Do not invent draw, full mesh rebuild, or CVOGObject-as-ECX.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/VB-IB shape/FieldBlock use. Rejects draw/import/thiscall-as-object overclaims. Residual product English + device-wrapper typing → **accept-with-gaps**.
