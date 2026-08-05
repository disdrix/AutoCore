# Review A (reconstruction fidelity): `aa_008ab8f0` Client_MissionDialog_FlushPreparedResponse

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ab8f0` |
| **VA** | `0x008ab8f0` |
| **Canonical name** | `Client_MissionDialog_FlushPreparedResponse` (rename from `FUN_008ab8f0`) |
| **Review date** | `2026-07-29` (UF-011 residual seal — cancel-close +0x650) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_008ab8f0_Client_MissionDialog_FlushPreparedResponse.md` |
| **System tag** | `missions-progression` |
| **Verdict** | **accept-with-gaps** (send site + invoker + UF-011 static sealed; runtime open) |

---

## 1. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Ghidra decompile (live 2026-07-29 residual) | `FUN_008ab8f0` @ `0x008ab8f0` ≡ frozen raw |
| Clean plate | `docs/reconstruction/reconstructed-exact/Client_MissionDialog_FlushPreparedResponse.cpp` |
| Function record | `docs/reconstruction/functions/aa_008ab8f0_Client_MissionDialog_FlushPreparedResponse.md` |
| Prepare opcode | Ghidra `Client_NpcDialog_PrepareResponseOpcode` @ `0x008abd70` → `*(+0x650)=0x206E` |
| Handle button | Ghidra `Client_MissionDialogHandleButton` @ `0x008ae7c0` (fill only for 0x206E) |
| Dialog ctor | Ghidra `FUN_008ac3f0` @ `0x008ac3f0` → `*this = PTR_FUN_00a4a51c` |
| Dialog dtor | Ghidra `FUN_008ac340` @ `0x008ac340` |
| Vtable base | `0x00a4a51c` (`PTR_FUN_00a4a51c`) |
| Flush slot | `0x00a4a51c + 0x440 = 0x00a4a95c` → dword `0x008ab8f0` |
| BuildWidgets slot | `0x00a4a51c + 0x43c = 0x00a4a958` → `0x008ad240` |
| Close invoker | Ghidra `FUN_007fca10` @ `0x007fca10` — if visible (`+0x3d8`) call `vtbl+0x440` |
| UI event dispatch | Ghidra `FUN_008aec40` @ `0x008aec40` (DATA vtbl `0x00a4a854`) |
| Alt dispatch | Ghidra `FUN_008af020` @ `0x008af020` |
| Host slot | client `+0x1058` (index **10** in `+0x1030` table); **not** `+0x107c` |
| Show path | `Client_ShowNpcMissionDialogUI` @ `0x009438f0` uses `param_1+0x1058` |
| Hide sibling | `Client_HideMissionDialogIfOpen` @ `0x0092ce50` — `+0x107c` only; **not** Flush |
| Packet | `src/AutoCore.Game/Packets/Sector/MissionDialogResponsePacket.cs` |
| Xrefs to body | Ghidra `get_function_xrefs(0x008ab8f0)` → **DATA only** `0x00a4a95c` |
| Global | `DAT_00d1b4b8` read @ `0x008ab902` |

---

## 2. Evidence used

### 2.1 Decompiler body (send gate) — re-verified live ≡ raw

```c
// 0x008ab8f0
if ((param_1[0x194] != 0) && (g_pSectorNetConnection_INFERRED != 0)) {
  (**(code **)(*(int *)g_pSectorNetConnection_INFERRED + 0x18))
    (0xffffffff, param_1 + 0x194, 0x20, 0);
}
// then optional DAT_00d1d8dc reward-cursor cleanup,
// FUN_008aa320(), dialog vtbl+0x3ac, FUN_00792490()
```

| Observation | Mapping |
|---|---|
| `param_1[0x194]` | dword index → byte offset `0x194 * 4 = 0x650` |
| Buffer pointer | `param_1 + 0x194` ≡ `dialog + 0x650` |
| Size | literal **`0x20`** (32 bytes) |
| Flags | trailing `0`; first arg `0xffffffff` |
| Global | `DAT_00d1b4b8` (sector net connection, inferred name) |
| Send slot | connection object vtable `+0x18` |

Assembly form (send site):

```text
CMP [ESI+0x650], 0
LEA EAX, [ESI+0x650]
MOV ECX, [DAT_00d1b4b8]
PUSH 0 ; PUSH 0x20 ; PUSH EAX ; PUSH -1
CALL [EDX+0x18]
```

### 2.2 Vtable placement (UF-010 partial → sealed offset)

| Item | Value | Confidence |
|---|---|---|
| Ctor installs vtable | `FUN_008ac3f0`: `*param_1 = &PTR_FUN_00a4a51c` | **High** |
| Host field | client `+0x1058` = `operator_new(0x748)` + `FUN_008ac3f0` in `FUN_0093e7e0` | **High** |
| Dialog table index | `(0x1058 - 0x1030) / 4 = 10` | **High** |
| Flush method offset | `0x00a4a95c - 0x00a4a51c = **0x440**` | **High** |
| Adjacent BuildWidgets | offset **0x43c** | **High** |
| Hide slot on this class | `+0x448` / `+0x444` → `FUN_0056f570` (empty stub) | **High** |

### 2.3 Virtual invoker chain (UF-010 residual — static seal)

```
Response / close UI event on NPC dialog
  FUN_008aec40  (dialog vtbl DATA 0x00a4a854)
    • btn ids 0x9c46..0x9c4d, msg==8 → Client_MissionDialogHandleButton
      if returns non-zero → FUN_007fca10()
    • case 40000 (0x9c40 close) msg==8 → FUN_007fca10()  [no HandleButton fill]
  FUN_008af020
    • HandleButton(0); if non-zero → FUN_007fca10()

FUN_007fca10  (generic CloseVisibleDialog)
  if dialog visible (vtbl+0x3d8):
    call dialog.vtbl+0x440   ← for this class = Flush @ 0x008ab8f0
    parent.vtbl+0xb0(dialog)  // detach
```

**Not** the invoker: `Client_HideMissionDialogIfOpen` (`+0x107c`, slots `+0x3d8/+0x448/+0x34c`) — different object; mission-dialog class `+0x448` is a no-op stub anyway.

### 2.4 Role in 0x206E seal chain

1. **Prepare** (`0x008abd70`, from Show @ `0x00943a60`) writes `*(dialog+0x650) = 0x206E`.
2. **HandleButton** state 1 fills `+0x654` / `+0x658..` / `+0x660..` — no `Client_SendSectorPacket` for `0x206E`.
3. **Event dispatcher** returns success → **`FUN_007fca10`** → **`vtbl+0x440` = this function** sends `0x20` from `+0x650`.

### 2.5 Packet size cross-check

| Field | Size |
|---|---|
| missionId i32 | 4 |
| accepted bool + pad3 | 4 |
| pad4 | 4 |
| TFID16 | 16 |
| **Body** | **28** |
| **+ opcode u32** | **32 = 0x20** |

Matches flush size exactly. AutoCore `MissionDialogResponsePacket` + server `GameOpcode.MissionDialogResponse = 0x206E`.

---

## 3. Confirmed claims with confidence

| Claim | Confidence | Notes |
|---|---|---|
| Rename justified | **High** | Primary wire action = flush prepared `+0x650` buffer |
| `param_1[0x194]` ≡ `dialog+0x650` | **High** | Index math + BuildWidgets clears same slot |
| Send size `0x20` from `+0x650` | **High** | Decompiler literal + asm PUSH 0x20 |
| Opcode head is pre-filled **0x206E** by Prepare | **High** | imm at Prepare; only code-site materialization |
| Send via `DAT_00d1b4b8` vtbl+0x18 | **High** (slot); **Probable** (global name) | Same sector C2S pattern |
| Vtable base `0x00a4a51c`, method offset **`+0x440`** | **High** | ctor + memory + math |
| Host object `client+0x1058` (slot index 10) | **High** | Show + UI init |
| Invoker = `FUN_007fca10` after `FUN_008aec40` / `FUN_008af020` | **High** (static) | Decompile chain; runtime not traced |
| HideMissionDialogIfOpen is **not** the flush invoker | **High** | Different field + empty +0x448 on this class |
| Secondary work is teardown | **High** | FUN_008aa320 + vtbl+0x3ac + FUN_00792490 |

---

## 4. Control flow: clean ≡ decompiler

| Stage | Match |
|---|---|
| Gate on prepared opcode + connection | **Yes** |
| vtbl+0x18 send (buffer, 0x20, flags 0) | **Yes** |
| Optional DAT_00d1d8dc reward-slot match loop | **Yes** |
| FUN_008aa320 → dialog+0x3ac → FUN_00792490 | **Yes** |

---

## 5. Remaining uncertainty

1. ~~**UF-011** — cancel-close clears `+0x650` before flush?~~ **Sealed High (static) 2026-07-29** — see §5.1 residual.
2. **State 0** returns success after immediate **0x206F** send — dispatcher still calls `FUN_007fca10` → may also flush prepared **0x206E** (dual-packet risk; static only).
3. **Global name** `g_pSectorNetConnection` remains inferred (`DAT_00d1b4b8`).
4. **Runtime** capture of accept → 0x206E still open (not required for static seal). Server tolerance of unfilled cancel 0x206E is product residual, not open client packing.

### 5.1 UF-011 residual (cancel-close +0x650 clear) — **sealed**

| Question | Answer | Evidence |
|---|---|---|
| Does Flush clear `+0x650` after send? | **No** | Live decompile `0x008ab8f0`: gate → vtbl+0x18 send → reward cleanup → `FUN_008aa320` → `vtbl+0x3ac` → `FUN_00792490`; **no** store to `param_1[0x194]` / `[ESI+0x650]`. Image: `CMP [ESI+0x650],0` / `LEA EAX,[ESI+0x650]` / `PUSH 0; PUSH 0x20; PUSH EAX; PUSH -1; CALL [EDX+0x18]` then fall-through (no zero write). |
| Does cancel-close clear `+0x650` *before* flush? | **No** | `FUN_008aec40` `case 40000` (`0x9c40`) + `msg==8` → `LAB_008aef8f` → `FUN_007fca10()` with **no** HandleButton and **no** `+0x650` write. `FUN_007fca10` only: visible? → `vtbl+0x440` (= Flush). |
| Can close flush **unfilled** 0x206E? | **Yes (static)** | Prepare-on-show (`0x008abd70`) unconditional `*(dialog+0x650)=0x206E`. Body fill is HandleButton state 1 only (`+0x654/+0x658/+0x660..`). Close never fills. Gate is “opcode dword ≠ 0”, not “body filled”. |
| When is `+0x650` zeroed? | Construct/BuildWidgets only | `Client_BuildNpcMissionDialogWidgets` (`0x008ad240`): `param_1[0x194..0x19b]=0` at widget build — **not** on cancel/close/post-send. `FUN_008aa320` tears child lists only. |

**UF-011 status: sealed High (static).** Risk is real (spurious/unfilled C2S 0x206E on close), not an open unknown. Residual for product: whether live server ignores cancel flushes / zero body — runtime capture, out of this slice.

---

## 6. Verdict

**accept-with-gaps.**

Send size **0x20**, opcode at **`+0x650`**, **UF-010 virtual invoker** (`FUN_007fca10` → `vtbl+0x440`), and **UF-011** (no pre-flush / post-send clear; close can emit unfilled 0x206E) are **statically sealed** with high confidence. Remaining gaps: state0 dual-send possibility, runtime live capture, inferred global name.
