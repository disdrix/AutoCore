# Review A (reconstruction fidelity): `aa_00925580` Client_SendItemPickup

| Field | Value |
|---|---|
| **Stable ID** | `aa_00925580` |
| **VA** | `0x00925580` |
| **Canonical name** | `Client_SendItemPickup` |
| **Review date** | `2026-07-29` (dual A/B — seal opcode **0x2055** / size **0x30**) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00925580_Client_SendItemPickup.md` |
| **System** | `inventory-transfer` / Activate special gather |
| **Verdict** | **accept-with-gaps** (opcode + size + layout + callers **sealed**; gate/float product residual) |

---

## 1. Purpose

Pack and send sector C2S **ItemPickup** when a special gather (`FUN_0058cd60` family @ **20.0f**, mode bits including **6**) returns a non-sentinel TFID pair in **ESI**. Used from:

1. Bound-action **Activate** exclusive early path (skips UseObject).
2. Periodic auto helper `FUN_00925670` (~100 ms throttle).
3. Interact hub `FUN_00925820` branch (clears select after send).

Not UseObject (`0x2072`); not QuestItemPickup (`0x205D`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00925580_FUN_00925580.md` (+ 2026-07-29 live) |
| Annotated | `docs/reconstruction/raw/aa_00925580_FUN_00925580.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_SendItemPickup.cpp` |
| Function record | `docs/reconstruction/functions/aa_00925580_Client_SendItemPickup.md` |
| Live decompile | Ghidra `decompile_function` `0x00925580` (2026-07-29) ≡ raw |
| Live bytes | `read_memory` `0x00925580` length 256; end `0x00925640` |
| Float const | `read_memory` `0x00a0f72c` → `6f12833a` = **0.001f** |
| Callers | `get_function_callers` + `get_xrefs_to` (3 UNCONDITIONAL_CALL) |
| Signature imms | `get_function_signature` → `[48, -1, 8277, 8]` |
| Call-site bytes | `read_memory` near `0x00927930`, `0x009256e0`, `0x00925bc0` |
| Server mirror | `ItemPickupPacket.cs`, `GameOpcode.ItemPickup = 0x2055` |
| Parent dual | `A/B_aa_00925d60_*` Activate exclusive 0x2055 path |

---

## 3. Sealed residuals

### 3.1 Opcode **0x2055** — **SEALED**

| Evidence | Detail |
|----------|--------|
| Decompile | `auStack_30[0] = 0x2055` |
| Asm imm | `C7 44 24 08 55 20 00 00` → `mov dword [esp+8], 0x2055` (pkt base after dual push) |
| Signature imm | **8277** decimal = **0x2055** |
| AutoCore | `GameOpcode.ItemPickup = 0x2055` |

### 3.2 Size **0x30** — **SEALED**

| Evidence | Detail |
|----------|--------|
| Decompile | `Client_SendSectorPacket(&DAT_00d1a840, 0x30, auStack_30)` |
| Asm | `6A 30` = `push 0x30` |
| Frame | `83 EC 30` / `83 C4 30` |
| Signature imm | **48** |

### 3.3 Packet layout — **SEALED** (static stores)

Stack frame after `sub esp,0x30`; send buffer base = that ESP.

| Off | Store | Content |
|----:|-------|---------|
| `+0x00` | imm | **`0x2055`** |
| `+0x04` | none | pad |
| `+0x08` | `[ESI]` | TFID d0 |
| `+0x0c` | `[ESI+4]` | TFID d1 |
| `+0x10`–`+0x27` | `xorps` zeros (6 dwords) | pad / forced Global=0 / unused |
| `+0x28` | `movss` from `DAT_00a0f72c` | **0.001f** |
| `+0x2c` | none | trailer in size |

Server `ItemPickupPacket.Read` (opcode stripped): `Int32 UnknownField` + `TFID` 16 B — matches `+0x04` pad + `+0x08` TFID16. Extra client body (`+0x18…+0x2f`) ignored by current AutoCore handler.

### 3.4 ESI ABI — **SEALED**

All three callers `LEA ESI, <pair*>` before `CALL`:

| Parent | Pair provenance |
|--------|-----------------|
| PollBound Activate | `uStack_40/3c` filled by `FUN_0058cd60` after vtbl`+0x1a0`(20.0f,1,6,…) |
| `FUN_00925670` | `local_30/2c` same gather family (last arg 1; ~100 ms) |
| `FUN_00925820` | stack pair at hub; then clear `[0x1d6]` select |

Validity test in body: `([ESI] & [ESI+4]) != 0xFFFFFFFF` (same AND-sentinel idiom as empty TFID).

### 3.5 Transport — **SEALED**

- `this = &DAT_00d1a840`
- `EAX = 8` → `Client_SendSectorPacket` reliability **Ordered** (`~(EAX>>2)&2 == 0`)
- Single callee

### 3.6 Gates — **High** structure / **Tentative** product names

| Gate | Structure conf. | Product name |
|------|-----------------|--------------|
| `DAT_00d1b4b0 == 0` | High | inventory busy (set by grab) — Probable |
| `char+0xcd0 == 0` | High | Tentative |
| `(cd8 & cdc) == -1` | High | empty active TFID-like — Probable |
| ESI valid | High | gather hit |
| vtbl+0x194 | High | dead/modal — Probable (shared PollBound) |
| `DAT_00d1b958/95c` +0x3d8 | High (call) | Tentative UI/modal objects |

---

## 4. Control-flow checklist

| Stage | Match clean ≡ raw ≡ live |
|-------|--------------------------|
| `sub esp,0x30` | Yes |
| Ordered gate chain | Yes |
| Pack TFID + zeros + float + opcode | Yes |
| `SendSectorPacket(0x30)` | Yes |
| Silent skip on any gate | Yes |
| `add esp,0x30; ret` | Yes |

---

## 5. Gaps

1. Product names for `+0xcd0/+0xcd8/+0xcdc` and UI objects `DAT_00d1b958/95c`.
2. Why write literal **0.001f** at `+0x28` (not a tick delta).
3. Whether gather TFID pair is full identity or coid-only (Global forced 0 — likely intentional for world loot).
4. Runtime capture: Activate near world loot → single `0x2055` frame size 0x30.
5. Server range (AutoCore 10u) vs client gather 20f mismatch (server policy, not this unit).

**Verdict:** **accept-with-gaps** — **opcode 0x2055 and size 0x30 sealed High**.
