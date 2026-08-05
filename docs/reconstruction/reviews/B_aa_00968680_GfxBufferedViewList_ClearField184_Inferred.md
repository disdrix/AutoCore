# Review B (skeptical / adversarial): `aa_00968680` GfxBufferedViewList_ClearField184_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00968680` |
| **VA** | `0x00968680` |
| **Canonical name** | `GfxBufferedViewList_ClearField184_Inferred` (**Inferred**) |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00968680_GfxBufferedViewList_ClearField184_Inferred.md` |
| **System** | graphics / gfxBufferedView global list |
| **Live tools** | Independent decompile + `read_memory` + sibling `009686e0` + W37-I ctor cross-check |
| **Verdict** | **accept-with-gaps** — accept CF; reject destroy/unlink / thiscall / object-flag-domain claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Unlinks / deletes list nodes | **Falsified** — walk-only; only memory write is store 0 at `payload+0x184` |
| 2 | Same body as sibling `FUN_009686e0` | **Falsified** — sibling gates on `payload+0x44→+0x30` and **calls** `FUN_0096c8e0` |
| 3 | Field `+0x184` is world-object flag mask (e.g. `Object+0x184`) | **Falsified as domain** — list is gfxBufferedView registry (W37-I); object-flag units are unrelated domain |
| 4 | `__thiscall` / ECX list head | **Falsified** — loads global sentinel; no this |
| 5 | Scaffold `Named_CalleeOf_…gfxDevice…` is product API name | **Rejected** — parent-seed noise |
| 6 | Multi-caller utility | **Falsified** — single CODE xref (Device Reset success) |
| 7 | Clears `+0x180` as well | **Falsified** — only imm store to **`+0x184`** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Circular walk + zero `+0x184` | **High** | Missed device-reset state |
| List = gfxBufferedView | **High** | Wrong object class |
| Field English | **None** | Wrong port semantics |
| Payload always non-null in practice | **Med** | Defensive null check present |

---

## 3. Decompiler pitfalls (must survive port)

1. Empty-looking leaf — do not invent destroy/unlink from sibling naming.  
2. Do **not** merge with `FUN_009686e0` (different gate + callee).  
3. Do **not** map `+0x184` to gameplay object flags without list-domain proof.

---

## 4. What is safe to claim

| Safe | Unsafe |
|---|---|
| Post-Reset success walk clears `view+0x184` | Product name of field |
| Sentinel `DAT_00d1ee30` / node payload@+8 | Cross-domain object flag meaning |
| Leaf / plain RET / single caller | Full buffered-view field map |

---

## 5. CF challenge of Review A

- Body CF + 40 B + zero seal: **agree Confirmed**  
- List domain via W37-I: **agree High**  
- Field English residual: **agree Open**  

**Verdict:** **accept-with-gaps**
