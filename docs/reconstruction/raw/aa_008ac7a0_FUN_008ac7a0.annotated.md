# Annotated low-level: FUN_008ac7a0 → Client_MaybeShowMultiActiveMissionTip_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_008ac7a0` |
| VA | `0x008ac7a0`–`0x008ac884` (228 B) |
| System | `missions-progression` |
| Date | 2026-08-04 (WQ7R-A residual seal; supersedes 2026-07-23 scaffold notes) |
| Ghidra | `FUN_008ac7a0` |
| Inferred name | `Client_MaybeShowMultiActiveMissionTip_Inferred` |

## Machine-level notes

- **Role:** After mission accept, walk the character **active-mission instance hash** (`char/global +0x540`) under traversal lock and, if **more than one** qualifying payload is present, fire first-time tip **`0x20`**.
- **Not** a dialog-list refresh (older HandleButton comment was wrong). **Not** a network send. **Not** GiveMission/CompleteObjective.
- Prefer live decompile + `read_memory` for CF; preserve exact predicate pair on payload `+0xf8` / `+0xfc`.
- Product English for tip `0x20` and field `+0xf8/+0xfc` is **open** → `_Inferred` name.

## ABI

| Slot | Role |
|------|------|
| Formals | none |
| Return | void; plain `ret` (`C3`) |
| Globals | `DAT_00d1b6d8` (client/character singleton), tip this `DAT_00d1a840` |

## Offsets (body-backed)

| Site | Offset | Use |
|------|--------|-----|
| Singleton | `+0xd34` bit0 | Early gate: must be clear to proceed |
| Singleton | `+0x540` | Active mission **hash** root |
| Hash | `+0x1d` | Traversal lock byte (set 1 / clear 0) |
| Hash | `+0x14` | First walk node (null-terminated chain) |
| Node | `+0x14` | Next walk node |
| Node | `+0x8` | Payload pointer (mission instance) |
| Payload | `+0xf8` (short) | Qualifier: must be **0** to count |
| Payload | `+0xfc` (int) | Qualifier: must be **≠ −1** to count |

**Probable (not sealed product English):** tip id `0x20` uses FirstFlags dword index `1` bit `0` at `char+0xd30+4` = `+0xd34` bit0 — same bit as the early gate if `DAT_00d1b6d8` is the character. Treat as co-located FirstFlags bit, not independently proven here.

## Pseudocode (annotated)

```c
// Client_MaybeShowMultiActiveMissionTip_Inferred  @ 0x008ac7a0
// Called from Client_MissionDialogHandleButton accept-offer path
// after GiveMission + Hide + MaybeShowFirstTimeTip(2).
void Client_MaybeShowMultiActiveMissionTip_Inferred(void)
{
  // Gate: live singleton + flag bit0 clear
  if (DAT_00d1b6d8 == 0) return;
  if ((*(unsigned char*)(DAT_00d1b6d8 + 0xd34) & 1) != 0) return;

  int* hash = *(int**)(DAT_00d1b6d8 + 0x540);
  int count = 0;
  int* node = 0;

  // TraversalLock enter (HashError strings if re-entrant)
  if (*(char*)((char*)hash + 0x1d) != 0) {
    FUN_007a4480(0, "HashError:TraversalLock, already locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }
  *(unsigned char*)((char*)hash + 0x1d) = 1;

  while (true) {
    hash = *(int**)(DAT_00d1b6d8 + 0x540);
    if (*(char*)((char*)hash + 0x1d) == 0) {
      FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
      FUN_007a4480(0, "VOG_DEBUG_STOP");
    }
    // first: hash+0x14; next: node+0x14
    node = (node == 0) ? *(int**)((char*)hash + 0x14)
                       : *(int**)((char*)node + 0x14);
    int* payload = (node == 0) ? 0 : *(int**)((char*)node + 8);
    if (payload == 0) break;

    // Qualifying active instance: short@+0xf8==0 && int@+0xfc!=-1
    if (*(short*)((char*)payload + 0xf8) == 0 &&
        *(int*)((char*)payload + 0xfc) != -1) {
      count++;
    }
  }

  // unlock
  *(unsigned char*)(*(char**)(DAT_00d1b6d8 + 0x540) + 0x1d) = 0;

  // tip only when 2+ qualify (bytes: cmp ebx,2 / jl skip)
  if (count >= 2) {
    // thiscall: ECX = DAT_00d1a840, stack tipId = 0x20
    Client_MaybeShowFirstTimeTip(/*this*/ DAT_00d1a840, 0x20);
  }
}
```

## Call graph

```
Client_MissionDialogHandleButton  (state1 accept, button0, GiveMission path)
  → Client_MaybeShowFirstTimeTip(2)     // "first mission" tip family
  → Client_MaybeShowMultiActiveMissionTip_Inferred  // THIS
       → walk char+0x540
       → maybe Client_MaybeShowFirstTimeTip(0x20)
```

## Open questions

- Product English for tip id `0x20` string table.
- Exact type of payload object (mission instance vs def); product names for `+0xf8` / `+0xfc`.
- Whether gate `+0xd34` bit0 is *only* tip-0x20 FirstFlags or a broader flag word.
- Runtime / bit-exact.
