# Review B (skeptical / adversarial): `aa_009430f0` Client_OnLocalCharacterReady_EnterWorldSetup_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_009430f0` |
| **VA** | `0x009430f0` |
| **Canonical name** | `Client_OnLocalCharacterReady_EnterWorldSetup_Inferred` |
| **Review date** | `2026-08-05` (R10-017 dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_009430f0_Client_OnLocalCharacterReady_EnterWorldSetup_Inferred.md` |
| **Live tools** | Independent `decompile_function` + `read_memory` + `disassemble_function` + xrefs/callers + float/string reads + caller site bytes |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Decompiler `void FUN_009430f0(void)` is complete ABI (no host) | **Falsified** — **ESI** is host; every stage uses `[ESI+imm]`; callers `MOV ESI,client` before CALL |
| 2 | ECX thiscall with client in ECX | **Falsified** — prologue loads ECX from `[ESI+0xe04]` for callee this; entry host is ESI |
| 3 | Stack args / `RET 4` / `RET N` | **Falsified** — epilog **`RET`** (`C3`) only after `POP EBX; POP ECX` |
| 4 | Integer stores to `cam+0x530` | **Falsified** — **`MOVSS`** loads from float globals 10.0f / ~6.7f |
| 5 | Sole callee of CreateCharacter only | **Falsified** — **3** xrefs: CreateCharacter + **2** sites in `FUN_00946c00` |
| 6 | Is body of dualed parent `0x00942e20` | **Falsified** — parent body ends **exclusive** at `0x009430f0`; separate function; no static call edge from parent |
| 7 | Product name sealed without `_Inferred` | **Fails** — no PDB/demangle; role-from-callers + string |
| 8 | `DAT_00d1ad1c` dword write | **Falsified** — `MOV byte ptr [0x00d1ad1c], BL` |
| 9 | Second FUN_00941fb0 also uses `//rejoinchat` | **Falsified** — second site sets **EDX=ECX=0xa1419b**; only first uses `0xa2cff8` |
| 10 | Runtime Confirmed | **Fails** — open (no Launcher; Terminal false) |

---

## 2. Decisive machine dataflow

```text
; entry: ESI = client*
009430f0  PUSH ECX
009430f1  MOV  ECX, [ESI+0xe04]          ; worldRoot this
009430f7  PUSH EBX
009430f8  CALL 004d9f00
009430fd  MOV  EAX, [ESI+0xe04]
00943103  MOV  ECX, [EAX+0xe894]         ; env*
00943109  MOV  byte ptr [ECX+0x8c], 1
...
00943173  MOV  dword ptr [EAX+0xcc4], 6  ; camera mode
009431b5  MOVSS XMM0, [0x00aaaccc]       ; ~6.7f branch
009431cd  MOVSS XMM0, [0x00a110d8]       ; 10.0f branch
009431bd/d5  MOVSS [cam+0x530], XMM0
...
0094320f  PUSH 0x19 / MOV ECX,ESI / CALL Client_MaybeShowFirstTimeTip
...
00943273  MOV  EAX, ESI
00943275  CALL 009301b0                  ; UI refresh
...
009432a8  MOV  ECX, 0xa1419b
009432ad  MOV  EDX, 0xa2cff8             ; "//rejoinchat"
009432b2  CALL 00941fb0                  ; mode 3, flag 0
...
009432e9  POP  EBX
009432ea  POP  ECX
009432eb  RET
```

CreateCharacter site (`0x00814959`): falls through after quickbar + `FUN_0094c2a0` with client in ESI/param_2.

FUN_00946c00 sites: `8B F3 E8 …` (`MOV ESI, EBX; CALL rel32`) — EBX holds client/param_1.

A ≡ B on live decompile CF + body hex + xrefs + call-site pattern.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Multi-stage enter-world CF | **High** | wrong port model |
| ESI host / bare RET | **High** | ABI smash |
| Body 508 B + hash | **High** | wrong unit bounds |
| Callers 3 / 2 parents | **High** | incomplete edges |
| Float zoom 10.0 / 6.7 | **High** | wrong camera feel |
| `//rejoinchat` path | **High** | miss chat rejoin |
| Product English / tip table | **Tentative** | overclaim UX copy |
| Case 3 / 0x1e product names | **Open** | wrong event taxonomy |
| Undualed helper internals | **Open** | incomplete dependency seal |

---

## 4. Gaps accepted

- Product names for camera, worldRoot, tips, dispatcher cases.
- Full FUN_00941fb0 / 004d9f00 / 009301b0 dual seals (out of OWN scope).
- Runtime / differential.

---

## 5. Verdict

**accept-with-gaps** — adversarial path falsified freestanding-void, stack-arg, CreateCharacter-only, parent-body, and integer-zoom claims. Core CF/ABI/callers/floats/string sealed. Product English open → keep `_Inferred`. Terminal **false**.
