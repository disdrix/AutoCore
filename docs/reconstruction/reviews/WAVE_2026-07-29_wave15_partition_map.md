# Multi-agent partition map — wave 15 (2026-07-29)

| Field | Value |
|-------|-------|
| Terminal bar | every live Ghidra VA → full / reviewed / trivial-batch / deferred-low |
| Live Ghidra | 25666 |
| Dual pairs start | **1131** unique A |
| Rule | **One write owner per VA** |

## Loot / catalog residual

| VA | Focus |
|----|-------|
| `0x00599dd0` | mod slot count |
| `0x00508a00` | loot residual |
| `0x005e07d0` | catalog fill |
| `0x005e0cd0` | catalog fill filtered |
| `0x005a3310` | map insert |

## Combat floater residual

| VA | Focus |
|----|-------|
| `0x004044c0` | floater relocate |
| `0x00402ea0` | floater residual |
| `0x004044e0` | floater residual |
| `0x00539810` | dword grow |

## Vehicle / enter-world residual

| VA | Focus |
|----|-------|
| `0x005a4f60` | CreateWeaponTrackAction |
| `0x004fb660` | createVehicleAction |
| `0x004f8430` | weapon track residual |
| `0x004f7d60` | vehicle action residual |
| `0x005d4050` | vehicle residual |
| `0x005fe5c0` | vehicle residual |
| `0x00597f90` | VehicleAction_ctor |
| `0x005fd390` | buildHavokVehicleFramework |
| `0x004fb370` | soft pose residual |
| `0x00506f50` | create msg helper |

## Inventory equip residual (2nd level)

| VA | Focus |
|----|-------|
| `0x004024b0` | equip residual |
| `0x004d3310` | equip residual |
| `0x004d9b50` | equip residual |
| `0x004f70f0` | equip residual |
| `0x00519d20` | equip residual |
| `0x0051f4e0` | equip residual |
| `0x0051f550` | equip residual |
| `0x0076cec0` | equip residual |
| `0x007fe720` | equip residual |
| `0x007fef20` | equip residual |
| `0x00802170` | equip residual |
| `0x008718a0` | garage residual |
| `0x0087d2f0` | garage residual |
| `0x0089b090` | garage residual |
| `0x0089bc30` | garage residual |
| `0x0089c330` | garage residual |
| `0x0092a200` | equip residual |
| `0x0092d730` | equip residual |
| `0x00933370` | equip residual |
| `0x0093ffb0` | equip residual |

## Mission / skill residual

| VA | Focus |
|----|-------|
| `0x00546060` | EnsureXml string twin |
| `0x005460d0` | EnsureXml string twin |
| `0x00546140` | EnsureXml string twin |
| `0x004d1d00` | continent unlock body |
| `0x00547050` | mission residual |
| `0x007988e0` | XML helper |
| `0x00799460` | XML helper |
| `0x00799900` | XML helper |
| `0x007e34b0` | skill ensure residual |
| `0x00514e70` | skill clear |
| `0x006a3db0` | LevelUp residual |
| `0x0056bab0` | weapon FX event |

## Containers / hash residual

| VA | Focus |
|----|-------|
| `0x00539090` | FreeBuckets twin |
| `0x005390d0` | FreeBuckets twin |
| `0x00539110` | FreeBuckets twin |
| `0x0053b540` | scalar deleting dtor |
| `0x0053b650` | scalar deleting dtor |
| `0x0053b760` | scalar deleting dtor |
| `0x0053b7f0` | scalar deleting dtor |
| `0x0053b880` | FreeBuckets |
| `0x00456960` | vector grow core |
| `0x00422d70` | COM prep |
| `0x004229e0` | COM residual |
| `0x0052b4e0` | bulk wipe |
| `0x00402d50` | residual |
| `0x0040d230` | residual |

## Meta

Parent restamps. Terminal **false**. Dual 1131 ≪ 25666.
