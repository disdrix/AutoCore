# Review B (skeptical / adversarial): `aa_00925580` Client_SendItemPickup

| Field | Value |
|---|---|
| **Stable ID** | `aa_00925580` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00925580_Client_SendItemPickup.md` |
| **Verdict** | **accept-with-gaps** on CF (opcode/size/layout/callers closed; product residuals open) |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This is UseObject / `0x2072` | Imm is `0x2055`; size `0x30` ≠ `0x20` | **Falsified** |
| 2 | Opcode might be QuestItemPickup `0x205D` | Bytes `55 20 00 00` not `5D 20`; click type-4 is different unit | **Falsified** |
| 3 | Size is body-only without opcode | `push 0x30` with buffer base containing opcode at +0 | **Falsified** — size **includes** opcode |
| 4 | Full 16-byte TFID copied from object `+0x160` | Only `ESI[0], ESI[1]`; rest zeroed | **Falsified** — 8 B from ESI + zeros |
| 5 | `UnknownField` is a meaningful client constant | `+0x04` never written | **Falsified** as “client-authored field” — pad residual |
| 6 | Always sends when called | Multi-gate silent return | **Falsified** as unconditional send |
| 7 | Stack ABI / stdcall args carry TFID | All callers use **ESI** only | **Falsified** as stack-param |
| 8 | Hidden fourth caller | `get_function_callers` + 3 xrefs only | **Falsified** |
| 9 | Float `@+0x28` is live time | Store is load of **global constant** `0.001f` | **Falsified** as dynamic timestamp |
| 10 | Server must consume all 0x30 | AutoCore reads pad4+TFID16 only | **Not required** by client — slack OK |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| `0x2055` / `0x30` | **High** | Wrong C2S identity |
| Layout (opcode/pad/TFID8/zeros/float) | **High** | Misaligned parse |
| ESI pair ABI | **High** | Wrong target coid |
| Global forced 0 | **High** | Wrong local/global item |
| EAX=8 Ordered | **High** | Delivery class |
| Gate product names | **Tentative** | Doc only |
| Float product role | **Tentative / Open** | Ignore-safe on server |
| Runtime | **Open** | Unverified live wire |

---

## 3. Cross-check raw + live bytes

```
SUB ESP, 0x30
CMP [DAT_00d1b4b0], 0 / JNE out
EAX = [DAT_00d1b6d8]
CMP [EAX+0xcd0], 0 / JNE out
ECX = [EAX+0xcd8] & [EAX+0xcdc]
CMP ECX, -1 / JNE out
EDX = [ESI] & [ESI+4]
CMP EDX, ECX(= -1) / JE out     ; invalid TFID pair
; vtbl+0x194, DAT_00d1b958+0x3d8, DAT_00d1b95c+0x3d8 — any nonzero → out
XORPS XMM0,XMM0
ECX=[ESI]; EDX=[ESI+4]
LEA EAX,[ESP]; PUSH EAX          ; buffer*
; zero pkt+0x10..+0x27 via movss
MOV [ESP+0x0C], ECX              ; → pkt+0x08 after accounting
PUSH 0x30
MOV EAX, 8
MOV ECX, DAT_00d1a840
MOVSS [ESP+0x30], [0x00a0f72c]   ; pkt+0x28 = 0.001f
MOV [ESP+0x08], 0x2055           ; pkt+0x00
MOV [ESP+0x14], EDX              ; pkt+0x0c
CALL Client_SendSectorPacket
ADD ESP, 0x30
RET
```

Decompiler `auStack_30[0]=0x2055` and `Client_SendSectorPacket(...,0x30,...)` map 1:1. Live body ≡ 2026-07-23 raw.

---

## 4. Surviving contract for AutoCore

```
On ItemPickup C2S (client path aa_00925580):
  Total size 0x30 including opcode:
    +0x00 = 0x2055
    +0x04 = pad (unwritten)
    +0x08 = TFID_16 with Global/pad forced 0 after first 8 B from gather pair
    +0x18..+0x27 = zero
    +0x28 = 0.001f constant (ignore-safe)
    +0x2c = unwritten trailer
  Server may:
    strip opcode; ReadInt32 pad; ReadTFID; resolve map object by Coid;
    range-gate (AutoCore currently 10u; client gather 20f — server policy).
  Do not require UnknownField meaningful.
  Do not treat as UseObject.
```

---

## 5. Open questions

1. Gate object names (`DAT_00d1b958/95c`, char `+0xcd0` family).
2. Float `@+0x28` design intent.
3. Live capture of Activate → 0x2055 exclusive vs UseObject.
4. Whether `FUN_00925820` path is UI-confirm vs auto (parent residual).

**Verdict:** **accept-with-gaps** — adversarial checks hold; **opcode/size sealed**.
