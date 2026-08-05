# Review A (reconstruction fidelity): `aa_00930d70` Client_SendUseObject_IfInteractable

| Field | Value |
|---|---|
| **Stable ID** | `aa_00930d70` |
| **VA** | `0x00930d70` |
| **Canonical name** | `Client_SendUseObject_IfInteractable` |
| **Review date** | `2026-07-29` (dual residual strengthen — gates + objective store) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00930d70_Client_SendUseObject_IfInteractable.md` |
| **System** | `interaction-activation` |
| **Scratch** | `tmp/a_00930d70.md` |
| **Verdict** | **accept** on gated CF + objective fill; **accept-with-gaps** on wire / product English |

---

## 1. Purpose

**Gated** C2S UseObject path: send **`0x2072`** size **`0x20`** only when:

1. Block flag `*( *(client+0xe04) + 0xf6 ) == 0`
2. **And** (`FUN_00524520(character, target)` returns non-zero **objective id** **OR** clone type `*( *(target+0xa8) + 0x38 ) == 4`)

Then pack TFID from `target+0x160..+0x16c`, set packet `+0x18` = FUN return (id or **0**), optional send via `*(client+0xc78)` vtbl`+0x18`. Returns **1** if the pack path is taken (even if net ptr is null), else **0**.

**Sibling contrast** (`Client_SendUseObject` `0x00916740`): no gates in body; objective via `Client_FindObjectiveMatchingTarget` or **−1**; stashes `client+0xd28`; different net expression.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | Ghidra `decompile_function` / `batch_decompile` `0x00930d70` ≡ raw body |
| Live bytes | Ghidra `read_memory` `0x00930d70` length 160 (2026-07-29 residual) |
| Callee decompile | `0x00524520` (`FUN_00524520`), `0x0059d9c0` |
| Raw | `docs/reconstruction/raw/aa_00930d70_Client_SendUseObject_IfInteractable.md` |
| Annotated | `docs/reconstruction/raw/aa_00930d70_Client_SendUseObject_IfInteractable.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_SendUseObject_IfInteractable.cpp` |
| Function record | `docs/reconstruction/functions/aa_00930d70_Client_SendUseObject_IfInteractable.md` |
| Sibling | `aa_00916740` Client_SendUseObject dual A/B |
| Callee dual | `aa_00524520` FindActiveObjectiveIdForInteract |
| System map | `docs/reconstruction/systems/interaction-activation.md` |

---

## 3. Sealed control flow (bytes + decompile)

Reconstructed from `read_memory` (not disassembler tool):

```
00930d70  SUB ESP,0x20
          PUSH EDI
          MOV EDI,EAX                    ; target
          MOV EAX,[ESI+0xe04]
          CMP BYTE PTR [EAX+0xf6],0
          JNE  → return 0
          MOV ECX,[ESI+0xe98]            ; character*  ← SEALED thiscall ECX
          PUSH EDI                       ; target arg
          CALL 0x00524520                ; rel32 → FUN_00524520
          TEST EAX,EAX
          JNZ  allow
          MOV ECX,[EDI+0xa8]
          CMP DWORD PTR [ECX+0x38],4
          JE   allow
          XOR  AL,AL
          POP  EDI
          ADD  ESP,0x20
          RET                            ; return 0
allow:
          ADD  EDI,0x160                 ; &TFID
          CMP  DWORD PTR [ESI+0xc78],0
          MOV  EDX,[EDI] ; ECX,[EDI+4] → [ESP+0xc],[ESP+0x10]
          MOV  EDX,[EDI+8]; ECX,[EDI+0xc] → [ESP+0x14],[ESP+0x18]
          MOV  DWORD PTR [ESP+4],0x2072  ; packet+0x00
          MOV  [ESP+0x1c],EAX            ; packet+0x18 = FUN return  ← SEALED
          JZ   skip_send                 ; net null → still return 1
          ; send: (**(**(ESI+0xc78))+0x18)(0xFFFFFFFF, packet, 0x20, 0)
skip_send:
          MOV  AL,1
          POP  EDI
          ADD  ESP,0x20
          RET
```

Packet frame after `PUSH EDI` (packet base = `ESP+4`):

| Offset | Source | Notes |
|---:|---|---|
| `+0x00` | literal `0x2072` | `[ESP+4]` |
| `+0x04` | **never written** | pad / residual |
| `+0x08..+0x17` | `target+0x160..+0x16c` | four dwords |
| `+0x18` | **EAX after FUN** | match id, or **0** on type-4-only |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Block gate `*( *(ESI+0xe04)+0xf6 ) == 0` | **High / Confirmed** | bytes |
| `FUN_00524520` thiscall `ECX = *(ESI+0xe98)` | **High / Confirmed** | `MOV ECX,[ESI+0xe98]` before call — residual gap **closed** |
| Call target `0x00524520` | **High / Confirmed** | rel32 decode from bytes |
| Allow: FUN≠0 **OR** type@`clone+0x38`==4 | **High / Confirmed** | TEST/JNZ + CMP/JE |
| Opcode `0x2072` size `0x20` | **High** | literals |
| Packet `+0x18` = explicit `MOV [ESP+0x1c],EAX` | **High / Confirmed** | not mere decompiler local alias |
| Type-4 no-match → objective **0** (not −1) | **High / Confirmed** | EAX=0 stored; no `or eax,-1` |
| No `client+0xd28` stash | **High** | absent from body |
| Net via `*(ESI+0xc78)` vtbl`+0x18` | **High** | body |
| Return **1** after gates even if net null | **High** | JZ skip_send then `MOV AL,1` |
| Returns 0/1 in **AL** | **High** | `XOR AL,AL` / `MOV AL,1` |
| ESI=client, EAX=target on entry | **High** (static) | body uses; callers preserve convention |
| `FUN_00524520` returns objective id (`def+0x10`) | **High** | callee dual + decompile |
| Wire capture confirms 0 vs −1 product impact | **Open** | need live dump |
| Block-flag / type-4 product English | **Probable / Open** | class name not sealed |
| Net `+0xc78` ≡ sibling global | **Open** | two expressions |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Block gate → FUN → type-4 OR → pack → optional send → 1/0 | **Yes** |
| Objective hygiene (explicit EAX store; 0 not −1) | **Yes** (sealed stronger than overlay-by-name) |
| Character ECX provenance | **Yes** (`client+0xe98`) |
| No FindObjectiveMatchingTarget / no +0xd28 | **Yes** |

**Result:** Gated send kernel **sealed** static. Residual closed: character pointer + explicit objective store.

---

## 6. Gaps (after residual)

1. ~~Character ECX into `FUN_00524520`~~ **Sealed:** `*(client+0xe98)`.
2. ~~Objective uninit / garbage~~ **Sealed:** `MOV [ESP+0x1c],EAX` after FUN.
3. ~~Type-4 → 0 vs −1 static~~ **Sealed** (wire still open for product).
4. Live wire dump type-4 path `@+0x18`.
5. Product English for block flag `*(e04)+0xf6` and clone type **4**.
6. Whether `client+0xc78` is the same object as `g_pSectorNetConnection_INFERRED`.
7. Caller dual detail for `FUN_008be900` / `FUN_00925820` (listed xrefs).

---

## 7. Verdict

**Gated UseObject CF is sealed** for block flag, character lookup, objective-id gate / type-4 bypass, TFID pack, explicit objective dword, optional net send, and 0/1 return. Static residual distinguishing this path from `Client_SendUseObject` (−1 sentinel, stash, different matcher) is closed.

**Verdict: accept** (kernel CF + objective fill) / **accept-with-gaps** (live wire, flag/type English, net-ptr identity).
