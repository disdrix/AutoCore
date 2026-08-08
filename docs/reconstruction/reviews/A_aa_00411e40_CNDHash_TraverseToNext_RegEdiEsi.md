# Review A (reconstruction fidelity): `aa_00411e40` CNDHash_TraverseToNext_RegEdiEsi

| Field | Value |
|---|---|
| **Stable ID** | `aa_00411e40` |
| **VA** | `0x00411e40`–`0x00411e80` inclusive (**65 B** / `0x41`) |
| **Canonical name** | `CNDHash_TraverseToNext_RegEdiEsi` |
| **Ghidra name** | `FUN_00411e40` |
| **Review date** | `2026-08-05` (MEGA-114 OWN dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00411e40_CNDHash_TraverseToNext_RegEdiEsi.md` |
| **System** | interaction-activation / CNDHash container |
| **Live tools** | Ghidra `decompile_function`, `force_decompile`, `get_function_by_address`, `disassemble_function`, `read_memory`, `get_function_callers`, `get_xrefs_to`, `get_function_callees` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose (behavioral)

**CNDHash ordered-list iterator step** under an already-held traversal lock — **register-ABI twin** of dualed `CNDHash_TraverseToNext` (`0x00411900`):

1. If `*(hash+0x1d) == 0` → log `"HashError:TraverseToNext, not locked for traversal"` + `"VOG_DEBUG_STOP"` (**continues**; does **not** return early).
2. Cursor `*ESI`:
   - If **0** → seed from list head `*(hash+0x14)`; write cursor.
   - Else → advance `cursor = *(cursor+0x14)` (list-next @ **+0x14** on 0x1c-class nodes).
3. If cursor node non-null → return **payload** `*(node+8)`.
4. Else → return **0**.

Does **not** mutate membership, lock byte, or freelist.

> **Node layout note:** Same family as dualed twin: **+0x14** next / **+8** value. Inventory 64-bit nodes (**+0x20** links / **+0xc** value) are a different layout — do not mix.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile A≡B | `decompile_function` ≡ `force_decompile` @ `0x00411e40` |
| Machine | `read_memory` length 80; `disassemble_function` |
| Function range | entry `00411e40`, body through `RET` @ `00411e80` |
| Callers | `get_function_callers` (6 named) + 11 `get_xrefs_to` CALL sites |
| Parent sample | `Client_UpdateNpcInteractIcons` `0x0091b8d0` (partition parent) |
| Twin (READ) | dualed `aa_00411900` CNDHash_TraverseToNext |
| Raw / annotated / clean | see function record |

---

## 3. Authoritative body (live 2026-08-05)

**Decompile** (register args as `unaff_*`):

```c
undefined4 FUN_00411e40(void)
{
  int iVar1;
  int *unaff_ESI;
  int unaff_EDI;

  if (*(char *)(unaff_EDI + 0x1d) == '\0') {
    FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }
  if (*unaff_ESI == 0) {
    *unaff_ESI = *(int *)(unaff_EDI + 0x14);
    iVar1 = *(int *)(unaff_EDI + 0x14);
  } else {
    iVar1 = *(int *)(*unaff_ESI + 0x14);
    *unaff_ESI = iVar1;
  }
  if (iVar1 != 0) {
    return *(undefined4 *)(iVar1 + 8);
  }
  return 0;
}
```

**Assembly seal** (branch polarity inverted vs decompile `if (*cursor==0)` but equivalent):

```text
00411e40  CMP byte ptr [EDI+0x1d],0
00411e44  JNZ  00411e61
          … dual FUN_007a4480 + ADD ESP,0x10 …
00411e61  MOV  EAX,[ESI]
00411e63  TEST EAX,EAX
00411e65  JZ   00411e6e          ; null → seed head
00411e67  MOV  EAX,[EAX+0x14]    ; next
00411e6a  MOV  [ESI],EAX
00411e6c  JMP  00411e76
00411e6e  MOV  EAX,[EDI+0x14]    ; head
00411e71  MOV  [ESI],EAX
00411e73  MOV  EAX,[EDI+0x14]
00411e76  TEST EAX,EAX
00411e78  JZ   00411e7e
00411e7a  MOV  EAX,[EAX+8]       ; payload
00411e7d  RET
00411e7e  XOR  EAX,EAX
00411e80  RET
```

---

## 4. Signature (sealed)

```c
// EDI = CNDHash* hash; ESI = node** cursor; EAX = payload|0; bare RET
uint32_t CNDHash_TraverseToNext_RegEdiEsi(void /* regargs */);
```

| Slot | Source | Conf |
|---|---|---|
| hash | **EDI** (`[EDI+0x1d]`, `[EDI+0x14]`) | **High** |
| cursor | **ESI** (`[ESI]`, store back) | **High** |
| return | **EAX** = `[node+8]` or 0 | **High** |
| cleanup | bare **`RET`** ×2 exits | **High** |
| stack args | **none** | **High** |

Call-site seal (`0x0091be73`): `mov edi,[client+0x6f0]`; `lea esi,[esp+0x1c]`; `call`.

---

## 5. Confidence

| Claim | Level |
|---|---|
| CF sealed decompile A≡B ≡ raw ≡ bytes | **High** |
| Product role TraverseToNext | **Confirmed** (string `0x00a27c9c`) |
| Register ABI EDI/ESI | **High** (asm + call sites) |
| Returns payload not node | **Confirmed** |
| Lock log non-fatal | **Confirmed** |
| Universal node layout across all CNDHash | **False** — 0x1c vs inv 0x28 |
| Payload product English per host | **Open** |
| Runtime / bit-exact | **Open** |

**Verdict:** **accept-with-gaps.**
