# Review B (skeptical / adversarial): `aa_00811e00` Client_ProcessSectorUpdate_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00811e00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W26-M) |
| **Counterpart** | `reviews/A_aa_00811e00_Client_ProcessSectorUpdate_Inferred.md` |
| **Scratch** | `tmp/a_00811e00.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Pure `__thiscall` with only ECX+stack; no object formal | **Falsified** — prologue `MOV EDI,EAX` / `MOV ESI,ECX`; callers leave object in EAX (W24-Q `FUN_00814400` dual) |
| 2 | This is the create path | **Falsified** — create is `FUN_008120d0` immediately after pads; this unit updates existing objects |
| 3 | Ghidra `void FUN_00811e00(void)` is ABI | **Falsified** — `RET 4` + stack load `[EBP+8]` + ECX/EAX formals |
| 4 | Always applies transform | **Falsified** — early returns: `+0xA1`, bind match, partial identity, null physics |
| 5 | Name is retail symbol | **Overstated** — debug string supports ProcessSectorUpdate role; `_Inferred` kept |
| 6 | Single S2C opcode owns this VA | **Falsified** — **7** callers across recv family |
| 7 | Live decompile drifted from raw | **Falsified** — live 2026-07-29 ≡ raw 2026-07-23 body |
| 8 | Nested `FUN_004e87d0` CF sealed here | **Out of ownership** — residual gap only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Multi-reg ABI ECX/EAX/stack | **High** | Corrupt update / wrong object |
| Body size + RET 4 | **High** | Boundary merge with create |
| ProcessSectorUpdate string role | **High** | Naming only if wrong |
| Offset map used in branches | **High** | Wrong flag/transform apply |
| Nested helper interiors | **Medium** | Incomplete physics port |
| Product packet English | **Open** | Doc-only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  OutputDebugStringA("Requesting ProcessSectorUpdate\n")
  if packet[0xA1]: vtbl+0xC4; FUN_009972a0; FUN_008024d0; ret
  if bind match obj[0x2B]: ret
  if (id_lo & id_hi) != -1: vtbl+0x260; ret
  merge flag A8 → obj+0x17C bit2
  optional FUN_0092a200 mark
  phys = vtbl+0x1CC; copy transform; apply helpers

bytes:
  55 8B EC 83 E4 F0 83 EC 34 53 8B 5D 08 56 57 68 7C F1 A7 00 8B F8 8B F1 …
  … 5F 5E 5B 8B E5 5D C2 04 00 | CC… | FUN_008120d0
```

No conflict on sealed CF among raw, live decompile, and prologue/epilogue bytes.

---

## 4. Surviving contract for AutoCore

```
// When porting create-or-update handlers:
//   if resolve hit → Client_ProcessSectorUpdate_Inferred(packet, game) with object in EAX
//   if miss → create (FUN_008120d0)
// Preserve multi-reg ABI. Honor packet+0xA1 early path and bind-skip.
// Transform source: packet +0x64..+0x7C → object +0x80.. ; physics via vtbl+0x1CC.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/string/body bounds; nested helpers and product English remain gaps → **accept-with-gaps**.
