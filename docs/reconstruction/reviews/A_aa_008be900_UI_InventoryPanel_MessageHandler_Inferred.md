# Review A (reconstruction fidelity): `aa_008be900` UI_InventoryPanel_MessageHandler_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008be900` |
| **VA** | `0x008be900`–`0x008beb13` |
| **Canonical name** | `UI_InventoryPanel_MessageHandler_Inferred` |
| **Ghidra name** | `FUN_008be900` |
| **Review date** | `2026-07-29` (W20-F OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_008be900_UI_InventoryPanel_MessageHandler_Inferred.md` |
| **System** | `inventory-transfer` / UI message dispatch |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` entry/epilogue + float bias. No `disassemble_bytes`. No Launcher.

---

## 1. Purpose

**UI message handler** for an inventory / item-use panel. Dispatches `(msg, controlId)` for slot ids `0x9c43..0x9c46`, close `0x9c40`, specials `0x9c41`/`0x9c42`, else **`UI_DefaultMessageHandler`**.

On slot **msg `0xe`**: `Client_UseInventoryItem_Inferred(1)`; if that returns 0 → `Client_SendUseObject_IfInteractable`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | `decompile_function` `0x008be900` — **identical** to raw |
| Function meta | body `008be900`–`008beb13` (531 B) |
| Entry bytes | `read_memory` @ `0x008be900` — `sub esp,10`; load controlId→ESI, msg→EDI; `mov ebp,ecx` |
| Epilogue | `read_memory` @ `0x008beb00` — call default then **`C2 08 00`** (`ret 8`) |
| Float bias | `read_memory` `0x00aaa5dc` = `0x4F800000` = **4294967296.0f** |
| DATA xref | `0x00a457a4` → `0x008be900` |
| Peer duals | `UI_DefaultMessageHandler`, `Client_UseInventoryItem_Inferred`, `Client_SendUseObject_IfInteractable`, `UI_Case_CloseBtn_9c40` |
| Raw / clean | `raw/aa_008be900_*`, `UI_InventoryPanel_MessageHandler_Inferred.cpp` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body `0x008be900`–`0x008beb13` (531 B) | **Confirmed** | Ghidra + `ret 8` |
| ABI: **ECX=this**, stack **(msg, controlId)**, **`ret 8`** | **Confirmed** | entry loads + epilogue `C2 08 00` |
| Slot band exclusive `0x9c42 < id < 0x9c47` ⇒ `0x9c43..0x9c46` | **Confirmed** | decomp + entry `cmp esi, 0x9c43` |
| Slot index `id - 0x9c43`; widgets `this+0x55c[slot]` | **Confirmed** | |
| msg `5` → dual vtbl rects → `FUN_007fd420` | **High** | |
| msg `6` → flags `DAT_00d1d8f4=1`, `f5=0`; hide `DAT_00d1d8dc` | **Confirmed** | |
| msg `0xe` → `FUN_00941d50(1)` then optional IfInteractable | **Confirmed** | sealed duals peer |
| `0x9c40` + msg `8` → `FUN_007fca10` then default | **Confirmed** | decomp fallthrough |
| `0x9c41` + msg `8` → return 1 | **Confirmed** | |
| `0x9c42` + msg `0x1a` → scroll index + `FUN_008bda60` | **High** | |
| Default → `UI_DefaultMessageHandler` / `FUN_0087b500` | **Confirmed** | peer dual |
| u32→float bias `2^32` at `0x00aaa5dc` | **Confirmed** | `read_memory` |
| Product panel class English | **Inferred** | `_Inferred` |
| Product names of msg codes | **Tentative** | |

---

## 4. Control flow: raw ≡ live ≡ clean

| Stage | Match |
|---|---|
| Slot band msg 5 / 6 / 0xe | **Yes** |
| Close 0x9c40 leave | **Yes** (then default) |
| 0x9c41 swallow | **Yes** |
| 0x9c42 scroll sync | **Yes** |
| Default handler | **Yes** |
| No invented opcodes in this unit | **Yes** (use path is callee) |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| Message-handler ABI (`ret 8`, msg+id) | **Yes** |
| Inventory use cascade on 0xe | **Yes** |
| Slot id family + scroll host | **Yes** |
| Product class name | **No** |

**Decision:** promote **`UI_InventoryPanel_MessageHandler_Inferred`** (role High; class English open → `_Inferred`).

---

## 6. Gaps

1. Product class of `this` panel.
2. Product English for msg `5`/`6`/`0xe`/`8`/`0x1a`.
3. How item register (EDI) is set before msg `0xe` reaches `FUN_00941d50`.
4. Owner of DATA slot `0x00a457a4`.
5. Runtime / bit-exact — open.

**Verdict:** **accept-with-gaps**
