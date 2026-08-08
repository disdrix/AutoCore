# Review B (skeptical / adversarial): `aa_0059dc50` ObjectiveNode_IsEligibleForTracker_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059dc50` |
| **VA** | `0x0059dc50` |
| **Canonical name** | `ObjectiveNode_IsEligibleForTracker_Inferred` |
| **Review date** | `2026-08-05` (MEGA-025 dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_0059dc50_ObjectiveNode_IsEligibleForTracker_Inferred.md` |
| **Live tools** | Independent `decompile_function` + `read_memory` + analyze/xrefs + `disassemble_function` + assembly context |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is the **tracker writer** / `Tracker_SetActiveMissionObjective` body | **Falsified** — pure bool gate; writer is `0x0092a590`; bind parent `0x0092fd00` *calls* this |
| 2 | This is `FUN_0059db80` evaluator | **Falsified** — different VA; this *calls* `0059db80` and only tests `==-1` |
| 3 | cdecl / no stack cleanup / void return | **Falsified** — **`RET 4`** ×2; **AL** bool (`XOR AL,AL` / `MOV AL,1`) |
| 4 | ECX = character, stack = node | **Falsified** — call sites `MOV ECX, node`; `PUSH character`; ESI=this, EDI=arg |
| 5 | Band is exclusive decompiler form only / wrong bounds | **Falsified** — asm `CMP 0xdfd/JL` + `CMP 0xe02/JG` → inclusive `[0xdfd,0xe02]`; decompiler equivalent |
| 6 | Always requires virtual `+0x27c` | **Falsified** — virtual only when id in band; else fall through to true |
| 7 | Named_CalleeOf VOG_DEBUG_STOP is product name | **Falsified** — VOG_DEBUG_STOP is hash-lock assert in parents; retire scaffold |
| 8 | Completes mission / mutates tracker state | **Falsified** — no stores to tracker; only reads + calls; returns bool |
| 9 | Runtime Confirmed | **Fails** — open (no Launcher) |

---

## 2. Decisive machine dataflow

```text
PUSH ESI / PUSH EDI
MOV  EDI, [ESP+0xc]        // character*
TEST EDI, EDI
MOV  ESI, ECX              // node*
JZ   fail

MOV  EAX, [ESI+0x14c]      // template*
CMP  word [EAX+0xf8], 0
JZ   after_flag
CMP  byte [ESI+0x14], 0
JZ   fail
after_flag:
PUSH EDI / MOV ECX, ESI
CALL FUN_0059db80
CMP  EAX, -1
JZ   fail

MOV  ECX, [ESI+0x14c]
MOV  EAX, [ECX]            // template id
CMP  EAX, 0xdfd
JL   pass
CMP  EAX, 0xe02
JG   pass
// band hit: this-adjust character + CALL [vtbl+0x27c]
CMP  EAX, 5
JGE  pass
fail:
POP EDI / XOR AL,AL / POP ESI / RET 4
pass:
POP EDI / MOV AL,1 / POP ESI / RET 4
```

Call-site (`Client_TryBindActiveMissionTracker` @ `0x0092fd25`):

```text
// after CNDHash_LookupByKey → node in EAX; character in ESI
PUSH ESI
MOV  ECX, EAX
CALL 0x0059dc50
TEST AL, AL
JNZ  tracker_bind_path      // only bind when eligible
// else fall through → return 0
```

A ≡ B on live decompile + body hex + xrefs + assembly context.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Bool gate CF (4 fail paths + pass) | **High** | wrong tracker selection |
| ECX=node + stack=character + RET 4 | **High** | stack smash / wrong this |
| Inclusive id band + vtbl+0x27c threshold | **High** | wrong special-case filter |
| Caller set (5 / 9 xrefs) | **High** | missing specialization |
| Product field English | Medium | naming only |
| Virtual method product role | Medium | port comment only |

---

## 4. Surviving contract for AutoCore

```csharp
// thiscall RET 4; AL = eligible for mission tracker bind/selection
bool ObjectiveNode_IsEligibleForTracker(ObjectiveNode node, Character character)
{
    if (character == null)
        return false;

    var tmpl = node.Template; // +0x14c
    if (tmpl.GateShort_F8 != 0 && node.FlagByte_14 == 0)
        return false;

    if (ObjectiveEval(node, character) == -1) // FUN_0059db80
        return false;

    uint id = tmpl.Id; // first dword
    if (id >= 0xdfd && id <= 0xe02) // inclusive six-id band
    {
        if (character.Virtual_0x27c() < 5)
            return false;
    }
    return true;
}
// Keep distinct from FUN_0059db80 (evaluator) and Tracker_SetActive / TryBind (parents).
// Do not invent product names for short/flag/band/vtbl without more evidence.
// Retire Named_CalleeOf_Named_VOG_DEBUG_STOP scaffold.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/caller roles/band mechanics. Residual product English → **accept-with-gaps**. Runtime Confirmed **not** claimed.
