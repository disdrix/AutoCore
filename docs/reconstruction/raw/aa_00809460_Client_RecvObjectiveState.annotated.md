# Annotated low-level: Client_RecvObjectiveState (`aa_00809460`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00809460` |
| **VA** | `0x00809460` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **System** | missions-progression |
| **Source raw** | `aa_00809460_Client_RecvObjectiveState.md` (capture 2026-07-23) |
| **Opcode** | **S2C `0x2071`** (progress only; not force-complete) |

This file is the **annotated** layer: widths, signedness, branch order, side effects, and decompiler corrections. It does not replace the immutable raw capture.

---

## 1. Corrected signature

```c
// Packet handler; client object often in EAX (decompiler in_EAX)
void Client_RecvObjectiveState(ObjectiveStatePacket* pkt /* param_1 */);
```

| Name | Width | Signedness | Origin | Role |
|---|---|---|---|---|
| `param_1` / pkt | 32-bit pointer | unsigned | stack/arg | Packet buffer |
| `in_EAX` | 32-bit pointer | unsigned | `EAX` | Client / game context object |
| return | void | — | — | — |

### Packet layout (byte offsets on `param_1`)

| Offset | Width | Role |
|---|---|---|
| `+0x10` | **u32** | Bitmask of which evaluator slots fire `vtable+0x20` |
| `+0x14` | **u32** | Objective id (hash key into pending `char+0x55c`) |
| `+0x18` | **u32 / f32 bits** | Progress slot 0 → `node[1]` |
| `+0x1c` | **u32 / f32 bits** | Progress slot 1 → `node[2]` |
| `+0x20` | **u32 / f32 bits** | Progress slot 2 → `node[3]` |
| `+0x24` | **u32 / f32 bits** | Progress slot 3 → `node[4]` |

Slots stored as raw dwords (**IEEE float** bit patterns; **no conversion**). Absolute counts for UseItem/Kill/Patrol; 0..1 ratios for other types (Eval consumers).

---

## 2. Decompiler corrections

| Decompiler artifact | Correction | Confidence |
|---|---|---|
| `in_EAX + 0xe98` | Local player / character pointer on client object | **Probable** |
| `character + 0x55c` | Pending objective runtime hash | **High** |
| `piVar4[1..4]` stores | Four progress fields on **runtime objective node** | **High** |
| `in_EAX + 0x107c` | Mission UI root; vtable probes `+0x3d8`, `+0x448`, `+0x34c` | **High** (role); class name open |
| Evaluator array on `*piVar4` def `+0x158/+0x15c` | Same as AddActiveObjective / EvaluatePending | **High** |
| Bit test `(mask & (1 << (slot & 31)))` | Per-requirement dispatch of **shared** `vtable+0x20` = `FUN_00637de0` progress toast | **High** |
| `vtable+0x20` identity | **Not** event Action (`+0x04`) / Eval (`+0x08`/`+0x10`) / SlotAction (`+0x18`); toast via `+0x1c`→SlotAction text + `FUN_0040c5c0` | **High** residual strengthen |
| `FUN_0092ce90` | `Client_RefreshMissionRelatedUi` — mission panel refresh; not EvaluatePending | **High** (role) |
| `*(client+0x4d0)+4 = 1` | Dirty UI flag on active-mission tracker object | **High** (dirty); product name open |
| Slot dwords | IEEE **float** bit patterns (absolute or 0..1 by type) | **High** residual 2026-07-29 |

**Does NOT** call `CompleteObjective` — progress only. Distinct from opcode **`0x2070`** force-complete path (not this unit).

---

## 3. Control flow

```text
char = *(client + 0xe98)
if char == 0: return
node = Lookup(char+0x55c, pkt.objectiveId)
if node == 0: return

node.slot0..3 = pkt floats/dwords at +0x18..+0x24

if ui = *(client+0x107c):
  if ui.vtable[+0x3d8](): ui[+0x448](); ui[+0x34c]()

for i = 0 .. requirementCount-1:
  if pkt.mask & (1u << i):
    req[i].vtable[+0x20](char, node)   // == FUN_00637de0 shared toast

FUN_0092ce90()
*( *(client+0x4d0) + 4 ) = 1
```

| Branch | Effect |
|---|---|
| No character / no objective node | Silent no-op |
| Mask bit clear | Skip that requirement's progress toast |
| Success | Progress written + optional UI + dirty flag |

---

## 4. Side-effect order

1. Hash lookup (read).
2. **Four dword stores** on runtime node.
3. Optional UI vtable pair.
4. Bit-selected shared progress toast (`vtbl+0x20` = `FUN_00637de0`).
5. `FUN_0092ce90` + dirty byte.

---

## 5. Open questions

- ~~Exact float vs int interpretation of the four slots~~ **Sealed High** — IEEE float bits; absolute for UseItem/Kill/Patrol; ratio for others (residual `reviews/a_00809460.md` 2026-07-29).
- ~~What `vtable+0x20` is per type~~ **Sealed High** — shared `FUN_00637de0` progress toast across Collect/UseItem/Patrol/Kill (+10 more DATA slots); not event Action/Eval/SlotAction.
- Full opcode `0x2071` header (fields before `+0x10`).
- ~~Identity of `FUN_0092ce90`~~ **Sealed High** role as mission UI refresh; original PDB open. UI `+0x107c` sealed as mission UI root (class name open).
- ~~Whether EvaluatePendingObjectives is scheduled after this dirty flag~~ **Sealed High — no.**
- Product names for toast helpers / widget classes; type 7/8 toast-skip enum confirmation.
