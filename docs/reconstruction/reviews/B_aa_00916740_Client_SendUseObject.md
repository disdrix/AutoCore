# Review B (skeptical / adversarial): `aa_00916740` Client_SendUseObject

| Field | Value |
|---|---|
| **Stable ID** | `aa_00916740` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual residual refresh — packet / opcode / TFID / callers) |
| **Counterpart** | `reviews/A_aa_00916740_Client_SendUseObject.md` |
| **Verdict** | **accept-with-gaps** on CF (static residuals sealed; pad/runtime open) |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Requires interactable check inside function | Body is pure pack+send | **Falsified** — gates are callers |
| 2 | Objective always a real id | Miss path writes `0xFFFFFFFF` | **Falsified** |
| 3 | Same packet semantics as IfInteractable | Sibling may send objective **0** (type-4); no `+0xd28`; net via `client+0xc78` | **Falsified** |
| 4 | Match key is object pointer | Key is `*( *(obj+0xa8)+0x34 )` | **Falsified** |
| 5 | Client distance 30f here | No distance in body; click uses **25.0f** | **Falsified** |
| 6 | Opcode might be outside the 0x20 buffer | `MOV [ESP],0x2072` then send size `0x20` from same base | **Falsified** — opcode **in** buffer |
| 7 | TFID is field-built (Coid/Global writes) | Four raw dwords from `obj+0x160` | **Falsified** — bulk copy |
| 8 | FindObjective this == client ECX | `MOV ECX,[0x00d1b6d8]` before CALL; client was ECX only for stash | **Falsified** — character global |
| 9 | Net global is unknown / speculative only | `MOV ECX,[0x00d1b4b8]` then vtbl`+0x18` | **Falsified as “unknown address”** — VA sealed; C++ type still open |
| 10 | Extra hidden callers | `get_function_callers` + 4 xrefs only | **Falsified** — three parents, four CALL sites |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| `0x2072` / `0x20` | **High** | Wrong C2S |
| Layout table (opcode/pad/TFID/obj) | **High** | Misaligned parse |
| TFID bulk 16 B @ `obj+0x160` | **High** | Wrong target |
| Objective −1 fallback | **High** | Wrong turn-in id |
| EAX target / ECX client entry | **High** | Wrong stash/object |
| FindObjective this `DAT_00d1b6d8` | **High** | Wrong objective walk |
| Net `DAT_00d1b4b8` | **High** (addr) / **Tentative** (type) | Send no-op if null; type rename risk only |
| Pad `@+0x04` / trail `@+0x1c` value | **Open** | Server ignore vs garbage-sensitive reader |
| Callers complete | **High** | Missed send path |

---

## 3. Cross-check against raw + listing

```
; entry: ECX=client, EAX=target  (all 4 CALL sites set both)
SUB ESP, 0x20
[ECX+0xd28] = EAX

; TFID_16 bulk
EDX = EAX+0x160
[ESP+0x08..0x14] = *[EDX .. EDX+0xc]   ; 4 dwords

[ESP+0x00] = 0x2072
; [ESP+0x04] NEVER WRITTEN
; [ESP+0x1c] NEVER WRITTEN

ECX = [DAT_00d1b6d8]
PUSH *( *[target+0xa8] + 0x34 )
CALL Client_FindObjectiveMatchingTarget   ; 0x00525bd0
[ESP+0x18] = (EAX==0) ? -1 : *(EAX+0x10)

ECX = [DAT_00d1b4b8]
if ECX: vtbl+0x18(-1, packet, 0x20, 0)
ADD ESP, 0x20; RET
```

Decompiler `local_20`/`local_18`/`local_8` map 1:1 to these ESP offsets. Body 2026-07-29 re-decompile ≡ 2026-07-23 raw; listing closes pad/trail and global VAs.

---

## 4. Callers (adversarial completeness)

| Parent | Sites | Could EAX/ECX be wrong? |
|---|---|---|
| Click pick | `0x00924ee5` | **No** — `EAX=[EBX+0x758]`, `ECX=EBX` immediate pre-CALL |
| Poll bound | `0x00927be1` | **No** — `EAX=EDI`, `ECX=EBX` immediate pre-CALL |
| RecvCompleteDynamicObjective | `0x0081004c`, `0x008100fa` | **Low residual** — ECX=`DAT_00d1b778` sealed; EAX from resolve/iter (dataflow hits call boundary / loop); still “world object*” by surrounding CMP `clone+0x34` |

Attack “Recv path might call with garbage EAX”: only after non-null world object and id match branches — not a free CALL.

---

## 5. Surviving contract for AutoCore

```
On UseObject (unconditional client path aa_00916740):
  C2S buffer size 0x20:
    +0x00 = 0x2072
    +0x04 = pad (client does not store; server skips 4 after opcode)
    +0x08 = TFID_16 bulk from worldObject+0x160
    +0x18 = IDObjective = matching active objective id OR -1
    +0x1c = unwritten trailer (within size; server stops after objective)
  stash last-use target at client+0xd28
  FindObjectiveMatchingTarget(this=DAT_00d1b6d8, key=clonebase+0x34)
  send via DAT_00d1b4b8 vtbl+0x18 if non-null
Server must still range-gate (~25–30f product).
Do not assume this path ran interactable prechecks.
Sibling IfInteractable is a different contract (gates, objective 0, client+0xc78, no +0xd28).
```

---

## 6. Open questions

1. Pad `@+0x04` / trail `@+0x1c` on live wire (need capture or proven frame zero).
2. `DAT_00d1b4b8` vs `client+0xc78` identity (sibling dual-path).
3. Runtime interact capture with real objective id.
4. C++ types of `DAT_00d1b6d8` / `DAT_00d1b778` / `DAT_00d1b4b8` (roles sealed).

**Verdict:** **accept-with-gaps** on CF — adversarial falsifications hold; residual packet/opcode/TFID/callers **closed** at static level.
