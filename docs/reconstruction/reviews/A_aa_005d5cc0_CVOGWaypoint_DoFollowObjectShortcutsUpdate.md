# Review A (reconstruction fidelity): `aa_005d5cc0` CVOGWaypoint_DoFollowObjectShortcutsUpdate

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d5cc0` |
| **VA** | `0x005d5cc0`–`0x005d62fb` (**1596 B** / `0x63C`) |
| **Canonical name** | `CVOGWaypoint_DoFollowObjectShortcutsUpdate` |
| **Ghidra name** | `FUN_005d5cc0` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY MEGA-057) |
| **Counterpart** | `reviews/B_aa_005d5cc0_CVOGWaypoint_DoFollowObjectShortcutsUpdate.md` |
| **System** | skills-abilities / waypoint path AI |
| **Evidence pass** | Live `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

`CVOGWaypoint` FSM **state-2** handler: resolve follow-object TFID at `this+0x30`, cast to physics, measure surface distance owner↔target, maintain path/shortcut COIDs at `+0x40/+0x44/+0x48`, and write desired pose float4 at `+0x20..+0x2c`. Product plate string sealed.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-057 append) | `docs/reconstruction/raw/aa_005d5cc0_FUN_005d5cc0.md` |
| Annotated | `docs/reconstruction/raw/aa_005d5cc0_FUN_005d5cc0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGWaypoint_DoFollowObjectShortcutsUpdate.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005d5cc0.cpp` |
| Function FUN | `docs/reconstruction/functions/aa_005d5cc0_FUN_005d5cc0.md` |
| Function named | `docs/reconstruction/functions/aa_005d5cc0_CVOGWaypoint_DoFollowObjectShortcutsUpdate.md` |
| Sole caller | `CVOGWaypoint_UpdateState` @ `0x005d6300` case 2 (`0x005d6353`) |
| Plate string | `"CVOGWaypoint::DoFollowObjectShortcutsUpdate"` @ `0x009dace4` |

---

## 3. Signature

```c
// Ghidra residual: void __fastcall FUN_005d5cc0(int param_1)
// Bytes: MOV ESI,ECX; … POP EBP; RET
void __thiscall CVOGWaypoint_DoFollowObjectShortcutsUpdate(CVOGWaypoint *this);
```

| Item | Evidence | Conf |
|---|---|---|
| thiscall ECX=this | `MOV ESI, ECX` @ `005d5ce7` | **High** |
| No stack args; RET 0 | epilogue `RET` @ `005d62fb` | **High** |
| void return | no EAX produce; void semantics | **High** |
| SEH present | push `-1`; push `0x9a7110`; FS:[0] | **High** |
| Body range | `get_function_by_address` `005d5cc0–005d62fb` | **High** |

---

## 4. Control flow (sealed)

1. Scope enter with product plate string via `FUN_0076cf00`.
2. Resolve TFID `this+0x30` → follow object (via owner map → `Object_ResolveFromTFID`).
3. Null **or** flag bit5 at `obj+0x17c` clear → `+0x52=0` → unscope.
4. Else `+0x52=1`; RTDynamicCast → `CVOGPhysicsBase`.
5. Load target pose float4 (rb `+0xb0` / entity `+0x84` dual).
6. Load owner pose from `*(this+0x10)` same dual.
7. `Object_SurfaceDistance3D_Inferred(owner, target)` — **ECX=owner** (byte seal).
8. Compare dist to `+0x4c` → set `+0x53`.
9. If `dist < 1.0f`: copy target pose → `+0x20..+0x2c` → unscope.
10. If path COID pair valid (`(+0x40)&(+0x44) != −1`):
    - `FUN_005d5960(this)`;
    - normalize (target−owner_world) and (saved_pose−owner_world);
    - if **dot < 0.2f**: clear `+0x40/44/48` to −1; snap pose from **target** world pos;
    - unscope.
11. Else gather shortcuts (`FUN_004d5910`); pick nearest candidate within `dist²` both ways; store COID `obj+0x134` → `+0x40/44`; vtbl+0x10 / +0x2c for secondary id + pose; or snap to target if empty/no pick.
12. Free vector; unscope `FUN_0076cef0`; return.

| Stage | Match | Conf |
|---|---|---|
| Plate string + SEH scope | **Yes** | **High** |
| TFID resolve + flag +0x52 | **Yes** | **High** |
| Physics cast + dual pose load | **Yes** | **High** |
| Surface distance + +0x53 / 1.0 snap | **Yes** | **High** |
| Path-active dir-dot 0.2 clear | **Yes** | **High** |
| Shortcut gather/pick/COID | **Yes** (callee residual) | **High** CF / **Med** English |
| Sole caller state-2 | **Yes** | **High** |

---

## 5. Machine bytes / constants (`read_memory` + disasm)

| Addr / site | Role |
|---|---|
| `005d5ce7` | `MOV ESI, ECX` this |
| `005d5ce9` | push string `0x9dace4` |
| `005d5d1d` | `CALL Object_ResolveFromTFID` |
| `005d5d4f` | `CALL __RTDynamicCast` |
| `005d5def` | `CALL Object_SurfaceDistance3D` (ECX=owner) |
| `005d5e0b` | `COMISS` vs `g_flOne` @ `00a0f2a0` = **1.0f** |
| `005d5e5c` | `CALL FUN_005d5960` (path-active) |
| `005d5fe4` | `COMISS` vs `DAT_00a0f70c` = **0.2f** |
| `005d60b5` | `CALL FUN_004d5910` (gather) |
| `005d61a5` | load COID `[EBX+0x134]` |
| `005d62fb` | `RET` |
| string `009dace4` | `CVOGWaypoint::DoFollowObjectShortcutsUpdate\0` |
| `_DAT_009dace0` | **1e7f** min-dist init |

---

## 6. Gaps / open

1. Product English for residual callees `FUN_004d5910` (shortcut gather) and `FUN_005d5960` (state-1 peer).
2. Candidate object class for vtbl `+0x10` / `+0x2c` / field `+0x134` COID (structural only).
3. Full meaning of object flag `+0x17c` bit 5 (usable-follow gate).
4. Exact owner-map walk into `Object_ResolveFromTFID` / `FUN_004d5910` this-arg (CF sealed; English open).
5. Runtime / bit-exact / differential — open (Terminal **false**).

---

## 7. Verdict

CF/ABI/plate/caller/constants sealed; residual callee product English and candidate class → **accept-with-gaps**.
