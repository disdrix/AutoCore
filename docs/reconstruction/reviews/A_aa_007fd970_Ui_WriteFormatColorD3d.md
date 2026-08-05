# Review A (reconstruction fidelity): `aa_007fd970` Ui_WriteFormatColorD3d

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fd970` |
| **VA** | `0x007fd970`–`0x007fda16` |
| **Canonical name** | `Ui_WriteFormatColorD3d` |
| **Ghidra name** | `FUN_007fd970` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W22-F) |
| **Counterpart** | `reviews/B_aa_007fd970_Ui_WriteFormatColorD3d.md` |
| **System** | ui / gfx |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (JT + index table); callers 00871150 / 00870e80 / 00814d80 |
| **Verdict** | **accept** |

---

## 1. Purpose

Leaf helper: map format color index (**CL**) to a 4-byte little-endian D3DCOLOR written through **EAX**. No callees; pure table dispatch.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007fd970_FUN_007fd970.md` (+ 2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_007fd970_FUN_007fd970.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Ui_WriteFormatColorD3d.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_007fd970.cpp` |
| Function record | `docs/reconstruction/functions/aa_007fd970_FUN_007fd970.md` |
| Parent context | `UiHost_RefreshTrackedNodeWidgets` `0x00871150` (CL from node+0x1c−0x0f) |
| Live | decompile ≡ raw; body 167 B; JT `@0x007fda18`; idx `@0x007fda3c` |

---

## 3. Signature (sealed)

```c
// CL = formatIndex; EAX = out[4]; return EAX
uint8_t* Ui_WriteFormatColorD3d(uint8_t formatIndex, uint8_t* outColor);
```

| Formal | Source | Conf |
|---|---|---|
| formatIndex | **CL** (`param_1`) | **High** |
| outColor | **EAX** (`in_EAX` phantom) | **High** |
| return | EAX preserved (out ptr) | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if formatIndex > 0x66: default white
idx = IndexTable[formatIndex]
jmp JumpTable[idx]
case 0..4 / 100 / 0x65 / 0x66 / default: write 4 bytes; ret
```

| Stage | Match | Conf |
|---|---|---|
| MOVSX CL / CMP 0x66 / JA default | **Yes** | **High** |
| Index + jump tables | **Yes** | **High** |
| All case byte constants | **Yes** | **High** |
| Leaf / no callees | **Yes** | **High** |
| D3DCOLOR LE via pure R/G/B | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Prologue matches sealed ABI. Jump table dwords:
`0x007fd98a, 0x007fd999, 0x007fd9a9, 0x007fd9b9, 0x007fd9c9, 0x007fd9d9, 0x007fd9e9, 0x007fd9f9, 0x007fda09`.

Index table: `00 01 02 03 04` then `08`×(0x64−5) then `05 06 07` for 0x64/65/66.

---

## 6. Gaps

- Product English for palette indices 0..4.
- Full semantic of `node+0x1c` pre-bias at map-marker path.
- Live UI swatch differential.

## Verdict rationale

CF, ABI, tables, and every sealed color constant match bytes High. Residual is product naming only → **accept**.
