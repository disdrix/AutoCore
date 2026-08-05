# Multi-agent partition map — wave 14 (2026-07-29)

| Field | Value |
|-------|-------|
| Terminal bar | every live Ghidra VA → full / reviewed / trivial-batch / deferred-low |
| Live Ghidra | 25666 |
| Dual pairs start | **1041** unique A |
| Rule | **One write owner per VA** |

## Kill loot / generate residual

| VA | Focus |
|----|-------|
| `0x00508dc0` | loot residual |
| `0x00509b10` | loot residual |
| `0x00509c70` | loot residual |
| `0x005129b0` | loot residual |
| `0x00513cf0` | loot residual |
| `0x00513d10` | loot residual |
| `0x005e0580` | loot residual |
| `0x005e1030` | loot residual |
| `0x005e1150` | loot residual |
| `0x004d78e0` | multi-target hit apply |
| `0x004e1600` | deferred combat pack |

## Mission complete residual

| VA | Focus |
|----|-------|
| `0x004de9f0` | CompleteObjective post-reward |
| `0x00519660` | Medal table lazy loader |
| `0x00531250` | AddAttributePoints |
| `0x005312c0` | AddSkillPoints |
| `0x00530df0` | SendInventoryAddItem |
| `0x005179a0` | SetInteractSpecialFX |
| `0x004dbef0` | complete residual |

## Vehicle net residual

| VA | Focus |
|----|-------|
| `0x005a3b00` | spatial map insert |
| `0x005b2490` | hardpoint size by type |
| `0x005b2c10` | deferred blob grow |
| `0x00575870` | convoy scatter origin |
| `0x0040b330` | map node lookup |

## Containers / DB residual

| VA | Focus |
|----|-------|
| `0x00466da0` | vector grow |
| `0x00422d10` | locale invoke |
| `0x0041de50` | locale invoke |
| `0x007dbce0` | type def load |
| `0x00545a90` | type def per-rec |
| `0x00536920` | character ctor hash |
| `0x00539d70` | hash recreate |
| `0x00539dd0` | hash recreate |
| `0x00539e30` | hash recreate |
| `0x0051d230` | medal load residual |
| `0x0051e4d0` | medal load residual |
| `0x00604e10` | medal load residual |
| `0x00605090` | medal load residual |
| `0x007cea40` | medal DB residual |

## Meta

Parent restamps. Terminal **false**. Dual 1041 ≪ 25666.
