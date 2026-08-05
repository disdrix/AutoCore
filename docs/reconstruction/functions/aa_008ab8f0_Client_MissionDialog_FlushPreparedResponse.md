# Function record: Client_MissionDialog_FlushPreparedResponse

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ab8f0` |
| **Canonical name** | `Client_MissionDialog_FlushPreparedResponse` |
| **Prior FUN_ name** | `FUN_008ab8f0` |
| **Address** | `0x008ab8f0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Calling convention** | MSVC `__thiscall` / decompiler `__fastcall` with `this` in ECX |
| **Completion status** | **Human-refined** — C2S 0x206E send site + static invoker + UF-011 sealed |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Mission dialog teardown helper that **flushes the prepared MissionDialogResponse** buffer at `dialog+0x650` when the opcode field is non-zero. This is the **actual C2S 0x206E send site** relative to HandleButton (which only fills payload fields). Invoked virtually as **`vtbl+0x440`** via generic close `FUN_007fca10`.

## Signature

```c
void __fastcall Client_MissionDialog_FlushPreparedResponse(int* dialog /* this */);
```

## Wire behavior

| Condition | Action |
|---|---|
| `*(dialog+0x650) == 0` | Skip send |
| `*(dialog+0x650) != 0` and `DAT_00d1b4b8 != 0` | `vtbl+0x18(0xffffffff, dialog+0x650, 0x20, 0)` |

- `param_1[0x194]` ≡ offset `0x650` (`0x194 * 4`)
- Size **0x20** matches `MissionDialogResponsePacket` (opcode + missionId + accepted/pad + TFID16)
- Opcode value **0x206E** is written earlier by `Client_NpcDialog_PrepareResponseOpcode`
- **No clear** of `+0x650` after send (Flush body)
- **No clear** of `+0x650` on cancel-close before flush (UF-011 **sealed High static**)
- Zero of `+0x650..+0x66c` only at **BuildWidgets** construct (`0x008ad240`)

## Object / vtable

| Item | Value |
|---|---|
| Host field | client **`+0x1058`** (dialog table index **10** from `+0x1030`) |
| Ctor | `FUN_008ac3f0` @ `0x008ac3f0` (`i_d_npc.xml`) |
| Vtable base | **`0x00a4a51c`** (`PTR_FUN_00a4a51c`) |
| This method offset | **`+0x440`** → DATA slot `0x00a4a95c` |
| Adjacent BuildWidgets | `+0x43c` → `0x008ad240` |
| Class `+0x448` hide | empty stub `FUN_0056f570` (not used as flush) |

## Invoker chain (UF-010 static)

```
FUN_008aec40 (dialog UI event; vtbl DATA 0x00a4a854)
  • response btn 0x9c46..0x9c4d + msg 8 → HandleButton; if success → FUN_007fca10
  • close btn 0x9c40 + msg 8 → FUN_007fca10  (no fill)
FUN_008af020 → HandleButton(0); if success → FUN_007fca10

FUN_007fca10:
  if visible (vtbl+0x3d8): call vtbl+0x440  (= this function)
```

**Not invoker:** `Client_HideMissionDialogIfOpen` @ `0x0092ce50` (operates on `client+0x107c`).

## Call graph

| Role | Symbol | Address |
|---|---|---|
| Vtable entry (DATA) | slot `+0x440` | `0x00a4a95c` |
| Vtable base | `PTR_FUN_00a4a51c` | `0x00a4a51c` |
| Close invoker | `FUN_007fca10` | `0x007fca10` |
| Event dispatch | `FUN_008aec40` | `0x008aec40` |
| Alt dispatch | `FUN_008af020` | `0x008af020` |
| Prepare opcode | `Client_NpcDialog_PrepareResponseOpcode` | `0x008abd70` |
| Fill payload | `Client_MissionDialogHandleButton` state 1 | `0x008ae7c0` |
| Show path | `Client_ShowNpcMissionDialogUI` | `0x009438f0` |

## Confidence by dimension

| Dimension | Level | Rationale |
|---|---|---|
| Offset `+0x650` / index `0x194` | **High** | asm LEA + decompiler |
| Send size `0x20` | **High** | `PUSH 0x20` |
| Opcode pre-filled 0x206E | **High** | Prepare imm |
| Connection global `DAT_00d1b4b8` | **High** (addr); name inferred | asm MOV ECX |
| Vtable `+0x440` / base `0x00a4a51c` | **High** | ctor + memory |
| Invoker `FUN_007fca10` | **High (static)** | decompile; runtime open |
| UF-011 no cancel/post-send clear | **High (static)** | decompile close + Flush + BuildWidgets zero sites |
| Overall | **High (static seal)** | runtime / state0 dual-send remain |

## UF-011 (cancel-close +0x650) — sealed High static

| Claim | Result |
|---|---|
| Flush clears `+0x650` after send | **No** |
| Cancel-close (`0x9c40` / case 40000) clears before flush | **No** |
| Close can flush unfilled 0x206E | **Yes** (Prepare-on-show opcode; no HandleButton body fill) |

## Open questions

- ~~UF-011: cancel-close clears `+0x650`?~~ **Sealed: does not clear; unfilled close flush possible.**
- State 0 success → close may also flush 0x206E after 0x206F.
- Runtime live capture of accept / cancel → 0x206E.

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_008ab8f0_Client_MissionDialog_FlushPreparedResponse.md` |
| Annotated | `raw/aa_008ab8f0_Client_MissionDialog_FlushPreparedResponse.annotated.md` |
| Clean | `reconstructed-exact/Client_MissionDialog_FlushPreparedResponse.cpp` |
| Dual A/B | `reviews/A_aa_008ab8f0_*`, `reviews/B_aa_008ab8f0_*` |
| Chain | `reviews/CHAIN_2026-07-29_c2s_206e_seal.md` |
