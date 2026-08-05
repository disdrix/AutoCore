# Skeptical / adversarial review: `Inventory_SerializeAddItemPacket` @ `0x004fadb0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fadb0` |
| **Review type** | Skeptical / adversarial |
| **Date** | 2026-07-23 |
| **Scope** | AddItem packet fill helper + field layout claims |
| **Verdict** | **needs-more-evidence** |

---

## 1. What was inspected

| Path | Role |
|------|------|
| `raw/aa_004fadb0_Inventory_SerializeAddItemPacket.md` | Immutable decompile |
| Clean + function record | Package claims |
| `Client_SendInventoryAddItem` raw | Caller opcode / branch on +0x12 |
| `Documentation/PACKET STRUCTURES.md` | 0x2047 layout |
| `docs/inventory-cargo-wire-re.md` | Client cargo visual path |

**Not performed:** live re-decompile, CE, full FindFreeSlot dual review inside this pass.

---

## 2. Evidence used (authoritative body)

1. Returns 0 if `*(this+0x2b0)==0`.
2. Writes packet `+0x18` then branches on `FUN_00513e70`.
3. Free path sets `+0x18=1`, `+0x12=0`, `*(+8)=item[0x58]`, `*(+0xc)=item[0x59]`.
4. Stack path may set `+0x12=1`, zero `+0x10/+0x11`, COID from other object.
5. May `LeaveCriticalSection` on cargo object.

---

## 3. Attack results

### Claim 1 — Fills S2C-shaped 0x2047 AddItem packet

| Sub-claim | Attack result |
|-----------|----------------|
| Caller stamps opcode `0x2047` | **Not broken** (in SendInventoryAddItem, not this body). |
| This function writes field offsets matching 0x2047 docs | **Probable.** Offsets align; this body never writes opcode. |
| Direction is C2S request | **Plate narrative.** Name “SerializeAddItemPacket” used by client send; server may use same layout for S2C — direction not decided inside this helper. |

### Claim 2 — `item[0x58]/[0x59]` are grid X/Y

| Sub-claim | Attack result |
|-----------|----------------|
| Old plate text | **FALSIFIED.** Indices `0x58*4=0x160`, `0x59*4=0x164` match COID TFID halves used everywhere else; merge path copies `obj+0x160/+0x164` into the same packet slots; PACKET STRUCTURES places COID at +8. |
| Clean correction to COID | **Holds** against multi-source attack. |

### Claim 3 — `FUN_005714e0` is FindFreeSlot writing X/Y

| Sub-claim | Attack result |
|-----------|----------------|
| Called with `(item, packet+0x10, packet+0x11, 1, -1)` | **Not broken** as CF. |
| Writes cargo slot coords | **Probable** — only free path depends on it for X/Y; not symbol-proven here. |
| Type==4 skips find | **Holds** — type 4 short-circuits OR. Semantic class name unproven. |

### Claim 4 — Stack merge is safe / complete

| Sub-claim | Attack result |
|-----------|----------------|
| CBID equality via clonebase+0x34 | **Not broken.** |
| Flag bit 19 must be clear on both | **Not broken** as CF; meaning of bit **unproven**. |
| `FUN_0040abf0(vfunc+0x25c)` is qty compatibility | **Interpretive.** Could be stack-key, max-stack, or other gate. |
| Always finds best stack | **Unproven** — first successful match breaks; order is iterator order. |

### Claim 5 — Signature / this pointer

| Sub-claim | Attack result |
|-----------|----------------|
| `this+0x2b0` is cargo inventory | **Probable** (vehicle cargo layout also used at equip `vehicle+0x2b0`). |
| Four-arg thiscall including iter out | **Probable** from Ghidra; caller passes `&local_14c`. |
| Clean renames | Cosmetic; raw param_1..4 still valid. |

### Claim 6 — Clean ≡ retail

| Sub-claim | Attack result |
|-----------|----------------|
| CF match | **Yes.** |
| Decompiler ≡ retail | **Not sealed.** |
| CS release always paired | **Risky** — only in stack branch after scan; free path never takes CS here (lock may be inside callees). |

---

## 4. Alternate interpretations

### Minimal hard reading

```
if (!cargo) return 0;
pkt.wasAdded = 0;
if (!stack_mode()) {
  if (type==4 || find_slot(item, &pkt.x, &pkt.y)) fill_new_slot();
} else {
  for (item in cargo) if (same_cbid && flags_ok && qty_ok) fill_merge(); break;
  unlock_if_held();
  if (!filled && (type==4 || find_slot(...))) fill_new_slot();
}
return filled;
```

### Risky over-read

- Calling `+8` “grid X” (falsified).
- Assuming merge always prefers fullest stack.
- Assuming this is server-only or client-only exclusively.

---

## 5. What would seal or kill claims

| Evidence | Effect |
|----------|--------|
| Live decompile of `FUN_005714e0` / `FUN_00513e70` | Name find-slot / stack-mode |
| Packet capture of C2S 0x2047 from this client path | Seal field packing |
| Type-4 item add live test | Confirm X/Y may be unset |

---

## 6. Verdict

### **needs-more-evidence**

Field-layout correction (COID at +8) is **strong**. Helper naming and stack-mode semantics remain open. Do not mark complete or bit-exact.
