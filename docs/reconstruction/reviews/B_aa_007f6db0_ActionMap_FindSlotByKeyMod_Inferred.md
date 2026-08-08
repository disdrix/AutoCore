# Review B (skeptical / adversarial): `aa_007f6db0` ActionMap_FindSlotByKeyMod_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007f6db0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-018) |
| **Counterpart** | `reviews/A_aa_007f6db0_ActionMap_FindSlotByKeyMod_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Plain `__fastcall(param_1,param_2)` with stack ECX/EDX formals | **Falsified** — asm uses **EAX=mode, EDI=map, SI=key, DX=mod**; decomp phantoms |
| 2 | Function is a keybind **writer** / mutator | **Falsified** — pure scan; only returns pointer; no stores in body |
| 3 | Single mode / single lane | **Falsified** — 4-mode JT + primary/alt per slot |
| 4 | Matches key only (ignores mod) | **Falsified** — `TEST DX,DX` + mod0/mod1 zeroness + override flag |
| 5 | `thiscall` / ECX=ActionMap | **Falsified** — **EDI** carries base; ECX is loop index |
| 6 | `RET 4` / stack args | **Falsified** — bare `C3`; no stack formals |
| 7 | Many callers / global registry | **Falsified** — **1** UNCONDITIONAL_CALL (`0x00911429`) |
| 8 | Product mode names known | **Unproven** — offsets sealed; English Tentative |
| 9 | Modes 1–3 used at runtime by this path | **Unproven** — sole caller forces `XOR EAX,EAX` (mode 0) |
| 10 | Named_CalleeOf_* is canonical | **Falsified** — retired; ActionMap family name preferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Mode switch + JT | **High** | Wrong bank scanned |
| Bounds / stride 0x34 | **High** | OOB / wrong slot |
| Dual-lane key/mod match | **High** | Miss / false match |
| Override flag path | **High** | Ignore customized-mod escape |
| ABI EAX/EDI/SI/DX + RET0 | **High** | Corrupt caller regs |
| Return = key0 field* | **High** | held/edge offsets wrong |
| Mode product names | **Tentative** | Docs only |
| Modes 1–3 live use | **Tentative** | Dead code vs latent API |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
mode=EAX; map=EDI; key=SI; modState=DX
if mode>3: EAX=0; ret
jt[mode]:
  for i in 0..max-1:
    cursor = map + mod0[mode] + i*0x34
    if key0==key and (same_zero(modState,mod0) or flag): return map+key0[mode]+i*0x34
    if key1==key and (same_zero(modState,mod1) or flag): return map+key0[mode]+i*0x34
  EAX=0; ret
```

Caller seal (`Client_Input_OnKeyDown_MatchAction`):

```
BX = 0 or 0x2A from GetAsyncKeyState(SHIFT/L/R)
SI = constructed key
EDX=EBX; EAX=0; EDI=0x00d1b9ac
CALL 0x007f6db0
TEST EAX,EAX → held@+4 / edge@+5 / FUN_0093a5c0(1)
```

Sibling seal: `ActionMap_TrySetSlotBind` shares `kMax`/`kKey0`/`kMod0` exactly.

Live decompile ≡ raw. Clean plate carries tables.

---

## 4. Surviving contract for AutoCore

```
// ActionMap slot lookup (client only)
slot = ActionMap_FindSlotByKeyMod(mode, key, modState, actionMap)
// slot points at key0; held=slot[4], edge=slot[5]
// match: key primary OR alt, with mod zeroness agreement OR override flag
// mode 0..3; stride 0x34; null if none

// Port notes:
// - Register ABI is custom; do not model as MSVC __fastcall.
// - OnKeyDown only exercises mode 0; keep modes 1–3 for parity with TrySetSlotBind.
// - Do not invent product mode names; keep _Inferred until sealed.
// - Distinct from TrySetSlotBind (write) and FormatSlotBindDisplay (UI string).
```

---

## 5. Verdict

Adversarial attacks on ABI / writer-identity / single-lane / thiscall / multi-caller **fail**. Residual gaps are product English and unobserved modes 1–3 → **accept-with-gaps**.
