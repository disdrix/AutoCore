# Review A (reconstruction fidelity): `aa_00916740` Client_SendUseObject

| Field | Value |
|---|---|
| **Stable ID** | `aa_00916740` |
| **VA** | `0x00916740` |
| **Canonical name** | `Client_SendUseObject` |
| **Review date** | `2026-07-29` (dual residual refresh — packet / opcode / TFID / callers) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00916740_Client_SendUseObject.md` |
| **System** | `interaction-activation` |
| **Verdict** | **accept-with-gaps** (static packet+callers **sealed**; runtime open) |

---

## 1. Purpose

C2S **UseObject** (`0x2072`, size `0x20`): stash target at `client+0xd28`; bulk-copy **TFID_16** from `target+0x160`; resolve `IDObjective` via `Client_FindObjectiveMatchingTarget(*( *(target+0xa8)+0x34 ))` → def`+0x10` or **−1**; send via `DAT_00d1b4b8` (`g_pSectorNetConnection_INFERRED`) vtbl`+0x18`.

Unconditional once entered — interactability / range belong to **callers**.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00916740_Client_SendUseObject.md` (+ 2026-07-29 asm residual section) |
| Annotated | `docs/reconstruction/raw/aa_00916740_Client_SendUseObject.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_SendUseObject.cpp` |
| Function record | `docs/reconstruction/functions/aa_00916740_Client_SendUseObject.md` |
| Live decompile | Ghidra `decompile_function` `0x00916740` — body ≡ raw |
| Live listing | Ghidra `disassemble_function` `0x00916740` (full body) |
| Live bytes | Ghidra `read_memory` `0x00916740` length 128 |
| Call-site asm | Ghidra `get_assembly_context` xrefs `0081004c`, `008100fa`, `00924ee5`, `00927be1` |
| Callers API | `get_function_callers` → PollBound / ClickPick / RecvCompleteDynamicObjective |
| Server mirror | `UseObjectPacket.cs` + `UseObjectPacketTests` (pad4 + TFID16 + i32 after opcode strip) |

---

## 3. Sealed residuals (this refresh)

### 3.1 Opcode + size — **SEALED**

| Fact | Evidence |
|---|---|
| Opcode literal `0x2072` | `MOV dword ptr [ESP], 0x2072` @ `0x00916772` |
| Send size `0x20` | `PUSH 0x20` @ `0x009167a9` before vtbl`+0x18` |
| Opcode lives **inside** the 0x20 buffer at `+0x00` | buffer base = ESP after `SUB ESP,0x20`; send LEA is that base |

### 3.2 Packet layout — **SEALED** (static stores)

| Offset | Width | Store | Content |
|-------:|------:|-------|---------|
| `+0x00` | 4 | `MOV [ESP],0x2072` | opcode |
| `+0x04` | 4 | **none** | pad (stack residual; not written in body) |
| `+0x08` | 4 | `MOV [ESP+0x8],…` | TFID dword0 ← `*(obj+0x160)` |
| `+0x0c` | 4 | `MOV [ESP+0xc],…` | TFID dword1 ← `*(obj+0x164)` |
| `+0x10` | 4 | `MOV [ESP+0x10],…` | TFID dword2 ← `*(obj+0x168)` |
| `+0x14` | 4 | `MOV [ESP+0x14],…` | TFID dword3 ← `*(obj+0x16c)` |
| `+0x18` | 4 | `MOV [ESP+0x18],…` | `IDObjective` (match id or `0xFFFFFFFF`) |
| `+0x1c` | 4 | **none** | trailing unwritten within size `0x20` |

Server strip (AutoCore `UseObjectPacket.Read`): after opcode, skip pad4, `ReadTFID` (16), `ReadInt32` objective. Meaningful client body = pad + TFID16 + i32 (`0x18` body); size `0x20` total includes opcode + 4 trailing unwritten bytes.

### 3.3 TFID packing — **SEALED**

```
LEA EDX, [EAX + 0x160]          ; TFID_16 base on world object
MOV ECX, [EDX]     ; +0
MOV [ESP+0x8], ECX
MOV ECX, [EDX+4]   ; +4
MOV [ESP+0xc], ECX
MOV ECX, [EDX+8]   ; +8
MOV EDX, [EDX+0xc] ; +0xc
MOV [ESP+0x10], ECX
MOV [ESP+0x14], EDX
```

* **Bulk 16-byte copy** of object identity block `obj+0x160..+0x16f` into packet `+0x08..+0x17`.
* No field-wise Coid/Global split in this unit — wire TFID_16 is the object’s stored TFID block.
* Server `ReadTFID`: `i64 Coid` + `bool Global` + 7 pad ≡ same 16 B layout.

### 3.4 Objective + character this — **SEALED** (static)

| Fact | Evidence |
|---|---|
| Match key | `*( *(obj+0xa8) + 0x34 )` — clonebase field, not object* |
| Callee | `CALL 0x00525bd0` `Client_FindObjectiveMatchingTarget` |
| **this / ECX** for callee | `MOV ECX, dword ptr [0x00d1b6d8]` then PUSH key — **not** the client `param_1` |
| Miss | `MOV [ESP+0x18], 0xFFFFFFFF` |
| Hit | `MOV ECX, [EAX+0x10]` → `[ESP+0x18]` |

Prior open “Character ECX residual” for **this call site** is **closed**.

### 3.5 Net send — **SEALED** address (type name still INFERRED)

| Fact | Evidence |
|---|---|
| Global | `MOV ECX, dword ptr [0x00d1b4b8]` |
| Null skip | `TEST ECX / JZ` |
| Call | `CALL dword ptr [EDX+0x18]` with args `(-1, packet*, 0x20, 0)` |
| Contrast sibling | IfInteractable uses `client+0xc78`, not this global |

### 3.6 Callers — **SEALED** (xrefs + register setup)

| Call site | Parent | ECX (client) | EAX (target) | Gate (caller, not body) |
|---|---|---|---|---|
| `0x00924ee5` | `Client_InteractClickPickTarget` `0x009247b0` | `MOV ECX, EBX` (controller this) | `MOV EAX, [EBX+0x758]` (= decomp `[0x1d6]`) | `obj+0x11c != 0` and dist ≤ `DAT_00aaa6fc` (25.0f) |
| `0x00927be1` | `Client_Input_PollBoundActions` `0x00925d60` | `MOV ECX, EBX` | `MOV EAX, EDI` | bound-action interact path (flag `+0x11c` / sibling gates upstream) |
| `0x0081004c` | `Client_RecvCompleteDynamicObjective` `0x0080ff00` | `MOV ECX, [0x00d1b778]` | EAX from world-resolve path (`FUN_009197a0` boundary / match `clone+0x34`) | S2C `0x2070` force-complete; optional use when world target matches |
| `0x008100fa` | same parent | `MOV ECX, [0x00d1b778]` | EAX from `FUN_004022a0` iter world object | second site in same handler |

`get_function_callers`: exactly these three parents. No additional production callers.

### 3.7 Entry convention — **SEALED** at call sites (Probable→**High** static)

Body first instruction pair:

```
SUB ESP, 0x20
MOV dword ptr [ECX + 0xd28], EAX   ; stash proves ECX=client, EAX=target
```

All four CALL sites load ECX/EAX immediately before CALL as above.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Opcode `0x2072` size `0x20` | **High** | literal + PUSH |
| Full stack layout table §3.2 | **High** | every store from listing |
| TFID bulk `obj+0x160` ×16 B | **High** | LEA+four dwords |
| Objective −1 / def`+0x10` | **High** | explicit branch |
| Stash `client+0xd28` | **High** | first store |
| ECX=client, EAX=target | **High** | body + all call sites |
| FindObjective this = `DAT_00d1b6d8` | **High** | MOV before CALL |
| Net global = `DAT_00d1b4b8` | **High** | MOV before send |
| No interact gate in body | **High** | absent |
| Pad `+0x04` / trail `+0x1c` wire value | **Open** | unwritten stack |
| `DAT_00d1b4b8` ≡ `client+0xc78` | **Open** | sibling residual |
| Runtime capture | **Open** | deferred |

---

## 5. Control flow: clean ≡ raw ≡ listing

| Stage | Match |
|---|---|
| Stash → TFID pack → opcode → FindObjective → objective store → conditional send | **Yes** |
| No invented range / interact check | **Yes** |
| Character this for FindObjective from `DAT_00d1b6d8` | **Yes** (clean updated) |

---

## 6. Gaps / open (remaining)

1. Wire dump of pad dword `@+0x04` and trailing `@+0x1c` (stack garbage vs zeroed).
2. Proof `DAT_00d1b4b8` always aliases `client+0xc78` (IfInteractable path).
3. Live interact capture (NPC deliver with real objective id ≠ −1).
4. Exact type name of `DAT_00d1b4b8` / `DAT_00d1b6d8` / `DAT_00d1b778` (roles sealed; C++ type open).

**Verdict:** **accept-with-gaps** — packet layout, opcode, TFID packing, callers, entry regs, FindObjective this, and net global **sealed** statically; pad/trail wire + runtime remain open.
