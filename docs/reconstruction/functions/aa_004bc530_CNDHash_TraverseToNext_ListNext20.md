# Function record: CNDHash_TraverseToNext_ListNext20

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bc530` |
| **Canonical name** | `CNDHash_TraverseToNext_ListNext20` |
| **Prior scaffold** | `FUN_004bc530` |
| **Rejected misname** | `Named_VOG_DEBUG_STOP_004bc530` (assert-string false product id) |
| **Address** | `0x004bc530`–`0x004bc57d` inclusive (**78 B** / `0x4E`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / CNDHash |
| **Agent** | MEGA-029 OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B **accept-with-gaps** — CF/ABI/layout sealed; stamp/runtime open) |
| **Terminal** | **false** (runtime open) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

MSVC-era **CNDHash::TraverseToNext** for the **0x28-class / list-next@+0x20** node family. Walks the hash's ordered list under a held **TraversalLock** (`this+0x1d`), updating an external cursor and returning each node's **payload** at `+0x0c`.

```text
CNDHash_TraverseToNext_ListNext20(hash, &cursor) -> payload|0
  if !hash.lockedForTraversal: log HashError:TraverseToNext…; // continue
  if cursor==0: cursor = hash.listHead (+0x14)
  else:         cursor = cursor->listNext (+0x20)
  return cursor ? cursor->payload (+0xc) : 0
```

String-sealed operation name (`HashError:TraverseToNext, not locked for traversal` @ `0x00a27c9c`). Layout suffix **ListNext20** disambiguates from dualed skill-family twin `CNDHash_TraverseToNext` `0x00411900` (next+0x14 / payload+8).

## Signature (decompiler + bytes)

```c
// __thiscall; RET 4
// ECX = CNDHash* this; stack = node** cursor; EAX = payload|0
uint32_t __thiscall CNDHash_TraverseToNext_ListNext20(
    CNDHash *this,
    uint32_t *cursor);
```

| Item | Value |
|---|---|
| Lock byte | `this+0x1d` (read-only check) |
| List head | `this+0x14` |
| Node next | `node+0x20` |
| Node payload | `node+0x0c` |
| Cleanup | `RET 4` ×2 exits |
| Log callee | `FUN_007a4480` (cdecl) |

## Artifacts

- Raw scaffold + re-verify: `docs/reconstruction/raw/aa_004bc530_FUN_004bc530.md`
- Annotated: `docs/reconstruction/raw/aa_004bc530_FUN_004bc530.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CNDHash_TraverseToNext_ListNext20.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004bc530.cpp`
- Retired misname: `docs/reconstruction/reconstructed-exact/Named_VOG_DEBUG_STOP_004bc530.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_004bc530_CNDHash_TraverseToNext_ListNext20.md`
- Dual B: `docs/reconstruction/reviews/B_aa_004bc530_CNDHash_TraverseToNext_ListNext20.md`
- FUN_ record: `docs/reconstruction/functions/aa_004bc530_FUN_004bc530.md`
- Report: `docs/agents/task-dual-ab-004bc530-mega-029-report.md`

## Callers / callees

| Direction | Symbol | Notes |
|---|---|---|
| Callee | `FUN_007a4480` | unlocked-path log ×2 |
| Caller | `FUN_004bae00` | sole; sites `0x004bae24` (hash@+4), `0x004bae4e` (hash@+8) |
| Lock setter | `FUN_00402c40` | parent calls before this; string `HashError:TraversalLock…` |
| Twin | `CNDHash_TraverseToNext` `0x00411900` | next+0x14 / payload+8 — **do not merge** |

## Family

| Sibling | Role |
|---|---|
| `CNDHash_TraverseToNext` `0x00411900` | same product op; **0x1c-node** layout |
| `FUN_00402c40` | TraversalLock set |
| `FUN_004bae00` | dual-hash lock/traverse/unlock shell |
| CNDHash Alloc/Ctor/Free at `004bc7a0+` | same region; stamp-disambiguated siblings |

## Confidence

| Claim | Level |
|---|---|
| Control flow | **Confirmed** |
| `__thiscall` + `RET 4` | **Confirmed** |
| Product role TraverseToNext | **Confirmed** (string) |
| Layout next+0x20 / payload+0xc | **Confirmed** |
| Reject VOG_DEBUG_STOP misname | **Confirmed** |
| Distinct from twin `00411900` | **Confirmed** |
| Exact COList stamp English | **Tentative** |
| Runtime / bit-exact | **Open** |
