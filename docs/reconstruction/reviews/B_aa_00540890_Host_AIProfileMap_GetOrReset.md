# Review B (skeptical / adversarial): `aa_00540890` Host_AIProfileMap_GetOrReset

| Field | Value |
|---|---|
| **Stable ID** | `aa_00540890` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W26-N) |
| **Counterpart** | `reviews/A_aa_00540890_Host_AIProfileMap_GetOrReset.md` |
| **Scratch** | `tmp/a_00540890.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + callers. **No** `disassemble_bytes`. Own VA `0x00540890` only.

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Always clears the map | **Falsified** — skip when `size!=0 && forceReset==0` |
| 2 | cdecl / no this | **Falsified** — `MOV EDI,ECX`; `RET 4` |
| 3 | Returns void / bool | **Falsified** — `LEA EAX,[EDI+0xF00]` |
| 4 | Map lives at `+0x100` | **Falsified** — `0xF00` / `0xF04` / `0xF08` immediates |
| 5 | This is the lower_bound itself | **Falsified** — no key walk; callers use `FUN_004cbd50` |
| 6 | `FUN_007c3b80` is thiscall on map | **Falsified** — ECX loaded from `DAT_00b0469c`; map is stack arg |
| 7 | Product name plate-sealed | **Overstated** — role from callers; no local string |
| 8 | Live ≠ raw | **Falsified** — identical CF |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall RET 4 + EAX map | **High** | ABI break |
| Clear gate + sentinel re-link | **High** | use-after-free / empty tree |
| Offsets 0xF00/F04/F08 | **High** | wrong container |
| HBAI profile role | **High** | wrong table pairing |
| Product English | **Probable** | naming only |
| `FUN_007c3b80` body | **Partial** | side effects after clear |
| Runtime | **Open** | matrix |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  if size==0 || forceReset: clear tree; FUN_007c3b80(map)
  return host+0xF00

bytes:
  57 8B F9 83 BF 08 0F 00 00 00 …
  80 7C 24 08 00 74 3D
  8B 0D 9C 46 B0 00 56 E8 …
  8D 87 00 0F 00 00 5F C2 04 00
```

**No conflict** on owned ABI/CF/layout.

---

## 4. Surviving contract for AutoCore

```
// Host_AIProfileMap_GetOrReset @ 0x00540890
// ECX = host (global DAT_00b041fc at HBAI sites); forceReset stack; RET 4
// EAX = &host->profileMap  // +0xF00

map = Host_AIProfileMap_GetOrReset(host, 0);
// FUN_004cbd50(&it, &key);  // lower_bound
// end_it = *(node**)(map + 4);  // head
```

Port rules:

- Treat as **get-with-optional-reset**, not pure getter and not lower_bound.
- Preserve **skip clear** when size≠0 and forceReset==0 (hot HBAI path).
- End-iterator compare uses **head at map+4**, matching MSVC map.
- Do not invent product host class name without plate evidence.

---

## 5. Verdict

Adversarial pass **confirms** A on CF/ABI/layout; product English + nested `FUN_007c3b80` residual → **accept-with-gaps**.
