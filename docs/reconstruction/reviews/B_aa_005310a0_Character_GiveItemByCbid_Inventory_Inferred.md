# Review B (skeptical / adversarial): `aa_005310a0` Character_GiveItemByCbid_Inventory_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005310a0` |
| **VA** | `0x005310a0` |
| **Canonical name** | `Character_GiveItemByCbid_Inventory_Inferred` |
| **Review date** | `2026-08-05` (MEGA-003 dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_005310a0_Character_GiveItemByCbid_Inventory_Inferred.md` |
| **Live tools** | Independent `decompile_function` + `disassemble_function` + `read_memory` + analyze/xrefs |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Log-only / `"Invalid CBID"` reporter | **Falsified** — primary path factories item, stamps serial, sends inventory add; log is **fail** exit only |
| 2 | Factory-only (no inventory) | **Falsified** — calls `Client_SendInventoryAddItem` `0x00530df0` each unit |
| 3 | Same as `CVOGReaction_GiveItemByCbid` | **Falsified** — different VA; factory is **callee**; this owns count loop + insert |
| 4 | `__thiscall (this, cbid)` / `RET 4` | **Falsified** — two stack args; **`RET 8`** (`C2 08 00`) |
| 5 | `while (GiveItemByCbid succeeds)` infinite grant | **Falsified** — `remaining = count`; `SUB remaining,1`; `JNZ loop`; factory null → fail |
| 6 | Free-function / ECX unused | **Falsified** — `MOV EDI,ECX`; dual-base char from EDI; SendAdd uses ECX=EDI |
| 7 | Always returns false / always true | **Falsified** — AL=1 success paths; AL=0 only on factory null |
| 8 | Gate `+0x7e` clear means fail | **Falsified** — clear → **success** early (`MOV AL,1`) |
| 9 | Runtime Confirmed | **Fails** — open; Terminal false |

---

## 2. Decisive machine dataflow

```text
MOV EDI, ECX
// char* = *( *(EDI+4)+4 ) + 0xa8 + EDI
MOV AL, [char+0x7e]
TEST AL, AL
JZ  success                     // return 1 without grant

MOV EDX, [ESP+0x30]             // count
MOV [ESP+0x14], EDX             // remaining
MOV EBX, [ESP+0x2c]             // cbid
loop:
  PUSH 0
  PUSH EBX
  CALL CVOGReaction_GiveItemByCbid
  ADD ESP, 8
  TEST ESI, ESI
  JZ   fail_log                 // Invalid CBID...
  // ... init / serial / transform / owner ...
  CALL Client_SendInventoryAddItem  // ECX=EDI
  SUB  [ESP+0x14], 1
  JNZ  loop
success:
  MOV AL, 1
  RET 8
fail_log:
  XOR AL, AL
  RET 8
```

String seal: `"Invalid CBID: %d (bad item)"` @ `0x009cfea4` (`read_memory`).  
Float seal: `g_flOne` @ `0x00a0f2a0` = `00 00 80 3F`.

Call-site pattern (UseItem init @ `0x0060d57f`): push qty; push cbid; `CALL 0x005310a0`; test AL; on 0 log `"Failed to give item %d..."`.

A ≡ B on live decompile + body disassembly + xrefs.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + RET 8; cbid+count | **High** | stack smash / wrong arity |
| Count-down grant loop | **High** | multi-grant wrong |
| Factory + inventory insert split | **High** | double-insert or missing bag |
| Caller set (8 sites / 6 parents) | **High** | missing UseItem path |
| Character class English | Medium | naming only |
| Vtbl slot English / bind gate | Medium–Low | wrong notify/bind model |
| Runtime | Open | residual |

---

## 4. Surviving contract for AutoCore

```csharp
// Character grant: create `count` items of `cbid` and inventory-add each.
// thiscall RET 8; returns false only when factory cannot resolve CBID.
bool GiveItemByCbidInventory(Character self, int cbid, int count)
{
    var ch = self.DualBaseCharacter(); // +0xa8 via *( *(this+4)+4 )
    if (!ch.ReadyFlag_7e) return true;

    int remaining = count;
    bool first = true;
    uint invFlag = (uint)count;

    do {
        var item = GiveItemByCbid(cbid, 0); // factory only
        if (item == null) {
            Log(1, "Invalid CBID: %d (bad item)", cbid);
            return false;
        }
        item.InitFromCbid(cbid, ch, 1);           // vtbl+8
        var serial = ch.NextInstanceSerial();     // +0xe6e0 u64++
        item.StampSerial(serial, flag: 1);        // FUN_00512160
        item.ResetTransformIdentity();            // vtbl+0x1cc + g_flOne
        item.SetOwnerFields(ch);                  // vtbl+0x2a4/+0x218
        if (first) {
            first = false;
            if (ItemRequiresBindOrLock(item)) remaining = 1; // FUN_00513e70
            else invFlag = 1;
        }
        item.SetInventoryNotifyFlag(invFlag);     // vtbl+0x260
        Client_SendInventoryAddItem(self, item, invFlag);
        remaining--;
    } while (remaining != 0);

    return true;
}
// Keep distinct from CVOGReaction_GiveItemByCbid (factory) and pure log helpers.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/caller roles and rejects log-only / factory-only / wrong-arity claims. Residual class English + vtbl/bind semantics → **accept-with-gaps**. Runtime Confirmed **not** claimed.
