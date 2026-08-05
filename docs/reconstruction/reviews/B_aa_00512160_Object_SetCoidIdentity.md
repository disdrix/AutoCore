# Review B (skeptical / adversarial): `aa_00512160` Object_SetCoidIdentity

| Field | Value |
|---|---|
| **Stable ID** | `aa_00512160` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00512160_Object_SetCoidIdentity.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Allocates / validates COID | Body is three stores | **Falsified** — pure setter |
| 2 | Writes TFID at different offsets | Offsets are `+0x160/164/168` only | **Falsified** as other layout |
| 3 | Is stdcall free function | Decompiler `__thiscall`; ECX=object | **Survives** as thiscall |
| 4 | Flag at `+0x168` is “network dirty” etc. | No evidence in body | **Open** — semantic residual |
| 5 | Name conflicts with other identity writers | Registry sole proposed name for VA | **Survives** |

---

## 2. Live ≡ raw

```
// full function
mov byte  [ecx+0x168], arg_flag
mov dword [ecx+0x160], arg_lo
mov dword [ecx+0x164], arg_hi
ret
```

Clean scaffold and live decompile agree. No hidden calls.

---

## 3. Surviving contract

```
Object_SetCoidIdentity(this, coidLo, coidHi, flag)
  this[+0x160]=lo; this[+0x164]=hi; this[+0x168]=flag
```

**Verdict:** **accept**.
