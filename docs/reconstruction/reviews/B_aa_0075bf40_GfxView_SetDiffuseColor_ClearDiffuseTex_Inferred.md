# Review B (skeptical / adversarial): `aa_0075bf40` GfxView_SetDiffuseColor_ClearDiffuseTex_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075bf40` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (W37-L) |
| **Counterpart** | `reviews/A_aa_0075bf40_GfxView_SetDiffuseColor_ClearDiffuseTex_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` on **own VA** (+ string + callers). No ledger edits. No `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Function only sets a texture | Always stores `+0x148` color; texture clear is conditional | **Falsified** — **color setter** primary; clear side effect |
| 2 | cdecl free function | ECX this; field stores via EDI; `ret 4` | **Falsified** — **thiscall** |
| 3 | Returns the color or HRESULT | `XOR EAX,EAX` always | **Falsified** — always **0** |
| 4 | Requires non-null effect | Null path still writes color/dirty | **Falsified** — effect optional |
| 5 | Skips dirty when index miss | Dirty store is unconditional after clear branch | **Falsified** — always dirty |
| 6 | Decompiler `local_4 = this` is real | No such store in non-null path bytes | **Falsified** — decomp noise |
| 7 | Name Confirmed product symbol | Only string `"DiffuseTexture"`; no RTTI/method plate | **Clarify** — keep **`_Inferred`** |
| 8 | `+0x148` is float | Call sites push integer immediates; `MOV` dword | **Falsified** — **uint32** packed |
| 9 | Same as SetNear/SetFar | Separate VA; different fields | **Falsified** — distinct worker |
| 10 | FUN_00970060 always runs | `JL` skips when index &lt; 0 | **Clarify** — conditional clear |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + ret 4 + return 0 | **High** | Wrong stack cleanup |
| Offsets 0x129 / 0x134 / 0x148 | **High** | Corrupt wrong fields |
| DiffuseTexture string clear path | **High** | Leave stale texture when setting solid color |
| Color always written | **High** | Ports skip write on miss |
| Packed format English | **Medium** | Channel swap in UI |
| FUN_00970060 internals | **Low** | Wrong clear API |

---

## 3. Cross-check against raw / bytes

```
raw decompile:
  if +0x134==0: idx=-1 else lookup DiffuseTexture
  if idx>=0: clear
  +0x148=color; +0x129=1; return 0

bytes:
  MOV EDI,ECX
  MOV ECX,[EDI+0x134]; TEST; LEA ESI,[EDI+0x134]
  JZ idx=-1
  PUSH "DiffuseTexture"; PUSH &idx; CALL 00752370
  MOV EAX,[idx]; TEST; JL skip
  PUSH 0; PUSH EAX; CALL 00970060
  MOV [EDI+0x148], color; MOV byte [EDI+0x129],1
  XOR EAX,EAX; RET 4
```

Clean must **not** invent:

- Returning color or failure codes
- Skipping color write when effect null
- Float color field
- Confirmed product plate without RTTI
- Unconditional texture clear

---

## 4. Surviving contract for AutoCore

```csharp
// Behavior-exact port of 0x0075bf40
int GfxView_SetDiffuseColor_ClearDiffuseTex(GfxView self, uint color)
{
    int index = -1;
    var effect = self.EffectAt134;
    if (effect != null)
        Effect_FindParamIndexByName(effect, ref index, "DiffuseTexture");
    if (index >= 0)
        ClearParamTexture(index, 0); // FUN_00970060
    self.Color148 = color;
    self.Dirty129 = 1;
    return 0;
}
```

---

## 5. Verdict

**accept-with-gaps** — adversarial pass removes decompiler noise and overclaims; sealed contract is small and stable.
