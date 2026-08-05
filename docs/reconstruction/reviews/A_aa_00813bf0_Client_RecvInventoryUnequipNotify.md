# Review A (reconstruction fidelity): `aa_00813bf0` Client_RecvInventoryUnequipNotify

| Field | Value |
|---|---|
| **Stable ID** | `aa_00813bf0` |
| **VA** | `0x00813bf0` |
| **Canonical name** | `Client_RecvInventoryUnequipNotify` |
| **Review date** | `2026-07-23` (residual refresh `2026-07-29`) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00813bf0_Client_RecvInventoryUnequipNotify.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

S2C InventoryUnequip notify (**`0x203E` size `0x30`**): item TFID `@+8`, vehicle id `@+0x18`, realm `@+0x20`, destX/Y `@+0x28/+0x29`, invType `@+0x2A`. Distinct from C2S `Client_SendInventoryUnequip` (same opcode, bidirectional — **directional demux sealed** in residual).

Local owner path: invType switch — 0 no place; 1 cargo place footprint; 2 UI helper `FUN_0093d6e0`; 3 locker place; fail toast *“This equipment cannot be changed at this time.”*

Non-local: resolve item, clear equip class switch (ornament / power plant / melee / weapon slot / wheelset / armor).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw / clean | `raw/aa_00813bf0_…`, `reconstructed-exact/Client_RecvInventoryUnequipNotify.cpp` |
| Function record | `functions/aa_00813bf0_…` |
| Residual scratch | `reviews/a_00813bf0.md` |
| Dispatch | `Client_PacketDispatch` case `0x203e` |
| C2S sibling | `Client_SendInventoryUnequip` `0x00862c00` |
| Clear helpers | `0x004fe620`, `0x004fe800`, `0x004fe110`, `0x004ff510`, `0x00502180`, `Vehicle_EquipPowerPlant` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Log line + vehicle resolve `FUN_004bafe0` | **High** | |
| Null vehicle early paths | **High** | |
| Local vs non-local owner branch | **High** CF |
| invType 0/1/2/3 switch + place | **High** CF |
| Place via `FUN_00571620` | **High** | |
| Opcode 0x203E size 0x30 | **High** | dispatch + C2S builder |
| **C2S/S2C demux is directional** (PacketDispatch vs SendSectorPacket) | **High** | residual 2026-07-29 |
| Shared 0x30 layout; C2S omits vehicle/invType | **High** | Send body vs Recv reads |
| Non-local class map 6/10/0xc/0x10/0x1c → named roles | **High** | unhappy-type / same-equip strings |
| Class-10 clear → PowerPlant null | **High** | |
| Class-6 ornament `+0x26c`; melee `+0x264`; weapons `+0x260[]`; wheelset `+0x258`; armor `+0x254` | **High** | helper decompiles |
| RaceItem `+0x270` in this switch | **High absent** | class 6 requires subtype 10 only |
| Packet in EAX / client param | **Probable** | Decomp framing |
| invType 2 → `FUN_0093d6e0` exact UI semantics | **Probable** | helper multi-case |

---

## 4. Control flow: clean ≡ raw

Human-refined clean preserves log, vehicle resolve, local switch, non-local class clear, UI refresh. Residual re-decompile 2026-07-29: no CF change.

---

## 5. Gaps / open

Runtime unequip; bit-exact / image diff; PDB names for FUN_* helpers; invType-2 UI detail Probable.

**Verdict:** **accept-with-gaps** — dual residual **demux** and **class map** sealed; only verification/runtime remain.
