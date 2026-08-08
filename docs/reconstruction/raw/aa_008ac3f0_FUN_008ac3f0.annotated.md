# Annotated low-level: FUN_008ac3f0 → Client_NpcMissionDialogHost_Ctor_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_008ac3f0` |
| VA | `0x008ac3f0`–`0x008ac53f` (body **336 B** / `0x150`) |
| System | missions-progression (client NPC mission dialog host) |
| Date | 2026-08-05 (MEGA-107 dual seal) |
| Ghidra | `FUN_008ac3f0` |
| Meaningful name | `Client_NpcMissionDialogHost_Ctor_Inferred` |

## Machine-level notes

- **Role:** Constructor for the **NPC mission dialog host** object stored at **`client+0x1058`** (dialog table index 10). Alloc size **`0x748`**.
- **ABI:** Stack `this*` → **EDI**; base ctor gets `(this, 0)`; returns **EAX=this**; **`RET 4`**. Not ECX-thiscall for the outer frame (callees re-load `ECX=EDI`).
- **Vtable:** Installs **`0x00a4a51c`** (`PTR_FUN_00a4a51c`) — same class as Flush (`+0x440`) / BuildWidgets (`+0x43c`).
- **UI skin:** `NDUIWindow_ReloadInterface("i_d_npc.xml")` then builds response strip via dualed `UI_MissionDialog_BuildResponseButtons_Inferred` (`0x008ac110`), then virtual post-init `vtbl+0x34C` → `FUN_00791dc0`.
- Prefer assembly (`read_memory` body) when decompiler widths collide; CF is straight-line (no branches).

## Field map (this = EDI)

| Offset | Index | Init | Peer meaning |
|---|---|---|---|
| `+0x000` | — | vtbl `0x00a4a51c` | class identity |
| `+0x4FC` | `0x13f` | **0x0C** | chrome / dialog-type id |
| `+0x500` | `0x140` | **1** | flag |
| `+0x50C` | `0x143` | **0** (movss 0) | — |
| `+0x514` | `0x145` | **0** | — |
| `+0x580` | byte `@0x160` | **0** | BuildWidgets also clears this byte |
| `+0x584..+0x5B0` | `0x161..0x16c` | 3×(0,0,0,1) floats | UI transform / basis |
| `+0x5BC` | `0x16f` | **0** | response layout extra X (peer) |
| `+0x5C0` | `0x170` | **0** | response layout extra Y (peer) |
| `+0x63C` | 399 | **1** | layout flag |
| `+0x640` | 400 | **1** | response **columns** (min 1 in BuildResponseButtons) |
| `+0x648` | `0x192` | **0** | layout mode |
| `+0x704` | `0x1c1` | **0** | scrollbar pages peer field |
| `+0x72C..+0x734` | `0x1cb..0x1cd` | **0** | — |
| `+0x73C..+0x744` | `0x1cf..0x1d1` | **0** | (skips `0x1ce`) |

Plus bulk zero/init via `FUN_008ab0a0` (response slots, NPC ptr, list heads, etc. — callee OWN residual).

## Pseudocode (annotated)

```c
// Ghidra: FUN_008ac3f0
// MEGA-107: Client_NpcMissionDialogHost_Ctor_Inferred
// ABI: stack this* → EDI; RET 4; EAX = this
int * Client_NpcMissionDialogHost_Ctor_Inferred(int *self /* stack */)
{
  // SEH: LAB_009b645d
  FUN_0087b890(self, 0);                 // base NDUI window/host ctor (arg1=0)
  // install mission-dialog vtable
  *self = (int)&PTR_FUN_00a4a51c;        // 0x00a4a51c

  // 3×4 float basis @ +0x584: rows (0,0,0,1)
  // zeros @ +0x72C.. / +0x73C..
  self[0x13f] = 0xC;                     // +0x4FC
  self[0x140] = 1;                       // +0x500
  self[0x192] = 0;                       // +0x648 layout mode
  self[0x143] = 0;                       // +0x50C
  self[399] = 1;                         // +0x63C
  self[400] = 1;                         // +0x640 columns
  self[0x145] = 0;                       // +0x514
  *(uint8_t *)(self + 0x160) = 0;        // +0x580
  self[0x1c1] = 0;                       // +0x704
  self[0x170] = 0;                       // +0x5C0
  self[0x16f] = 0;                       // +0x5BC

  FUN_008ab0a0();                        // ECX=self — zero mission-dialog fields
  NDUIWindow_ReloadInterface("i_d_npc.xml");
  FUN_008ac110();                        // EDI-this response buttons (dualed)
  (*(code **)(*self + 0x34c))();         // ECX=self → FUN_00791dc0
  return self;                           // RET 4
}
```

## Call graph (OWN unit only)

```
FUN_0093e7e0  (client UI subsystem ctor table)
  operator_new(0x748)
  └─ FUN_008ac3f0  Client_NpcMissionDialogHost_Ctor_Inferred  [MEGA-107 OWN]
        ├─ FUN_0087b890(self, 0)          base host
        ├─ *self = vtbl 0x00a4a51c
        ├─ field defaults (matrix, columns=1, mode=0, id=0xC, …)
        ├─ FUN_008ab0a0()                 field zero pack
        ├─ NDUIWindow_ReloadInterface("i_d_npc.xml")
        ├─ FUN_008ac110                   UI_MissionDialog_BuildResponseButtons_Inferred [dualed]
        └─ vtbl+0x34C → FUN_00791dc0      post-XML virtual

Host slot: client+0x1058
Class methods (not this body): BuildWidgets +0x43c, Flush +0x440, …
```

## Open questions

- Product / PDB class name for vtable `0x00a4a51c`.
- Exact English for base `FUN_0087b890` and virtual `FUN_00791dc0` (not OWN).
- Runtime confirmation of host lifetime vs HideMissionDialogIfOpen (`+0x107c` sibling).
