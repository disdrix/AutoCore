# Review B (skeptical / adversarial): `aa_00404c30` Object_Store16At90_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404c30` |
| **VA** | `0x00404c30` |
| **Canonical name** | `Object_Store16At90_Inferred` |
| **Review date** | `2026-08-05` (R10-022 dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00404c30_Object_Store16At90_Inferred.md` |
| **Live tools** | Independent `decompile_function` + `read_memory` + analyze/xrefs + `disassemble_function` + assembly context + twin `00404c60` evidence |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This **is** the skill invalid-template / invalid-creature **string formatter** | **Falsified** — no strings, no format callees; parents own skill strings |
| 2 | Out-copy / getter (like TFID copy @ +0x228 / +0x668) | **Falsified** — writes **to** `[ECX+0x90..]`, not from this to out |
| 3 | Same as twin `00404c60` | **Falsified** — twin dest **+0x80..0x8c**; this is **+0x90..0x9c** |
| 4 | cdecl / no stack cleanup | **Falsified** — body ends **`RET 4`** (`C2 04 00`); call sites push 1 arg |
| 5 | Stack = this / ECX = src | **Falsified** — `MOV EAX,[ESP+4]` then stores to **`[ECX+imm]`**; call sites `MOV/LEA ECX,obj` + `PUSH src` |
| 6 | Size ≠ 16 / different offsets | **Falsified** — four stores imm **90/94/98/9C** |
| 7 | Branches / callees / SEH | **Falsified** — straight-line leaf |
| 8 | Must be float4 / quaternion only | **Unproven** — body is dword moves; callers pack floats **or** other dwords; product English open |
| 9 | Only 4 callers (miss 00812360) | **Falsified** — live xrefs = **5** including `FUN_00812360` |
| 10 | Runtime Confirmed | **Fails** — open (no Launcher) |

---

## 2. Decisive machine dataflow

```text
MOV EAX, [ESP+4]           // src
MOV EDX, [EAX]
MOV [ECX+0x90], EDX        // this[0x90] = src[0]
MOV EDX, [EAX+4]
MOV [ECX+0x94], EDX
MOV EDX, [EAX+8]
MOV [ECX+0x98], EDX
MOV EAX, [EAX+0xC]
MOV [ECX+0x9C], EAX
RET 4
```

Call-site example (skill path @ `0x0058a271`):

```text
// after twin CALL 0x00404c60
PUSH ECX          // src
MOV ECX, EDI      // object this
CALL 0x00404c30
```

Call-site example (physics load @ `0x005c7804`):

```text
// after twin CALL 0x00404c60
PUSH EDX
LEA ECX, [ECX+ESI*1+4]   // multi-inh this adjust
CALL 0x00404c30
```

Call-site example (client pack @ `0x0091dcad`):

```text
// FUN_004e8dc0 packs float basis into stack buffer
PUSH ECX
LEA ECX, [ECX+EAX*1+4]
CALL 0x00404c30
```

A ≡ B on live decompile + body hex + xrefs + assembly context + twin offset.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 16 B store @ +0x90 CF | **High** | wrong field layout |
| thiscall + RET 4; ECX=dst | **High** | stack smash |
| Caller set (5) | **High** | missing consumer |
| Direction into this | **High** | port inverted |
| Product field English | Medium | naming only |
| Skill-string identity | **Falsified** | mis-system plate |

---

## 4. Surviving contract for AutoCore

```csharp
// Store 16 bytes into object field block at +0x90.
// thiscall; one stack arg; RET 4. Leaf.
void Store16At90(Object obj, ReadOnlySpan<byte> src16 /* length 16 */)
{
    // dword-equivalent:
    // obj.field90[0..3] = src as 4× uint32
    Buffer.BlockCopy(src16.ToArray(), 0, /* obj base + 0x90 */, 0, 16);
}
// Keep distinct from twin Store16At80 (00404c60) and from TFID *out-copy*
// helpers (0040aff0 / 0061b960). Do not invent skill format strings here.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/caller inventory/direction. Residual product field English + runtime open → **accept-with-gaps**.
