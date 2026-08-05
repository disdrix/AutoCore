# Review B (skeptical / adversarial): `aa_0093d6e0` Client_InventoryGrabApplyToCursor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0093d6e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0093d6e0_Client_InventoryGrabApplyToCursor.md` |
| **Verdict** | **accept-with-gaps** on CF (ABI + switch sealed; product invType residual) |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Pure `__thiscall` on client | No `mov ecx` this; prologue uses **EAX/DL + 2 stack** | **Falsified** as thiscall |
| 2 | Decompiler `param_1` is first meaningful arg | Live: first stack = client after `push ebp`; EAX=item | **Falsified** — decompiler param order misleading |
| 3 | Always returns 1 on valid item | Case **2** returns **0** after vehicle sheet refresh | **Falsified as always-1** |
| 4 | Case 4 still removes from grid / sets qty | Gated `if (param_2 != 4)` around Find/Remove/qty | **Falsified** |
| 5 | This is the GrabResponse demux | Only callee; opcode/header live in `0x00811be0` | **Falsified** |
| 6 | `unaff_retaddr` is real API | Stack qty / decompiler retaddr bleed; call sites push qty | **Sealed as qty**, not return address |
| 7 | Hidden fourth caller | 3 UNCONDITIONAL_CALL only | **Falsified** |
| 8 | invType 0 is valid success path | default → return 0 | **Falsified** |
| 9 | `ret 4` | Bytes `c2 08 00` | **Falsified** — `ret 8` |
| 10 | Product name is Confirmed PDB | Registry proposed only | **Gap** — keep Probable / `_Inferred` if renamed in code |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX=item, DL=invType, stack client+qty, ret 8 | **High** | Wrong port ABI |
| Switch 1..5 + default fail | **High** | Miss dest window |
| Case 2 early return 0 + `FUN_008801b0` | **High** | Double-apply / missing vehicle UI |
| Case 4 skip remove/qty | **High** | Double-remove storage |
| FindByCoid + RemoveItem on non-4 | **High** | Ghost stacks |
| `+0x30b4/+0x30b5` success flags | **High** | Cursor chrome stuck |
| invType English labels | **Open** | Doc only |
| FUN_0085fd20 / 007fc270 product | **Open** | UI residual |
| Runtime / server parity | **Open** | Live desync |

---

## 3. Cross-check live prologue

```
0093d6e0  push ebp
0093d6e1  mov  ebp, [esp+8]     ; client*
0093d6e5  push edi
0093d6e6  mov  edi, eax         ; item*
0093d6e8  mov  eax, [ebp+0xe98] ; local char
0093d6ee  test eax, eax
0093d6f0  mov  byte [ebp+0xc70], 0
0093d6f7  jz   fail
0093d6f9  test edi, edi
0093d6fb  jnz  cont
fail:
0093d6fd  pop  edi
0093d6fe  xor  al, al
0093d700  pop  ebp
0093d701  ret  8
cont:
0093d704  movzx ecx, dl         ; invType
...
```

Grab site `0x00811d75..7c`: `mov dl,[ebx+0x18]`; `push [ebx+0x1c]` (qty); `push client`; `mov eax,item`; `call`.

---

## 4. Surviving contract for AutoCore

```c
// custom MSVC: EAX=item, DL=invType, stdcall-ish stack cleanup 8
bool Client_InventoryGrabApplyToCursor(Item* item /*EAX*/, uint8_t invType /*DL*/,
                                       Client* client, int qty);
```

- invType **2**: reparent via `vtbl+0x2ac`, refresh `client+0x1078` vehicle sheet, return **false**.
- invType **4**: reparent + UI only (no grid remove / qty stamp).
- invType **1/3/5**: optional grid remove if coid present, dec capacity, set qty, reparent, dirty flags, `FUN_00931d60`, return **true**.
- Null char/item or missing hosts → **false**.

---

## 5. Verdict

**accept-with-gaps** — adversarial checks seal ABI and case-2/4 special CF against decompiler noise. Do not promote invType product names without wire/UI strings.
