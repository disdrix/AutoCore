# Review A (reconstruction fidelity): `aa_00968680` GfxBufferedViewList_ClearField184_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00968680` |
| **VA** | `0x00968680` |
| **Body** | `0x00968680`–`0x009686a7` inclusive (**40 B** / `0x28`); pad `CC` then sibling `FUN_009686e0` |
| **Canonical name** | `GfxBufferedViewList_ClearField184_Inferred` (**Inferred**) |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00968680_GfxBufferedViewList_ClearField184_Inferred.md` |
| **System** | graphics / gfxBufferedView global list |
| **Live tools** | Ghidra `batch_decompile`, `analyze_function_complete`, `read_memory`, xrefs, parent decompile, W37-I ctor (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** — list walk + zero `+0x184` sealed; field product English open |
| **Dual status** | **Present (W38-Z)** |

---

## 1. Purpose

On successful Device Reset, clear field **`+0x184`** on every live payload registered in the global **gfxBufferedView** circular list:

```
sentinel = DAT_00d1ee30;
for (n = sentinel->next; n != sentinel; n = n->next)
  if (n->payload) *(uint32_t*)(payload + 0x184) = 0;
```

**ABI:** no formals; plain **RET**. Leaf (no callees).

Ctor `FUN_00968a50` (W37-I) always inserts `this` into this list and sets **`+0x184 = 1`**.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | Ghidra `batch_decompile` `0x00968680` — **≡ raw** |
| Complete analysis | 1 xref; caller `FUN_0075eff0`; leaf |
| Machine | `read_memory` body **40 B** then `CC` |
| Parent | `FUN_0075eff0` success arm @ `0x0075f362` |
| List twin | `FUN_00968a50` GfxBufferedView ctor (W37-I) |
| Sibling | `FUN_009686e0` pre-Reset walk (not OWN) |
| Scaffold | `raw/aa_00968680_*`, `reconstructed-exact/FUN_00968680.cpp` |

**Not performed:** Launcher, runtime golden, bit-exact image diff, parent ledger edits.

---

## 3. Machine seal (`read_memory`)

| Claim | Evidence | Conf |
|---|---|---|
| Load sentinel `DAT_00d1ee30` | `8b 0d 30 ee d1 00` | **Confirmed** |
| Start at `*sentinel`; end when node==sentinel | `8b 01; 8b d1; 3b c2; 74 19` / loop `75 e9` | **Confirmed** |
| Payload `@+8` | `8b 48 08` | **Confirmed** |
| Null-skip | `85 c9; 74 0a` | **Confirmed** |
| Store 0 at `payload+0x184` | `c7 81 84 01 00 00 00 00 00 00` | **Confirmed** |
| Plain RET | `c3` | **Confirmed** |
| Body 40 B | last `c3` @ `0x009686a7` | **Confirmed** |

Full hex (40 B):

```
8b0d30eed1008b018bd13bc274198bff8b480885c9740ac78184010000000000008b003bc275e9c3
```

---

## 4. Gaps

- Product English for `gfxBufferedView+0x184`.
- Whether list can hold non-buffered-view payloads.
- Runtime / bit-exact / differential.

---

## 5. Verdict

**accept-with-gaps** — CF/ABI/list zero sealed; field English residual.
