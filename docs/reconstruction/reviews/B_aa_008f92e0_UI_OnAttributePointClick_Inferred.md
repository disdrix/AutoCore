# Review B (skeptical / adversarial): `aa_008f92e0` UI_OnAttributePointClick_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008f92e0` |
| **VA** | `0x008f92e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_008f92e0_UI_OnAttributePointClick_Inferred.md` |
| **Verdict** | **accept-with-gaps** on CF (spend map + packet sealed; product pool naming + server authority open) |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This spends **`char+0x6CC`** attribute pool (`AddAttributePoints`) | Body only touches **`+0x6CE`** via `CVOGCharacter_AddSkillPoints` | **Falsified** — wrong pool sibling |
| 2 | `AddSkillPoints` **adds** delta | Dual `aa_005312c0`: **assigns** short; call site passes `pool-1` | **Falsified as +=** — set-to-(n-1) |
| 3 | Control IDs map linearly to offsets (`9C41→13C`, `9C42→13E`, …) | Getters: `9C41→+0x13E`, `9C42→+0x13C`, `9C43→+0x140`, `9C44→+0x142` | **Falsified** — IDs not offset-ordered |
| 4 | All four spend paths recalc vehicle heat | Only **`0x9C42`** calls `Vehicle_RecalcCombatPools` / `CalcHeatMaximum` | **Falsified** |
| 5 | Always sends sector packet after spend | `FUN_00807440` false → return `1` **without** send | **Falsified as always** |
| 6 | Empty pool returns failure `0` | `pool < 1` → **`return 1`** (message consumed) | **Falsified** |
| 7 | Arena only blocks via shared label | Cases share toast; last case inlines same string call | **Survives** as same policy |
| 8 | Hard stat cap 200 enforced on write | Get clamps to 200; **set stores get()+1 with no write clamp** | **Falsified as hard write cap** — soft get only |
| 9 | Function is direct CALLed from many sites | Single **DATA** xref `0x00a35a2c` | **Falsified as code xrefs** — table dispatch |
| 10 | `param_3` switch starts at 0 | Bytes: `lea ecx,[edx-0x9C40]`; cases 0..4 → IDs `0x9C40`..`0x9C44` | **Survives** |
| 11 | Opcode is skill-train `0x2059` | Packet word is **`0x205A`** | **Falsified** — distinct from skill-train family |
| 12 | `case 40000` also spends a point | Only `FUN_007fca10()` + return 1 | **Falsified** |
| 13 | Client write is server-authoritative alone | Optimistic local set + optional notify | **Gap** — server must re-validate; not proven here |
| 14 | Free pool product name = “skill points” because API name | Toast: **“attribute points”** | **Gap** — do not seal product glossary from RE symbol alone |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Signature thiscall + 2 args, `ret 8` | **High** | Wrong UI dispatch binding |
| Gate: local char / event 8 / control switch | **High** | Dead UI / wrong widget |
| Four stat offsets + flags table | **High** | Wrong attribute applied / wrong wire flag |
| Pool `+0x6CE` assign via AddSkillPoints | **High** | Desync free points |
| Arena `DAT_00d1b644+0xF6` block | **High** | Illegal arena spends |
| Packet `0x205A` 8-byte `{opcode,flags}` | **High** | Server ignore / wrong handler |
| Soft get cap 200 | **High** | Off-by-one near ceiling |
| Which dialog owns vtable slot | **Open** | Mis-place handler in port |
| Product names of four stats | **Open** | UX / design docs only |
| Server mirror of optimistic client | **Open** | Exploit / desync if server trusts client |
| `+0x6CC` vs `+0x6CE` product glossary | **Open** | Confuse mission rewards with sheet spend |

---

## 3. Cross-check raw + live entry bytes

```
008f92e0  sub  esp, 8
008f92e3  push esi
008f92e4  mov  esi, [DAT_00d1b6d8]     ; local character*
008f92ea  test esi, esi
008f92ec  push edi
008f92ed  mov  edi, ecx               ; this = UI host
008f92ef  jnz  have_char
          … xor al,al; pop; add esp,8; ret 8   ; return 0
have_char:
          mov  edx, [esp+…]            ; controlId (param_3)
          mov  eax, [esp+…]            ; eventType (param_2)
          lea  ecx, [edx - 0x9C40]
          cmp  ecx, 4
          ja   fallthrough_event_switch
          jmp  [ecx*4 + switchdataD_008f96c0]
…
epilogue paths:
          pop  edi / mov al,1 / pop esi / add esp,8 / ret 8
          ; default: push edx,eax; mov ecx,edi; call FUN_0087b500; … ret 8
```

Live decompile (2026-07-29) matches 2026-07-23 raw control flow, string, opcode `0x205A`, and per-case flags `1 / 0x10000 / 0x100 / 0x1000000`.

DATA slot `0x00a35a2c` = `E0 92 8F 00` → `0x008F92E0` (handler install, not CALL).

---

## 4. Surviving contract for AutoCore

```
bool UI_OnAttributePointClick(UiHost* self, int eventType, uint controlId):
  char* pc = g_LocalCharacter                    // DAT_00d1b6d8
  if (!pc) return false

  switch (controlId):
    case 0x9C40:
      if (eventType == 8) { FUN_007fca10(); return true }
      break
    case 0x9C41..0x9C44:
      if (eventType != 8) break
      if (*(i16*)(pc+0x6CE) < 1) return true
      if (g_Arena && *(u8*)(g_Arena+0xF6)) { Toast(attr_arena_msg); return true }
      off, flag, sideFx = map[controlId]         // sealed table in Review A §3.1
      v = min(*(i16*)(pc+off), 200)
      *(i16*)(pc+off) = (i16)(v + 1)             // via typed setters
      CVOGCharacter_AddSkillPoints(pc, *(i16*)(pc+0x6CE) - 1)
      run sideFx                                  // vehicle only for 0x9C42; vtbl+0x5C for 0x9C43
      Client_RefreshMissionDialogChrome()
      self->vtbl[+0x448](); self->vtbl[+0x34C]()
      if (!CanSendSector(self)) return true
      SendSectorPacket(g_Client, 8, {0x205A, flag})
      return true

  switch (eventType):
    case 7, 8, 0xD, 0xE: return true
    default: return FUN_0087b500(self, eventType, controlId)
```

**Adversarial do-nots**

- Do **not** wire this to `+0x6CC` / `AddAttributePoints`.
- Do **not** assume control ID order == memory order of stats.
- Do **not** skip server validation of spend + arena + caps.
- Do **not** treat get-cap 200 as a write clamp without separate proof.
- Do **not** merge opcode `0x205A` with skill-train `0x2059`.

---

## 5. Residual risks

1. **Handler table owner** — only DATA xref; dialog class / registration site not walked (own-VA scope).
2. **Product glossary** — “attribute points” toast vs `AddSkillPoints` / `+0x6ce` vs `+0x6cc` twin.
3. **Server** — packet flags meaning on sector; whether client-side set is authoritative preview only.
4. **FUN_007fca10** case `0x9C40` — UI navigation/help-ish; not a spend; full semantics out of scope.
5. **FUN_00807440** — decomp noisy (`in_EAX`); role sealed only as “send gate,” not full session object layout.
