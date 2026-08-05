# Review A (reconstruction fidelity): `aa_00811be0` Client_RecvInventoryGrabResponse

| Field | Value |
|---|---|
| **Stable ID** | `aa_00811be0` |
| **VA** | `0x00811be0` |
| **Canonical name** | `Client_RecvInventoryGrabResponse` |
| **Review date** | `2026-07-29` (dual residual refresh) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00811be0_Client_RecvInventoryGrabResponse.md` |
| **Prior dual** | `aa_00811be0_reconstruction_review.md` / `aa_00811be0_skeptical_review.md` |
| **Live re-decompile** | Ghidra MCP `batch_decompile` 2026-07-29 — CF **≡** raw; call-arg attribution for `FUN_0093d6e0` still wrong in decompiler |
| **Dispatch seal** | `Client_PacketDispatch` `case 0x2035`/`0x2039` → this VA; xref call `0x008159b0` |
| **Scratch** | `tmp/a_00811be0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

S2C InventoryGrabResponse (dispatch opcode **0x2035**). Clears `client+0xb6`, resolves item by TFID, then:

- **Whole-grab** (`splitFlag@+0x20 == 0`): `Client_InventoryGrabApplyToCursor` (`FUN_0093d6e0`) with invType@+0x18 + count@+0x1c on the resolved item, then mission UI refresh.
- **Stack split** (`splitFlag != 0`): reduce source qty, spawn peeled stack via `CVOGReaction_GiveItemByCbid`, bind split COID@+0x28 via `Object_SetCoidIdentity` (`FUN_00512160`), init/set qty/register/gfx, then apply **new stack** to cursor via same helper.

Shared jump slot with opcode **0x2039** (early-out, no grab work).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00811be0_Client_RecvInventoryGrabResponse.md` |
| Annotated | `raw/aa_00811be0_Client_RecvInventoryGrabResponse.annotated.md` |
| Clean | `reconstructed-exact/Client_RecvInventoryGrabResponse.cpp` |
| Prior dual | `aa_00811be0_reconstruction_review.md` / skeptical |
| System / design | `systems/inventory-transfer.md`, stack-split design spec |
| Server Write | `src/AutoCore.Game/Packets/Sector/InventoryGrabResponsePacket.cs` |
| Dispatch | `Client_PacketDispatch` `0x00815710` |
| Helper raw | `raw/aa_0093d6e0_FUN_0093d6e0.md`, `aa_00512160` |
| Sibling | DropResponse dual residual `aa_00813730` |
| Scratch | `tmp/a_00811be0.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Clear `client+0xb6`; call `FUN_007a69d0` first | **High** | Prologue `MOV ESI,EAX` + store |
| Early return when `*packet == 0x2039` | **High** | `CMP dword ptr [EBX],0x2039` |
| Opcode **0x2035** dispatch → this function | **Confirmed** | PacketDispatch case + sole xref `0x008159b0` |
| Framing **EAX=client, EBX=packet** | **Confirmed** | Call site `MOV EAX,EBP; MOV EBX,ESI` + prologue |
| TFID resolve from packet `+0x08` | **High** | |
| Success requires object + `success@+0x38 != 0` | **High** | `CMP byte [EBX+0x38]` |
| Split branch on `splitFlag@+0x20` | **High** | `CMP byte [EBX+0x20]` |
| **InventoryType @+0x18** fed to cursor helper | **High** | Asm `MOV DL,[EBX+0x18]` (decompiler omitted) |
| Whole path: full cursor apply, not UI-only | **High** | `0093d6e0` grid remove + qty + cursor attach |
| Split: GetQty/SetQty residual, GiveItemByCbid | **High** | Source=`EBP`, new=`EDI` |
| `FUN_00512160` thiscall new stack + COID@+0x28 | **High** | `MOV ECX,EDI; PUSH 1; PUSH hi; PUSH lo` |
| Split create fail → toast + `FUN_007fc150` | **High** | |
| Resolve/success fail → ODS only + refresh | **High** | Weaker UX |
| `DAT_00d1a8f6` cleared here | **Falsified** | Xrefs only send paths / other UI |
| Formal `__cdecl(client, packet)` portable | **Tentative** | Formals unused; registers sealed |

---

## 4. Control flow: clean ≡ raw (CF)

| Stage | Match |
|---|---|
| Clear `+0xb6` + helper | **Yes** |
| Early `0x2039` | **Yes** |
| TFID resolve + dual success gate | **Yes** |
| Simple vs split on `@+0x20` | **Yes** |
| Split create failure toast vs success vcalls | **Yes** |
| Failure ODS path | **Yes** |

**Decompiler gap (not CF reorder):** raw/clean show `FUN_0093d6e0(client, count)` only. Asm proves **EAX=item, DL=invType@+0x18, stack=(client,count)**. Residual plate documents true args; clean plate updated 2026-07-29.

---

## 5. Gaps / open

1. Original PDB names for `FUN_0093d6e0` / `FUN_00512160` / `FUN_004bc180` (roles sealed).
2. Runtime whole vs split round-trip capture.
3. Bit-exact / differential open.
4. AutoCore `AddToExistingItem` name vs client **SplitFlag** at same offset (wire risk).

**Verdict:** Clean CF scaffold faithful. Dual residual seals dispatch, ABI, packet dictionary (incl. invType@+0x18), simple-arm completeness, and helper roles. **accept-with-gaps.**
