# Review B (skeptical / adversarial): `aa_00404c60` Object_Store16At80_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404c60` |
| **VA** | `0x00404c60` |
| **Canonical name** | `Object_Store16At80_Inferred` |
| **Review date** | `2026-08-05` (MEGA-053 dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00404c60_Object_Store16At80_Inferred.md` |
| **Live tools** | Independent `decompile_function` + `read_memory` + analyze/xrefs + `disassemble_function` + assembly context + twin `00404c30` disasm |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This **is** the skill invalid-template / invalid-creature **string formatter** | **Falsified** — no strings, no format callees; parents own `"Skill %d had invalid template %d."` etc. |
| 2 | Out-copy / getter (like TFID copy @ +0x228 / +0x668) | **Falsified** — writes **to** `[ECX+0x80..]`, not from this to out |
| 3 | Same as twin `00404c30` | **Falsified** — twin dest **+0x90..0x9c**; this is **+0x80..0x8c** |
| 4 | cdecl / no stack cleanup | **Falsified** — body ends **`RET 4`** (`C2 04 00`); call sites push 1 arg |
| 5 | Stack = this / ECX = src | **Falsified** — `MOV EAX,[ESP+4]` then stores to **`[ECX+imm]`**; call sites `MOV ECX,obj` + `PUSH src` |
| 6 | Size ≠ 16 / different offsets | **Falsified** — four stores imm **80/84/88/8C** |
| 7 | Branches / callees / SEH | **Falsified** — straight-line leaf |
| 8 | Must be float4 / quaternion only | **Unproven** — body is dword moves; callers pack floats **or** other dwords; product English open |
| 9 | Runtime Confirmed | **Fails** — open (no Launcher) |

---

## 2. Decisive machine dataflow

```text
MOV EAX, [ESP+4]           // src
MOV EDX, [EAX]
MOV [ECX+0x80], EDX        // this[0x80] = src[0]
MOV EDX, [EAX+4]
MOV [ECX+0x84], EDX
MOV EDX, [EAX+8]
MOV [ECX+0x88], EDX
MOV EAX, [EAX+0xC]
MOV [ECX+0x8C], EAX
RET 4
```

Call-site example (skill path @ `0x0058a265`):

```text
PUSH EAX          // src
MOV ECX, EDI      // object this
CALL 0x00404c60
// often: PUSH / MOV ECX,EDI / CALL 0x00404c30  (twin @ +0x90)
```

Call-site example (template path @ `0x0062061f`):

```text
LEA ECX, [EDX+EDI*1+4]   // multi-inh this adjust
PUSH EAX                 // &stack blob
CALL 0x00404c60
// then twin 00404c30; parent may log "Skill %d had invalid template %d." on other branch
```

A ≡ B on live decompile + body hex + xrefs + assembly context + twin offset.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 16 B store @ +0x80 CF | **High** | wrong field layout |
| thiscall + RET 4; ECX=dst | **High** | stack smash |
| Caller set (4) | **High** | missing consumer |
| Direction into this | **High** | port inverted |
| Product field English | Medium | naming only |
| Skill-string identity | **Falsified** | mis-system plate |

---

## 4. Surviving contract for AutoCore

```csharp
// Store 16 bytes into object field block at +0x80.
// thiscall; one stack arg; RET 4. Leaf.
void Store16At80(Object obj, ReadOnlySpan<byte> src16 /* length 16 */)
{
    // dword-equivalent:
    // obj.field80[0..3] = src as 4× uint32
    Buffer.BlockCopy(src16.ToArray(), 0, /* obj base + 0x80 */, 0, 16);
}
// Keep distinct from twin Store16At90 (00404c30) and from TFID *out-copy*
// helpers (0040aff0 / 0061b960). Do not invent skill format strings here.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/caller inventory/direction. Residual product field English + twin dual open → **accept-with-gaps**.
