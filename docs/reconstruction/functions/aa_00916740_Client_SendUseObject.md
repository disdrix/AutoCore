# Function record: Client_SendUseObject

| Field | Value |
|---|---|
| **Stable ID** | `aa_00916740` |
| **Canonical name** | `Client_SendUseObject` |
| **Address** | `0x00916740` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | interaction-activation |
| **Completion status** | **Human-refined clean** + dual A/B residual seal 2026-07-29 (packet/opcode/TFID/callers); runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Build and send C2S **UseObject** (`0x2072`, size `0x20`): stash the target object pointer on the client, bulk-copy TFID_16 from the target, resolve an optional matching **objective id** from the character’s active objectives (or **−1**), and transmit via sector net connection `DAT_00d1b4b8` vtable `+0x18`.

This is the **unconditional** send path once called — interactability / range gates belong to **callers** (click pick, bound-action poll, S2C complete-dynamic-objective). Sibling: `Client_SendUseObject_IfInteractable` (`aa_00930d70`).

## Signature (listing-sealed)

```c
// MSVC: ECX = client/controller; EAX = target world object*  (both set at every CALL)
// Stack frame: SUB ESP,0x20 packet buffer; no C args.
void Client_SendUseObject(void /* ECX=client, EAX=target */);
```

## Behavioral notes (sealed)

1. `*(client + 0xd28) = target` — last-use object stash (`MOV [ECX+0xd28],EAX`).
2. Packet stack buffer size **0x20** (opcode included):

| Off | Field | Store |
|----:|-------|-------|
| `+0x00` | opcode | `0x2072` |
| `+0x04` | pad | **unwritten** |
| `+0x08..+0x17` | TFID_16 | bulk from `target+0x160..+0x16c` (4 dwords) |
| `+0x18` | IDObjective | match `*(def+0x10)` or `0xFFFFFFFF` |
| `+0x1c` | trailer | **unwritten** (within size) |

3. Objective: `Client_FindObjectiveMatchingTarget` @ `0x00525bd0`
   - **this** = `*(DAT_00d1b6d8)` (local character global — **not** client ECX)
   - arg = `*( *(target+0xa8) + 0x34 )`
   - miss → −1; hit → `*(ret+0x10)`
4. If `*(DAT_00d1b4b8) != 0`: vtbl`+0x18(-1, packet, 0x20, 0)`.

## Callers / callees

| Direction | Address | Name | Notes |
|-----------|---------|------|-------|
| Caller | `0x00925d60` / site `0x00927be1` | `Client_Input_PollBoundActions` | `EAX=EDI`, `ECX=EBX` |
| Caller | `0x009247b0` / site `0x00924ee5` | `Client_InteractClickPickTarget` | `EAX=[EBX+0x758]`, `ECX=EBX`; gate `+0x11c` + dist≤25f |
| Caller | `0x0080ff00` / sites `0x0081004c`, `0x008100fa` | `Client_RecvCompleteDynamicObjective` | `ECX=[DAT_00d1b778]`; EAX world object from resolve/iter |
| Callee | `0x00525bd0` | `Client_FindObjectiveMatchingTarget` | this=`DAT_00d1b6d8` |

No other callers (`get_function_callers` + xref count 4).

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00916740_Client_SendUseObject.md` |
| Annotated | `docs/reconstruction/raw/aa_00916740_Client_SendUseObject.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_SendUseObject.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_00916740_Client_SendUseObject.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_00916740_Client_SendUseObject.md` |
| System map | `docs/reconstruction/systems/interaction-activation.md` |
| Server | `src/AutoCore.Game/Packets/Sector/UseObjectPacket.cs` |

## Confidence by dimension

| Dimension | Level | Rationale |
|---|---|---|
| Opcode / size | **High** | listing literals |
| Full layout table | **High** | every store sealed |
| TFID pack offsets | **High** | LEA + 4 dwords |
| Objective −1 fallback | **High** | explicit branch |
| Stash `client+0xd28` | **High** | first store |
| ECX=client, EAX=target | **High** | body + all call sites |
| FindObjective this | **High** | `DAT_00d1b6d8` |
| Net global VA | **High** | `DAT_00d1b4b8` |
| Net global C++ type | Probable | named INFERRED |
| Pad/trail wire value | Open | unwritten |
| Overall (static) | **High** | |
