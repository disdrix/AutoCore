# Review A (reconstruction fidelity): `aa_00929ec0` Client_EvalAutoPatrolWaypoint

| Field | Value |
|---|---|
| **Stable ID** | `aa_00929ec0` |
| **VA** | `0x00929ec0` |
| **Canonical name** | `Client_EvalAutoPatrolWaypoint` |
| **Scaffold alias** | `identity` (raw/clean slug — **not** CRT `identity`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00929ec0_Client_EvalAutoPatrolWaypoint.md` |
| **System** | `missions-progression` / client AutoPatrol |
| **Live tools** | Ghidra `decompile_function` + `read_memory` + callers/callees (no `disassemble_bytes`) |
| **Verdict** | **accept** (game CF + C2S 0x20B3 path sealed High; some layout Probable) |

---

## 1. Purpose

Client mission **patrol waypoint evaluator**:

1. Index into patrol manager waypoint vector (`+0x11c` begin / `+0x120` end, pointer stride 4).
2. Resolve waypoint object TFID; refresh cached XYZ from object `+0x80/+0x84/+0x88` (indices 0x20–0x22).
3. Optionally emit **C2S AutoPatrol** opcode **`0x20B3`**, packet size **`0x18`**, via `Client_SendSectorPacket` when AutoPatrol flag `manager+0x102` is set and player is within distance threshold `manager+0x104`.
4. Always write out-params: waypoint TFID (16 bytes) and position float3 — or **invalid TFID sentinel** from `DAT_00a158a0..ac` on failure paths.

**Not** CRT identity / not a no-op. Scaffold name `identity` is a mis-slug; Ghidra symbol is already `Client_EvalAutoPatrolWaypoint`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00929ec0_identity.md` |
| Annotated | `docs/reconstruction/raw/aa_00929ec0_identity.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/identity.cpp` |
| Function record | `docs/reconstruction/functions/aa_00929ec0_identity.md` |
| Live decompile | Ghidra `Client_EvalAutoPatrolWaypoint` (2026-07-29) |
| Live entry | `read_memory` @ `0x00929ec0` |
| Related duals | `A_aa_009197a0_Client_FindFirstObjectInRadius`, packet notes on `Client_SendSectorPacket` |

---

## 3. Seal: entry / formals

`read_memory` @ `0x00929ec0`:

```
00929ec0  55              push ebp
00929ec1  8B EC           mov  ebp, esp
00929ec3  83 E4 F0        and  esp, -16       ; 16-byte align
00929ec6  83 EC 24        sub  esp, 0x24
00929ec9  53              push ebx
00929eca  8B 5D 08        mov  ebx, [ebp+8]   ; patrolManager
00929ecd  8B 0B           mov  ecx, [ebx]
00929ecf  83 B9 98 0E 00 00 00  cmp dword [ecx+0xE98], 0
00929ed6  56              push esi
00929ed7  57              push edi
00929ed8  8B F0           mov  esi, eax       ; waypoint index from EAX
```

Hex: `558bec83e4f083ec24538b5d088b0b83b9980e00000056578bf0…`

| Claim | Evidence | Conf |
|---|---|---|
| Stack formals: mgr, outTfid, outPos | `[ebp+8]`… decomp + clean | **High** |
| **EAX = waypoint index** (extra register formal) | `mov esi, eax` immediately | **High** |
| Early null player/context via `*(mgr+0)+0xe98` | cmp at entry | **High** |
| `__cdecl`-like stack cleanup (no `ret n` in decomp) | plate + callers | **High** |
| Real game code (not CRT) | plate, callees, opcode path | **Confirmed** |

---

## 4. Control flow stages (clean ≡ raw ≡ live)

| Stage | Behavior | Conf |
|---|---|---|
| A | If `*( *mgr + 0xe98 ) == 0` → write invalid TFID to out, return | **High** |
| B | If index &lt; 0 or index past vector length → invalid TFID out, return | **High** |
| C | `pEntry = *(begin + index)` TFID* at vector | **High** |
| D | If `mgr+8` flag set: distance check vs player using **cached** pos on entry; may set `mgr+4=1`; copy pos + TFID out; return | **High** |
| E | Else `Object_ResolveFromTFID(pEntry)` | **High** |
| F | Gate object “owner/map” slot `obj[0x2b]` vs player-derived id; vtbl `+0x198` / `+0x144` | **Probable** (offsets High, English Medium) |
| G | Refresh entry cached pos from `obj+0x80..88`; write out pos | **High** |
| H | If `mgr+0x102` AutoPatrol enabled and dist &lt; `*(float*)(mgr+0x104)`: build packet, `Client_SendSectorPacket(*mgr, 0x18, &pkt)` | **High** |
| I | Packet: dword0 = **0x20B3** (decomp float bit-pattern `1.17303e-41`), pad, TFID from `obj+0x160` (indices 0x58–0x5b) | **High** |
| J | Success: copy entry TFID → out | **High** |
| K | Failure after resolve: zero entry TFID to sentinel, set `mgr+4=1`, invalid out | **High** |

---

## 5. Callees / callers

**Callees (Ghidra):**

| VA | Name |
|---|---|
| `0x004bb950` | `Object_ResolveFromTFID` |
| `0x00807460` | `Client_SendSectorPacket` |

**Callers:**

| VA | Name | Role |
|---|---|---|
| `0x009197a0` | `Client_FindFirstObjectInRadius` / `FUN_009197a0` | prefer AutoPatrol waypoint in radius |
| `0x00919ae0` | `FUN_00919ae0` | sibling radius/query |
| `0x00851630` | `FUN_00851630` | mission/client path |
| `0x00859bc0` | `FUN_00859bc0` | mission/client path |
| `0x008a8770` | `FUN_008a8770` | UI/client path |

Xrefs include `0x00919843`, `0x00919b42`, `0x008518a0`, `0x0085a090`, `0x008a8c5f`, `0x00956f3d`.

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Name `Client_EvalAutoPatrolWaypoint` | **High** | Ghidra symbol + plate + sibling duals |
| Scaffold `identity` is wrong product name | **Confirmed** | not CRT identity |
| C2S opcode **0x20B3** size **0x18** | **High** | plate + packet notes + decomp |
| Not in `Client_PacketDispatch` (C2S only) | **High** | dispatch comments elsewhere |
| Manager layout +0x11c/+0x120 vector | **High** | entry bytes + decomp |
| AutoPatrol enable +0x102, range +0x104 | **High** | decomp |
| Invalid TFID = `DAT_00a158a0` block | **High** | shared sentinel pattern |
| vtbl +0x198 / +0x144 English meaning | **Probable** | offsets sealed |
| Full patrol entry struct product names | **Probable** | TFID + float3 cache |

---

## 7. Gaps

1. Promote scaffold filenames `identity` → `Client_EvalAutoPatrolWaypoint` (docs only; dual establishes name).
2. Exact semantics of `mgr+4` / `mgr+8` flags beyond “dirty / special mode”.
3. Runtime observation of 0x20B3 on wire; differential harness.
4. English for object vtbl slots.

**Verdict:** **accept** — real game AutoPatrol helper; CF and C2S path sealed; rename away from `identity`.
