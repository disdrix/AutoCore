# Multi-agent partition map — wave 13 (2026-07-29)

| Field | Value |
|-------|-------|
| Terminal bar | every live Ghidra VA → full / reviewed / trivial-batch / deferred-low |
| Live Ghidra | 25666 |
| Dual pairs start | **949** unique A |
| Rule | **One write owner per VA** |

## Weapon / SpecialFX residual

| VA | Focus |
|----|-------|
| `0x004b67d0` | FX fire event path |
| `0x004da2e0` | FX fire event path |
| `0x004b85d0` | FX teardown list free |
| `0x004bacf0` | FX teardown |
| `0x005875c0` | FX teardown |
| `0x004b9300` | FX setup |
| `0x004a1620` | FX master ctor helper |
| `0x004a6390` | LoadMasterFromXML |

## Vehicle net unpack residual

| VA | Focus |
|----|-------|
| `0x004c2f10` | attr u16 +0x142 |
| `0x005208e0` | net mask helper |
| `0x00521440` | ghost unpack helper |
| `0x00521480` | ghost unpack helper |
| `0x005214b0` | ghost unpack helper |
| `0x00522f70` | ghost unpack |
| `0x00524680` | ghost unpack |
| `0x005a0b30` | correction event |
| `0x005b2800` | skills HB residual |
| `0x005f5ad0` | vehicle net residual |
| `0x005fe6a0` | vehicle net residual |
| `0x005f7360` | PostCorrectionEvent (if missing) |
| `0x00780a80` | net helper |
| `0x007971b0` | net helper |

## Combat death / loot residual

| VA | Focus |
|----|-------|
| `0x004d2750` | OnDeath loot |
| `0x004d2820` | OnDeath loot |
| `0x004d31a0` | OnDeath loot |
| `0x004d4440` | OnDeath loot |
| `0x004d0ed0` | GiveItem residual |
| `0x00512160` | loot helper |
| `0x005123e0` | loot helper |
| + related combat pool helpers | batch |

## Audio proximity residual

| VA | Focus |
|----|-------|
| `0x00480170` | sound path resolve |
| `0x00480350` | sound path |
| `0x00480460` | sound path |
| `0x00722b80` | sound helper |
| `0x007249c0` | sound helper |
| `0x0071e570` | sound instance ctor |

## Containers / hash residual

| VA | Focus |
|----|-------|
| `0x0053b330` | CNDHash RemoveAll twin |
| `0x0053b430` | CNDHash RemoveAll twin |
| `0x00537a10` | AllocBuckets twin |
| `0x005b3300` | array grow |
| `0x005fff20` | list compact |
| `0x004406e0` | vector push |
| `0x0042b250` | BitStream residual |
| `0x0042b270` | BitStream residual |

## Meta

Parent restamps. Terminal **false**. Dual 949 ≪ 25666.
