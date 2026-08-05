# Review A (reconstruction fidelity): `aa_00944d50` Client_ClearObjectReferences

| Field | Value |
|---|---|
| **Stable ID** | `aa_00944d50` |
| **VA** | `0x00944d50` |
| **Canonical name** | `Client_ClearObjectReferences` |
| **Prior names** | `FUN_00944d50` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (fidelity) |
| **Counterpart** | `reviews/B_aa_00944d50_Client_ClearObjectReferences.md` |
| **System** | client / object lifecycle / UI unbind |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Fan-out **client/UI reference scrub** for a departing object: clear sticky slots, COID tree, select chrome, inventory/mission bindings, selection targets; finish with COID notify `FUN_00996ff0`. Used by special-event ship teardown (`ClientSpecialEvent_Respawn_dtor`) and sibling helpers — **not** the full `VOGClient_CompletelyDestroyObject` path.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00944d50_FUN_00944d50.md` |
| Annotated | `docs/reconstruction/raw/aa_00944d50_FUN_00944d50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_ClearObjectReferences.cpp` |
| Alias clean | `docs/reconstruction/reconstructed-exact/FUN_00944d50.cpp` (Ghidra-shaped) |
| Function record | `docs/reconstruction/functions/aa_00944d50_Client_ClearObjectReferences.md` |
| Live decompile | `decompile_function` `0x00944d50` |
| Live bytes | entry `51 53 55 8B 6C 24 10…`; epilogue `C2 04 00` |
| Callers/callees | `get_xrefs_to` / `get_function_callees` |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| `__thiscall` | entry uses ECX as client (`mov ebx,ecx`) |
| Stack object* | `mov ebp,[esp+10h]` after 3 pushes |
| `RET 4` | epilogue `C2 04 00` |
| Null early-out | first branch on `param_2` |

### 3.2 Stage order — **SEALED** (clean ≡ raw major stages)

Sticky clear → related notify → COID tree erase → UI host → selection/chrome → misc panels → inventory/equip → mission refresh → inventory sheets → cargo panel → always unbind pair → class 0x0E → selection list `Object_SetSelectedTarget` → secondary → global dialog → list/panel/local-player → `FUN_00996ff0(COID)`.

### 3.3 Key offsets — **SEALED** (touched by this unit)

- Client: `+0x3bf8`, `+0xd24/+0xd28`, `+0xe04`, `+0xe98`, `+0xf0c`, `+0xf40`, `+0x105c`, `+0x1060`, `+0x1068`, `+0x1088`, `+0x1098`, `+0x10a0`, `+0x10a4`, `+0x10b4`, `+0x10cc`, `+0x113c`, `+0x3048`, `+0x30a0`
- Object: COID `+0x160/+0x164`, clonebase `+0xa8` → class `+0x38`, many vfuncs

### 3.4 Named sibling callees — **SEALED as callees**

`Object_SetSelectedTarget`, `InventoryGrid_ContainsItem`, `Vehicle_HasEquippedTFID`, `UiSelectWidget_ApplySelectChrome`, `Client_UI_InventorySheet_RemoveByItem`, `Client_RefreshOpenMissionUiWindows`.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| ABI / null / RET 4 | **High** | bytes |
| Stage order | **High** | live ≡ raw |
| Not CompletelyDestroyObject | **High** | different VA; different callers |
| COID tree erase present | **High** | keys obj[0x58/0x59] |
| Product method name | **Probable** | inferred |
| Every panel product type | **Tentative** | offsets only |
| Tree-walk iterator SSA | **Probable** | raw authoritative for bit-exact |
| Runtime | **Open** | deferred |

---

## 5. Control flow checklist

| Stage | Match clean↔raw |
|---|---|
| Null + sticky +0x3bf8 | **Yes** |
| Related FUN_00405920 | **Yes** |
| COID tree erase | **Yes** (iterator detail: prefer raw) |
| Select chrome dual FUN_00837d50 | **Yes** |
| Inventory/mission branch | **Yes** |
| Sheets + always unbind | **Yes** |
| Object_SetSelectedTarget walk | **Yes** |
| FUN_00996ff0 tail | **Yes** |

---

## 6. Gaps

1. Product name (no format string).
2. Full types for every panel offset and COID tree node layout.
3. Semantics of `FUN_00405920` / `LAB_0092d8e0`, `FUN_007fdab0`, `FUN_008027e0`, `FUN_00996ff0`.
4. Whether CompletelyDestroyObject ever reaches this via indirect path (not in direct xrefs).
5. Runtime verification per panel branch.
6. Named clean slightly normalizes tree-iterator SSA — use alias `FUN_00944d50.cpp` / raw for bit-exact port of that loop.

**Verdict:** **accept-with-gaps**
