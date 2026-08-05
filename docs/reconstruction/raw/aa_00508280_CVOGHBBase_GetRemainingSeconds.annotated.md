# Annotated low-level: CVOGHBBase_GetRemainingSeconds

| Field | Value |
|---|---|
| Stable ID | `aa_00508280` |
| VA | `0x00508280` |
| System | heartbeat / timed-actions |
| Date | 2026-07-29 (machine seal) |

---

## Machine-level notes

- Body: `0x00508280`–`0x005082b5` (54 bytes). No CALLs.
- ABI: `__thiscall`/`__fastcall` — `ECX = this`; float return in ST0; bare `ret`.
- Field loads (only):
  - `+0x14` → `dwLastFireTickMs`
  - `+0x08` → `nPeriodMs` (real pulse period; **not** sentinel)
  - `+0x10` → `nPeriodCounter`
- Globals:
  - `0x00b041cc` `g_dwClientTickMs`
  - `0x00aaa5dc` = `2^32` float (signed-neg fild assist)
  - `0x00a0f72c` `g_flMsToSeconds_Inferred` = **0.001f**
- Does **not** touch `+0x0C` (`nPeriodSentinel` / SetPeriodAndCounter target).

### Body disassembly (from `read_memory`, not `disassemble_bytes`)

```
51                    push  ecx                    ; fild scratch slot
8B 41 14              mov   eax, [ecx+0x14]
2B 05 CC 41 B0 00     sub   eax, [g_dwClientTickMs]
8B 51 08              mov   edx, [ecx+0x08]
03 C2                 add   eax, edx
79 02                 jns   short base_ok
33 C0                 xor   eax, eax
8B 49 10              mov   ecx, [ecx+0x10]
83 E9 01              sub   ecx, 1
0F AF CA              imul  ecx, edx
03 C8                 add   ecx, eax
85 C9                 test  ecx, ecx
89 0C 24              mov   [esp], ecx
DB 04 24              fild  dword [esp]
7D 06                 jge   short scaled
D8 05 DC A5 AA 00     fadd  dword [0x00aaa5dc]
D8 0D 2C F7 A0 00     fmul  dword [0x00a0f72c]
59                    pop   ecx
C3                    ret
```

Hex: `518b41142b05cc41b0008b510803c2790233c08b491083e9010fafca03c885c9890c24db04247d06d805dca5aa00d80d2cf7a00059c3`

---

## Pseudocode (annotated ≡ raw ≡ machine)

```c
/* TimedAction_GetRemainingSeconds — UI helper: remaining time until next fire as float seconds
   (integer ms * 0.001). Used for "Remaining" tooltips. */

float __fastcall CVOGHBBase_GetRemainingSeconds(CVOGHBBase *this)
{
  float fVar1;
  int iVar2;

  /* +0x14 lastFire, +0x08 period (NOT +0x0C sentinel) */
  iVar2 = (this->dwLastFireTickMs - g_dwClientTickMs) + this->nPeriodMs;
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  /* +0x10 counter multi-period stack */
  iVar2 = (this->nPeriodCounter + -1) * this->nPeriodMs + iVar2;
  fVar1 = (float)iVar2;
  if (iVar2 < 0) {
    fVar1 = fVar1 + _DAT_00aaa5dc; /* 2^32 */
  }
  return fVar1 * g_flMsToSeconds_Inferred; /* 0.001f @ 0x00a0f72c */
}
```

---

## Callers (code xrefs)

15 unconditional CALLs — primary named: `FUN_00578550` (Remaining tooltip), `FUN_00625b00` (readiness), `FUN_00955eb0` (debug combat dump ×4), plus `FUN_005b2830`, `FUN_00618180`, `FUN_00618bf0`, `FUN_0083b920`, and additional sites. See Review A inventory.

---

## Open questions

- Semantic names for remaining `FUN_*` consumers.
- Runtime tooltip vs field capture (deferred).
