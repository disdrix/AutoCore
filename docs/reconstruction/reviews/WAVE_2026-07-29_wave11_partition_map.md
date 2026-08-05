# Multi-agent partition map — wave 11 (2026-07-29)

| Field | Value |
|-------|-------|
| Terminal bar | every live Ghidra VA → full / reviewed / trivial-batch / deferred-low |
| Live Ghidra | 25666 |
| Dual pairs start | **842** unique A |
| Rule | **One write owner per VA** |

## Weapon / combat fire chain

| VA | Focus |
|----|-------|
| `0x004b68c0` | Weapon fire helper callee |
| `0x004b73c0` | Weapon fire helper callee |
| `0x004b7550` | Weapon fire helper callee |
| `0x004b75d0` | Weapon fire helper callee |
| `0x004b7e50` | Weapon fire helper callee |
| `0x004b8dc0` | Weapon fire helper callee |
| `0x004ec010` | Weapon/anim helper |
| `0x00569cb0` | Weapon fire helper |
| `0x0056aca0` | Weapon_CanFireHeatCheck (if no dual) |

## Inventory UI rebuild / sheet

| VA | Focus |
|----|-------|
| `0x0040dc40` | inventory rebuild helper |
| `0x00413be0` | hash/list helper |
| `0x004294f0` | rebuild helper |
| `0x00571260` | inventory grid helper |
| `0x0085fd80` | sheet clear helper |
| `0x00931d60` | inventory collect page |
| `0x008800e0` | garage/equip UI |
| `0x0088ef70` | inventory UI |

## Physics / HB residual

| VA | Focus |
|----|-------|
| `0x005075f0` | HB list helper (unstick path) |
| `0x005b3370` | phys activate callee |
| `0x0062a6c0` | phys activate callee |
| `0x005083f0` | HB helper |
| `0x0055fe50` | HB helper |
| `0x00600140` | HB helper |
| `0x005984dc` / mid airStab | if separate entry |

## Select / unequip / mission residual

| VA | Focus |
|----|-------|
| `0x00504f60` | unequip path |
| `0x0093d6e0` | unequip UI |
| `0x0040b1b0` | select target helper |
| `0x00893580` | select UI |
| `0x008b2470` | select UI |
| `0x008e9690` | select UI |
| `0x004cf3b0` | combat pools helper |
| `0x007a4330` | RandomUnitScalar |

## Meta

Parent restamps. Terminal **false**. Dual 842 ≪ 25666.
