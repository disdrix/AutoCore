# Function record: Item_TryConcatStackWithPeer

| Field | Value |
|---|---|
| **Stable ID** | `aa_00513eb0` |
| **Canonical name** | `Item_TryConcatStackWithPeer` |
| **Prior names** | `FUN_00513eb0`, `Named_CalleeOf_Client_RecvInventoryDropResponse_00513eb0` |
| **Address** | `0x00513eb0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` |
| **Calling convention** | MSVC `__thiscall` — `this` = destination item; peer on stack; **`ret 4`** |
| **Body** | `0x00513eb0`–`0x00513f5e` inclusive (**175 B** / `0xAF`) |
| **Completion status** | **Human-refined** — dual A/B sealed 2026-08-05 MEGA-012 |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual verdict** | **accept-with-gaps** |

## Purpose

Attempt to **concatenate** peer item into destination `this` when both share the same CBID (`clonebase+0x34`).

Used by:
- `Client_RecvInventoryDropResponse` concat branch (packet concat flag; failure string *"Dropping failed trying to concatinate"*)
- `FUN_008134d0` TradeRemoveItem_Response when add-to-existing finds a same-CBID stack

## Signature (sealed)

```c
// this = destination Item* receiving the merge
// peer = Item* being absorbed (must be non-null, same CBID)
bool __thiscall Item_TryConcatStackWithPeer(void* this, void* peer);
```

## Behavioral summary (SEALED)

1. If `peer == null` → **false**.
2. If `*(peer.clonebase+0x34) != *(this.clonebase+0x34)` → **false** (`clonebase = item+0xA8`).
3. `limit = *(u16*)(*(this.clonebase+0x3C) + 0x4BC)`.
4. If `limit ∉ {0, 0xFFFF}`:
   - `sum = *(u16*)(this+0x180) + *(u16*)(peer+0x180)`.
   - If `sum <= limit`: store `sum` at `this+0x180`; dirty; return **true** (**no** vfunc qty merge).
   - Else: store `sum % limit` (or `limit` if remainder 0) at `this+0x180`; continue.
5. `this.SetQty(peer.GetQty() + this.GetQty())` via vtbl **`+0x25C` / `+0x260`**.
6. Dirty via `FUN_00512670`; return **true**.

## Naming note

- Role sealed by drop-response **"concatinate"** string + concat/split plate + same-CBID merge CF.
- **Not** `Item_CanAcceptStackQty` (`aa_0040abf0`) — predicate only; max @ def **`+0x4BA`**.
- **Not** `Item_IsStackEligible` (`aa_00513e70`) — eligibility flags only.
- Scaffold `Named_CalleeOf_Client_RecvInventoryDropResponse_00513eb0` **retired**.

## Callers (xref complete @ dual time)

| Site VA | Function | this | peer |
|---------|----------|------|------|
| `0x00813673` | `FUN_008134d0` TradeRemoveItem_Response | found stack (`FUN_005710c0`) | item leaving trade |
| `0x00813995` | `Client_RecvInventoryDropResponse` | existing (`FUN_00571010`) | selected/drag (`+0x3AC`) |

## Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary / size | **High** |
| Signature (`__thiscall` + peer + RET 4) | **High** |
| Control flow | **High** (live ≡ raw 2026-08-05) |
| CBID gate + dirty callee | **High** |
| Call-site this/peer roles | **High** |
| Concat role / name | **High / Probable** |
| Product English `+0x180` / def`+0x4BC` | **Open** |
| Fit-path skip of vfunc qty | **Sealed oddity**; rationale **Open** |
| Runtime / diff | **Open** |
| Overall | **accept-with-gaps** |

## Dual reviews

- A: `docs/reconstruction/reviews/A_aa_00513eb0_Item_TryConcatStackWithPeer.md`
- B: `docs/reconstruction/reviews/B_aa_00513eb0_Item_TryConcatStackWithPeer.md`

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00513eb0_FUN_00513eb0.md`
- Annotated: `docs/reconstruction/raw/aa_00513eb0_FUN_00513eb0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Item_TryConcatStackWithPeer.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00513eb0.cpp`
- FUN record: `docs/reconstruction/functions/aa_00513eb0_FUN_00513eb0.md`
- Report: `docs/agents/task-dual-ab-00513eb0-mega-012-report.md`
