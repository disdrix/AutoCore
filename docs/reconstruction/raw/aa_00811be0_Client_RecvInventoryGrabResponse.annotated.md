# Annotated low-level: Client_RecvInventoryGrabResponse (`aa_00811be0`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00811be0` |
| **VA** | `0x00811be0` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **Source raw** | `aa_00811be0_Client_RecvInventoryGrabResponse.md` (capture 2026-07-23) |
| **System** | inventory-transfer |
| **Wire** | S2C **`0x2035`** GrabResponse; early-out if opcode **`0x2039`** (shared dispatch slot) |
| **Residual** | 2026-07-29 dual residual — asm sealed invType@+0x18 + true `FUN_0093d6e0` args |

---

## 1. Calling convention (packet dispatch) — Confirmed

```c
// Call site Client_PacketDispatch @ 0x008159b0:
//   MOV EBX, ESI   ; packet
//   MOV EAX, EBP   ; client
//   CALL 0x00811be0
// Prologue: MOV ESI, EAX  ; clear [ESI+0xb6]
void Client_RecvInventoryGrabResponse(/* EAX client, EBX packet */);
```

| Location | Role |
|---|---|
| `EAX` → `ESI` | Client / player UI root |
| `EBX` | Packet pointer |
| `*packet` (u32) | Opcode |
| `packet+0x08` | Item TFID (`TFID_16` at `EBX+2` dwords) |
| **`packet+0x18`** | **InventoryType (u8)** → `DL` for cursor helper |
| `packet+0x1c` | Quantity (count) |
| `packet+0x20` | SplitFlag: 0 → whole-grab; nonzero → stack split |
| `packet+0x28/+0x2c` | Split COID (split path only) → `FUN_00512160` |
| `packet+0x38` | Success / proceed flag |

---

## 2. Control flow

```text
*(u8*)(client + 0xb6) = 0
logger = FUN_007a69d0()            // &DAT_00d1f660

if *packet == 0x2039:
  return                              // shared jump: ignore

item = Object_ResolveFromTFID(packet+8)   // kept in EBP
if item != NULL && success@+0x38 != 0:
  if splitFlag@+0x20 == 0:
    // whole-grab — full cursor apply (not qty-only)
    FUN_0093d6e0(item=EAX, invType=DL@+0x18, client, count@+0x1c)
    Client_RefreshOpenMissionUiWindows(client)
    return

  // stack split path (source=EBP, new stack=EDI)
  oldQty = item.vtbl+0x25c()
  item.vtbl+0x260(oldQty - count)
  newStack = CVOGReaction_GiveItemByCbid(cbid from item blob +0x34)
  if newStack == NULL:
    toast "Grab Item failed: Failed creating new stack object on coid"
    FUN_007fc150(); return           // cursor UI clear — NOT DAT_00d1a8f6

  FUN_00512160(this=newStack, coidLo@+0x28, coidHi@+0x2c, flag=1)
  newStack.vtbl+8(cbid, client+0xe04, 0)
  newStack.vtbl+0x260(count)
  FUN_004bc180(newStack)             // register object list
  // graphics init at 1.0f scale etc.
  FUN_0093d6e0(item=newStack, invType@+0x18, client, count)
  Client_RefreshOpenMissionUiWindows(client)
  return

// resolve / success fail
OutputDebugString("Grab Item failed: Failed on coid: %i")
Client_RefreshOpenMissionUiWindows(client)
return
```

---

## 3. Side-effect order

1. Clear `client+0xb6` busy/flag byte (not global `DAT_00d1a8f6`).
2. Opcode gate `0x2039`.
3. Resolve TFID → object.
4. Either:
   - whole: grid remove (in helper when present) + qty + cursor attach, or
   - split: mutate original qty → create new stack → bind COID → init → cursor attach of **new**.
5. Mission UI refresh.
6. On hard fail: debug string and/or toast.

Grid place is **not** this handler (drop path). Whole-grab **does** remove via `FUN_0093d6e0` when item is still in a typed inventory.

---

## 4. Decompiler corrections

| Artifact | Correction | Confidence |
|---|---|---|
| `unaff_EBX` / `in_EAX` | Dispatch **EBX=packet, EAX=client** | **Confirmed** (call site + prologue) |
| `0x2035` binding | External PacketDispatch case + sole xref | **Confirmed** |
| `0x2039` early out | Sibling opcode shares handler entry | **Confirmed** |
| `FUN_0093d6e0(client,count)` 2-arg fiction | Real: **EAX=item, DL=invType@+0x18, stack client+count** | **High** (asm) |
| `+0x38` as split | **Success**; split is `@+0x20` | **High** |
| `FUN_00512160` stack-only | **thiscall** ECX=new stack | **High** (asm) |
| `CVOGReaction_GiveItemByCbid` | Spawn new stack instance from CBID | **High** |
| `g_flOne` / scale vfunc | float 1.0 visual setup | **High** |
| Busy clear `DAT_00d1a8f6` here | **Absent** (xref map) | **Confirmed** |
