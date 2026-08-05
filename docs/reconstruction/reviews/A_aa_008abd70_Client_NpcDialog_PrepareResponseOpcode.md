# Review A (reconstruction fidelity): `aa_008abd70` Client_NpcDialog_PrepareResponseOpcode

| Field | Value |
|---|---|
| **Stable ID** | `aa_008abd70` |
| **VA** | `0x008abd70` |
| **Canonical name** | `Client_NpcDialog_PrepareResponseOpcode` |
| **Review date** | `2026-07-29` (dual residual strengthen; prior refresh same day; original 2026-07-23) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_008abd70_Client_NpcDialog_PrepareResponseOpcode.md` |
| **System tag** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |
| **Scratch** | `tmp/a_008abd70.md` |

---

## 1. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Ghidra decompile (live) | `Client_NpcDialog_PrepareResponseOpcode` @ `0x008abd70` ≡ raw |
| Raw | `docs/reconstruction/raw/aa_008abd70_Client_NpcDialog_PrepareResponseOpcode.md` |
| Annotated | `docs/reconstruction/raw/aa_008abd70_Client_NpcDialog_PrepareResponseOpcode.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_NpcDialog_PrepareResponseOpcode.cpp` |
| Function record | `docs/reconstruction/functions/aa_008abd70_Client_NpcDialog_PrepareResponseOpcode.md` |
| Sole caller | Ghidra xrefs: `Client_ShowNpcMissionDialogUI` CALL @ `0x00943a60` only |
| Call-site asm | `get_assembly_context`: `MOV ESI,EBX; MOV ECX,EDI; CALL 0x008abd70` |
| Entry bytes | `read_memory(0x008abd70,48)` — `MOV [ESI+0x670],ECX` + imm `0x206E` @ `+0x650` |
| Opcode imm | `6E 20 00 00` at `0x008abd8c` |
| Reward panel callee | `FUN_008ab9b0` @ `0x008ab9b0` (objective reward text lines) |
| Flush consumer | `Client_MissionDialog_FlushPreparedResponse` @ `0x008ab8f0` |
| Chain | `reviews/CHAIN_2026-07-29_c2s_206e_seal.md` |
| Packet | `src/AutoCore.Game/Packets/Sector/MissionDialogResponsePacket.cs` |
| Tests | `src/AutoCore.Game.Tests/Packets/MissionDialogAndObjectivePacketTests.cs` |

---

## 2. Evidence used

### 2.1 Opcode store (core) — High

```asm
; entry after prologue (read_memory)
85 C9                         test  ecx, ecx
… 
89 8E 70 06 00 00             mov   [esi+0x670], ecx
C7 86 50 06 00 00 6E 20 00 00 mov   dword ptr [esi+0x650], 0x206E
0F 84 …                       je    param_zero_chrome
```

- Immediate **0x206E** into `dialog+0x650` (packet buffer head).
- Store is **unconditional** relative to `param_1` (runs before branch on ZF from `TEST ECX`).
- Sole `.text` materialization of imm `0x206E` for this client image (data-section hits ignored).

### 2.2 Calling convention / params — High (residual closed)

| Register | Meaning | Sealed by |
|---|---|---|
| **ESI** | dialog UI* (`*(client+0x1058)`) | Caller `MOV ESI,EBX` @ `0x00943a5e`; EBX used as dialog elsewhere (`+0x510`, `+0x644`, `+0x670`) |
| **ECX** | mission def* | Caller `MOV ECX,EDI` @ `0x00943a5c`; EDI = hash-lookup def; also already-active `CMP [EBX+0x670],EDI` |

Decompiler labels `param_1` + `unaff_ESI` with a zero-arg call from Show — **register recovery, not missing args**. Convention is dual-register (ECX + ESI), not pure stack.

### 2.3 Sole static caller + present spine

1. **Only** `Client_ShowNpcMissionDialogUI` calls this (`get_function_xrefs` / callers).
2. Reachability requires `def != 0` and objectives byte `(char)def[0x4c] != 0`.
3. After already-active early-out, Prepare is **unconditional** (before offer/active/turn-in chrome).
4. Therefore sole caller **always** passes nonzero mission def → decompiler `param_1 == 0` branch is **not taken** on the only named path (branch retained in image).

### 2.4 What this function does *not* do

- Does **not** fill `+0x654` missionId, `+0x658` accepted, or `+0x660` TFID (HandleButton state 1).
- Does **not** call sector send / `Client_SendSectorPacket` / Flush.
- Does perform **UI** work: title/layout on `+0x6dc`, optional `+0x6e4` reward panel via `FUN_008ab9b0`, `sprintf("[%d] %s")`, scale via `DAT_00d1e818/1c` × `DAT_00aaa678/67c` (≈ 0.000833 / 0.000625).

### 2.5 Seal chain role

| Step | Function | Address | Role |
|---|---|---|---|
| 1 | ShowNpcMissionDialogUI | `0x009438f0` | Sole caller; frames ESI/ECX |
| 2 | **PrepareResponseOpcode** | `0x008abd70` | `+0x650 = 0x206E`, `+0x670 = def` |
| 3 | MissionDialogHandleButton | `0x008ae7c0` | Fills payload (state 1) |
| 4 | FlushPreparedResponse | `0x008ab8f0` | Sends 0x20 from `+0x650` |

### 2.6 AutoCore alignment

```csharp
// MissionDialogResponsePacket.cs
// Ghidra Client_NpcDialog_PrepareResponseOpcode @ 0x008abd70 sets dialog+0x650 = 0x206E.
public override GameOpcode Opcode => GameOpcode.MissionDialogResponse; // 0x206E
```

Plate “payload body: missionId + accepted + TFID” describes **buffer contract** (filled later), not stores in this body.

---

## 3. Confirmed claims with confidence

| Claim | Confidence | Notes |
|---|---|---|
| `dialog+0x650 = 0x206E` | **High** | Imm + `read_memory` + unique code pattern |
| `dialog+0x670 = mission def*` | **High** | ECX from sole caller; already-active compare uses same slot |
| ESI = dialog, ECX = param | **High** | Call-site asm + entry uses |
| Only static caller is Show @ `0x00943a60` | **High** | xrefs |
| Sole caller always nonzero def | **High** | Show gate before CALL |
| C2S opcode is 0x206E not 0x2070 | **High** | Literal + AutoCore enum |
| Prepare ≠ send | **High** | No send in body; Flush separate |
| Unconditional stamp on present path | **High** | After already-active only |
| Full payload assembled here | **Low — false** | HandleButton owns body |
| `param_1 == 0` UI branch live from Show | **Low — false for sole caller** | Image branch remains |
| Chrome helper product names | **Tentative** | FUN_* open |
| Title sprintf arg sources | **Tentative** | via `FUN_007a69d0` / `007a6de0` |

---

## 4. Control flow: clean ≡ raw / decompiler

| Stage | Match |
|---|---|
| Write `+0x670` / `+0x650` | **Yes** |
| param==0: scale/show `+0x6dc` chrome | **Yes** (retained; sole caller skips) |
| param!=0: optional FUN_00547920, title layout, `+0x6e4` panel | **Yes** |
| Early returns on panel path | **Yes** |
| Invented clamps / deleted stages | **None** |

---

## 5. Remaining uncertainty

1. Product names for UI helpers and vtbl slots on `+0x6dc` / `+0x6e4`.
2. Exact `sprintf("[%d] %s")` level/name producers.
3. Whether any **indirect** path ever calls with `param_1 == 0` (no static xref).
4. Cross-function: cancel-close may still flush 0x206E with incomplete body (Flush/UF-011 — not this unit).
5. Runtime capture / bit-diff open.

---

## 6. Verdict

**accept-with-gaps.**

Residual strengthen: register framing **High**, sole-caller nonzero-def path **High**, opcode imm re-proven with `read_memory`. Gaps remain UI chrome depth and cross-function flush policy — **not** the opcode identity claim.
