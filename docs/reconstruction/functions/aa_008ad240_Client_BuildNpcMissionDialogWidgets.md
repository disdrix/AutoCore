# Function record: Client_BuildNpcMissionDialogWidgets

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ad240` |
| **Canonical name** | `Client_BuildNpcMissionDialogWidgets` |
| **Address** | `0x008ad240` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Calling convention** | MSVC `__thiscall` / decompiler `__fastcall` (`this` in ECX → EDI) |
| **Completion status** | **Human-refined** — dual A/B residual 2026-07-29: **construct-only `+0x650` zero sealed High (UF-011)** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Construct the full NPC mission dialog widget tree (`i_d_npc_2d_*.xml` rewards, dialogue, item slots, close). At entry, **zeros the prepared MissionDialogResponse buffer** at `dialog+0x650` (size **0x20**). Heavy MSXML — must not race CompleteObjective / interact FX after turn-in.

## Signature (refined)

```c
void __fastcall Client_BuildNpcMissionDialogWidgets(int *pDialog /* this */);
```

## Prepared buffer zero (UF-011)

| Item | Value |
|---|---|
| First store | `*(uint32*)(dialog + 0x650) = 0` |
| Range | `dialog+0x650` .. `dialog+0x66c` (**8 dwords**) |
| Byte length | **`0x20`** — matches Flush send size |
| Decomp form | `param_1[0x194..0x19b] = 0` (`0x194 * 4 = 0x650`) |
| Image form | `XOR EAX,EAX; LEA ECX,[EDI+0x650]; MOV [ECX+i],EAX` for `i=0,4,…,0x1C` |
| Extra | `*(uint8*)(dialog + 0x580) = 0` (`param_1 + 0x160`) |
| When | **Widget construct only** — not cancel-close, not post-Flush |
| Relation | UF-011 **sealed High**: cancel can flush **unfilled** `0x206E` because this zero is **not** on the close path |

```
BuildWidgets (vtbl+0x43c)  --zero-->  +0x650..+0x66c
Prepare-on-show            --stamp-->  +0x650 = 0x206E
HandleButton state1        --fill-->   body (+0x654..)
Flush (vtbl+0x440)         --send-->   0x20 bytes if opcode ≠ 0  (no clear)
```

## Object / vtable

| Item | Value |
|---|---|
| Host field | client **`+0x1058`** (dialog index 10) |
| Vtable base | **`0x00a4a51c`** |
| This method | **`vtbl+0x43c`** → DATA `0x00a4a958` = `0x008ad240` |
| Adjacent Flush | **`vtbl+0x440`** → `0x008ab8f0` |
| Body xrefs | **DATA only** `0x00a4a958` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008ad240_Client_BuildNpcMissionDialogWidgets.md`
- Annotated: `docs/reconstruction/raw/aa_008ad240_Client_BuildNpcMissionDialogWidgets.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_BuildNpcMissionDialogWidgets.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_008ad240_Client_BuildNpcMissionDialogWidgets.md`
- Dual B: `docs/reconstruction/reviews/B_aa_008ad240_Client_BuildNpcMissionDialogWidgets.md`
- Peer Flush / UF-011: `docs/reconstruction/functions/aa_008ab8f0_Client_MissionDialog_FlushPreparedResponse.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| `+0x650` zero span / size `0x20` | **High** (image + decomp) |
| UF-011 construct-only clear site | **High (static)** |
| Vtable `+0x43c` placement | High |
| Packet send / mission mutation | **None** (UI only) |
| Full child English map | Medium / residual |
| Types / product names | Probable |
