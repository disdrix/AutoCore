# Review B (skeptical / adversarial): `aa_005b3f60` Obj_DefaultCtor_SetVtbl_EmptyListAt10_ZeroF4At20

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b3f60` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W30-O) |
| **Counterpart** | `reviews/A_aa_005b3f60_Obj_DefaultCtor_SetVtbl_EmptyListAt10_ZeroF4At20.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompile alone is sufficient layout | **Partial fail** — hides `LEA EDI,[ESI+0x10]`; indexes `[5]/[6]` equal `+0x14`/`+0x18` but list base must be stated |
| 2 | Zeros are integer dword stores | **Overstated** — bytes are `xorps` + `movss` (bit-identical zero; float intent) |
| 3 | This also populates the list | **Falsified** — size left 0; populate is separate (`FUN_005b3fa0` after store at host+`0xe4fc`) |
| 4 | Object size unknown | **Falsified** — both callers `PUSH 0x30` / `operator_new(0x30)` |
| 5 | Product class known from vtbl neighborhood | **Falsified** — rdata after slot is `"vs.1.1…"` shader text |
| 6 | Name is retail symbol | **Overstated** — structural inferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Vtbl + empty list@+0x10 + F4 zero | **High** | Wrong object init / list UAF on dtor |
| Size 0x30 | **High** | Alloc mismatch |
| Default-only (no populate) | **High** | Double-init or missing grid |
| Product English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against bytes + callers

```
; FUN_004cd8f0 / FUN_004cd9a0
PUSH 0x30
CALL operator_new
MOV ECX,EAX
CALL 005b3f60
MOV [host+0xe4fc], EAX
; then separate populate — not inside 005b3f60
```

```
; body bytes (authority)
MOV ESI, ECX
LEA EDI, [ESI+0x10]
MOV [ESI], 0x009d95b4
CALL 005b43b0          ; sentinel
MOV [EDI+4], EAX / [EDI+8]=0
MOVSS [ESI+0x20..0x2c], 0
MOV EAX, ESI / RET
```

Dtor twin `005b3b20`: `ADD ECX,0x10` then `StdList_Destroy_FreeHead` — matches list placement.

---

## 4. Surviving contract for AutoCore

```
// Port default ctor only:
*this = vtbl_009d95b4;
list = this+0x10;
list->head = BuySelfLinkedSentinel_0x30();
list->size = 0;
*(float*)(this+0x20..0x2c) = 0;
// Do NOT populate list here.
// Do NOT claim product class name.
```

---

## 5. Verdict

Adversarial pass **confirms** A on bytes/ABI/callers and **rejects** “decompile-only layout” and “includes populate” → **accept-with-gaps**.
