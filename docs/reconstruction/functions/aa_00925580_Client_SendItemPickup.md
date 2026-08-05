# Function record: `Client_SendItemPickup`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00925580` |
| **Canonical name** | `Client_SendItemPickup` |
| **Prior aliases** | `FUN_00925580`, `Named_CalleeOf_Client_Input_PollBoundActions_00925580` |
| **Address** | `0x00925580` |
| **Body** | `0x00925580`–`0x00925664` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` + Activate special-gather slice of `interaction-activation` |
| **Completion status** | **Dual A/B sealed** (opcode/size/layout/callers High; gate product names residual) |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Send C2S **ItemPickup** (`GameOpcode.ItemPickup` = **`0x2055`**) after a special cone/gather hit. Register ABI: **ESI** → 8-byte TFID pair. Packet size **`0x30`** via `Client_SendSectorPacket(&DAT_00d1a840, …)` with **EAX=8**.

## Signature (decompiler + call-site sealed)

```c
// ESI = uint32_t tfidPair[2]*
void Client_SendItemPickup(void);
```

## Sealed wire

| Fact | Value | Confidence |
|------|-------|------------|
| Opcode | **`0x2055`** | **High** (imm `C7 44 24 08 55 20 00 00`; sig imm 8277) |
| Size | **`0x30`** | **High** (`PUSH 0x30` / decomp second arg) |
| Transport | `Client_SendSectorPacket` / `DAT_00d1a840` | **High** |
| Reliability seed | `EAX=8` → Ordered | **High** |
| TFID source | `ESI[0], ESI[1]` @ pkt `+0x08/+0x0c` | **High** |
| Global flag on wire | forced **0** (`+0x10..`) | **High** |
| Float `@+0x28` | `g_flMsToSeconds` **0.001f** | **High** (store); **Tentative** (product) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00925580_FUN_00925580.md` (+ 2026-07-29 live section)
- Annotated: `docs/reconstruction/raw/aa_00925580_FUN_00925580.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_SendItemPickup.cpp`
- Reviews: `A_aa_00925580_Client_SendItemPickup.md`, `B_aa_00925580_Client_SendItemPickup.md`
- Scratch: `tmp/a_00925580.md`
- Report: `docs/agents/task-dual-ab-00925580-item-pickup-report.md`
- Server: `ItemPickupPacket.cs`, `GameOpcode.ItemPickup`, `HandleItemPickupPacket`

## Callers / callees

**Callees:** `Client_SendSectorPacket` (`0x00807460`) only.

**Callers (3):**

| VA site | Parent |
|---------|--------|
| `0x0092794c` | `Client_Input_PollBoundActions` |
| `0x00925707` | `FUN_00925670` |
| `0x00925be3` | `FUN_00925820` |

## Confidence

| Claim | Level |
|---|---|
| Opcode `0x2055` + size `0x30` | **High** |
| Layout table (static stores) | **High** |
| ESI TFID-pair ABI | **High** |
| Three callers complete | **High** |
| Gate field product names | **Tentative** |
| Float field product meaning | **Tentative** |
| Runtime wire | **Open** |
