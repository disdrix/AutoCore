# Review B (skeptical / adversarial): `aa_0058e370` CVOGObject_SetGfxBodyLink_Mode1AndTarget

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058e370` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W20-M) |
| **Counterpart** | `reviews/A_aa_0058e370_CVOGObject_SetGfxBodyLink_Mode1AndTarget.md` |
| **Verdict** | **accept** (trivial CF; residual is naming / mode enum only) |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus xrefs / sibling decompiles for role claims).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Related to `FUN_0058e300` / `0058e270` attach/detach physics helpers | **Falsified as identity** — those call `0096d550`/`0096dc80`; this unit only stores mode+ptr |
| 2 | Always writes even if gfxBody missing | **Falsified** — dual null gates |
| 3 | Mode written is 9 (create default) | **Falsified** — bytes `c6 02 01` |
| 4 | `__stdcall` / multi-arg stack | **Falsified** — thiscall + `ret 4` |
| 5 | Allocates the packet | **Falsified** — only writes existing packet; alloc is in `0058f780` |
| 6 | Many callers / generic leaf | **Falsified for fan-out** — **one** CALL xref (`004b73c0`) |
| 7 | `+0x914` is unrelated float/stat | **Falsified** — gfxBody string + create path |
| 8 | Parent-seed Client_PacketDispa chain names the purpose | **Falsified** — seed noise; body is gfx link arm |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Store-only leaf | **High** | inventing notify/free breaks silent no-ops |
| Offsets 0x914 / 0x78 | **High** | wrong object field map |
| Mode constant 1 | **High** | wrong arm state vs teardown mode 9 |
| Single-caller role | **High** | over-generalizing as shared API |

---

## 3. Cross-check against raw + bytes

```
mov  eax, [ecx+0x914]
test eax, eax / jz done
cmp  [eax+0x78], 0 / jz done
mov  byte [packet], 1
mov  [packet+4], arg
ret  4
```

Any clean plate calling graphics APIs, freelist, or writing mode 9 is **wrong for this VA**.

---

## 4. Surviving contract for AutoCore

```c
// Port: null-safe arm of gfxBody link packet
void CVOGObject_SetGfxBodyLink_Mode1AndTarget(Object *self, void *target)
{
  auto *body = self->gfxBody;           // +0x914
  if (!body || !body->linkPacket) return; // +0x78
  body->linkPacket->mode = 1;           // +0
  body->linkPacket->assoc = target;     // +4
}
```

Do not invent mode-1 consumers here; seal those at their own VAs.

---

## 5. Open questions

1. Mode enum product labels (1 vs 9).
2. Whether server needs an equivalent (likely client-only gfx).

**Verdict:** **accept**
