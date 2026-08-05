# Review A (reconstruction fidelity): `aa_0075e710` D3DPresentParams_Log_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075e710` |
| **VA** | `0x0075e710`–`0x0075e7d2` exclusive (**194 B** / `0xC2`) |
| **Canonical name** | `D3DPresentParams_Log_Inferred` |
| **Ghidra name** | `FUN_0075e710` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W38-X) |
| **Counterpart** | `reviews/B_aa_0075e710_D3DPresentParams_Log_Inferred.md` |
| **System** | client / gfxDevice D3D9 present params |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` (full body) + `get_assembly_context` callers + plate strings + W37-N / W35-R present layout. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

Log a **14-dword** (`0x38`) **D3DPRESENT_PARAMETERS**-shaped block pointed by **ESI** via ten `FUN_0076c130` format lines (BackBuffer / MultiSample / SwapEffect FLIP|COPY|DISCARD / hDeviceWindow / Fullscreen / depth-stencil / Flags / refresh / PresentationInterval).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W38-X append) | `docs/reconstruction/raw/aa_0075e710_FUN_0075e710.md` |
| Annotated | `docs/reconstruction/raw/aa_0075e710_FUN_0075e710.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/D3DPresentParams_Log_Inferred.cpp` |
| Trio parent | W37-N `aa_0075eff0` GfxDevice_Reset (`device+0x2B8`) |
| Live | decompile + 194 B hex + caller `LEA ESI` + `MOV ECX,0xE` copies |

---

## 3. Signature (sealed)

```c
// ESI = D3DPRESENT_PARAMETERS* (14 dwords); bare RET; void
void D3DPresentParams_Log_Inferred(void /* ESI params */);
```

| Formal | Source | Conf |
|---|---|---|
| ESI params | `LEA ESI,[EBP+0x2B8]` / stack local after `MOVSD` ×0xE | **High** |
| cleanup | `ADD ESP,0x40; C3` (arg cleanup for last printf batch) | **High** |
| return | void | **High** |

---

## 4. Field map (sealed ≡ D3DPRESENT_PARAMETERS layout)

| Off (dwords) | Log label | D3D9 field (inferred) | Conf |
|---|---|---|---|
| 0–3 | BackBuffer WxH, format, # | Width/Height/Format/Count | **High** |
| 4–5 | MultiSampleType / Quality | MultiSampleType / Quality | **High** |
| 6 | SwapEffect → FLIP(2)/COPY(3)/else DISCARD | SwapEffect enum | **High** |
| 7 | hDeviceWindow | hDeviceWindow | **High** |
| 8 | Fullscreen = (field==0) | **Windowed inverted** | **High** |
| 9–10 | EnableAutoDepthStencil / Format | same | **High** |
| 11–13 | Flags / RefreshHz / PresentationInterval | same | **High** |

---

## 5. Machine bytes

- Body: `0x0075e710`–`0x0075e7d1` inclusive (**194 B**); pad `CC` to sibling `FUN_0075e7e0`.
- Full hex: raw W38-X append.
- Stack: mid-body `ADD ESP,0x20` after first two logs; epilog `ADD ESP,0x40` then `C3`.

---

## 6. Gaps (fidelity)

- Confirm `FUN_0076c130` product name (printf-style logger; not `vog_LogMessage`).
- Product source file/line for these plates (likely gfxDevice).
- Runtime / bit-exact / differential (log text only).
