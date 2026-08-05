# Review B (skeptical / adversarial): `aa_0063a700` CVOGHBAIBase_SetFloat0x2c

| Field | Value |
|---|---|
| **Stable ID** | `aa_0063a700` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0063a700_CVOGHBAIBase_SetFloat0x2c.md` |
| **Verdict** | **accept-with-gaps** on CF (float store + callers sealed; product field name open) |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Integer dword store only | Bytes are `movss`/`movss` | **Falsified as int-only** — SSE float |
| 2 | Zero-arg / no stack cleanup | `ret 4` + `push 0` at callers | **Falsified** |
| 3 | Mutates more than one field | Body is load+store+ret only | **Falsified** |
| 4 | Unique to Default_ctor | Also Turreted_ctor + 5 DATA vtbl slots | **Falsified as Default-only** |
| 5 | Field is `param_1[0x1f]` / `+0x7c` (the 1.0f seed) | Store offset is `+0x2c` not `+0x7c` | **Falsified** — distinct field |
| 6 | `push 0` is integer zero distinct from float | IEEE 0.0f bit pattern is 0 | **Survives as 0.0f** for SSE path |
| 7 | Canonical name is studio PDB symbol | No PDB evidence | **Gap** — role name only |
| 8 | Hidden non-vtbl callees | xrefs: 2 CALL + 5 DATA only | **Falsified** (within Ghidra static xrefs) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Single float store at `+0x2c` | **High** | Wrong HBAI layout |
| `__thiscall` + stack float + `ret 4` | **High** | Bad ABI in ports |
| Ctor init to 0.0f | **High** | Wrong default state |
| Vtbl[+0x20] method | **High** | Miss virtual calls |
| Product meaning of field | **Open** | Misnamed docs only |
| Runtime / process | **Open** | Unverified live |

---

## 3. Cross-check raw + live bytes

```
0063a700  movss xmm0, dword [esp+0x4]   ; stack float
0063a706  movss dword [ecx+0x2c], xmm0  ; this+0x2c
0063a70b  ret 4
```

Decompiler body (2026-07-29) matches 2026-07-23 raw shape; live bytes **upgrade type** to float. Caller sites:

```
; Default_ctor @ 0x0063c95x
push 0
mov  ecx, esi
...
call FUN_0063a700          ; 0x0063c966

; Turreted_ctor @ 0x0063984x
push 0
mov  ecx, esi
...
call FUN_0063a700          ; 0x00639860
```

Vtbl dword at `0x009e3ce0` = `00 a7 63 00` → `0x0063a700`.

---

## 4. Surviving contract for AutoCore

```
HBAI.float_at_0x2c = value;   // via this setter or vtbl[+0x20]
// ctors of Turreted / Default zero it
// do not confuse with float_at_0x7c (seeded 1.0f in same ctors)
```

No server port required unless HBAI AI state is server-simulated with this field.

---

## 5. Gaps surviving attack

1. Product name / gameplay meaning of `+0x2c`.
2. Dynamic vtbl call inventory.
3. Runtime verification.

**Verdict:** **accept-with-gaps**
