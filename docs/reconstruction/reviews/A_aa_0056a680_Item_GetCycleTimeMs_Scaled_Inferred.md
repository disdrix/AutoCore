# Review A (reconstruction fidelity): `aa_0056a680` Item_GetCycleTimeMs_Scaled_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0056a680` |
| **VA** | `0x0056a680`–`0x0056a765` |
| **Canonical name** | `Item_GetCycleTimeMs_Scaled_Inferred` |
| **Ghidra name** | `FUN_0056a680` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W25-L) |
| **Counterpart** | `reviews/B_aa_0056a680_Item_GetCycleTimeMs_Scaled_Inferred.md` |
| **System** | item / weapon combat stats |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (body + `g_flOne` + bias); callers (TacArc, DPS UI, tooltip) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Return **cycle time in milliseconds** from `this+0xD0`, optionally scaled by a related-object float (`vtbl+0x214`→`+0x1E8`) when flag is clear and scale ≠ 1.0; floor scaled results at **500** ms. Used as DPS / tac-arc time denominator.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0056a680_FUN_0056a680.md` (+ W25-L append) |
| Annotated | `docs/reconstruction/raw/aa_0056a680_FUN_0056a680.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Item_GetCycleTimeMs_Scaled_Inferred.cpp` |
| Clean scaffold | `docs/reconstruction/reconstructed-exact/FUN_0056a680.cpp` |
| Function record | `docs/reconstruction/functions/aa_0056a680_Item_GetCycleTimeMs_Scaled_Inferred.md` |
| Live | `decompile_function` `0x0056a680`; `read_memory` entry + epilogue; globals; xrefs |

---

## 3. Signature

```c
// thiscall; stack char bSkipScale; ret 4; EAX = int ms
int Item_GetCycleTimeMs_Scaled_Inferred(void* this_item, char bSkipScale);
```

| Item | Evidence | Conf |
|---|---|---|
| thiscall ESI=this | `8B F1` | **High** |
| Stack flag | `80 7C 24 08 00` / `ret 4` | **High** |
| Base `+0xD0` | raw + epilogue `8B 86 D0 00 00 00` | **High** |
| Floor 500 | `81 F9 F4 01 00 00` / `B8 F4 01 00 00` | **High** |
| `g_flOne` / bias | `read_memory` `0x00a0f2a0` / `0x00aaa6d0` | **High** |

---

## 4. Control flow (sealed)

```
if !bSkipScale && related[+0xB0] && blob=vtbl+0x214() && scale[+0x1E8] != 1.0:
  product = scale * (float)baseMs
  if trunc(product ± bias) > 500: return Round(product)
  return 500
return baseMs
```

| Stage | Match | Conf |
|---|---|---|
| Skip-scale → raw | **Yes** | **High** |
| Related null / blob null / scale==1 → raw | **Yes** | **High** |
| Scaled floor 500 | **Yes** | **High** |
| Round via `FUN_0040dab0` | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

| Addr | Role |
|---|---|
| `0x0056a680` | flag test; related load `+0xB0`; vtbl+0x214; `ucomiss` vs `g_flOne` |
| `0x0056a700+` | mulss; ±bias; cmp 500; call `FUN_0040dab0`; `ret 4` arms |

**No `disassemble_bytes` used.**

---

## 6. Call surface

| Caller | Role evidence |
|---|---|
| `CVOGTacArc_UpdateMesh` | divide timing by `result * ms→sec` |
| `FUN_0087d810` / tooltip | **DPS** = dmg / (result * ms→sec) |
| `FUN_005fe6a0` | HB stores result at +8 |
| Setter sibling | `FUN_0056a1b0` writes `+0xD0` |

Xrefs: **21**.

---

## 7. Confidence

| Claim | Level |
|---|---|
| CF / ms base / scale / 500 floor | **High** |
| DPS-denominator use | **High** |
| Product type / scale field English | **Inferred** |
| Runtime / bit-exact | **Open** |

---

## 8. Gaps

1. Product class for `this` / related / blob.
2. Exact designer name for 500 ms floor.
3. Live scale values under class mods.
