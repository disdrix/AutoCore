# Annotated low-level: Client_QuickBarActivateSkillSlot (`aa_00921b50`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00921b50` |
| **VA** | `0x00921b50` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **System** | skills-abilities |
| **Source raw** | `aa_00921b50_Client_QuickBarActivateSkillSlot.md` (capture 2026-07-23) |
| **Related** | Builds same C2S `0x2030` as `Client_RequestCastSkill`; also called from DriveControlTick secondary path |

---

## 1. Corrected signature

```c
void Client_QuickBarActivateSkillSlot(char nSlotIndex);
// Uses globals: DAT_00d1b6d8 (local character/world root), g_pSectorNetConnection_INFERRED
```

| Name | Width | Role |
|---|---|---|
| `nSlotIndex` | i8 / char | Zero-based quick-bar slot among **non-hidden** skills (`skill+0x615 & 1` skips counting) |

---

## 2. High-level algorithm

```text
1. Resolve local character from DAT_00d1b6d8 → +0xa4 → vtbl+0x1d8
2. Snapshot aim/source TFID-like block from character interior +0x164.. or override from +0xa4 object +0x160..
3. Traverse skill linked list at character interior +0x74:
     - set traversal lock byte list+0x1d = 1 (debug assert if already locked)
     - skip entries with (skill+0x615 & 1) != 0
     - count visible skills until count == nSlotIndex
     - clear lock
4. if skill found AND Skill_LocalCastValidate(character, 0, skill, 0) == 0:
     a. skillId = skill+0x5fc
     b. if world+0x7e == 0: ClearActiveCast + maybe StartCastAgainHeartbeat
     c. if charge (skill+0x14) != 0: vtbl+0x238 activating presentation
     d. build packet 0x2030:
          skillId @ +0x18
          TFID from Client_Skill_ResolveCastTarget(..., aim snapshot, DAT_00d1a640, 1)
          aim XYZ often zeroed then partially filled from resolve side outputs
     e. send via g_pSectorNetConnection->vtbl+0x18(0xFFFFFFFF, buf, 0x28, 0)
     f. optional FUN_0089ff80 if DAT_00d1b8f0 UI flag
```

---

## 3. Packet notes (Confirmed / plate)

Same layout as RequestCast path:

| Offset | Field |
|---|---|
| `+0x00` | `0x2030` |
| `+0x04` | pad |
| `+0x08` | TFID 16B from resolve |
| `+0x18` | `skill+0x5fc` |
| `+0x1C` | aim XYZ (often 0 on pure hotbar press) |

**Assembly caveat (plate):** after `PUSH` size/flag, `LEA` of buffer forces ESP recompute — opcode dword sits **8 bytes before** the resolved TFID dword[0] in the stack frame. Annotated layout above is **logical** packet order at send time.

Send path differs from `Client_RequestCastSkill`:

| Path | Send helper |
|---|---|
| RequestCast | `Client_SendSectorPacket(client, 0x28, buf)` |
| QuickBarActivate | `conn->vtbl+0x18(-1, buf, 0x28, 0)` on `g_pSectorNetConnection_INFERRED` |

---

## 4. Traversal lock

```text
list = *(character_interior + 0x74)
if list+0x1d already 1: HashError:TraversalLock debug strings
list+0x1d = 1
... walk via node+0x14 next, node+0x8 skill ptr ...
list+0x1d = 0
```

**Side effect:** temporary lock byte only; must clear even if early conditions fail after lock (function clears after walk).

Slot indexing **skips** skills with `*(u8*)(skill+0x615) & 1` — hidden/passive bar filter **Probable**.

---

## 5. Side-effect order

1. Global character resolve.
2. Read aim/TFID snapshot fields.
3. List lock → walk → unlock.
4. LocalCastValidate.
5. Optimistic CD heartbeat (if world flag allows).
6. Optional activating VFX call.
7. Resolve TFID + **network send 0x28**.
8. Optional UI refresh `FUN_0089ff80`.

Does **not** call `Client_RequestCastSkill` — **parallel builder** of the same opcode.

---

## 6. Field map

| Offset | Object | Role |
|---|---|---|
| `DAT_00d1b6d8` | global | local player / world object root |
| root `+0xa4` | link | vehicle/target helper for vtbl+0x1d8 |
| char interior `+0x74` | list head | skill hash/list with lock at `+0x1d` |
| char interior `+0xa8` → `+0x7e` | world flag | suppress optimistic HB when nonzero |
| skill `+0x5fc` | skill id | packet |
| skill `+0x615` bit0 | filter | excluded from slot index |
| skill `+0x14` | charge ms | heartbeat / VFX |
| skill `+0x61c` | gate | blocks StartCastAgain when set |

---

## 7. Callers (sealed 2026-07-29 dual residual)

| Caller | Sites | Arg |
|---|---|---|
| `Client_QuickBar_ActivateSlot` `0x009436c0` | `0x00943725`, `0x0094374a` | `'\0'` / `'\x01'` when on-foot `entity+0x6b9` |
| `Client_Input_DriveControlTick` `0x009223b0` | `0x009234e2`, `0x00923546` | same literals under drive/host gates |

**Not** the ActivateSlot type-1 path (that calls `Client_CastSkillFromQuickBarSlot(skillId)` → `RequestCastSkill`).

`nSlotIndex` is the Nth skill with `(skill+0x615 & 1) == 0` in the list at entity `+0x74` — **not** the persisted quick-bar skill-id table (`client+0x3220` / `character_quickbar`).

## 8. Open questions

- Exact type of list at `+0x74` (hash vs intrusive list).
- Aim residual: body zeros `uStack_14/18/1c` then copies **never-written** `uStack_60/5c/58` — decomp hazard; do not port as authored zeros.
- Full identity of `DAT_00d1a640` aim default and `DAT_00d1b8f0` UI object.
- Product name for `skill+0x615` bit0 (hidden/passive filter — CF sealed).
