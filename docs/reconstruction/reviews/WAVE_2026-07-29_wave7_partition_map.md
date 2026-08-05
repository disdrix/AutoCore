# Multi-agent partition map — wave 7 (2026-07-29)

| Field | Value |
|-------|-------|
| Terminal bar | every live Ghidra VA → full / reviewed / trivial-batch / deferred-low |
| Live Ghidra | 25666 |
| Dual pairs start (wave6 end) | **~664 unique A** |
| Imports ledger | **167** |
| Thunks ledger | **67** |
| Rule | One write owner per VA |

## High-priority duals (named full, no dual)

| VA | Focus |
|----|-------|
| `0x0042b940` | BitStream_readQuantizedFloat |
| `0x004370b0` | stoChunkReader_EnterChunkScope |
| `0x004bb950` | Object_ResolveFromTFID |
| `0x005f5de0` | VehicleNet_PackUpdate |
| `0x00636f00` | EMSG_Sector_Damage_Unpack |
| `0x00637750` | TNL_ByteBuffer_UnpackData |
| (+ more from live clean_named list at launch) | net/skill/vehicle/mission residual |

## Meta

| Role | Focus |
|------|-------|
| CRT import expand | Remaining pure FF25 IAT not in imports ledger |
| Parent | restamp ledgers after duals land |

## Honesty

Terminal **false**. Dual ~664 / 25666 (~2.6%). Inventory stamp ≠ dual depth.
