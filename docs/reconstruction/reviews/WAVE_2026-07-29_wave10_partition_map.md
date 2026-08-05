# Multi-agent partition map — wave 10 (2026-07-29)

| Field | Value |
|-------|-------|
| Terminal bar | every live Ghidra VA → full / reviewed / trivial-batch / deferred-low |
| Live Ghidra | 25666 |
| Dual pairs start | **783** unique A |
| Rule | **One write owner per VA** |

## Skills / targeting (GatherTargetsInArea chain)

| VA | Focus |
|----|-------|
| `0x004073a0` | GatherTargets helper |
| `0x004e9aa0` | area/target math |
| `0x004ea350` | area/target math |
| `0x0058a810` | GatherTargets helper |
| `0x0058c7a0` | GatherTargets helper |
| `0x0058d9c0` | GatherTargets helper |
| `0x0058def0` | GatherTargets helper |
| `0x0058df60` | GatherTargets helper |
| `0x0056d520` | Weapon start-fire |

## Missions / hash / objectives

| VA | Focus |
|----|-------|
| `0x0053c460` | AddActiveObjective hash |
| `0x0053c760` | AddActiveObjective hash |
| `0x005307e0` | EvaluatePendingObjectives |
| `0x0059d880` | EvaluatePendingObjectives |
| `0x004059f0` | Client_SendLogicUiPacket (if no dual) |

## Inventory / UI

| VA | Focus |
|----|-------|
| `0x0089c6c0` | AddItem path |
| `0x00411900` | QuickBar activate helper |
| `0x0089ff80` | QuickBar helper |
| `0x00413a60` | hash unlink |
| `0x00413920` | hash insert |
| `0x007fbb70` | selection clear |
| `0x0085e590` | inventory item widget ctor |
| `0x0085f150` | place widget |
| `0x00860700` | inventory sheet rebuild |
| `0x004f1e20` | item def ensure |
| `0x005142a0` | store price gate |

## Physics / math / transform

| VA | Focus |
|----|-------|
| `0x0055e490` | physics world list |
| `0x0055eb80` | physics activate |
| `0x005d4440` | set body type |
| `0x005a5810` | HF bilinear |
| `0x004367f0` | dword vector resize |
| `0x0040d2a0` | SetPosition physics |
| `0x0076f6e0` | homogeneous transform |
| `0x0076f240` | mat4 helper |
| `0x00972e50` | basis rebuild |
| `0x0043f2e0` | ortho matrix |
| `0x0055e530` | cast terrain helper |

## Containers / HB / string

| VA | Focus |
|----|-------|
| `0x00508490` | list insert twin |
| `0x004e2ca0` | hash bucket unlink |
| `0x0051b870` | targeting vtbl |
| `0x0051b850` | targeting vtbl |
| `0x00604dd0` | targeting OnHeartBeat |
| `0x00404710` | POD copy |
| `0x0040c720` | toast grow |
| `0x00403980` | vector grow |
| `0x008f6030` | chat style |
| `0x007a6910` | locale ctor |
| `0x007a6890` | locale dtor |
| `0x007a6880` | get locale |

## Client input residual

| VA | Focus |
|----|-------|
| `0x0091d660` | random kick sibling |
| `0x00915670` | HB1 path |
| `0x0093a5c0` | focus-loss HB |
| `0x0093e120` | vehicle non-null path |

## Meta

Parent restamps ledgers. Terminal **false**. Dual 783 ≪ 25666.
