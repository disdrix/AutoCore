# Review A (reconstruction fidelity): `aa_008612b0` UI_InventoryWindow_OnItemClickDispatch_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008612b0` |
| **VA** | `0x008612b0` |
| **Body** | `0x008612b0`–`0x00861676` exclusive (**966 B** / `0x3C6`); `RET 0x8` @ `0x00861673` |
| **Canonical name** | `UI_InventoryWindow_OnItemClickDispatch_Inferred` |
| **Ghidra name** | `FUN_008612b0` |
| **Review date** | `2026-08-05` (gap-close OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_008612b0_UI_InventoryWindow_OnItemClickDispatch_Inferred.md` |
| **System** | inventory-transfer |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` (entry/end/RTTI/string) + `get_xrefs_to` / `get_function_xrefs` + `get_function_callees` + `get_function_by_address` + `analyze_control_flow` + dualed child records (`00861200`, `00513770`, `00807460`, `00930d70`, `00941f50`, `0093bac0`). **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Inventory-window **vtable method** for selected-item click/use/equip/store dispatch: RTTI-cast selected `CNDUIWindow` → `CWndInventoryItem`, branch modes **1/3/4**, store sell **`0x2027`**, UseObject, skill-target types **8/`0x32`**, and equip leaf **`UI_InventoryWindow_TryEquipOrLockedToast_Inferred`**. Not the equip leaf itself (that is `0x00861200`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_008612b0_FUN_008612b0.md` |
| Annotated | `docs/reconstruction/raw/aa_008612b0_FUN_008612b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_InventoryWindow_OnItemClickDispatch_Inferred.cpp` |
| Twin include | `docs/reconstruction/reconstructed-exact/FUN_008612b0.cpp` |
| Named record | `docs/reconstruction/functions/aa_008612b0_UI_InventoryWindow_OnItemClickDispatch_Inferred.md` |
| FUN record | `docs/reconstruction/functions/aa_008612b0_FUN_008612b0.md` |
| Dualed equip leaf | `UI_InventoryWindow_TryEquipOrLockedToast_Inferred` @ `0x00861200` |
| Dualed store want | `Item_IsWantedByStore_Inferred` @ `0x00513770` |
| Dualed sector send | `Client_SendSectorPacket` @ `0x00807460` |
| Dualed UseObject | `Client_SendUseObject_IfInteractable` @ `0x00930d70` |
| Live body | `disassemble_function` full + `read_memory` entry/exit/RTTI/string |

---

## 3. Calling convention (assembly-sealed)

| Slot | Role | Evidence |
|---|---|---|
| ECX | inventory window this\* | `MOV EDI,ECX` @ entry; close uses `ECX=EDI` |
| stack formals | 2 opaque dwords | every exit **`RET 0x8`** (`C2 08 00`) |
| cleanup | `ADD ESP,0xC8` after pops | frame `SUB ESP,0xC8` |
| return | **AL** 1/0 | `MOV AL,1` / `XOR AL,AL` |
| install | DATA `@0x00a64b00` | dword `0x008612b0`; no code callers |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 966 B + pad `CC` after `RET 0x8` | **Confirmed** | `get_function_by_address` + control-flow size + end `read_memory` |
| ECX=window; RET 0x8; AL return | **Confirmed** | full disasm exits |
| Vtable-only install `@0x00a64b00` | **Confirmed** | `get_xrefs_to` / `get_function_xrefs` DATA only |
| RTTI CNDUIWindow → CWndInventoryItem | **Confirmed** | type strings `@0x00afe1ac` / `@0x00aff3ac` |
| Mode cascade 1/3/4 | **Confirmed** | `SUB EAX,1/2/1` after load `@[+0x56c]+4` |
| Store string + chrome `0x4e24` | **Confirmed** | `read_memory` `0x00a52924`; `MOV EAX,0x4e24` |
| Opcode `0x2027` size `0x40` sell packet | **Confirmed** | `MOV [esp+0x14],0x2027`; `PUSH 0x40`; `Client_SendSectorPacket` |
| Equip leaf CALL `00861200` | **Confirmed** | `MOV ECX,EBX; MOV EAX,EDI; CALL 00861200` @ `008615f0` |
| Product window class English | **Open** | selected child sealed; host class residual |
| Mode / formals / close-vtbl English | **Open** | `_Inferred` |
| Runtime / bit-exact / differential | **Open** | terminal false |

---

## 5. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| Early busy / no-selected → `FUN_0085f220` | **Yes** |
| RTTI cast → mode 1/3/4 branch | **Yes** |
| mode 4 → `FUN_00861280` + close | **Yes** |
| Store: IsWantedByStore → toast or `0x2027` | **Yes** |
| UseObject / flag / use-coid / type 8/`0x32` / equip leaf | **Yes** |
| Fallthrough close + return 1 | **Yes** |

Decompile warning *“Type propagation algorithm not settling”* does **not** break CF seal; ABI corrections (RET 0x8, ECX this, AL return) come from disasm.

---

## 6. Naming gate

- Role = inventory-window **selected-item click/use/equip/store dispatch** (vtable method).
- RTTI + store string + dualed equip leaf + opcode `0x2027` support name family.
- Partition hint `OnEquipCommand` under-states store/use/skill branches → **`OnItemClickDispatch`**.
- Product demangle incomplete → **`_Inferred`**.

---

## 7. Gaps / open

- Exact product class of inventory **sheet/window** host (child is `CWndInventoryItem`).
- Mode dword English (1/3/4 observed only).
- Two stack formals’ product types (unused in body).
- `vtbl[+0x33c]` / inv-item `vtbl[+0x3ac]` method English.
- Residual callees `FUN_0085f220`, `FUN_00861280`, `FUN_00524520`, `FUN_0093a330` product names.
- Runtime click / store-sell / equip verification.

**Verdict:** **accept-with-gaps** — CF/ABI/RTTI/string/opcode/child duals sealed; product English + runtime open.
