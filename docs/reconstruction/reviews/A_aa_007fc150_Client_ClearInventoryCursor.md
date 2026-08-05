# Review A (reconstruction fidelity): `aa_007fc150` Client_ClearInventoryCursor

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fc150` |
| **VA** | `0x007fc150` |
| **Canonical name** | `Client_ClearInventoryCursor` (**INFERRED**) |
| **Aliases** | `FUN_007fc150`, `Named_CalleeOf_Client_RecvInventoryEquip_007fc150` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007fc150_Client_ClearInventoryCursor.md` |
| **System** | `inventory-transfer` (UI / cursor) |
| **Evidence pass** | Live Ghidra decompile + `read_memory` (ESI-based client); equip residual notes |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Client inventory cursor clear / hide path** used after equip/grab/drop when the hand/cursor item should be released:

Preconditions (both required): `client+0xf40 != 0` and `client+0x9b8 != 0` (cursor/UI object pair).

Then:

1. If `client+0x1168` → vfunc `+4(1)` (modal/UI child close-ish).
2. Probe inventory UI panes:
   - `*(client+0x1040)+0x50c` and `*(client+0x1034)+0x510`: if present and vfunc **`+0x3d8`** true → `FUN_008c26c0`.
   - `client+0x105c` / `+0x1060`: if `+0x3d8` and secondary field non-zero → `FUN_0085e890`.
3. If cursor root `**(client+0xf40)` non-null → vfunc **`+0xb0( client+0x9b8 )`** (detach/hide cursor visual).
4. `*(cursor+0x494) = 0` where cursor = `*(client+0x9b8)`; vfunc **`+0x3b0(0)`**.
5. If `client+0xe98` → `FUN_0051f4e0(0)` (related player/vehicle UI clear).

**Not** hardpoint mutation. Pairs with `Client_SetInventoryCursor` (`0x007fc270`).

Calling convention: **ESI = client\*** (register; decompiler `unaff_ESI`). Confirmed by image: all accesses are `[esi+disp]`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007fc150_FUN_007fc150.md` |
| Annotated | `docs/reconstruction/raw/aa_007fc150_FUN_007fc150.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_007fc150.cpp` |
| Function record | `docs/reconstruction/functions/aa_007fc150_FUN_007fc150.md` |
| Counterpart B | `reviews/B_aa_007fc150_Client_ClearInventoryCursor.md` |

---

## 3. Signature

```c
// ESI = Client* (custom register convention from inventory recv parents)
void Client_ClearInventoryCursor(void /* ESI=client */);
```

### Image notes (`read_memory` 2026-07-29)

```
cmp dword [esi+0xf40], 0 ; jz exit
cmp dword [esi+0x9b8], 0 ; jz exit
; ... pane probes + cursor hide ...
mov dword [ *(esi+0x9b8) + 0x494 ], 0
call [cursor.vtbl+0x3b0](0)
```

| Stage | Match | Confidence |
|---|---|---|
| Dual gate `+0xf40` / `+0x9b8` | **Yes** | **High** |
| Cursor field `+0x494 = 0` | **Yes** | **High** |
| Hide vfunc `+0x3b0(0)` | **Yes** | **High** |
| No equip hardpoint writes | **Yes** | **High** |
| ESI client convention | **High** | image `[esi+…]` |

---

## 4. Callers

| Caller | Role |
|---|---|
| `Client_RecvInventoryEquip` | Clear cursor when appropriate after equip |
| `Client_RecvInventoryGrabResponse` | Cursor lifecycle |
| `Client_RecvInventoryDropResponse` | Cursor lifecycle |
| Other UI FUN_007ff3d0 / 008012f0 / … | Inventory UI |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Cursor clear / hide | **High** | equip residual + CF |
| Offsets `+0xf40`, `+0x9b8`, cursor `+0x494` | **High** | bytes |
| Pane helper names | **Open** | `FUN_008c26c0` / `FUN_0085e890` |
| Exact UI widget product IDs | **Tentative** | only structural |

---

## 6. Gaps / open

1. Product names for pane helpers and vfuncs.
2. Full formal signature in IDA (ESI vs stack) for clean C++ ports.

**Verdict:** **accept-with-gaps**
